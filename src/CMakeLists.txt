set ( root_src
  lodepng.cpp
  main.cpp
)

set ( basescape_src
  Basescape/BaseInfoState.cpp
  Basescape/BaseView.cpp
  Basescape/BasescapeState.cpp
  Basescape/BuildFacilitiesState.cpp
  Basescape/CraftArmorState.cpp
  Basescape/CraftEquipmentState.cpp
  Basescape/CraftInfoState.cpp
  Basescape/CraftSoldiersState.cpp
  Basescape/CraftWeaponsState.cpp
  Basescape/CraftsState.cpp
  Basescape/DismantleFacilityState.cpp
  Basescape/ManageAlienContainmentState.cpp
  Basescape/ManufactureInfoState.cpp
  Basescape/ManufactureStartState.cpp
  Basescape/ManufactureState.cpp
  Basescape/MiniBaseView.cpp
  Basescape/MonthlyCostsState.cpp
  Basescape/NewManufactureListState.cpp
  Basescape/NewResearchListState.cpp
  Basescape/PlaceFacilityState.cpp
  Basescape/PlaceLiftState.cpp
  Basescape/PlaceStartFacilityState.cpp
  Basescape/PurchaseState.cpp
  Basescape/ResearchInfoState.cpp
  Basescape/ResearchState.cpp
  Basescape/SackSoldierState.cpp
  Basescape/SelectStartFacilityState.cpp
  Basescape/SellState.cpp
  Basescape/SoldierArmorState.cpp
  Basescape/SoldierDiaryMissionState.cpp
  Basescape/SoldierDiaryOverviewState.cpp
  Basescape/SoldierDiaryPerformanceState.cpp
  Basescape/SoldierInfoState.cpp
  Basescape/SoldierMemorialState.cpp
  Basescape/SoldiersState.cpp
  Basescape/StoresState.cpp
  Basescape/TransferBaseState.cpp
  Basescape/TransferConfirmState.cpp
  Basescape/TransferItemsState.cpp
  Basescape/TransfersState.cpp
)

set ( battlescape_src
  Battlescape/AbortMissionState.cpp
  Battlescape/ActionMenuItem.cpp
  Battlescape/ActionMenuState.cpp
  Battlescape/AliensCrashState.cpp
  Battlescape/AIModule.cpp
  Battlescape/BattleState.cpp
  Battlescape/BattlescapeGame.cpp
  Battlescape/BattlescapeGenerator.cpp
  Battlescape/BattlescapeMessage.cpp
  Battlescape/BattlescapeState.cpp
  Battlescape/BriefingState.cpp
  Battlescape/Camera.cpp
  Battlescape/CannotReequipState.cpp
  Battlescape/CommendationLateState.cpp
  Battlescape/CommendationState.cpp
  Battlescape/DebriefingState.cpp
  Battlescape/Explosion.cpp
  Battlescape/ExplosionBState.cpp
  Battlescape/InfoboxOKState.cpp
  Battlescape/InfoboxState.cpp
  Battlescape/Inventory.cpp
  Battlescape/InventoryState.cpp
  Battlescape/Map.cpp
  Battlescape/MedikitState.cpp
  Battlescape/MedikitView.cpp
  Battlescape/MeleeAttackBState.cpp
  Battlescape/MiniMapState.cpp
  Battlescape/MiniMapView.cpp
  Battlescape/NextTurnState.cpp
  Battlescape/Particle.cpp
  Battlescape/Pathfinding.cpp
  Battlescape/PathfindingNode.cpp
  Battlescape/PathfindingOpenSet.cpp
  Battlescape/PrimeGrenadeState.cpp
  Battlescape/Projectile.cpp
  Battlescape/ProjectileFlyBState.cpp
  Battlescape/PromotionsState.cpp
  Battlescape/PsiAttackBState.cpp
  Battlescape/ScannerState.cpp
  Battlescape/ScannerView.cpp
  Battlescape/TileEngine.cpp
  Battlescape/UnitDieBState.cpp
  Battlescape/UnitFallBState.cpp
  Battlescape/UnitInfoState.cpp
  Battlescape/UnitPanicBState.cpp
  Battlescape/UnitSprite.cpp
  Battlescape/UnitTurnBState.cpp
  Battlescape/UnitWalkBState.cpp
  Battlescape/WarningMessage.cpp
)

