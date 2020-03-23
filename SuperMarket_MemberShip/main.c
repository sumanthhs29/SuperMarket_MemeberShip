#include <stdio.h>
#include <stdlib.h>
typedef struct mem
{
    char name[15];
    long int id;
    int pt;
    struct mem *next;
}MEMBERS;

int ide;
MEMBERS *add_mem(MEMBERS *m)
{
    MEMBERS *temp;
    temp=(MEMBERS*)malloc(sizeof(MEMBERS));
    printf("\nEnter the Member name\n");
    scanf("%s",temp->name);
    printf("\nEnter the phone number :");
    scanf("%ld",&temp->id);
    temp->pt=0;
    ide++;
    if(m==NULL)
        temp->next=NULL;
    else
        temp->next=m;
    return temp;
}

MEMBERS *purchase(MEMBERS *m,long int idee)
{
    int i=0,j,items[20],n,total=0,dis=0,flag=0;
    MEMBERS *temp;
    temp=m;
    while(temp!=NULL)
    {
        if(idee==temp->id)
        {

            flag=1;
            printf("\nEnter the number of items purchased\n");
            scanf("%d",&n);
            for(j=0;j<n;j++)
            {
                printf("\nEnter the item price\n");
                scanf("%d",&items[i]);
                total=total+items[i];
            }

            temp->pt=temp->pt+total*0.1;
            printf("\nPoints = %d",temp->pt);
            if(temp->pt>100)
            {
                dis=total*0.2;
                temp->pt=temp->pt-100;
            }
            total=total-dis;
            printf("\nTotal amount = %d",total);
            temp=temp->next;
        }
    }
    if(flag==0)
        printf("\nNo member found");
    return m;
}
int main()
{
    MEMBERS *m;
    m=(MEMBERS*)malloc(sizeof(MEMBERS));
    m=NULL;
    int choice;
    long int ide;
    while(1)
    {
        printf("\n1:Add_Member 2:PURCHASE 3:QUIT\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:m=add_mem(m);
                    break;
            case 2:printf("\nEnter the member phone number: ");
                    scanf("%ld",&ide);
                    m=purchase(m,ide);
                    break;
            case 3:exit(0);
            default:printf("Invalid choice\n");
        }
    }
    return 0;
}
