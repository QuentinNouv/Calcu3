//
// Created by Quentin on 26/11/2019.
//

#ifndef CALCU3_EXPRTOKEN_H
#define CALCU3_EXPRTOKEN_H


#include <string>
#include <cmath>
namespace  tokTypes{
    enum type {
        val,
        var,
        bOp,
        uOp,
        comma
    };

    enum opType {
        plus,
        moins,
        mult,
        div,
        assign,
        oNull
    };
    enum parenthesisType {
        lParenth,
        rParenth,
        parenthesisNull
    };
}

using namespace tokTypes;

class TokenFactory;

class ExprToken {
private:
    tokTypes::type _t;
    tokTypes::opType _oT;
    tokTypes::parenthesisType _uOT;
    std::string _var;
    double _val{};
public:
    ExprToken(type t, opType oT, parenthesisType uOt, std::string var, double val);

public:
    friend class TokenFactory;
    ExprToken() = delete;
    [[nodiscard]] type getT() const;

    [[nodiscard]] opType getOT() const;

    [[nodiscard]] const std::string &getVar() const;

    [[nodiscard]] double getVal() const;
};

class TokenFactory{
public:
    static ExprToken getVarToken(std::string &v);
    static ExprToken getOpToken(opType o);
    static ExprToken getParenthesisToken(parenthesisType parenthesis);
    static ExprToken getValToken(double v);
    static ExprToken getCommaToken();
};


#endif //CALCU3_EXPRTOKEN_H
