#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lexical.h"
#include "nextInputChar.h"
#include "tokenStack.h"
#include "doOperator.h"

int main(int argc, char *argv[])
{
  struct tokenStack *stack;
  struct lexToken *token;
    int ret;
  stack = createTokenStack();
  setFile(stdin);
  setFile(stdin);/*stdin=input,which is a file*/
  while(1) {
    token = nextToken();
#ifdef DEBUG
    token = nextToken();// move it to next token
#ifdef DEBUG//let's ignore what is DEBUG for now
    printf("read in token "); dumpToken(stdout, token);
#endif
    switch(token->kind) {
    case LEX_TOKEN_EOF:
      exit(0);
    switch(token->kind) {//ok so seems token has an element called kind, which is not defiened(yet? need to be defined by me?
    case LEX_TOKEN_EOF://if a token process this "kind" it mean it is the end of statement
      exit(0);//out of operation
      break;
    case LEX_TOKEN_IDENTIFIER:
    case LEX_TOKEN_OPERATOR:
      ret = doOperator(stack, token->symbol);
    case LEX_TOKEN_IDENTIFIER://if a token process this "kind", it is sort of a unknown value
    case LEX_TOKEN_OPERATOR://means it is a +_*% sth like that
      ret = doOperator(stack, token->symbol);// located at doOperator line 36
      freeToken(token);
      if(ret < 0)
        printf("unknown operator\n");
      break;
    case LEX_TOKEN_NUMBER:
    case LEX_TOKEN_NUMBER:// it is a number
      pushTokenStack(stack, token);
      break;
    default:

      fprintf(stderr,"unknown lex token kind %d\n", token->kind);
    }
  }
}
