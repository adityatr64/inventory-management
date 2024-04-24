#include<string.h>
#include<stdio.h> 
#include <stdlib.h>


typedef struct DataSupplier//creating a struct
{
    size_t supplierId;
    char supplierName[100];
    char supplierAddress[2048];
}DataSupplier;

void addSupplier()
{
    FILE *fileptr;
    fileptr=fopen("Entries_sup.dat","ab");//opeing the file
    if(fileptr==NULL)//if there is an error opening file
    {
        printf("Invalid File creating");
    }
    //append to existing
    DataSupplier s1;
    printf("enter the values: ");//taking user input
    scanf("%zu",&s1.supplierId);getchar();
    fgets(s1.supplierName,100,stdin);//this is seperate because its a character
    fgets(s1.supplierName,2048,stdin);//this is seperate because its a character
    fwrite(&s1,sizeof(DataSupplier),1,fileptr);//writes the scaned thing into the file
    fclose(fileptr);//close file
}
void fetchSupplier(int datano)//serial no wise  (this is prolly faster)
{
    FILE *fileptr;
    DataSupplier supplier;
    fileptr=fopen("Entries_sup.dat","rb");//opeing file to read in binary
    if(fileptr==NULL)//if it doesnt exist
    {
        printf("Invalid File");
        exit(1);
    }
    fseek(fileptr,128*datano,SEEK_CUR);//move the pointer to required point in the file
        fread(&supplier,sizeof(DataSupplier),1,fileptr);//the the value at the pointer
        if(feof(fileptr))
        {
            printf("Not found");
        }
        else
        {
            printf("name:%sid:%zu \n",supplier.supplierName,supplier.supplierId);//printf the values 
        }
    fclose(fileptr);//closes the file
}
void updateSupplier(size_t ID,DataSupplier newSupplierData )
{
    FILE *fileptr;
    DataSupplier supplier;
    fileptr=fopen("Entries_sup.dat","r+b");//read and wirte in binary
    if(fileptr==NULL)
    {
        printf("Invalid File");
        exit(1);
    }
    while(fread(&supplier, sizeof(DataSupplier), 1, fileptr))//go through each entry till it reaches the required entry
    {
        if(supplier.supplierId == ID)
        {
            printf("here");
            fseek(fileptr, -sizeof(DataSupplier), SEEK_CUR);//sets the pointer to the start of the required value
            fwrite(&newSupplierData, sizeof(DataSupplier), 1, fileptr);//rewirtes the value
            break;//exit the loop after writing
        }
    }
    fclose(fileptr);//closes file
}
void deleteSupplier(size_t ID)// check if u have diffrent meathod
{
    DataSupplier supplier;
    FILE *fileptr = fopen("Entries_sup.dat", "rb");

    FILE *tempFileptr = fopen("temp.dat", "wb");//makes temp file
    if (fileptr == NULL || tempFileptr == NULL) 
    {
        printf("Error! Can't open file.\n");
        exit(1);
    }
    while(fread(&supplier, sizeof(DataSupplier), 1, fileptr)) 
    {
        if(supplier.supplierId != ID) 
        {
            fwrite(&supplier, sizeof(DataSupplier), 1, tempFileptr);
        }
    }
    fclose(fileptr);
    fclose(tempFileptr);
    remove("Entries_sup.dat");
    rename("temp.dat", "Entries_sup.dat");
}
void SupplierMang()
{
    int c,n=1;
    printf("(1).Add a Supplier\n(2).Fetch a Supplier\n(3).Update a Supplier\n(4).Delete a Supplier\nEnter the option: ");
    scanf("%d",&c);
    switch(c)
    {
        case 1:
            addSupplier();
            break;
        case 2:
            printf("Enter the id of Supplier: ");
            scanf("%d",&n);
            fetchSupplier(n-1);
            break;
        case 3:
            printf("Enter the details of Supplier: ");
            DataSupplier p1={1,"works,yes it does","Adress"};
            updateSupplier(p1.supplierId, p1);
            break;
        case 4:
            printf("Enter Supplier ID : ");
            scanf("%d",&n);
            deleteSupplier(n);
            break;
        default:
            printf("wrong option!\n");
    }
}

