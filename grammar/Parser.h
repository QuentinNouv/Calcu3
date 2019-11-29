//
// Created by Quentin Nouvel on 28/11/2019.
//

#ifndef CALCU3_PARSER_H
#define CALCU3_PARSER_H


#include <vector>
#include "../tokens/ExprToken.h"
#include "../error/Error.h"

class Parser{
private:
	std::vector<ExprToken> tokens;
	bool error;
	std::unique_ptr<Error> err;

public:
	[[nodiscard]] bool isWrong() const;

	[[nodiscard]] Error &getErr() const;
};


#endif //CALCU3_PARSER_H
