//
// Created by Quentin Nouvel on 28/11/2019.
//

#ifndef CALCU3_ERROR_H
#define CALCU3_ERROR_H


#include <string>

class Error{
private:
	std::string _message;
	int _position;
public:
	Error(std::string &message, int position);

	Error(std::string message, int position);

	[[nodiscard]] const std::string &getMessage() const;

	[[nodiscard]] int getPosition() const;

};


#endif //CALCU3_ERROR_H
