#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
#define C1 (pcd(infix[i])==pcd(stack[top]))&&(infix[i]=='^')
char stack[MAX];
char infix[MAX], postfix[MAX];
int top=-1;
void isFull(){
	if(top==MAX-1){
		printf("Stack has in Overflow Condition!\n");
		exit(1);

	}
}
void isEmpty(){
	if(top==-1){
		printf("Underflow Condition!\n");
		exit(1);
	}
}
void push(char data){
	isFull();
	top++;
	stack[top]=data;
}
char pop(){
	char val;
	isEmpty();
	val=stack[top];
	top--;
	return val;
}
char peek(){
	isEmpty();
	return stack[top];
}
char is_bal(char str[]){
	int i;
	for(i=0;i<strlen(str);i++){
		switch(str[i]){
			case '(':
				push(-1);
				break;
			case '{':
				push(-2);
				break;
			case '[':
				push(-3);
				break;
			case ')':
				(peek()+1==0)?pop():({
					printf("Given expression is NOT balanced.\n");
					exit(1);
				});
				/*if(peek()+1==0)
					pop();
				else{
					printf("Given expression is NOT balanced.\n");
					exit(1);
				}*/
				break;
			case '}':
				if(peek()+2==0)
					pop();
				else{
					printf("Given expression is NOT balanced.\n");
					exit(1);
				}
				break;
			case ']':
				if(peek()+3==0)
					pop();
				else{
					printf("Given expression is NOT balanced.\n");
					exit(1);
				}
				break;
		}
	}
	if(top==-1)
		printf("Given expression is balanced.\n");
	else
		printf("Given expression is NOT balanced.\n");
}
// bool isOperand(){
// 	(infix[i]>='a'&&infix[i]<='z'||infix[i]>='A'&&infix[i]<='Z')?({return true;}):({return false;});
// }
int pcd(char c){
		switch(c){
			case '+':
			case '-':
				return 1;
			case '/':
			case '*':
				 return 2;
			case '^':
				return 3;
			default:
				return -1;
		}
}
void in2post(){
	int i,j=0;
	for(i=0;i<strlen(infix);i++){
		switch(infix[i]){
			case 'A'...'Z':
			case 'a'...'z':
				postfix[j++]+=infix[i];
				break;
			case '(':
				push(infix[i]);
				break;
			case ')':
				while((stack[top]!='(')&&(top!=-1))
					postfix[j++]+=pop();
				if(stack[top]=='(')
					pop();
				break;
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
				(top==-1)?(push(infix[i])):
				({
					if(pcd(infix[i])>pcd(stack[top]))
						push(infix[i]);

					else if(C1)
							push(infix[i]);		//This block for associative rule of "^" right to left
					else{
						while(pcd(infix[i])<=pcd(stack[top])&&(top!=-1))
							postfix[j++]+=pop();
						push(infix[i]);
					}
				});
				break;
		}
	}
	while(top!=-1)
		postfix[j++]+=pop();
}
int main(){
	printf("Enter the expression:\n");
	gets(infix);
	in2post(infix);
	puts(postfix);
	
	//is_bal(infix);
}
