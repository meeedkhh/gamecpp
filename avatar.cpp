#include "avatar.h"
#include "ResourceManager.h"
#include <iostream>

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


void avatar::move1(SDL_Event event){

		
		
	
}

