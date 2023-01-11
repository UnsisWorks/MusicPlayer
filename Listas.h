#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data[100];
    struct node *next;
    struct node *prev;
} node;

typedef struct list {
    node *head;
} list;

struct node *create_nodo ();
list *init_list();
int is_empty(list *l);
void insert(list *l, char data[]);
void delete_node(list *l, char data[]);
int count_nodes(list *l);
node *search (list *l, char data[]);
void delete_list(list *l);