#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};typedef struct node node_t;

typedef struct circ_llist {
    node_t *tail;
} circ_llist_t;

void initialize(circ_llist_t* list){
    node_t* a = (node_t*) malloc(sizeof(node_t));
    list -> tail = NULL;
}

void add_node(circ_llist_t* list, int data){
    node_t* b = (node_t*) malloc(sizeof(node_t));
    b -> data = data;
    if (list -> tail  == NULL) {
        list -> tail = b;
        b -> next = list -> tail;
    } else {
        b -> next = list -> tail -> next;
        list -> tail -> next = b;
        list -> tail = list -> tail -> next;

    }
}

node_t* find_middle(circ_llist_t *list) {
    node_t *ptr = (node_t*) malloc(sizeof(node_t));
    ptr = list -> tail;
    int n = 0;
    while(ptr -> next != list -> tail){
        ptr = ptr -> next;
        ++n;
    }
    ptr -> next = list -> tail;
    for(int i = 0; i < (n+1)/2+2; ++i){
        ptr = ptr -> next;
    }
    // 5 1 2 3 4 5 3 1 2 3
    return ptr;
}

int main(){
 circ_llist_t my_list;
 initialize(&my_list);
 node_t *middle_ptr;
 int data, input_size;

 scanf("%d\n", &input_size);
 for(int i=0; i < input_size; ++i) {
 scanf("%d", &data);
 add_node(&my_list, data);
 }
 middle_ptr = find_middle(&my_list);
 printf("%d\n", middle_ptr->data);
 return 0;
}
