/* See LICENSE file for copyright and license details. */

/* Helper macros for spawning commands */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }
#define CMD(...)   { .v = (const char*[]){ __VA_ARGS__, NULL } }

/* appearance */
static const unsigned int borderpx       = 2;   /* border pixel of windows */
static const unsigned int snap           = 20;  /* snap pixel */
static const unsigned int gappih         = 10;  /* horiz inner gap between windows */
static const unsigned int gappiv         = 10;  /* vert inner gap between windows */
static const unsigned int gappoh         = 20;  /* horiz outer gap between windows and screen edge */
static const unsigned int gappov         = 20;  /* vert outer gap between windows and screen edge */
static const int smartgaps_fact          = 1;   /* gap factor when there is only one client; 0 = no gaps, 3 = 3x outer gaps */
static const int showbar                 = 1;   /* 0 means no bar */
static const int topbar                  = 1;   /* 0 means bottom bar */
static const int bar_height              = 30;   /* 0 means derive from font, >= 1 explicit height */
#define ICONSIZE 20    /* icon size */
#define ICONSPACING 5  /* space between icon and title */
/* Status is to be shown on: -1 (all monitors), 0 (a specific monitor by index), 'A' (active monitor) */
static const int statusmon               = 'A';
static const unsigned int systrayspacing = 2;   /* systray spacing */
static const int showsystray             = 1;   /* 0 means no systray */

/* Indicators: see patch/bar_indicators.h for options */
static int tagindicatortype              = INDICATOR_TOP_LEFT_SQUARE;
static int tiledindicatortype            = INDICATOR_NONE;
static int floatindicatortype            = INDICATOR_TOP_LEFT_SQUARE;
static const char statussep              = ';'; /* separator between status bars */
static const char *fonts[]               = { "Cascadia Code:size=8:style=Bold" };

static char c000000[]                    = "#000000"; // placeholder value

static char normfgcolor[]                = "#bbbbbb";
static char normbgcolor[]                = "#222222";
static char normbordercolor[]            = "#444444";
static char normfloatcolor[]             = "#db8fd9";

static char selfgcolor[]                 = "#eeeeee";
static char selbgcolor[]                 = "#005577";
static char selbordercolor[]             = "#005577";
static char selfloatcolor[]              = "#005577";

static char titlenormfgcolor[]           = "#bbbbbb";
static char titlenormbgcolor[]           = "#222222";
static char titlenormbordercolor[]       = "#444444";
static char titlenormfloatcolor[]        = "#db8fd9";

static char titleselfgcolor[]            = "#eeeeee";
static char titleselbgcolor[]            = "#005577";
static char titleselbordercolor[]        = "#005577";
static char titleselfloatcolor[]         = "#005577";

static char tagsnormfgcolor[]            = "#bbbbbb";
static char tagsnormbgcolor[]            = "#222222";
static char tagsnormbordercolor[]        = "#444444";
static char tagsnormfloatcolor[]         = "#db8fd9";

static char tagsselfgcolor[]             = "#eeeeee";
static char tagsselbgcolor[]             = "#005577";
static char tagsselbordercolor[]         = "#005577";
static char tagsselfloatcolor[]          = "#005577";

static char hidnormfgcolor[]             = "#005577";
static char hidselfgcolor[]              = "#227799";
static char hidnormbgcolor[]             = "#222222";
static char hidselbgcolor[]              = "#222222";

static char urgfgcolor[]                 = "#bbbbbb";
static char urgbgcolor[]                 = "#222222";
static char urgbordercolor[]             = "#ff0000";
static char urgfloatcolor[]              = "#db8fd9";

static char scratchselfgcolor[]          = "#FFF7D4";
static char scratchselbgcolor[]          = "#77547E";
static char scratchselbordercolor[]      = "#894B9F";
static char scratchselfloatcolor[]       = "#894B9F";

static char scratchnormfgcolor[]         = "#FFF7D4";
static char scratchnormbgcolor[]         = "#664C67";
static char scratchnormbordercolor[]     = "#77547E";
static char scratchnormfloatcolor[]      = "#77547E";

