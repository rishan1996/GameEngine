#include "Sprite.h"
#include "Vertex.h"
#include "ImageLoader.h"
#include "ResourceManager.h"

#include <cstddef>

Sprite::Sprite() : _vboID(0), _x(0), _y(0), _width(0), _height(0)
{
}


Sprite::~Sprite()
{
	//If _vboID isn't 0 delete the buffer object
	if(_vboID)
		glDeleteBuffers(1, &_vboID);
}

void Sprite::initialize(float x, float y, float width, float height, std::string texturePath){
	_x = x;
	_y = y;
	_width = width;
	_height = height;

	

	//Load the texture
	_texture = ResourceManager::getTexture(texturePath);

	//If vertex buffer object hasnt been generated
	if (_vboID == 0){
		//Generate buffer and assign it to an id
		glGenBuffers(1, &_vboID);
	}

	Vertex vertexData[6];

	//Set vertex position and colour data 
	for(int i = 0; i < 6; i++){
		//Set the position
		vertexData[i].position.x = x;
		if(i == 0 || i == 4 || i == 5 )
			vertexData[i].position.x += width;

		vertexData[i].position.y = y;
		if(i == 0|| i == 1 || i == 5)
			vertexData[i].position.y += height;	

		//Set the color
		vertexData[i].setColour(255, 255, 255, 255);

		//Set the UV data
		if(i == 0 || i == 5)
			vertexData[i].setUV(1.0f/3.0f, 1.0f);

		else if(i == 2 || i == 3)
			vertexData[i].setUV(0.0f, 2.0f/3.0f);

		else if(i == 1)
			vertexData[i].setUV(0.0f, 1.0f);

		else
			vertexData[i].setUV(1.0f/3.0f, 2.0f/3.0f);


	}

	//vertexData[1].setColour(0, 0, 255, 255);
	//vertexData[4].setColour(255, 0, 0, 255);

	//Bind the buffer object
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	//Upload the buffer
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertexData), vertexData, GL_STATIC_DRAW);

	//Unbind the buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}


void Sprite::draw(){

	//Bind the texture
	glBindTexture(GL_TEXTURE_2D, _texture.id);

	//Bind the buffer object
	glBindBuffer(GL_ARRAY_BUFFER, _vboID);

	//Enable use of one vertex array
	glEnableVertexAttribArray(0);

	//Position attribute pointer
	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, position));

	//Colour attribute pointer
	glVertexAttribPointer(1, 4, GL_UNSIGNED_BYTE, GL_TRUE, sizeof(Vertex), (void*)offsetof(Vertex, colour));

	//UV attribute pointer
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)offsetof(Vertex, uv));

	//Draws array of verticies
	glDrawArrays(GL_TRIANGLES, 0, 6);

	//Disable use of vertex array
	glDisableVertexAttribArray(0);

	//Unbind the buffer
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}