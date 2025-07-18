#pragma once
#include <rendell_ui/rendell_ui.h>

namespace rendell_stuff
{
rendell_ui::WindowSharedPtr createWindow(uint32_t width, uint32_t height, const char *title);
bool init(rendell_ui::WindowSharedPtr window);
}
