/*
 * Declaration of a Parse Tree
 *
 * Authors:
 * Rahul Ganesh Prabhu (2018A7PS0193P)
 * Shreyas Kera (2018A7PS1119P)
 * Achyut Anand Tadepalli (2018A7PS1118P)
 * Raghurama Varma Gonela (2018A7PS1120P)
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "token.h"
#include "token_stream.h"
#include "grammar.h"
#include "type_expression.h"
#include "type_expression_table.h"

#ifndef PARSE_TREE_H
#define PARSE_TREE_H

typedef struct ParseTreeNode ParseTreeNode;


/*
 * Struct for a single node of the parse tree
 *
 * left_child : The left child of the parse tree node
 * right_sibling : The right sibling of the parse tree node
 * is_leaf : Denotes whether the node is a leaf
 * depth : The depth of the node
 * lexeme : The lexeme in the node
 * line_number : The line number of the line being parsed
 * type_expression : The type expression of the node
 * type_expression_exists : Denotes whether the node has a type expression
 * grammar_rule : The grammar rule used
 * symbol : The symbol contained in the node
 */
struct ParseTreeNode{
  ParseTreeNode* left_child;
  ParseTreeNode* right_sibling;
  int is_leaf;
  size_t depth;
  char* lexeme;
  size_t line_number;
  TypeExpression type_expression;
  int type_expression_exists;
  SymbolNode* grammar_rule;
  char* symbol;
};

/*
 * Struct containing the entire parse tree
 *
 * root : The root of the parse tree
 */
typedef struct{
  ParseTreeNode* root;
} ParseTree;

/*
 * Builds the parse tree given the token stream and grammar
 *
 * t: The Parse Tree to be populated
 * s : The Token Stream
 * G : Our Grammar
 */
void createParseTree(ParseTree* t, TokenStream* s, Grammar* G);

/*
 * Prints the given parse tree
 *
 * t : The Parse Tree
 */
void printParseTree(ParseTree* t);

/*
 * Traverses the parse tree and populates the type expression table
 *
 * t : The Parse Tree
 * E : The Type Expression Table to Populate
 */
void traverseParseTree(ParseTree* t, TypeExpressionTable* E);

/*
 * Free the memory from the parse tree preventing memory leaks
 *
 * t : The Parse Tree
 */
void freeParseTree(ParseTree* t);

/*
 * Denotes whether or not to print type error output
 */
extern int error_output;

#endif