static char redcolor[] = "#eeeeee";
static char greencolor[] = "#eeeeee";
static char bluecolor[] = "#eeeeee";
static char yellowcolor[] = "#eeeeee";
static char magentacolor[] = "#eeeeee";
static char cyancolor[] = "#eeeeee";

static char *colors[][ColCount] = {
    /*                   fg                     bg               border                float */
    [SchemeRed]          = { redcolor,         normbgcolor,      normbordercolor,      normfloatcolor },
    [SchemeGreen]        = { greencolor,       normbgcolor,      normbordercolor,      normfloatcolor },
    [SchemeBlue]         = { bluecolor,        normbgcolor,      normbordercolor,      normfloatcolor },
    [SchemeYellow]       = { yellowcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
    [SchemeMagenta]      = { magentacolor,     normbgcolor,      normbordercolor,      normfloatcolor },
    [SchemeCyan]         = { cyancolor,        normbgcolor,      normbordercolor,      normfloatcolor },
    [SchemeNorm]         = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
    [SchemeSel]          = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
    [SchemeTitleNorm]    = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
    [SchemeTitleSel]     = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
    [SchemeTagsNorm]     = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
    [SchemeTagsSel]      = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
    [SchemeHidNorm]      = { normfgcolor,      normbgcolor,      c000000,              c000000 },
    [SchemeHidSel]       = { selfgcolor,       selbgcolor,       c000000,              c000000 },
    [SchemeUrg]          = { selbgcolor,       normbgcolor,      selbordercolor,       selfloatcolor },
    [SchemeScratchNorm]  = { normfgcolor,      normbgcolor,      normbordercolor,      normfloatcolor },
    [SchemeScratchSel]   = { selfgcolor,       selbgcolor,       selbordercolor,       selfloatcolor },
};

static const char *const autostart[] = {
    "picom", NULL,
    "slstatus", NULL,
    "xclickroot", "-1", "xdg-xmenu", NULL,
    "nitrogen", "--restore", NULL,
    NULL /* terminate */
};

static const char *scratchpadcmd[] = {"s", "st", "-n", "spterm", NULL};

/* Tags
 * In a traditional dwm the number of tags in use can be changed simply by changing the number
 * of strings in the tags array. This build does things a bit different which has some added
 * benefits. If you need to change the number of tags here then change the NUMTAGS macro in dwm.c.
 *
 * Examples:
 *
 *  1) static char *tagicons[][NUMTAGS*2] = {
 *         [DEFAULT_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F", "G", "H", "I" },
 *     }
 *
 *  2) static char *tagicons[][1] = {
 *         [DEFAULT_TAGS] = { "•" },
 *     }
 *
 * The first example would result in the tags on the first monitor to be 1 through 9, while the
 * tags for the second monitor would be named A through I. A third monitor would start again at
 * 1 through 9 while the tags on a fourth monitor would also be named A through I. Note the tags
 * count of NUMTAGS*2 in the array initialiser which defines how many tag text / icon exists in
 * the array. This can be changed to *3 to add separate icons for a third monitor.
 *
 * For the second example each tag would be represented as a bullet point. Both cases work the
 * same from a technical standpoint - the icon index is derived from the tag index and the monitor
 * index. If the icon index is is greater than the number of tag icons then it will wrap around
 * until it an icon matches. Similarly if there are two tag icons then it would alternate between
 * them. This works seamlessly with alternative tags and alttagsdecoration patches.
 */
static char *tagicons[][11] =
{
    [DEFAULT_TAGS] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K" },
    [ALTERNATIVE_TAGS] = { "1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11" },
    [ALT_TAGS_DECORATION] = { "<1>", "<2>", "<3>", "<4>", "<5>", "<6>", "<7>", "<8>", "<9>", "<10>", "<11>" },
};

/* There are two options when it comes to per-client rules:
 *  - a typical struct table or
 *  - using the RULE macro
 *
 * A traditional struct table looks like this:
 *    // class      instance  title  wintype  tags mask  isfloating  monitor
 *    { "Gimp",     NULL,     NULL,  NULL,    1 << 4,    0,          -1 },
 *    { "Firefox",  NULL,     NULL,  NULL,    1 << 7,    0,          -1 },
 *
 * The RULE macro has the default values set for each field allowing you to only
 * specify the values that are relevant for your rule, e.g.
 *
 *    RULE(.class = "Gimp", .tags = 1 << 4)
 *    RULE(.class = "Firefox", .tags = 1 << 7)
 *
 * Refer to the Rule struct definition for the list of available fields depending on
 * the patches you enable.
 */
static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     *  WM_WINDOW_ROLE(STRING) = role
     *  _NET_WM_WINDOW_TYPE(ATOM) = wintype
     */
    RULE(.wintype = WTYPE "DIALOG", .isfloating = 1)
    RULE(.wintype = WTYPE "UTILITY", .isfloating = 1)
    RULE(.wintype = WTYPE "TOOLBAR", .isfloating = 1)
    RULE(.wintype = WTYPE "SPLASH", .isfloating = 1)
    RULE(.class = "Gimp", .tags = 1 << 4)
    RULE(.class = "Firefox", .tags = 1 << 7)
    RULE(.instance = "spterm", .scratchkey = 's', .isfloating = 1)
};

