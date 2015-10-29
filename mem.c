#include "mem.h"

struct M {
	uint16_t* RAM;
	uint16_t* ROM;
	uint16_t* SCR;
	uint16_t KBD;
	uint16_t RomSize;
};

int memInit(Mem* mem)
{
	//16K RAM
	if((mem->RAM = (uint16_t*)calloc(0x4000, sizeof(uint16_t))) == NULL)
		return 1;

	//32K ROM
	if((mem->ROM = (uint16_t*)calloc(0x8000, sizeof(uint16_t))) == NULL)
	{
		free(mem->RAM);
		return 1;
	}

	//8K Screen
	if((mem->SCR = (uint16_t*)calloc(0x2000, sizeof(uint16_t))) == NULL)
	{
		free(mem->RAM);
		free(mem->ROM);
		return 1;
	}

	mem->KBD = 0;
	mem->RomSize = 0;

	return 0;
}

void memClean(Mem* mem)
{
	free(mem->RAM);
	free(mem->ROM);
	free(mem->SCR);
}

uint16_t memRAMRead(Mem* mem, uint16_t address)
{
	if(mem->RAM == NULL)
	{
		printf("Error: Memory not initialised\n");
		return 0;
	}

	if(address < 0x4000)
	{
		return mem->RAM[address];
	}
	else if(address <= 0x5FFF)
	{
		return mem->SCR[address % 0x2000];
	}
	else if(address == 0x6000)
	{
		return mem->KBD;
	}

	printf("Error: read memory violation [%.4X]\n", address);

	return 0;
}

void memRAMWrite(Mem* mem, uint16_t address, uint16_t value)
{
	if(mem->RAM == NULL)
	{
		printf("Error: Memory not initialised\n");
		return;
	}

	if(address < 0x4000)
	{
		mem->RAM[address] = value;
	}
	else if(address <= 0x5FFF)
	{
		mem->SCR[address % 0x2000] = value;
	}
	else if(address == 0x6000)
	{
		mem->KBD = value;
	}
	else
	{
		printf("Error: write memory violation [%.4X]\n", address);
	}

	return;
}

uint16_t memROMRead(Mem* mem, uint16_t address)
{
	if(mem->ROM == NULL)
	{
		printf("Error: Memory not initialised\n");
		return 0;
	}

	return mem->ROM[address];
}

int memOpenROM(Mem* mem, char* fn)
{
	if(mem->ROM == NULL)
	{
		printf("Error: Memory not initialised\n");
		return 1;
	}

	FILE *fp; //file pointer
	int size; //size
	unsigned char* buffer; //buffer

	//open file
	if((fp = fopen(fn, "rb")) == NULL)
	{
		return 1;
	}

	//get the size
	fseek(fp, 0, SEEK_END);
	size = ftell(fp);
	rewind(fp);

	//read the file
	buffer = (unsigned char*) calloc(size+1, sizeof(char));
	fread(buffer, 1, size, fp);
	fclose(fp);

	//write characters into ROM, 2 bytes at a time
	for(int i = 0; i < size; i+=2)
	{
		mem->ROM[mem->RomSize] = (uint16_t) buffer[i];
		mem->ROM[mem->RomSize] += (uint16_t) buffer[i+1] << 8;
		mem->RomSize++;
	}
	free(buffer);
	return 0;
}

void memPrintROM(Mem* mem)
{
	int line = 0;
	for(int i = 0; i < mem->RomSize; i++)
	{
		if(line++ >= 16)
		{
			line = 0;
			printf("%.4X\n", mem->ROM[i]);
		}
		else
		{
			printf("%.4X ", mem->ROM[i]);
		}
	}
	printf("\n");
}

size_t memSizeof()
{
	return sizeof(Mem);
}

