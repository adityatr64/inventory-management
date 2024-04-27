typedef struct Product
{
    int id;
    char name[25];
    float price;
    int quantity;
}Product;
typedef struct Supplier
{
    int id;
    char name[25];
    char address[200];
}Supplier;
typedef struct Transaction
{
    int id;
    char date[10];
    float pid;
    int quantity;
}Transaction;
