#include"book.h"

int main()
{
    int size;
    printf("Enter the number of books you want to store:");
    scanf("%d", &size);
    struct Book* arr = (struct Book*)malloc(sizeof(struct Book) * size);
    
    storebook(arr,size);
    
    
    char ch;
    do
    {
        printf("\n Book management system\n");
        printf("1. Add new Book\n");
        printf("2. Remove Book\n");
        printf("3. Search Book\n");
        printf("4. Update Book\n");
        printf("5. Display Top Three Books\n");
        printf("6. Display all Book\n");
        printf("7. Exit\n");
        printf("\nEnter your Choice:");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            size++;
            addBook(arr, size);
            break;

        case 2:{
      int BookID;
            
            removeBook(arr, &size);
            break;
        }

        case 3:
            searchBook(arr, size);
            break;

        case 4:
            updateBook(arr, size);
            break;

        case 5:
            displayTopThreeBooks(arr, size);
            break;

        case 6:
            displayBook(arr, size);
            break;

        case 7:
            printf("Exiting the program.\n");
            free(arr); // Free allocated memory before exiting
            return 0;

        default:
            printf("Invalid Choice. Please select a valid option.\n");
            break;
        }
        printf("\nDo you want to continue? (y/n): ");
        scanf(" %c", &ch);

    } while (ch == 'y' || ch == 'Y');

    free(arr); // Free allocated memory before exiting
    return 0;
}

