CC = i586-mingw32msvc-gcc -std=c99
USE = -L./lib/ -mwindows -lglfw3 -lglu32 -lopengl32 -Wl,--subsystem,console
#CC = gcc -ggdb -std=c99
#USE = -Wall
OBJECTS = cpu.o mem.o vm.o main.o

hasm : $(OBJECTS)
	./rom/hasm ./rom/*.asm
	$(CC) -o mysim.exe $(OBJECTS) $(USE)

.PHONY : clean
clean :
	rm -rf $(OBJECTS) mysim.exe
