#include <stdio.h>
#include "ProductModule.c"
#include "SupplierModule.c"
#include "TransactionsModule.c"
#include "Reqs.c"

int main() 
{
  printf("=================INVENTORY MANAGEMENT=================\n");
  
  int Pid[limit];
  char Pname[limit][25];
  float Pprice[limit];
  int Pquantity[limit];

  int Sid[limit];
  char Sname[limit][25];
  char Sadd[limit][200];

  int Tid[limit];
  int Tpid[limit];
  int Tquantity[limit];
  char date[limit][10];

  char ch;
  char sch;
  do {
    printf("# OPTION #\n(1) Product Module\n(2) Supplier Module\n(3) Transaction Module\n(q) QUIT(1/2/3/q): ");
    scanf("%c%*c", &ch);
    switch (ch) 
    {
    case '1': {
      printf("\n################ OPTIONS ################\n(1) Add Product\n(2) Update Product\n(3) Display Products\n(4) Delete Product\n(q) QUIT(1/2/3/4/q): ");
      scanf("%c%*c", &sch);      
      switch (sch) 
      {
      case '1': 
      {
        AddPro(Pid, Pname, Pprice, Pquantity);
        break;
      }
      case '2': 
      {
        UpPro(Pid, Pname, Pprice,Pquantity);
        break;
      }
      case '3': 
      {
        DispPro(Pid, Pname, Pprice,Pquantity);
        break;
      }
      case '4': 
      {
        DelPro(Pid, Pname, Pprice,Pquantity);
        break;
      }
      case 'q': 
      {
        break;
      }
      default: 
      {
        printf("Invalid ch.\n");
      }
      }
      break;
    }
    case '2': {
      printf("\n## SUPPLIER OPTIONS ##\n1. Add Supplier\n2. Update Supplier\n3. Display Suppliers\n4. Delete Supplier\n(1/2/3/4/q): ");

      scanf("%c%*c", &sch);
      switch (sch) {
      case '1': 
      {
        AddSup(Sid, Sname, Sadd);
        break;
      }
      case '2': 
      {
        UpSup(Sid, Sname, Sadd);
        break;
      }
      case '3': 
      {
        DispSup(Sid, Sname, Sadd);
        break;
      }
      case '4': 
      {
        DelSup(Sid, Sname, Sadd);
        break;
      }
      case 'q': 
      {
        break;
      }
      default: {
        printf("Invalid ch.\n");
      }
      }

      break;
    }
    case '3': {
      printf("\n## TRANSACTION OPTIONS ##\n1. Add Transaction\n2. Update Transaction\n3. Display Transactions\n(1/2/3/4/q): ");
      scanf("%c%*c", &sch);
      switch (sch) 
      {
      case '1': {
        AddTrans(Tid, Tpid, Tquantity,date);
        break;
      }
      case '2': {
        UpTrans(Tid, Tpid, Tquantity,date);
        break;
      }
      case '3': {
        DispTrans(Tid, Tpid,Tquantity, date);
        break;
      }
      case 'q':
        break;
      default:
        printf("Invalid ch.\n");
      }
      break;
    }
    case 'q': {
      printf("================= exitting =================\n");
      break;
    }
    default: {
      printf("invalid option\n");
      continue;
    }
    }
  }while (ch != 'q');
  return 0;
}
