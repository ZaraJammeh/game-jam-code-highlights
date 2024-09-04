#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <vector>
#include <fstream>

#include <SDL.h>

#include "vector2Structs.hpp"
#include "Tileset.hpp"

class Tilemap {
	public:
		Tilemap(Tileset* source, std::string filepath, position initPos, int rowSize);
		position getPosition();
		void setPosition(position newPos);
		void render(SDL_Renderer* rend);
		void render(SDL_Renderer* rend, position offset);
		void render(SDL_Renderer* rend, position destPos, int scaledTileSize);
	private:
		Tileset* m_source;
		position m_pos;
		int m_rowSize;
		std::vector<std::vector<int>> m_map;
};


#endif