set ( engine_src
  Engine/Action.cpp
  Engine/Adlib/adlplayer.cpp
  Engine/Adlib/fmopl.cpp
  Engine/AdlibMusic.cpp
  Engine/CatFile.cpp
  Engine/CrossPlatform.cpp
  Engine/FastLineClip.cpp
  Engine/FileMap.cpp
  Engine/FlcPlayer.cpp
  Engine/Font.cpp
  Engine/GMCat.cpp
  Engine/Game.cpp
  Engine/InteractiveSurface.cpp
  Engine/Language.cpp
  Engine/LanguagePlurality.cpp
  Engine/LocalizedText.cpp
  Engine/ModInfo.cpp
  Engine/Music.cpp
  Engine/OpenGL.cpp
  Engine/OptionInfo.cpp
  Engine/Options.cpp
  Engine/Palette.cpp
  Engine/RNG.cpp
  Engine/Scalers/hq2x.cpp
  Engine/Scalers/hq3x.cpp
  Engine/Scalers/hq4x.cpp
  Engine/Scalers/init.cpp
  Engine/Scalers/scale2x.cpp
  Engine/Scalers/scale3x.cpp
  Engine/Scalers/scalebit.cpp
  Engine/Scalers/xbrz.cpp
  Engine/Screen.cpp
  Engine/Sound.cpp
  Engine/SoundSet.cpp
  Engine/State.cpp
  Engine/Surface.cpp
  Engine/SurfaceSet.cpp
  Engine/Timer.cpp
  Engine/Unicode.cpp
  Engine/Zoom.cpp
)

set ( geoscape_src
  Geoscape/AlienBaseState.cpp
  Geoscape/AllocatePsiTrainingState.cpp
  Geoscape/BaseDefenseState.cpp
  Geoscape/BaseDestroyedState.cpp
  Geoscape/BaseNameState.cpp
  Geoscape/BuildNewBaseState.cpp
  Geoscape/ConfirmCydoniaState.cpp
  Geoscape/ConfirmDestinationState.cpp
  Geoscape/ConfirmLandingState.cpp
  Geoscape/ConfirmNewBaseState.cpp
  Geoscape/CraftErrorState.cpp
  Geoscape/CraftPatrolState.cpp
  Geoscape/DogfightErrorState.cpp
  Geoscape/DogfightState.cpp
  Geoscape/FundingState.cpp
  Geoscape/GeoscapeCraftState.cpp
  Geoscape/GeoscapeState.cpp
  Geoscape/Globe.cpp
  Geoscape/GraphsState.cpp
  Geoscape/InterceptState.cpp
  Geoscape/ItemsArrivingState.cpp
  Geoscape/LowFuelState.cpp
  Geoscape/MissionDetectedState.cpp
  Geoscape/MonthlyReportState.cpp
  Geoscape/MultipleTargetsState.cpp
  Geoscape/NewPossibleManufactureState.cpp
  Geoscape/NewPossibleResearchState.cpp
  Geoscape/ProductionCompleteState.cpp
  Geoscape/PsiTrainingState.cpp
  Geoscape/ResearchCompleteState.cpp
  Geoscape/ResearchRequiredState.cpp
  Geoscape/SelectDestinationState.cpp
  Geoscape/TargetInfoState.cpp
  Geoscape/UfoDetectedState.cpp
  Geoscape/UfoLostState.cpp
)

set ( interface_src
  Interface/ArrowButton.cpp
  Interface/Bar.cpp
  Interface/BattlescapeButton.cpp
  Interface/ComboBox.cpp
  Interface/Cursor.cpp
  Interface/FpsCounter.cpp
  Interface/Frame.cpp
  Interface/ImageButton.cpp
  Interface/NumberText.cpp
  Interface/ScrollBar.cpp
  Interface/Slider.cpp
  Interface/Text.cpp
  Interface/TextButton.cpp
  Interface/TextEdit.cpp
  Interface/TextList.cpp
  Interface/ToggleTextButton.cpp
  Interface/Window.cpp
)

