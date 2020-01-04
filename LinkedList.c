#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct _node_t *node_t;
struct _node_t{
	int val;
	node_t pred, succ;
};

typedef struct _list_t *list_t;
struct _list_t{
	node_t head, tail;
}

list_t make_list(){
	list_t list=malloc(sizeof(struct _list_t));
	list->head=list->tail=NULL;
	return list;
}
void destroy_list(list_t list){
	node_t curr, next;
	for(curr = list->head; curr !=null; curr = next){
		next=curr->succ; free (curr);}
	free(list);
	}
}
node_t list_add(list_t list, int value){
	node_t new_node = malloc(sizeof(struct _node_t));
	new_node->val = value;
	new_node->succ = NULL;
	new_node->pred=list->tail;
	if(list->tail){
		list->tail->succ=new_node;
	}else{
		list->head=new_node;
	}
	list->tail=new_node;
	return new_node;
}
void delete(list_t list, node_t node){
	if(node == list->head)
		list->head=node->succ;
	else
		node->pred->succ = node->succ;
	if(node == list->tail)
		list->tail=node->pred;
	else
		node->succ->pred=node->pred;
	free(node);
}
void *node_value(node_t node){
	return node->val;	
}
node_t list_head(list_t list){
	return list->head;
}
node_t node_succ(node_t node){
	node_t temp;
	if(node->succ != NULL){
		temp=node->succ;
	}else{
		temp=NULL;
	}
	return temp;
}
