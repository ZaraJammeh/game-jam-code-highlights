#include "Tilemap.hpp"

#include <iostream>

Tilemap::Tilemap(Tileset* source, std::string filepath, position initPos, int rowSize) {
	// initialise member variables
	m_source = source;
	m_pos = initPos;
	m_rowSize = rowSize;

	// parse map file into 2D vector
	int tileCode;
	int i = 0;
	int j = 0;
	bool mapEnd = false;
	std::ifstream mapStream(filepath);
	while (!mapEnd) {
		mapStream >> tileCode;
		if (mapStream.fail()) {
			mapEnd = true;
			break;
		}
		else {
			// place tile code in 2D vector
			if (i == 0) {
				// start new row
				m_map.push_back({});
			}
			m_map[j].push_back(tileCode);
			i++;
			if (i >= m_rowSize) {
				i = 0;
				j++;
			}
		}
	}
	mapStream.close();
}

position Tilemap::getPosition() {
	return m_pos;
}

void Tilemap::setPosition(position newPos) {
	m_pos = newPos;
}

void Tilemap::render(SDL_Renderer* rend) {
	// standard render function
	int tileSize = m_source->getTileSize();
	SDL_Rect tileDestRect(m_pos.x, m_pos.y, tileSize, tileSize);

	// render each tile in map
	int tileCode;
	int i, j;
	for (j = 0; j < m_map.size(); j++) {
		tileDestRect.y = tileSize * j + m_pos.y;
		for (i = 0; i < m_map[j].size(); i++) {
			tileDestRect.x = tileSize * i + m_pos.x;
			tileCode = m_map[j][i];
			if (tileCode > -1) {
				// skip blank tiles when rendering
				m_source->renderTile(rend, tileCode, tileDestRect);
			}
		}
	}
}

void Tilemap::render(SDL_Renderer* rend, position offset) {
	int tileSize = m_source->getTileSize();
	// calculate effective position from offset and m_pos
	position effPos;
	effPos.x = m_pos.x - offset.x;
	effPos.y = m_pos.y - offset.y;
	SDL_Rect tileDestRect(effPos.x, effPos.y, tileSize, tileSize);
	// render each tile in the map, accounting for positional offset
	int tileCode;
	int i, j;
	for (j = 0; j < m_map.size(); j++) {
		tileDestRect.y = tileSize * j + effPos.y;
		for (i = 0; i < m_map[j].size(); i++) {
			tileDestRect.x = tileSize * i + effPos.x;
			tileCode = m_map[j][i];
			if (tileCode > -1) {
				// skip blank tiles when rendering
				m_source->renderTile(rend, tileCode, tileDestRect);
			}
		}
	}
}

void Tilemap::render(SDL_Renderer* rend, position destPos, int scaledTileSize) {
	// render using custom parameters, rather than object's own variables
	SDL_Rect tileDestRect(destPos.x, destPos.y, scaledTileSize, scaledTileSize);

	// render each tile in the map, accounting for positional offset
	int tileCode;
	int i, j;
	for (j = 0; j < m_map.size(); j++) {
		tileDestRect.y = scaledTileSize * j + destPos.y;
		for (i = 0; i < m_map[j].size(); i++) {
			tileDestRect.x = scaledTileSize * i + destPos.x;
			tileCode = m_map[j][i];
			if (tileCode > -1) {
				// skip blank tiles when rendering
				m_source->renderTile(rend, tileCode, tileDestRect);
			}
		}
	}
}