#include "Tileset.hpp"

Tileset::Tile::Tile(Tileset* parent, SDL_Rect clipRect) {
	m_parent = parent;
	m_clipRect = clipRect;
}

void Tileset::Tile::render(SDL_Renderer* rend, SDL_Rect destRect) {
	// render relevant part of parent tileset texture
	SDL_RenderCopy(rend, m_parent->m_texture, &m_clipRect, &destRect);
}

Tileset::Tileset(SDL_Renderer* rend, std::string filepath, int tileSize, int tileCount) {
	// initialise all member variables
	SDL_Surface* surface = ResourceManager::getInstance().getSurface(filepath);
	m_texture = SDL_CreateTextureFromSurface(rend, surface);
	dimensions textureDims; // get texture dimensions
	SDL_QueryTexture(m_texture, NULL, NULL, &textureDims.w, &textureDims.h);
	m_boundingRect = SDL_Rect(0, 0, textureDims.w, textureDims.h);
	m_tileSize = tileSize;
	m_tileCount = tileCount;

	// instantiate and store Tiles
	int i;
	position clipPos(0, 0);
	SDL_Rect clipRect(clipPos.x, clipPos.y, tileSize, tileSize);
	Tile* newTile;
	for (i = 0; i < tileCount; i++) {
		newTile = new Tile(this, clipRect);
		m_tiles.push_back(newTile);
		clipPos.x += tileSize;
		if (clipPos.x >= m_boundingRect.w) {
			// move to next row
			clipPos.x = 0;
			clipPos.y += tileSize;
		}
		// future improvements - use pointers instead, to update changes automatically
		clipRect.x = clipPos.x;
		clipRect.y = clipPos.y;
	}
}

Tileset::~Tileset() {
	int i;
	for (i = m_tiles.size()-1; i >= 0 ; i--) {
		delete m_tiles[i];
	}
}

int Tileset::getTileSize() {
	return m_tileSize;
}

int Tileset::getTileCount() {
	return m_tileCount;
}

void Tileset::renderTile(SDL_Renderer* rend, int tileCode, SDL_Rect destRect) {
	m_tiles[tileCode]->render(rend, destRect);
}