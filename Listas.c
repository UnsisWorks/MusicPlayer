#include <stdio.h>
#include <stdlib.h>
#include "Listas.h"

struct node *create_nodo (){
    return ((struct node *)malloc(sizeof(struct node)));
}

// Inicializa una nueva lista vacía.
list *init_list() {
    list *l = malloc(sizeof(list));
    l->head = NULL;
    return l;
}


void insert(list *l, char data[]) {
    node *n = malloc(sizeof(node));
    // n->data = data;
    strcpy(n->data, data);

    if (l->head == NULL) {
        // Si la lista está vacía, el nuevo nodo será el único nodo en la lista.
        // En este caso, el nodo anterior y el siguiente del nuevo nodo serán el mismo nodo.
        n->prev = n;
        n->next = n;
        l->head = n;
    } else {
        // Si la lista no está vacía, se inserta el nuevo nodo después del último nodo en la lista.
        node *last = l->head->prev;
        n->prev = last;
        n->next = l->head;
        last->next = n;
        l->head->prev = n;
    }
}

node *search(list *l, char data[]) {
    // Si la lista está vacía, no hay nodos que buscar.
    if (l->head == NULL) {
        return NULL;
    }

    // Si hay un solo nodo en la lista, se devuelve el nodo si contiene el dato buscado, o NULL en caso contrario.
    if ((l->head->prev == l->head) && (l->head->next == l->head)) {
        if ((strcmp(l->head->data, data)) == 0) {
            return l->head;
        } else {
            return NULL;
        }
    }
    
    // Si hay más de un nodo en la lista, se busca el nodo recorriendo la lista en ambos sentidos.
    node *n = l -> head;
    while (n != l->head->next) {
        // printf("info sea: %d\n", n->data);
        if (strcmp(n->data, data) == 0) {
            return n;
        }
        n = n->next;
    }
    n = l->head->prev;
    while (n != l->head) {
        if (strcmp(n->data, data) == 0) {
            return n;
        }
        n = n->prev;
    }

    // Si no se encuentra el nodo, se devuelve NULL.
    return NULL;
}

void delete_node(list *l, char data[]) {
    node *n = search(l, data);
    // printf("info: %d\n", n->data);

    // Si la lista está vacía, no se puede eliminar ningún nodo.
    if (l->head == NULL) {
        return;
    }

    // Si hay un solo nodo en la lista, simplemente se establece el puntero head de la lista en NULL.
    if (l->head->prev == l->head && l->head->next == l->head) {
        free(l->head);
        l->head = NULL;
        return;
    }

    // Si hay más de un nodo en la lista, se ajustan los punteros prev y next de los nodos vecinos del nodo a eliminar.
    node *prev = n->prev;
    node *next = n->next;
    prev->next = next;
    next->prev = prev;

    // Si el nodo a eliminar es el primer nodo en la lista, se actualiza el puntero head de la lista.
    if (n == l->head) {
        l->head = next;
    }

    // Finalmente, se libera la memoria asignada al nodo eliminado.
    free(n);
}

int count_nodes(list *l) {
    // Si la lista está vacía, no hay nodos que contar.
    if (l->head == NULL) {
        return 0;
    }

    // Si hay un solo nodo en la lista, se devuelve 1.
    if (l->head->prev == l->head && l->head->next == l->head) {
        return 1;
    }

    // Si hay más de un nodo en la lista, se cuentan los nodos recorriendo la lista en ambos sentidos.
    int count = 1;
    node *n = l->head->next;
    while (n != l->head) {
        count++;
        n = n->next;
    }
    // n = l->head->prev;
    // while (n != l->head) {
    //     count++;
    //     n = n->prev;
    // }
    return count;
}


void delete_list(list *l) {
    // Si la lista está vacía, no hay nodos que eliminar.
    if (l->head == NULL) {
        return;
    }

    // Si hay un solo nodo en la lista, se elimina el nodo y se libera la memoria asignada para la lista.
    if (l->head->prev == l->head && l->head->next == l->head) {
        free(l->head);
        free(l);
        return;
    }

    // Si hay más de un nodo en la lista, se eliminan todos los nodos recorriendo la lista en ambos sentidos.
    node *n = l->head->next;
    while (n != l->head) {
        node *tmp = n;
        n = n->next;
        free(tmp);
    }
    n = l->head->prev;
    // while (n != l->head) {
    //     node *tmp = n;
    //     n = n->prev;
    //     free(tmp);
    // }

    // Se elimina el primer nodo y se libera la memoria asignada para la lista.
    free(l->head);
    free(l);
}
/* Imprime los elementos de la lista doblemente enlazada circular. */
void print_list(list *list) {
  node *current = list->head;

  /* Recorre la lista hasta volver al elemento inicial. */
  do {
    printf("%s -> ", current->data);
    current = current->next;
  } while (current != list->head);
  puts("NULL");
}


int is_empty(list *l) {
    if (l -> head == NULL) {
      // la lista está vacía
      return 0;
    } else {
    // la lista no está vacía
    return 1;
    }
}