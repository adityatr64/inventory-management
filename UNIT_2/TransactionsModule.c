#include <stdio.h>

extern const int limit;
extern int Titems;
extern int check(int id, int *id_array, int Elements);

void AddTrans(int *Tid, int *TPid,int *Tquantity, char date[][10]) 
{
  if (Titems < limit) 
  {
    printf("### Add Transaction ###\n");
    printf("TRAN ID: ");
    int tid;
    t_here:
    scanf("%d", &tid);
    if(check(tid, Tid, Titems))
    {
      printf("ID already exists \nEnter a diffrent ID:");
      goto t_here;
    }
    *(Tid + Titems)=tid;

    printf("PROD ID: ");
    scanf("%d", (TPid + Titems));

    printf("PROD QUAN: ");
    scanf("%d%*c", (Tquantity + Titems));

    printf("TRAN DATE: ");
    scanf("%s%*c",*(date + Titems));
    (Titems)++;

    printf("Product added successfully.\n");
  } 
  else 
  {
    printf("Product array is full. Cannot add more products.\n");
  }
}

void DispTrans(int *Tid, int *TPid,int *Tquantity, char date[][10])
{
  printf("%s\t\t%s\t\t%s\t\t%s\n", "ID", "PID", "QUANTITY", "DATE");
  for (int i = 0; i < Titems; i++) 
  {
    printf("%d\t\t%d\t\t%d\t\t%s\n", *(Tid+i), *(TPid+i),*(Tquantity+i), *(date+i));
  }
}
void UpTrans(int *Tid, int *TPid,int *Tquantity, char date[][10]) 
{

  int tid;
  printf("\n## Update Transaction ##\n");
  printf("PID: ");
  scanf("%d%*c", &tid);

  for (int i = 0; i < Titems; i++) {
    if (*(Tid+i) != tid) 
    {
      continue;
    }
    printf("%s\t\t%s\t\t%s\t\t%s\n", "ID", "PID", "QUANTITY", "DATE");
    printf("%d\t\t%d\t\t%d\t\t%s\n", *(Tid+i), *(TPid+i),*(Tquantity+i), *(date+i));

    printf("1. Update PID\n2. Update Quantity\n3.Update Date\n(1/2/3/q): ");
    int choice;
    scanf("%d%*c", &choice);
    switch (choice) 
    {
    case 1: 
    {
      printf("PID: ");
      scanf("%d", (TPid + i));
      break;
    }
    case 2: 
    {
      printf("QUANTITY: ");
      scanf("%d", (Tquantity + i));
      break;
    }
    case 3: 
    {
      printf("DATE: ");
      scanf("%s%*c",*(date+i));
      break;
    }
    case 'q': 
    {
      printf("== exitting ==");
      break;
    }
    default: 
    {
      printf("Invalid choice");
      break;
    }
    }

    printf("%s\t\t%s\t\t%s\t\t%s\n", "ID", "PID", "QUANTITY", "DATE");
    printf("%d\t\t%d\t\t%d\t\t%s\n", *(Tid+i), *(TPid+i),*(Tquantity+i), *(date+i));
  }
}