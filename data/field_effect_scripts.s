	.include "asm/macros.inc"
	.include "constants/constants.inc"

	.section script_data, "aw", %progbits

	.align 2
gFieldEffectScriptPointers::
	.4byte gFieldEffectScript_ExclamationMarkIcon1      @ FLDEFF_EXCLAMATION_MARK_ICON
	.4byte gFieldEffectScript_UseCutOnTallGrass         @ FLDEFF_USE_CUT_ON_GRASS
	.4byte gFieldEffectScript_UseCutOnTree              @ FLDEFF_USE_CUT_ON_TREE
	.4byte gFieldEffectScript_Shadow                    @ FLDEFF_SHADOW
	.4byte gFieldEffectScript_TallGrass                 @ FLDEFF_TALL_GRASS
	.4byte gFieldEffectScript_Ripple                    @ FLDEFF_RIPPLE
	.4byte gFieldEffectScript_FieldMoveShowMon          @ FLDEFF_FIELD_MOVE_SHOW_MON
	.4byte gFieldEffectScript_Ash                       @ FLDEFF_ASH
	.4byte gFieldEffectScript_SurfBlob                  @ FLDEFF_SURF_BLOB
	.4byte gFieldEffectScript_UseSurf                   @ FLDEFF_USE_SURF
	.4byte gFieldEffectScript_GroundImpactDust          @ FLDEFF_DUST
	.4byte gFieldEffectScript_UseSecretPowerCave        @ FLDEFF_USE_SECRET_POWER_CAVE
	.4byte gFieldEffectScript_JumpTallGrass             @ FLDEFF_JUMP_TALL_GRASS
	.4byte gFieldEffectScript_SandFootprints            @ FLDEFF_SAND_FOOTPRINTS
	.4byte gFieldEffectScript_JumpBigSplash             @ FLDEFF_JUMP_BIG_SPLASH
	.4byte gFieldEffectScript_Splash                    @ FLDEFF_SPLASH
	.4byte gFieldEffectScript_JumpSmallSplash           @ FLDEFF_JUMP_SMALL_SPLASH
	.4byte gFieldEffectScript_LongGrass                 @ FLDEFF_LONG_GRASS
	.4byte gFieldEffectScript_JumpLongGrass             @ FLDEFF_JUMP_LONG_GRASS
	.4byte gFieldEffectScript_UnusedGrass               @ FLDEFF_UNUSED_GRASS
	.4byte gFieldEffectScript_UnusedGrass2              @ FLDEFF_UNUSED_GRASS_2
	.4byte gFieldEffectScript_UnusedSand                @ FLDEFF_UNUSED_SAND
	.4byte gFieldEffectScript_WaterSurfacing            @ FLDEFF_WATER_SURFACING
	.4byte gFieldEffectScript_BerryTreeGrowthSparkle    @ FLDEFF_BERRY_TREE_GROWTH_SPARKLE
	.4byte gFieldEffectScript_DeepSandFootprints        @ FLDEFF_DEEP_SAND_FOOTPRINTS
	.4byte gFieldEffectScript_PokeCenterHeal            @ FLDEFF_POKECENTER_HEAL
	.4byte gFieldEffectScript_UseSecretPowerTree        @ FLDEFF_USE_SECRET_POWER_TREE
	.4byte gFieldEffectScript_UseSecretPowerShrub       @ FLDEFF_USE_SECRET_POWER_SHRUB
	.4byte gFieldEffectScript_TreeDisguise              @ FLDEFF_TREE_DISGUISE
	.4byte gFieldEffectScript_MountainDisguise          @ FLDEFF_MOUNTAIN_DISGUISE
	.4byte gFieldEffectScript_NPCUseFly                 @ FLDEFF_NPCFLY_OUT
	.4byte gFieldEffectScript_UseFly                    @ FLDEFF_USE_FLY
	.4byte gFieldEffectScript_FlyIn                     @ FLDEFF_FLY_IN
	.4byte gFieldEffectScript_QuestionMarkIcon          @ FLDEFF_QUESTION_MARK_ICON
	.4byte gFieldEffectScript_FeetInFlowingWater        @ FLDEFF_FEET_IN_FLOWING_WATER
	.4byte gFieldEffectScript_BikeTireTracks            @ FLDEFF_BIKE_TIRE_TRACKS
	.4byte gFieldEffectScript_SandDisguisePlaceholder   @ FLDEFF_SAND_DISGUISE
	.4byte gFieldEffectScript_UseRockSmash              @ FLDEFF_USE_ROCK_SMASH
	.4byte gFieldEffectScript_UseDig                    @ FLDEFF_USE_DIG
	.4byte gFieldEffectScript_SandPile                  @ FLDEFF_SAND_PILE
	.4byte gFieldEffectScript_UseStrength               @ FLDEFF_USE_STRENGTH
	.4byte gFieldEffectScript_ShortGrass                @ FLDEFF_SHORT_GRASS
	.4byte gFieldEffectScript_HotSpringsWater           @ FLDEFF_HOT_SPRINGS_WATER
	.4byte gFieldEffectScript_UseWaterfall              @ FLDEFF_USE_WATERFALL
	.4byte gFieldEffectScript_UseDive                   @ FLDEFF_USE_DIVE
	.4byte gFieldEffectScript_Pokeball                  @ FLDEFF_POKEBALL
	.4byte gFieldEffectScript_HeartIcon                 @ FLDEFF_HEART_ICON
	.4byte gFieldEffectScript_Nop47                     @ FLDEFF_NOP_47
	.4byte gFieldEffectScript_Nop48                     @ FLDEFF_NOP_48
	.4byte gFieldEffectScript_AshPuff                   @ FLDEFF_ASH_PUFF
	.4byte gFieldEffectScript_AshLaunch                 @ FLDEFF_ASH_LAUNCH
	.4byte gFieldEffectScript_SweetScent                @ FLDEFF_SWEET_SCENT
	.4byte gFieldEffectScript_SandPillar                @ FLDEFF_SAND_PILLAR
	.4byte gFieldEffectScript_Bubbles                   @ FLDEFF_BUBBLES
	.4byte gFieldEffectScript_Sparkle                   @ FLDEFF_SPARKLE
	.4byte gFieldEffectScript_ShowSecretPowerCave       @ FLDEFF_SECRET_POWER_CAVE
	.4byte gFieldEffectScript_ShowSecretPowerTree       @ FLDEFF_SECRET_POWER_TREE
	.4byte gFieldEffectScript_ShowSecretPowerShrub      @ FLDEFF_SECRET_POWER_SHRUB
	.4byte gFieldEffectScript_ShowCutGrass              @ FLDEFF_CUT_GRASS
	.4byte gFieldEffectScript_FieldMoveShowMonInit      @ FLDEFF_FIELD_MOVE_SHOW_MON_INIT
	.4byte gFieldEffectScript_UsePuzzleEffect           @ FLDEFF_USE_TOMB_PUZZLE_EFFECT
	.4byte gFieldEffectScript_SecretBaseBootPC          @ FLDEFF_PCTURN_ON
	.4byte gFieldEffectScript_HallOfFameRecord          @ FLDEFF_HALL_OF_FAME_RECORD
	.4byte gFieldEffectScript_UseTeleport               @ FLDEFF_USE_TELEPORT
	.4byte gFieldEffectScript_RayquazaSpotlight         @ FLDEFF_RAYQUAZA_SPOTLIGHT
	.4byte gFieldEffectScript_DestroyDeoxysRock         @ FLDEFF_DESTROY_DEOXYS_ROCK
	.4byte gFieldEffectScript_MoveDeoxysRock            @ FLDEFF_MOVE_DEOXYS_ROCK
	.4byte gFieldEffectScript_DotDotDotIcon				@ FLDEFF_DOTDOTDOT_ICON
	.4byte gFieldEffectScript_AngryIcon					@ FLDEFF_ANGRY_ICON
	.4byte gFieldEffectScript_SweatIcon					@ FLDEFF_SWEAT_ICON
	.4byte gFieldEffectScript_ExclamationMark2Icon		@ FLDEFF_EXCLAMATION_MARK_2_ICON
	.4byte gFieldEffectScript_BulbIcon					@ FLDEFF_BULB_ICON
	.4byte gFieldEffectScript_SpeechlessIcon			@ FLDEFF_SPEECHLESS_ICON
	.4byte gFieldEffectScript_MusicIcon					@ FLDEFF_MUSIC_ICON
	.4byte gFieldEffectScript_CircleIcon				@ FLDEFF_CIRCLE_ICON
	.4byte gFieldEffectScript_SleepyIcon				@ FLDEFF_SLEEPY_ICON
	.4byte gFieldEffectScript_CrossIcon					@ FLDEFF_CROSS_ICON
	.4byte gFieldEffectScript_StarIcon					@ FLDEFF_STAR_ICON
	.4byte gFieldEffectScript_FunnnyIcon				@ FLDEFF_FUNNY_ICON
	.4byte gFieldEffectScript_VommitIcon				@ FLDEFF_VOMMIT_ICON
	.4byte gFieldEffectScript_SmileIcon					@ FLDEFF_SMILE_ICON
	.4byte gFieldEffectScript_FacePalmIcon				@ FLDEFF_FACE_PALM_ICON
	.4byte gFieldEffectScript_BombedIcon				@ FLDEFF_BOMBED_ICON
	.4byte gFieldEffectScript_DogeIcon					@ FLDEFF_DOGE_ICON
	.4byte gFieldEffectScript_EvilIcon					@ FLDEFF_EVIL_ICON
	.4byte gFieldEffectScript_Sweat2Icon				@ FLDEFF_SWEAT_2_ICON
	.4byte gFieldEffectScript_SkullIcon					@ FLDEFF_SKULL_ICON
	.4byte gFieldEffectScript_SwordIcon					@ FLDEFF_SWORD_ICON
	.4byte gFieldEffectScript_CreeperIcon				@ FLDEFF_CREEPER_ICON
	.4byte gFieldEffectScript_SpitBloodIcon				@ FLDEFF_SPIT_BLOOD_ICON
	.4byte gFieldEffectScript_InterestingIcon			@ FLDEFF_INTERESTING_ICON

