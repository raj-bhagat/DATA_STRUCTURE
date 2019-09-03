/*
 *	Author : Deepak
 *	Date   : 23 August 2019 
 *	Specification file for Single Linked List
 *	Contain test cases to test various functionalities
 *	of Single Linked List.
*/
#include <assert.h>
#include<stdio.h>
#include "slist.h"

/* test case to check creation of empty slist variable */
void test_empty_list()
{
	Slist s = slist_new();
	Slist *list = &s;
	assert (slist_length(list) == 0);
}

/*	test case to check adding node from 'head' position
 *	finding length of list and lookup functions
*/
void test_addition_at_head()
{
	int temp;	
	Node *cur;
	Slist s = slist_new();
	Slist *list = &s;
	list = slist_add_head(list, 10);
	assert (slist_length(list) == 1);
	
	list = slist_add_head(list, 20);
	list = slist_add_head(list, 30);
	list = slist_add_head(list, 40);
	list = slist_add_head(list, 50);
	assert (slist_length(list) == 5);
	assert (slist_lookup(list, 30));
	list= slist_add_after_element(list, 30, 60);
	assert (slist_lookup(list, 60));
	assert (slist_length(list) == 6);
	list= slist_delete_element(list, 60);
	for(cur=list->head;cur!=NULL;cur=cur->next){
		printf("%d->",cur->data);
	}

	temp= slist_max(list);
	printf("\nmax value=%d",temp); 
	temp= slist_min(list);
	printf("\nmin value=%d",temp);

	// list2
	Slist s1 = slist_new();
	Slist *list2 = &s1;
	list2 = slist_add_head(list2, 10);
	list2 = slist_add_head(list2, 20);
	list2 = slist_add_head(list2, 30);
	list2 = slist_add_head(list2, 40);
	list2 = slist_add_head(list2, 50);
	if(slist_compare(list, list2)){
		printf("\nLinked list is same\n");
	}
	else{
		printf("\nLinked list is not same\n");
	}
	for(cur=list2->head;cur!=NULL;cur=cur->next){
		printf("%d->",cur->data);
	}

}
int main()
{
	test_empty_list();
	test_addition_at_head();
	
	return 0;
}

/*
 *	Running your programs. Assume that already you have
 *	'slist.h', 'slist.c' and 'slist_spec.c' files.
 *
 *	gcc slist.c slist_spec.c -o slist
 *
 *	If you get errors, fix them. Otherwise you have exe file
 *	with name 'slist' (due to -o slist option used during compilation)
 *	
 *	Running exe file:	./a.out slist
 *	If you don't get any message in terminal, code executed perfectly
 *	( No news good news!!!!!!!)
 *
*/
