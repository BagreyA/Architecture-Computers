#include "../include/mySimpleComputer.h"

const int MEMORY_SIZE = 128;
int *memory;

char AX;
unsigned char CX;
char Flag;
struct L1 *cache;
int updateCacheFlag = 0;