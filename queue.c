#include "queue.h"

#define Q_MALLOC(_ptr, n) (_ptr *) malloc((n)*sizeof(_ptr))


static
bool q_init(void)
{
	/* Head will always be dummy */
	genericQueue * dummyHead = (genericQueue *) malloc (sizeof(genericQueue));
	if (!dummyHead) return false;
	head = dummyHead;
	tail = head;
	isInit = true;
}

bool q_isEmpty(void)
{
	return (numItems < 1);
}

bool q_add(void * data, size_t size)
{
	if (!isInit)
	{
		if (!q_init()) 
		{
			return false;
		}
	}

	genericQueue * entry = Q_MALLOC(genericQueue, 1);
	entry->size = size;
	entry->data = data;
	entry->next = NULL;

	/* add item at the end of the queue */
	if (head != tail)
	{
		tail->next = entry;
		tail = tail->next;
	}
	else
	{
		head->next = entry;
		tail = entry;
		tail->next = NULL;
	}

	++numItems;

}

void q_pop(genericQueue * hold)
{
	if (q_isEmpty())
	{
		hold =  NULL;
		return;
	}
	
	/* point to item to be popped */
	genericQueue * val = head->next;
	head->next = head->next->next;
	numItems--;

	hold = val;
}

void q_peek(genericQueue * hold)
{
	if (q_isEmpty())
	{
		hold =  NULL;
		return;
	}
		hold = head->next;
}

bool q_clear(void)
{
	if (q_isEmpty()) return true;
	genericQueue * cur, * nxt;
	cur = head->next;
	nxt = cur->next;

	while (nxt)
	{
		free(cur);
		cur = nxt;
		nxt = nxt->next;
	}
	free(cur);

	return true;
}

uint32_t q_numItems(void)
{
	return numItems;
}

int main(void)
{
	return 0;
}