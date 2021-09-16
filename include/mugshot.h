#ifndef GUARD_MUGSHOTS_H
#define GUARD_MUGSHOTS_H

void DrawMugshot(int index, bool8 right);
void ClearMugshot(bool8 right);
u8 getLeftBustTileCount(void);
u8 getRightBustTileCount(void);
bool8 hasMugshotAtRight(void);

#endif //GUARD_MUGSHOTS_H