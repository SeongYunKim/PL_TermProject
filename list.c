#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void appendErrorList(ErrorNode **list, char *code, int line) {
    ErrorNode *curErrorNode = *list;
    ErrorNode *newErrorNode = (ErrorNode *) malloc(sizeof(ErrorNode));
    newErrorNode->code = code;
    newErrorNode->line = line;
    newErrorNode->next = NULL;
    if (*list == NULL) {
        *list = newErrorNode;
    } else {
        while (curErrorNode->next != NULL) {
            curErrorNode = curErrorNode->next;
        }
        curErrorNode->next = newErrorNode;
    }
}

void printErrorList(ErrorNode **list) {
    ErrorNode *curErrorNode = *list;
    while (curErrorNode->next != NULL) {
        printf("Syntax Error on line %d : %s\n", curErrorNode->line, curErrorNode->code);
        curErrorNode = curErrorNode->next;
    }
    printf("Syntax Error on line %d : %s\n", curErrorNode->line, curErrorNode->code);
}