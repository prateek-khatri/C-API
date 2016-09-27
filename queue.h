#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdio.h> // remove this after debugging
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

typedef struct genericQueue
{
	size_t size;
	void *data;
	struct genericQueue * next;
} genericQueue;

static 
bool isInit = false;

static
uint32_t numItems = 0;

static 
genericQueue * head = NULL;

static
genericQueue * tail = NULL;

bool q_add(void *data, size_t size);
void q_pop(genericQueue * ptr);
void peek(genericQueue * ptr);
bool q_isEmpty(void);
uint32_t q_numItems(void);
bool q_clear(void);



#endif //_QUEUE_H_