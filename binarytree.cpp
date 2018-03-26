#include <iostream>
using namespace std;

class bst{
struct node{
	int data;
	node *left;
	node *right;

	};
node *root;
node *insert(int x,node *t)
{
   if (t==NULL)
	{
	  t=new node;
	  t->data=x;
	  t->left=t->right=NULL;
	}
      else if(x<t->data)
		t->left=insert(x,t->left);
      else if(x>t->data)
		t->right=insert(x,t->right);
	return t;
}
node * findmin(node *t)
{
	if(t==NULL)
	  return NULL;
	else if(t->left==NULL)
	  return t;
	else 
	  return findmin(t->left);
}
node * findmax(node *t)
{
	if(t==NULL)
	  return NULL;
	else if(t->right)
	  return t;
	else
	  return findmax(t->right);
}
node *remove(int x,node *t)
{
	node *temp;
	if(t==NULL)
	  return NULL;
	else if(x<t->data)
	   t->left=remove(x,t->left);
	else if(x>t->data)
	   t->right=remove(x,t->right);
	else if(t->left && t->right){
		temp=findmin(t->right);
		t->data=temp->data;
		t->right=remove(t->data,t->right);
	}
	else {
		temp=t;
		if(t->left==NULL)
		  t=t->right;
		else if(t->right==NULL)
		  t=t->left;
		delete temp;
	      }
    	    return t;
}
void inorder(node *t){
	if (t==NULL)
	   return;
	inorder(t->left);
	cout<<t->data<<" ";
	inorder(t->right);


}
node *find(node *t,int x)
{
	if(t==NULL)
	 return NULL;
	else if(x<t->data)
	 return find(t->left,x);
	else if(x>t->data)
	 return find(t->right,x);
	else 
	   return t;
}
public:
    bst()
     {
     root=NULL;
	}
   void insert(int x)
{
     root=insert(x,root);
}
    void remove(int x)
{
	root=remove(x,root);
}
void display()
{
	inorder(root);
	cout<<endl;
}
void search(int x)
{
	root=find(root,x);
}

};

int main()
{
bst t;
t.insert(52);
t.insert(25);
t.insert(40);
t.insert(45);
t.insert(33);
t.display();
t.remove(33);
t.display();





}
