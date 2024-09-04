#ifndef LOOPINGTEXTURERECT_HPP
#define LOOPINGTEXTURERECT_HPP

#include "TextureRect.hpp"

class LoopingTextureRect : public TextureRect {
	public:
		LoopingTextureRect(SDL_Renderer* rend, std::string filepath, position initPos, dimensions initDims, char loopDir);
		//~LoopingTextureRect();
		void scroll(position offset);
		void render(SDL_Renderer* rend);
	private:
		position m_resetPos;
		char m_loopDir;
};

#endif