#include "Tree.h"
#include <iostream>
using namespace std;

void Tree::Insert(int[] arr, int data) //
{
	bool done = false;
	Node* temp = mp_root;
	while(!done)
	{
		if(mp_root == nullptr)
		{
			mp_root = new Node(data);
			
		}
		if(temp->data < data)
		{
			temp->left = new Node(data);
		}
		if(temp->data > data)
		{
			temp->right = new Node(data);
		}	
	}
}

//===============================================================
Node* Tree::Search(int data) //search the data in tree
{
    Node* temp = mp_root;
    bool done = false;

    while(!done)
    {
    	if(temp->data < data)
    	{
    	    temp = temp->mp_left;
    	}
    	else if (temp->data > data)
    	{
    	    temp = temp->mp_right;
    	}
    	if(temp->data == data)
    	{
    		return temp;
		}
	}
}

//===============================================================
Node* Tree::Search_Del(int data)
{
	Node* temp = mp_root;
    bool done = false;
	Node* temp_before;
	
    while(!done)
    {
    	if(temp->data < data)
    	{
    		temp_before = temp;
    	    temp = temp->mp_left;
    	}
    	else if (temp->data > data)
    	{
    		temp_before = temp;
    	    temp = temp->mp_right;
    	}
    	if(temp->data == data)
    	{
    		return temp_before;
		}
	}
}
//===============================================================
void Tree::Delete(int data) // delete node in tree
{
	Node* temp = Search(data);
	//node has no children
	if(temp->left == nullptr && temp->right == nullptr)
	{
		delete temp;
	}
	//node has one child
	else if(temp->left == nullptr || temp->right == nullptr)
	{
		
		/*
		please redo the one child
		p.right/left = p.right->lef/right 
		*/
		//node has one child on the right
		Node* temp_one_child = Search_Del(data);
		if((temp_one_child->left)->data == data)
		{
			Node* save_replace = (temp_one_child->left)->right;
			delete temp_one_child->left;
			temp_one_child->left = save_replace;			
		}
		//node has one child on the left
		if((temp_one_child->right)->data == data)
		{
			Node* save_replace = (temp_one_child->right)->left;
			delete temp_one_child->right;
			temp_one_child->right = save_replace;			
		}
	}
	//node has two children
	else if(temp->left != nullptr && temp->right != nullptr)
	{
		Node* temp_two_child = Search_Del(data);
		temp_two_child = findmin(temp);
		
	}
}

//===============================================================
void Tree::Traverse(Node* root)
{

	Stack add;	//stack that keeps the address
	Node* p_current_node = root;	//node points to root
	bool end = false;
	
	while(end == false)
	{
		if(p_current_node != 0)	//if node does not point to null
		{
			add.push(p_current_node);	//keeps the address of the node
			p_current_node = p_current_node->left;	//left traverse

		}
		else	//if current pointer points to null
		{
			p_current_node = add.top();		//takes the first element in the stack
			add.pop();	// remove the element adress in the stack
			cout << p_current_node->data << " ";  	//display data
			p_current_node = popped_item->right;	//right traverse
			
			if(p_current_node == 0 && add.isempty())
			{
				end = true;
			}
		}
	}
}

//===============================================================
Node* Tree::findmax(Node* temp)
{
    bool done = false;
    Node* temp = mp_root;
	Node* temp_prev = temp;   
	
	while(!done)
    {
		if(temp->right == nullptr)
		{
			temp_prev = nullptr;
			return temp;
		}
		temp_prev = temp;
		temp = temp->right;
	}
}

//===============================================================
Node* Tree::findmin(Node* temp)
{
    bool done = false;
    Node* temp = mp_root;
    Node* temp_prev;

	while(!done)
    {
		if(temp->left == nullptr)
		{
			temp_prev = nullptr;
			return temp;
		}
		temp_prev = temp
		temp = temp->left;
	}
}

//===============================================================
bool Tree::IsEmpty(Node* p) // for insert
{
    if(p == nullptr)
    {
    	return true;
	}
	else
	{
		return false;
	}
}
