//Deletion at pos not working also invalid pos value
#include<stdio.h>
#include<stdlib.h>
typedef struct dll{
	int data;
	struct dll *prev;
	struct dll *next;
}node;
int ct=0;
node *insert(node *head,int d,int c){
	ct++;
	int i,p;
	node *curr=NULL;
	node *temp=NULL;
	node *neo=(node*)malloc(sizeof(node));
	neo->data=d;
	neo->prev=NULL;
	neo->next=NULL;
	if(head==NULL)
		head=neo;
	else if(c==1){
		add_beg:
		neo->next=head;
		head->prev=neo;
		head=neo;
		return head;
	}
	else if(c==2){
		curr=head;
		while(curr->next!=NULL)
			curr=curr->next;
		add_end:
		curr->next=neo;
		neo->prev=curr;
	}
	else if(c==3){
		printf("Enter the position to delete = ");
		scanf("%d",&p);
		curr=head;
		if(p>ct){
			p=ct;
			goto add_end;
		}
		if(p<=1)
			goto add_beg;
		for(i=1;i<p-1;i++)
			curr=curr->next;
		if(curr->next==NULL)
			goto add_end;
		temp=curr->next;
		curr->next=neo;
		temp->prev=neo;
		neo->prev=curr;
		neo->next=temp;
	}
	return head;
}
node *delete_node(node *head,int c){
	int p,i;
	node *curr=NULL;
	node *temp=NULL;
	if(head==NULL){
		printf("linked list is already empty!");
		return head;
	}
	ct--;
	if(c==1){
		del_beg:
		head=head->next;
		free(head->prev);
		head->prev=NULL;
		return head;
	}
	else if(c==2){
		curr=head;
		if(head->next==NULL)
			head=NULL;
		else{
			while(curr->next!=NULL)
				curr=curr->next;
			del_end:
			curr=curr->prev;
			free(curr->next);
			curr->next=NULL;
		}
		return head;
	}
	else if(c==3){
		printf("Enter the position to delete = ");
		scanf("%d",&p);
		curr=head;
		if(p>ct){
			p=ct;
			goto del_end;
		}
		if(p<=1){
			goto del_beg;
		}
		for(i=1;i<p;i++)
			curr=curr->next;
		if(curr->next==NULL)
			goto del_end;
		temp=curr->prev;
		temp->next=curr->next;
		curr->next->prev=temp;
		free(curr);
		curr=NULL;
	}
	return head;
}
void print(node *head){
	node *curr=head;
	if(curr==NULL)
		printf("Linked list is already empty!");
	while(curr!=NULL){
		printf("%d ",curr->data);
		curr=curr->next;
	}
	printf("\n");
	free(curr);
}
int main(){
	node *head=NULL;
	int c,ch,d,flag=1;
	while(flag){
		printf("For Doubly Linked List Manipulation\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice = ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("1. At Beginning\n2. At End\n3. At any position\nEnter your choice = ");
				scanf("%d",&c);
				printf("Enter the value to be inserted = ");
				scanf("%d",&d);
				head=insert(head,d,c);
				break;
			case 2:
				printf("1. At Beginning\n2. At End\n3. At any position\nEnter your choice = ");
				scanf("%d",&c);
				head=delete_node(head,c);
				break;
			case 3:
				print(head);
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("Invalid Input");

		}
	}
}
