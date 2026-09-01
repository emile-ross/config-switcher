#include "header.h"

#define p_check(name, config_name) \
	else if (scmp(program_name, name)) \
	{ \
		*(success) = True; \
		return config_name; \
	}

char *get_config_name(const char *restrict program_name, Bool *success)
{
	*(success) = True;

	if (cmp(program_name, "nvim", "neovim"))
		return "init.lua";
	else if (cmp(program_name, "hypr", "hyprland"))
		return "hyprland.conf";
	p_check("waybar", "config.jsonc");
	p_check("rofi", "config.rasi");
	p_check("wofi", "config");
	p_check("cava", "config");
	p_check("sway", "config");
	else
	{
		*(success) = False;
		/* defaults to 'config' for the configuration name */
		return "config";
	}
}

