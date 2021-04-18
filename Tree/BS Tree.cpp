#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node *root;

void init()
{
    root = NULL;
}

Node *Insert(Node *root,int val)
{
    if(root==NULL)
    {
        root = new Node();
        root->data = val;
        root->left = root->right = NULL;
    }

    else if(val <= root->data)
    {
        root->left = Insert(root->left,val);
    }

    else
    {
        root->right = Insert(root->right,val);
    }
    return root;
}

bool Search(Node *root,int val)
{
    if(root == NULL)
        return false;

    else if(root->data == val)
        return true;

    else if(val <= root->data)
    {
        return Search(root->left,val);
    }

    else
    {
        return Search(root->right,val);
    }
}

void preorder(Node *root)
{
    if(root == NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if(root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

void inorder(Node *root)
{
    if(root == NULL)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void LevelOrder(Node *root)
{
    if(root == NULL)
    {
        return;
    }

    queue<Node*>q;

    q.push(root);

    while(!q.empty())
    {
        Node *current = q.front();
        q.pop();
        cout<<current->data<<" ";

        if(current->left != NULL)q.push(current->left);
        if(current->right != NULL)q.push(current->right);
    }
    cout<<endl;
}

int FindMin(Node *root)
{
    if(root == NULL)
    {
        cout<<"Tree is Empty\n";
        return 0;
    }
    else if(root->left == NULL)
    {
        return root->data;
    }

    return FindMin(root->left);

    /*while(root->left != NULL)
    {
        root = root->left;
    }

    return root;*/
}

int FindMax(Node *root)
{
    if(root == NULL)
    {
        cout<<"Tree is Empty\n";
        return 0;
    }
    else if(root->right == NULL)
    {
        return root->data;
    }

    return FindMax(root->right);

    /*while(root->right != NULL)
    {
        root = root->right;
    }

    return root;*/
}

int FindHeight(Node *root)
{
    if(root == NULL)
        return -1;

    return max(FindHeight(root->left),FindHeight(root->right))+1;
}

bool IsBstUtil(Node *root,int minValue,int maxValue)
{
    if(root == NULL)return true;

    if(root->data<minValue && root->data>maxValue && IsBstUtil(root->left,minValue,root->data) && IsBstUtil(root->right,root->data,maxValue))
    {
        return true;
    }

    else
    {
        return false;
    }
}

bool IsBinarySearchTree(Node *root)
{
    return IsBstUtil(root,INT_MIN,INT_MAX);
}

Node* FindMinNode(Node* root)
{
    if(root == NULL)return NULL;

	while(root->left != NULL)
        root = root->left;
	return root;
}


Node *Delete(Node *root,int data)
{
    if(root == NULL)return root;
    else if(data < root->data)root->left = Delete(root->left,data);
    else if(data > root->data)root->right = Delete(root->right,data);
    else
    {
        if(root->left == NULL && root->right == NULL)
        {
            delete root;
            root = NULL;
        }

        else if(root->left == NULL)
        {
            Node *temp = root;
            root = root->right;
            delete temp;
        }
        else if(root->right == NULL)
        {
            Node *temp = root;
            root = root->left;
            delete temp;
        }
        else
        {
            Node *temp = FindMinNode(root->right);
            root->data = temp->data;
            root->right = Delete(root->right,temp->data);
        }
    }
    return root;
}

Node *Find(Node *root,int data)
{
    if(root == NULL)return NULL;
    else if(root->data == data)return root;
    else if(root->data < data)return Find(root->right,data);
    else return Find(root->left,data);
}

Node *Getsuccessor(Node *root,int data)
{
    Node *current = Find(root,data);
    if(current == NULL)return NULL;

    if(current->right != NULL)return FindMinNode(current->right);

    else
    {
        Node *successor = NULL;
        Node *ancestor = root;

        while(ancestor != current)
        {
            if(current->data < ancestor->data)
            {
                successor = ancestor;
                ancestor = ancestor->left;
            }
            else
            {
                ancestor = ancestor->right;
            }
        }
        return successor;
    }
}

int main()
{
    init();
    cout<<"1.Insert"<<endl;
    cout<<"2.Search"<<endl;
    cout<<"3.Pre-order"<<endl;
    cout<<"4.Post-order"<<endl;
    cout<<"5.In-order"<<endl;
    cout<<"6.Level-Order"<<endl;
    cout<<"7.Find Max"<<endl;
    cout<<"8.Find Min"<<endl;
    cout<<"9.Find Height"<<endl;
    cout<<"10.Is a Binary Search Tree"<<endl;
    cout<<"11.Delete Node"<<endl;
    cout<<"12.Find Successor"<<endl;

    while(1)
    {
        int op;
        cin>>op;

        if(op==1)
        {
            int val;
            cin>>val;
            root = Insert(root,val);
        }
        else if(op==2)
        {
            int val;
            cin>>val;

            if(Search(root,val))
                cout<<"Found\n";
            else
                cout<<"Not Found\n";
        }
        else if(op==3)
        {
            preorder(root);
        }
        else if(op==4)
        {
            postorder(root);
        }
        else if(op==5)
        {
            inorder(root);
        }
        else if(op==6)
        {
            LevelOrder(root);
        }
        else if(op==7)
        {
            int r = FindMax(root);
            cout<<r<<endl;
        }
        else if(op==8)
        {
            int r = FindMin(root);
            cout<<r<<endl;
        }
        else if(op==9)
        {
            int r = FindHeight(root);
            cout<<r<<endl;
        }
        else if(op==10)
        {
            if(IsBinarySearchTree(root))
            {
                cout<<"Tree is a Binary Search Tree"<<endl;
            }
            else
            {
                cout<<"Tree is not a Binary Search Tree"<<endl;
            }
        }
        else if(op==11)
        {
            int val;
            cin>>val;
            Delete(root,val);
        }
        else if(op==12)
        {
            int val;
            cin>>val;
            Node *successor = Getsuccessor(root,val);

            if(successor == NULL)cout<<"No Successor Found\n";

            else
            {
                cout<<"Successor is "<<successor->data<<endl;
            }
        }
        else
        {
            break;
        }
    }
    return 0;
}
