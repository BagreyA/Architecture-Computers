#pragma once

struct memBuffer
{
  int addr;
  int buf;
  int input;
};

extern struct memBuffer membuffer[4];
extern char **in_out;
extern int editing_cell;
extern int gui_refresh_flag;
extern int in_out_ind;

void printMemory (void);
void printTerm (int, int, struct memBuffer *);
void print_message (char *msg);
void printCache (void);
void sc_initCache (void);
void init_default (void);
void validate_cell (void);
void draw_blocks (void);
void render_gui (void);
int input_value (int address);

int edit_acc (void);
int edit_counter (void);
int read_memcell (int pos);

void CU (void);
int ALU (int command, int operand);
void IRC (int signum);