#include <stdio.h>
#include "reqs.h"

extern const int limit;
extern int Titems;

void AddTrans(Transaction *trans) 
{
  if (Titems < limit) 
  {
    printf("### Add Transction ###\n");
    int tid;
    printf("TID: ");
    here:
    scanf("%i%*c", &tid);
    if(check_trans(tid,trans,Titems))
    {
      printf("ID already exists \nEnter a diffrent ID: ");
      goto here;
    }
    (trans+Titems)->id=tid;
    printf("DATE: ");
    scanf("%[^\n]",(trans + Titems)->date);//fgets later

    printf("PID: ");
    scanf("%i%*c", &(trans + Titems)->pid);

    printf("QUANTITY: ");
    scanf("%i%*c", &(trans + Titems)->quantity);

    (Titems)++;
    printf("Product added successfully.\n\n");

  } 
  else 
  {
    printf("Product array is full. Cannot add more products.\n\n");
  }
}
void DispTrans(Transaction *trans) //works
{
  printf("%s\t\t%s\t\t%s\t\t%s\n", "ID", "DATE", "PID", "QUANTITY");
  for (int i = 0; i < Titems; i++) 
  {
    printf("%i\t\t%s\t\t%i\t\t%i\n", (trans+i)->id, (trans+i)->date,(trans+i)->pid, (trans+i)->quantity);
  }
}
void UpTrans(Transaction *trans) //works right now
{
  int tid;
  printf("\n## Update Transcaction ##\n");
  printf("TID: ");
  scanf("%i%*c", &tid);

  // find the product
  for (int i = 0; i < Titems; i++) 
  {
    if ((trans+i)->id != tid) 
    {
      continue;
    }
    printf("%s\t\t%s\t\t%s\t\t%s\n", "ID", "DATE", "PID", "QUANTITY");
    printf("%i\t\t%s\t\t%i\t\t%i\n", (trans+i)->id, (trans+i)->date,(trans+i)->pid, (trans+i)->quantity);
    printf("1. Update DATE\n2. Update PID\n3. Update Quantity\n(1/2/3/q): ");
    int choice;
    scanf("%i%*c", &choice);
    switch (choice) 
    {
    case 1: {
      printf("DATE: ");
      scanf("%[^\n]",(trans+i)->date);//fgets later
      break;
    }
    case 2: {
      printf("PID: ");
      scanf("%i%*c", &(trans+i)->pid);
      break;
    }
    case 3: {
      printf("QUANTITY: ");
      scanf("%i%*c",&(trans+i)->quantity);
      break;
    }
    case 'q': {
      printf("== exitting ==");
      break;
    }
    default: {
      printf("Invalid choice");
      break;
    }
    }

    printf("%s\t\t%s\t\t%s\t\t%s\n", "ID", "DATE", "PID", "QUANTITY");
    printf("%i\t\t%s\t\t%i\t\t%i\n", (trans+i)->id, (trans+i)->date,(trans+i)->pid, (trans+i)->quantity);
  }
}
