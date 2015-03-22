#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <stdio.h>
#include <stdlib.h>
template <class T>
struct ListNode
{
public:
	T* value;
	ListNode<T>* next;

};


template <class T>
class LinkedList
{
private:
	int position;
	ListNode<T>* root;
	ListNode<T>* currentnode;
public:
	int Size()
	{	
		//printf("Size() call\n");
		int r=0;
		//printf ("root=%i\n",root);
		if (root!=nullptr)
		{
			r++;
			ListNode<T>* current=root;
			while (current->next!=nullptr)
			{
				//printf("Size(): iterating...\n");
				current=current->next;
				r++;
			}
		}
		printf ("%i\n",r);
		return r;
	}

	LinkedList()
	{
		//printf("%s","hurr\n");
		root=nullptr;
		currentnode=nullptr;
	}
T* Next()
{
	//printf("Next()\n");
	//printf("currentnode=%i",currentnode);
	if (currentnode==nullptr)
	{
		currentnode=root;
		//printf ("currentnode is null, returning root\n");
	}
	else

	{
		currentnode=currentnode->next;
	}

	//printf ("address of currentnode to be returned:%i\n",currentnode);

	T* retval=currentnode->value;
	if (currentnode->next==nullptr)
	{
		currentnode=nullptr;
	}
	return retval;
}
	void AddElement (T* e)
	{
		printf("AddElement\n");
		
		
		if (root==nullptr)
		{
			printf("Root is null\n");
			root=new ListNode<T>;
			root->value=e;
			root->next=nullptr;
		}
		else

		{
			ListNode<T>* current=root;
		//	printf("current=%i, root=%i\n", current,root);
			while (current->next!=nullptr)
			{

				/*printf("Root's next: %î\n", root->next);
				printf("Current's next: %i\n", current->next);
				
				printf("iterating...\n");*/
				current=current->next;
			}
			current->next=new ListNode<T>;
			current->next->value=e;
			current->next->next=nullptr;
			
		}
	}
};

#endif