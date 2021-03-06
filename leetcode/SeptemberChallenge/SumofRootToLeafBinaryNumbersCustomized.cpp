#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*
Given a binary tree, each node has value 0 or 1.  Each root-to-leaf path represents a binary number starting with the most significant bit.  For example, if the path is 0 -> 1 -> 1 -> 0 -> 1, then this could represent 01101 in binary, which is 13.

For all leaves in the tree, consider the numbers represented by the path from the root to that leaf.

Return the sum of these numbers.

 

Example 1:



Input: [1,0,1,0,1,0,1]
Output: 22
Explanation: (100) + (101) + (110) + (111) = 4 + 5 + 6 + 7 = 22*/


/*Note:

The number of nodes in the tree is between 1 and 1000.
node.val is 0 or 1.
The answer will not exceed 2^31 - 1.*/



  // Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
 
  	void getNum(TreeNode *root,int a, int &sum)
  	{
  		if(root==NULL)
  		{
  			return;
  		}
  		a*=2;
  		a+=root->val;
  		if(root->left ==NULL and root->right==NULL)
  		{
  			sum+=a;
  			return;
  		}
  		getNum(root->left,a,sum);
  		getNum(root->right,a,sum);
  	}

    int sumRootToLeaf(TreeNode* root) {

    	 int sum=0;
    	getNum(root,0,sum);
    	return sum;
    	
        
        
    }


int main()
{
	
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(0);
	root->right = new TreeNode(1);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(1);
	root->right->left = new TreeNode(0);
	root->right->right = new TreeNode(1);
	cout << sumRootToLeaf(root);
	return 0;
}