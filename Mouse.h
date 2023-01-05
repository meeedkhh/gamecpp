#ifndef MOUSE_H
#define MOUSE_H
#include <SDL.h>
#include <SDL_image.h>
class Mouse
{
	
	public:
	    SDL_Texture * tex;
	    SDL_Rect rect;
	    SDL_Rect point;
	    SDL_Renderer *ren;

	    Mouse(){
	        tex = IMG_LoadTexture(ren, "C:/Users/Mohamed/Desktop/pro_s3/mouse.png");
	        rect.w = 25;
	        rect.h = 25;
	        point.w = 1;
	        point.h = 1;      
	    
	    }
    
	    void update(){
	        SDL_GetMouseState(&rect.x, &rect.y);
	        point.x = rect.x;
	        point.y = rect.y;
	    }
    
	    void draw(){
	        SDL_RenderCopy(ren, tex, NULL, &rect);
	    }

};

#endif
