#include <stdio.h>
#include <string.h>

typedef struct {
    int id;
    char name[50];
    int age;
    char phoneNumber[15];
} student;

void printStudents(student students[], int currentLength) {
    for (int i = 0; i < currentLength; i++) {
        printf("id: %d, ten: %s, tuoi: %d, sdt: %s\n", students[i].id, students[i].name, students[i].age, students[i].phoneNumber);
    }
}

void sortStudentsByName(student students[], int currentLength) {
    student temp;
    for (int i = 0; i < currentLength - 1; i++) {
        for (int j = i + 1; j < currentLength; j++) {
            if (strcmp(students[i].name, students[j].name) > 0) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int main() {
    student students[5] = {
        {1, "Nguyen Van A", 20, "0901234567"},
        {2, "Tran Thi B", 22, "0912345678"},
        {3, "Le Thi C", 21, "0923456789"},
        {4, "Pham Minh D", 23, "0934567890"},
        {5, "Doan Mai E", 19, "0945678901"}
    };

    int currentLength = 5;

    printf("Danh sach sinh vien ban dau:\n");
    printStudents(students, currentLength);

    sortStudentsByName(students, currentLength);

    printf("\nDanh sach sinh vien sau khi sap xep theo ten:\n");
    printStudents(students, currentLength);

    return 0;
}
