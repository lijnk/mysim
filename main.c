#define GLFW_INCLUDE_GLU
#include "inc/GLFW/glfw3.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <windows.h>
#include "vm.h"

GLFWwindow* window;

void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(action == GLFW_RELEASE)
	{
		vmKBDEvent(0);
	}
	else if(action == GLFW_PRESS)
	{
		int shiftStatus = glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) | glfwGetKey(window, GLFW_KEY_RIGHT_SHIFT);
		switch(key)
		{
#include "kbd.h"
		}
	}
}

static void cursor_position_callback(GLFWwindow* window, double x, double y)
{
}

static void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.f, width, 0.f, height);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glRasterPos2i(0, height);
}

static void error_callback(int error, const char* description)
{
	fprintf(stderr, "Error: %s\n", description);
}

int main(int argc, char** argv)
{
	int width, height;

	glfwSetErrorCallback(error_callback);
	
	if(!glfwInit())
		exit(EXIT_FAILURE);

	window = glfwCreateWindow(SCR_W, SCR_H, "MySim", NULL, NULL);
	if(!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwSetCursorPosCallback(window, cursor_position_callback);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	glfwSetKeyCallback(window, key_callback);

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwGetFramebufferSize(window, &width, &height);
	framebuffer_size_callback(window, width, height);

	if(vmInit() != 0)
	{
		printf("Failed to initialise VM (%s)\n", strerror(errno));
		system("PAUSE");
		return 1;
	}

	if(vmLoadRom("./rom/Pong.rom") != 0)
	{
		printf("Failed to read rom (%s)\n", strerror(errno));
		vmClean();
		system("PAUSE");
		return 1;
	}

	while(vmPeekRAM(0x3FFF) == 0)
	{
		vmTick();
		glfwPollEvents();
	}

	//vmDrawScreen();

	vmClean();
	system("PAUSE");

	return 0;
}

