#include<string.h>
#include<stdio.h> 
#include <stdlib.h>


typedef struct DataProduct//creating a struct
{
    size_t productId,productPrice,quantity;
    char productName[100];
}DataProduct;
void addProduct()
{
    FILE *fileptr;
    fileptr=fopen("Entries.dat","ab");//opeing the file
    if(fileptr==NULL)//if there is an error opening file
    {
        printf("Invalid File creating");
    }                                                                       //append to existing
    DataProduct p1;
    printf("enter the values: ");//taking user input
    scanf("%zu%zu%zu",&p1.productId,&p1.productPrice,&p1.quantity);getchar();
    fgets(p1.productName,100,stdin);//this is seperate because its a character
    fwrite(&p1,sizeof(DataProduct),1,fileptr);//writes the scaned thing into the file
    fclose(fileptr);//close file
}
void fetchProduct(int datano)//serial no wise  (this is prolly faster)
{
    FILE *fileptr;
    DataProduct product;
    fileptr=fopen("Entries.dat","rb");//opeing file to read in binary
    if(fileptr==NULL)//if it doesnt exist
    {
        printf("Invalid File");
        exit(1);
    }
    fseek(fileptr,128*datano,SEEK_CUR);//move the pointer to required point in the file
        fread(&product,sizeof(DataProduct),1,fileptr);//the the value at the pointer
        if(feof(fileptr))
        {
            printf("Not found");
        }
        else
        {
            printf("name:%sid:%zu \n",product.productName,product.productId);//printf the values 
        }
    fclose(fileptr);//closes the file
}
void updateProduct(size_t ID,DataProduct newProductData )
{
    FILE *fileptr;
    DataProduct product;
    fileptr=fopen("Entries.dat","r+b");//read and wirte in binary
    if(fileptr==NULL)
    {
        printf("Invalid File");
        exit(1);
    }
    while(fread(&product, sizeof(DataProduct), 1, fileptr))//go through each entry till it reaches the required entry
    {
        if(product.productId == ID)
        {
            printf("here");
            fseek(fileptr, -sizeof(DataProduct), SEEK_CUR);//sets the pointer to the start of the required value
            fwrite(&newProductData, sizeof(DataProduct), 1, fileptr);//rewirtes the value
            break;//exit the loop after writing
        }
    }
    fclose(fileptr);//closes file
}
void deleteProduct(size_t ID)// check if u have diffrent meathod
{
    DataProduct product;
    FILE *fileptr = fopen("Entries.dat", "rb");

    FILE *tempFileptr = fopen("temp.dat", "wb");//makes temp file
    if (fileptr == NULL || tempFileptr == NULL) 
    {
        printf("Error! Can't open file.\n");
        exit(1);
    }
    while(fread(&product, sizeof(DataProduct), 1, fileptr)) 
    {
        if(product.productId != ID) 
        {
            fwrite(&product, sizeof(DataProduct), 1, tempFileptr);
        }
    }
    fclose(fileptr);
    fclose(tempFileptr);
    remove("Entries.dat");
    rename("temp.dat", "Entries.dat");
}

void ProductMang()
{
    int c,n=1;
    printf("(1).Add a Product\n(2).Fetch a Product\n(3).Update a Product\n(4).Delete a Product\nEnter the option: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            addProduct();
            break;
        case 2:
            printf("Enter the id of product: ");
            scanf("%d",&n);
            fetchProduct(n-1);
            break;
        case 3:
            printf("Enter the details of product: ");
            DataProduct p1={1,900,5,"works,yes it does"};
            updateProduct(p1.productId, p1);
            break;
        case 4:
            printf("Enter product ID : ");
            scanf("%d",&n);
            deleteProduct(n);
            break;
        default:
            printf("wrong option!\n");
    }
}
