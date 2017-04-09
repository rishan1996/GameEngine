#include "UniformLocationCache.h"
#include <iostream>



UniformLocationCache::UniformLocationCache()
{
}


UniformLocationCache::~UniformLocationCache()
{
}

GLuint UniformLocationCache::getUniformLocation(std::string locationOf, GLSLProgram* currentProgram) {
	//Search the map using binary search for the key with the same name
	auto locationIterator = _uniformLocationCache.find(locationOf);

	//Check if location was not in the map
	if (locationIterator == _uniformLocationCache.end()) {
		//If no location then load it in
		GLuint tempLocation = currentProgram->getUniformLocation(locationOf);

		//Insert the location into the map
		_uniformLocationCache.emplace(locationOf, tempLocation);

		std::cout << "Loaded location into cache\n";

		//Return the texture
		return tempLocation;
	}

	//Location is contained in the map
	return locationIterator->second; //Iterator contains a pair, return the value
}