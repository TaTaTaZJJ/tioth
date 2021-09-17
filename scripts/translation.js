const fs = require("fs");
var filename = process.argv[2];
var locale = process.argv[3];

fs.readFile(filename, (err, jsonBuffer) => {
    if (err) throw err;
    let jsonData = JSON.parse(jsonBuffer.toString());
    if (!jsonData.texts || !Array.isArray(jsonData.texts)) {
        console.log("texts should be an array of object");
        return;
    }
    if (!jsonData.path) {
        console.log("path is missing from the json file.");
        return;
    }
    fs.readFile(jsonData.path, (err, targetBuffer) => {
        if (err) throw err;
        let targetData = targetBuffer.toString();
        jsonData.texts.forEach(text => {
            let newText = text[locale];
            if (newText == undefined) {
                console.log(`missing ${locale} of ${text.label} in ${filename}`)
            }
            else {
                let regex = new RegExp(text.label + '\\[\\].*_\\(.*\\);', 'g');
                let replacingWord = text.label + "[] = _(\"" + newText + "\");";
                if (!regex.test(targetData)) {
                    regex = new RegExp(text.label + '\\](.*)_\\("(.*)\\);', 'g');
                    replacingWord = text.label + "] = _(\"" + newText + "\");";
                    if (!regex.test(targetData)) {
                        regex = new RegExp(text.label + '\\[\\](.*)_\\((\\n[^\\)]+){1,}"\\);', 'g')
                        newText = newText.replace('\\l', '\\l"\n"');
                        newText = newText.replace('\\n', '\\n"\n"');
                        newText = newText.replace('\\p', '\\p"\n"');
                        replacingWord = text.label + '[] = _(\n"' + newText + '");';
                    }
                }
                targetData = targetData.replace(regex, replacingWord);
            }
        });
        fs.writeFile(jsonData.path, targetData, (err) => {
            if (err) throw err;
            console.log(`Translated ${jsonData.path} with ${filename}`)
        })
    });
});
