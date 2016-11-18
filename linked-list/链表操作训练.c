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
        p->next=NULL;
        return head;
}

STU *add(STU *a,int n,int d)
{
        if(a==NULL)
        {
                printf("链表为空无法插入\n");
                return NULL;
        }
        if(n==1)
        {
                STU *p=(STU *)malloc(S);
                p->next=a;
                p->data=d;
                return p;
        }
        STU *b=a;
        for(int i=1;i<n-1;i++)
                b=b->next;
        STU *p;
        p=(STU *)malloc(S);
        p->data=d;
        p->next=b->next;
        b->next=p;
        return a;
}

STU *delete(STU *a,int n)
{
        if(a==NULL)
        {
                printf("链表为空无法删除");
                return NULL;
        }
        if(n==1)
        {
                STU *p=a->next;
                free(a);
                return p;
        }
        STU *c,*b=a;
        for(int i=1;i<n-1;i++)
                b=b->next;
        c=b->next;
        b->next=c->next;
        free(c);
        return a;
}

STU *reverse(STU *a)
{
        if(a==NULL)
        {
                printf("链表为空无法逆序");
                return NULL;
        }
        STU *p1=a,*p2=a->next,*p3=p2->next;
        a->next=NULL;
        while(p3)
        {
                p2->next=p1;
                p1=p2;
                p2=p3;
                p3=p2->next;
        }
        p2->next=p1;
        return p2;
}

STU *bubblesort(STU *a)
{
        STU *p=a,*tail,*f;
        for(tail=a;tail->next!=NULL;tail=tail->next);
        if(tail==a)
        {
                printf("仅有一个学生数据，无需排序\n");
                return NULL;
        }
        if(tail==a->next)
        {
                if(a->data>tail->data)
                {
                        int temp;
                        temp=a->data;
                        a->data=tail->data;
                        tail->data=temp;
                }
                return a;
        }
        while(tail!=a)
        {
                int flag=1;
                for(p=a;p!=tail;p=p->next)
                {
                        int temp;
                        if(p->data>p->next->data)
                        {
                                temp=p->data;
                                p->data=p->next->data;
                                p->next->data=temp;
                                flag=0;
                        }
                        if(p->next==tail)
                                f=p;
                }
                tail=f;
                if(flag)
                        break;
        }
        return a;
}

STU *insertsort(STU *a)
{
        STU *p=a->next,*q,*t=p,*x;
        a->next=NULL;
        while(p)
        {
                for(q=a;q!=NULL&&q->data<p->data;t=q,q=q->next);
                x=p->next;
                if(q==a)
                {
                        p->next=a;
                        a=p;
                }
                else if(q==NULL)
                {
                        t->next=p;
                        p->next=NULL;
                }
                else
                {
                        p->next=t->next;
                        t->next=p;
                }
                p=x;
        }
        return a;
}

STU *selectsort(STU *a)
{
        STU *min,*head=NULL,*p,*q,*pmin;
        while(a)
        {
                min=a;
                for(p=a;p->next!=NULL;p=p->next)
                        if(p->next->data<min->data)
                        {
                                min=p->next;
                                pmin=p;
                        }
                if(head==NULL)
                        q=head=min;
                else
                {
                        q->next=min;
                        q=min;
                }
                if(min==a)
                        a=a->next;
                else
                        pmin->next=min->next;
        }
        q->next=NULL;
        return head;
}

void destroylist(STU *a)
{
        if(a==NULL)
        {
                printf("链表为空，不需要清空\n");
                return;
        }
        STU *p;
        while(a)
        {
                p=a;
                a=a->next;
                free(p);
        }
        printf("链表清空\n");
}

int main(int argv,char **args)
{
        STU *a;
        printf("请输入学生个数:");
        int n;
        scanf("%d",&n);
        a=creat(n);
        STU *b=a;
        while(b)
        {
                printf("%d\n",b->data);
                b=b->next;
        }
        printf("请输入插入学生的位置:");
        int x;
        scanf("%d",&x);
        printf("请输入插入学生的数据:");
        int y;
        scanf("%d",&y);
        a=add(a,x,y);
        b=a;
        while(b)
        {
                printf("%d\n",b->data);
                b=b->next;
        }
        a=delete(a,x);
        b=a;
        printf("删除后链表\n");
        while(b)
        {
                printf("%d\n",b->data);
                b=b->next;
        }
        a=reverse(a);
        b=a;
        printf("逆序后链表\n");
        while(b)
        {
                printf("%d\n",b->data);
                b=b->next;
        }
        printf("冒泡排序后\n");
        b=bubblesort(a);
        while(b)
        {
                printf("%d\n",b->data);
                b=b->next;
        }
        printf("插入排序后\n");
        b=insertsort(a);
        while(b)
        {
                printf("%d\n",b->data);
                b=b->next;
        }
        printf("选择排序后\n");
        b=selectsort(a);
        while(b)
        {
                printf("%d\n",b->data);
                b=b->next;
        }
        destroylist(a);
        return 0;
}
