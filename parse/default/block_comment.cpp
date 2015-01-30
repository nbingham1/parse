/*
 * block_comment.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: nbingham
 */

#include "block_comment.h"

namespace parse
{
block_comment::block_comment()
{
}

block_comment::~block_comment()
{

}

token block_comment::consume(tokenizer &tokens)
{
	token result;
	result.type = tokens.comment_type<block_comment>();
	result.start = tokens.offset+1;

	tokens.next();
	tokens.next();

	bool star = false;
	bool done = false;
	char character;

	while (!done)
	{
		character = tokens.next_char();

		if (character == '\0')
		{
			error(tokens, "expected '*/'", "", __FILE__, __LINE__);
			result.end = tokens.offset;
			return result;
		}
		else if (character == '*')
			star = true;
		else if (star && character == '/')
			done = true;
		else
			star = false;
	}

	result.end = tokens.offset;
	return result;
}

bool block_comment::is_next(configuration &config, tokenizer &tokens, int i)
{
	return (tokens.peek_char(i) == '/' && tokens.peek_char(i+1) == '*');
}
}
