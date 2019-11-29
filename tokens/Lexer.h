//
// Created by Quentin on 27/11/2019.
//

#ifndef CALCU3_LEXER_H
#define CALCU3_LEXER_H


#include <string>
#include <vector>
#include "ExprToken.h"
#include "../error/Error.h"

class Lexer{
private:
	enum state{
		waitingExpr,
		litteral,
		numeral,
		mantisse
	};

	void waitingExprAction();

	void litteralAction();

	void numeralAction();

	void mantisseAction();

	void addAndClear();

	bool handleSeparators();

	void lexicalError();

	state s;
	std::string buffer;
	std::string instruction;
	std::vector<ExprToken> tokens;
	unsigned i{};
	unsigned start;
	bool error = false;
	std::unique_ptr<Error> err;
public:
	explicit Lexer(std::string &instruction);

	std::vector<ExprToken> lex();

	bool isWrong();

	[[nodiscard]] Error &getError();
};


#endif //CALCU3_LEXER_H
