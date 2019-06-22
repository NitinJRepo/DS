//Optimized solution by pushing only right children to the stack.

#include <iostream>
#include <stack>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int data;
	Node *left, *right;
	
    Node(int data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

// Iterative function to perform pre-order traversal of the tree
void preorderIterative(Node *root)
{
	// return if tree is empty
	if (root == nullptr)
		return;

	// create an empty stack and push root node
	stack<Node*> stack;
	stack.push(root);

	// start from root node (set current node to root node)
	Node* curr = root;

	// run till stack is not empty
	while (!stack.empty())
	{
		// if current node is not null, print it and push its right child
		// to the stack and move to its left child
		if (curr != nullptr)
		{
			cout << curr->data << " ";

			if (curr->right)
				stack.push(curr->right);

			curr = curr->left;
		}
		// else if current node is null, we pop a node from the stack
		// set current node to the popped node
		else
		{
			curr = stack.top();
			stack.pop();
		}
	}
}

// main function
int main()
{
	/* Construct below tree
              1
            /   \
           /     \
          2       3
         /      /  \
        /      /    \
       4      5      6
             / \
            /   \
           7     8
	*/
	
	Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->left = new Node(5);
	root->right->right = new Node(6);
	root->right->left->left = new Node(7);
	root->right->left->right = new Node(8);

	preorderIterative(root);

	return 0;
}

//Time complexity: O(n)
//Space complexity: O(n)