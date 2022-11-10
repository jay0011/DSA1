//Queue operation using 2 stacks by linked list implementation
#include<stdio.h>
#include<stdlib.h>
typedef struct Stack{
	int data;
	struct Stack *link;
}node;
node *push(node *head,int d){
	node *neo=(node*)malloc(sizeof(node));
	neo->data=d;
	neo->link=NULL;
	if(head==NULL)
		head=neo;
	else{
		neo->link=head;
		head=neo;
	}
	return head;
}
int top(node *head){
	return head->data;
}
node *pop(node *head){
	if(head==NULL)
		return NULL;
	head=head->link;
	return head;
}
node *delque(node *head1, node *head2){
	int t;
	if(head1==NULL)
		return NULL;
	else{
		while(head1!=NULL){
			t=top(head1);
			head2=push(head2,t);
			head1=pop(head1);
		}
		//res=top(head2);
		head2=pop(head2);
		while(head2!=NULL){
			t=top(head2);
			head1=push(head1,t);
			head2=pop(head2);
		}
	}
	return head1;
}
void print(node *head){
	node *curr=head;
	if(curr==NULL)
		printf("Queue is Empty\n");
	else{
		while(curr!=NULL){
			printf("%d ",curr->data);
			curr=curr->link;
		}
		printf("\n");
	}
	free(curr);
}
int main(){
	node *stack1=NULL;
	node *stack2=NULL;
	int ch,data,f=1;
	while(f){
		printf("For Queue Manipulation\n");
		printf("1.Insertion\n");
		printf("2.Deletion\n");
		printf("3.Display\n");
		printf("4.Exit\n");
		printf("Enter your choise = ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("Enter the data to insert = ");
				scanf("%d",&data);
				stack1=push(stack1,data);
				break;
			case 2:
				stack1=delque(stack1,stack2);
				break;
			case 3:
				print(stack1);
				break;
			case 4:
				f=0;
				break;
			default:
				printf("Invalid Input!\n");
				break;
		}
	}
}
