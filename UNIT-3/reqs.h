#ifndef REQS_H
#define REQS_H

#define strLimit 100

typedef struct Product
{
    int id;
    char name[strLimit];
    float price;
    int quantity;
}Product;
typedef struct Supplier
{
    int id;
    char name[strLimit];
    char address[strLimit];
}Supplier;
typedef struct Transaction
{
    int id;
    char date[10];
    int pid;
    int quantity;
}Transaction;


int check_pro(int id, Product *pro, int max_count)
{
    for (int i = 0; i < max_count; i++) {
      if ((pro+i)->id == id) 
      {
        return 1;
      }
    }
    return 0;
}


int check_sup(int id, Supplier *sup, int max_count)
{
    for (int i = 0; i < max_count; i++) {
      if ((sup+i)->id == id) 
      {
        return 1;
      }
    }
    return 0;
}


int check_trans(int id, Transaction *trans, int max_count)
{
    for (int i = 0; i < max_count; i++) {
      if ((trans+i)->id == id) 
      {
        return 1;
      }
    }
    return 0;
}

#endif