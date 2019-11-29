//
// Created by Quentin Nouvel on 28/11/2019.
//

#include "Error.h"

#include <utility>

Error::Error(std::string &message, int position) : _message(std::move(message)), _position(position){
}

Error::Error(std::string message, int position) : _message(std::move(message)), _position(position){
}

const std::string &Error::getMessage() const{
	return _message;
}

int Error::getPosition() const{
	return _position;
}
