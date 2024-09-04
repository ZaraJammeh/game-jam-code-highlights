#include "LoopingTextureRect.hpp"

LoopingTextureRect::LoopingTextureRect(SDL_Renderer* rend, std::string filepath, position initPos, dimensions initDims, char loopDir)
	: TextureRect(rend, filepath, initPos, initDims) {
	m_resetPos = initPos;
	m_loopDir = loopDir;
}

void LoopingTextureRect::scroll(position offset) {
	// sets position by adding offset and looping if necessary
	position newPos = m_pos;
	switch (m_loopDir) {
	
	case 'h':
		newPos.x -= offset.x;
		if (newPos.x > m_dims.w || newPos.x < -(m_dims.w)) {
			newPos = m_resetPos;
		}
		break;
	case 'v':
		newPos.y -= offset.y;
		if (newPos.y > m_dims.h || newPos.y < -(m_dims.h)) {
			newPos = m_resetPos;
		}
		break;
	default:
		break;
	}
	this->setPosition(newPos);
}

void LoopingTextureRect::render(SDL_Renderer* rend) {
	SDL_RenderCopy(rend, m_texture, NULL, &m_boundingRect);
	// render copies of the same texture directly before and after it
	SDL_Rect beforeBounds = m_boundingRect;
	SDL_Rect afterBounds = m_boundingRect;
	switch (m_loopDir) {
	// better system would be to use enum instead of char
	case 'h':
		beforeBounds.x -= m_dims.w;
		afterBounds.x += m_dims.w;
		break;
	case 'v':
		beforeBounds.y -= m_dims.h;
		afterBounds.y += m_dims.h;
		break;
	default:
		break;
	}
	SDL_RenderCopy(rend, m_texture, NULL, &beforeBounds);
	SDL_RenderCopy(rend, m_texture, NULL, &afterBounds);
}