#include <stdio.h>
#include <stdlib.h>
struct stack{
	int top;
	int cap;
	int *arr;
};
struct stack* CreateStack(int size)
{
	struct stack *s= (struct stack*)malloc(sizeof(struct stack));
	if(s==NULL)
	return NULL;
	s->top=-1;
	s->cap=size;
	s->arr=(int *)malloc(size*sizeof(int));
	if(s->arr==NULL)
	return NULL;
	return s;
}
int IsEmpty(struct stack *s)
{
	return (s->top==-1);
}
int IsFull(struct stack *s)
{
	return (s->top==s->cap-1);
}
void push(struct stack *s,int data)
{
	if(IsFull(s))
	printf("Overflow!\n");
	else
	s->arr[++s->top]=data;
}
int pop(struct stack* s)
{
	if(IsEmpty(s))
	return -1;
	else
	return (s->arr[s->top--]);
}
int top(struct stack *s)
{
    if(IsEmpty(s))
        return -1;
    else
        return (s->arr[s->top]);
}
void display(struct stack* s)
{
	int i;
	if(IsEmpty(s))
	printf("Empty Stack. Nothing to display!!");
	else
	{
		printf("The Stack is : \n");
	for(i=0;i<=s->top;i++)
	{
		printf("%d ",s->arr[i]);
	}
    }
    printf("\n");
}
int main()
{
    int arr[1000];
	int num,size,i;
	scanf("%d",&size);
	do
    {
        int ctr=1;
        struct stack *s1,*s2;
        s1 = CreateStack(size);
        s2 = CreateStack(size);
        for(i=0;i<size;i++)
        {
            scanf("%d",&arr[i]);
        }
        for(i=size-1;i>=0;i--)
        {
            push(s1,arr[i]);
        }
        for(i=0;i<size;i++)
        {
            if(top(s1)==ctr)
            {
                pop(s1);
                ctr++;
            }
            else if(top(s2)==ctr)
            {
                pop(s2);
                ctr++;
            }
            else{
                while(!(IsEmpty(s1)))
                {
                    num = pop(s1);
                    push(s2,num);
                    if(top(s1)==ctr)
                    {
                        pop(s1);
                        ctr++;
                        break;
                    }
                }
            }
        }
        if(ctr==size+1)
            printf("yes\n");
        else
            printf("no\n");
        scanf("%d",&size);
    } while(size!=0);
	return 0;
}
