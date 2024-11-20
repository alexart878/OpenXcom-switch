#pragma once

#include "../Interface/TextEdit.h"

namespace OpenXcom
{

namespace Switch
{

/// @brief caller for NS keyboard with dirty workaround
/// @param txtEdit pointer to OpenXcom::TextEdit 
void callSwitchKeyboardDirty(TextEdit *txtEdit);

/// @brief get NX screen width based on (un)dock mode
/// @return width in pixels
int getSwitchScreenWidth();

/// @brief get NX screen height based on (un)dock mode
/// @return height in pixels
int getSwitchScreenHeight();

}

}
