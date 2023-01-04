#include "button.h"

button::button(){
	static SDL_Texture *t = IMG_LoadTexture(render,"buttons.png");
	tex =t;
	
	srect.h=100;
	srect.w=400;
	srect.x=0;
	
	drect.h=75;
	drect.w=300;
	
}

button::~button(){
}

void button::draw(){
	SDL_RenderCopy(render,tex,&srect,&drect);
}
