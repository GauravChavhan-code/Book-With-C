#include"book.h"

void storebook(struct Book* arr, int size) {
    for(int i=0;i<size;i++) { // Assuming a maximum of 100 books for this example
        printf("\nEnter Book ID: ");
        scanf("%s", &(arr[i].BookID));

        printf("Enter Book Name: ");
        scanf(" %s", arr[i].Bookname);

        printf("Enter Author Name: ");
        scanf(" %s", arr[i].authorName);

        printf("Enter Price: ");
        scanf("%lf", &(arr[i].price));

        printf("Enter Rating: ");
        scanf("%f", &(arr[i].rating));
    } 
}


void displayBook(struct Book* arr, int size)
{
    if (size == 0) {
        printf("No books to display.\n");
        return;
    }

     printf("\nDisplaying all books:\n");
    printf(" | Book Name    | ISBN No   | Author Name | Price   | Rating\n");
    for (int i = 0; i < size; i++) {
        printf("|-------------|-------------|-------------|-------------|-------------|\n");
        printf("|  %-15s |  %-10s |  %-11s |  %-7.2lf |  %-6.2f\n", arr[i].Bookname, arr[i].BookID, arr[i].authorName, arr[i].price, arr[i].rating);
    }
    printf("|-------------|-------------|-------------|-------------|-------------|\n");

}

void searchBook(struct Book* arr, int size)
{
    int searchChoice;
    printf("\nSearch by:\n");
    printf("1. Book ID\n");
    printf("2. Book Name\n");
    printf("3. Author Name\n");
    printf("Enter your choice: ");
    scanf("%d", &searchChoice);

    switch (searchChoice)
    {
        case 1:
        {
            char targetID[10];
            printf("Enter Book ID to search for: ");
            scanf("%s", &targetID);

            int found = 0;
            for (int i = 0; i < size; i++)
{
                if (strcmp(arr[i].BookID,targetID)==0)
                {
                    found = 1;
                    printf("\nBook ID: %s", arr[i].BookID);
                    printf("\nBook Name: %s", arr[i].Bookname);
                    printf("\nAuthor Name: %s", arr[i].authorName);
                    printf("\nPrice: %.2f", arr[i].price);
                    printf("\nRating: %.1f\n", arr[i].rating);
                    break; // Found the book, no need to continue searching
                }
            }

            if (!found)
                printf("Book with ID %s not found.\n", targetID);
            break;
        }

        case 2:
        {
            char targetName[100]; // Assuming a maximum length of 100 characters for Bookname
            printf("Enter Book Name to search for: ");
            scanf(" %[^\n]s", targetName);

            int found = 0;
            for (int i = 0; i < size; i++)
            {
                if (strcmp(arr[i].Bookname, targetName) == 0)
                {
                    found = 1;
                    printf("\nBook ID: %s", arr[i].BookID);
                    printf("\nBook Name: %s", arr[i].Bookname);
                    printf("\nAuthor Name: %s", arr[i].authorName);
                    printf("\nPrice: %.2f", arr[i].price);
                    printf("\nRating: %.1f\n", arr[i].rating);
                }
            }

            if (!found)
                printf("No books with the name '%s' found.\n", targetName);
            break;
        }
        

        case 3:
        {
            char targetAuthor[100]; // Assuming a maximum length of 100 characters for authorName
            printf("Enter Author Name to search for: ");
            scanf(" %[^\n]s", targetAuthor);

            int found = 0;
            for (int i = 0; i < size; i++)
            {
                if (strcmp(arr[i].authorName, targetAuthor) == 0)
                {
                    found = 1;
                    printf("\nBook ID: %s", arr[i].BookID);
                    printf("\nBook Name: %s", arr[i].Bookname);
                    printf("\nAuthor Name: %s", arr[i].authorName);
                    printf("\nPrice: %.2f", arr[i].price);
                    printf("\nRating: %.1f\n", arr[i].rating);
                }
            }

            if (!found)
                printf("No books by the author '%s' found.\n", targetAuthor);
            break;
        }

        default:
            printf("Invalid choice for search.\n");
    }
}

void updateBook(struct Book* arr, int size)
{
    char targetID[10];
    printf("Enter the Book ID to update: ");
    scanf("%s", &targetID);

    int found = 0;
    for (int i = 0; i < size; i++)
    {
        if (strcmp(arr[i].BookID,targetID)==0)
        {
            found = 1;

            printf("\nBook ID: %s", arr[i].BookID);
            printf("\nBook Name: %s", arr[i].Bookname);
            printf("\nAuthor Name: %s", arr[i].authorName);
            printf("\nPrice: %.2f", arr[i].price);
            printf("\nRating: %.1f\n", arr[i].rating);

            
            printf("Enter new Price: ");
            scanf("%lf", &arr[i].price);

            printf("Enter new Rating: ");
            scanf("%f", &arr[i].rating);

            printf("\nBook updated successfully!\n");
            break; // No need to continue searching
        }
    }

    if (!found)
        printf("Book with ID %s not found.\n", targetID);
}


void displayTopThreeBooks(struct Book* arr, int size)
{
    if (size < 3)
    {
        printf("Not enough books to display top three.\n");
        return;
    }
// Sort books by rating (you can use any sorting algorithm here)
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j].rating < arr[j + 1].rating)
            {
                struct Book temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            
        }
    }

    printf("\nTop Three Books:\n");
    for (int i = 0; i < 3; i++)
    {
        printf("\nBook ID: %s", arr[i].BookID);
        printf("\nBook Name: %s", arr[i].Bookname);
        printf("\nAuthor Name: %s", arr[i].authorName);
        printf("\nPrice: %.2f", arr[i].price);
        printf("\nRating: %.1f\n", arr[i].rating);
    }
}


void removeBook(struct Book* arr, int* size)
{
    char targetID[10];
    printf("Enter Book ID to remove: ");
    scanf("%s", &targetID);

    int found = 0;
    for (int i = 0; i < *size; i++)
    {
        if (strcmp(arr[i].BookID,targetID)==0)
        {
            found = 1;

            // Move the last book to the current position to "remove" the book
            arr[i] = arr[*size - 1];
            (*size)--;

            printf("Book with ID %s removed successfully.\n", targetID);
            break; // No need to continue searching
        }
    }

    if (!found)
        printf("Book with ID %s not found.\n", targetID);
}
void addBook(struct Book* arr, int size)
{
    printf("\nEnter Book ID: ");
    scanf("%s", &(arr[size - 1].BookID)); // Using size - 1 to access the last element

    printf("Enter Book Name: ");
    scanf(" %s", arr[size - 1].Bookname); 

    printf("Enter Author Name: ");
    scanf(" %s", arr[size - 1].authorName);

    printf("Enter Price: ");
    scanf("%lf", &(arr[size - 1].price));

    printf("Enter Rating: ");
    scanf("%f", &(arr[size - 1].rating));

    printf("Book added successfully!\n");
}