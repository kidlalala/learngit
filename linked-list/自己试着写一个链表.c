#include<stdio.h>
#include<stdlib.h>
struct student
{
        int data;
        struct student *next;
};
typedef struct student STU;
#define S sizeof(struct student)
STU * creat1(int n)
{
        STU *head,*p,*q;
        head=NULL;
        int x;
        p=(STU *)malloc(S);
        for(int i=1;i<=n;i++)
        {
                printf("请输入学生数据:");
                scanf("%d",&x);
                p->data=x;
                if(head==NULL)
                {
                        q=head=p;
                        head->next=NULL;
                }
                else
                {
                        q->next=p;
                        q=p;
                }
                p=(STU *)malloc(S);
        }
        return head;
}
STU * creat2(int n)
{
        STU *head,*p;
        head=NULL;
        for(int i=1;i<=n;i++)
        {
                p=(STU *)malloc(S);
                int x;
                printf("请输入学生数据:");
                scanf("%d",&x);
                p->data=x;
                p->next=head;
                head=p;
        }
        return head;
}
int main(int argv,char **args)
{
        STU *a,*b;
        int n;
        printf("请输入链表长度:");
        scanf("%d",&n);
        a=creat1(n);
        while(a)
        {
                printf("%d ",a->data);
                a=a->next;
        }
        puts("");
        b=creat2(n);
        while(b)
        {
                printf("%d ",b->data);
                b=b->next;
        }
        puts("");
        return 0;
}
