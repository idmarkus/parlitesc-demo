//
// Created by eti on 2023-07-08.
//

#pragma once

#include "typedefs.hpp"

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengl.h>

#include <SDL_keyboard.h>
#include <iostream>

namespace PLSC::Demo
{

	class Window
	{
	private:
		SDL_Window* m_window;
		SDL_GLContext m_glContext;
		i32 m_width, m_height;
		b m_sync;

	public:
		explicit Window(i32 width, i32 height, i32 x, i32 y, b vsync);
		explicit Window(i32 width, i32 height, b vsync);
		explicit Window(i32 width, i32 height);

		~Window();

		void init(i32 x, i32 y);

		void setTitle(std::string const& title);
		void setTitle(char const* title);

		[[nodiscard]] inline i32 width() const
		{
			return m_width;
		}
		[[nodiscard]] inline i32 height() const
		{
			return m_height;
		}

		void clear();
		void swap();

		bool keyQuit();
		bool sizeChanged();

	private:
		inline void _crashIf(const bool condition)
		{
			if (condition)
			{
				std::cout << "SDL Error: " << SDL_GetError() << std::endl;
				_exitFailure();
			}
		}
		inline void _exitFailure()
		{
			if (m_window != nullptr) SDL_DestroyWindow(m_window);
			SDL_StopTextInput();
			SDL_Quit();
			exit(EXIT_FAILURE);
		}
	};

} // Demo