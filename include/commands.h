#define NOP 0x00
#define CPUINFO 0x01

#define READ 0x0A
#define WRITE 0x0B

#define LOAD 0x14
#define STORE 0x15

#define ADD 0x1E
#define SUB 0x1F
#define DIVIDE 0x20
#define MUL 0x21

#define JUMP 0x28
#define JNEG 0x29
#define JZ 0x2A
#define HALT 0x2B

#define NOT 0x33
#define AND 0x34
#define OR 0x35
#define XOR 0x36

#define JNS 0x37
#define JC 0x38
#define JNC 0x39
#define JP 0x3A
#define JNP 0x3B

#define CHL 0x3C
#define SHR 0x3D
#define RCL 0x3E
#define RCR 0x3F

#define NEG 0x40
#define ADDC 0x41
#define SUBC 0x42

#define LOGLC 0x43
#define LOGRC 0x44
#define RCCL 0x45
#define RCCR 0x46

#define MOVA 0x47
#define MOVR 0x48
#define MOVCA 0x49
#define MOVCR 0x4A