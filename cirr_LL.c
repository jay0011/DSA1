
#include<stdio.h>
#include<stdlib.h>
typedef struct cirrLL{
	int data;
	struct cirrLL *link;
}node;
int ct=0;
node *insert(node *last,int d,int c){
	ct++;
	int i,p;
	node *curr=NULL;

	node *neo=(node*)malloc(sizeof(node));
	neo->data=d;
	neo->link=neo;
	if(last==NULL){
		last=neo;
		return last;
	}
	switch(c){
		case 1:
			neo->link=last->link;
			last->link=neo;
			break;
		case 2:
			neo->link=last->link;
			last->link=neo;
			last=last->link;
			break;
		case 3:
			printf("Enter the position to delete = ");
			scanf("%d",&p);
			curr=last->link;
			switch(p){
				case 1:
					neo->link=curr;
					last->link=neo;
					break;
				case 2...(ct+1):
					for(i=1;i<p-1;i++)
						curr=curr->next;
					neo->link=curr->link;
					curr->link=neo
					break;
				default:
					printf("Invalid choice of insert position!\n");
					break;
			}
		default:
			printf("Invalid choice in insertion!\n");
			break;
	}
	return last;
}
node *delete_node(node *last,int c){
	int p,i;
	node *curr=NULL;
	node *temp=NULL;
	if(last==NULL){
		printf("Linked list is already empty!\n");
		return last;
	}
	ct--;
	switch(c){
		case 1:
			
			break;
		case 2:
			neo->link=last->link;
			last->link=neo;
			last=last->link;
			break;
		case 3:
			printf("Enter the position to delete = ");
			scanf("%d",&p);
			curr=last->link;
			switch(p){
				case 1:
					neo->link=curr;
					last->link=neo;
					break;
				case 2...(ct+1):
					for(i=1;i<p-1;i++)
						curr=curr->next;
					neo->link=curr->link;
					curr->link=neo
					break;
				default:
					printf("Invalid choice of insert position!\n");
					break;
			}
		default:
			printf("Invalid choice in insertion!\n");
			break;
	}
	if(c==1){
		del_beg:
		last=last->next;
		free(head->prev);
		last->prev=NULL;
		return last;
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
void print(node *last){
	node *curr=last->link;
	if(last==NULL)
		printf("Linked list is already empty!");
	while(curr!=last){
		curr=curr->next;
		printf("%d ",curr->data);
	}
	printf("%d ",curr->data);
	printf("\n");
}
int main(){
	node *last=NULL;
	int c,ch,d,flag=1;
	while(flag){
		printf("For Circular Singly Linked List Manipulation\n1. Insertion\n2. Deletion\n3. Display\n4. Exit\nEnter your choice = ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				printf("1. At Beginning\n2. At End\n3. At any position\nEnter your choice = ");
				scanf("%d",&c);
				printf("Enter the value to be inserted = ");
				scanf("%d",&d);
				last=insert(last,d,c);
				break;
			case 2:
				printf("1. At Beginning\n2. At End\n3. At any position\nEnter your choice = ");
				scanf("%d",&c);
				last=delete_node(last,c);
				break;
			case 3:
				print(last);
				break;
			case 4:
				flag=0;
				break;
			default:
				printf("Invalid Input");

		}
	}
}
