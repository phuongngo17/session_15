#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int age;
    char number[15];
    char email[50];
};

int main() {
    struct Student student= {"Nguyen Van A",20,"0123456789","nguyenvana@gmail.com"};
    strcpy(student.name, "Nguyen Van A");
    student.age = 20;
    strcpy(student.number, "0123456789");
    strcpy(student.email, "nguyenvana@gmail.com");

    printf("Ho va ten: %s\n", student.name);
    printf("Tuoi: %d\n", student.age);
    printf("So dien thoai: %s\n", student.number);
    printf("Email: %s\n", student.email);

    return 0;
}

