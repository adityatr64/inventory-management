#include <stdio.h>
#include <string.h>
extern const int limit;
extern int Pitems;
// extern int check(int id, ids *id_path, int Elements);


void AddPro(Product *pro) 
{
  if (Pitems < limit) 
  {
    printf("### Add Product ###\n");
    int pid;
    printf("PID: ");
    here:
    scanf("%i%*c", &pid);
    // if(check(pro->id.id,&pro->id,Pitems))
    // {
    //   printf("ID already exists \nEnter a diffrent ID: ");
    //   goto here;
    // }
   (pro+Pitems)->id=pid;

    printf("PNAME: ");
    scanf("%s%*c",(pro + Pitems)->name);//fgets later

    printf("PRICE: ");
    scanf("%f%*c", &(pro + Pitems)->price);

    printf("QUANTITY: ");
    scanf("%i%*c", &(pro + Pitems)->quantity);

    (Pitems)++;
    printf("Product added successfully.\n\n");

  } 
  else 
  {
    printf("Product array is full. Cannot add more products.\n\n");
  }
}
void DispPro(Product *pro) //works
{
  printf("%s\t\t%s\t\t%s\t\t%s\n", "ID", "NAME", "PRICE", "QUANTITY");
  for (int i = 0; i < Pitems; i++) 
  {
    printf("%i\t\t%s\t\t%.2f\t\t%i\n", (pro+i)->id, &(pro+i)->name,(pro+i)->price, (pro+i)->quantity);
  }
}
void UpPro(Product *pro) //works right now
{
  int pid;
  printf("\n## Update Product ##\n");
  printf("PID: ");
  scanf("%i%*c", &pid);

  // find the product
  for (int i = 0; i < Pitems; i++) 
  {
    if ((pro+i)->id != pid) 
    {
      continue;
    }
    printf("%s\t\t%s\t\t%s\t\t%s\n", "ID", "NAME", "PRICE", "QUANTITY");
    printf("%i\t\t%s\t\t%f\t\t%i\n", (pro+i)->id, (pro+i)->name,(pro+i)->price, (pro+i)->quantity);
    printf("1. Update Name\n2. Update Price\n3. Update Quantity\n(1/2/3/q): ");
    int choice;
    scanf("%i%*c", &choice);
    switch (choice) 
    {
    case 1: {
      printf("PNAME: ");
      scanf("%s%*c",(pro+i)->name);//fgets later
      break;
    }
    case 2: {
      printf("PRICE: ");
      scanf("%f%*c", (pro+i)->price);
      break;
    }
    case 3: {
      printf("QUANTITY: ");
      scanf("%i%*c",(pro+i)->quantity);
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
    printf("%i\t\t%s\t\t%0.3f\t\t%i\n", (pro+i)->id, (pro+i)->name,(pro+i)->price, (pro+i)->quantity);
  }
}
void DelPro(Product *pro)//works'.
{
  int pid,j=0;
  printf("\n## DELETE PRODUCT ##\n");
  printf("PID: ");
  scanf("%i%*c", &pid);

  for(int i=0;i<Pitems;i++)
  {
    if(pid==(pro+i)->id||j>0)
    {
      j=1;
      char *temp;
    
      (pro+i)->id=(pro+i+j)->id;
      strcpy((pro+i)->name,(pro+i+j)->name);
      (pro+i)->price=(pro+i+j)->price;
      (pro+i)->quantity=(pro+i+j)->quantity;
    }
  }
  Pitems--;
}