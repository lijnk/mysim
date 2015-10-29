#ifndef MEM_H
#define MEM_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct M;
typedef struct M Mem;

int memInit(Mem* mem); //init memory
void memClean(Mem* mem); //clean up memory
uint16_t memRAMRead(Mem* mem, uint16_t address); //read memory
void memRAMWrite(Mem* mem, uint16_t address, uint16_t value); //write memory
uint16_t memROMRead(Mem* mem, uint16_t address); //read rom
int memOpenROM(Mem* mem, char* fn); //open rom file
void memPrintROM(Mem* mem); //print rom contents

size_t memSizeof(); //size of memory type

#endif
