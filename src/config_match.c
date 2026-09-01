#include "header.h"

#define p_check(name, config_name) \
	else if (scmp(program_name, name)) \
		*(success) = True; \
		return config_name;

char *get_config_name(const char *restrict program_name, Bool *success)
{
	*(success) = True;

	if (cmp(program_name, "nvim", "neovim"))
		return "init.lua";
	else if (cmp(program_name, "hypr", "hyprland"))
		return "hyprland.conf";
	else if (scmp(program_name, "waybar"))
		return "config.jsonc";
	else if (scmp(program_name, "rofi"))
		return "config.rasi";
	else if (scmp(program_name, "wofi"))
		return "config";
	else if (scmp(program_name, "cava"))
		return "config";
	else if (scmp(program_name, "sway"))
		return "config";
	else
	{
		*(success) = False;
		/* defaults to 'config' for the configuration name */
		return "config";
	}
}

