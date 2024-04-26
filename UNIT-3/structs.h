typedef struct ids
{
    int id;
}ids;
typedef struct Product
{
    ids id;
    char name[25];
    float price;
    int quantity;
}Product;
typedef struct Supplier
{
    ids id;
    char name[25];
    float address[200];
}Supplier;
typedef struct Transaction
{
    ids id;
    char date[10];
    float pid;
    int quantity;
}Transaction;
