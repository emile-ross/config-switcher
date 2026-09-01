struct config_contents
{
	char *program_name;
	char *config_name;
	char *style_name;
};

static const struct config_contents program_configs[] = 
{
	{ "bpytop", "bpytop.conf", NULL },
	{ "btop", "btop.conf", NULL },
	{ "cava", "config", NULL },
	{ "fastfetch", "config.jsonc", NULL },
	{ "fuzzel", "fuzzel.ini", NULL },
	{ "htop", "htoprc", NULL },
	{ "hypr", "hyprland.conf", NULL },
	{ "keepassxc", "keepassxc.ini", NULL },
	{ "kitty", "kitty.conf", NULL },
	{ "lazygit", "config.yml", NULL },
	{ "mpv", "mpv.conf", NULL },
	{ "neofetch", "config.conf", NULL },
	{ "nvim", "init.lua", NULL },
	{ "rofi", "config.rasi", NULL },
	{ "sway", "config", NULL },
	{ "vesktop", "settings.json", NULL },
	{ "vlc", "vlcrc", "vlc-qt-interface.conf" },
	{ "waybar", "config.json", "style.css" },
	{ "waybar", "config.jsonc", NULL },
	{ "wofi", "config", NULL },
};

