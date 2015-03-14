#include <stdio.h>
template <class T>
struct ListNode
{
public:
	T* value;
	ListNode* next;

};


template <class T>
class LinkedList
{
public:
	ListNode<T>* root;
	LinkedList()
	{
		printf("%s","hurr\n");
		root=nullptr;
	}
	T* Last()
	{
		return root->value;
	}
	void AddElement (T* e)
	{
		printf("AddElement\n");
		
		
		if (root==nullptr)
		{
			printf("Root is null\n");
			ListNode<T>* newelement;
			newelement->value=e;
			
			root=newelement;
		}
		else

		{

		}
	}
};