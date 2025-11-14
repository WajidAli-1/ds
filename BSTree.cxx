#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node * left;
	Node * right;
	Node(){
		data=0;
		left=NULL;
		right=NULL;
		}
	
	};
class BSTree{
	public:
	Node * root;
	BSTree(){
		root=NULL;
		}
	void insert(int value)
	{
		Node *n= new Node();
		n->data=value;
		if(root==NULL) // first node
		{
	        root=n;
	    	return;
		}
		
		Node * t=root;
		while(true)
		{
		if(value < t->data)
		{
			if(t->right == NULL)
			{
				t->right=n; 
				break;
			}
			else
		    	t=t->right;
		}
		else
		{
			if(t->left == NULL)
			{
				t->left=n; 
				break;
			}
			else
            t=t->left;
		}
		}
		}
	void display()
	{
			Node*t=root;
		   cout<<"\npreorder traversal is:\n";
			preorder(t);
		   cout<<"\ninorder traversal is:\n";
			inorder(t);
		   cout<<"\npostorder traversal is:\n";
			postorder(t);
			
	}
	void preorder(Node *t){
				if(t==NULL) return;
				cout<<"\t"<<t->data;
				preorder(t->right);
				preorder(t->left);
	}
	void inorder(Node *t){
				if(t==NULL) return;
		
				inorder(t->right);
				cout<<"\t"<<t->data;
				inorder(t->left);
	}
	void postorder(Node *t){
				if(t==NULL) return;
				postorder(t->right);
				postorder(t->left);
				cout<<"\t"<<t->data;
		
	}
	int count(Node * t){
		if(t==NULL) return 0;
		int c1=count(t->right);
		int c2=count(t->left);
		return 1+c1+c2;
	}
		int height(Node * t){
		if(t==NULL) return -1;
		int h1=height(t->right);
		int h2=height(t->left);
		return 1+max(h1,h2);
	}
		int countleaf(Node * t){
		if(t==NULL) return 0;
		if(t->right==NULL && t->left==NULL)
		return 1;
		int c1=countleaf(t->right);
		int c2=countleaf(t->left);
		return c1+c2;
	}
		int countnonleaf(Node * t){
		if(t==NULL) return 0;
		
		if(t->right!=NULL || t->left!=NULL)
		return 1;
		int c1=countnonleaf(t->right);
		int c2=countnonleaf(t->left);
		return c1+c2;
	}
		int counteven(Node * t){
		if(t==NULL) return 0;
	    cout<<"\nVisiting : "<<t->data;
		if(t->data% 2== 0){
			   	cout<<"\t"<<t->data;
					return 1;
		}
		int c1=counteven(t->right);
		int c2=counteven(t->left);
		return c1+c2;
	}
			
			
	};

int main()
{
	BSTree t1;
	t1.insert(5);
	t1.insert(3);
	t1.insert(6);
	t1.insert(16);
	t1.insert(1);
		t1.insert(7);
	t1.insert(17);
		t1.insert(2);
	t1.display();
	Node * t= t1.root;
//cout<<"\nNo of nodes in BST\n"<<t1.count(t);
 //cout<<"\nNo of leaf nodes in BST\n"<<t1.countleaf(t);
//  cout<<"\nNo of non leaf nodes in BST\n"<<t1.countnonleaf(t);
//	cout<<"\nHeight of BST\n"<<t1.height(t);
  cout<<"\nNo of even nodes in BST\n"<<t1.counteven(t);
	
	
}