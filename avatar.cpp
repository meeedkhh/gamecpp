#include "avatar.h"
#include "ResourceManager.h"

avatar::avatar(SDL_Renderer*& render, std::string filepath){
	
	SDL_Surface *retrieveSurface = ResourceManager::GetInstance().GetSurface(filepath);
	m_texture = SDL_CreateTextureFromSurface(render,retrieveSurface);
}

avatar::~avatar(){
	SDL_DestroyTexture(m_texture);
}


void avatar::draw(int x, int y, int h, int w){
	// Create a rectangle
    m_dst.x = x;
    m_dst.y = y;
    m_dst.w = w;
    m_dst.h = h;
}
void avatar::PlayFrame(int x , int y , int h,int w,int frame){
	m_src.x=x + w*frame;
	m_src.y=y;
	m_src.h=h;
	m_src.w=w;
}

void avatar::Update(){
	
}

void avatar::Render(SDL_Renderer*&render){
	SDL_RenderCopy(render,m_texture,&m_src,&m_dst);
}


void avatar::move(SDL_Event *event){

	if(SDL_PollEvent(event)){
		
		if(event->type==SDL_KEYDOWN ){
			if (event->key.keysym.sym == SDLK_a ) {
                // handle keydown event for 'q' key
                m_dst.x--;
                
            } 
//			else if (event.key.keysym.sym == SDLK_s) {
//	                // handle keydown event for 's' key
//	                m_dst.y++;
//	            }
//			else if (event.key.keysym.sym == SDLK_d) {
//	                // handle keydown event for 'd' key
//	                m_dst.x++;
//	            } 
//			else if (event.key.keysym.sym == SDLK_w) {
//	                // handle keydown event for 'z' key
//	                m_dst.y--;
//            }
		}
		
	}
}

