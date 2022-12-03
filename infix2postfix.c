#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX 50
char stack[MAX];
char infix[MAX], postfix[MAX];
int top=-1;
void push(char data){
	top++;
	stack[top]=data;
}
char pop(){
	char val;
	val=stack[top];
	top--;
	return val;
}
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
				(top==-1)?(push(infix[i])):({
					if(pcd(infix[i])>pcd(stack[top]))
						push(infix[i]);

					else if((pcd(infix[i])==pcd(stack[top]))&&(infix[i]=='^'))
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
	in2post();
	puts(postfix);

}
