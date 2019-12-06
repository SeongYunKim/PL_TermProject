#pragma once

typedef struct {
    char *code;
    int line;
    //struct ErrorList *prev;
    struct ErrorList *next;
}ErrorNode;

void appendErrorList(ErrorNode **node, char *code, int line);
void printErrorList(ErrorNode **node);