/*
 * symbol.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: nbingham
 */

#include "symbol.h"

namespace parse
{
symbol::symbol()
{
	debug_name = "symbol";
}

symbol::~symbol()
{

}

token symbol::consume(tokenizer &tokens)
{
	token result;
	result.type = tokens.token_type<symbol>();
	result.start = tokens.offset+1;

	string one(1, tokens.next_char());
	string two = one + string(1, tokens.peek_char(1));
	string three = two + string(1, tokens.peek_char(2));
	string total = one;

	if (three == ">>=" || three == "<<=")
	{
		total += tokens.next_char();
		total += tokens.next_char();
	}
	else if (two == ":=" || two == "->" || two == "==" || two == "~=" ||
		two == "<=" || two == ">=" || two == "&&" || two == "||" ||
		two == "**" || two == ">>" || two == "<<" || two == "[]" ||
		two == ".." || two == "*[" || two == "!=" || two == "::" ||
		two == "+=" || two == "-=" || two == "*=" || two == "/=" ||
		two == "&=" || two == "|=" || two == "^=" || two == "++" ||
		two == "--" || two == "%=")
	{
		total += tokens.next_char();
	}

	result.end = tokens.offset+1;
	return result;
}

bool symbol::is_next(configuration &config, tokenizer &tokens, int i)
{
	char character = tokens.peek_char(i);

	return (character == '~' || character == '!' || character == '@' || character == '#' ||
			 character == '$' || character == '%' || character == '^' || character == '&' ||
			 character == '*' || character == '(' || character == ')' || character == '-' ||
			 character == '=' || character == '+' || character == '[' || character == '{' ||
			 character == ']' || character == '}' || character == '\\' || character == '|' ||
			 character == ';' || character == ':' || character == ',' || character == '<' ||
			 character == '.' || character == '>' || character == '/' || character == '?');
}

}