#ifndef TEXTURERECT_HPP
#define TEXTURERECT_HPP

#include <string>

#include <SDL.h>

#include "vector2Structs.hpp"
#include "ResourceManager.hpp"

class TextureRect {
	public:
		TextureRect() {};
		TextureRect(SDL_Renderer* rend, std::string filepath, position initPos, dimensions initDims);
		~TextureRect();
		SDL_Rect getBoundingRect();
		SDL_Texture* getTexturePtr();
		position getPosition();
		dimensions getDimensions();
		void setPosition(position newPos);
		void setDimensions(dimensions newDims);
		void update();
		void render(SDL_Renderer* rend);
		void render(SDL_Renderer* rend, position offset);
		void render(SDL_Renderer* rend, position destPos, int scaleMult);
	protected:
		SDL_Texture* m_texture;
		position m_pos;
		dimensions m_dims;
		SDL_Rect m_boundingRect;
};

#endif