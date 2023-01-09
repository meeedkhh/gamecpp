#ifndef AVATAR_H
#define AVATAR_H
#include <string>
#include "SDL.h"

class avatar
{
	public:
		//cnstructor
		avatar(SDL_Renderer*& render, std::string filepath);
		// Destructor
		~avatar();
		void draw(int x,int y,int h,int w );
		// Select and play a specific frame
        void PlayFrame(int x, int y,int w, int h, int frame);
        // Update every frame
        void Update();
        // Render
        void Render(SDL_Renderer*& render);
        void move(SDL_Event *event);
    protected:
    	SDL_Rect m_src;    // Where we're selecting from
        SDL_Rect m_dst;   // Where we are rendering
        SDL_Texture* m_texture;
};

#endif
