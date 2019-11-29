//
// Created by Quentin Nouvel on 28/11/2019.
//

#include "Parser.h"

bool Parser::isWrong() const{
	return error;
}

Error &Parser::getErr() const{
	return *err;
}
