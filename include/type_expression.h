/*
 * Declaration of a Type Expression
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

#ifndef TYPE_EXPRESSION_H
#define TYPE_EXPRESSION_H

/*
 * Enum defining whether it is primitive, rectangular array or jagged array
 */
enum VarClass {
  VARCLASS_PRIMITIVE,
  VARCLASS_RECTANGULAR,
  VARCLASS_JAGGED
};

/* 
 * Enum denoting the type of rectangular array
 */
enum RectStatus{
  RECTSTATUS_STATIC,
  RECTSTATUS_DYNAMIC,
  RECTSTATUS_NOT_APPLICABLE
};

/*
 * Enum denoting the type of the rectangular array
 */
enum Type{
  TYPE_INTEGER,
  TYPE_REAL,
  TYPE_BOOLEAN,
  TYPE_JAGGED_ARRAY,
  TYPE_RECTANGULAR_ARRAY
};

/*
 * Arrays mapping from enums ot their string representation
 */
static char* var_class_map[] = {"primitive", "rectangular", "jagged"};
static char* rect_status_map[] = {"static", "dynamic", "not_applicable"};
static char* type_map[] = {"integer", "real", "Boolean", "jaggedArray", "rectangularArray"};

/*
 * Struct containing all the sizes of the jagged array
 */
typedef struct {
  int length;
  int* ranges;
} RangeR2Item;

/*
 * Struct for the type of a Jagged Array
 */
typedef struct{
  int dimension_count;
  int range_R1[2];
  RangeR2Item* range_R2;
  enum Type basic_element_type;
} JaggedArray;

/*
 * Struct for the type of a rectangular array
 */
typedef struct{
  int dimension_count;
  int* lows;
  int* highs;
  enum Type basic_element_type;
} RectArray;

/*
 * Union for the array type
 */
typedef union{
  JaggedArray j;
  RectArray r;
} Array;

/*
 * Struct representing the type expression, implemented as a tagged union
 */
typedef struct{
  Array array;
  enum Type t;
} TypeExpression;

/*
 * Returns 1 if two type expressions are equal
 */
int isTEEqual(TypeExpression a, TypeExpression b);

/*
 * Print a type expression
 *
 * a : The type expression
 */
void printTE(TypeExpression a);

#endif
