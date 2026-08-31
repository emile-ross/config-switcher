#include "header.h"

char *get_config_name(const char *restrict program_name, Bool success)
{
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
		return NULL;
}

