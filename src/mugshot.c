#include "global.h"
#include "blit.h"
#include "window.h"
#include "menu.h"
#include "palette.h"
#include "event_data.h"
#include "mugshot.h"
#include "constants/mugshot.h"

struct Mugshot
{
    u8 x;
    u8 y;
    u8 width;
    u8 height;
    const u32 *image;
    const u16 *palette;
};

void DrawMugshot(u16 index, int x, int y);
void ClearMugshot(void);

static const u32 sMugshotImg_Test[] = INCBIN_U32("graphics/mugshots/test.4bpp.lz");
static const u16 sMugshotPal_Test[] = INCBIN_U16("graphics/mugshots/test.gbapal");

static const struct Mugshot sMugshots[MUGSHOT_COUNT] = {
    [MUGSHOT_TEST] = {.x = 18, .y = 5, .width = 64, .height = 80, .image = sMugshotImg_Test, .palette = sMugshotPal_Test},
};

//WindowId + 1, 0 if window is not open
static EWRAM_DATA u8 sMugshotWindow = 0;

void ClearMugshot(void)
{
    if (sMugshotWindow != 0)
    {
        ClearStdWindowAndFrameToTransparent(sMugshotWindow - 1, 0);
        CopyWindowToVram(sMugshotWindow - 1, 3);
        RemoveWindow(sMugshotWindow - 1);
        sMugshotWindow = 0;
    }
}

void DrawMugshot(u16 index, int x, int y)
{
    struct WindowTemplate t;
    u16 windowId;
    const struct Mugshot* const mugshot = sMugshots + index;

    if (x == MUGSHOT_DEFAULT_POS)
        x = mugshot->x;

    if (y == MUGSHOT_DEFAULT_POS)
        y = mugshot->y;

    if (sMugshotWindow != 0)
    {
        ClearMugshot();
    }

#if GAME_VERSION == VERSION_EMERALD
    SetWindowTemplateFields(&t, 0, x, y, mugshot->width / 8, mugshot->height / 8, MUGSHOT_PALETTE_NUM, 0x40);
#else
    t = SetWindowTemplateFields(0, x, y, mugshot->width / 8, mugshot->height / 8, MUGSHOT_PALETTE_NUM, 0x40);
#endif
    windowId = AddWindow(&t);
    sMugshotWindow = windowId + 1;

    LoadPalette(mugshot->palette, 16 * MUGSHOT_PALETTE_NUM, 32);
    CopyToWindowPixelBuffer(windowId, (const void *)mugshot->image, 0, 0);
    PutWindowRectTilemap(windowId, 0, 0, mugshot->width / 8, mugshot->height / 8);
    CopyWindowToVram(windowId, 3);
}
