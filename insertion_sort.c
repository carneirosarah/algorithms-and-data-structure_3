#include "insertion_sort.h"

dl_list* insertion_sort(dl_list* data) {

    int key = 0;
    dl_list* p = NULL;
    dl_list* aux = NULL;

    for (dl_list* node = data -> next; node != NULL; node = node -> next) {
        
        key = node -> info;

        for (p = node -> prev; p != NULL && p -> info > key; p = p -> prev) {

            p->next->info = p->info;
            aux = p;
        }

        if (p != NULL) {

            p->next->info = key;
        } else {
            
            aux -> info = key;
        }

        print(data);
    }
    
    return data;
}
