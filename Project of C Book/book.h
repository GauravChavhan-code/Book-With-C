#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
    char BookID[10]; // Assuming a maximum length of 10 characters for BookId
    char Bookname[100];  // Assuming a maximum length of 100 characters for Bookname
    char authorName[100];  // Assuming a maximum length of 100 characters for authorName
    double price;
    float rating;
};
void storebook(struct Book*,int);
void displayBook(struct Book* , int );
void searchBook(struct Book* , int );
void updateBook(struct Book* , int );
void displayTopThreeBooks(struct Book* , int );
void removeBook(struct Book* , int* );
void addBook(struct Book* , int );
