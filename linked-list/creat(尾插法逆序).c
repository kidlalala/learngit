#include<stdio.h>
#include<stdlib.h>
struct student
{
        int data;
        struct student *next;
};
typedef struct student STU;
STU * creat(int n)
{
        int S=sizeof(struct student);
        STU *head,*p;
        head=NULL;
        for(int i=1;i<=n;i++)
        {
                p=(STU *)malloc(S);
                printf("请输入学生数据：");
                int x;
                scanf("%d",&x);
                p->data=x;
                p->next=head;
                head=p;
        }
        return head;
}
int main(int argv,char **args)
{
        STU *a;
        int n;
        printf("请输入链表长度：");
        scanf("%d",&n);
        a=creat(n);
        while(a)
        {
                printf("%d\n",a->data);
                a=a->next;
        }
        return 0;
}
