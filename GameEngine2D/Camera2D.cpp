#include "Camera2D.h"

//Include all the files in 2DGameEngine namespace
namespace GameEngine2D {

	Camera2D::Camera2D() : 
		_screenWidth(500),
		_screenHeight(500),
		_updateMatrix(true),
		_scale(0.0f),
		_position(0.0f, 0.0f),
		_cameraMatrix(1.0f),
		_orthoMatrix(1.0f)
	{
	}


	Camera2D::~Camera2D()
	{
	}

	void Camera2D::init(int screenWidth, int screenHeight){
		_screenWidth = screenWidth;
		_screenHeight = screenHeight;
		_orthoMatrix = glm::ortho(0.0f, (float)_screenWidth, 0.0f, (float)_screenHeight);
	}

	void Camera2D::update(){

		if (_updateMatrix) {
			glm::vec3 translate(-_position.x, -_position.y, 0.0f);
			//Translate the camera matrix by our position
			_cameraMatrix = glm::translate(_orthoMatrix, translate);

			glm::vec3 scale(_scale, _scale, 0.0f);
			//Scale the camera matrix
			_cameraMatrix = glm::scale(_cameraMatrix, scale);

		}

	}

}