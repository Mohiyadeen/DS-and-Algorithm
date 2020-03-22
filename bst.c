#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct _bst {
	struct _bst *left;
	int node;
	struct _bst *right;
};

typedef struct _bst bst_node; 

bst_node * root = NULL;

bst_node * insert_bst(bst_node *p, int node) {
	if(p == NULL)
	{
		p = (bst_node *)malloc(sizeof(bst_node));
		memset(p,0x00,sizeof(bst_node));
		p->node = node;
		return p;
	}
	if(p->node > node)
		p->left = insert_bst(p->left, node);
	else if(p->node < node)
		p->right = insert_bst(p->right, node);

	else
		printf("\n Node is already present");

	return p;

}

int height_bst(bst_node *p)
{
	int left=0,right =0;
	if(p == NULL)
		return 0;

	left = height_bst(p->left);
	right = height_bst(p->right);

	if(left > right)
		return left+1;
	else
		return right+1;

}

bst_node * InPre(bst_node * n)
{
	while(n != NULL && n->right != NULL)
		n =n->right;
	return n;
}
bst_node * InSucc(bst_node * n) {
	while(n != NULL && n->left != NULL)
		n= n->left;

	return n;
}

bst_node * delete_bst(bst_node *p, int node) {
	bst_node * temp;
 	if(p == NULL) {
		printf("\n Node is not present");
		return NULL;
	}
	if(p->node == node && p->left == NULL && p->right == NULL)
	{
		if(root == p)
			root = NULL;
		free(p);
		p= NULL;
		return p;
	}

	if(p->node > node)
		p->left = delete_bst(p->left, node);
	else if(p->node < node)
		p->right = delete_bst(p->right, node);
	else {

		if(height_bst(p->left) > height_bst(p->right))
		{
			temp = InPre(p->left);
			p->node = temp->node;
			p->left = delete_bst(p->left, temp->node);
		}
		else {
			temp = InSucc(p->right);
			p->node = temp->node;
			p->right = delete_bst(p->right, temp->node);
		}
		return p;
	}


}
void inorder_traverse(bst_node *p)
{
	if(p!= NULL)
	{
		inorder_traverse(p->left);
		printf(" %d ", p->node);
		inorder_traverse(p->right);
	}
}

int main()
{

	char c = 'n';
	char a = 0;
	int node;
	printf("\n==============BST================");
	do {
		printf("\n 1. INSERT");
		printf("\n 2. DELETE");
		printf("\n 3. DISPLAY");
		printf("\n 4. EXIT");
		printf("\n Please enter choice :\n");
		scanf("%hhd", &a);
		switch(a)
		{
			case 1: 
				{
				printf("\nPlease enter the value to insert");
				scanf("%d",&node);
				root = insert_bst(root, node);
				break;
				}
			case 2:
				{
				printf("\nPlease enter the value to delete");
				scanf("%d",&node);
				root = delete_bst(root, node);
				break;
				}
			case 3:
				{
					inorder_traverse(root);
					break;
				}
			case 4:
			default:
			exit(0);
		}
		printf("\nDo you want to coninue , enter 'y or 'Y'\n");
		scanf(" %c", &c);
	}while(c == 'Y' || c == 'y');

}
