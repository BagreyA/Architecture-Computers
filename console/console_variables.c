#include <console.h>
#include <stdio.h>

char **in_out = NULL;
int editing_cell = 0;
int gui_refresh_flag = 0;
struct memBuffer membuffer[4] = { 0 };
int in_out_ind = 0;