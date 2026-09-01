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
	else if (ch("mpv"))
		return "mpv.conf";
	else if (ch("lazygit"))
		return "config.yml";
	else if (ch("fuzzel"))
		return "fuzzel.ini";
	else if (ch("neofetch"))
		return "config.conf";
	else if (ch("htop"))
		return "htoprc";
	else if (ch("fastfetch"))
		return "config.jsonc";
	else if (ch("kitty"))
		return "kitty.conf";
	else if (ch("btop"))
		return "btop.conf";
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

