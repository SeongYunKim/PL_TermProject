#pragma once

#include "list.h"

typedef struct checkNode{
    int int_data;
    char str_data;
    varType type_data;
    void *ptr_data;
    int line;
} checkNode;