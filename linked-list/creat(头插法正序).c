#include<stdio.h>
#include<stdlib.h>
struct student
{
        int data;
        struct student *next;
};
typedef struct student STU;
int S=sizeof(STU);
STU *creat(int n)
{
        STU *head,*p,*q;
        head=NULL;
        int x;
        p=(STU *)malloc(S);
        for(int i=1;i<=n;i++)
        {
                printf("请输入学生数据：");
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
                p=(STU*)malloc(S);
        }
        p->next=NULL;
        return head;
}
int main(int argv,char **args)
{
        STU *a;
        printf("请输入创建链表长度：");
        int n;
        scanf("%d",&n);
        a=creat(n);
        while(a)
        {
                printf("%d\n",a->data);
                a=a->next;
        }
        return 0;
}
