/* See LICENSE file for copyright and license details. */

/* interval between updates (in ms) */
const unsigned int interval = 1000;

/* text to show if no value can be retrieved */
static const char unknown_str[] = "n/a";

/* maximum output string length */
#define MAXLEN 2048

/* battery levels to notify - add any levels you want to receive notification for (in percent) */
const int notifiable_levels[] = {
    20,
    10,
    5,
};

/*
 * function            description                     argument (example)
 *
 * backlight_perc      backlight percentage            device name
 *                                                     (intel_backlight, numbered on FreeBSD)
 *                                                     NULL on OpenBSD
 * battery_perc        battery percentage              battery name (BAT0)
 *
 * battery_notify      linux battery notifications     battery name (BAT0)
 *                                                     OpenBSD/FreeBSD not supported
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_remaining   battery remaining HH:MM         battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * battery_state       battery charging state          battery name (BAT0)
 *                                                     NULL on OpenBSD/FreeBSD
 * cat                 read arbitrary file             path
 * cpu_freq            cpu frequency in MHz            NULL
 * cpu_perc            cpu usage in percent            NULL
 * datetime            date and time                   format string (%F %T)
 * disk_free           free disk space in GB           mountpoint path (/)
 * disk_perc           disk usage in percent           mountpoint path (/)
 * disk_total          total disk space in GB          mountpoint path (/)
 * disk_used           used disk space in GB           mountpoint path (/)
 * entropy             available entropy               NULL
 * gid                 GID of current user             NULL
 * hostname            hostname                        NULL
 * io_in               disk IO (read)                  NULL
 * io_out              disk IO (write)                 NULL
 * io_perc             disk IO (percentage)            NULL
 * ipv4                IPv4 address                    interface name (eth0)
 * ipv6                IPv6 address                    interface name (eth0)
 * kernel_release      `uname -r`                      NULL
 * keyboard_indicators caps/num lock indicators        format string (c?n?)
 *                                                     see keyboard_indicators.c
 * keymap              layout (variant) of current     NULL
 *                     keymap
 * load_avg            load average                    NULL
 * netspeed_rx         receive network speed           interface name (wlan0)
 * netspeed_tx         transfer network speed          interface name (wlan0)
 * num_files           number of files in a directory  path
 *                                                     (/home/foo/Inbox/cur)
 * ram_free            free memory in GB               NULL
 * ram_perc            memory usage in percent         NULL
 * ram_total           total memory size in GB         NULL
 * ram_used            used memory in GB               NULL
 * run_command         custom shell command            command (echo foo)
 * swap_free           free swap in GB                 NULL
 * swap_perc           swap usage in percent           NULL
 * swap_total          total swap size in GB           NULL
 * swap_used           used swap in GB                 NULL
 * temp                temperature in degree celsius   sensor file
 *                                                     (/sys/class/thermal/...)
 *                                                     NULL on OpenBSD
 *                                                     thermal zone on FreeBSD
 *                                                     (tz0, tz1, etc.)
 * uid                 UID of current user             NULL
 * up                  interface is running            interface name (eth0)
 * uptime              system uptime                   NULL
 * username            username of current user        NULL
 * alsa_master_vol     ALSA Master device volume       NULL
 * vol_perc            OSS/ALSA volume in percent      mixer file (/dev/mixer)
 *                                                     NULL on OpenBSD/FreeBSD
 * wifi_essid          WiFi ESSID                      interface name (wlan0)
 * wifi_perc           WiFi signal in percent          interface name (wlan0)
 */
static const struct arg args[] = {
    /* function         format                        argument */
    { cpu_perc,         "\x02 CPU: %s%%\x09 :",         NULL                  },
    { alsa_master_vol,  "\x03 VOL: %s :",               NULL                  },
    { datetime,         "\x4 %s \x09:",                 "%I:%M:%S %p"         },
    { ram_perc,         ";\x02RAM: %s%%\x09  :: ",      NULL                  },
    { backlight_perc,   "\x03 BKL: %s\x09  :: ",       "radeon_bl0"          },
    { uptime,           "\x04 UPT: %s\x09  :: ",        NULL                  },
    { keymap,           "\x05 KMP: %s\x09  :: ",        NULL                  },
    { temp,             "\x07 TMP: %s%%\x09  :: ",      "/sys/class/thermal/thermal_zone0/temp" },
    { swap_perc,        "\x06 SWP: %s%\x09  :: ",       NULL                  },
    { datetime,         "\x02 DAT: %s\x09  :: ",        "%x"                  },
    { disk_perc,        "\x03 DSK: %s%%\x09  :: ",      "/"                   },
    { username,         "\x04 USR: %s\x09",             NULL                  },
    //{ battery_notify, "",       "BAT0"}, /* There is nothing to print its just a notifications*/
};
