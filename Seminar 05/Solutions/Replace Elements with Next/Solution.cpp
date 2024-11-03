int getNumOnIndex(int x, const SinglyLinkedList& sll)
{
    if(x >= sll.size)
        return -1;
    
    Node* head = sll.head;
    int pos = 0;
    
    while(head)
    {
        if(pos == x)
            return head->value;
        
        pos++;
        head = head->next;
    }
    
    return -1;
}

void SinglyLinkedList::replace(int X)
{
    int a = getNumOnIndex(X, *this);

    if(a == -1)
        return;
  
    Node* curr = head;
    while(curr)
    {
        if(curr->value == a && curr->next)
        {
            curr->value = curr->next->value;
        }
        
        curr = curr->next;
    }
}