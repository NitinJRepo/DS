#include<stdio.h>
#include<stdlib.h>

typedef struct node1
{
	int data;
	struct node1 *left;
	struct node1 *right;
}node;

int nod=0,leaf=0;

int menu()
{
	int ch;
	printf("\n 0 : QUIT");
	printf("\n 1 : INSERT NODE");
	printf("\n 2 : PRE-ORDER TRAVERSE");
	printf("\n 3 : IN-ORDER TRAVERSE");
	printf("\n 4 : POST-ORDER TRAVERSE");
	printf("\n 5 : DELETE NODE");
	printf("\n 6 : DISPLAY NO. OF NODE");
	printf("\n 7 : DISPLAY NO. OF LEAF");
	printf("\n ENTER YOUR CHIOICE ");
	scanf("%d",&ch);
	return ch;
}

node *insert(node *p,int n)
{
       if(p==NULL)
       {
	       p=(node*) malloc (sizeof(node));
	       p->left=NULL;
	       p->right=NULL;
	       p->data=n;
       }

       else if(n<p->data)
       p->left=insert(p->left,n);
       else if(n>p->data)
       p->right=insert(p->right,n);
       else if(n==p->data)
       {
		printf("\n duplicate node");
       }
       return p;
}

void preorder(node *p)
{
	if(p!=NULL)
	{
		printf("%d\t",p->data);
		preorder(p->left);
		preorder(p->right);
	}
}

void inorder(node *p)
{
	if(p!=NULL)
	{
		inorder(p->left);
		printf("%d\t",p->data);
		inorder(p->right);
	}
}

void postorder(node *p)
{
	if(p!=NULL)
	{
		postorder(p->left);
		postorder(p->right);
		printf("%d\t",p->data);
	}
}

void countnode(node *p)
{
	if(p!=NULL)
	{
		nod++;
		if(p->left!=NULL)
			countnode(p->left);

		if(p->right!=NULL)
			countnode(p->right);
	}

}


/* Given a non-empty binary search tree, return the node with minimum
   data value found in that tree. Note that the entire tree does not
   need to be searched. */
node* minValueNode(node *root)
{
    node *p = root;
 
    /* loop down to find the leftmost leaf */
    while (p->left != NULL)
        p = p->left;
 
    return p;
}
 
//Given a binary search tree and a data, this function deletes the data and returns the new root 
/* node* deleteNode(node* root, int data)
{
    // base case
    if (root == NULL) return root;
 
    // If the data to be deleted is smaller than the root's data,
    // then it lies in left subtree
    if (data < root->data)
        root->left = deleteNode(root->left, data);
 
    // If the data to be deleted is greater than the root's data,
    // then it lies in right subtree
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
 
    // if data is same as root's data, then This is the node
    // to be deleted
    else
    {
        // node with only one child or no child
        if (root->left == NULL)
        {
            node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            node *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        node* temp = minValueNode(root->right);
 
        // Copy the inorder successor's content to this node
        root->data = temp->data;
 
        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

*/

node* deleteNode(node *root, int data)
{
	if(root == NULL) 
		return root;

	else if(data < root->data) 
		root->left = deleteNode(root->left,data);

	else if (data > root->data) 
		root->right = deleteNode(root->right,data);
	
	// if data is same as root's data, then This is the node to be deleted
	else
	{   
		//Case 1: No child
		if(root->left == NULL && root->right == NULL)	
		{
			free(root);
			root = NULL;
		}
		//Case 2: One child
		else if(root->left == NULL)		
		{
			node *temp = root;
			root= root->right;
			free(temp);
		}
		else if(root->right == NULL)
		{
			node *temp = root;
			root = root->left;
			free(temp);
		}	
		//case 3: Two children											
		else				
		{
			//Get the inorder successor (smallest in the right subtree)
			node *temp = minValueNode(root->right);
			// Copy the inorder successor's content to this node
			root->data = temp->data;
			// Delete the inorder successor
			root->right = deleteNode(root->right,temp->data);
		}
	}
	return root; 
}

void countleaf(node *p)
{
	if(p!=NULL)
	{
		if((p->left==NULL)&&(p->right==NULL))
		leaf++;
		else
		countleaf(p->left);
		countleaf(p->right);
	}
}

int main()
{
	int ch,n;
	node *root;
	root=NULL;
	
	while(ch=menu())
	{
		switch(ch)
		{
			case 0: 
					return 0;
			case 1: 
					printf("\n enter data");
					scanf("%d",&n);
					root=insert(root,n);
					break;
			case 2:	
					preorder(root);
					break;
			case 3:	
					inorder(root);
					break;
			case 4:	
					postorder(root);
					break;
			case 5:	
					printf("\n enter data to be deleted ");
					scanf("%d",&n);
					root = deleteNode(root, n);
					break; 
			case 6:	
					countnode(root);
					printf("\n TOTAL NODES= %d",nod);
					nod=0;
					break;
			case 7: 
					countleaf(root);
					printf("\n TOTAL LEAVES=%d",leaf);
					leaf=0;
					break;
			default:
					printf("\n WRONG CHOICE");
					break;
		}
	}
}
