#include "header.h"

char *get_config_name(char *program_name, char *second_config)
{
	if (cmp(program_name, "nvim", "neovim"))
		return "init.lua";

	if (cmp(program_name, "hypr", "hyprland"))
		return "hyprland.conf";

	if (scmp(program_name, "waybar"))
	{
		second_config = bmalloc("style.css");
		return "config.jsonc";
	}

	if (scmp(program_name, "cava"))
		return "config";

	if (scmp(program_name, "sway"))
		return "config";

