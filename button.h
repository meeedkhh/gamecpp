#ifndef BUTTON_H
#define BUTTON_H
#include <SDL.h>
#include <SDL_image.h>
#include "Mouse.h"


class button
{
	public:
		SDL_Texture *tex;
		SDL_Rect srect , drect;
		bool isSelected = false;
		SDL_Renderer *render;
		button();
		virtual ~button();
		bool draw();
};

#endif