set ( menu_src
  Menu/AbandonGameState.cpp
  Menu/ConfirmLoadState.cpp
  Menu/CutsceneState.cpp
  Menu/DeleteGameState.cpp
  Menu/ErrorMessageState.cpp
  Menu/ListGamesState.cpp
  Menu/ListLoadOriginalState.cpp
  Menu/ListLoadState.cpp
  Menu/ListSaveState.cpp
  Menu/LoadGameState.cpp
  Menu/MainMenuState.cpp
  Menu/NewBattleState.cpp
  Menu/NewGameState.cpp
  Menu/OptionsAdvancedState.cpp
  Menu/OptionsAudioState.cpp
  Menu/OptionsBaseState.cpp
  Menu/OptionsBattlescapeState.cpp
  Menu/OptionsConfirmState.cpp
  Menu/OptionsControlsState.cpp
  Menu/OptionsDefaultsState.cpp
  Menu/OptionsGeoscapeState.cpp
  Menu/ModConfirmExtendedState.cpp
  Menu/ModListState.cpp
  Menu/OptionsNoAudioState.cpp
  Menu/OptionsVideoState.cpp
  Menu/PauseState.cpp
  Menu/SaveGameState.cpp
  Menu/SetWindowedRootState.cpp
  Menu/SlideshowState.cpp
  Menu/StartState.cpp
  Menu/StatisticsState.cpp
  Menu/TestState.cpp
  Menu/VideoState.cpp
)

set ( mod_src
  Mod/AlienDeployment.cpp
  Mod/AlienRace.cpp
  Mod/Armor.cpp
  Mod/ArticleDefinition.cpp
  Mod/City.cpp
  Mod/ExtraSounds.cpp
  Mod/ExtraSprites.cpp
  Mod/ExtraStrings.cpp
  Mod/MCDPatch.cpp
  Mod/MapBlock.cpp
  Mod/MapData.cpp
  Mod/MapDataSet.cpp
  Mod/MapScript.cpp
  Mod/Mod.cpp
  Mod/Polygon.cpp
  Mod/Polyline.cpp
  Mod/RuleAlienMission.cpp
  Mod/RuleBaseFacility.cpp
  Mod/RuleCommendations.cpp
  Mod/RuleConverter.cpp
  Mod/RuleCountry.cpp
  Mod/RuleCraft.cpp
  Mod/RuleCraftWeapon.cpp
  Mod/RuleGlobe.cpp
  Mod/RuleInterface.cpp
  Mod/RuleInventory.cpp
  Mod/RuleItem.cpp
  Mod/RuleManufacture.cpp
  Mod/RuleMissionScript.cpp
  Mod/RuleMusic.cpp
  Mod/RuleRegion.cpp
  Mod/RuleResearch.cpp
  Mod/RuleSoldier.cpp
  Mod/RuleTerrain.cpp
  Mod/RuleUfo.cpp
  Mod/RuleVideo.cpp
  Mod/SoldierNamePool.cpp
  Mod/SoundDefinition.cpp
  Mod/StatString.cpp
  Mod/StatStringCondition.cpp
  Mod/Texture.cpp
  Mod/UfoTrajectory.cpp
  Mod/Unit.cpp
)

set ( savegame_src
  Savegame/AlienBase.cpp
  Savegame/AlienMission.cpp
  Savegame/AlienStrategy.cpp
  Savegame/Base.cpp
  Savegame/BaseFacility.cpp
  Savegame/BattleItem.cpp
  Savegame/BattleUnit.cpp
  Savegame/Country.cpp
  Savegame/Craft.cpp
  Savegame/CraftWeapon.cpp
  Savegame/CraftWeaponProjectile.cpp
  Savegame/EquipmentLayoutItem.cpp
  Savegame/GameTime.cpp
  Savegame/ItemContainer.cpp
  Savegame/MissionSite.cpp
  Savegame/MovingTarget.cpp
  Savegame/Node.cpp
  Savegame/Production.cpp
  Savegame/Region.cpp
  Savegame/ResearchProject.cpp
  Savegame/SaveConverter.cpp
  Savegame/SavedBattleGame.cpp
  Savegame/SavedGame.cpp
  Savegame/SerializationHelper.cpp
  Savegame/Soldier.cpp
  Savegame/SoldierDeath.cpp
  Savegame/SoldierDiary.cpp
  Savegame/Target.cpp
  Savegame/Tile.cpp
  Savegame/Transfer.cpp
  Savegame/Ufo.cpp
  Savegame/Vehicle.cpp
  Savegame/Waypoint.cpp
  Savegame/WeightedOptions.cpp
)

