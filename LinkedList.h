#ifndef LinkedList.h
#define LinkedList.h

typedef struct _node_t *node_t;
struct _node_t;

typedef struct _list_t *list_t;
struct _list_t;

list_t make_list();
void destroy_list(list_t list);
node_t list_t add(list_t list, int value);
void delete(list_t list, node_t node);
void *node_value(node_t node);
node_t list_Head(list_t list);
node_t node_succ(node_t node);

#endif /* linkedList.h */
