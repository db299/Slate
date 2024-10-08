#pragma once

#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include "objects/Object.h"
#include "SlateDefinitions.h"
#include "ParseState.h"

struct ExpressionInfo {
	std::string& line;
	size_t index;
	ExpressionInfo(std::string& line, size_t index) : line(line) {
		this->index = index;
	}
};

class SlateContext {

private:

	std::vector<std::string*> expresions;

public:

	SlateContext();

	std::unordered_map<std::string, Object*> nameMap;

	ExpressionInfo newExpression();
	void processSyntax();
	ParseError lexer(std::string& line, std::vector<Token>& tokens);
	ParseError parser(std::vector<Token>& tokens);

	/**
	 * Function to perform shunting yard on a token of vectors.
	*/
	std::vector<Token> SlateContext::shuntingYard(std::vector<Token>& tokens);
	ParseError processSyntaxLine(std::string& line);
	void removeExpresion(size_t index);

	int precedence(Token token);
	bool isOperator(Token token);
	bool rightAssociative(Token token);
	bool isOperand(Token token);
	bool isOpenBracket(Token token);
	bool isClosedBracket(Token token);

	void brk();

};