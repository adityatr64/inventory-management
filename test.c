#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct list
{
    int val;
    struct list* link;
}list;
void appendLink(list *head)
{
    printf("Enter new : ");
    list *temp=head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp=temp->link;
    temp->link=NULL;
    temp=(list*)malloc(sizeof(list));
    scanf("%d",&temp->val);
}
int main()
{
    printf("hello");
    list *l1=(list *)malloc(sizeof(list)),*iter;
    iter=l1;
    appendLink(l1);
    while(iter->link!=NULL)
    {
        printf("%d",iter->val);
    }
    return 0;
}