#include<stdio.h>
#include<stddef.h>
#include<stdlib.h>
#include<assert.h>
#include "slist.h"

Slist slist_new()
{
	Slist s={NULL,NULL,0};
	return s;
}
static Node* slist_new_node(int32_t element)
{
	Node *new_node=(Node*) malloc(sizeof(Node));
	new_node->data=element;
	new_node->next=NULL;
	return new_node;
}
Slist* slist_add_head(Slist *list, int32_t element)
{
	assert(list!= NULL);
	Node *new_node=slist_new_node(element);
	new_node->next=list->head;
	list->head=new_node;
	if(list->tail==NULL){
		list->tail=new_node;
	}
	++list->length;
	assert((list->length==1 && list->head==list->tail) || (list->length > 0 && list->head!=list->tail));
	return list;
}
uint32_t slist_length(const Slist *list)
{
	assert(list!=NULL);
	return list->length;
}
uint32_t slist_lookup(const Slist *list, int32_t key)
{
	assert(list!=NULL);
	Node *cur;
	for(cur=list->head;cur!=NULL;cur=cur->next){
		if(cur->data==key){
			break;
		}
	}
	return(cur!=NULL);	
}
Slist* slist_delete_head(Slist *list)
{
	assert(list!=NULL);
	Node *temp;
	if(list->head!=NULL){
		temp=list->head;
		list->head=list->head->next;
		if(list->head==NULL){
			list->tail=NULL;
		}
		--list->length;
		free(temp);
	}
	return list;
}
Slist* slist_add_tail(Slist *list, int32_t element)
{
	assert(list!=NULL);
	Node *new_node= slist_new_node(element);
	if(list->tail!=NULL){
		list->tail->next=new_node;
		list->tail=new_node;
	}
	else{
		list->tail=list->head=new_node;
	}
	++list->length;
	return list;
}
uint32_t slist_max(const Slist *list)
{
	assert(list!=NULL);
	Node *cur;
	uint32_t max=0;
	for(cur=list->head;cur!=NULL;cur=cur->next){
		if(cur->data>max){
			max=cur->data;
		}
	}
	return max;
}
uint32_t slist_min(const Slist *list)
{
	assert(list!=NULL);
	Node *cur;
	uint32_t min;
	min=list->head->data;
	for(cur=list->head;cur!=NULL;cur=cur->next){
		if(cur->data<min){
			min=cur->data;
		}
	}
	return min;
}	
Slist* slist_add_after_element(Slist *list, int32_t key, int32_t  element)
{
	assert(list!=NULL);
	assert(slist_lookup(list,key));
	Node *cur,*temp;
	temp=slist_new_node(element);
	for(cur=list->head;cur!=NULL;cur=cur->next){
		if(cur->data==key){
			temp->next=cur->next;
			cur->next=temp;
			break;
		}
	}
	++list->length;
	return list;
}
Slist* slist_delete_element(Slist *list, int32_t key)
{
	assert(list!=NULL);
	assert(slist_lookup(list,key));
	Node *cur, *prev;
	for(cur=list->head;cur!=NULL;cur=cur->next){
		if(cur->data==key){
			prev->next=cur->next;
			break;
		}
		prev=cur;
	}
	--list->length;
	return list;
} 
Slist* slist_reverse(Slist *list)
{
	Node *cur;
	Slist r= slist_new();
	Slist *rev= &r;
	for(cur=list->head;cur!=NULL;cur=cur->next){
		rev= slist_add_head(rev,cur->data);
	}
	return rev;
}
uint32_t slist_compare(Slist *list1, Slist *list2)
{
	assert(list1!=NULL);
	assert(list2!=NULL);
	Node *cur1, *cur2;
	int32_t flag=1;

	if(list1->length != list2->length){
		flag=0;
		return flag;
	}
	else{
		cur1=list1->head;
		cur2=list2->head;
		while(cur1!=NULL && cur2!=NULL){
			if(cur1->data!=cur2->data){
				flag=0;
				break;
			}
			cur1=cur1->next;
			cur2=cur2->next;
		}
	}
	return flag;
}
Slist* slist_union(Slist *list1, Slist *list2)
{
	assert(list1!=NULL);
	assert(list2!=NULL);
	Node *cur;
	Slist s= slist_new();
	Slist *list3=&s;
	for(cur=list1->head;cur!=NULL;cur=cur->next){
		if(list3->head==NULL){
			list3= slist_add_head(list3,cur->data);
		} 
		else if(slist_lookup(list3,cur->data)==0){
			slist_add_tail(list3,cur->data);
		}
	}
	for(cur=list2->head;cur!=NULL;cur=cur->next){
		if(slist_lookup(list3,cur->data)==0){
			slist_add_tail(list3,cur->data);
		}
	}
	return list3;
}
Slist* slist_intersection(Slist *list1, Slist *list2)
{
	assert(list1!=NULL);
	assert(list2!=NULL);
	Node *cur;
	Slist s= slist_new();
	Slist *list3=&s;
	for(cur=list1->head;cur!=NULL;cur=cur->next){
		if(slist_lookup(list2,cur->data)==1 && slist_lookup(list3,cur->data)==0){
		slist_add_tail(list3,cur->data);
		}
	}
	return list3;
}
Slist* slist_unique_list(Slist *list, int32_t element)
{
	assert(list!=NULL);
	if(list->head== NULL){
		list=slist_add_head(list, element);
	}
	else{
		if(slist_lookup(list,element)==0){
			list=slist_add_tail(list,element);
		}
		else{
			printf("\n%d is present in the list\n",element);
		}
	}
	return list;
}
 
	
			
