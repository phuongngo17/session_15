#include <stdio.h>
#include <string.h>

#define MAX_STUDENT 100

struct Student {
    char name[50];
    int age;
    char phone[20];
    char email[50];
};

struct Student students[MAX_STUDENT];
int student_count = 0;

void add_student() {
    if (student_count >= MAX_STUDENT) {
        printf("Khong the them sinh vien moi vi da dat gioi han %d sinh vien.\n", MAX_STUDENT);
        return;
    }

    struct Student new_student;
    printf("Nhap ten sinh vien: ");
    scanf("%s", new_student.name);
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &new_student.age);
    printf("Nhap so dien thoai sinh vien: ");
    scanf("%s", new_student.phone);
    printf("Nhap email sinh vien: ");
    scanf("%s", new_student.email);

    students[student_count] = new_student;
    student_count++;
}

void edit_student() {
    int index;
    printf("Nhap vi tri sinh vien can sua: ");
    scanf("%d", &index);

    if (index < 0 || index >= student_count) {
        printf("Vi tri sinh vien khong hop le.\n");
        return;
    }

    struct Student new_student;
    printf("Nhap ten sinh vien: ");
    scanf("%s", new_student.name);
    printf("Nhap tuoi sinh vien: ");
    scanf("%d", &new_student.age);
    printf("Nhap so dien thoai sinh vien: ");
    scanf("%s", new_student.phone);
    printf("Nhap email sinh vien: ");
    scanf("%s", new_student.email);

    students[index] = new_student;
}

void delete_student() {
    int index;
    printf("Nhap vi tri sinh vien can xoa: ");
    scanf("%d", &index);

    if (index < 0 || index >= student_count) {
        printf("Vi tri sinh vien khong hop le.\n");
        return;
    }

    for (int i = index; i < student_count - 1; i++) {
        students[i] = students[i + 1];
    }

    student_count--;
}

void print_student(struct Student student) {
    printf("%-30s%-10d%-20s%-30s\n", student.name, student.age, student.phone, student.email);
}

void print_all_students() {
    printf("%-30s%-10s%-20s%-30s\n", "Ho va ten", "Tuoi", "So dien thoai", "Email");
    for (int i = 0; i < student_count; i++) {
        print_student(students[i]);
    }
}

void menu() {
    printf("1. Them sinh vien\n");
    printf("2. Sua sinh vien\n");
    printf("3. Xoa sinh vien\n");
    printf("4. In danh sach sinh vien\n");
    printf("5. Thoat\n");
}

int main() {
    int choice;
    do {
        menu();
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_student();
                break;
            case 2:
                edit_student();
                break;
            case 3:
                delete_student();
                break;
            case 4:
                print_all_students();
                break;
            case 5:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

