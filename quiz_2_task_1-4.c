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
void reverse_list(circ_llist_t* list){
    node_t* now = (node_t*) malloc(sizeof(node_t));
    node_t* pre = (node_t*) malloc(sizeof(node_t));
    node_t* next = (node_t*) malloc(sizeof(node_t));
    now = list -> tail -> next;
    pre = list -> tail;
    next = list -> tail -> next -> next;
    while (now != list-> tail){
        //printf("%d%d%d\n", pre -> data, now -> data, next -> data);
        now -> next = pre;
        pre = now;
        now = next;
        next= next -> next;
    }
    //printf("%d%d%d\n", pre -> data, now -> data, next -> data);
    now -> next = pre;
    pre = now;
    now = next;
    next= next -> next;
    //printf("%d%d%d\n", pre -> data, now -> data, next -> data);
    list -> tail = now ;
}

void output_list(circ_llist_t* list){
    while (list -> tail -> next != list -> tail) {
        printf("%d ", list -> tail -> next -> data);
        list -> tail -> next = list -> tail -> next -> next; 
    }
    printf("%d", list -> tail -> data);
}

int main(){
 circ_llist_t my_list;
 initialize(&my_list);
 int data, input_size;

 scanf("%d\n", &input_size);
 for(int i=0; i < input_size; ++i) {
 scanf("%d", &data);
 add_node(&my_list, data);
 }
 reverse_list(&my_list);
 output_list(&my_list);
 return 0;
}
