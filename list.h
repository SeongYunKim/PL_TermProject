#pragma once

// Error Node ==========================================================================================================

typedef struct ErrorNode{
    char *code;
    int line;
    //struct ErrorList *prev;
    struct ErrorNode *next;
}ErrorNode;

void errorNodeAppend(ErrorNode **node, char *code, int line);
void errorListPrint(ErrorNode **node);

// Name Node ===========================================================================================================

typedef enum varType{
    V_INT = 1,
    V_INT_ARY = 2,
    V_FLOAT = 3,
    V_FLOAT_ARY = 4,
    V_FUNC = 5,
    V_PROC = 6,
    V_UNKNOWN = 7
} varType;

typedef struct NameNode{
    char name[1000];
    int dec_line;
    enum varType type;
    struct NameNode *next;
}NameNode;
typedef NameNode *NameList;

NameNode *nameNodeFind(NameNode *list, char *name);
void nameListAppend(NameList *list, char *name, varType type, int dec_line);
void nameNodeConcat(NameList First, NameList Second);
NameList makeNameList();