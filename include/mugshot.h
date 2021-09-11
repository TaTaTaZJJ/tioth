#ifndef GUARD_MUGSHOTS_H
#define GUARD_MUGSHOTS_H

#define MUGSHOT_DEFAULT_POS 0xFF    //假如x或y值等于这个值，使用默认x或y值
#define MUGSHOT_PALETTE_NUM 13      //头像的色板位置

void ClearMugshot(void);
void DrawMugshot(u16 index, int x, int y);

#endif //GUARD_MUGSHOTS_H