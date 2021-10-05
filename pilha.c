#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

stack* new_stack () {

    stack* s = (stack*) calloc (1, sizeof(stack));
    s -> top = NULL;
    return s;
}

stack* push (stack* data, int value) {

    element* node = (element*) calloc (1, sizeof(element));
    node -> value = value;
    node -> next = data -> top;
    data -> top = node;

    return data;
}

void pop (stack* data) {

    if (is_empty(data)) {

        return;
    }

    element* node = data -> top;
    data -> top = node -> next;
    free(node);
}

int is_empty (stack* data) {
    
    return data -> top == NULL;
}

void free_stack (stack* data) {

    element *node, *aux = data -> top;

    while (node != NULL) {
        
        aux = node -> next;
        free(node);
        node = aux;
    }

    free(data);
}

void print(stack* data) {

    for (element* node = data -> top; node != NULL; node = node -> next) {
        
        printf("info = %d \n", node -> value);
    }
}

int length (stack* data) {
    
    int len = 0;

    for (element* p = data -> top; p != NULL; p = p -> next) {
        len++;    
    }

    return len;
}

stack* reverse(stack* data) {

    stack* aux = new_stack();

    for (element* p = data -> top; p != NULL; p = p -> next) {
        
        aux = push(aux, p -> value);
    }

    return aux;
}