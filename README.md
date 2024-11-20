# OpenXcom for Nintendo Switch

This port based on fork of sdl2 branch, from the original OpenXcom repo:
([link](https://github.com/OpenXcom/OpenXcom/tree/sdl2) to the original, other info: [website](https://openxcom.org), original [readme](https://github.com/OpenXcom/OpenXcom/blob/master/README.md)).
Without the efforts put in by [SupSuper](https://github.com/SupSuper) and OpenXcom dev team, none of this would've been possible.

## Key differences

- Controller support, thanks to [Northfear](https://github.com/Northfear) and his PS Vita [port](https://github.com/Northfear/OpenXcom-vita) for point of start
- Touchscreen, switch keyboard support
- Modified software rendering functions from sdl1, which don't supported in devkitPRO
- Modified build files and scripts, to bring fluid devkit toolchain integration
- Docked and handheld recognition, screen resolution changes on game's start

## Controls

I used most comfortable layout (IMHO, can be remapped through game's controls menu):

- Left stick: mouse move
- Right stick: map scrolling
- A: mouse left button
- B: mouse right button
- X: inventory
- Y: map
- L1/R1: switch soldiers
- L2/R2: quick save/load
- L3: ctrl mode
- R3: center on selected soldier
- Minus: game menu (pause)
- Plus: end turn
- Dpad up/down: floor view up/down
- Dpad left/right: use weapon in left/right hand

## Installation

- Go to releases page, and grab latest .nro executable
- Obtain legal copy of XCOM: UFO Defense and/or XCOM: TFTD, for steam, files in:
```
  UFO: "Steam\SteamApps\common\XCom UFO Defense\XCOM"
  TFTD: "Steam\SteamApps\common\X-COM Terror from the Deep\TFD"
```
- Use "bin" folder from this repo, rename it to "openxcom" and place somewhere on SD
- Place openxcom.nro file to the root of this folder
- Look up UFO/README.txt and TFTD/README.txt in this folder, and place data accordingly
- Launch game in NON-applet mode to avoid memory insufficiency
- OPTIONAL: if you want to create forwarder DO NOT USE video capture - it causes CPU Boost bug after closing app

## Directory Locations

OpenXcom has three directory locations that it searches for user and game files:

<table>
  <tr>
    <th>Folder type</th>
    <th>Folder contents</th>
    <th>Folder default location</th>
  </tr>
  <tr>
    <td>user</td>
    <td>mods, savegames, screenshots</td>
    <td>/switch/openxcom/userdir</td>
  </tr>
  <tr>
    <td>config</td>
    <td>game configuration</td>
    <td>/config/openxcom</td>
  </tr>
  <tr>
    <td>data</td>
    <td>UFO and TFTD data files, standard mods, common resources</td>
    <td>/switch/openxcom</td>
  </tr>
</table>

## Build

Those, who want improve something, or just compile by their own, should follow next steps:

- Setup switch homebrew enviroment, more info: [link](https://devkitpro.org/wiki/Getting_Started)
- Download switch-sdl2, switch-sdl2_gfx, switch-sdl2_image, switch-sdl2_mixer, switch-sdl2_ttf
- Tricky part: compile [yaml-cpp](https://github.com/jbeder/yaml-cpp) with devkitPRO, place includes/lib to $DEVKITPRO paths
- For cmake:
```
cd OpenXcom-switch
mkdir build && cd build
cmake .. -DSWITCH=ON -DCMAKE_TOOLCHAIN_FILE=$DEVKITPRO/cmake/Switch.cmake -DCMAKE_BUILD_TYPE=Release/Debug/None
make
```
- Also, you can use scripts/build-switch for automated compile process
