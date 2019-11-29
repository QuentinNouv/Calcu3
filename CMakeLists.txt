cmake_minimum_required(VERSION 3.15)
project(Calcu3)

set(CMAKE_CXX_STANDARD 17)
set( CMAKE_CXX_FLAGS "-Wall -Wextra -Werror" )

add_executable(Calcu3 main.cpp variables/Variable.h Program.h Program.cpp tokens/ExprToken.cpp tokens/ExprToken.h tokens/Lexer.cpp tokens/Lexer.h error/Error.cpp error/Error.h grammar/Parser.cpp grammar/Parser.h)