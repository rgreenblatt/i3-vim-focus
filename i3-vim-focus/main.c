/* File: i3_vim_focus.c
 *
 * Compile with:
 * gcc main.c -lX11 -lxdo -o i3_vim_focus $(pkg-config --libs --cflags i3ipc-glib-1.0)
 *
 */

#include <stdio.h>
#include <stdlib.h>

#include <strings.h>
#include <string.h>

#include <xdo.h>

#include <glib/gprintf.h>
#include <i3ipc-glib/i3ipc-glib.h>
#include <unistd.h>
#include <limits.h>
#define INT_BYTES ((CHAR_BIT * sizeof(int) - 1) / 3 + 2)

int main(int argc, char *argv[]) {

    char cmd[200];

    unsigned char *name;
    int name_len;
    int name_type;
    Window window_ret;

    i3ipcConnection *conn;
    gchar *reply;

    if(argc < 2){
        printf("Missing argument\n");
        return 1;
    }

    xdo_t *xdo = xdo_new(NULL);
    xdo_get_active_window(xdo, &window_ret);
    xdo_get_window_name(xdo, window_ret, &name, &name_len, &name_type);

    if(strstr(name, "nvim")) 
    {
        strcpy(cmd, (argv[1][0] == 'l')? "t":
                    (argv[1][0] == 'd')? "g" :
                    (argv[1][0] == 'u')? "z" :
                                        "p");

        /* strcat(cmd, "&& sleep 1. && xdotool key Super+Escape"); */
        /* charcodemap_t keys; */
        /* xdo_clear_active_modifiers(xdo, window_ret, &keys, 1); */
        /* strcpy(cmd, "Ctrl+backslash"); */
        xdo_send_keysequence_window(xdo, window_ret, cmd, 0);
        /* strcpy(cmd, "Ctrl+n"); */
        /* xdo_send_keysequence_window(xdo, window_ret, cmd, 0); */
        /* strcpy(cmd, "g+z+"); */
        /* strcat(cmd, (argv[1][0] == 'l')? "h" : */
        /*             (argv[1][0] == 'd')? "j" : */
        /*             (argv[1][0] == 'u')? "k" : */
        /*                                 "l"); */
        /* xdo_send_keysequence_window(xdo, window_ret, cmd, 0); */
    }
    else
    {
        conn = i3ipc_connection_new(NULL, NULL);
        strcpy(cmd, "focus ");
        strcat(cmd, argv[1]);
        reply = i3ipc_connection_message(conn, I3IPC_MESSAGE_TYPE_COMMAND, cmd, NULL);
        g_free(reply);
        g_object_unref(conn);
    }

    XFree(name);
    return  0;
}
