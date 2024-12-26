#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} student;

void printStudents(student students[], int currentLength) {
    if (currentLength == 0) {
        printf("danh sach sinh vien rong.\n");
        return;
    }
    for (int i = 0; i < currentLength; i++) {
        printf("id: %d, ten: %s, tuoi: %d, sdt: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

void deleteStudent(int id, student students[], int *currentLength) {
    int found = -1;
    for (int i = 0; i < *currentLength; i++) {
        if (students[i].id == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("khong tim thay sinh vien voi id %d.\n", id);
        return;
    }

    for (int i = found; i < *currentLength - 1; i++) {
        students[i] = students[i + 1];
    }

    (*currentLength)--;
    printf("sinh vien voi id %d da bi xoa.\n", id);
}

int main() {
    student students[5] = {
        {1, "nguyen van a", 20, "0901234567"},
        {2, "tran thi b", 22, "0912345678"},
        {3, "le thi c", 21, "0923456789"},
        {4, "pham minh d", 23, "0934567890"},
        {5, "doan mai e", 19, "0945678901"}
    };

    int currentLength = 5;

    printf("danh sach sinh vien ban dau:\n");
    printStudents(students, currentLength);

    int idToDelete;
    printf("\nnhap id sinh vien can xoa: ");
    scanf("%d", &idToDelete);

    deleteStudent(idToDelete, students, &currentLength);

    printf("\ndanh sach sinh vien sau khi xoa:\n");
    printStudents(students, currentLength);

    return 0;
}

