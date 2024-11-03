#include <iostream>

struct Node
{
	int data;
	Node* next = nullptr;
	Node(int value, Node* ptr = nullptr) : data(value), next(ptr) {}
};

Node* merge(Node* first, Node* second)
{
    if (!first)
    {
        return second;
    }

    if (!second)
    {
        return first;
    }
    
    Node* resultHead = nullptr;
    Node* resultCurrent = nullptr;

    if (first->data <= second->data)
    {
        resultHead = resultCurrent = first;
        first = first->next;
    }
    else
    {
        resultHead = resultCurrent = second;
        second = second->next;
    }

    while (first && second)
    {
        if (first->data <= second->data)
        {
            resultCurrent->next = first;
            first = first->next;
        }
        else
        {
            resultCurrent->next = second;
            second = second->next;
        }

        resultCurrent = resultCurrent->next;
    }

    if(first)
    {
        resultCurrent->next = first;
    }

    if(second)
    {
        resultCurrent->next = second;
    }
    
    return resultHead;
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
	Node* list1 = new Node{ 1, new Node{3, new Node{5, new Node{7}}} };
	Node* list2 = new Node{ 2, new Node{4, new Node{6}}};
	Node* mergeResult = merge(list1, list2);

	printList(mergeResult);
	freeList(mergeResult);
}