/*
 * Declaration of Type Expression Table
 *
 * Authors:
 * Rahul Ganesh Prabhu (2018A7PS0193P)
 * Shreyas Kera (2018A7PS1119P)
 * Achyut Anand Tadepalli (2018A7PS1118P)
 * Raghurama Varma Gonela (2018A7PS0193P)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type_expression.h"

#ifndef TYPE_EXPRESSIONTABLE_H
#define TYPE_EXPRESSIONTABLE_H

/*
 * Struct for a single record in a type expression
 *
 * var_name : The variable name
 * arrayType : The type of array of the variable
 * rectType : The type of rectangular array
 * type_expression : The type expression of the variable
 */
typedef struct{
  char* var_name;
  enum VarClass arrayType;
  enum RectStatus rectType;
  TypeExpression type_expression;
} TypeExpressionRecord;

/*
 * Struct for the type expression table
 *
 * T : The array of type expression records, one for each variable
 * size : The size of the array
 * capacity : The capacity of the array
 */
typedef struct {
  TypeExpressionRecord* T;
  size_t size;
  size_t capacity;
} TypeExpressionTable;

/*
 * Print the type expression table
 */
void printTypeExpressionTable(TypeExpressionTable Te);

/*
 * Get the type expression table for a particular variable
 *
 * E : The type expression table
 * var_name : The variable name
 */
TypeExpressionRecord getTypeExpressionRecord(TypeExpressionTable* E, char* var_name);

#endif
