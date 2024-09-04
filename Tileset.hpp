#ifndef TILESET_HPP
#define TILESET_HPP

#include <string>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "vector2Structs.hpp"
#include "ResourceManager.hpp"

class Tileset {
	public:
		Tileset(SDL_Renderer* rend, std::string filepath, int tileSize, int tileCount);
		~Tileset();
		int getTileSize();
		int getTileCount();
		void renderTile(SDL_Renderer* rend, int tileCode, SDL_Rect destRect);
	private:
		SDL_Texture* m_texture;
		SDL_Rect m_boundingRect;
		int m_tileSize;
		int m_tileCount;

		// include tile as inner class
		class Tile {
			public:
				Tile(Tileset* parent, SDL_Rect clipRect);
				void render(SDL_Renderer* rend, SDL_Rect destRect);
			private:
				// TODO need to add collision functionality
				Tileset* m_parent;
				SDL_Rect m_clipRect;
		};
		// would be better to use array with malloc style "define fixed size at runtime"
		std::vector<Tile*> m_tiles;

};

#endif