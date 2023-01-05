#include "button.h"

button::button(){
	
	static SDL_Texture *t=NULL;
	t = IMG_LoadTexture(render,"C:/Users/Mohamed/Desktop/pro_s3/buttons2.png");
	tex =t;

	srect.h=100;
	srect.w=400;
	srect.x=0;
	
	drect.h=75;
	drect.w=300;
	
}

button::~button(){
}

bool button::draw(){
	if (tex == nullptr) {
		return 1;
	}
	SDL_RenderCopy(render,tex,&srect,&drect);
}