gFieldEffectScript_ExclamationMarkIcon1::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_ExclamationMarkIcon
	field_eff_end

gFieldEffectScript_UseCutOnTallGrass::
	field_eff_callnative FldEff_UseCutOnGrass
	field_eff_end

gFieldEffectScript_UseCutOnTree::
	field_eff_callnative FldEff_UseCutOnTree
	field_eff_end

gFieldEffectScript_Shadow::
	field_eff_callnative FldEff_Shadow
	field_eff_end

gFieldEffectScript_TallGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_TallGrass
	field_eff_end

gFieldEffectScript_Ripple::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_Ripple
	field_eff_end

gFieldEffectScript_FieldMoveShowMon::
	field_eff_callnative FldEff_FieldMoveShowMon
	field_eff_end

gFieldEffectScript_Ash::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_Ash
	field_eff_end

gFieldEffectScript_SurfBlob::
	field_eff_callnative FldEff_SurfBlob
	field_eff_end

gFieldEffectScript_UseSurf::
	field_eff_callnative FldEff_UseSurf
	field_eff_end

gFieldEffectScript_GroundImpactDust::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_Dust
	field_eff_end

gFieldEffectScript_UseSecretPowerCave::
	field_eff_callnative FldEff_UseSecretPowerCave
	field_eff_end

