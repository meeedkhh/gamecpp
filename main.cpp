#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include <SDL_mixer.h>
#include "button.h"
#include "Mouse.h"
#define WIDTH 1280
#define HEIGHT 720
#include "justessay.cpp"

using namespace std;
typedef struct{
	SDL_Texture *mous;
	SDL_Rect mrect;
	SDL_Rect point;
}mous2;

typedef struct{
	SDL_Texture *tex;
	SDL_Rect srect , drect;
	bool isSelected = false;
}button1;




int main(int argc, char* argv[]) {

	// variable declarations
	SDL_Window* win = NULL;
	SDL_Renderer* renderer = NULL;
	SDL_Texture* img = NULL;
	SDL_Texture* img1 = NULL;
	// Initialize SDL.
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		return 1;

	// create the window and renderer
	// note that the renderer is accelerated
	win = SDL_CreateWindow("Image Loading", SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	renderer = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);

	// initializing my mouse and rendering a game mouse
	mous2 mous1;
	
	// here i give the texture that i want to work with 
	mous1.mous=IMG_LoadTexture(renderer, "C:/Users/Mohamed/Desktop/pro_s3/mouse.png");
	if (mous1.mous == nullptr) {
		std::cout << "IMG_LoadTexture Error: " << SDL_GetError() << "\n";
		return 1;
	}
	
	mous1.mrect.h=25;
	mous1.mrect.w=25;
	mous1.point.h=1;
	mous1.point.w=1;
	

	// load our image
	img = IMG_LoadTexture(renderer, "C:/Users/Mohamed/Documents/k/MENU_GAME.png");
	
	if (img == nullptr) {
		std::cout << "IMG_LoadTexture Error: " << SDL_GetError() << "\n";
		return 1;
	}
	
	// load our image
	img1 = IMG_LoadTexture(renderer, "C:/Users/Mohamed/Documents/k/screen2.jpg");
	
	if (img1 == nullptr) {
		std::cout << "IMG_LoadTexture Error: " << SDL_GetError() << "\n";
		return 1;
	}

	int w, h; // texture width & height
	SDL_QueryTexture(img, NULL, NULL, &w, &h); // get the width and height of the texture
	// put the location where we want the texture to be drawn into a rectangle
	// I'm also scaling the texture 2x simply by setting the width and height

	SDL_QueryTexture(img1, NULL, NULL, &w, &h);
	SDL_Rect texr; texr.x = 0; texr.y = 0; texr.w = w; texr.h = h;

	unsigned int lastUpdateTime = 0;
	

	//initializing a start button and give it the x and y	
	button1 start1;
	// loading the image of start button 
	start1.tex = IMG_LoadTexture(renderer,"C:/Users/Mohamed/Desktop/pro_s3/buttons2.png");
	if (start1.tex == nullptr) {
		std::cout << "IMG_LoadTexture Error: " << SDL_GetError() << "\n";
		return 1;
	}
	// rect that will contain the start button image 
	start1.srect.h=100;
	start1.srect.w=400;
	start1.srect.x=0;
	start1.srect.y=0;
	
	// rect for the place where we want the start button to show 
	start1.drect.h=75;
	start1.drect.w=300;
	start1.drect.x=1280/2 -200;
	start1.drect.y=200;
	
	button1 exit ;
	// loading the image of exit button 
	exit.tex = IMG_LoadTexture(renderer,"C:/Users/Mohamed/Desktop/pro_s3/buttons2.png");
	if (start1.tex == nullptr) {
		std::cout << "IMG_LoadTexture Error: " << SDL_GetError() << "\n";
		return 1;
	}
	// rect that will contain the exit button image 
	exit.srect.h=100;
	exit.srect.w=400;
	exit.srect.x=0;
	exit.srect.y=700;
	
	// rect for the place where we want the start button to show 
	exit.drect.h=75;
	exit.drect.w=300;
	exit.drect.x=1280/2 -200;
	exit.drect.y=440;
	
	button1 options;
	// loading the image of exit button 
	options.tex = IMG_LoadTexture(renderer,"C:/Users/Mohamed/Desktop/pro_s3/buttons2.png");
	if (options.tex == nullptr) {
		std::cout << "IMG_LoadTexture Error: " << SDL_GetError() << "\n";
		return 1;
	}
	// rect that will contain the options button image 
	options.srect.h=100;
	options.srect.w=400;
	options.srect.x=0;
	options.srect.y=300;
	
	// rect for the place where we want the options button to show 
	options.drect.h=75;
	options.drect.w=300;
	options.drect.x=1280/2 -200;
	options.drect.y=320;
	
	// main loop
	while (1) {
		
		// updating the mouse by getting the mouse coord and give it to the mouse that i want to work with 
		
		SDL_GetMouseState(&mous1.mrect.x, &mous1.mrect.y);
	    mous1.point.x = mous1.mrect.x;
	    mous1.point.y = mous1.mrect.y;
	    // and hiding the original cursor 
	    SDL_ShowCursor(false);
	    
		// here the prgram check if there is any intersection between the cursor and the 
		// start button and change the color of start button
	    if(SDL_HasIntersection(&(mous1.mrect) , &(start1.drect))){
	        start1.isSelected = true;
	        start1.srect.x = 400;   
	    }
	    else if(SDL_HasIntersection(&(mous1.mrect) , &(exit.drect))){
	    	exit.isSelected=true;
	    	exit.srect.x=400;
	    	cout<<"exit selcted";
		}
		else if(SDL_HasIntersection(&(mous1.mrect) , &(options.drect))){
	    	options.isSelected=true;
	    	options.srect.x=400;
	    	cout<<"options selcted";
		}
		else{
	        start1.isSelected = false;
	        start1.srect.x = 0;
	        exit.isSelected=false;
	    	exit.srect.x=0;
	    	options.isSelected=false;
	    	options.srect.x=0;
	    }
	    
		// event handling
		SDL_Event e;
		if (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT)
				break;
			else if (e.type == SDL_KEYUP && e.key.keysym.sym == SDLK_ESCAPE)
				break;
			else if (e.type == SDL_KEYUP){
				img=img1;
			}
			else if(e.type==SDL_MOUSEBUTTONDOWN && exit.isSelected==true){
				img=IMG_LoadTexture(renderer, "C:/Users/Mohamed/Documents/k/MENU_GAME.png");
			}
			else if(e.type==SDL_MOUSEBUTTONDOWN && start1.isSelected==true){
				game();
			}
		
			
		}

		// paint the image once every 30ms, i.e. 33 images per second
		if (lastUpdateTime + 30 < SDL_GetTicks() ) {
			lastUpdateTime = SDL_GetTicks();

			// clear the screen
			SDL_RenderClear(renderer);
			// copy the texture to the rendering context
			
			SDL_RenderCopy(renderer, img, NULL, &texr);
			//rendering the start button and exit button
			if(img1==img){
				SDL_RenderCopy(renderer,start1.tex,&start1.srect,&start1.drect);
				SDL_RenderCopy(renderer,exit.tex,&exit.srect,&exit.drect);
				SDL_RenderCopy(renderer,options.tex,&options.srect,&options.drect);
			}
			
			//rendering the texture of the cursor
			SDL_RenderCopy(renderer, mous1.mous, NULL, &mous1.mrect);
		
			
			// flip the backbuffer
			// this means that everything that we prepared behind the screens is actually shown
			SDL_RenderPresent(renderer);
			
		}
	}
	

	SDL_DestroyTexture(img);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(win);
	

	return 0;
}

