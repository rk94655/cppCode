#include<iostream>
#include<queue>
#include<climits>
using namespace std;
// template<typename T>
class node{
public:
	int data;
	node*left;
	node*right;
	node(int d)
	{
		data=d;
		left=NULL;
		right=NULL;
	}
};
node * buildBSTTree(node *root, int data)
{
	if(root==NULL)
		return new node(data);
	// node * res;
	if(data<=root->data)
	{
		root->left = buildBSTTree(root->left,data);
	}
	else
	{
		root->right = buildBSTTree(root->right,data);
	}
	return root;
}

node* buildBST()
{
	int d;
	cin>>d;
	node * root=NULL;
	while(d!=-1)
	{
		root = buildBSTTree(root,d);
		cin>>d;
	}
	return root;

}

void inOrderPrint(node *root)
{
	if(root==NULL)
		return;
	inOrderPrint(root->left);
	cout << root->data << ",";
	inOrderPrint(root->right);
}
void BFSwithNewLine(node *root)
{
	queue<node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		node * f = q.front();
		if(f==NULL)
		{
			cout << endl;
			q.pop();
			if(!q.empty())
				q.push(NULL);
		}
		else{
			cout << f->data << " ";
			q.pop();
if(f->left!=NULL)
			q.push(f->left);
		if(f->right!=NULL)
			q.push(f->right);
		}


	}
}

bool isBST(node *root, int minV=INT_MIN, int maxV = INT_MAX)
{
	if(root==NULL)
		return true;
	if(root->data>=minV and root->data <= maxV and isBST(root->left, minV, root->data) and isBST(root->right, root->data,maxV))
		return true;
	else 
		return false;
}
int main()
{
	node *root = buildBST();
	BFSwithNewLine(root);
	if(isBST(root))
		cout << "Yes it is BST";
	else
		cout << "No it is not a BST";
	return 0;
}