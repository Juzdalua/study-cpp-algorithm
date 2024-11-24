#include <bits/stdc++.h>
using namespace std;

/*
    1. 후위 순회
postorder( node )
    if (node.visited == false)
        postorder( node->left )
        postorder( node->right )
        node.visited = true

    2. 전위 순회
preorder( node )
    if (node.visited == false)
        node.visited = true
        preorder( node->left )
        preorder( node->right )

    3. 중위 순회
inorder( node )
    if (node.visited == false)
        inorder( node->left )
        node.visited = true
        inorder( node->right )

*/
vector<int> adj[1004];
int visited[1004];

void postOrder(int here)
{
    if (visited[here] == 0)
    {
        if (adj[here].size() == 1)
            postOrder(adj[here][0]);
        if (adj[here].size() == 2)
        {
            postOrder(adj[here][0]);
            postOrder(adj[here][1]);
        }
        visited[here] = 1;
        cout << here << ' ';
    }
}
void preOrder(int here)
{
    if (visited[here] == 0)
    {
        visited[here] = 1;
        cout << here << ' ';
        if (adj[here].size() == 1)
            preOrder(adj[here][0]);
        if (adj[here].size() == 2)
        {
            preOrder(adj[here][0]);
            preOrder(adj[here][1]);
        }
    }
}
void inOrder(int here)
{
    if (visited[here] == 0)
    {
        if (adj[here].size() == 1)
        {
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << ' ';
        }
        else if (adj[here].size() == 2)
        {
            inOrder(adj[here][0]);
            visited[here] = 1;
            cout << here << ' ';
            inOrder(adj[here][1]);
        }
        else
        {
            visited[here] = 1;
            cout << here << ' ';
        }
    }
}

int main()
{
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(4);
    adj[2].push_back(5);

    int root = 1;
    cout << "\n 트리순회 : postOrder \n";
    postOrder(root);

    memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : preOrder \n";
    preOrder(root);

    memset(visited, 0, sizeof(visited));
    cout << "\n 트리순회 : inOrder \n";
    inOrder(root);

    return 0;
}