gFieldEffectScript_JumpTallGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_JumpTallGrass
	field_eff_end

gFieldEffectScript_SandFootprints::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_SandFootprints
	field_eff_end

gFieldEffectScript_JumpBigSplash::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_JumpBigSplash
	field_eff_end

gFieldEffectScript_Splash::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_Splash
	field_eff_end

gFieldEffectScript_JumpSmallSplash::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_JumpSmallSplash
	field_eff_end

gFieldEffectScript_LongGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_LongGrass
	field_eff_end

gFieldEffectScript_JumpLongGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_JumpLongGrass
	field_eff_end

gFieldEffectScript_UnusedGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_UnusedGrass
	field_eff_end

gFieldEffectScript_UnusedGrass2::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_UnusedGrass2
	field_eff_end

gFieldEffectScript_UnusedSand::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_UnusedSand
	field_eff_end

gFieldEffectScript_WaterSurfacing::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_WaterSurfacing
	field_eff_end

gFieldEffectScript_BerryTreeGrowthSparkle::
	field_eff_callnative FldEff_BerryTreeGrowthSparkle
	field_eff_end

gFieldEffectScript_DeepSandFootprints::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_DeepSandFootprints
	field_eff_end

gFieldEffectScript_PokeCenterHeal::
	field_eff_loadfadedpal gSpritePalette_PokeballGlow
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_PokecenterHeal
	field_eff_end

