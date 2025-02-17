// Fig. 12.3: fig12_03.c
// Inserting and deleting nodes in a list
#include <stdio.h>
#include <stdlib.h>
//#include "ll.h"
#include "ll2.h"

int main( void )
{ 
   LLPtr startPtr = NULL; // initially there are no nodes
   unsigned int choice; // user's choice
   int item; // char entered by user
   char name[50];

   instructions(); // display the menu
   printf( "%s", "? " );
   scanf( "%u", &choice );
   //%u

   // loop while user does not choose 3
   while ( choice != 3 ) { 

      switch ( choice ) { 
         case 1:
            printf("%s", "Enter id and name: ");
            scanf("%d %s", &item, name);
            insert(&startPtr, item, name); // insert item in listมี name ตอนทำ ll2.h
            printList(startPtr);
            printlist_reverse(startPtr);
            break;
         case 2: // delete an element
            // if list is not empty
            if (!isEmpty(startPtr))
            { 
               printf("%s", "Enter number to be deleted: ");
               scanf("%d", &item);

               // if character is found, remove it
               if (deletes(&startPtr, item) )// remove item
               { 
                  printf("%d deleted.\n", item);
                  printList(startPtr);
                  printlist_reverse(startPtr);
               } // end if
               else{
                  printf("%d not found.\n\n", item);
               } // end else
            } // end if
            else{
               puts("List is empty.\n");
            } // end else

            break;
         default:
            puts( "Invalid choice.\n" );
            instructions();
            break;
      } // end switch

      printf( "%s", "? " );
      scanf( "%u", &choice );
   } // end while
  /* Clear all nodes at the end of nodes*/
  LLPtr currentPtr = startPtr;
  LLPtr tempPtr;

  while(currentPtr!=NULL){
   tempPtr=currentPtr;
   currentPtr=currentPtr->nextPtr;
   printf("Delete %d",tempPtr->data);
   free(tempPtr);
  }
   puts( "End of run." );
} // end main
