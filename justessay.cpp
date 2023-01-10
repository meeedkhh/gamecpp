#include "SDL.h"
#include <SDL_image.h>
#include <iostream>
#define SCREEN_WIDTH  1280
#define SCREEN_HEIGHT 720
#define SPRITE_SIZE    32
#include "avatar.h"

using namespace std ;

static int game(){
	// variable declarations
	SDL_Window* wingame = NULL;
	SDL_Renderer* rengame = NULL;
	SDL_Texture* img = NULL;
	SDL_Surface *temp, *sprite , *screen;

	// Initialize SDL.
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return 1;

	// create the window and renderer
	// note that the renderer is accelerated
	wingame = SDL_CreateWindow("Image Loading", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	rengame = SDL_CreateRenderer(wingame, -1, SDL_RENDERER_ACCELERATED);
	
	screen=SDL_GetWindowSurface(wingame);
	
	// load our image
	img = IMG_LoadTexture(rengame, "C:/Users/Mohamed/Documents/k/screen3.jpg");
	if (img == nullptr) {
		std::cout << "IMG_LoadTexture Error: " << SDL_GetError() << "\n";
		return 1;
	}
	
	avatar avatar1(rengame,"./images/edited.bmp");
	

	int w, h; // texture width & height
	SDL_QueryTexture(img, NULL, NULL, &w, &h); // get the width and height of the texture
	// put the location where we want the texture to be drawn into a rectangle
	// I'm also scaling the texture 2x simply by setting the width and height
	SDL_Rect texr; texr.x = 0; texr.y = 0; texr.w = w; texr.h = h;

	unsigned int lastUpdateTime = 0;

	// main loop
	
	while (1) {

		// event handling
		SDL_Event ev;
		int y=200;
		int x=200;

		if(SDL_PollEvent(&ev)){
			if (ev.type==SDL_QUIT && ev.type==SDL_MOUSEBUTTONDOWN){
				break;
			}
			else if(ev.type==SDL_KEYUP && ev.key.keysym.sym== SDLK_SPACE){
				break;
			}
			switch(ev.type){
				case SDL_KEYDOWN:
            if (ev.key.keysym.sym == SDLK_q) {
                // handle keydown event for 'q' key
                std::cout<<"siir";
            } else if (ev.key.keysym.sym == SDLK_s) {
                // handle keydown event for 's' key
                std::cout<<"siir";
            } else if (ev.key.keysym.sym == SDLK_d) {
                // handle keydown event for 'd' key
                std::cout<<"siir";
            } else if (ev.key.keysym.sym == SDLK_z) {
                // handle keydown event for 'z' key
                std::cout<<"siir";
            }
            break;
        		case SDL_KEYUP:
            if (ev.key.keysym.sym == SDLK_q) {
                // handle keyup event for 'q' key
            	std::cout<<"siir";
            } else if (ev.key.keysym.sym == SDLK_s) {
                // handle keyup event for 's' key
                std::cout<<"siir";
            } else if (ev.key.keysym.sym == SDLK_d) {
                // handle keyup event for 'd' key
                std::cout<<"siir";
            } else if (ev.key.keysym.sym == SDLK_z) {
                // handle keyup event for 'z' key
                std::cout<<"siir";
            }
            break;
		}
			
		}
		avatar1.draw(x,y,150,150);
		// paint the image once every 30ms, i.e. 33 images per second
		if (lastUpdateTime + 30 < SDL_GetTicks()) {
			lastUpdateTime = SDL_GetTicks();
			
			// clear the screen
			SDL_RenderClear(rengame);
			// copy the texture to the rendering context
			SDL_RenderCopy(rengame, img, NULL, &texr);
			
			static int framenumber=0;
			
			avatar1.PlayFrame(0,0,170,170,framenumber);
			avatar1.Render(rengame);
			avatar1.move1(ev);
			framenumber++;
			if(framenumber>6){
				framenumber=0;
			}
			// flip the backbuffer
			// this means that everything that we prepared behind the screens is actually shown
			SDL_RenderPresent(rengame);
		}
	}

	SDL_DestroyTexture(img);
	SDL_DestroyRenderer(rengame);
	SDL_DestroyWindow(wingame);

	return 0;
}

