/*
 * line_comment.cpp
 *
 *  Created on: Oct 16, 2014
 *      Author: nbingham
 */

#include "line_comment.h"

namespace parse
{
line_comment::line_comment()
{
}

line_comment::~line_comment()
{

}

token line_comment::consume(tokenizer &tokens)
{
	token result;
	result.type = tokens.comment_type<line_comment>();
	result.start = tokens.offset+1;

	tokens.next_char();
	tokens.next_char();

	char character;

	do
	{
		character = tokens.next_char();
	} while (character != '\0' && character != '\n');

	result.end = tokens.offset;
	return result;
}

bool line_comment::is_next(configuration &config, tokenizer &tokens, int i)
{
	return (tokens.peek_char(i) == '/' && tokens.peek_char(i+1) == '/');
}
}