set ( ufopedia_src
  Ufopaedia/ArticleState.cpp
  Ufopaedia/ArticleStateArmor.cpp
  Ufopaedia/ArticleStateBaseFacility.cpp
  Ufopaedia/ArticleStateCraft.cpp
  Ufopaedia/ArticleStateCraftWeapon.cpp
  Ufopaedia/ArticleStateItem.cpp
  Ufopaedia/ArticleStateTFTD.cpp
  Ufopaedia/ArticleStateTFTDArmor.cpp
  Ufopaedia/ArticleStateTFTDCraft.cpp
  Ufopaedia/ArticleStateTFTDCraftWeapon.cpp
  Ufopaedia/ArticleStateTFTDFacility.cpp
  Ufopaedia/ArticleStateTFTDItem.cpp
  Ufopaedia/ArticleStateTFTDUso.cpp
  Ufopaedia/ArticleStateTFTDVehicle.cpp
  Ufopaedia/ArticleStateText.cpp
  Ufopaedia/ArticleStateTextImage.cpp
  Ufopaedia/ArticleStateUfo.cpp
  Ufopaedia/ArticleStateVehicle.cpp
  Ufopaedia/Ufopaedia.cpp
  Ufopaedia/UfopaediaSelectState.cpp
  Ufopaedia/UfopaediaStartState.cpp
)

set( NX_src
  NSwitch/SwitchTools.cpp
  NSwitch/SwitchController.cpp
)

set(DEVKITPRO $ENV{DEVKITPRO})
set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR aarch64)

set(CMAKE_C_COMPILER "${DEVKITPRO}/devkitA64/bin/aarch64-none-elf-gcc")
set(CMAKE_CXX_COMPILER "${DEVKITPRO}/devkitA64/bin/aarch64-none-elf-g++")
set(CMAKE_LINKER "${DEVKITPRO}/libnx/switch.ld")

set(CMAKE_CXX_FLAGS 
  "${CMAKE_CXX_FLAGS} \
  -march=armv8-a+crc+crypto \
  -mtune=cortex-a57 \
  -mtp=soft \
  -fPIE \
  -D__SWITCH__ \
  -D__NO_OPENGL \
  -O2 \
  -ffunction-sections \
  -flto"
)

#set(CMAKE_EXE_LINKER_FLAGS "-specs=${DEVKITPRO}/libnx/switch.specs ${CMAKE_EXE_LINKER_FLAGS}")

set (openxcom_src ${engine_src} ${root_src} ${basescape_src} ${battlescape_src} ${geoscape_src} ${interface_src} ${menu_src} ${mod_src} ${savegame_src} ${ufopedia_src} ${NX_src})

add_executable (openxcom ${openxcom_src})

target_include_directories(openxcom 
  PRIVATE 
  ${DEVKITPRO}/libnx/include
  ${DEVKITPRO}/portlibs/switch/include
  ${DEVKITPRO}/portlibs/switch/include/SDL2
  ${DEVKITPRO}/devkitA64/aarch64-none-elf/include
)

target_link_directories(openxcom
  PRIVATE
  ${DEVKITPRO}/libnx/lib
  ${DEVKITPRO}/portlibs/switch/lib
)

target_link_libraries(openxcom
  "-Wl,--start-group"
  nx
  SDL2
  SDL2_image
  SDL2_mixer
  yaml-cpp
  #
  drm_nouveau
  EGL
  glapi
  jpeg
  modplug
  mpg123
  ogg
  opus
  opusfile
  png
  webp
  vorbisidec
  z
  "-Wl,--end-group"
)

# Set output directory for Switch
set_target_properties(openxcom PROPERTIES
  RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/switch"
)

# create .nro target

set(NRO_OUT "${CMAKE_BINARY_DIR}/switch/openxcom.nro")
set(NRO_ICON "${CMAKE_SOURCE_DIR}/res/openxcom_256.jpg")
set(NACP_OUT "${CMAKE_BINARY_DIR}/switch/openxcom.nacp")
set(NACP_NAME "OpenXcom")
set(NACP_AUTHOR "alexart878")
set(NACP_VERSION "1.0")

if(NOT COMMAND nx_generate_nacp)
  message(FATAL_ERROR "The `nx_generate_nacp` cmake command is not available. Please use an appropriate Nintendo Switch toolchain.")
endif()

if(NOT COMMAND nx_create_nro)
  message(FATAL_ERROR "The `nx_create_nro` cmake command is not available. Please use an appropriate Nintendo Switch toolchain.")
endif()

nx_generate_nacp(
  ${NACP_OUT}
  NAME ${NACP_NAME}
  AUTHOR ${NACP_AUTHOR}
  VERSION ${NACP_VERSION}
)

nx_create_nro(
  openxcom
  OUTPUT ${NRO_OUT}
  ICON ${NRO_ICON}
  NACP ${NACP_OUT}
)

# install .nro to desired dir
install(FILES ${NRO_OUT} DESTINATION "${CMAKE_INSTALL_FULL_DATAROOTDIR}")
