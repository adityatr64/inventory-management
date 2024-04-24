#include <stdio.h>

extern const int limit;
extern int Sitems;
extern int check(int id, int *id_array, int Elements);

void AddSup(int *Sid, char Sname[][25],char Sadd[][200]) 
{
  if (Sitems < limit) 
  {
    printf("### Add Supplier ###\n");
    int sid;
    printf("SUPPLIER ID: ");
    s_here:
    scanf("%d%*c", &sid);
    if(check(sid, Sid,Sitems))
    {
      printf("ID already exists \nEnter a Diffrent ID: ");
      goto s_here;
    }
    *(Sid + Sitems)=sid;

    printf("SUPPLIER NAME: ");
    scanf("%s%*c",*(Sname + Sitems));

    printf("SUPPLIER ADDRESS: ");
    fgets(*(Sadd+Sitems),200,stdin);
    for(int i=0;i<200
    ;i++)
    {
        if(*(*(Sadd+Sitems)+i)=='\n')
        {
            *(*(Sadd+Sitems)+i)='\0';
            break;
        }
    }
    
    (Sitems)++;

    printf("Supplier has been added.\n");
  } 
  else 
  {
    printf("Supplier array is full. Cannot add more products.\n");
  }
}

void DispSup(int *Sid, char Sname[][25],char Sadd[][200]) 
{
  printf("%s\t\t%s\t\t%s\n", "ID", "NAME", "ADDR");
  for (int i = 0; i < Sitems; i++) 
  {
    printf("%i\t\t%s\t\t%s\n", *(Sid+i), *(Sname+i),*(Sadd+i));
  }
}
void UpSup(int *Sid, char Sname[][25],char Sadd[][200]) 
{
  int supid;
  printf("\n## Update Supplier ##\n");
  printf("PID: ");
  scanf("%d%*c", &supid);

  // find the product
  for (int i = 0; i < Sitems; i++) 
  {
    if (Sid[i] != supid) 
    {
      continue;
    }
    printf("%s\t\t%s\t\t%s\n", "ID", "NAME", "ADDR");
    printf("%d\t\t%s\t\t%s\n", *(Sid+i), *(Sname+i),*(Sadd+i));

    printf("1. Update Name\n2. Update Address\n(1/2/q): ");
    int choice;
    scanf("%d%*c", &choice);
    switch (choice) 
    {
    case 1: 
    {
      printf("SUP NAME: ");
      scanf("%s%*c",*(Sname+i));
      break;
    }
    case 2: 
    {
      printf("SUP ADDRESS: ");
      scanf("%s%*c",*(Sadd + i));
      break;
    }
    case 'q': 
    {
      printf("================= exitting =================");
      break;
    }
    default: 
    {
      printf("Invalid choice");
      break;
    }
    }

    printf("%s\t\t%s\t\t%s\n", "ID", "NAME", "ADDR");
    printf("%d\t\t%s\t\t%s\n", *(Sid+i), *(Sname+i),*(Sadd+i));
  }
}

void DelSup(int Sid[], char Sname[][25],char Sadd[][200]) 
{
  int sid,j=0;
  printf("\n## DELETE SUPPLIER ##\n");
  printf("SUPPLIER ID : ");
  scanf("%d%*c", &sid);
  
  for(int i=0;i<Sitems;i++)
  {
    if(sid==*(Sid+i)||j>0)
    {
      j=1;
      *(Sid+i)=*(Sid+i+j);
      for(int k=0;k<25;k++)
      {
        *(*(Sname+i)+k)=*(*(Sname+i+j)+k);
      }
      for(int k=0;k<200;k++)
      {
        *(*(Sadd+i)+k)=*(*(Sadd+i+j)+k);
      }
    }
  } 
  Sitems--;
}