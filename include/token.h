/*
 * Declaration of the Token
 *
 * Authors:
 * Rahul Ganesh Prabhu (2018A7PS0193P)
 * Shreyas Kera (2018A7PS1119P)
 * Achyut Anand Tadepalli (2018A7PS1118P)
 * Raghurama Varma Gonela (2018A7PS1120P)
 */

#include <string.h>

#ifndef TOKEN_H
#define TOKEN_H

/*
 * Enum defining all the terminals (token classes)
 */
enum Token {
  TOKEN_PROGRAM,
  TOKEN_PAR,
  TOKEN_CURLY_OPEN,
  TOKEN_CURLY_CLOSE,
  TOKEN_DECLARE,
  TOKEN_COLON,
  TOKEN_SEMICOLON,
  TOKEN_INTEGER,
  TOKEN_REAL,
  TOKEN_BOOL,
  TOKEN_LIST,
  TOKEN_OF,
  TOKEN_VARIABLES,
  TOKEN_RECT_OPEN,
  TOKEN_RECT_CLOSE,
  TOKEN_DOUBLE_PERIOD,
  TOKEN_JAGGED,
  TOKEN_ARRAY,
  TOKEN_EQUAL_SIGN,
  TOKEN_PLUS,
  TOKEN_MINUS,
  TOKEN_DIVIDE,
  TOKEN_MULTIPLY,
  TOKEN_AND,
  TOKEN_OR,
  TOKEN_VAR_ID,
  TOKEN_INTEGER_LITERAL,
  TOKEN_SIZE,
  TOKEN_VALUES,
  TOKEN_R1,
  TOKEN_NONE
};

/*
 * Categorizes a given lexeme into its token class.
 *
 * lexeme : The given lexeme
 */
enum Token lexemeType(char* lexeme);

/*
 * Array that maps token types to their grammar symbol (terminals)
 */
extern const char* tokenToSymbolMap[31];

#endif
