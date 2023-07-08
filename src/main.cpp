#include "PLSC.hpp"
#include "Window.hpp"

#include <iostream>
#include <chrono>
#include <string>

int main(int argc, char** argv)
{
	(void)argc;
	(void)argv;

	PLSC::Demo::Window window(1280, 720, 50, 50, false);

	i32 i = 0;
	while (!window.keyQuit())
	{
		window.clear();
		window.setTitle(std::to_string(i++));
		window.swap();
	}

	return 0;
}
