#include "cpu.h"

struct C {
	uint16_t DReg; //d register
	uint16_t AReg; //a register
	uint16_t PC; //program counter
	uint16_t RomSize; //size of rom
};

int cpuInit(CPU* cpu)
{
	cpu->DReg = 0;
	cpu->AReg = 0;
	cpu->PC = 0;
	cpu->RomSize = 0;

	return 0;
}

int cpuRunCMD(CPU* cpu, uint16_t cmd)
{
	if(!(cmd & 0x8000)) //address instruction
	{
		cpu->AReg = cmd & 0x7FFF; //load a register
		cpu->PC++;
		return 0;
	}

	//command instruction
	int16_t out = 0; //resulting cpu result
	uint16_t xmem = cpu->DReg; //x input
	uint16_t ymem = 0; //a register or memory location

	//whether we take from ram or a register
	if(cmd & 0x1000)
		ymem = cpuRAMRead(cpu->AReg);
	else
		ymem = cpu->AReg;

	if(cmd & 0x800) xmem = 0;
	if(cmd & 0x400) xmem = ~xmem;
	if(cmd & 0x200) ymem = 0;
	if(cmd & 0x100) ymem = ~ymem;
	if(cmd & 0x080) out = xmem + ymem;
	else out = xmem & ymem;
	if(cmd & 0x040) out = ~out;

	//jump
	if((cmd & 0x4) && (out < 0)) cpu->PC = cpu->AReg;
	else if((cmd & 0x2) && (out == 0)) cpu->PC = cpu->AReg;
	else if((cmd & 0x1) && (out > 0)) cpu->PC = cpu->AReg;
	else cpu->PC++;

	//destination
	if(cmd & 0x08) cpuRAMWrite(cpu->AReg, out);
	if(cmd & 0x10) cpu->DReg = out;
	if(cmd & 0x20) cpu->AReg = out;

	return 0;
}

uint16_t cpuGetPC(CPU* cpu)
{
	return cpu->PC;
}

uint16_t cpuGetAReg(CPU* cpu)
{
	return cpu->AReg;
}

uint16_t cpuGetDReg(CPU* cpu)
{
	return cpu->DReg;
}

size_t cpuSizeof()
{
	return sizeof(CPU);
}
