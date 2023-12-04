#include<stdio.h>
struct Student {
    char name[50];
    int age;
    char number[20];
    char email[50];
};

void studentImport(struct Student *st) {	
    printf("Nhap ho ten:");
    gets(sv->name);
    printf("Nhap tuoi: ");
    scanf("%d", &sv->age);
    printf("Nhap so dien thoai: ");
    scanf("%s",sv->number);
    printf("Nhap email: ");
    scanf("%s",sv->email);
}

void studentExport(struct Student st) {
    printf("Ho ten: %s\n", st.name);
    printf("Tuoi: %d\n", st.age);
    printf("So dien thoai: %s\n", st.number);
    printf("Email: %s\n", st.email);
}

int main() {
    struct Student st;
    studentImport(&st);
    studentExport(st);
    return 0;
}

