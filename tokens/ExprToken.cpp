//
// Created by Quentin on 26/11/2019.
//

#include "ExprToken.h"

#include <utility>

static std::string emptyStr = std::string();

double ExprToken::getVal() const {
    return _val;
}

const std::string &ExprToken::getVar() const {
    return _var;
}

opType ExprToken::getOT() const {
    return _oT;
}

type ExprToken::getT() const {
    return _t;
}

ExprToken::ExprToken(type t, opType oT, parenthesisType uOt, std::string var, double val)
    : _t(t), _oT(oT), _uOT(uOt),_var(std::move(var)), _val(val) {}

ExprToken TokenFactory::getVarToken(std::string &v) {
    return ExprToken(tokTypes::type::var, tokTypes::opType::oNull, tokTypes::parenthesisType::parenthesisNull, v, NAN);
}

ExprToken TokenFactory::getOpToken(opType o) {
    return ExprToken(tokTypes::type::bOp, o, tokTypes::parenthesisType::parenthesisNull, emptyStr, NAN);;
}

ExprToken TokenFactory::getParenthesisToken(parenthesisType parenthesis) {
    return ExprToken(tokTypes::type::uOp, tokTypes::opType::oNull, parenthesis, emptyStr, NAN);;
}

ExprToken TokenFactory::getValToken(double v) {
    return ExprToken(tokTypes::type::val, tokTypes::opType::oNull, tokTypes::parenthesisType::parenthesisNull, emptyStr, v);;
}

ExprToken TokenFactory::getCommaToken() {
    return ExprToken(tokTypes::type::comma, tokTypes::opType::oNull, tokTypes::parenthesisType::parenthesisNull, emptyStr, NAN);;
}
