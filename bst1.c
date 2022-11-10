//						Binary Seach Tree
#include<stdio.h>
#include<stdlib.h>

typedef struct tree{
	int data;
	struct tree *left;
	struct tree *right;
}node;

node *insert(node *root, int d){
	node *neo=(node*)malloc(sizeof(node));
	neo->data=d;
	neo->left=NULL;
	neo->right=NULL;
	if(root==NULL)
		root=neo;
	else if(d<root->data)
		root->left=insert(root->left,d);
	else
		root->right=insert(root->right,d);
	return root;
}

node *binary_search(node *root, int key){
	if(root==NULL)
		return NULL;
	else if(key<root->data)
		return binary_search(root->left,key);
	else if(key>root->data)
		return binary_search(root->right,key);
	else
		return root;
}

void inorder_print(node *root){
	if(root==NULL)
		return;
	inorder_print(root->left);
	printf("%d ",root->data);
	inorder_print(root->right);
}
/*
node *inorder_successor(node *root){
	node *curr=root;
	while(curr && curr->left!=NULL)
		curr=curr->left;
	return curr;
}
*/
node *delete_node(node *root, int key){
	node *temp;
	if(root==NULL)
		return NULL;
	if(key<root->data)
		root->left=delete_node(root->left,key);
	else if(key>root->data)
		root->right=delete_node(root->right,key);
	else{
		if(root->left==NULL)				//For no child
			root=root->right;
		else if(root->right==NULL)			//For one child
			root=root->left;
		else{								//For two child
			temp=root->right;				//Using Inorder Successor
			while(temp && temp->left!=NULL)
				temp=temp->left;
			root->data=temp->data;
			root->right=delete_node(root->right,root->data);
		}
	}
	return root;
}
int main(){
	node *root=NULL;
	int t,d,ct=0;
	printf("Enter how much value to insert in binary seach tree = ");
	scanf("%d",&t);
	while(t--){
		//printf("Enter the %d element = ",++ct);
		scanf("%d",&d);
		root=insert(root,d);
	}
	inorder_print(root);
	printf("\n");
	printf("Enter the key value to search = ");
	scanf("%d",&d);
	//((binary_search(root,d)->data)==d)?printf("True\n"):printf("False\n");
	root=delete_node(root,d);
	inorder_print(root);
}
