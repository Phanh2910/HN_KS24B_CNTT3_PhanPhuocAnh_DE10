#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct Employee {
    char name[50];
    char date[50];
    struct Employee *next;
    struct Employee *prev;
} Employee;

void printScreen() {
    printf("======HUMAN RESOURCE MANAGER======\n");
    printf("1. Tao giam doc\n");
    printf("2. Them nhan vien cap duoi\n");
    printf("3. In so do nhan su\n");
    printf("4. Tim kiem theo ten nhan su\n");
    printf("5. Tinh chieu cao he thong nhan su\n");
    printf("6. in duong dan tu CEO -> Nhan su bat ky\n");
    printf("7. Exit\n");
    printf("===================================\n");
    printf("Nhap lua chon cua ban: ");
}



int main() {
    int choice;
    do {
        printScreen();
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                printf("Thoat chuong trinh thanh cong");
                break;
            default:
                printf("Lua chon khong hop le, hay chon lai");
                break;
        }
    }while (choice != 7);

    return 0;
}