gFieldEffectScript_UseSecretPowerTree::
	field_eff_callnative FldEff_UseSecretPowerTree
	field_eff_end

gFieldEffectScript_UseSecretPowerShrub::
	field_eff_callnative FldEff_UseSecretPowerShrub
	field_eff_end

gFieldEffectScript_TreeDisguise::
	field_eff_callnative ShowTreeDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_MountainDisguise::
	field_eff_callnative ShowMountainDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_NPCUseFly::
	field_eff_callnative FldEff_NPCFlyOut
	field_eff_end

gFieldEffectScript_UseFly::
	field_eff_callnative FldEff_UseFly
	field_eff_end

gFieldEffectScript_FlyIn::
	field_eff_callnative FldEff_FlyIn
	field_eff_end

gFieldEffectScript_QuestionMarkIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_QuestionMarkIcon
	field_eff_end

gFieldEffectScript_FeetInFlowingWater::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_FeetInFlowingWater
	field_eff_end

gFieldEffectScript_BikeTireTracks::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_BikeTireTracks
	field_eff_end

gFieldEffectScript_SandDisguisePlaceholder::
	field_eff_callnative ShowSandDisguiseFieldEffect
	field_eff_end

gFieldEffectScript_UseRockSmash::
	field_eff_callnative FldEff_UseRockSmash
	field_eff_end

gFieldEffectScript_UseStrength::
	field_eff_callnative FldEff_UseStrength
	field_eff_end

gFieldEffectScript_UseDig::
	field_eff_callnative FldEff_UseDig
	field_eff_end

gFieldEffectScript_SandPile::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_SandPile
	field_eff_end

gFieldEffectScript_ShortGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_ShortGrass
	field_eff_end

gFieldEffectScript_HotSpringsWater::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect1, FldEff_HotSpringsWater
	field_eff_end

gFieldEffectScript_UseWaterfall::
	field_eff_callnative FldEff_UseWaterfall
	field_eff_end

gFieldEffectScript_UseDive::
	field_eff_callnative FldEff_UseDive
	field_eff_end

gFieldEffectScript_Pokeball::
	field_eff_loadpal gSpritePalette_Pokeball
	field_eff_callnative FldEff_Pokeball
	field_eff_end

gFieldEffectScript_HeartIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_HeartIcon
	field_eff_end

gFieldEffectScript_Nop47::
	field_eff_callnative FldEff_Nop47
	field_eff_end

gFieldEffectScript_Nop48::
	field_eff_callnative FldEff_Nop48
	field_eff_end

gFieldEffectScript_AshPuff::
	field_eff_loadfadedpal_callnative gSpritePalette_Ash, FldEff_AshPuff
	field_eff_end

gFieldEffectScript_AshLaunch::
	field_eff_loadfadedpal_callnative gSpritePalette_Ash, FldEff_AshLaunch
	field_eff_end

gFieldEffectScript_SweetScent::
	field_eff_callnative FldEff_SweetScent
	field_eff_end

gFieldEffectScript_SandPillar::
	field_eff_loadfadedpal_callnative gSpritePalette_SandPillar, FldEff_SandPillar
	field_eff_end

gFieldEffectScript_Bubbles::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEffect0, FldEff_Bubbles
	field_eff_end

gFieldEffectScript_Sparkle::
	field_eff_loadfadedpal_callnative gSpritePalette_SmallSparkle, FldEff_Sparkle
	field_eff_end

