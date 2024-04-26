#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct customer{
    char username[100];
    char password[100];
    struct customer *next;
}*user;
typedef struct customer customer;
void sign_up(customer* users, int* numUsers)
 {
    (*numUsers)++;
    
    users = ( customer*)malloc(2 * sizeof(struct customer));
    if (users == NULL) {
        printf("Memory allocation failed!\n");
        //exit(1);
    }
    printf("Enter username: ");
    scanf("%s", ((users+*numUsers - 1))->username);
    printf("Enter password: ");
    scanf("%s", (users)[*numUsers - 1].password);
    printf("User signed up successfully!\n");
}

int log_in(struct customer** users, int numUsers) 
{
    char *username=(char *)malloc(sizeof(char)*50);
    char *password=(char *)malloc(sizeof(char)*50);
    printf("Enter username: ");
    scanf("%s%*c", username);
    printf("Enter password: ");
    scanf("%s%*c", password);
    printf("here");
    for (int i = 0; i < numUsers; i++)
     {
            printf("there");
        if (strcmp((*users)[i].username, username) == 0 && strcmp((*users)[i].password, password) == 0) {
            printf("Login successful!\n");
            return 1;
        }
    }
    printf("Login failed! Incorrect username or password.\n");
    return 0;
}

int main(){
    int choice;
    int choice2;
    int choice3;
    struct customer c;
    int userCount = 0;
    struct customer* users = NULL;

    main_menu:
    printf("\n");
    printf("^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
    printf("                                       WELCOME  TO  SHOP                                             \n");
    printf("=====================================================================================================\n");
    options:
    printf("\n\n");
    printf("1. ADMINISTRATOR\n");
    printf("2. CUSTOMER\n");
    printf("3. EXIT\n");
    printf("\n");
    printf("=====================================================================================================\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n\n");
    switch (choice)
    {
    case 1:
    printf("*****************************************************************************************************\n");
    printf("                                          ADMINISTRATOR                                              \n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("1. HOME\n");
    printf("2. ADMIN DETAILS\n");
    printf("3. ADMIN COMMANDS\n");
    printf("4. SETTINGS\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
        break;
    case 2:
    signup:
    printf("Choose SIGN UP or LOG IN: \n 1.SIGN UP \n 2.LOG IN\n 3.EXIT\n");
        scanf("%d", &choice2);

        switch (choice2)
        {
        case 1:
        printf("*****************************************************************************************************\n");
        printf("                                       CREATE AN ACCOUNT                                             \n");
        sign_up(&users, &userCount);
        goto customer_options;
        printf("-----------------------------------------------------------------------------------------------------\n");
        break;
        case 2:
        printf("*****************************************************************************************************\n");
        printf("                                 LOG IN TO AN EXISTING ACCOUNT                                       \n");
        if (log_in(&user, userCount)) 
        {
            printf("Login successful!\n");
            customer_options:
            printf("*****************************************************************************************************\n");
            printf("                                            CUSTOMER                                                 \n");
            printf("-----------------------------------------------------------------------------------------------------\n\n");
            printf("1. CUSTOMER PROFILE\n");
            printf("2. ITEMS\n");
            printf("3. CUSTOMER CART\n");
            printf("4. CUSTOMER POLICIES\n");
            printf("5. LOG IN \\ SIGN UP PAGE\n");
            printf("6. EXIT\n");
            printf("-----------------------------------------------------------------------------------------------------\n");
            printf("Enter your choice: ");
            scanf("%d", &choice3);
            switch (choice3)
            {
            case 1:
                printf("*****************************************************************************************************\n");
                printf("                                     CUSTOMER PROFILE                                                \n");
                printf("Username: \n");
                printf("Password: \n");
                printf("-----------------------------------------------------------------------------------------------------\n");
                break;
            case 2:
                printf("*****************************************************************************************************\n");
                printf("                                            ITEMS                                                    \n");
                printf("");
                printf("-----------------------------------------------------------------------------------------------------\n");
                break;
            case 3:
                printf("*****************************************************************************************************\n");
                printf("                                      PRODUCT DETAILS                                                \n");
                printf("-----------------------------------------------------------------------------------------------------\n");
                break;
            case 4:
                printf("*****************************************************************************************************\n");
                printf("                                     CUSTOMER POLICIES                                               \n");
                printf("-----------------------------------------------------------------------------------------------------\n");
                break;
            case 5:
                goto signup;
                break;
            case 6:
                goto exit;
                break;
            default:
                printf("INVALID NUMBER TYPED");
                break;
            }
        } else {
            printf("Invalid username or password. Please try again.\n");
                }
            printf("-----------------------------------------------------------------------------------------------------\n");
        break;
        
        case 3:
            goto exit;
            break;

        default:
            printf("INVALID NUMBER TYPED");
            break;
        }
    

    case 3:
    exit:
    free(users);
    printf("*****************************************************************************************************\n");
    printf("                                              EXIT                                                   \n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    return 0;

    default:
    printf("INVALID NUMBER TYPED");
        break;
    }
}
