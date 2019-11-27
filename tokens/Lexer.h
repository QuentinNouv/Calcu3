//
// Created by Quentin on 27/11/2019.
//

#ifndef CALCU3_LEXER_H
#define CALCU3_LEXER_H


#include <string>
#include <vector>
#include "ExprToken.h"

class Lexer {
private:
    enum state {
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

    state s;
    std::string buffer;
    std::string instruction;
    std::vector<ExprToken> tokens;
    unsigned int i{};
public:
    explicit Lexer(std::string &instruction);
    std::vector<ExprToken> lex();
};


#endif //CALCU3_LEXER_H
