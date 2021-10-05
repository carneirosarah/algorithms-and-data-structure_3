//#include "merge_sort.c"
#include "insertion_sort.c"


int main (void) {

    // stack* list = new_stack();
    // list = push(list, 3);
    // list = push(list, 8);
    // list = push(list, 1);
    // list = push(list, 4);
    // list = push(list, 6);
    // list = push(list, 2);
    // list = push(list, 7);
    // list = push(list, 4);

    // print(list);

    // printf("\n");

    // stack* out = merge_sort(list, 0, 8);
    // print(out);

    // printf("\n");


    dl_list* data = new_node();
    data = insert(data, 4);
    data = insert(data, 7);
    data = insert(data, 2);
    data = insert(data, 6);
    data = insert(data, 4);
    data = insert(data, 1);
    data = insert(data, 8);
    data = insert(data, 3);

    print(data);

    printf("\n");

    dl_list* out = insertion_sort(data);

    print(out);

    return 0;
}