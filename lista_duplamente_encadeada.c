#include "lista_duplamente_encadeada.h"
#include <stdio.h>
#include <stdlib.h>

dl_list* new_node (void) {
    
    return NULL;
}

dl_list* insert(dl_list* node, int info) {

    dl_list* new = (dl_list*) calloc (1, sizeof(dl_list));
    new -> info = info;
    new -> next = node;
    new -> prev = NULL;

    if (node != NULL) {
        node -> prev = new;
    }

    return new;
}

dl_list* search (dl_list* node, int info) {

    for (dl_list* p = node; p != NULL; p = p -> next) {
        
        if(p -> info == info) {
            return p;
        }
    }

    return NULL;
}

dl_list* remove_node (dl_list* node, int info) {

    dl_list* p = search(node, info);

    if (p == NULL) {
        return node;
    }

    if (node == p) {
        
        node = p -> next;
    } else {

        p -> prev -> next = p -> next;
    }

    free(p);

    return node;
}

int length (dl_list* node) {
    
    int len = 0;

    for (dl_list* p = node; p != NULL; p = p -> next) {
        len++;    
    }

    return len;
}

dl_list* last_element (dl_list* node) {
    
    dl_list* p = NULL;
    
    for (p = node; p -> next != NULL; p = p -> next);

    return p;
}

dl_list* merge(dl_list* a, dl_list* b) {

    dl_list* concat = new_node();

    for (dl_list* p = last_element(b); p != NULL; p = p->prev)
    {
        concat = insert(concat, p->info);
    }
    
    for (dl_list* p = last_element(a); p != NULL; p = p->prev)
    {
        concat = insert(concat, p->info);
    }

    return concat;
}

dl_list** split (dl_list* nodes, int k){

    dl_list** pieces = (dl_list**) calloc (k, sizeof(dl_list*));
    dl_list* p = last_element(nodes);
    
    int len = length(nodes)/k;

    for (int i = 0; i < k; i++) {
        
        pieces[i] = new_node();

        if (i == k - 1) {

            len = len + (length(nodes)%k);
        }
        
        for (int j = 0; j < len; j++) {

            pieces[i] = insert(pieces[i], p->info);
            p = p -> prev;
        }
    }

    return pieces;
}

dl_list* copy(dl_list* nodes) {
    
    dl_list* new = new_node();

    for (dl_list* p = last_element(nodes); p != NULL; p = p -> prev) {
        new = insert(new, p -> info);
    }
    
    return new;
}

void print(dl_list* data) {

    dl_list* p;

    for(p = data; p!=NULL; p = p -> next) {
        printf("info = %d\n", p->info);
    }
    
    printf("\n");
}

dl_list* reverse (dl_list* a) {

    dl_list* p = a;
    dl_list* prev = NULL;
    dl_list* aux = NULL;

    while (p != NULL) {
        aux = p -> next;
        p -> next = p -> prev;
        p -> prev = aux;
        prev = p;
        p = aux;
    }
    
    a = prev;
    return a;
}

dl_list* sort(dl_list* nodes, int type) {

    dl_list* finish = last_element(nodes);

    // ordem crescente
    if (type == 0) {

        return quicksort(nodes, nodes, finish);

    // ordem decrescente
    } else {
        
        return reverse(quicksort(nodes, nodes, finish));
    }
}

// Implementacao do Quicksort
dl_list* quicksort(dl_list* nodes, dl_list* start, dl_list* finish) {

    if (nodes != NULL && start != NULL && finish != NULL) {

        dl_list* pivot = finish;
        dl_list* smaller = start;
        int aux = 0;

        for (dl_list* p = start; p != finish->next; p = p -> next) {

            if (p -> info <= pivot -> info && p != smaller) {

                if (p->info < smaller->info) {

                    aux = p -> info;
                    p -> info = smaller -> info;
                    smaller -> info = aux;
                }

                if ( p == pivot ) {
                    pivot = smaller;
                }

                smaller = smaller -> next;
            }
        }

        if (smaller -> info < pivot -> info) {

            aux = pivot -> info;
            pivot -> info = smaller -> info;
            smaller -> info = aux;

            pivot = smaller;  
        }      

        if (pivot != start) {
            quicksort(nodes, start, pivot);
        }

        if (pivot != finish) {
            quicksort(nodes, pivot -> next, finish);
        }

        return start;
    }
}