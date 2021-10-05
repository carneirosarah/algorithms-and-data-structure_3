#ifndef LISTA_DUPLAMENTE_ENCADEADA_H
#define LISTA_DUPLAMENTE_ENCADEADA_H

struct doubly_linked_list {
    int info;
    struct doubly_linked_list* next;
    struct doubly_linked_list* prev;
};

typedef struct doubly_linked_list dl_list;

dl_list* new_node (void);
dl_list* insert(dl_list* node, int info);
dl_list* search (dl_list* node, int info);
dl_list* remove_node (dl_list* node, int info);
int length (dl_list* node);
dl_list* last_element (dl_list* node);
dl_list* merge(dl_list* a, dl_list* b);
dl_list** split (dl_list* nodes, int k);
dl_list* copy(dl_list* nodes);
void print(dl_list* data);
dl_list* sort(dl_list* nodes, int type);
// Implementacao do Quicksort
dl_list* quicksort(dl_list* nodes, dl_list* start, dl_list* finish);

#endif