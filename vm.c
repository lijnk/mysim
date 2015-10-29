#include "vm.h"

typedef struct V {
	CPU* cpu;
	Mem* mem;
} VM;

typedef struct P {
	float r;
	float g;
	float b;
} Pix;

static VM* vm;

extern GLFWwindow* window;

int vmInit()
{
	if((vm = (VM*)malloc(sizeof(VM))) == NULL)
		return 1;

	if((vm->cpu = (CPU*)malloc(cpuSizeof())) == NULL)
	{
		free(vm);
		return 1;
	}

	if((vm->mem = (Mem*)malloc(memSizeof())) == NULL)
	{
		free(vm);
		free(vm->cpu);
		return 1;
	}

	if(cpuInit(vm->cpu) != 0)
	{
		free(vm);
		free(vm->cpu);
		free(vm->mem);
		return 1;
	}

	if(memInit(vm->mem) != 0)
	{
		free(vm);
		free(vm->cpu);
		free(vm->mem);
		return 1;
	}

	return 0;
}

void vmClean()
{
	memClean(vm->mem);
	free(vm->cpu);
	free(vm->mem);
	free(vm);
}

int vmLoadRom(char* fn)
{
	return memOpenROM(vm->mem, fn);
}

void vmTick()
{
	cpuRunCMD(vm->cpu, memROMRead(vm->mem, cpuGetPC(vm->cpu)));
}

uint16_t vmPeekRAM(uint16_t address)
{
	return memRAMRead(vm->mem, address);
}

uint16_t vmPeekROM(uint16_t address)
{
	return memROMRead(vm->mem, address);
}

uint16_t vmPeekPC()
{
	return cpuGetPC(vm->cpu);
}

uint16_t vmPeekAReg()
{
	return cpuGetAReg(vm->cpu);
}

uint16_t vmPeekDReg()
{
	return cpuGetAReg(vm->cpu);
}

void vmKBDEvent(uint16_t key)
{
	memRAMWrite(vm->mem, 0x6000, key);
}

void vmDrawScreen()
{
	Pix* screen = (Pix*)calloc(SCR_H*SCR_W, sizeof(Pix));

	glClearColor(1, 0, 0, 0);
	glClear(GL_COLOR_BUFFER_BIT);

	for(int i = 0; i < 0x2000; i++)
	{
		uint16_t value = memRAMRead(vm->mem, i + 0x4000);
		for(uint16_t j = 0; j < 16; j++)
		{
			if((value>>j) & 1)
			{
				screen[(i*16)+j].r = 0.f;
				screen[(i*16)+j].g = 0.f;
				screen[(i*16)+j].b = 0.f;
			}
			else
			{
				screen[(i*16)+j].r = 1.f;
				screen[(i*16)+j].g = 1.f;
				screen[(i*16)+j].b = 1.f;
			}
		}
	}
	glDrawPixels(SCR_W, SCR_H, GL_RGB, GL_FLOAT, screen);
	glPixelZoom(1.f, -1.f);
	glfwSwapBuffers(window);

	free(screen);
}

void cpuRAMWrite(uint16_t address, uint16_t value)
{
	memRAMWrite(vm->mem, address, value);
	if(address >= 0x4000)
	{
		vmDrawScreen();
	}
}

uint16_t cpuRAMRead(uint16_t address)
{
	memRAMRead(vm->mem, address);
}