gFieldEffectScript_ShowSecretPowerCave::
	field_eff_loadfadedpal_callnative gSpritePalette_SecretPower_Cave, FldEff_SecretPowerCave
	field_eff_end

gFieldEffectScript_ShowSecretPowerTree::
	field_eff_loadfadedpal_callnative gSpritePalette_SecretPower_Plant, FldEff_SecretPowerTree
	field_eff_end

gFieldEffectScript_ShowSecretPowerShrub::
	field_eff_loadfadedpal_callnative gSpritePalette_SecretPower_Plant, FldEff_SecretPowerShrub
	field_eff_end

gFieldEffectScript_ShowCutGrass::
	field_eff_loadfadedpal_callnative gSpritePalette_CutGrass, FldEff_CutGrass
	field_eff_end

gFieldEffectScript_FieldMoveShowMonInit::
	field_eff_callnative FldEff_FieldMoveShowMonInit
	field_eff_end

gFieldEffectScript_UsePuzzleEffect::
	field_eff_callnative FldEff_UsePuzzleEffect
	field_eff_end

gFieldEffectScript_SecretBaseBootPC::
	field_eff_callnative FldEff_SecretBasePCTurnOn
	field_eff_end

gFieldEffectScript_HallOfFameRecord::
	field_eff_loadfadedpal gSpritePalette_PokeballGlow
	field_eff_loadfadedpal_callnative gSpritePalette_HofMonitor, FldEff_HallOfFameRecord
	field_eff_end

gFieldEffectScript_UseTeleport::
	field_eff_callnative FldEff_UseTeleport
	field_eff_end

gFieldEffectScript_RayquazaSpotlight::
	field_eff_callnative FldEff_RayquazaSpotlight
	field_eff_end

gFieldEffectScript_DestroyDeoxysRock::
	field_eff_callnative FldEff_DestroyDeoxysRock
	field_eff_end

gFieldEffectScript_MoveDeoxysRock::
	field_eff_callnative FldEff_MoveDeoxysRock
	field_eff_end

gFieldEffectScript_DotDotDotIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_DotDotDotIcon
	field_eff_end

gFieldEffectScript_AngryIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_AngryIcon
	field_eff_end

gFieldEffectScript_SweatIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_SweatIcon
	field_eff_end

gFieldEffectScript_ExclamationMark2Icon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_ExclamationMark2Icon
	field_eff_end

gFieldEffectScript_BulbIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_BulbIcon
	field_eff_end

gFieldEffectScript_SpeechlessIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_SpeechlessIcon
	field_eff_end

gFieldEffectScript_MusicIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_MusicIcon
	field_eff_end

gFieldEffectScript_CircleIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_CircleIcon
	field_eff_end

gFieldEffectScript_SleepyIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_SleepyIcon
	field_eff_end

gFieldEffectScript_CrossIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_CrossIcon
	field_eff_end

gFieldEffectScript_StarIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_StarIcon
	field_eff_end

gFieldEffectScript_FunnnyIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_FunnnyIcon
	field_eff_end

gFieldEffectScript_VommitIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_VommitIcon
	field_eff_end

gFieldEffectScript_SmileIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_SmileIcon
	field_eff_end

gFieldEffectScript_FacePalmIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_FacePalmIcon
	field_eff_end

gFieldEffectScript_BombedIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_BombedIcon
	field_eff_end

gFieldEffectScript_DogeIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_DogeIcon
	field_eff_end

gFieldEffectScript_EvilIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_EvilIcon
	field_eff_end

gFieldEffectScript_Sweat2Icon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_Sweat2Icon
	field_eff_end

gFieldEffectScript_SkullIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_SkullIcon
	field_eff_end

gFieldEffectScript_SwordIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_SwordIcon
	field_eff_end

gFieldEffectScript_CreeperIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_CreeperIcon
	field_eff_end

gFieldEffectScript_SpitBloodIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_SpitBloodIcon
	field_eff_end

gFieldEffectScript_InterestingIcon::
	field_eff_loadfadedpal_callnative gSpritePalette_GeneralFieldEmotion, FldEff_InterestingIcon
	field_eff_end
