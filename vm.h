#ifndef VM_H
#define VM_H
#include "cpu.h"
#include "mem.h"
#include "inc/GLFW/glfw3.h"

#define SCR_H 256
#define SCR_W 512

int vmInit(); //initialises vm
void vmClean(); //clean up vm
int vmLoadRom(char* fn); //loads rom into memory
void vmTick(); //ticks vm cpu

uint16_t vmPeekRAM(uint16_t address); //peek into RAM
uint16_t vmPeekROM(uint16_t address); //peek into ROM
uint16_t vmPeekPC(); //peek into program counter
uint16_t vmPeekAReg(); //peek into A register
uint16_t vmPeekDReg(); //peek into D register
void vmKBDEvent(uint16_t key); //set keyboard event
void vmDrawScreen(); //draw screen

#endif
