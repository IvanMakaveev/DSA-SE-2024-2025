#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int currId;
    Node* left = nullptr;
    Node* right = nullptr;
};

vector<Node*> nodes(1e6);

void print(Node* root)
{
    if(root != nullptr)
    {
        print(root->left);
        cout << root->currId << ' ';        
        print(root->right);
    }
}

int fillPaints(Node* root, int& paints)
{
    if(root == nullptr)
    {
        return -1;
    }
    
    if(root->left == nullptr && root->right == nullptr)
    {
        return -2;
    }
    
    
    int leftPaint = fillPaints(root->left, paints);
    int rightPaint = fillPaints(root->right, paints);

    if(leftPaint == -2 || rightPaint == -2)
    {
        paints++;
        return 0;
    }
    
    if(leftPaint == 0 || rightPaint == 0)
    {
        return -1;
    }
    
    return -2;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int verts = 0;
    cin >> verts;
    
    for(int i = 0; i < verts; i++)
    {
        nodes[i] = new Node();
        nodes[i]->currId = i;
    }
    
    for(int i = 0; i < verts; i++)
    {
        int left, right;
        cin >> left >> right;
        
        if (left != -1)
        {
            nodes[i]->left = nodes[left];
        }
        if(right != -1)
        {
            nodes[i]->right = nodes[right];
        }
    }
    
    int paints = 0;
    fillPaints(nodes[0], paints);
    cout << paints;
}