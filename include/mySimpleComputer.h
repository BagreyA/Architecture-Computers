#pragma once
#include "./myTerm.h"
#include <stdbool.h>

#define OVERFLOW_FLAG 0
#define ZERO_DIVISION_FLAG 1
#define MEMORY_OUT_FLAG 2
#define IGNORE_SIGNAL_FLAG 3
#define WRONG_COMMAND_FLAG 4

#define CACHE_SIZE 5
#define CACHE_LINE_SIZE 10

extern const int MEMORY_SIZE;
extern int *memory;
extern struct L1 *cache;

struct L1
{
  int address;
  int data[CACHE_LINE_SIZE];
  int lastAccessTime;
};

int sc_memoryInit (void);
int sc_memorySet (int address, int value);
int sc_memoryGet (int address, int *value);
int sc_memorySave (char *filename);
int sc_memoryLoad (char *filename);

int sc_regInit (void);
int sc_regSet (int reg, int value);
int sc_regGet (int reg, int *value);
int sc_accumulatorInit (void);
int sc_accumulatorSet (int value);
int sc_accumulatorGet (int *value);
int sc_icounterInit (void);
int sc_icounterSet (int value);
int sc_icounterGet (int *value);

int sc_commandEncode (int sign, int command, int operand, int *value);
int sc_commandDecode (int value, int *sign, int *command, int *operand);
int sc_commandValidate (int command);

void printCell (int address, enum colors fg, enum colors bg);
void printFlags (void);
void printDecodedCommand (int value);
void printAccumulator (void);
void printCounters (void);

int sc_oldCacheGet (void);