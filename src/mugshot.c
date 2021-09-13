#include "global.h"
#include "blit.h"
#include "window.h"
#include "bg.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "mugshot.h"
#include "constants/mugshot.h"

struct Mugshot
{
    u8 width;
    u8 height;
    u8 bust; // 胸围, 用于计算对话框箭头坐标
    const u32 *image;
    const u16 *palette;
};

static EWRAM_DATA u8 sMugshotWindow = 0;
static EWRAM_DATA u8 sMugshotBust = 0;

void DrawMugshot(void);
void ClearMugshot(void);

static const u32 sMugshotImg_Test[] = INCBIN_U32("graphics/mugshots/test.4bpp.lz");
static const u16 sMugshotPal_Test[] = INCBIN_U16("graphics/mugshots/test.gbapal");
static const u32 sMugshotImg_Test2[] = INCBIN_U32("graphics/mugshots/test2.4bpp.lz");
static const u16 sMugshotPal_Test2[] = INCBIN_U16("graphics/mugshots/test2.gbapal");
static const struct Mugshot sMugshots[MUGSHOT_COUNT] = {
    [MUGSHOT_TEST] = {.width = 64, .height = 96, .bust = 64, .image = sMugshotImg_Test, .palette = sMugshotPal_Test},
    [MUGSHOT_TEST2] = {.width = 64, .height = 88, .bust = 64, .image = sMugshotImg_Test2, .palette = sMugshotPal_Test2},
};

void ClearMugshot(void)
{   
    if (sMugshotWindow != 0)
    {
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
        sMugshotBust = 0;
    }
}

// 垂直翻转的WindowRectTileMap
static void PutWindowRectTilemapFlip(u8 windowId, u8 x, u8 y, u8 width, u8 height)
{
    int i, j;
    struct Window windowLocal = gWindows[windowId];
    for (i = 0; i < height; ++i)
    {
        for (j = 0; j < width; ++j)
        {
            FillBgTilemapBufferRect(windowLocal.window.bg,
                                    BG_TILE_H_FLIP(windowLocal.window.baseBlock + width - 1 - j + (i * width)),
                                    windowLocal.window.tilemapLeft + x + j,
                                    windowLocal.window.tilemapTop + y + i,
                                    1,
                                    1,
                                    windowLocal.window.paletteNum);
        }
    }
}

void DrawMugshot(void)
{
    struct WindowTemplate t;
    u16 windowId;
    u8 x, y;
    u8 isRight = VarGet(VAR_MUGSHOT_DIRECTION);
    u16 index = VarGet(VAR_MUGSHOT_ID);
    const struct Mugshot *const mugshot = sMugshots + index;
    y = (112 - mugshot->height) / 8;
    if (sMugshotWindow != 0)
        ClearMugshot();

    sMugshotBust = mugshot->bust;
    if (isRight)
        x = (240 - mugshot->width) / 8;
    else
        x = 0;

    SetWindowTemplateFields(&t, 0, x, y, mugshot->width / 8, mugshot->height / 8, MUGSHOT_PALETTE_NUM, 0x40);
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;
    LoadPalette(mugshot->palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    CopyToWindowPixelBuffer(windowId, (const void *)mugshot->image, 0, 0);
    if (isRight)
        PutWindowRectTilemapFlip(windowId, 0, 0, mugshot->width / 8, mugshot->height / 8);
    else
        PutWindowRectTilemap(windowId, 0, 0, mugshot->width / 8, mugshot->height / 8);
    CopyWindowToVram(windowId, 3);
}

u8 getBustTileCount(void)
{
    return sMugshotBust / 8;
}