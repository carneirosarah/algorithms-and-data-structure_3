#include "merge_sort.h"


stack* merge_sort(stack* list, int start, int finish) {
        
    if (finish - start > 1) {

        int middle = (finish + start)/2;

        merge_sort(list, start, middle);
        merge_sort(list, middle, finish);
        merge(list, start, middle, finish);
    }

}

stack* merge(stack* list, int start, int half, int finish) {

    stack* l_list = new_stack();
    stack* r_list = new_stack();
    
    int i = 0;

    for (element* p = list -> top; p != NULL; p = p -> next) {
        
        if (i >= start && i < half) {

            l_list = push(l_list, p->value);
        
        } else if (i >= half && i < finish) {

            r_list = push(r_list, p->value);
        }

        i++;
    }

    l_list = reverse(l_list);
    r_list = reverse(r_list);

    i = 0;

    for (element* p = list -> top; p != NULL; p = p -> next) {
        
        if (i >= start && i<finish) {

            if (is_empty(l_list)) {
                p -> value = r_list->top->value;
                pop(r_list);

            } else if (is_empty(r_list)) {

                p -> value = l_list-> top->value;
                pop(l_list);

            } else if (l_list->top->value < r_list ->top->value) {

                p -> value = l_list->top->value;
                pop(l_list);

            } else {

                p -> value = r_list->top-> value;
                pop(r_list);
            }
        
        } else if (i > finish) {
            break;
        }

        i++;
    }
    
    return list;
}