
 #include "genlinklist.h"

LIST makelinklist(void){
	LIST linklist = (LIST)malloc(sizeof(linklist_t));

	linklist->head = NULL;
	linklist->tail = NULL;

	return linklist;
}

node_t * createNode(void * item){
	node_t * node = (node_t *) malloc(sizeof(node_t));

	node->prev = NULL;
	node->next = NULL;
	node->item = item;
	return node;
}

void insertnode(LIST linklist, void * item)
{
	node_t * node = createNode(item);

	if (isEmpty(linklist)==1){
		puts("Nothing currently in list, adding now");
		linklist->head = node;
		linklist->tail = node;

		return;
	}

	linklist->tail->next = node;
	node->prev = linklist->tail;
	linklist->tail = node;
}

void forwardTraverse(LIST linklist, void (* print)(void * val))
{
	node_t * current = linklist->head;

	printf("[");

	while (current != NULL)
	{
		print(current->item);
		current = current->next;
		if (current != NULL){
			printf(", ");
		}
	}
	printf("]\n");
}

void toString(void * val){
  int * p = (int *) val;
  printf("%d", * p);
}

int isEmpty(LIST linklist){
  if (linklist->head == NULL && linklist->tail == NULL){
    return 1;
  }
  return 0;
  }

void add(LIST linkedlist, void * item)
{
	node_t * nodeNew = createNode(item);

	if (isEmpty(linkedlist)==1){
		puts("Nothing currently in list, adding now");
		linkedlist->head = nodeNew;
		linkedlist->tail = nodeNew;

		return;
	}

	linkedlist->tail->next = nodeNew;
	nodeNew->prev = linkedlist->tail;
	linkedlist->tail = nodeNew;
}
