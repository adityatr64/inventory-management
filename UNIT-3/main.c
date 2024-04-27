#include <stdlib.h>
#include <stdio.h>
#include "structs.h"
#include "product_module.c"
#include "supplier_module.c"
// #include "Reqs.c"

const int limit = 512;
int Pitems = 0;
int Titems = 0;
int Sitems = 0;

int main() 
{
    Product *pro=(Product*)malloc(limit*sizeof(Product));
    Supplier *sup=(Supplier*)malloc(limit*sizeof(Supplier));
    Transaction *trans=(Transaction*)malloc(limit*sizeof(Transaction));
    printf("===================================================INVENTORY MANAGEMENT=====================================================\n");
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
            AddPro(pro);
            break;
        }
        case '2': 
        {
            UpPro(pro);
            break;
        }
        case '3': 
        {
            DispPro(pro);
            break;
        }
        case '4': 
        {
            DelPro(pro);
            break;
        }
        case 'q': 
        {
            break;
        }
        default: 
        {
            getchar();
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
            AddSup(sup);
            break;
        }
        case '2': 
        {
            // UpSup(sup);
            break;
        }
        case '3': 
        {
            DispSup(sup);
            break;
        }
        case '4': 
        {
            // DelSup(Sid, Sname, Sadd);
            break;
        }
        case 'q': 
        {
            break;
        }
        default: {
            printf("Invalid ch.\n");
            getchar();
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
            // AddTrans(Tid, Tpid, Tquantity,date);
            break;
        }
        case '2': {
            // UpTrans(Tid, Tpid, Tquantity,date);
            break;
        }
        case '3': {
            // DispTrans(Tid, Tpid,Tquantity, date);
            break;
        }
        case 'q':
            break;
        default:
            printf("Invalid ch.\n");
            getchar();
        }
        break;
        }
        case 'q': {
        printf("================= exitting =================\n");
        break;
        }
        default: {
        printf("invalid option\n");
        getchar();
        continue;
        }
        }
    }while (ch != 'q');
    return 0;
}
