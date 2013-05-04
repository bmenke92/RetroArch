/*  RetroArch - A frontend for libretro.
 *  Copyright (C) 2010-2013 - Hans-Kristian Arntzen
 *  Copyright (C) 2011-2013 - Daniel De Matteis
 * 
 *  RetroArch is free software: you can redistribute it and/or modify it under the terms
 *  of the GNU General Public License as published by the Free Software Found-
 *  ation, either version 3 of the License, or (at your option) any later version.
 *
 *  RetroArch is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY;
 *  without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
 *  PURPOSE.  See the GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License along with RetroArch.
 *  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _RMENU_H_
#define _RMENU_H_

#include "menu_common.h"

#ifdef _XBOX1
#define HAVE_MENU_PANEL
#endif

#if defined(HAVE_OPENGL)
#define DEVICE_CAST gl_t*
#elif defined(_XBOX1)
#define DEVICE_CAST xdk_d3d_video_t*
#endif

enum
{
   CONFIG_FILE = 0,
#ifdef HAVE_SHADER_MANAGER
   SHADER_PRESET_FILE,
#endif
   INPUT_PRESET_FILE
};

enum
{
   FILE_BROWSER_MENU = 0,
   GENERAL_VIDEO_MENU,
   GENERAL_AUDIO_MENU,
   EMU_GENERAL_MENU,
   EMU_VIDEO_MENU,
   EMU_AUDIO_MENU,
   PATH_MENU,
   CONTROLS_MENU,
#ifdef HAVE_SHADER_MANAGER
   SHADER_CHOICE,
   CGP_CHOICE,
#endif
   BORDER_CHOICE,
   LIBRETRO_CHOICE,
   PATH_SAVESTATES_DIR_CHOICE,
   PATH_DEFAULT_ROM_DIR_CHOICE,
#ifdef HAVE_XML
   PATH_CHEATS_DIR_CHOICE,
#endif
   PATH_SRAM_DIR_CHOICE,
   PATH_SYSTEM_DIR_CHOICE,
   INPUT_PRESET_CHOICE,
   INGAME_MENU,
   INGAME_MENU_RESIZE,
   INGAME_MENU_CORE_OPTIONS,
   INGAME_MENU_LOAD_GAME_HISTORY,
   INGAME_MENU_VIDEO_OPTIONS,
   INGAME_MENU_SCREENSHOT,
};


#ifndef HAVE_RMENU_XUI
enum
{
   SETTING_FONT_SIZE,
   SETTING_REFRESH_RATE,
   SETTING_THROTTLE_MODE,
   SETTING_TRIPLE_BUFFERING,
   SETTING_DEFAULT_VIDEO_ALL,
   SETTING_SOUND_MODE,
#ifdef HAVE_RSOUND
   SETTING_RSOUND_SERVER_IP_ADDRESS,
#endif
   SETTING_ENABLE_CUSTOM_BGM,
   SETTING_DEFAULT_AUDIO_ALL,
   SETTING_EMU_SHOW_DEBUG_INFO_MSG,
   SETTING_EMU_SHOW_INFO_MSG,
   SETTING_EMU_SKIN,
   SETTING_EMU_DEFAULT_ALL,
   SETTING_EMU_REWIND_ENABLED,
   SETTING_EMU_REWIND_GRANULARITY,
   SETTING_EMU_VIDEO_DEFAULT_ALL,
#ifdef _XBOX1
   SETTING_EMU_AUDIO_SOUND_VOLUME_LEVEL,
#endif
   SETTING_EMU_AUDIO_MUTE,
   SETTING_EMU_AUDIO_DEFAULT_ALL,
   SETTING_PATH_DEFAULT_ROM_DIRECTORY,
   SETTING_PATH_SAVESTATES_DIRECTORY,
   SETTING_PATH_SRAM_DIRECTORY,
#ifdef HAVE_XML
   SETTING_PATH_CHEATS,
#endif
   SETTING_PATH_SYSTEM,
   SETTING_ENABLE_SRAM_PATH,
   SETTING_ENABLE_STATE_PATH,
   SETTING_PATH_DEFAULT_ALL,
   SETTING_CONTROLS_SCHEME,
   SETTING_CONTROLS_NUMBER,
   SETTING_DPAD_EMULATION,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_B,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_Y,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_SELECT,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_START,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_UP,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_DOWN,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_LEFT,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_RIGHT,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_A,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_X,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_L,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_R,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_L2,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_R2,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_L3,
   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_R3,
   SETTING_CONTROLS_SAVE_CUSTOM_CONTROLS,
   SETTING_CONTROLS_DEFAULT_ALL,
   SETTING_LAST,
   INGAME_MENU_CHANGE_LIBRETRO_CORE,
   INGAME_MENU_LOAD_GAME_HISTORY_MODE,
   INGAME_MENU_CHANGE_GAME,
   INGAME_MENU_CORE_OPTIONS_MODE,
   INGAME_MENU_VIDEO_OPTIONS_MODE,
   INGAME_MENU_SETTINGS,
   INGAME_MENU_LOAD_STATE,
   INGAME_MENU_SAVE_STATE,
   INGAME_MENU_SCREENSHOT_MODE,
   INGAME_MENU_RETURN_TO_GAME,
   INGAME_MENU_RESET,
   INGAME_MENU_RESIZE_MODE,
   INGAME_MENU_FRAME_ADVANCE,
#ifdef HAVE_MULTIMAN
   INGAME_MENU_RETURN_TO_MULTIMAN,
#endif
   INGAME_MENU_QUIT_RETROARCH,
#ifdef __CELLOS_LV2__
   SETTING_CHANGE_RESOLUTION,
   SETTING_PAL60_MODE,
#endif
   SETTING_HW_TEXTURE_FILTER,
#ifdef _XBOX1
   SETTING_FLICKER_FILTER,
   SETTING_SOFT_DISPLAY_FILTER,
#endif
   SETTING_ASPECT_RATIO,
   SETTING_ROTATION,
#ifdef HAVE_SHADER_MANAGER
   SHADERMAN_AUTOSTART_CGP_ON_STARTUP,
   SHADERMAN_LOAD_CGP,
   SHADERMAN_SAVE_CGP,
   SHADERMAN_APPLY_CHANGES,
   SHADERMAN_SHADER_PASSES,
   SHADERMAN_SHADER_0,
   SHADERMAN_SHADER_0_FILTER,
   SHADERMAN_SHADER_0_SCALE,
   SHADERMAN_SHADER_1,
   SHADERMAN_SHADER_1_FILTER,
   SHADERMAN_SHADER_1_SCALE,
   SHADERMAN_SHADER_2,
   SHADERMAN_SHADER_2_FILTER,
   SHADERMAN_SHADER_2_SCALE,
   SHADERMAN_SHADER_3,
   SHADERMAN_SHADER_3_FILTER,
   SHADERMAN_SHADER_3_SCALE,
   SHADERMAN_SHADER_4,
   SHADERMAN_SHADER_4_FILTER,
   SHADERMAN_SHADER_4_SCALE,
   SHADERMAN_SHADER_5,
   SHADERMAN_SHADER_5_FILTER,
   SHADERMAN_SHADER_5_SCALE,
   SHADERMAN_SHADER_6,
   SHADERMAN_SHADER_6_FILTER,
   SHADERMAN_SHADER_6_SCALE,
   SHADERMAN_SHADER_7,
   SHADERMAN_SHADER_7_FILTER,
   SHADERMAN_SHADER_7_SCALE,
#endif
#ifdef HAVE_SHADER_MANAGER
   SHADERMAN_SHADER_LAST = SHADERMAN_SHADER_0_SCALE + (3 * (RGUI_MAX_SHADERS - 1)),
#else
   SHADERMAN_SHADER_LAST = SETTING_ROTATION,
#endif
   SHADERMAN_LAST,
   SETTING_LAST_LAST,
};
#endif

#define FIRST_VIDEO_SETTING				0
#define FIRST_AUDIO_SETTING				SETTING_DEFAULT_VIDEO_ALL+1
#define FIRST_EMU_SETTING				   SETTING_DEFAULT_AUDIO_ALL+1
#define FIRST_EMU_VIDEO_SETTING			SETTING_EMU_DEFAULT_ALL+1
#define FIRST_EMU_AUDIO_SETTING			SETTING_EMU_VIDEO_DEFAULT_ALL+1
#define FIRST_PATH_SETTING				   SETTING_EMU_AUDIO_DEFAULT_ALL+1
#define FIRST_CONTROLS_SETTING_PAGE_1	SETTING_PATH_DEFAULT_ALL+1
#define FIRST_CONTROL_BIND				   SETTING_CONTROLS_RETRO_DEVICE_ID_JOYPAD_B
#define FIRST_INGAME_MENU_SETTING      SETTING_LAST+1
#define FIRST_SHADERMAN_SETTING        INGAME_MENU_QUIT_RETROARCH+1

#define MAX_NO_OF_VIDEO_SETTINGS			SETTING_DEFAULT_VIDEO_ALL+1
#define MAX_NO_OF_AUDIO_SETTINGS			SETTING_DEFAULT_AUDIO_ALL+1
#define MAX_NO_OF_EMU_SETTINGS			SETTING_EMU_DEFAULT_ALL+1
#define MAX_NO_OF_EMU_VIDEO_SETTINGS	SETTING_EMU_VIDEO_DEFAULT_ALL+1
#define MAX_NO_OF_EMU_AUDIO_SETTINGS	SETTING_EMU_AUDIO_DEFAULT_ALL+1
#define MAX_NO_OF_PATH_SETTINGS			SETTING_PATH_DEFAULT_ALL+1
#define MAX_NO_OF_CONTROLS_SETTINGS		SETTING_CONTROLS_DEFAULT_ALL+1
#define MAX_NO_OF_INGAME_MENU_SETTINGS INGAME_MENU_QUIT_RETROARCH+1
#ifdef HAVE_SHADER_MANAGER
#define MAX_NO_OF_SHADERMAN_SETTINGS   SHADERMAN_SHADER_PASSES+1
#endif

void menu_init (void);
bool menu_iterate(void);
void menu_free (void);

#endif /* MENU_H_ */
