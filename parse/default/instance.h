/*
 * instance.h
 *
 *  Created on: Oct 16, 2014
 *      Author: nbingham
 */

#include "../parse.h"

#ifndef instance_h
#define instance_h

namespace parse
{
struct instance
{
	instance();
	~instance();

	string debug_name;

	static token consume(tokenizer &tokens);
	static bool is_next(configuration &config, tokenizer &tokens, int i = 1);
};
}

#endif