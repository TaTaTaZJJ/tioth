#include "global.h"
#include "blit.h"
#include "window.h"
#include "bg.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "mugshot.h"
#include "constants/mugshot.h"

static EWRAM_DATA u8 sMugshotWindowLeft = 0;
static EWRAM_DATA u8 sMugshotBustLeft = 0;
static EWRAM_DATA u8 sMugshotWindowRight = 0;
static EWRAM_DATA u8 sMugshotBustRight = 0;
struct Mugshot
{
    u8 width;
    u8 height;
    u8 bust; // 胸围, 用于计算对话框箭头坐标
    const u32 *image;
    const u16 *palette;
};

static const u32 sMugshotImg_Test[] = INCBIN_U32("graphics/mugshots/test.4bpp.lz");
static const u16 sMugshotPal_Test[] = INCBIN_U16("graphics/mugshots/test.gbapal");
static const u32 sMugshotImg_Test2[] = INCBIN_U32("graphics/mugshots/test2.4bpp.lz");
static const u16 sMugshotPal_Test2[] = INCBIN_U16("graphics/mugshots/test2.gbapal");
static const u32 sMugshotImg_Majo[] = INCBIN_U32("graphics/mugshots/majo.4bpp.lz");
static const u16 sMugshotPal_Majo[] = INCBIN_U16("graphics/mugshots/majo.gbapal");

static const struct Mugshot sMugshots[MUGSHOT_COUNT] = {
    [MUGSHOT_TEST] = {.width = 64, .height = 96, .bust = 64, .image = sMugshotImg_Test, .palette = sMugshotPal_Test},
    [MUGSHOT_TEST2] = {.width = 64, .height = 88, .bust = 64, .image = sMugshotImg_Test2, .palette = sMugshotPal_Test2},
    [MUGSHOT_MAJO] = {.width = 96, .height = 104, .bust = 64, .image = sMugshotImg_Majo, .palette = sMugshotPal_Majo},
};

void ClearMugshot(bool8 right)
{
    if (right && sMugshotWindowRight != 0)
    {
        ClearStdWindowAndFrameToTransparent(sMugshotWindowRight - 1, 0);
        CopyWindowToVram(sMugshotWindowRight - 1, 3);
        RemoveWindow(sMugshotWindowRight - 1);
        sMugshotWindowRight = 0;
    }
    else if (sMugshotWindowLeft != 0)
    {
        ClearStdWindowAndFrameToTransparent(sMugshotWindowLeft - 1, 0);
        CopyWindowToVram(sMugshotWindowLeft - 1, 3);
        RemoveWindow(sMugshotWindowLeft - 1);
        sMugshotWindowLeft = 0;
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

void DrawMugshot(int index, bool8 right)
{
    struct WindowTemplate t;
    u16 windowId;
    u8 x = 0;
    u8 y = 0;
    u8 baseblock = 0x40;
    u8 palNum = 13;

    const struct Mugshot *const mugshot = sMugshots + index;
    y = (112 - mugshot->height) / 8;

    if (right)
    {
        if (sMugshotWindowRight != 0)
            ClearMugshot(TRUE);
        x = (240 - mugshot->width) / 8;
        sMugshotBustRight = mugshot->bust;
        baseblock = 0xF0;
        palNum = 14;
    }
    else
    {
        if (sMugshotWindowLeft != 0)
            ClearMugshot(FALSE);
        sMugshotBustLeft = mugshot->bust;
    }

    SetWindowTemplateFields(&t, 0, x, y, mugshot->width / 8, mugshot->height / 8, palNum, baseblock);
    windowId = AddWindow(&t);
    CopyToWindowPixelBuffer(windowId, (const void *)mugshot->image, 0, 0);

    if (right)
    {
        sMugshotWindowRight = windowId + 1;
        PutWindowRectTilemapFlip(windowId, 0, 0, mugshot->width / 8, mugshot->height / 8);
    }
    else
    {
        sMugshotWindowLeft = windowId + 1;
        PutWindowRectTilemap(windowId, 0, 0, mugshot->width / 8, mugshot->height / 8);
    }

    LoadPalette(mugshot->palette, 16 * palNum, 32);
    CopyWindowToVram(windowId, 3);
}

u8 getLeftBustTileCount(void)
{
    return sMugshotBustLeft / 8;
}

u8 getRightBustTileCount(void)
{
    return sMugshotBustRight / 8;
}

bool8 hasMugshotAtRight(void)
{
    return sMugshotWindowRight != 0;
}
