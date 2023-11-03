#include<iostream>
#include<queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};



class Solution {
public:
    Node* connect(Node* root)
    {
        if (!root)  return nullptr;

        queue<Node*> q;    //使用队列来存当前层的节点
        q.push(root);
        while (!q.empty())
        {
            Node* last = nullptr;

            for (int i = 0; i < q.size(); i++)     //对于每一层，根据上一层的节点数量，弹出上一层节点，然后将上一层节点的左右子节点入队
            {
                Node* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                if (i != 0) last->next = node;     //如果当前节点不是最左节点，填充节点的右侧节点指针
                last = node;                       //将last向右移动       
            }
        }
        return root;
    }

};