/* Bar rules allow you to configure what is shown where on the bar, as well as
 * introducing your own bar modules.
 *
 *    monitor:
 *      -1  show on all monitors
 *       0  show on monitor 0
 *      'A' show on active monitor (i.e. focused / selected) (or just -1 for active?)
 *    bar - bar index, 0 is default, 1 is extrabar
 *    alignment - how the module is aligned compared to other modules
 *    widthfunc, drawfunc, clickfunc - providing bar module width, draw and click functions
 *    name - does nothing, intended for visual clue and for logging / debugging
 */
static const BarRule barrules[] = {
    /* monitor   bar    alignment         widthfunc                 drawfunc                clickfunc                hoverfunc                name */
    { -1,        0,     BAR_ALIGN_LEFT,   width_tags,               draw_tags,              click_tags,              hover_tags,              "tags" },
    {  0,        0,     BAR_ALIGN_RIGHT,  width_systray,            draw_systray,           click_systray,           NULL,                    "systray" },
    { -1,        0,     BAR_ALIGN_LEFT,   width_ltsymbol,           draw_ltsymbol,          click_ltsymbol,          NULL,                    "layout" },
    { statusmon, 0,     BAR_ALIGN_RIGHT,  width_statuscolors,       draw_statuscolors,      click_statuscolors,      NULL,                    "statuscolors" },
    { -1,        0,     BAR_ALIGN_NONE,   width_awesomebar,         draw_awesomebar,        click_awesomebar,        NULL,                    "awesomebar" },
    { statusmon, 1,     BAR_ALIGN_CENTER, width_statuscolors_es,    draw_statuscolors_es,   click_statuscolors,      NULL,                    "statuscolors_es" },
};

/* layout(s) */
static const float mfact     = 0.52; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
    { "TTT",      bstack },
    { "|M|",      centeredmaster },
    { ">M>",      centeredfloatingmaster },
    { "[D]",      deck },
    { "(@)",      spiral },
    { "[\\]",     dwindle },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = {"pulsar-desktop", NULL};

static const char* termcmd[]  = { "st", NULL };
static const char* firefoxcmd[] = {"firefox", NULL};
static const char* filemancmd[] = {"pcmanfm-qt", NULL};

static const char* pulsar_music_cmd[] = {"pulsar-music", NULL};
static const char* pulsar_videos_cmd[] = {"pulsar-videos", NULL};
static const char* pulsar_sources_cmd[] = {"pulsar-sources", NULL};
static const char* pulsar_pictures_cmd[] = {"pulsar-pictures", NULL};
static const char* pulsar_projects_cmd[] = {"pulsar-projects", NULL};
static const char* pulsar_manpages_cmd[] = {"pulsar-manpages", NULL};
static const char* pulsar_websearch_cmd[] = {"pulsar-websearch", NULL};
static const char* pulsar_wallpapers_cmd[] = {"pulsar-wallpapers", NULL};

