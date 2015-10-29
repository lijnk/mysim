#ifndef CPU_H
#define CPU_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct C;
typedef struct C CPU;

int cpuInit(CPU* cpu); //initialises vm
int cpuTick(CPU* cpu); //performs a single tick
int cpuRunCMD(CPU* cpu, uint16_t cmd); //runs command given
uint16_t cpuGetPC(CPU* cpu); //returns pc
uint16_t cpuGetAReg(CPU* cpu); //returns A register
uint16_t cpuGetDReg(CPU* cpu); //returns D register
size_t cpuSizeof(); //sizeof function for cpu

//user defined
extern void cpuRAMWrite(uint16_t address, uint16_t value); //cpu write to ram
extern uint16_t cpuRAMRead(uint16_t address); //cpu read from ram

#endif

