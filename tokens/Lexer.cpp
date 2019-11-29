//
// Created by Quentin on 27/11/2019.
//

#include <stdexcept>
#include "Lexer.h"
#include "../error/Error.h"

Lexer::Lexer(std::string &instruction): s(waitingExpr), instruction(instruction){}

std::vector<ExprToken> Lexer::lex(){
	for (i = 0; i < instruction.size(); ++i) {
		if (error) return tokens;
		switch (s) {
			case waitingExpr:
				waitingExprAction();
				break;
			case litteral:
				litteralAction();
				break;
			case numeral:
				numeralAction();
				break;
			case mantisse:
				mantisseAction();
				break;
		}
	}
	if (s != waitingExpr) addAndClear();
	return tokens;
}

void Lexer::waitingExprAction(){
	if (!handleSeparators()) {
		start = i;
		switch (instruction[i]) {
			case 'a' ... 'z':
			case 'A' ... 'Z':
			case '_':
				buffer.push_back(instruction[i]);
				s = litteral;
				break;
			case '0' ... '9':
				buffer.push_back(instruction[i]);
				s = numeral;
				break;
			case '.':
				buffer.push_back(instruction[i]);
				s = mantisse;
				break;
			default:
				lexicalError();
		}
	}
}

void Lexer::litteralAction() {
	if (!handleSeparators())
		switch (instruction[i]) {
			case 'a' ... 'z':
			case 'A' ... 'Z':
			case '0' ... '9':
			case '_':
				buffer.push_back(instruction[i]);
				break;
			default:
				lexicalError();
		}
}

void Lexer::numeralAction() {
	if (!handleSeparators())
		switch (instruction[1]) {
			case '0' ... '9':
				buffer.push_back(instruction[i]);
				break;
			case '.':
				buffer.push_back(instruction[i]);
				s = mantisse;
				break;
			default:
				lexicalError();
		}
}

void Lexer::mantisseAction() {
    if (!handleSeparators())
        switch (instruction[i]){
            case '0' ... '9':
                buffer.push_back(instruction[i]);
                break;
			default:
				lexicalError();
        }
}

void Lexer::addAndClear() {
    if (s == litteral) {
		tokens.push_back(TokenFactory::getVarToken(buffer, start, i));
	} else if ( s == mantisse || s == numeral) {
		tokens.push_back(TokenFactory::getValToken(std::stod(buffer), start, i));
	} else {
        throw std::invalid_argument("Can't add & clear in waitingExpr state.");
    }
    buffer.clear();
    s = waitingExpr;
}

bool Lexer::handleSeparators() {
    bool used = true;
    switch (instruction[i]) {
		case ' ':
			if (s != waitingExpr) addAndClear();
			break;
		case '(':
			if (s != waitingExpr) addAndClear();
			tokens.push_back(TokenFactory::getParenthesisToken(tokTypes::lParenth, i, i));
			break;
		case ')':
			if (s != waitingExpr) addAndClear();
			tokens.push_back(TokenFactory::getParenthesisToken(tokTypes::rParenth, i, i));
			break;
		case ',':
			if (s != waitingExpr) addAndClear();
			tokens.push_back(TokenFactory::getCommaToken(i, i));
			break;
		case '+':
			if (s != waitingExpr) addAndClear();
			tokens.push_back(TokenFactory::getOpToken(tokTypes::plus, i, i));
			break;
		case '-':
			if (s != waitingExpr) addAndClear();
			tokens.push_back(TokenFactory::getOpToken(tokTypes::moins, i, i));
			break;
		case '*':
			if (s != waitingExpr) addAndClear();
			tokens.push_back(TokenFactory::getOpToken(tokTypes::mult, i, i));
			break;
		case '/':
			if (s != waitingExpr) addAndClear();
			tokens.push_back(TokenFactory::getOpToken(tokTypes::div, i, i));
			break;
		default:
			used = false;
	}
	return used;
}

void Lexer::lexicalError(){
	error = true;
	err = std::make_unique<Error>(Error("Lexical error", (int) i));
}

bool Lexer::isWrong(){
	return error;
}

Error &Lexer::getError(){
	return *err;
}
