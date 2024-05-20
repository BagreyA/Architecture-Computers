#pragma once
#include "../mySimpleComputer/sc.h"
#include <mySimpleComputer.h>
#include <myTerm.h>
#include <unistd.h>

#define ACS_CKBOARD 'a'  // Прямоугольник закрашенный
#define ACS_ULCORNER 'l' // Левый верхний угол LUCORNER
#define ACS_URCORNER 'k' // Правый верхний угол
#define ACS_LRCORNER 'j' // Правый нижний угол
#define ACS_LLCORNER 'm' // Левый нижний угол
#define ACS_HLINE 'q'    // Горизонтальная линия
#define ACS_VLINE 'x'    // Вертикальная линия

extern int bc[16][2];

int bc_strlen (char *str);
int bc_printA (char str);
int bc_box (int x1, int y1, int x2, int y2, enum colors box_fg,
            enum colors box_bg, char *header, enum colors header_fg,
            enum colors header_bg);

int bc_setbigcharpos (int *big, int x, int y, int value);
int bc_getbigcharpos (int *big, int x, int y, int *value);

int bc_printbigchar (int *big, int x, int y, enum colors bg, enum colors fg);

int bc_bigcharwrite (int fd, int *big, int count);
int bc_bigcharread (int fd, int *big, int need_count, int *count);

void printBigCell (void);