static const char* tfilemancmd[] = {"st", "-e", "lfrun", NULL};
static const char* tbrowsercmd[] = {"st", "-e", "elinks", NULL};

static const Key on_empty_keys[] = {
    /* modifier key                function            argument */
    { 0,            XK_Return,     spawn,              {.v = termcmd } },
    { 0,            XK_p,          spawn,              {.v = dmenucmd } },
    { 0,            XK_b,          spawn,              {.v = firefoxcmd } },
    { 0,            XK_f,          spawn,              {.v = filemancmd } },

    { 0,            XK_n,          spawn,             { .v = pulsar_music_cmd } },
    { 0,            XK_v,          spawn,             { .v = pulsar_videos_cmd } },
    { 0,            XK_s,          spawn,             { .v = pulsar_sources_cmd } },
    { 0,            XK_i,          spawn,             { .v = pulsar_pictures_cmd } },
    { 0,            XK_p,          spawn,             { .v = pulsar_projects_cmd } },
    { 0,            XK_m,          spawn,             { .v = pulsar_manpages_cmd } },
    { 0,            XK_q,          spawn,             { .v = pulsar_websearch_cmd } },
    { 0,            XK_w,          spawn,             { .v = pulsar_wallpapers_cmd } },

    { ShiftMask,    XK_b,          spawn,              {.v = tbrowsercmd } },
    { ShiftMask,    XK_f,          spawn,              {.v = tfilemancmd } },
};

/*
* Xresources preferences to load at startup.
*
*     Name                      Type       Address
*    ------------------------------------------------
*     "nmaster"                 INTEGER    &nmaster
*     "mfact"                   FLOAT      &mfact
*     "color12"                  STRING     &color12
*
* In the Xresources file setting resources shoud be prefixed with "dwm.", e.g.
*
*    dwm.nmaster: 1
*    dwm.mfact: 0.50
*    dwm.color12: #FA6EFA
*
* Note that the const qualifier must be removed from the variables if you plan on
* overriding them with values from Xresources. While resources can be reloaded
* using the xrdb function some changes may only take effect following a restart.
*/
ResourcePref resources[] = {
    /* Resource name            Type       Address                */
    { "color8",                 STRING,    &redcolor },
    { "color9",                 STRING,    &greencolor },
    { "color10",                STRING,    &bluecolor },
    { "color11",                STRING,    &yellowcolor },
    { "color12",                STRING,    &magentacolor },
    { "color13",                STRING,    &cyancolor },
    { "foreground",             STRING,    &normfgcolor },
    { "background",             STRING,    &normbgcolor },
    { "background",             STRING,    &normbordercolor },
    { "color0",                 STRING,    &normfloatcolor },
    { "color0",                 STRING,    &selfgcolor },
    { "color12",                STRING,    &selbgcolor },
    { "color12",                STRING,    &selbordercolor },
    { "color12",                STRING,    &selfloatcolor },
    { "foreground",             STRING,    &titlenormfgcolor },
    { "background",             STRING,    &titlenormbgcolor },
    { "titlenormbordercolor",   STRING,    &titlenormbordercolor },
    { "titlenormfloatcolor",    STRING,    &titlenormfloatcolor },
    { "titleselfgcolor",        STRING,    &titleselfgcolor },
    { "titleselbgcolor",        STRING,    &titleselbgcolor },
    { "titleselbordercolor",    STRING,    &titleselbordercolor },
    { "titleselfloatcolor",     STRING,    &titleselfloatcolor },
    { "color0",                 STRING,    &tagsnormfgcolor },
    { "background",             STRING,    &tagsnormbgcolor },
    { "tagsnormbordercolor",    STRING,    &tagsnormbordercolor },
    { "tagsnormfloatcolor",     STRING,    &tagsnormfloatcolor },
    { "color0",                 STRING,    &tagsselfgcolor },
    { "color12",                STRING,    &tagsselbgcolor },
    { "tagsselbordercolor",     STRING,    &tagsselbordercolor },
    { "tagsselfloatcolor",      STRING,    &tagsselfloatcolor },
    { "hidnormfgcolor",         STRING,    &hidnormfgcolor },
    { "hidnormbgcolor",         STRING,    &hidnormbgcolor },
    { "hidselfgcolor",          STRING,    &hidselfgcolor },
    { "hidselbgcolor",          STRING,    &hidselbgcolor },
    { "foreground",             STRING,    &urgfgcolor },
    { "background",             STRING,    &urgbgcolor },
    { "urgbordercolor",         STRING,    &urgbordercolor },
    { "urgbordercolor",         STRING,    &urgbordercolor },
    { "color12",                STRING,    &urgfloatcolor },
    { "foreground",             STRING,    &scratchselfgcolor },
    { "background",             STRING,    &scratchselbgcolor },
    { "background",             STRING,    &scratchselbordercolor },
    { "scratchselfloatcolor",   STRING,    &scratchselfloatcolor },
    { "scratchnormfgcolor",     STRING,    &scratchnormfgcolor },
    { "scratchnormbgcolor",     STRING,    &scratchnormbgcolor },
    { "scratchnormbordercolor", STRING,    &scratchnormbordercolor },
    { "scratchnormfloatcolor",  STRING,    &scratchnormfloatcolor },
};

