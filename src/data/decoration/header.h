const struct Decoration gDecorations[] =
{
    [DECOR_NONE] =
    {
        .id = DECOR_NONE,
#ifdef CHINESE
        .name = _("SMALL DESK"),         //TODO: 汉化 （低优先度）
#else
        .name = _("SMALL DESK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 0,
        .description = DecorDesc_SMALL_DESK,
        .tiles = DecorGfx_SMALL_DESK,
    },
 
    [DECOR_SMALL_DESK] =
    {
        .id = DECOR_SMALL_DESK,
#ifdef CHINESE
        .name = _("SMALL DESK"),         //TODO: 汉化 （低优先度）
#else
        .name = _("SMALL DESK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 3000,
        .description = DecorDesc_SMALL_DESK,
        .tiles = DecorGfx_SMALL_DESK,
    },
 
    [DECOR_POKEMON_DESK] =
    {
        .id = DECOR_POKEMON_DESK,
#ifdef CHINESE
        .name = _("POKéMON DESK"),       //TODO: 汉化 （低优先度）
#else
        .name = _("POKéMON DESK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DESK,
        .price = 3000,
        .description = DecorDesc_POKEMON_DESK,
        .tiles = DecorGfx_POKEMON_DESK,
    },
 
    [DECOR_HEAVY_DESK] =
    {
        .id = DECOR_HEAVY_DESK,
#ifdef CHINESE
        .name = _("HEAVY DESK"),         //TODO: 汉化 （低优先度）
#else
        .name = _("HEAVY DESK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = DecorDesc_HEAVY_DESK,
        .tiles = DecorGfx_HEAVY_DESK,
    },
 
    [DECOR_RAGGED_DESK] =
    {
        .id = DECOR_RAGGED_DESK,
#ifdef CHINESE
        .name = _("RAGGED DESK"),        //TODO: 汉化 （低优先度）
#else
        .name = _("RAGGED DESK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = DecorDesc_RAGGED_DESK,
        .tiles = DecorGfx_RAGGED_DESK,
    },
 
    [DECOR_COMFORT_DESK] =
    {
        .id = DECOR_COMFORT_DESK,
#ifdef CHINESE
        .name = _("COMFORT DESK"),       //TODO: 汉化 （低优先度）
#else
        .name = _("COMFORT DESK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x2,
        .category = DECORCAT_DESK,
        .price = 6000,
        .description = DecorDesc_COMFORT_DESK,
        .tiles = DecorGfx_COMFORT_DESK,
    },
 
    [DECOR_PRETTY_DESK] =
    {
        .id = DECOR_PRETTY_DESK,
#ifdef CHINESE
        .name = _("PRETTY DESK"),        //TODO: 汉化 （低优先度）
#else
        .name = _("PRETTY DESK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = DecorDesc_PRETTY_DESK,
        .tiles = DecorGfx_PRETTY_DESK,
    },
 
    [DECOR_BRICK_DESK] =
    {
        .id = DECOR_BRICK_DESK,
#ifdef CHINESE
        .name = _("BRICK DESK"),         //TODO: 汉化 （低优先度）
#else
        .name = _("BRICK DESK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = DecorDesc_BRICK_DESK,
        .tiles = DecorGfx_BRICK_DESK,
    },
 
    [DECOR_CAMP_DESK] =
    {
        .id = DECOR_CAMP_DESK,
#ifdef CHINESE
        .name = _("CAMP DESK"),  //TODO: 汉化 （低优先度）
#else
        .name = _("CAMP DESK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = DecorDesc_CAMP_DESK,
        .tiles = DecorGfx_CAMP_DESK,
    },
 
    [DECOR_HARD_DESK] =
    {
        .id = DECOR_HARD_DESK,
#ifdef CHINESE
        .name = _("HARD DESK"),  //TODO: 汉化 （低优先度）
#else
        .name = _("HARD DESK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_DESK,
        .price = 9000,
        .description = DecorDesc_HARD_DESK,
        .tiles = DecorGfx_HARD_DESK,
    },
 
    [DECOR_SMALL_CHAIR] =
    {
        .id = DECOR_SMALL_CHAIR,
#ifdef CHINESE
        .name = _("SMALL CHAIR"),        //TODO: 汉化 （低优先度）
#else
        .name = _("SMALL CHAIR"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_SMALL_CHAIR,
        .tiles = DecorGfx_SMALL_CHAIR,
    },
 
    [DECOR_POKEMON_CHAIR] =
    {
        .id = DECOR_POKEMON_CHAIR,
#ifdef CHINESE
        .name = _("POKéMON CHAIR"),      //TODO: 汉化 （低优先度）
#else
        .name = _("POKéMON CHAIR"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_POKEMON_CHAIR,
        .tiles = DecorGfx_POKEMON_CHAIR,
    },
 
    [DECOR_HEAVY_CHAIR] =
    {
        .id = DECOR_HEAVY_CHAIR,
#ifdef CHINESE
        .name = _("HEAVY CHAIR"),        //TODO: 汉化 （低优先度）
#else
        .name = _("HEAVY CHAIR"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_HEAVY_CHAIR,
        .tiles = DecorGfx_HEAVY_CHAIR,
    },
 
    [DECOR_PRETTY_CHAIR] =
    {
        .id = DECOR_PRETTY_CHAIR,
#ifdef CHINESE
        .name = _("PRETTY CHAIR"),       //TODO: 汉化 （低优先度）
#else
        .name = _("PRETTY CHAIR"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_PRETTY_CHAIR,
        .tiles = DecorGfx_PRETTY_CHAIR,
    },
 
    [DECOR_COMFORT_CHAIR] =
    {
        .id = DECOR_COMFORT_CHAIR,
#ifdef CHINESE
        .name = _("COMFORT CHAIR"),      //TODO: 汉化 （低优先度）
#else
        .name = _("COMFORT CHAIR"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_COMFORT_CHAIR,
        .tiles = DecorGfx_COMFORT_CHAIR,
    },
 
    [DECOR_RAGGED_CHAIR] =
    {
        .id = DECOR_RAGGED_CHAIR,
#ifdef CHINESE
        .name = _("RAGGED CHAIR"),       //TODO: 汉化 （低优先度）
#else
        .name = _("RAGGED CHAIR"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_RAGGED_CHAIR,
        .tiles = DecorGfx_RAGGED_CHAIR,
    },
 
    [DECOR_BRICK_CHAIR] =
    {
        .id = DECOR_BRICK_CHAIR,
#ifdef CHINESE
        .name = _("BRICK CHAIR"),        //TODO: 汉化 （低优先度）
#else
        .name = _("BRICK CHAIR"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_BRICK_CHAIR,
        .tiles = DecorGfx_BRICK_CHAIR,
    },
 
    [DECOR_CAMP_CHAIR] =
    {
        .id = DECOR_CAMP_CHAIR,
#ifdef CHINESE
        .name = _("CAMP CHAIR"),         //TODO: 汉化 （低优先度）
#else
        .name = _("CAMP CHAIR"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_CAMP_CHAIR,
        .tiles = DecorGfx_CAMP_CHAIR,
    },
 
    [DECOR_HARD_CHAIR] =
    {
        .id = DECOR_HARD_CHAIR,
#ifdef CHINESE
        .name = _("HARD CHAIR"),         //TODO: 汉化 （低优先度）
#else
        .name = _("HARD CHAIR"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CHAIR,
        .price = 2000,
        .description = DecorDesc_HARD_CHAIR,
        .tiles = DecorGfx_HARD_CHAIR,
    },
 
    [DECOR_RED_PLANT] =
    {
        .id = DECOR_RED_PLANT,
#ifdef CHINESE
        .name = _("RED PLANT"),  //TODO: 汉化 （低优先度）
#else
        .name = _("RED PLANT"),
#endif
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = DecorDesc_RED_PLANT,
        .tiles = DecorGfx_RED_PLANT,
    },
 
    [DECOR_TROPICAL_PLANT] =
    {
        .id = DECOR_TROPICAL_PLANT,
#ifdef CHINESE
        .name = _("TROPICAL PLANT"),     //TODO: 汉化 （低优先度）
#else
        .name = _("TROPICAL PLANT"),
#endif
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = DecorDesc_TROPICAL_PLANT,
        .tiles = DecorGfx_TROPICAL_PLANT,
    },
 
    [DECOR_PRETTY_FLOWERS] =
    {
        .id = DECOR_PRETTY_FLOWERS,
#ifdef CHINESE
        .name = _("PRETTY FLOWERS"),     //TODO: 汉化 （低优先度）
#else
        .name = _("PRETTY FLOWERS"),
#endif
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_PLANT,
        .price = 3000,
        .description = DecorDesc_PRETTY_FLOWERS,
        .tiles = DecorGfx_PRETTY_FLOWERS,
    },
 
    [DECOR_COLORFUL_PLANT] =
    {
        .id = DECOR_COLORFUL_PLANT,
#ifdef CHINESE
        .name = _("COLORFUL PLANT"),     //TODO: 汉化 （低优先度）
#else
        .name = _("COLORFUL PLANT"),
#endif
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = DecorDesc_COLORFUL_PLANT,
        .tiles = DecorGfx_COLORFUL_PLANT,
    },
 
    [DECOR_BIG_PLANT] =
    {
        .id = DECOR_BIG_PLANT,
#ifdef CHINESE
        .name = _("BIG PLANT"),  //TODO: 汉化 （低优先度）
#else
        .name = _("BIG PLANT"),
#endif
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = DecorDesc_BIG_PLANT,
        .tiles = DecorGfx_BIG_PLANT,
    },
 
    [DECOR_GORGEOUS_PLANT] =
    {
        .id = DECOR_GORGEOUS_PLANT,
#ifdef CHINESE
        .name = _("GORGEOUS PLANT"),     //TODO: 汉化 （低优先度）
#else
        .name = _("GORGEOUS PLANT"),
#endif
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_PLANT,
        .price = 5000,
        .description = DecorDesc_GORGEOUS_PLANT,
        .tiles = DecorGfx_GORGEOUS_PLANT,
    },
 
    [DECOR_RED_BRICK] =
    {
        .id = DECOR_RED_BRICK,
#ifdef CHINESE
        .name = _("RED BRICK"),  //TODO: 汉化 （低优先度）
#else
        .name = _("RED BRICK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_RED_BRICK,
        .tiles = DecorGfx_RED_BRICK,
    },
 
    [DECOR_YELLOW_BRICK] =
    {
        .id = DECOR_YELLOW_BRICK,
#ifdef CHINESE
        .name = _("YELLOW BRICK"),       //TODO: 汉化 （低优先度）
#else
        .name = _("YELLOW BRICK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_YELLOW_BRICK,
        .tiles = DecorGfx_YELLOW_BRICK,
    },
 
    [DECOR_BLUE_BRICK] =
    {
        .id = DECOR_BLUE_BRICK,
#ifdef CHINESE
        .name = _("BLUE BRICK"),         //TODO: 汉化 （低优先度）
#else
        .name = _("BLUE BRICK"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_BLUE_BRICK,
        .tiles = DecorGfx_BLUE_BRICK,
    },
 
    [DECOR_RED_BALLOON] =
    {
        .id = DECOR_RED_BALLOON,
#ifdef CHINESE
        .name = _("RED BALLOON"),        //TODO: 汉化 （低优先度）
#else
        .name = _("RED BALLOON"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_RED_BALLOON,
        .tiles = DecorGfx_RED_BALLOON,
    },
 
    [DECOR_BLUE_BALLOON] =
    {
        .id = DECOR_BLUE_BALLOON,
#ifdef CHINESE
        .name = _("BLUE BALLOON"),       //TODO: 汉化 （低优先度）
#else
        .name = _("BLUE BALLOON"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_BLUE_BALLOON,
        .tiles = DecorGfx_BLUE_BALLOON,
    },
 
    [DECOR_YELLOW_BALLOON] =
    {
        .id = DECOR_YELLOW_BALLOON,
#ifdef CHINESE
        .name = _("YELLOW BALLOON"),     //TODO: 汉化 （低优先度）
#else
        .name = _("YELLOW BALLOON"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_YELLOW_BALLOON,
        .tiles = DecorGfx_YELLOW_BALLOON,
    },
 
    [DECOR_RED_TENT] =
    {
        .id = DECOR_RED_TENT,
#ifdef CHINESE
        .name = _("RED TENT"),   //TODO: 汉化 （低优先度）
#else
        .name = _("RED TENT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_ORNAMENT,
        .price = 10000,
        .description = DecorDesc_RED_TENT,
        .tiles = DecorGfx_RED_TENT,
    },
 
    [DECOR_BLUE_TENT] =
    {
        .id = DECOR_BLUE_TENT,
#ifdef CHINESE
        .name = _("BLUE TENT"),  //TODO: 汉化 （低优先度）
#else
        .name = _("BLUE TENT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_ORNAMENT,
        .price = 10000,
        .description = DecorDesc_BLUE_TENT,
        .tiles = DecorGfx_BLUE_TENT,
    },
 
    [DECOR_SOLID_BOARD] =
    {
        .id = DECOR_SOLID_BOARD,
#ifdef CHINESE
        .name = _("SOLID BOARD"),        //TODO: 汉化 （低优先度）
#else
        .name = _("SOLID BOARD"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = DecorDesc_SOLID_BOARD,
        .tiles = DecorGfx_SOLID_BOARD,
    },
 
    [DECOR_SLIDE] =
    {
        .id = DECOR_SLIDE,
#ifdef CHINESE
        .name = _("SLIDE"),      //TODO: 汉化 （低优先度）
#else
        .name = _("SLIDE"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_2x4,
        .category = DECORCAT_ORNAMENT,
        .price = 8000,
        .description = DecorDesc_SLIDE,
        .tiles = DecorGfx_SLIDE,
    },
 
    [DECOR_FENCE_LENGTH] =
    {
        .id = DECOR_FENCE_LENGTH,
#ifdef CHINESE
        .name = _("FENCE LENGTH"),       //TODO: 汉化 （低优先度）
#else
        .name = _("FENCE LENGTH"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_FENCE_LENGTH,
        .tiles = DecorGfx_FENCE_LENGTH,
    },
 
    [DECOR_FENCE_WIDTH] =
    {
        .id = DECOR_FENCE_WIDTH,
#ifdef CHINESE
        .name = _("FENCE WIDTH"),        //TODO: 汉化 （低优先度）
#else
        .name = _("FENCE WIDTH"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 500,
        .description = DecorDesc_FENCE_WIDTH,
        .tiles = DecorGfx_FENCE_WIDTH,
    },
 
    [DECOR_TIRE] =
    {
        .id = DECOR_TIRE,
#ifdef CHINESE
        .name = _("TIRE"),       //TODO: 汉化 （低优先度）
#else
        .name = _("TIRE"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_2x2,
        .category = DECORCAT_ORNAMENT,
        .price = 800,
        .description = DecorDesc_TIRE,
        .tiles = DecorGfx_TIRE,
    },
 
    [DECOR_STAND] =
    {
        .id = DECOR_STAND,
#ifdef CHINESE
        .name = _("STAND"),      //TODO: 汉化 （低优先度）
#else
        .name = _("STAND"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_4x2,
        .category = DECORCAT_ORNAMENT,
        .price = 7000,
        .description = DecorDesc_STAND,
        .tiles = DecorGfx_STAND,
    },
 
    [DECOR_MUD_BALL] =
    {
        .id = DECOR_MUD_BALL,
#ifdef CHINESE
        .name = _("MUD BALL"),   //TODO: 汉化 （低优先度）
#else
        .name = _("MUD BALL"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 200,
        .description = DecorDesc_MUD_BALL,
        .tiles = DecorGfx_MUD_BALL,
    },
 
    [DECOR_BREAKABLE_DOOR] =
    {
        .id = DECOR_BREAKABLE_DOOR,
#ifdef CHINESE
        .name = _("BREAKABLE DOOR"),     //TODO: 汉化 （低优先度）
#else
        .name = _("BREAKABLE DOOR"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = DecorDesc_BREAKABLE_DOOR,
        .tiles = DecorGfx_BREAKABLE_DOOR,
    },
 
    [DECOR_SAND_ORNAMENT] =
    {
        .id = DECOR_SAND_ORNAMENT,
#ifdef CHINESE
        .name = _("SAND ORNAMENT"),      //TODO: 汉化 （低优先度）
#else
        .name = _("SAND ORNAMENT"),
#endif
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = DecorDesc_SAND_ORNAMENT,
        .tiles = DecorGfx_SAND_ORNAMENT,
    },
 
    [DECOR_SILVER_SHIELD] =
    {
        .id = DECOR_SILVER_SHIELD,
#ifdef CHINESE
        .name = _("SILVER SHIELD"),      //TODO: 汉化 （低优先度）
#else
        .name = _("SILVER SHIELD"),
#endif
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = DecorDesc_SILVER_SHIELD,
        .tiles = DecorGfx_SILVER_SHIELD,
    },
 
    [DECOR_GOLD_SHIELD] =
    {
        .id = DECOR_GOLD_SHIELD,
#ifdef CHINESE
        .name = _("GOLD SHIELD"),        //TODO: 汉化 （低优先度）
#else
        .name = _("GOLD SHIELD"),
#endif
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = DecorDesc_GOLD_SHIELD,
        .tiles = DecorGfx_GOLD_SHIELD,
    },
 
    [DECOR_GLASS_ORNAMENT] =
    {
        .id = DECOR_GLASS_ORNAMENT,
#ifdef CHINESE
        .name = _("GLASS ORNAMENT"),     //TODO: 汉化 （低优先度）
#else
        .name = _("GLASS ORNAMENT"),
#endif
        .permission = DECORPERM_BEHIND_FLOOR,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_ORNAMENT,
        .price = 0,
        .description = DecorDesc_GLASS_ORNAMENT,
        .tiles = DecorGfx_GLASS_ORNAMENT,
    },
 
    [DECOR_TV] =
    {
        .id = DECOR_TV,
#ifdef CHINESE
        .name = _("TV"),         //TODO: 汉化 （低优先度）
#else
        .name = _("TV"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 3000,
        .description = DecorDesc_TV,
        .tiles = DecorGfx_TV,
    },
 
    [DECOR_ROUND_TV] =
    {
        .id = DECOR_ROUND_TV,
#ifdef CHINESE
        .name = _("ROUND TV"),   //TODO: 汉化 （低优先度）
#else
        .name = _("ROUND TV"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 4000,
        .description = DecorDesc_ROUND_TV,
        .tiles = DecorGfx_ROUND_TV,
    },
 
    [DECOR_CUTE_TV] =
    {
        .id = DECOR_CUTE_TV,
#ifdef CHINESE
        .name = _("CUTE TV"),    //TODO: 汉化 （低优先度）
#else
        .name = _("CUTE TV"),
#endif
        .permission = DECORPERM_SOLID_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_ORNAMENT,
        .price = 4000,
        .description = DecorDesc_CUTE_TV,
        .tiles = DecorGfx_CUTE_TV,
    },
 
    [DECOR_GLITTER_MAT] =
    {
        .id = DECOR_GLITTER_MAT,
#ifdef CHINESE
        .name = _("GLITTER MAT"),        //TODO: 汉化 （低优先度）
#else
        .name = _("GLITTER MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = DecorDesc_GLITTER_MAT,
        .tiles = DecorGfx_GLITTER_MAT,
    },
 
    [DECOR_JUMP_MAT] =
    {
        .id = DECOR_JUMP_MAT,
#ifdef CHINESE
        .name = _("JUMP MAT"),   //TODO: 汉化 （低优先度）
#else
        .name = _("JUMP MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = DecorDesc_JUMP_MAT,
        .tiles = DecorGfx_JUMP_MAT,
    },
 
    [DECOR_SPIN_MAT] =
    {
        .id = DECOR_SPIN_MAT,
#ifdef CHINESE
        .name = _("SPIN MAT"),   //TODO: 汉化 （低优先度）
#else
        .name = _("SPIN MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 2000,
        .description = DecorDesc_SPIN_MAT,
        .tiles = DecorGfx_SPIN_MAT,
    },
 
    [DECOR_C_LOW_NOTE_MAT] =
    {
        .id = DECOR_C_LOW_NOTE_MAT,
#ifdef CHINESE
        .name = _("C Low NOTE MAT"),     //TODO: 汉化 （低优先度）
#else
        .name = _("C Low NOTE MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_C_LOW_NOTE_MAT,
        .tiles = DecorGfx_C_LOW_NOTE_MAT,
    },
 
    [DECOR_D_NOTE_MAT] =
    {
        .id = DECOR_D_NOTE_MAT,
#ifdef CHINESE
        .name = _("D NOTE MAT"),         //TODO: 汉化 （低优先度）
#else
        .name = _("D NOTE MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_D_NOTE_MAT,
        .tiles = DecorGfx_D_NOTE_MAT,
    },
 
    [DECOR_E_NOTE_MAT] =
    {
        .id = DECOR_E_NOTE_MAT,
#ifdef CHINESE
        .name = _("E NOTE MAT"),         //TODO: 汉化 （低优先度）
#else
        .name = _("E NOTE MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_E_NOTE_MAT,
        .tiles = DecorGfx_E_NOTE_MAT,
    },
 
    [DECOR_F_NOTE_MAT] =
    {
        .id = DECOR_F_NOTE_MAT,
#ifdef CHINESE
        .name = _("F NOTE MAT"),         //TODO: 汉化 （低优先度）
#else
        .name = _("F NOTE MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_F_NOTE_MAT,
        .tiles = DecorGfx_F_NOTE_MAT,
    },
 
    [DECOR_G_NOTE_MAT] =
    {
        .id = DECOR_G_NOTE_MAT,
#ifdef CHINESE
        .name = _("G NOTE MAT"),         //TODO: 汉化 （低优先度）
#else
        .name = _("G NOTE MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_G_NOTE_MAT,
        .tiles = DecorGfx_G_NOTE_MAT,
    },
 
    [DECOR_A_NOTE_MAT] =
    {
        .id = DECOR_A_NOTE_MAT,
#ifdef CHINESE
        .name = _("A NOTE MAT"),         //TODO: 汉化 （低优先度）
#else
        .name = _("A NOTE MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_A_NOTE_MAT,
        .tiles = DecorGfx_A_NOTE_MAT,
    },
 
    [DECOR_B_NOTE_MAT] =
    {
        .id = DECOR_B_NOTE_MAT,
#ifdef CHINESE
        .name = _("B NOTE MAT"),         //TODO: 汉化 （低优先度）
#else
        .name = _("B NOTE MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_B_NOTE_MAT,
        .tiles = DecorGfx_B_NOTE_MAT,
    },
 
    [DECOR_C_HIGH_NOTE_MAT] =
    {
        .id = DECOR_C_HIGH_NOTE_MAT,
#ifdef CHINESE
        .name = _("C High NOTE MAT"),    //TODO: 汉化 （低优先度）
#else
        .name = _("C High NOTE MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_MAT,
        .price = 500,
        .description = DecorDesc_C_HIGH_NOTE_MAT,
        .tiles = DecorGfx_C_HIGH_NOTE_MAT,
    },
 
    [DECOR_SURF_MAT] =
    {
        .id = DECOR_SURF_MAT,
#ifdef CHINESE
        .name = _("SURF MAT"),   //TODO: 汉化 （低优先度）
#else
        .name = _("SURF MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_SURF_MAT,
        .tiles = DecorGfx_SURF_MAT,
    },
 
    [DECOR_THUNDER_MAT] =
    {
        .id = DECOR_THUNDER_MAT,
#ifdef CHINESE
        .name = _("THUNDER MAT"),        //TODO: 汉化 （低优先度）
#else
        .name = _("THUNDER MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_THUNDER_MAT,
        .tiles = DecorGfx_THUNDER_MAT,
    },
 
    [DECOR_FIRE_BLAST_MAT] =
    {
        .id = DECOR_FIRE_BLAST_MAT,
#ifdef CHINESE
        .name = _("FIRE BLAST MAT"),     //TODO: 汉化 （低优先度）
#else
        .name = _("FIRE BLAST MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_FIRE_BLAST_MAT,
        .tiles = DecorGfx_FIRE_BLAST_MAT,
    },
 
    [DECOR_POWDER_SNOW_MAT] =
    {
        .id = DECOR_POWDER_SNOW_MAT,
#ifdef CHINESE
        .name = _("POWDER SNOW MAT"),    //TODO: 汉化 （低优先度）
#else
        .name = _("POWDER SNOW MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_POWDER_SNOW_MAT,
        .tiles = DecorGfx_POWDER_SNOW_MAT,
    },
 
    [DECOR_ATTRACT_MAT] =
    {
        .id = DECOR_ATTRACT_MAT,
#ifdef CHINESE
        .name = _("ATTRACT MAT"),        //TODO: 汉化 （低优先度）
#else
        .name = _("ATTRACT MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_ATTRACT_MAT,
        .tiles = DecorGfx_ATTRACT_MAT,
    },
 
    [DECOR_FISSURE_MAT] =
    {
        .id = DECOR_FISSURE_MAT,
#ifdef CHINESE
        .name = _("FISSURE MAT"),        //TODO: 汉化 （低优先度）
#else
        .name = _("FISSURE MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_FISSURE_MAT,
        .tiles = DecorGfx_FISSURE_MAT,
    },
 
    [DECOR_SPIKES_MAT] =
    {
        .id = DECOR_SPIKES_MAT,
#ifdef CHINESE
        .name = _("SPIKES MAT"),         //TODO: 汉化 （低优先度）
#else
        .name = _("SPIKES MAT"),
#endif
        .permission = DECORPERM_PASS_FLOOR,
        .shape = DECORSHAPE_3x3,
        .category = DECORCAT_MAT,
        .price = 4000,
        .description = DecorDesc_SPIKES_MAT,
        .tiles = DecorGfx_SPIKES_MAT,
    },
 
    [DECOR_BALL_POSTER] =
    {
        .id = DECOR_BALL_POSTER,
#ifdef CHINESE
        .name = _("BALL POSTER"),        //TODO: 汉化 （低优先度）
#else
        .name = _("BALL POSTER"),
#endif
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = DecorDesc_BALL_POSTER,
        .tiles = DecorGfx_BALL_POSTER,
    },
 
    [DECOR_GREEN_POSTER] =
    {
        .id = DECOR_GREEN_POSTER,
#ifdef CHINESE
        .name = _("GREEN POSTER"),       //TODO: 汉化 （低优先度）
#else
        .name = _("GREEN POSTER"),
#endif
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = DecorDesc_GREEN_POSTER,
        .tiles = DecorGfx_GREEN_POSTER,
    },
 
    [DECOR_RED_POSTER] =
    {
        .id = DECOR_RED_POSTER,
#ifdef CHINESE
        .name = _("RED POSTER"),         //TODO: 汉化 （低优先度）
#else
        .name = _("RED POSTER"),
#endif
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = DecorDesc_RED_POSTER,
        .tiles = DecorGfx_RED_POSTER,
    },
 
    [DECOR_BLUE_POSTER] =
    {
        .id = DECOR_BLUE_POSTER,
#ifdef CHINESE
        .name = _("BLUE POSTER"),        //TODO: 汉化 （低优先度）
#else
        .name = _("BLUE POSTER"),
#endif
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = DecorDesc_BLUE_POSTER,
        .tiles = DecorGfx_BLUE_POSTER,
    },
 
    [DECOR_CUTE_POSTER] =
    {
        .id = DECOR_CUTE_POSTER,
#ifdef CHINESE
        .name = _("CUTE POSTER"),        //TODO: 汉化 （低优先度）
#else
        .name = _("CUTE POSTER"),
#endif
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_POSTER,
        .price = 1000,
        .description = DecorDesc_CUTE_POSTER,
        .tiles = DecorGfx_CUTE_POSTER,
    },
 
    [DECOR_PIKA_POSTER] =
    {
        .id = DECOR_PIKA_POSTER,
#ifdef CHINESE
        .name = _("PIKA POSTER"),        //TODO: 汉化 （低优先度）
#else
        .name = _("PIKA POSTER"),
#endif
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = DecorDesc_PIKA_POSTER,
        .tiles = DecorGfx_PIKA_POSTER,
    },
 
    [DECOR_LONG_POSTER] =
    {
        .id = DECOR_LONG_POSTER,
#ifdef CHINESE
        .name = _("LONG POSTER"),        //TODO: 汉化 （低优先度）
#else
        .name = _("LONG POSTER"),
#endif
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = DecorDesc_LONG_POSTER,
        .tiles = DecorGfx_LONG_POSTER,
    },
 
    [DECOR_SEA_POSTER] =
    {
        .id = DECOR_SEA_POSTER,
#ifdef CHINESE
        .name = _("SEA POSTER"),         //TODO: 汉化 （低优先度）
#else
        .name = _("SEA POSTER"),
#endif
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = DecorDesc_SEA_POSTER,
        .tiles = DecorGfx_SEA_POSTER,
    },
 
    [DECOR_SKY_POSTER] =
    {
        .id = DECOR_SKY_POSTER,
#ifdef CHINESE
        .name = _("SKY POSTER"),         //TODO: 汉化 （低优先度）
#else
        .name = _("SKY POSTER"),
#endif
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = DecorDesc_SKY_POSTER,
        .tiles = DecorGfx_SKY_POSTER,
    },
 
    [DECOR_KISS_POSTER] =
    {
        .id = DECOR_KISS_POSTER,
#ifdef CHINESE
        .name = _("KISS POSTER"),        //TODO: 汉化 （低优先度）
#else
        .name = _("KISS POSTER"),
#endif
        .permission = DECORPERM_NA_WALL,
        .shape = DECORSHAPE_2x1,
        .category = DECORCAT_POSTER,
        .price = 1500,
        .description = DecorDesc_KISS_POSTER,
        .tiles = DecorGfx_KISS_POSTER,
    },
 
    [DECOR_PICHU_DOLL] =
    {
        .id = DECOR_PICHU_DOLL,
#ifdef CHINESE
        .name = _("PICHU DOLL"),         //TODO: 汉化 （低优先度）
#else
        .name = _("PICHU DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_PICHU_DOLL,
        .tiles = DecorGfx_PICHU_DOLL,
    },
 
    [DECOR_PIKACHU_DOLL] =
    {
        .id = DECOR_PIKACHU_DOLL,
#ifdef CHINESE
        .name = _("PIKACHU DOLL"),       //TODO: 汉化 （低优先度）
#else
        .name = _("PIKACHU DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_PIKACHU_DOLL,
        .tiles = DecorGfx_PIKACHU_DOLL,
    },
 
    [DECOR_MARILL_DOLL] =
    {
        .id = DECOR_MARILL_DOLL,
#ifdef CHINESE
        .name = _("MARILL DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("MARILL DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_MARILL_DOLL,
        .tiles = DecorGfx_MARILL_DOLL,
    },
 
    [DECOR_TOGEPI_DOLL] =
    {
        .id = DECOR_TOGEPI_DOLL,
#ifdef CHINESE
        .name = _("TOGEPI DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("TOGEPI DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_TOGEPI_DOLL,
        .tiles = DecorGfx_TOGEPI_DOLL,
    },
 
    [DECOR_CYNDAQUIL_DOLL] =
    {
        .id = DECOR_CYNDAQUIL_DOLL,
#ifdef CHINESE
        .name = _("CYNDAQUIL DOLL"),     //TODO: 汉化 （低优先度）
#else
        .name = _("CYNDAQUIL DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_CYNDAQUIL_DOLL,
        .tiles = DecorGfx_CYNDAQUIL_DOLL,
    },
 
    [DECOR_CHIKORITA_DOLL] =
    {
        .id = DECOR_CHIKORITA_DOLL,
#ifdef CHINESE
        .name = _("CHIKORITA DOLL"),     //TODO: 汉化 （低优先度）
#else
        .name = _("CHIKORITA DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_CHIKORITA_DOLL,
        .tiles = DecorGfx_CHIKORITA_DOLL,
    },
 
    [DECOR_TOTODILE_DOLL] =
    {
        .id = DECOR_TOTODILE_DOLL,
#ifdef CHINESE
        .name = _("TOTODILE DOLL"),      //TODO: 汉化 （低优先度）
#else
        .name = _("TOTODILE DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_TOTODILE_DOLL,
        .tiles = DecorGfx_TOTODILE_DOLL,
    },
 
    [DECOR_JIGGLYPUFF_DOLL] =
    {
        .id = DECOR_JIGGLYPUFF_DOLL,
#ifdef CHINESE
        .name = _("JIGGLYPUFF DOLL"),    //TODO: 汉化 （低优先度）
#else
        .name = _("JIGGLYPUFF DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_JIGGLYPUFF_DOLL,
        .tiles = DecorGfx_JIGGLYPUFF_DOLL,
    },
 
    [DECOR_MEOWTH_DOLL] =
    {
        .id = DECOR_MEOWTH_DOLL,
#ifdef CHINESE
        .name = _("MEOWTH DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("MEOWTH DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_MEOWTH_DOLL,
        .tiles = DecorGfx_MEOWTH_DOLL,
    },
 
    [DECOR_CLEFAIRY_DOLL] =
    {
        .id = DECOR_CLEFAIRY_DOLL,
#ifdef CHINESE
        .name = _("CLEFAIRY DOLL"),      //TODO: 汉化 （低优先度）
#else
        .name = _("CLEFAIRY DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_CLEFAIRY_DOLL,
        .tiles = DecorGfx_CLEFAIRY_DOLL,
    },
 
    [DECOR_DITTO_DOLL] =
    {
        .id = DECOR_DITTO_DOLL,
#ifdef CHINESE
        .name = _("DITTO DOLL"),         //TODO: 汉化 （低优先度）
#else
        .name = _("DITTO DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_DITTO_DOLL,
        .tiles = DecorGfx_DITTO_DOLL,
    },
 
    [DECOR_SMOOCHUM_DOLL] =
    {
        .id = DECOR_SMOOCHUM_DOLL,
#ifdef CHINESE
        .name = _("SMOOCHUM DOLL"),      //TODO: 汉化 （低优先度）
#else
        .name = _("SMOOCHUM DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_SMOOCHUM_DOLL,
        .tiles = DecorGfx_SMOOCHUM_DOLL,
    },
 
    [DECOR_TREECKO_DOLL] =
    {
        .id = DECOR_TREECKO_DOLL,
#ifdef CHINESE
        .name = _("TREECKO DOLL"),       //TODO: 汉化 （低优先度）
#else
        .name = _("TREECKO DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_TREECKO_DOLL,
        .tiles = DecorGfx_TREECKO_DOLL,
    },
 
    [DECOR_TORCHIC_DOLL] =
    {
        .id = DECOR_TORCHIC_DOLL,
#ifdef CHINESE
        .name = _("TORCHIC DOLL"),       //TODO: 汉化 （低优先度）
#else
        .name = _("TORCHIC DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_TORCHIC_DOLL,
        .tiles = DecorGfx_TORCHIC_DOLL,
    },
 
    [DECOR_MUDKIP_DOLL] =
    {
        .id = DECOR_MUDKIP_DOLL,
#ifdef CHINESE
        .name = _("MUDKIP DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("MUDKIP DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_MUDKIP_DOLL,
        .tiles = DecorGfx_MUDKIP_DOLL,
    },
 
    [DECOR_DUSKULL_DOLL] =
    {
        .id = DECOR_DUSKULL_DOLL,
#ifdef CHINESE
        .name = _("DUSKULL DOLL"),       //TODO: 汉化 （低优先度）
#else
        .name = _("DUSKULL DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_DUSKULL_DOLL,
        .tiles = DecorGfx_DUSKULL_DOLL,
    },
 
    [DECOR_WYNAUT_DOLL] =
    {
        .id = DECOR_WYNAUT_DOLL,
#ifdef CHINESE
        .name = _("WYNAUT DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("WYNAUT DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_WYNAUT_DOLL,
        .tiles = DecorGfx_WYNAUT_DOLL,
    },
 
    [DECOR_BALTOY_DOLL] =
    {
        .id = DECOR_BALTOY_DOLL,
#ifdef CHINESE
        .name = _("BALTOY DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("BALTOY DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_BALTOY_DOLL,
        .tiles = DecorGfx_BALTOY_DOLL,
    },
 
    [DECOR_KECLEON_DOLL] =
    {
        .id = DECOR_KECLEON_DOLL,
#ifdef CHINESE
        .name = _("KECLEON DOLL"),       //TODO: 汉化 （低优先度）
#else
        .name = _("KECLEON DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_KECLEON_DOLL,
        .tiles = DecorGfx_KECLEON_DOLL,
    },
 
    [DECOR_AZURILL_DOLL] =
    {
        .id = DECOR_AZURILL_DOLL,
#ifdef CHINESE
        .name = _("AZURILL DOLL"),       //TODO: 汉化 （低优先度）
#else
        .name = _("AZURILL DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_AZURILL_DOLL,
        .tiles = DecorGfx_AZURILL_DOLL,
    },
 
    [DECOR_SKITTY_DOLL] =
    {
        .id = DECOR_SKITTY_DOLL,
#ifdef CHINESE
        .name = _("SKITTY DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("SKITTY DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_SKITTY_DOLL,
        .tiles = DecorGfx_SKITTY_DOLL,
    },
 
    [DECOR_SWABLU_DOLL] =
    {
        .id = DECOR_SWABLU_DOLL,
#ifdef CHINESE
        .name = _("SWABLU DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("SWABLU DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_SWABLU_DOLL,
        .tiles = DecorGfx_SWABLU_DOLL,
    },
 
    [DECOR_GULPIN_DOLL] =
    {
        .id = DECOR_GULPIN_DOLL,
#ifdef CHINESE
        .name = _("GULPIN DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("GULPIN DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_GULPIN_DOLL,
        .tiles = DecorGfx_GULPIN_DOLL,
    },
 
    [DECOR_LOTAD_DOLL] =
    {
        .id = DECOR_LOTAD_DOLL,
#ifdef CHINESE
        .name = _("LOTAD DOLL"),         //TODO: 汉化 （低优先度）
#else
        .name = _("LOTAD DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_LOTAD_DOLL,
        .tiles = DecorGfx_LOTAD_DOLL,
    },
 
    [DECOR_SEEDOT_DOLL] =
    {
        .id = DECOR_SEEDOT_DOLL,
#ifdef CHINESE
        .name = _("SEEDOT DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("SEEDOT DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_DOLL,
        .price = 3000,
        .description = DecorDesc_SEEDOT_DOLL,
        .tiles = DecorGfx_SEEDOT_DOLL,
    },
 
    [DECOR_PIKA_CUSHION] =
    {
        .id = DECOR_PIKA_CUSHION,
#ifdef CHINESE
        .name = _("PIKA CUSHION"),       //TODO: 汉化 （低优先度）
#else
        .name = _("PIKA CUSHION"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_PIKA_CUSHION,
        .tiles = DecorGfx_PIKA_CUSHION,
    },
 
    [DECOR_ROUND_CUSHION] =
    {
        .id = DECOR_ROUND_CUSHION,
#ifdef CHINESE
        .name = _("ROUND CUSHION"),      //TODO: 汉化 （低优先度）
#else
        .name = _("ROUND CUSHION"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_ROUND_CUSHION,
        .tiles = DecorGfx_ROUND_CUSHION,
    },
 
    [DECOR_KISS_CUSHION] =
    {
        .id = DECOR_KISS_CUSHION,
#ifdef CHINESE
        .name = _("KISS CUSHION"),       //TODO: 汉化 （低优先度）
#else
        .name = _("KISS CUSHION"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_KISS_CUSHION,
        .tiles = DecorGfx_KISS_CUSHION,
    },
 
    [DECOR_ZIGZAG_CUSHION] =
    {
        .id = DECOR_ZIGZAG_CUSHION,
#ifdef CHINESE
        .name = _("ZIGZAG CUSHION"),     //TODO: 汉化 （低优先度）
#else
        .name = _("ZIGZAG CUSHION"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_ZIGZAG_CUSHION,
        .tiles = DecorGfx_ZIGZAG_CUSHION,
    },
 
    [DECOR_SPIN_CUSHION] =
    {
        .id = DECOR_SPIN_CUSHION,
#ifdef CHINESE
        .name = _("SPIN CUSHION"),       //TODO: 汉化 （低优先度）
#else
        .name = _("SPIN CUSHION"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_SPIN_CUSHION,
        .tiles = DecorGfx_SPIN_CUSHION,
    },
 
    [DECOR_DIAMOND_CUSHION] =
    {
        .id = DECOR_DIAMOND_CUSHION,
#ifdef CHINESE
        .name = _("DIAMOND CUSHION"),    //TODO: 汉化 （低优先度）
#else
        .name = _("DIAMOND CUSHION"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_DIAMOND_CUSHION,
        .tiles = DecorGfx_DIAMOND_CUSHION,
    },
 
    [DECOR_BALL_CUSHION] =
    {
        .id = DECOR_BALL_CUSHION,
#ifdef CHINESE
        .name = _("BALL CUSHION"),       //TODO: 汉化 （低优先度）
#else
        .name = _("BALL CUSHION"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_BALL_CUSHION,
        .tiles = DecorGfx_BALL_CUSHION,
    },
 
    [DECOR_GRASS_CUSHION] =
    {
        .id = DECOR_GRASS_CUSHION,
#ifdef CHINESE
        .name = _("GRASS CUSHION"),      //TODO: 汉化 （低优先度）
#else
        .name = _("GRASS CUSHION"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_GRASS_CUSHION,
        .tiles = DecorGfx_GRASS_CUSHION,
    },
 
    [DECOR_FIRE_CUSHION] =
    {
        .id = DECOR_FIRE_CUSHION,
#ifdef CHINESE
        .name = _("FIRE CUSHION"),       //TODO: 汉化 （低优先度）
#else
        .name = _("FIRE CUSHION"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_FIRE_CUSHION,
        .tiles = DecorGfx_FIRE_CUSHION,
    },
 
    [DECOR_WATER_CUSHION] =
    {
        .id = DECOR_WATER_CUSHION,
#ifdef CHINESE
        .name = _("WATER CUSHION"),      //TODO: 汉化 （低优先度）
#else
        .name = _("WATER CUSHION"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x1,
        .category = DECORCAT_CUSHION,
        .price = 2000,
        .description = DecorDesc_WATER_CUSHION,
        .tiles = DecorGfx_WATER_CUSHION,
    },
 
    [DECOR_SNORLAX_DOLL] =
    {
        .id = DECOR_SNORLAX_DOLL,
#ifdef CHINESE
        .name = _("SNORLAX DOLL"),       //TODO: 汉化 （低优先度）
#else
        .name = _("SNORLAX DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_SNORLAX_DOLL,
        .tiles = DecorGfx_SNORLAX_DOLL,
    },
 
    [DECOR_RHYDON_DOLL] =
    {
        .id = DECOR_RHYDON_DOLL,
#ifdef CHINESE
        .name = _("RHYDON DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("RHYDON DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_RHYDON_DOLL,
        .tiles = DecorGfx_RHYDON_DOLL,
    },
 
    [DECOR_LAPRAS_DOLL] =
    {
        .id = DECOR_LAPRAS_DOLL,
#ifdef CHINESE
        .name = _("LAPRAS DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("LAPRAS DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_LAPRAS_DOLL,
        .tiles = DecorGfx_LAPRAS_DOLL,
    },
 
    [DECOR_VENUSAUR_DOLL] =
    {
        .id = DECOR_VENUSAUR_DOLL,
#ifdef CHINESE
        .name = _("VENUSAUR DOLL"),      //TODO: 汉化 （低优先度）
#else
        .name = _("VENUSAUR DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_VENUSAUR_DOLL,
        .tiles = DecorGfx_VENUSAUR_DOLL,
    },
 
    [DECOR_CHARIZARD_DOLL] =
    {
        .id = DECOR_CHARIZARD_DOLL,
#ifdef CHINESE
        .name = _("CHARIZARD DOLL"),     //TODO: 汉化 （低优先度）
#else
        .name = _("CHARIZARD DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_CHARIZARD_DOLL,
        .tiles = DecorGfx_CHARIZARD_DOLL,
    },
 
    [DECOR_BLASTOISE_DOLL] =
    {
        .id = DECOR_BLASTOISE_DOLL,
#ifdef CHINESE
        .name = _("BLASTOISE DOLL"),     //TODO: 汉化 （低优先度）
#else
        .name = _("BLASTOISE DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_BLASTOISE_DOLL,
        .tiles = DecorGfx_BLASTOISE_DOLL,
    },
 
    [DECOR_WAILMER_DOLL] =
    {
        .id = DECOR_WAILMER_DOLL,
#ifdef CHINESE
        .name = _("WAILMER DOLL"),       //TODO: 汉化 （低优先度）
#else
        .name = _("WAILMER DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_WAILMER_DOLL,
        .tiles = DecorGfx_WAILMER_DOLL,
    },
 
    [DECOR_REGIROCK_DOLL] =
    {
        .id = DECOR_REGIROCK_DOLL,
#ifdef CHINESE
        .name = _("REGIROCK DOLL"),      //TODO: 汉化 （低优先度）
#else
        .name = _("REGIROCK DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_REGIROCK_DOLL,
        .tiles = DecorGfx_REGIROCK_DOLL,
    },
 
    [DECOR_REGICE_DOLL] =
    {
        .id = DECOR_REGICE_DOLL,
#ifdef CHINESE
        .name = _("REGICE DOLL"),        //TODO: 汉化 （低优先度）
#else
        .name = _("REGICE DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_REGICE_DOLL,
        .tiles = DecorGfx_REGICE_DOLL,
    },
 
    [DECOR_REGISTEEL_DOLL] =
    {
        .id = DECOR_REGISTEEL_DOLL,
#ifdef CHINESE
        .name = _("REGISTEEL DOLL"),     //TODO: 汉化 （低优先度）
#else
        .name = _("REGISTEEL DOLL"),
#endif
        .permission = DECORPERM_SPRITE,
        .shape = DECORSHAPE_1x2,
        .category = DECORCAT_DOLL,
        .price = 10000,
        .description = DecorDesc_REGISTEEL_DOLL,
        .tiles = DecorGfx_REGISTEEL_DOLL,
    }
};
