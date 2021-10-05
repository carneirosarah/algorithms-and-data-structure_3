#ifndef PILHA_H
#define PILHA_H

struct element {
    int value;
    struct element* next;
};

typedef struct element element;

struct stack {
    element* top;
};

typedef struct stack stack;

stack* new_stack ();
stack* push (stack* data, int value);
void pop (stack* data);
int is_empty (stack* data);
void free_stack (stack* data);
void print(stack* data);
int length (stack* data);
stack* reverse(stack* data);

#endif