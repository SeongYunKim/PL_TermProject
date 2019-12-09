#pragma once

// Error Node ==========================================================================================================

typedef struct ErrorNode{
    char code[1000];
    int line;
    //struct ErrorList *prev;
    struct ErrorNode *next;
}ErrorNode;

void errorNodeAppend(ErrorNode **node, char *code, int line);
void errorListPrint(ErrorNode **node);

// Name Node ===========================================================================================================

typedef enum varType{
    V_INT,
    V_INT_ARY,
    V_FLOAT,
    V_FLOAT_ARY,
    V_FUNC,
    V_PROC,
    V_UNKNOWN
} varType;

typedef struct NameNode{
    char name[1000];
    int dec_line;
    enum varType type;
    struct NameNode *next;
}NameNode;
typedef NameNode *NameList;

NameNode *nameNodeFind(NameList list, char *name);
void nameListAppend(NameList *list, char *name, varType type, int dec_line);
void nameNodeConcat(NameList First, NameList Second);
NameList makeNameList();

// subProgNode =========================================================================================================

typedef enum pType{
    FUNC,
    PROC
}pType;

typedef struct SubProgNode {
    char name[1000];
    int dec_line;
    pType type;
    NameList param_list;
    NameList local_list;
    NameList used_var_list;
    struct SubProgNode *next;
}SubProgNode;
typedef SubProgNode *SubProgList;

void subProgListAppend(SubProgList *list, char *name, pType type, NameList param_list, NameList local_list, NameList used_var_list, int dec_line);
SubProgList makeSubProgList();