#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
};
typedef struct node node_t;
typedef struct circ_llist {
    node_t *tail;
} circ_llist_t;

void output_list(circ_llist_t* list){
    while (list -> tail -> next != list -> tail) {
        printf("%d ", list -> tail -> next -> data);
        list -> tail -> next = list -> tail -> next -> next; 
    }
    printf("%d", list -> tail -> data);
}

int main(){
    circ_llist_t my_list;
    node_t *a, *b, *c;
    a = (node_t*) malloc(sizeof(node_t));
    b = (node_t*) malloc(sizeof(node_t));
    c = (node_t*) malloc(sizeof(node_t));
    a->data = 3;
    b->data = 7;
    c->data = 1;
    a->next = b;
    b->next = c;
    c->next = a;
    my_list.tail = c;
    output_list(&my_list);
    return 0;
}
