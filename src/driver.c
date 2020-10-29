/*
 * Definition of the driver function
 *
 * Authors:
 * Rahul Ganesh Prabhu (2018A7PS0193P)
 * Shreyas Kera (2018A7PS1119P)
 * Achyuth Anand Tadepalli (2018A7PS1117P)
 * Raghurama Varma Gonela (2018A7PS1120P)
 */
#include "token_stream.h"
#include "parse_tree.h"
#include "grammar.h"

int main(int argc, char* argv[])
{
  TokenStream* s = (TokenStream*)malloc(sizeof(TokenStream));
  tokenizeSourceCode(argv[1],s);
  TokenStreamNode* saved_head = s->head; // To rewind the token stream between calls

  Grammar* G = (Grammar*)malloc(sizeof(Grammar));
  readGrammar("grammar.txt",G);
  extern int error_output;

  while(1)
  {
    int option;
    scanf("%d",&option);

    if(option==0)
    {
      break;
    }
    else if (option==1)
    {
      ParseTree* t = (ParseTree*)malloc(sizeof(ParseTree));
      error_output = 0;
      createParseTree(t,s,G);

      // Prepare for next call
      s->head = saved_head;
      freeParseTree(t);
    }
    else if (option==2)
    {
      ParseTree* t = (ParseTree*)malloc(sizeof(ParseTree));
      TypeExpressionTable* E = malloc(sizeof(TypeExpressionTable));
      E->capacity = 8;
      E->size = 0;
      E->T = malloc(E->capacity * sizeof(TypeExpressionRecord));
      error_output = 1;
      createParseTree(t,s,G);
      traverseParseTree(t,E);

      // Prepare for next call
      s->head = saved_head;
      freeParseTree(t);
      free(E);
    }
    else if (option==3)
    {
      ParseTree* t = (ParseTree*)malloc(sizeof(ParseTree));
      TypeExpressionTable* E = malloc(sizeof(TypeExpressionTable));
      error_output = 0;
      E->capacity = 8;
      E->size = 0;
      E->T = malloc(E->capacity * sizeof(TypeExpressionRecord));
      createParseTree(t,s,G);
      traverseParseTree(t,E);
      printParseTree(t);

      // Prepare for next call
      s->head = saved_head;
      freeParseTree(t);
    }
    else if (option==4)
    {
      ParseTree* t = (ParseTree*)malloc(sizeof(ParseTree));
      TypeExpressionTable* E = malloc(sizeof(TypeExpressionTable));
      E->capacity = 8;
      E->size = 0;
      E->T = malloc(E->capacity * sizeof(TypeExpressionRecord));
      error_output = 0;
      createParseTree(t,s,G);
      traverseParseTree(t,E);
      printTypeExpressionTable(*E);

      // Prepare for next call
      s->head = saved_head;
      freeParseTree(t);
      free(E);
    }
  }
}
