#include<stdio.h>
/*program to evaluate the given postfix expression*/
typedef struct
{
	int a[100];
	int top;
}STACK;
void push(STACK *s,int x)
{
		s->a[++s->top]=x;
	//	s->a[top++]=x;
	//	top=top+1;
}

int pop(STACK *s)
{
	int x;
	if(s->top<0)
		printf("oyee ye kya kr diyaaaaa\n");
	
	else
	{
		x=s->a[s->top--];
		//x=s->a[top];
		//top--;
		return x;
	}
}
int operation(int p1,int p2,char op)
{
	switch(op)
	{
		case '+':return p1+p2;
		case '*':return p1*p2;
		case '-':return p1-p2;
		case '/':return p1/p2;
	}
}
int evaluate(char pos[])
{
	STACK s1;
	int p1,p2,result,i;
	s1.top=-1;
	for(i=0;pos[i]!='\0';i++)
		if(isdigit(pos[i]))
			push(&s1,pos[i]-'0');/*use to find the integer value of it*/
		else
		{
			p2=pop(&s1);
			p1=pop(&s1);
			result=operation(p1,p2,pos[i]);
			push(&s1,result);
		}
	return pop(&s1);
}
void main()
{
	char postfix[100];
	printf("Please Enter the VALID POSTFIX string\n");
	scanf("%s",postfix);
	printf("The Result is==> %d\n",evaluate(postfix));
}
