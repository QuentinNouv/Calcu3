//
// Created by Quentin on 27/11/2019.
//

#include <stdexcept>
#include "Lexer.h"

Lexer::Lexer(std::string &instruction): s(waitingExpr), instruction(instruction){}

std::vector<ExprToken> Lexer::lex() {
    for (i = 0 ; i < instruction.size() ; ++i)
        switch (s){
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
    if (s != waitingExpr) addAndClear();
    return std::vector<ExprToken>();
}

void Lexer::waitingExprAction() {
    if (!handleSeparators())
        switch (instruction[i]){
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
                throw std::logic_error("impossible state");//TODO handle error
        }
}

void Lexer::litteralAction() {
    if (!handleSeparators())
        switch (instruction[i]){
            case 'a' ... 'z':
            case 'A' ... 'Z':
            case '0' ... '9':
            case '_':
                buffer.push_back(instruction[i]);
                break;
            default:
                throw std::logic_error("impossible state");//TODO handle error
        }
}

void Lexer::numeralAction() {
    if (!handleSeparators())
        switch (instruction[1]){
            case '0' ... '9':
                buffer.push_back(instruction[i]);
                break;
            case '.':
                buffer.push_back(instruction[i]);
                s = mantisse;
                break;
            default:
                throw std::logic_error("impossible state");//TODO handle error
        }
}

void Lexer::mantisseAction() {
    if (!handleSeparators())
        switch (instruction[i]){
            case '0' ... '9':
                buffer.push_back(instruction[i]);
                break;
            default:
                throw std::logic_error("impossible state");//TODO handle error
        }
}

void Lexer::addAndClear() {
    if (s == litteral) {
        tokens.push_back(TokenFactory::getVarToken(buffer));
    } else if ( s == mantisse || s == numeral){
        tokens.push_back(TokenFactory::getValToken(std::stod(buffer)));
    } else {
        throw std::invalid_argument("Can't add & clear in waitingExpr state.");
    }
    buffer.clear();
    s = waitingExpr;
}

bool Lexer::handleSeparators() {
    bool used = true;
    switch (instruction[i]){
        case ' ':
            if (s != waitingExpr) addAndClear();
            break;
        case '(':
            if (s != waitingExpr) addAndClear();
            tokens.push_back(TokenFactory::getParenthesisToken(tokTypes::lParenth));
            break;
        case ')':
            if (s != waitingExpr) addAndClear();
            tokens.push_back(TokenFactory::getParenthesisToken(tokTypes::rParenth));
            break;
        case ',':
            if (s != waitingExpr) addAndClear();
            tokens.push_back(TokenFactory::getCommaToken());
            break;
        case '+':
            if (s != waitingExpr) addAndClear();
            tokens.push_back(TokenFactory::getOpToken(tokTypes::plus));
            break;
        case '-':
            if (s != waitingExpr) addAndClear();
            tokens.push_back(TokenFactory::getOpToken(tokTypes::moins));
            break;
        case '*':
            if (s != waitingExpr) addAndClear();
            tokens.push_back(TokenFactory::getOpToken(tokTypes::mult));
            break;
        case '/':
            if (s != waitingExpr) addAndClear();
            tokens.push_back(TokenFactory::getOpToken(tokTypes::div));
            break;
        default:
            used = false;
    }
    return used;
}
