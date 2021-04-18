#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node *create_node(int item)
{
    Node *new_node = new Node();

    new_node->data = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void add_left(Node *node,Node *child)
{
    node->left = child;
}

void add_right(Node *node,Node *child)
{
    node->right = child;
}

Node *create_tree()
{
    Node *two = create_node(2);
    Node *seven = create_node(7);
    Node *nine = create_node(9);
    Node *one = create_node(1);
    Node *six = create_node(6);
    Node *five = create_node(5);
    Node *ten = create_node(10);
    Node *eight = create_node(8);
    Node *three = create_node(3);
    Node *four = create_node(4);

    add_left(two,seven);
    add_right(two,nine);

    add_left(seven,one);
    add_right(seven,six);

    add_left(six,five);
    add_right(six,ten);

    add_right(nine,eight);

    add_left(eight,three);
    add_right(eight,four);

    return two;
}

void pre_order(Node *node)
{
    cout<<node->data<<" ";

    if(node->left != NULL)
    {
        pre_order(node->left);
    }

    if(node->right != NULL)
    {
        pre_order(node->right);
    }
}

void post_order(Node *node)
{
    if(node->left != NULL)
    {
        post_order(node->left);
    }

    if(node->right != NULL)
    {
        post_order(node->right);
    }

    cout<<node->data<<" ";
}

void in_order(Node *node)
{
    if(node->left != NULL)
    {
        in_order(node->left);
    }

    cout<<node->data<<" ";

    if(node->right != NULL)
    {
        in_order(node->right);
    }
}

int main()
{
    Node *root = create_tree();

    cout<<"Pre-Order: ";
    pre_order(root);
    cout<<endl;

    cout<<"Post-Order: ";
    post_order(root);
    cout<<endl;

    cout<<"In-Order: ";
    in_order(root);
    cout<<endl;

    /*cout<<root->data<<endl;
    cout<<root->left->data<<endl;
    cout<<root->right->data<<endl;*/

    return 0;
}
