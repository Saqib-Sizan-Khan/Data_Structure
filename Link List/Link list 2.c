#include<stdio.h>
#include<stdlib.h>

#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
#define maxSize 1000

int list[maxSize];
int length;


void initializeList()
{
    length = 0 ;
}

int searchItem(int item)
{
    int i = 0;
    for (i = 0; i < length; i++)
    {
        if( list[i] == item )
            return i;
    }
    return NULL_VALUE;
}

int insertItem(int newitem)
{
    if (length == maxSize)
    {
        return NULL_VALUE;
    }

    list[length] = newitem ; //store new item
    length++ ;
    return SUCCESS_VALUE ;
}

int insertItemAt(int position,int item)
{
    if(position>=length)
    {
        printf("Can not Insert\n");
        return NULL_VALUE;
    }

    list[position] = item;
    return SUCCESS_VALUE;
}


int deleteItemAt(int position) //do not preserve order of items
{
    if ( position<0 || position >= length )
        return NULL_VALUE;
    list[position] = list[length-1] ;
    length-- ;
    return SUCCESS_VALUE ;
}


int deleteItem(int item)
{
    int position;
    position = searchItem(item) ;
    if ( position == NULL_VALUE )
        return NULL_VALUE;
    deleteItemAt(position) ;
    return SUCCESS_VALUE ;
}

int deleteItemOrdered(int position)
{
    if ( position<0 || position >= length )
    {
        printf("Invalid Position\n");
        return NULL_VALUE;
    }

    int i;
    for(i=position; i<length; i++)
    {
        list[i]=list[i+1];
    }
    length--;
    return SUCCESS_VALUE;
}

int deleteLast()
{
    length--;
    return SUCCESS_VALUE;
}

void printList()
{
    int i;
    for(i=0; i<length; i++)
        printf("%d ", list[i]);
    printf("\n");
}

int getlength(int length)
{
    printf("%d\n",length);
    return length;
}

int alterItem(int position,int newValue)
{
    if ( position<0 || position >= length )
    {
        printf("Invalid Position\n");
        return NULL_VALUE;
    }

    int temp;
    length++;

    temp = list[position];
    list[position] = newValue;
    list[length-1] = temp;
    return SUCCESS_VALUE;
}

int main(void)
{
    initializeList();
    printf("1. Insert new Item. 2. Delete Item at. 3. Delete Item.\n");
    printf("4. Delete Item. 5. Print. 6. Get Length.\n");
    printf("7. Insert Item At. 8. Delete Item Ordered. 9. Alter Item.\n");
    printf("10. Delete Last. 11. Exit.\n");
    while(1)
    {

        int ch;
        scanf("%d",&ch);
        if(ch==1)
        {
            int item;
            scanf("%d", &item);
            insertItem(item);
        }
        else if(ch==2)
        {
            int pos;
            scanf("%d", &pos);
            deleteItemAt(pos);
        }
        else if(ch==3)
        {
            int item;
            scanf("%d", &item);
            deleteItem(item);
        }
        else if(ch==5)
        {
            printList();
        }
        else if(ch==6)
        {
            getlength(length);
        }
        else if(ch==7)
        {
            int pos,item;
            scanf("%d %d",&pos,&item);
            insertItemAt(pos,item);
        }
        else if(ch==8)
        {
            int pos;
            scanf("%d",&pos);
            deleteItemOrdered(pos);
        }
        else if(ch==9)
        {
            int pos,value;
            scanf("%d %d",&pos,&value);
            alterItem(pos,value);
        }
        else if(ch==10)
        {
            deleteLast();
        }
        else if(ch==11)
        {
            break;
        }
    }
}
