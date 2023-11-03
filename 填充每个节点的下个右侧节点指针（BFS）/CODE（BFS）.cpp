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

        queue<Node*> q;    //ʹ�ö������浱ǰ��Ľڵ�
        q.push(root);
        while (!q.empty())
        {
            Node* last = nullptr;

            for (int i = 0; i < q.size(); i++)     //����ÿһ�㣬������һ��Ľڵ�������������һ��ڵ㣬Ȼ����һ��ڵ�������ӽڵ����
            {
                Node* node = q.front();
                q.pop();
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);

                if (i != 0) last->next = node;     //�����ǰ�ڵ㲻������ڵ㣬���ڵ���Ҳ�ڵ�ָ��
                last = node;                       //��last�����ƶ�       
            }
        }
        return root;
    }

};
