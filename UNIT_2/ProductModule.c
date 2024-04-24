#include <stdio.h>

extern const int limit;
extern int Pitems;
extern int check(int id, int *id_array, int Elements);

void AddPro(int *Pid, char Pname[][25], float *Pprice,int *Pquantity) 
{
  if (Pitems < limit) 
  {
    printf("### Add Product ###\n");
    int pid;
    printf("PID: ");
    here:
    scanf("%i%*c", &pid);
    if(check(pid,Pid,Pitems))
    {
      printf("ID already exists \nEnter a diffrent ID: ");
      goto here;
    }
   *(Pid + Pitems)=pid;

    printf("PNAME: ");
    scanf("%s%*c",*(Pname + Pitems));

    printf("PRICE: ");
    scanf("%f%*c", (Pprice + Pitems));

    printf("QUANTITY: ");
    scanf("%i%*c", (Pquantity + Pitems));

    (Pitems)++;
    printf("Product added successfully.\n\n");

  } 
  else 
  {
    printf("Product array is full. Cannot add more products.\n\n");
  }
}
void UpPro(int *Pid, char Pname[][25],float *Pprice, int *Pquantity) //works right now
{
  int pid;
  printf("\n## Update Product ##\n");
  printf("PID: ");
  scanf("%i%*c", &pid);

  // find the product
  for (int i = 0; i < Pitems; i++) 
  {
    if (Pid[i] != pid) 
    {
      continue;
    }
    printf("%s\t\t%s\t\t%s\t\t%s\n", "ID", "NAME", "PRICE", "QUANTITY");
    printf("%i\t\t%s\t\t%f\t\t%i\n", *(Pid+i), *(Pname+i),*(Pprice+i), *(Pquantity+i));
    printf("1. Update Name\n2. Update Price\n3. Update Quantity\n(1/2/3/q): ");
    int choice;
    scanf("%i%*c", &choice);
    switch (choice) 
    {
    case 1: {
      printf("PNAME: ");
      scanf("%s%*c",*(Pname + i));
      break;
    }
    case 2: {
      printf("PRICE: ");
      scanf("%f%*c", (Pprice + i));
      break;
    }
    case 3: {
      printf("QUANTITY: ");
      scanf("%i%*c", (Pquantity + i));
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
    printf("%i\t\t%s\t\t%0.3f\t\t%i\n", Pid[i], Pname[i],Pprice[i], Pquantity[i]);
  }
}
void DispPro(int *Pid, char Pname[][25],float *Pprice, int *Pquantity) //works
{
  printf("%s\t\t%s\t\t%s\t\t%s\n", "ID", "NAME", "PRICE", "QUANTITY");
  for (int i = 0; i < Pitems; i++) 
  {
    printf("%i\t\t%s\t\t%.2f\t\t%i\n", *(Pid+i), *(Pname+i),*(Pprice+i), *(Pquantity+i));
  }
}
void DelPro(int *Pid, char Pname[][25],float *Pprice, int *Pquantity)//works'.
{
  int pid,j=0;
  printf("\n## DELETE PRODUCT ##\n");
  printf("PID: ");
  scanf("%i%*c", &pid);

  for(int i=0;i<Pitems;i++)
  {
    if(pid==*(Pid+i)||j>0)
    {
      j=1;
    
      *(Pid+i)=*(Pid+i+j);
      for(int k=0;k<25;k++)
      {
        *(*(Pname+i)+k)=*(*(Pname+i+j)+k);
      }
      *(Pprice+i)=*(Pprice+i+j);
      *(Pquantity+i)=*(Pquantity+i+j);
    }
  }
  Pitems--;
}