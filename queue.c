#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "queue.h"


typedef struct node
{
  void *dat;
  struct node *next;
} node;

typedef struct queue
{
  int size;
  node *front;
  node *back;
} queue;

queue *hiq(int size)
{
  queue *q = malloc(sizeof(queue));
  q->size = size;
  q->front = q->back = NULL;

  return q;
}

void byeq(queue *q)
{
  node *n = q->front;
  while(n)
  {
    node *temp = n->next;
    free(n->dat);
    free(n);
    n = temp;
  }

  free(q);
}

void enq(queue *q, void *dat)
{
  int size = q->size;
  void *newdat = malloc(size);
  memcpy(newdat, dat, size);
  node *n = malloc(sizeof(node));
  n->dat = newdat;
  n->next = NULL;

  if(q->back)
  {
    q->back->next = n;
    q->back = n;
  }
  else
  {
    q->front = q->back = n;
  }
}

void deq(queue *q, void *dat)
{
  node *front = q->front;

  if(!front)
  {
    fputs("deq: empty queue\n", stderr);
    return;
  }
  
  memcpy(dat, front->dat, q->size);

  q->front = front->next;
  free(front->dat);
  free(front);
}
