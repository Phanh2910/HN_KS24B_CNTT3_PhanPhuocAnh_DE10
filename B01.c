#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Book {
    int id;
    char title[100];
    float price;
    char author[100];
    char category[100];
    char date[20];
    struct Book *prev;
    struct Book *next;
} Book;

typedef struct Rental {
    Book book;
    struct Rental *next;
} Rental;

Book *head = NULL;
Book *tail = NULL;
Rental *rentalHead = NULL;

Book *createBook() {
    Book *b = (Book *)malloc(sizeof(Book));
    printf("ID: ");
    scanf("%d", &b->id);
    printf("Title: ");
    getchar(); fgets(b->title, 100, stdin); strtok(b->title, "\n");
    printf("Price: ");
    scanf("%f", &b->price);
    printf("Author: ");
    getchar(); fgets(b->author, 100, stdin); strtok(b->author, "\n");
    printf("Category: ");
    fgets(b->category, 100, stdin); strtok(b->category, "\n");
    printf("Date: ");
    fgets(b->date, 20, stdin); strtok(b->date, "\n");
    b->prev = NULL;
    b->next = NULL;
    return b;
}

void addBook() {
    Book *b = createBook();
    if (head == NULL) {
        head = tail = b;
    } else {
        tail->next = b;
        b->prev = tail;
        tail = b;
    }
}

void displayBooks() {
    Book *cur = tail;
    while (cur != NULL) {
        printf("ID: %d\nTitle: %s\nPrice: %.2f\nAuthor: %s\nCategory: %s\nDate: %s\n\n",
               cur->id, cur->title, cur->price, cur->author, cur->category, cur->date);
        cur = cur->prev;
    }
}

void deleteBook() {
    int id;
    printf("Nhap id can xoa: ");
    scanf("%d", &id);
    Book *cur = head;
    while (cur != NULL) {
        if (cur->id == id) {
            if (cur == head && cur == tail) {
                head = tail = NULL;
            } else if (cur == head) {
                head = cur->next;
                head->prev = NULL;
            } else if (cur == tail) {
                tail = cur->prev;
                tail->next = NULL;
            } else {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            free(cur);
            return;
        }
        cur = cur->next;
    }
}

void updateBook() {
    int id;
    printf("Nhap id cap nhat: ");
    scanf("%d", &id);
    Book *cur = head;
    while (cur != NULL) {
        if (cur->id == id) {
            printf("ten moi: ");
            getchar(); fgets(cur->title, 100, stdin); strtok(cur->title, "\n");
            printf("Ngay san xuat: ");
            fgets(cur->date, 20, stdin); strtok(cur->date, "\n");
            printf("Gia moi: ");
            scanf("%f", &cur->price);
            printf("Ten tac gia: ");
            getchar(); fgets(cur->author, 100, stdin); strtok(cur->author, "\n");
            return;
        }
        cur = cur->next;
    }
}

void rentBook() {
    char title[100];
    printf("Nhap tieu de moi: ");
    getchar(); fgets(title, 100, stdin); strtok(title, "\n");
    Book *cur = head;
    while (cur != NULL) {
        if (strcmp(cur->title, title) == 0) {
            if (cur == head && cur == tail) {
                head = tail = NULL;
            } else if (cur == head) {
                head = cur->next;
                if (head) head->prev = NULL;
            } else if (cur == tail) {
                tail = cur->prev;
                if (tail) tail->next = NULL;
            } else {
                cur->prev->next = cur->next;
                cur->next->prev = cur->prev;
            }
            Rental *r = (Rental *)malloc(sizeof(Rental));
            r->book = *cur;
            r->next = rentalHead;
            rentalHead = r;
            free(cur);
            return;
        }
        cur = cur->next;
    }
}
int main() {
    int choice;
    while (1) {
        printf("======BOOK STORE MANAGER======\n");
        printf("1. Them moi sach\n");
        printf("2. Hien thi sach\n");
        printf("3. Xoa sach\n");
        printf("4. Cap nhat cho thue\n");
        printf("5. Danh dau cho thue\n");
        printf("6. Sap xep sach\n");
        printf("7. Tim kiem sach\n");
        printf("8. Thoat\n");
        printf("===============================\n");
        printf("Nhap lua chon: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                displayBooks();
                break;
            case 3:
                deleteBook();
                break;
            case 4:
                updateBook();
                break;
            case 5:
                rentBook();
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                printf("Thoat chuong trinh thanh cong\n");
            default:
                printf("Lua chon khong phu hop, hay chon lai");
        }
    }
    return 0;
}

