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

opType ExprToken::getOT() const{
	return _oT;
}

type ExprToken::getT() const{
	return _t;
}

parenthesisType ExprToken::getUOT(){
	return _uOT;
}

ExprToken::ExprToken(type t, opType oT, parenthesisType uOt, std::string var, double val, unsigned start, unsigned end)
		: _t(t), _oT(oT), _uOT(uOt), position{start, end}, _var(std::move(var)), _val(val){
}

const unsigned int *ExprToken::getPosition() const{
	return position;
}

ExprToken TokenFactory::getVarToken(std::string &v, unsigned start, unsigned end){
	return ExprToken(tokTypes::type::var, tokTypes::opType::oNull, tokTypes::parenthesisType::parenthesisNull, v, NAN,
					 start, end);
}

ExprToken TokenFactory::getOpToken(opType o, unsigned start, unsigned end){
	return ExprToken(tokTypes::type::bOp, o, tokTypes::parenthesisType::parenthesisNull, emptyStr, NAN, start, end);;
}

ExprToken TokenFactory::getParenthesisToken(parenthesisType parenthesis, unsigned start, unsigned end){
	return ExprToken(tokTypes::type::uOp, tokTypes::opType::oNull, parenthesis, emptyStr, NAN, start, end);;
}

ExprToken TokenFactory::getValToken(double v, unsigned start, unsigned end){
	return ExprToken(tokTypes::type::val, tokTypes::opType::oNull, tokTypes::parenthesisType::parenthesisNull, emptyStr,
					 v, start, end);;
}

ExprToken TokenFactory::getCommaToken(unsigned start, unsigned end){
	return ExprToken(tokTypes::type::comma, tokTypes::opType::oNull, tokTypes::parenthesisType::parenthesisNull,
					 emptyStr, NAN, start, end);;
}
