#pragma once

#include <string>
#include <GameEngine2D/SpriteBatch.h>
#include <GameEngine2D/ResourceManager.h>

const float MAP_DIMENSION = 50;
const float ENTITY_DIMENSION = 64;
const float TILE_DIMENSION = 64;
const float BULLET_DIMENSION = 16;

typedef enum TileType {
	ROAD,
	EARTH,
	GRASS
}tileType;

class Tile
{
public:
	Tile(glm::vec2 position, TileType tile);
	~Tile();

	void draw(GameEngine2D::SpriteBatch& spriteBatch);
	bool isCollidable() const { return _isCollidable; }
	const glm::vec2& getPosition() { return _position; }

private:
	glm::vec2 _position;
	tileType _tile;
	bool _isCollidable;
};

