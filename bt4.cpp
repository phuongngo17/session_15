#include <stdio.h>
#include <string.h>

struct Book {
    char id[10];
    char name[50];
    char author[50];
    float price;
    char category[50];
};

void print_book(struct Book book) {
    printf("%-10s%-30s%-20s%-10.2f%-20s\n", book.id, book.name, book.author, book.price, book.category);
}

int main() {
    struct Book books[100];
    int n = 0;
    int choice = 0;
    do {
        printf("MENU\n");
        printf("1. Nhap so luong va thong tin sach\n");
        printf("2. Hien thi thong tin sach\n");
        printf("3. Them sach vao vi tri\n");
        printf("4. Xoa sach theo ma sach\n");
        printf("5. Cap nhat thong tin sach theo ma sach\n");
        printf("6. Sap xep sach theo gia (tang/giam)\n");
        printf("7. Tim kiem sach theo ten sach\n");
        printf("8. Tim kiem sach theo khoang gia\n");
        printf("9. Thoat chuong trinh\n");
        printf("Chon chuc nang: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: {
                printf("Nhap so luong sach: ");
                scanf("%d", &n);
                for (int i = 0; i < n; ++i) {
                    printf("Nhap thong tin sach %d:\n", i + 1);
                    printf("Ma sach: ");
                    scanf("%s", books[i].id);
                    printf("Ten sach: ");
                    scanf("%s", books[i].name);
                    printf("Tac gia: ");
                    scanf("%s", books[i].author);
                    printf("Gia tien: ");
                    scanf("%f", &books[i].price);
                    printf("The loai: ");
                    scanf("%s", books[i].category);
                }
                break;
            }
            case 2: {
                printf("%-10s%-30s%-20s%-10s%-20s\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
                for (int i = 0; i < n; ++i) {
                    print_book(books[i]);
                }
                break;
            }
            case 3: {
                int pos = 0;
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                if (pos < 1 || pos > n + 1) {
                    printf("Vi tri khong hop le!\n");
                    break;
                }
                for (int i = n; i >= pos; --i) {
                    books[i] = books[i - 1];
                }
                printf("Nhap thong tin sach can them:\n");
                printf("Ma sach: ");
                scanf("%s", books[pos - 1].id);
                printf("Ten sach: ");
                scanf("%s", books[pos - 1].name);
                printf("Tac gia: ");
                scanf("%s", books[pos - 1].author);
                printf("Gia tien: ");
                scanf("%f", &books[pos - 1].price);
                printf("The loai: ");
                scanf("%s", books[pos - 1].category);
                ++n;
                break;
            }
            case 4: {
                char id[10];
                printf("Nhap ma sach can xoa: ");
                scanf("%s", id);
                int pos = -1;
                for (int i = 0; i < n; ++i) {
                    if (strcmp(books[i].id, id) == 0) {
                        pos = i;
                        break;
                    }
                }
                if (pos == -1) {
                    printf("Khong tim thay sach co ma %s!\n", id);
                    break;
                }
                for (int i = pos; i < n - 1; ++i) {
                    books[i] = books[i + 1];
                }
                n--;
                printf("da xoa sach co ma %s!\n", id);
                break;
            }
            case 5: {
                char id[10];
                printf("Nhap ma sach can cap nhat: ");
                scanf("%s",id);
                int pos = -1;
                for(int i=0;i<n;++i){
                	if(strcmp(books[i].id,id)==0){
                		pos =i;
                		break;
					}
				}
				if(pos==-1){
					printf("Khong tim thay sach co ma %s\n");
				}
			}
			case 6:{
		       int option;
    
               printf("\nSap xep sach theo gia:\n");
               printf("1. Tang dan\n");
               printf("2. Giam dan\n");
               printf("Lua chon: ");
               scanf("%d", &option);
    
              if (option == 1) {
               // Sap xep tang dan
               for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - 1 - i; j++) {
                        if (books[j].price > books[j + 1].price) {
                            struct Book temp = books[j];
                            books[j] = books[j + 1];
                            books[j + 1] = temp;
                        }
                    }
               }
               printf("Sach da duoc sap xep theo gia tang dan.\n");
              } else if (option == 2) {
               // Sap xep giam dan
                for (int i = 0; i < n - 1; i++) {
                    for (int j = 0; j < n - 1 - i; j++) {
                        if (books[j].price < books[j + 1].price) {
                            struct Book temp = books[j];
                            books[j] = books[j + 1];
                            books[j + 1] = temp;
                        }
                    }
                }
                printf("Sach da duoc sap xep theo gia giam dan.\n");
               } else {
                printf("Lua chon khong hop le!\n");
               }
			}
			case 7:{
				char name[50];
    
                printf("\nTim kiem sach theo ten sach:\n");
                printf("Ten sach: ");
                fflush(stdin);
                gets(name);
    
                int found = 0;
    
                printf("\nKet qua tim kiem:\n");
                printf("%-10s%-30s%-20s%-10s%-20s\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
                for (int i = 0; i < n; i++) {
                    if (strcmp(books[i].name, name) == 0) {
                        printf("%-10d%-30s%-20s%-10.2f%-20s\n", books[i].id, books[i].name, books[i].author, books[i].price, books[i].category);
                        found = 1;
                    }
                }
    
                if (!found) {
                   printf("Khong tim thay sach co ten sach %s.\n", name);
                }
				break;
			}
			case 8: {
				float minPrice, maxPrice;
    
                printf("\nTim kiem sach theo khoang gia:\n");
                printf("Gia tien tu: ");
                scanf("%f", &minPrice);
                printf("Gia tien lon: ");
                scanf("%f", &maxPrice);
    
                int found = 0;
    
                printf("\nKet qua tim kiem:\n");
                printf("%-10s%-30s%-20s%-10s%-20s\n", "Ma sach", "Ten sach", "Tac gia", "Gia tien", "The loai");
                for (int i = 0; i < n; i++) {
                    if (books[i].price >= minPrice && books[i].price <= maxPrice) {
                        printf("%-10d%-30s%-20s%-10.2f%-20s\n", books[i].id, books[i].name, books[i].author, books[i].price, books[i].category);
                        found = 1;
                    }
                }
    
                if (!found) {
                    printf("Khong tim thay sach trong khoang gia %.2f - %.2f.\n", minPrice, maxPrice);
                }
				break;
			}
			case 9: {
				printf("Thoat chuong trinh\n");
				break;
			}
			default:
				printf("lua chon khong hop le\n");
	    }
	}while(choice !=9);
}
