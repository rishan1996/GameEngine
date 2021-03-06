#include "Tile.h"

Tile::Tile(glm::vec2 position, TileType tile) : _isCollidable(false), _position(position), _tile(tile){
}


Tile::~Tile()
{
}



void Tile::draw(GameEngine2D::SpriteBatch & spriteBatch){
	glm::vec4 posAndSize(_position, ENTITY_DIMENSION, ENTITY_DIMENSION);

	glm::vec4 uv(0.0f, 0.0f, 1.0f, 1.0f);

	GLuint textureID;

	switch (_tile) {
		case EARTH:
			textureID = GameEngine2D::ResourceManager::getTexture("Textures/Tiles/Earth.png").id;
			_isCollidable = false;
			break;
		case ROAD:
			textureID = GameEngine2D::ResourceManager::getTexture("Textures/Tiles/Road.png").id;
			_isCollidable = true;
			break;
		case GRASS:
			textureID = GameEngine2D::ResourceManager::getTexture("Textures/Tiles/Grass.png").id;
			_isCollidable = true;
			break;
	}

	GameEngine2D::ColourRGBA8 colour(255, 255, 255, 255);

	spriteBatch.draw(posAndSize, uv, textureID, 0.0f, colour);
}
