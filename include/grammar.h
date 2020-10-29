/*
 * Declaration of the Grammar
 *
 * Authors:
 * Rahul Ganesh Prabhu (2018A7PS0193P)
 * Shreyas Kera (2018A7PS1119P)
 * Achyut Anand Tadepalli (2018A7PS1118P)
 * Raghurama Varma Gonela (2018A7PS1120P)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef GRAMMAR_H
#define GRAMMAR_H

typedef struct SymbolNode SymbolNode;

/*
 * A node in the linked list
 *
 * symbol : A string containing our variable
 * symbol_size: The size of symbol
 * is_terminal : Denotes if it is a terminal or not
 * next : The next node in the linked list
 */
struct SymbolNode {
  char* symbol;
  size_t symbol_size;
  int is_terminal;
  SymbolNode* next;
};

/*
 * The grammar, represented by an array of linked lists
 *
 * grammar_lhs : The array of linked lists
 * rule_count : The number of linked lists in our array
 */
typedef struct {
  SymbolNode** grammar_lhs;
  size_t rule_count;
} Grammar;

/* 
 * Reads the grammar from the given file and populates the grammar
 *
 * file_name: The grammar file
 * G: THe grammar to populate
 */
void readGrammar(char* file_name, Grammar* G);

/*
 * Prints a rule
 *
 * head: The grammar rule
 */
void printRule(SymbolNode* head);

#endif
