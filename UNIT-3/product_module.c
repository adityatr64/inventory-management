#include <stdio.h>
extern const int limit;
extern int Pitems;
extern int check(int id, ids *id_path, int Elements);


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
   (pro+Pitems)->id.id=pid;

    printf("PNAME: ");
    scanf("%s%*c",(pro + Pitems)->name);

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