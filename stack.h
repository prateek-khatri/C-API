#ifndef _STACK_H
#define _STACK_H_

#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef struct genericStack
{
	void * data;
	size_t size;
	struct genericStack * next;
} genericStack;

static
uint32_t numItems = 0;

static
genericStack * head = NULL;

static
genericStack * tail = NULL;

bool stk_isEmpty(void);
bool stk_push(void *data, size_t size);
bool stk_pop(genericStack * ptr);
bool stk_peek(genericStack * ptr);
uint32_t stk_numItems(void);


#endif _STACK_H_