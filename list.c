#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}

List * createList() {

  List* v = (List*) malloc(sizeof(List));
  assert(v != NULL);
  v->head = NULL;
  v->tail = NULL;
  v->current = NULL;
  
     return v;
}

void * firstList(List * list) {
  if(list->head == NULL)
  {
    return NULL;
  }

  list->current = list->head;
  
    return list->current->data;
}

void * nextList(List * list) {
  
  if(list->current == NULL)
  {
    return NULL;
  }

  if(list->current->next == NULL)
  {
    return NULL;
  }

  list->current = list->current->next;
    return list->current->data;
}

void * lastList(List * list) {
  if(list->tail == NULL)
  {
    return NULL;
  }

  list->current = list->tail;
  
    return list->current->data;
}

void * prevList(List * list) {
  if(list->current == NULL)
  {
    return NULL;
  }

  if(list->current->prev == NULL)
  {
    return NULL;
  }

  list->current = list->current->prev;
    return list->current->data;
}

void pushFront(List * list, void * data) {
  Node * nuevo = createNode(data);
  nuevo->next = list->head;

  if(list->head != NULL){

    list->head->prev = nuevo;
  }

  list->head = nuevo;
  
  if(list->tail == NULL)
  {
    list->tail = nuevo;
  }
}

void pushBack(List * list, void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, void * data) {
  Node * nuevoNodo = createNode(data);

  if(list->head == NULL && list->tail == NULL)
  {
    list->head = nuevoNodo;
    list->tail = nuevoNodo;
  }
  else
  {
    nuevoNodo->next = list->current->next;
    nuevoNodo->prev = list->current;

    if(list->current->next == NULL)
    {
      list->tail = nuevoNodo;
    }
    else
    {
      list->current->next->prev = nuevoNodo;
    }

    list->current->next = nuevoNodo;
  }
  
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  if(list->current == NULL)
    return NULL;

  void * dato = list->current->data;

  if(list->current == list->head)
  {
    list->head = list->current->next;
    list->head->prev = NULL;
  }
  else
  {
    if(list->current == list->tail)
    {
      list->tail = list->current->prev;
      list->tail->next = NULL;
    }
    else
    {
      list->current->prev->next = list->current->next;
      list->current->next->prev = list->current->prev;
    }
  }

  return dato;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}