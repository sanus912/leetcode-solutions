/*
 * Ex_4_5.h
 *
 *  Created on: Aug 25, 2012
 *      Author: jliu
 */

/*
 * Write an algorithm to find the 'next' node (i.e., in-order successor) of a given node
 * in a binary search tree where each node has a link to its parent.
 */

#include<iostream>
#include<cstdlib>
#include"../My Lib/MyBST.h"
using namespace std;

/*
 * in-order successor: O(n) time
 *
 * this function is based on binary search tree !
 * note that: if this is based on binary tree, un-ordered, "else-part" should be:
 * - find the first parent, that "parent->_left = node;"
 */
template<class T>
TreeNode<T> * nextNode(TreeNode<T> * node) {

	if(!node)
		return NULL;

	TreeNode<T> * next;
    TreeNode<T> * cur;

	if(node->_right) { // if has right, find the smallest node in right subtree
		next = node->_right;
		while(next->_left)
			next = next->_left;
	} else { // if has no right subtree, find the first larger node in parents
		next = node->_parent;
        cur = node;
		while(next && next->_left != cur) { // depends on the tree definition, could be "<="
            cur = next;
			next = next->_parent;
		}
	}

	return next;

}

template<class T>
void in_order_print(TreeNode<T> * root) {
	if (root) {
		if (root->_left)
			in_order_print(root->_left);
		cout << root->_data << " , ";
		if (root->_right)
			in_order_print(root->_right);
	}
}

int main() {
	MyBST<char> *tree = new MyBST<char>();
	char array[10];
	for (int i = 0; i < 10; i++)
		array[i] = char('A' + i);
	tree->addToTree(array, 0, 9);

	cout<<"in-order traversal the tree:"<<endl;
	in_order_print<char>(tree->getRoot());
	cout<<endl;

	for (int i = 0; i < 10; i++) {
		TreeNode<char> * node = nextNode<char>(tree->find('A'+i));
		cout<<char('A'+i)<<"\'s next node is: ";
		if(node)
			cout<<node->_data<<endl;
		else
			cout<<"NULL"<<endl;
	}
    
    return 0;
}

