#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_CD 100

struct CD {
    int id;
    char name[50];
    float duration;
    char content[100];
    bool status;
};
struct CD cdList[MAX_CD];
int cdCount = 2;
void displayMenu() {
    printf("\n************************MENU**************************\n");
    printf("1. In toan bo danh sach CD\n");
    printf("2. Them moi CD\n");
    printf("3. Cap nhat thong tin CD\n");
    printf("4. Xoa CD\n");
    printf("5. Sap xep danh sach CD theo thoi luong tang dan\n");
    printf("6. Tim kiem CD theo ten\n");
    printf("7. Tim kiem va in ra toan bo thong tin CD theo trang thai\n");
    printf("*******************************************************\n");
}

void printCDList() {
    printf("\nDanh sach CD:\n");
    printf("| %-5s | %-30s | %-10s | %-50s | %-7s |\n", "ID", "Ten CD", "Thoi luong", "Noi dung", "Status");
    for (int i = 0; i < cdCount; i++) {
        printf("| %-5d | %-30s | %-10.2f | %-50s | %-7s |\n",
               cdList[i].id, cdList[i].name, cdList[i].duration, cdList[i].content,
               cdList[i].status ? "Dang cho thue" : "Da cho thue");
    }
}
void addNewCD() {
    if (cdCount < MAX_CD) {
        struct CD newCD;
        printf("Nhap thong tin CD moi:\n");
        printf("Ten CD: ");
        scanf("%49[^\n]", newCD.name);
        printf("Thoi luong (phut): ");
        scanf("%f", &newCD.duration);
        printf("Noi dung: ");
        scanf(" %99[^\n]", newCD.content);
        newCD.status = true;
        newCD.id = cdCount + 1;
        cdList[cdCount++] = newCD;
        printf("Them CD thanh cong!\n");
    } else {
        printf("Danh sach CD da day. Khong the them moi CD.\n");
    }
}

void updateCDInfo() {
    char targetName[50];
    printf("Nhap ten CD muon cap nhat thong tin: ");
    scanf(" %49[^\n]", targetName);

    int foundIndex = -1;
    for (int i = 0; i < cdCount; i++) {
        if (strcmp(cdList[i].name, targetName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Nhap thong tin moi cho CD:\n");
        printf("Ten CD: ");
        scanf(" %49[^\n]", cdList[foundIndex].name);
        printf("Thoi luong (phut): ");
        scanf("%f", &cdList[foundIndex].duration);
        printf("Noi dung: ");
        scanf(" %99[^\n]", cdList[foundIndex].content);
        printf("Cap nhat CD thanh cong!\n");
    } else {
        printf("Khong tim thay CD co ten \"%s\"\n", targetName);
    }
}
void deleteCD() {
    char targetName[50];
    printf("Nhap ten CD muon xoa: ");
    scanf(" %49[^\n]", targetName);

    int foundIndex = -1;
    for (int i = 0; i < cdCount; i++) {
        if (strcmp(cdList[i].name, targetName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < cdCount - 1; i++) {
            cdList[i] = cdList[i + 1];
        }
        cdCount--;
        printf("Xoa CD thanh cong!\n");
    } else {
        printf("Khong tim thay CD co ten \"%s\"\n", targetName);
    }
}

void insertionSortCDList() {
    for (int i = 1; i < cdCount; i++) {
        struct CD key = cdList[i];
        int j = i - 1;
        while (j >= 0 && cdList[j].duration > key.duration) {
            cdList[j + 1] = cdList[j];
            j = j - 1;
        }
        cdList[j + 1] = key;
    }
}

int binarySearchCDByName(char targetName[50]) {
    int left = 0, right = cdCount - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int compareResult = strcmp(cdList[mid].name, targetName);
        if (compareResult == 0) {
            return mid;
        } else if (compareResult < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
void printCDListByStatus(bool status) {
    printf("\nDanh sach CD theo trang thai:\n");
    printf("| %-5s | %-30s | %-10s | %-50s | %-7s |\n", "ID", "Ten CD", "Thoi luong", "Noi dung", "Status");
    for (int i = 0; i < cdCount; i++) {
        if (cdList[i].status == status) {
            printf("| %-5d | %-30s | %-10.2f | %-50s | %-7s |\n",
                   cdList[i].id, cdList[i].name, cdList[i].duration, cdList[i].content,
                   cdList[i].status ? "Dang cho thue" : "Da cho thue");
        }
    }
}
int main(void) {

    cdList[0] = (struct CD){1, "CD1", 45.5, "Content1", true};
    cdList[1] = (struct CD){2, "CD2", 60.0, "Content2", false};
    cdCount = 2;

    int choice;
    do {
        displayMenu();
        printf("Nhap lua chon cua ban (1-7, 0 de thoat): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printCDList();
                break;
            case 2:
                addNewCD();
                break;
            case 3:
                updateCDInfo();
                break;
            case 4:
                deleteCD();
                break;
            case 5:
                insertionSortCDList();
                printCDList();
                break;
            case 6:
            {
                char targetName[50];
                printf("Nhap ten CD can tim: ");
                scanf(" %49[^\n]", targetName);
                int index = binarySearchCDByName(targetName);
                if (index != -1) {
                    printf("Thong tin CD tim thay:\n");
                    printf("| %-5s | %-30s | %-10s | %-50s | %-7s |\n", "ID", "Ten CD", "Thoi luong", "Noi dung", "Status");
                    printf("| %-5d | %-30s | %-10.2f | %-50s | %-7s |\n",
                           cdList[index].id, cdList[index].name, cdList[index].duration, cdList[index].content,
                           cdList[index].status ? "Dang cho thue" : "Da cho thue");
                } else {
                    printf("Khong tim thay CD co ten \"%s\"\n", targetName);
                }
            }
                break;
            case 7:
            {
                int statusChoice;
                printf("Nhap trang thai CD can tim (0: Da cho thue, 1: Dang cho thue): ");
                scanf("%d", &statusChoice);
                bool statusToSearch = (statusChoice == 1) ? true : false;
                printCDListByStatus(statusToSearch);
            }
                break;
            case 0:
                printf("Thoat chuong trinh. Cam on ban!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long nhap lai.\n");
        }
    } while (choice != 0);

}