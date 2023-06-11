#include "../../tools.cpp"
#define Node BNode<int> *
// 定义比较器
struct cmp
{
    bool operator()(Node a, Node b)
    {
        return a->val > b->val;
    }
};

//  打印二叉树
void printTree(Node root, int level)
{
    if (root == NULL)
        return;
    printTree(root->right, level + 1);
    for (int i = 0; i < 2 * level; i++)
        cout << "    ";
    cout << root->val << endl;
    printTree(root->left, level + 1);
}

// F: 频率数组
void Huffman(vector<int> F)
{
    priority_queue<Node, vector<Node>, cmp> pq;
    for (int i = 0; i < F.size(); i++)
    {
        Node node = new BNode<int>(F[i]);
        pq.push(node);
    }
    while (pq.size() > 1)
    {
        Node left = pq.top();
        pq.pop();
        Node right = pq.top();
        pq.pop();
        Node node = new BNode<int>(left->val + right->val);
        node->left = left;
        node->right = right;
        pq.push(node);
    }
    Node root = pq.top();
    printTree(root, 0);
}

int main()
{
    vector<int> F = {45, 13, 12, 16, 9, 5};
    Huffman(F);
    return 0;
}