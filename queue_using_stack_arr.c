//Queue operation using 2 stacks by array implementation
#include<stdio.h>
#define MAX 20
int push(int *stack,int top,int data){
	if(top==MAX-1)
		printf("Stack is overflow condition!\n");
	else{
		top++;
		stack[top]=data;
	}
	return top;
}
int top(int*stack){
	return *stack;
}
int pop(int *stack,int top){
	if(top==-1)
		printf("Stack is underflow condition!\n");
	else
		top--;
	return top;
}
int delque(int *head1,int *head2,int top1,int top2){
	int t;
	if(top1==-1)
		return top1;
	else{
		while(top1!=-1){
			t=head1[top1];
			top2=push(head2,top2,t);
			top1--;
		}
		top2=pop(head2,top2);
		while(top2!=-1){
			t=*(head2+top2);
			top1=push(head1,top1,t);
			top2--;
		}
	}
	return top1;
}
void print(int stack[],int top){
	int i;
	if(top==-1){
		printf("Queue is Empty!");
		return;
	}
	for(i=0;i<=top;i++)
		printf("%d ",i[stack]);
	printf("\n");
}
int main(){
	int stack1[MAX],top1=-1;
	int stack2[MAX],top2=-1;
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
				top1=push(stack1,top1,data);
				break;
			case 2:
				top1=delque(stack1,stack2,top1,top2);
				break;
			case 3:
				print(stack1,top1);
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
