#ifndef RESOURCEMANAGER_H
#define RESOURCEMANAGER_H

#include <string>
#include <unordered_map>

#include "SDL.h"

class ResourceManager
{
	public:
		static ResourceManager& GetInstance();

        SDL_Surface* GetSurface(std::string filepath);
        
    protected:
		ResourceManager();
        ResourceManager(ResourceManager const&);
        ResourceManager operator=(ResourceManager const&);

        std::unordered_map<std::string, SDL_Surface*> m_surfaces;
};

#endif
