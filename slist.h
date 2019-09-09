#ifndef _INCLUDED_SLIST_
#define _INCLUDED_SLIST_
#include<stdint.h>

typedef struct _node_ Node;
typedef struct _slist_ Slist;

struct _node_{
	int32_t data;
	Node *next;
};

struct _slist_{
	Node *head;
	Node *tail;
	uint32_t length;
};

Slist slist_new();
uint32_t slist_length(const Slist *list);
uint32_t slist_lookup(const Slist *list, int32_t key);
Slist* slist_add_head(Slist *list, int32_t element);
Slist* slist_delete_head(Slist *list);
Slist* slist_add_tail(Slist *list, int32_t element);
Slist* slist_delete_tail(Slist *list);
uint32_t slist_max(const Slist *list);
uint32_t slist_min(const Slist *list);
Slist* slist_add_after_element(Slist *list, int32_t key, int32_t  element);
Slist* slist_delete_element(Slist *list, int32_t key);
Slist* slist_reverse(Slist *list);
uint32_t slist_compare(Slist *list1, Slist *list2);
Slist* slist_union(Slist *list1, Slist *list2);
Slist* slist_intersection(Slist *list1, Slist *list2);
Slist* slist_unique_list(Slist *list, int32_t element);

#endif 