static const Key keys[] = {
    /* modifier                     key            function                argument */
    { MODKEY,                       XK_Escape,     setkeymode,             {.ui = COMMANDMODE} },
    { MODKEY,                       XK_p,          spawn,                  {.v = dmenucmd } },
    { MODKEY|ShiftMask,             XK_Return,     spawn,                  {.v = termcmd } },
    { MODKEY,                       XK_b,          togglebar,              {0} },
    { MODKEY|ShiftMask,             XK_b,          toggletopbar,           {0} },
    { MODKEY|ControlMask,           XK_space,      focusmaster,            {0} },
    { MODKEY,                       XK_k,          focusstack,             {.i = +1 } },
    { MODKEY,                       XK_j,          focusstack,             {.i = -1 } },
    { MODKEY,                       XK_s,          swapfocus,              {.i = -1 } },
    { MODKEY|ShiftMask,             XK_k,          rotatestack,            {.i = +1 } },
    { MODKEY|ShiftMask,             XK_j,          rotatestack,            {.i = -1 } },
    { MODKEY,                       XK_i,          incnmaster,             {.i = +1 } },
    { MODKEY,                       XK_d,          incnmaster,             {.i = -1 } },
    { MODKEY,                       XK_h,          setmfact,               {.f = -0.05} },
    { MODKEY,                       XK_l,          setmfact,               {.f = +0.05} },
    { MODKEY,                       XK_e,          aspectresize,           {.i = +24} },
    { MODKEY,                       XK_r,          aspectresize,           {.i = -24} },
    { Mod4Mask,                     XK_Down,       moveresize,             {.v = "0x 25y 0w 0h" } },
    { Mod4Mask,                     XK_Up,         moveresize,             {.v = "0x -25y 0w 0h" } },
    { Mod4Mask,                     XK_Right,      moveresize,             {.v = "25x 0y 0w 0h" } },
    { Mod4Mask,                     XK_Left,       moveresize,             {.v = "-25x 0y 0w 0h" } },
    { Mod4Mask|ShiftMask,           XK_Down,       moveresize,             {.v = "0x 0y 0w 25h" } },
    { Mod4Mask|ShiftMask,           XK_Up,         moveresize,             {.v = "0x 0y 0w -25h" } },
    { Mod4Mask|ShiftMask,           XK_Right,      moveresize,             {.v = "0x 0y 25w 0h" } },
    { Mod4Mask|ShiftMask,           XK_Left,       moveresize,             {.v = "0x 0y -25w 0h" } },
    { MODKEY,                       XK_Return,     zoom,                   {0} },
    { MODKEY,                       XK_g,          incrgaps,               {.i = +1 } },
    { MODKEY|ShiftMask,             XK_g,          incrgaps,               {.i = -1 } },
    /*{ MODKEY|Mod4Mask,              XK_i,          incrigaps,              {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_i,          incrigaps,              {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_o,          incrogaps,              {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_o,          incrogaps,              {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_6,          incrihgaps,             {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_6,          incrihgaps,             {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_7,          incrivgaps,             {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_7,          incrivgaps,             {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_8,          incrohgaps,             {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_8,          incrohgaps,             {.i = -1 } },
    { MODKEY|Mod4Mask,              XK_9,          incrovgaps,             {.i = +1 } },
    { MODKEY|Mod4Mask|ShiftMask,    XK_9,          incrovgaps,             {.i = -1 } },*/
    { Mod4Mask,                     XK_g,          togglegaps,             {0} },
    { Mod4Mask|ShiftMask,           XK_g,          defaultgaps,            {0} },
    { MODKEY,                       XK_Tab,        view,                   {0} },
    { MODKEY|ShiftMask,             XK_Left,       shiftview,              { .i = -1 } },
    { MODKEY|ShiftMask,             XK_Right,      shiftview,              { .i = +1 } },
    { MODKEY,                       XK_Left,       shiftviewclients,       { .i = -1 } },
    { MODKEY,                       XK_Right,      shiftviewclients,       { .i = +1 } },
    { Mod4Mask,                     XK_Left,       shiftboth,              { .i = -1 } }, // note keybinding conflict with focusadjacenttag tagandviewtoleft placedir
    { Mod4Mask,                     XK_Right,      shiftboth,              { .i = +1 } }, // note keybinding conflict with focusadjacenttag tagandviewtoright placedir
    { MODKEY,                       XK_z,          showhideclient,         {0} },
    { MODKEY|ShiftMask,             XK_z,          unhideall,              {0} },
    { MODKEY,                       XK_BackSpace,  killclient,             {0} },
    { MODKEY|ShiftMask,             XK_BackSpace,  killunsel,              {0} },
    { MODKEY|ShiftMask,             XK_q,          quit,                   {0} },
    { MODKEY,                       XK_q,          quit,                   {1} },
    { MODKEY,                       XK_x,          xrdb,                   {.v = NULL } },
    { Mod4Mask,                     XK_t,          setlayout,              {.v = &layouts[0]} },
    { Mod4Mask,                     XK_f,          setlayout,              {.v = &layouts[1]} },
    { Mod4Mask,                     XK_m,          setlayout,              {.v = &layouts[2]} },
    { Mod4Mask,                     XK_b,          setlayout,              {.v = &layouts[3]} },
    { Mod4Mask,                     XK_c,          setlayout,              {.v = &layouts[4]} },
    { Mod4Mask|ShiftMask,           XK_c,          setlayout,              {.v = &layouts[5]} },
    { Mod4Mask,                     XK_d,          setlayout,              {.v = &layouts[6]} },
    { Mod4Mask,                     XK_s,          setlayout,              {.v = &layouts[7]} },
    { Mod4Mask|ShiftMask,           XK_s,          setlayout,              {.v = &layouts[8]} },
    { MODKEY,                       XK_space,      setlayout,              {0} },
    { MODKEY|ShiftMask,             XK_space,      togglefloating,         {0} },
    { MODKEY,                       XK_grave,      togglescratch,          {.v = scratchpadcmd } },
    { MODKEY|ControlMask,           XK_grave,      setscratch,             {.v = scratchpadcmd } },
    { MODKEY|ShiftMask,             XK_grave,      removescratch,          {.v = scratchpadcmd } },
    { MODKEY,                       XK_f,          togglefullscreen,       {0} },
    { MODKEY|ShiftMask,             XK_s,          togglesticky,           {0} },
    { MODKEY,                       XK_0,          view,                   {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,          tag,                    {.ui = ~0 } },
    /*{ MODKEY,                       XK_comma,      focusmon,               {.i = -1 } },
    { MODKEY,                       XK_period,     focusmon,               {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,      tagmon,                 {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period,     tagmon,                 {.i = +1 } },*/
    { MODKEY,                       XK_n,          togglealttag,           {0} },
    { MODKEY,                       XK_minus,      setborderpx,            {.i = -1 } },
    { MODKEY,                       XK_equal,      setborderpx,            {.i = +1 } },
    { MODKEY,                       XK_plus,       setborderpx,            {.i = 0 } },
    { Mod4Mask,                     XK_j,          cyclelayout,            {.i = -1 } },
    { Mod4Mask,                     XK_k,          cyclelayout,            {.i = +1 } },
    TAGKEYS(                        XK_1,                                  0)
    TAGKEYS(                        XK_2,                                  1)
    TAGKEYS(                        XK_3,                                  2)
    TAGKEYS(                        XK_4,                                  3)
    TAGKEYS(                        XK_5,                                  4)
    TAGKEYS(                        XK_6,                                  5)
    TAGKEYS(                        XK_7,                                  6)
    TAGKEYS(                        XK_8,                                  7)
    TAGKEYS(                        XK_9,                                  8)
};

static const Key cmdkeys[] = {
    /* modifier                    keys                     function         argument */
    { 0,                           XK_Escape,               clearcmd,        {0} },
    { ControlMask,                 XK_c,                    clearcmd,        {0} },
    { 0,                           XK_i,                    setkeymode,      {.ui = INSERTMODE} },
};

static const Command commands[] = {
    /* modifier (4 keys)                          keysyms (4 keys)                                function         argument */
    { {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_h,     0,         0},            setlayout,       {.v = &layouts[0]} },
    { {ControlMask, 0,          0,         0},    {XK_w,      XK_o,     0,         0},            setlayout,       {.v = &layouts[2]} },
    { {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_o,     0,         0},            onlyclient,      {0} },
    { {ControlMask, 0,          0,         0},    {XK_w,      XK_v,     0,         0},            setlayout,       {.v = &layouts[0]} },
    { {ControlMask, 0,          0,         0},    {XK_w,      XK_less,  0,         0},            setmfact,        {.f = -0.05} },
    { {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_less,  0,         0},            setmfact,        {.f = +0.05} },
    { {ControlMask, ShiftMask,  0,         0},    {XK_w,      XK_0,     0,         0},            setmfact,        {.f = +1.50} },
    { {ShiftMask,   0,          0,         0},    {XK_period, XK_e,     0,         0},            spawn,           {.v = dmenucmd} },
    { {ShiftMask,   0,          0,         0},    {XK_period, XK_o,     0,         0},            spawn,           {.v = dmenucmd} },
    { {ShiftMask,   0,          0,         0},    {XK_period, XK_q,     XK_Return, 0},            quit,            {0} },
    { {ShiftMask,   0,          0,         0},    {XK_period, XK_b,     XK_d,      XK_Return},    killclient,      {0} },
    { {ShiftMask,   0,          0,         0},    {XK_period, XK_b,     XK_n,      XK_Return},    focusstack,      {.i = +1} },
    { {ShiftMask,   0,          ShiftMask, 0},    {XK_period, XK_b,     XK_n,      XK_Return},    focusstack,      {.i = -1} },
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static const Button buttons[] = {
    /* click                event mask           button          function        argument */
    { ClkLtSymbol,          0,                   Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,                   Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,                   Button1,        togglewin,      {0} },
    { ClkWinTitle,          0,                   Button3,        showhideclient, {0} },
    { ClkWinTitle,          0,                   Button2,        zoom,           {0} },
    { ClkStatusText,        0,                   Button2,        spawn,          {.v = termcmd } },
    /* placemouse options, choose which feels more natural:
     *    0 - tiled position is relative to mouse cursor
     *    1 - tiled postiion is relative to window center
     *    2 - mouse pointer warps to window center
     *
     * The moveorplace uses movemouse or placemouse depending on the floating state
     * of the selected client. Set up individual keybindings for the two if you want
     * to control these separately (i.e. to retain the feature to move a tiled window
     * into a floating position).
     */
    { ClkClientWin,         MODKEY,              Button1,        moveorplace,    {.i = 1} },
    { ClkClientWin,         MODKEY,              Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,              Button3,        resizemouse,    {0} },
    { ClkClientWin,         MODKEY|ShiftMask,    Button1,        dragmfact,      {0} },
    { ClkTagBar,            0,                   Button1,        view,           {0} },
    { ClkTagBar,            0,                   Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,              Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,              Button3,        toggletag,      {0} },
};

