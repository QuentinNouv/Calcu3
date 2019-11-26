//
// Created by Quentin Nouvel on 26/11/2019.
//

#ifndef CALCU3_VARIABLE_H
#define CALCU3_VARIABLE_H

#include <string>
#include <map>
#include <iostream>

template<class T>
class Variable{
private:
	Variable() = default;

	std::map<std::string, T> vars;

public:
	Variable(const Variable &) = delete;

	void operator=(const Variable &) = delete;

	static Variable &getInstance(){
		static Variable instance;
		return instance;
	}

	void writeEntry(std::string key, T value);

	std::pair<bool, T> getValue(std::string key);
};

template<class T>
void Variable<T>::writeEntry(std::string key, T value){
	vars[key] = value;
	//std::cout << key << std::string(" = ") << value << std::endl;
}

template<class T>
std::pair<bool, T> Variable<T>::getValue(std::string key){
	auto val = vars.find(key);
	bool exist = true;
	if (val == vars.end()) exist = false;
	return std::pair<bool, T>(exist, val->second);
}

#endif //CALCU3_VARIABLE_H
