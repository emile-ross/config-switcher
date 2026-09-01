#include "header.h"

#define ch(name) \
	scmp(program_name, name)

char *get_config_name(const char *restrict program_name, Bool *success)
{
	*(success) = True;

	if (cmp(program_name, "nvim", "neovim"))
		return "init.lua";
	else if (cmp(program_name, "hypr", "hyprland"))
		return "hyprland.conf";
	else if (ch("waybar"))
		return "config.jsonc";
	else if (ch("rofi"))
		return "config.rasi";
	else if (ch("wofi"))
		return "config";
	else if (ch("cava"))
		return "config";
	else if (ch("sway"))
		return "config";
	else
	{
		*(success) = False;
		/* defaults to 'config' for the configuration name */
		return "config";
	}
}

