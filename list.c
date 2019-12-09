#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

// Error Node ==========================================================================================================

void errorNodeAppend(ErrorNode **list, char *code, int line) {
    ErrorNode *curErrorNode = *list;
    ErrorNode *newErrorNode = (ErrorNode *) malloc(sizeof(ErrorNode));
    strcpy(newErrorNode->code, code);
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

void errorListPrint(ErrorNode **list) {
    ErrorNode *curErrorNode = *list;
    while (curErrorNode->next != NULL) {
        printf("Error (line %d) : %s\n", curErrorNode->line, curErrorNode->code);
        curErrorNode = curErrorNode->next;
    }
    printf("Error (line %d) : %s\n", curErrorNode->line, curErrorNode->code);
}

// Name Node ===========================================================================================================

void nameListAppend(NameList *list, char *name, varType type, int dec_line) {
    NameList curNameNode = *list;
    NameList newNameNode = (NameList)malloc(sizeof(NameNode));
    strcpy(newNameNode->name, name);
    newNameNode->type = type;
    newNameNode->dec_line = dec_line;
    newNameNode->next = NULL;
    if (*list == NULL) {
        *list = newNameNode;
    } else {
        while (curNameNode->next != NULL) {
            curNameNode = curNameNode->next;
        }
        curNameNode->next = newNameNode;
    }
}

NameNode *nameNodeFind(NameList list, char *name) {
    NameNode *curNameNode = list;
    if(list == NULL)
        return NULL;
    while(curNameNode->next != NULL && strcmp(curNameNode->name, name) != 0) {
        curNameNode = curNameNode->next;
    }
    if(strcmp(curNameNode->name, name) == 0)
        return curNameNode;
    return NULL;
}

void nameNodeConcat(NameList First, NameList Second) {
    NameList curNameNode = First;
    if (curNameNode == NULL) {
        First = Second;
    }
    else {
        while (curNameNode->next != NULL) {
            curNameNode = curNameNode->next;
        }
        curNameNode->next = Second;
    }
}

NameList makeNameList() {
    return NULL;
}

// checkNode ===========================================================================================================
void subProgListAppend(SubProgList *list, char *name, pType type, NameList param_list, NameList local_list, NameList used_var_list, int dec_line){
    SubProgList curNode = *list;
    SubProgList newNode = (SubProgList)malloc(sizeof(SubProgNode));
    strcpy(newNode->name, name);
    newNode->dec_line = dec_line;
    newNode->param_list = param_list;
    newNode->local_list = local_list;
    newNode->used_var_list = used_var_list;
    newNode->type = type;
    if (*list == NULL) {
        *list = newNode;
    } else {
        while (curNode->next != NULL) {
            curNode = curNode->next;
        }
        curNode->next = newNode;
    }
}

SubProgList makeSubProgList() {
    return NULL;
}