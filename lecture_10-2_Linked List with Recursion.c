#include <stdio.h>
#include <stdlib.h>


struct node{
    int data;
    struct node *next;
};
typedef struct node node_t;

typedef struct linked_list {
    node_t *head;
    node_t *tail;
} linked_list_t;

void initialize(linked_list_t *list_ptr) {
    list_ptr->head = NULL;
    list_ptr->tail = NULL;
}

void output(node_t *ptr) {
    if(ptr -> next != NULL){
        printf("%d ", ptr -> data);
        output(ptr -> next);
    } else {
        printf("%d \n", ptr -> data);
    }
}



void add_node(linked_list_t *list_ptr, int data) {
    node_t *ptr = (node_t*) malloc(sizeof(node_t));
    if(list_ptr -> head == NULL) {
        ptr -> data = data;
        ptr -> next = NULL;
        list_ptr -> tail = ptr;
        list_ptr -> head = list_ptr -> tail;
    }
    else {
        ptr -> data = data;
        ptr -> next = NULL;
        list_ptr -> tail -> next = ptr;
        list_ptr -> tail = list_ptr -> tail -> next; 
    }
}


void free_list(linked_list_t *ptr_list) {
    while (ptr_list -> head != NULL) {
        node_t *ptr = (node_t*) malloc(sizeof(node_t));
        ptr = ptr_list -> head;
        ptr_list -> head = ptr_list -> head -> next;
        free(ptr);
    }
}

void reverse_output(linked_list_t *ptr_list, node_t *ptr) {
    if(ptr != NULL) {
        reverse_output(ptr_list, ptr -> next);
        printf("%d", ptr -> data);
        if(ptr != ptr_list -> head){
            printf(" ");
        }
    }
}

int main(){
    linked_list_t my_list;
    initialize(&my_list);
    node_t *middle_ptr;
    
    int data, input_size;
    /* when you add a node, you add it at the tail */
    
    scanf("%d\n", &input_size);
    for(int i=0; i < input_size; ++i) {
        scanf("%d", &data);
        add_node(&my_list, data);
    }
    
    output(my_list.head);
    reverse_output(&my_list, my_list.head);

    free_list(&my_list);
    return 0;
}

