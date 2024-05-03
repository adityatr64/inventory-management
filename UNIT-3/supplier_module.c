#include <stdio.h>
#include <string.h>
#include "reqs.h"
extern const int limit;
extern int Sitems;

void AddSup(Supplier *sup) 
{
  if (Sitems < limit) 
  {
    printf("### Add Supplier ###\n");
    int sid;
    printf("SID: ");
    here:
    scanf("%i%*c", &sid);
    if(check_sup(sid,sup,Sitems))
    {
      printf("ID already exists \nEnter a diffrent ID: ");
      goto here;
    }
   (sup+Sitems)->id=sid;

    printf("NAME: ");
    scanf("%[^\n]",(sup + Sitems)->name);//fgets later

    printf("ADDRESS: ");
    scanf("%[^\n]", (sup + Sitems)->address);//fgets later

    (Sitems)++;
    printf("Product added successfully.\n\n");

  } 
  else 
  {
    printf("Product array is full. Cannot add more products.\n\n");
  }
}
void DispSup(Supplier *sup) //works
{
  printf("%s\t\t%s\t\t%s\n", "ID", "NAME", "ADDRESS");
  for (int i = 0; i < Sitems; i++) 
  {
    printf("%i\t\t%s\t\t%s\n", (sup+i)->id, (sup+i)->name,(sup+i)->address);
  }
}
void UpSup(Supplier *sup) //works right now
{
  int sid;
  printf("\n## Update Supplier ##\n");
  printf("SID: ");
  scanf("%i%*c", &sid);
  for (int i = 0; i < Sitems; i++) 
  {
    if ((sup+i)->id != sid) 
    {
      continue;
    }
    printf("%s\t\t%s\t\t%s\n", "ID", "NAME", "ADDRESS");
    printf("%i\t\t%s\t\t%s\n", (sup+i)->id, (sup+i)->name,(sup+i)->address);
    printf("1. Update Name\n2. Update Address\n(1/2/q): ");
    int choice;
    scanf("%i%*c", &choice);
    switch (choice) 
    {
    case 1: {
      printf("PNAME: ");
      scanf("%[^\n]",(sup+i)->name);
      break;
    }
    case 2: {
      printf("PRICE: ");
      scanf("%[^\n]", (sup+i)->address);
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

    printf("%s\t\t%s\t\t%s\t\t%s\n", "ID", "NAME", "PRICE", "QUANTITY");
    printf("%i\t\t%s\t\t%s\n", (sup+i)->id, (sup+i)->name,(sup+i)->address);
  }
}
void DelSup(Supplier *sup)//works'.
{
  int sid,j=0;
  printf("\n## DELETE PRODUCT ##\n");
  printf("PID: ");
  scanf("%i%*c", &sid);

  for(int i=0;i<Sitems;i++)
  {
    if(sid==(sup+i)->id||j>0)
    {
      j=1;
      char *temp;
    
      (sup+i)->id=(sup+i+j)->id;
      strcpy((sup+i)->name,(sup+i+j)->name);
      strcpy((sup+i)->address,(sup+i+j)->address);
    }
  }
  Sitems--;
}