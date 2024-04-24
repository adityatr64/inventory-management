#include <stdio.h>
#include "productDetailsModule.c"
#include "supplierDetailsModule.c"
int main(void)
//each entry is 128 bytes remember
{
    int c;
    printf("(1)Product Management\n(2)Supplier Management\n");
    scanf("%d",&c);
    switch (c)
    {
        case 1:
        ProductMang();
        break;
        case 2:
        SupplierMang();
        break;
        default:
        printf("lmao!");
    }
    return 0;
}