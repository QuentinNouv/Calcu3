
//
// Created by Quentin Nouvel on 26/11/2019.
//

#ifndef CALCU3_PROGRAM_H
#define CALCU3_PROGRAM_H

#include <map>
#include <vector>
#include <string>
#include "error/Error.h"

class Program{
private:
	static void printError(Error &err, std::string &instruction);

public:
	Program() = delete;

	static void run();
};


#endif //CALCU3_PROGRAM_H
