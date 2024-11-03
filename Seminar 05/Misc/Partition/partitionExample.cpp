#include <iostream>

struct Node
{
	int data;
	Node* next = nullptr;
	Node(int value, Node* ptr = nullptr) : data(value), next(ptr) {}
};

void push_back(Node*& begin, Node*& end, Node* toAdd)
{
	if (begin == nullptr)
	{
		begin = end = toAdd;
	}
	else
	{
		end->next = toAdd;
		end = toAdd;
	}
}

template <class PredicateType>
Node* partition(Node* list, const PredicateType& pred)
{
	Node* trueListHead = nullptr;
	Node* trueListTail = nullptr;

	Node* falseListHead = nullptr;
	Node* falseListTail = nullptr;

	while (list != nullptr)
	{
		if (pred(list->data))
			push_back(trueListHead, trueListTail, list);
		else
			push_back(falseListHead, falseListTail, list);
		list = list->next;
	}

	if(falseListTail != nullptr)
    {
		falseListTail->next = nullptr;
    }

	if (trueListTail != nullptr)
	{
		trueListTail->next = falseListHead;
	}

	return trueListHead != nullptr ? trueListHead : falseListHead;
}

void printList(Node* iter)
{
	while (iter)
	{
		std::cout << iter->data;
		if(iter->next)
		   std::cout << " -> ";
		
        iter = iter->next;
	}
}

void freeList(Node* iter)
{
	while (iter)
	{
		Node* toDelete = iter;
		iter = iter->next;
		delete toDelete;
	}
}

int main()
{
	Node* list = new Node{ 3, new Node{4, new Node{5, new Node{6}}} };
	Node* newBegin = partition(list, [](int x) {return x % 2 == 0; });
	printList(newBegin);
	freeList(newBegin);
}