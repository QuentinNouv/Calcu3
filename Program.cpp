//
// Created by Quentin Nouvel on 26/11/2019.
//
#include <iostream>
#include "Program.h"

std::vector<std::string> split(std::string input, const std::string &delimiter = ";"){
	std::vector<std::string> r;
	size_t pos = 0;
	std::string token;
	while ((pos = input.find(delimiter)) != std::string::npos) {
		token = input.substr(0, pos) + ";";
		r.push_back(token);
		input.erase(0, pos + delimiter.length());
	}
	r.push_back(input);
	return r;
}

void Program::run(){
	std::string input;
	std::cout << "Entrez une expression :" << std::endl;
	while (true) {
		bool lastShow;
		std::getline(std::cin, input);
		if (input == "exit") return;
		auto vec = split(input);
		int nb = (int) vec.size() - 1;
		for (int i = 0; i <= nb; ++i) {
			lastShow = true;
			std::string e = vec[i];
			if (e.length() != 0) {
				if (e.back() == ';') {
					lastShow = false;
					e.pop_back();
				}
				std::cout << "<" << e << ">" << lastShow << std::endl;
				//TODO trait e
			}
		}
	}
}
