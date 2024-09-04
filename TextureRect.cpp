#include "TextureRect.hpp"

TextureRect::TextureRect(SDL_Renderer* rend, std::string filepath, position initPos, dimensions initDims) {
    SDL_Surface* surface = ResourceManager::getInstance().getSurface(filepath);
    m_texture = SDL_CreateTextureFromSurface(rend, surface);
    // match pos, dims and boundingRect to the containing GameEntity
    m_pos = initPos;
    m_dims = initDims;
    m_boundingRect = SDL_Rect(m_pos.x, m_pos.y, m_dims.w, m_dims.h);
}

TextureRect::~TextureRect() {
    SDL_DestroyTexture(m_texture);
}

SDL_Rect TextureRect::getBoundingRect() {
    return m_boundingRect;
}

SDL_Texture* TextureRect::getTexturePtr() {
    return m_texture;
}

position TextureRect::getPosition() {
    return m_pos;
}

dimensions TextureRect::getDimensions() {
    return m_dims;
}

void TextureRect::setPosition(position newPos) {
    // should only be updated by containing GameEntity
    m_pos = newPos;
    m_boundingRect.x = m_pos.x;
    m_boundingRect.y = m_pos.y;
}

void TextureRect::setDimensions(dimensions newDims) {
    m_dims = newDims;
    m_boundingRect.w = m_dims.w;
    m_boundingRect.h = m_dims.h;
}

// will be used by FBFAnim
void TextureRect::update() {

} 

void TextureRect::render(SDL_Renderer* rend) {
    SDL_RenderCopy(rend, m_texture, NULL, &m_boundingRect);
}

void TextureRect::render(SDL_Renderer* rend, position offset) {
    SDL_Rect destRect(m_boundingRect);
    destRect.x -= offset.x;
    destRect.y -= offset.y;
    SDL_RenderCopy(rend, m_texture, NULL, &destRect);
}

void TextureRect::render(SDL_Renderer* rend, position destPos, int scaleMult) {
    // avoid using scale mult that would cause decimal dimensions?
    SDL_Rect destRect;
    destRect.x = destPos.x;
    destRect.y = destPos.y;
    destRect.w = m_boundingRect.w * scaleMult;
    destRect.h = m_boundingRect.h * scaleMult;
    SDL_RenderCopy(rend, m_texture, NULL, &destRect);
}