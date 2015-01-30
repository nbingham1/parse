/*
 * symbol.h
 *
 *  Created on: Oct 16, 2014
 *      Author: nbingham
 */

#include "../parse.h"

#ifndef symbol_h
#define symbol_h

namespace parse
{
struct symbol
{
	symbol();
	~symbol();

	string debug_name;

	static token consume(tokenizer &tokens);
	static bool is_next(configuration &config, tokenizer &tokens, int i = 1);
};
}

#endif