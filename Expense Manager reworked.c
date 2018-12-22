#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50 //maximum items entry

//structure definition
typedef struct item_details{
	char itemName[30];	//item name
	int quantity;	//item quantity
	float price;	//per item price
	float totalValue; //total amount = quantity*price
}item;

struct listNode{
	float expense;
	char itemA [100];
	struct listNode *nextPtr;
	

};

typedef struct listNode listNode;
typedef listNode *ListNodePtr;

void insert(ListNodePtr *sPtr, float value,char itemA[100]);
void printList(ListNodePtr currentPtr);

void printList(ListNodePtr currentPtr)
{
	/* if list is empty */
	if ( currentPtr == NULL ) 
		printf( "List is empty.\n\n" ); /* end if */
	else 
	{
		printf( "The list is:\n" );
		/* while not the end of the list */
		while ( currentPtr != NULL ) 
		{
			printf( "%s , %.2f --> ",currentPtr->itemA, currentPtr->expense );
			currentPtr = currentPtr->nextPtr;
		} /* end while */
		printf( "NULL\n\n" );
	} /* end else */
}

void insert(ListNodePtr *sPtr, float value,char *itemA)
{

	ListNodePtr newPtr; /* pointer to new node */
	ListNodePtr previousPtr; /* pointer to previous node in list */
	ListNodePtr currentPtr; /* pointer to current node in list */

	newPtr = malloc( sizeof( listNode ) );
	if ( newPtr != NULL ) 
	{ /* is space available */
		newPtr->expense = value;
		strcpy(newPtr->itemA,itemA);
		newPtr->nextPtr = NULL;
		previousPtr = NULL;
		currentPtr = *sPtr;
		/* loop to find the correct location in the list */
		while ( currentPtr != NULL) 
		{
			previousPtr = currentPtr; /* walk to ... */
			currentPtr = currentPtr->nextPtr; /* ... next node */
		} /* end while */
		/* insert newPtr at beginning of list */
		if ( previousPtr == NULL ) 
		{
			newPtr->nextPtr = *sPtr;
			*sPtr = newPtr;
		} /* end if */
		else 
		{ /* insert newPtr between previousPtr and currentPtr */
			previousPtr->nextPtr = newPtr;
			newPtr->nextPtr = currentPtr;
		} /* end else */ 
	} /* end if */
	else
		printf( "%c not inserted. No memory available.\n", value );
	}





int main(){
	item thing[MAX]; //structure variable
	int i,choice;
	int count=0;
	float expenses=0.0f;
	ListNodePtr startPtr = NULL;
	
	
		
	
	i=0;
	//Loops
	do{
	   printList(startPtr);

		printf("Enter item details [%2d ]:\n",i+1);
		
		printf("Item Name?  ");		
		fgets(thing[i].itemName,30,stdin);
		
		printf("Price? (in USD or IDR) ");
		scanf("%f",&thing[i].price);
		
		printf("Quantity?  ");
		scanf("%d",&thing[i].quantity);
		
		thing[i].totalValue=(float)thing[i].quantity*thing[i].price;
		expenses += thing[i].totalValue;

		i++;	//increase loop counter
		count++;//increase record counter
		
		printf("\nAdd more items? (press 1): ");
		scanf("%d",&choice);
		
		getchar();
		
	}while(choice==1);
	
	//items print out
	printf("Summary :\n");
	for(i=0; i<count; i++)
	{
		printf("%-30s\t %.2f \t %3d \n %.2f\n",thing[i].itemName, thing[i].price, thing[i].quantity, thing[i].totalValue);
	}
	printf("#### Total expense: %.2f ####\n",expenses);
	
	
	insert(&startPtr, expenses,thing[i].itemName);
	printList(startPtr);



	
	printf("Split the bill(s)? (press 1 for yes): ");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("How many friends? ");
		scanf("%d",&i);
		printf("Each friend will have to pay: %.2f\n",(expenses/(float)i));
	}
	
	printf("~Thanks for using this program... We hope it is very helpful!!~\n");
	return 0;
}
