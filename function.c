#include<stdio.h>
#include<string.h>
#include"function.h"
// logic ham
// Ham In Student
void printfStudent(Student std[], int *length){
    printf("\n**** All Students ****\n\n");
    printf("|==========|====================|==============================|====================|=============|\n");
    printf("|%-10s|%-20s|%-30s|%-20s|%-13s|\n", "ID", "Name", "Email", "Phone", "NO.Course");
    printf("|==========|====================|==============================|====================|=============|\n");
    int i;
    for (i = 0; i < *length; i++) {
    	if(std[i].studentId==0){
    		break;
		}
        printf("|%-10d|%-20.*s|%-30.*s|%-20.*s|%-13d|\n", 
               std[i].studentId, 
               20, std[i].name, 
               30, std[i].email, 
               20, std[i].phone, 
               std[i].studentId);
        printf("|==========|====================|==============================|====================|=============|\n");
    }
}
// Menu Ten He Thong
void displayMenu(void){
	printf("\n***Student Management System Using C***\n");
	printf("CHOOSE YOUR ROLE\n");
	printf("===================\n");
	printf("[1]: Admin.\n");
	printf("[2]: Student.\n");
//	printf("[3]: Teacher.\n");
	printf("[0]: Exit.\n");
	printf("===================\n");
	printf("Enter The Choice: ");
}
// Ham ket thuc
void end(void){
	system("cls");
	printf("	========= Thank You =========\n");
	printf("	========= See You Soon =========\n");
	
}
// Menu Admin
void menuAdmin(void){
	printf("\n***Student Management System Using C***\n");
	printf("		Menu\n");
	printf("=================================\n");
	printf("[1]: Students management.\n");
	printf("[2]: ClassRooms managemment.\n");
	printf("[3]: Teacher management.\n");
	printf("[4]: User Guideline.\n");
	printf("[5]: About Us.\n");
	printf("[0]: Menu ");
	printf("Enter The Choice: ");
}
// Menu Student
void menuStudent(void){
	printf("\n***Student Management System Using C***\n");
	printf("		Student Menu\n");
	printf("==============================\n");
	printf("[1]: Show all students.\n");
	printf("[2]: Add a new students.\n");
	printf("[3]: Search a students.\n");
	printf("[4]: Edit a students.\n");
	printf("[5]: Delete a student.\n");
	printf("[6]: Sort Students By Name.\n");
	printf("[0]: Menu.\n");
	printf("Enter The Choice: ");
}
// Menu chon che do
void chooseYourRole(int *choice,Student student[], int *length,int *firstChoice) {
	do{
		int n;
		char choiceSub[10];
		system("cls");
		menuStudent();
		scanf("%d",choice);
		getchar();
		system("cls");
		switch(*choice){
			case 1:
				printfStudent(student,length);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					*firstChoice=0;
					*choice = 0;
				}
				break;
			case 2:	
				printf("Nhap so luong sinh vien: ");
				scanf("%d", &n);
				getchar();
				inputStudent(student,n,length);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					*firstChoice=0;
					*choice = 0;
				}
				break;
			case 3:
				searchStudentByName(student,*length);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					*firstChoice=0;
					*choice = 0;
				}
				break;
			case 4: 
				editStudent(student,length);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					*firstChoice=0;
					*choice = 0;
				}
				break;
			case 5: 
				deleteStudent(student,length);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					*firstChoice=0;
					*choice = 0;
				}
				break;
			case 6:
				sortStudentsByName(student,*length);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					*firstChoice=0;
					*choice = 0;
				}
				break;
			case 0:
				break;
			default:
				printf("Lua chon khong hop le. Vui long chon lai\n");
				break;
		}	
	}while(*choice!=0);
}
// Nhap thong tin sinh vien
void inputStudent(Student student[], int n, int *currentLength) {
    int j, i;
    for (j = 0; j < n; j++) {
        // id student tang tu dong
        student[*currentLength + j].studentId = *currentLength + j + 1;
        printf("Nhap thong tin sinh vien thu %d: \n", *currentLength + j + 1);
        // nhap va check ten
        int valid = 0;
        do {
            printf("Ho Va Ten: ");
            fgets(student[*currentLength + j].name, sizeof(student[*currentLength + j].name), stdin);
            student[*currentLength + j].name[strcspn(student[*currentLength + j].name, "\n")] = '\0'; // Lo?i b? '\n'

            // ktra xem co trong khong
            if (strlen(student[*currentLength + j].name) == 0) {
                printf("Ten khong duoc de trong. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            // ktra xem co hop le khong
            valid = 1;
            for (i = 0; student[*currentLength + j].name[i] != '\0'; i++) {
                if (!isalpha(student[*currentLength + j].name[i]) && !isspace(student[*currentLength + j].name[i])) {
                    valid = 0;
                    printf("Ten khong hop le. Vui long nhap lai (chi chu va khoang trang).\n");
                    break;
                }
            }

            // ktra trung lap
//            for (i = 0; i < *currentLength; i++) {
//                if (strcmp(student[i].name, student[*currentLength + j].name) == 0) {
//                    valid = 0;
//                    printf("Ten da ton tai. Vui long nhap ten khac.\n");
//                    break;
//                }
//            }
        } while (!valid);

        // nhap va check sdt
        do {
            printf("So Dien Thoai: ");
            fgets(student[*currentLength + j].phone, sizeof(student[*currentLength + j].phone), stdin);
            student[*currentLength + j].phone[strcspn(student[*currentLength + j].phone, "\n")] = '\0';

            if (strlen(student[*currentLength + j].phone) == 0) {
                printf("So dien thoai khong duoc de trong. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            valid = 1;
            int len = strlen(student[*currentLength + j].phone);
            if (len < 10 || len > 11) {
                valid = 0;
                printf("So dien thoai khong hop le. Vui long nhap lai (do dai 10-11 ky tu).\n");
            } else {
                for (i = 0; i < len; i++) {
                    if (!isdigit(student[*currentLength + j].phone[i])) {
                        valid = 0;
                        printf("So dien thoai chi duoc chua so. Vui long nhap lai.\n");
                        break;
                    }
                }
            }

            // ktra trung lap
            for (i = 0; i < *currentLength; i++) {
                if (strcmp(student[i].phone, student[*currentLength + j].phone) == 0) {
                    valid = 0;
                    printf("So dien thoai da ton tai. Vui long nhap so khac.\n");
                    break;
                }
            }
        } while (!valid);

        // nhap va check email
        do {
            printf("Nhap Email: ");
            fgets(student[*currentLength + j].email, sizeof(student[*currentLength + j].email), stdin);
            student[*currentLength + j].email[strcspn(student[*currentLength + j].email, "\n")] = '\0';

            if (strlen(student[*currentLength + j].email) == 0) {
                printf("Email khong duoc de trong. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            valid = 1;
            char *at = strchr(student[*currentLength + j].email, '@');
            char *dot = strrchr(student[*currentLength + j].email, '.');
            if (!at || !dot || at > dot) {
                valid = 0;
                printf("Email khong hop le. Vui long nhap lai (dinh dang x@y.z).\n");
            }

            // ktra trung lap
            for (i = 0; i < *currentLength; i++) {
                if (strcmp(student[i].email, student[*currentLength + j].email) == 0) {
                    valid = 0;
                    printf("Email da ton tai. Vui long nhap email khac.\n");
                    break;
                }
            }
        } while (!valid);

        // Nhap pass và check
        do {
            printf("Nhap Password: ");
            fgets(student[*currentLength + j].password, sizeof(student[*currentLength + j].password), stdin);
            student[*currentLength + j].password[strcspn(student[*currentLength + j].password, "\n")] = '\0';

            if (strlen(student[*currentLength + j].password) == 0) {
                printf("Password khong duoc de trong. Vui long nhap lai.\n");
                valid = 0;
            } else {
                valid = 1;
            }
        } while (!valid);
    }

    // Tang so phan tu 
    *currentLength += n;
    printf("\n*** Student Added Successfully ***\n");
}
// Sua phan tu
void editStudent(Student student[], int *currentLength) {
    if (*currentLength == 0) {
        printf("Danh sach sinh vien hien dang trong. Khong co gi de sua.\n");
        return;
    }

    int id, i, j, valid;
    char input[100]; // Bien luu chu

    printf("Nhap ID sinh vien muon sua: ");
    scanf("%d", &id);
    getchar(); // Xoa ky tu "\n"

    // ktra id hop le
    if (id < 1 || id > *currentLength) {
        printf("Khong tim thay sinh vien voi ID: %d\n", id);
        return;
    }

    int found = -1;
    for (i = 0; i < *currentLength; i++) {
        if (student[i].studentId == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Khong tim thay sinh vien voi ID: %d\n", id);
        return;
    }

    printf("\nThong tin hien tai cua sinh vien:\n");
    printf("ID: %d\n", student[found].studentId);
    printf("Ho Va Ten: %s\n", student[found].name);
    printf("So Dien Thoai: %s\n", student[found].phone);
    printf("Email: %s\n", student[found].email);
//    printf("Password: %s\n", student[found].password);

    printf("\nNhap thong tin moi cho sinh vien (Nhap so 0 de bo qua):\n");

    // Nhap ten
    do {
        printf("Ho Va Ten (Nhap so 0 de bo qua): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "0") == 0) {
            break; // Bo qua khi nhap "0"
        }

        valid = 1;
        if (strlen(input) == 0) {
            printf("Ten khong duoc de trong. Vui long nhap lai.\n");
            valid = 0;
        } else {
            for (i = 0; input[i] != '\0'; i++) {
                if (!isalpha(input[i]) && !isspace(input[i])) {
                    valid = 0;
                    printf("Ten khong hop le. Vui long nhap lai (chi chu va khoang trang).\n");
                    break;
                }
            }
        }

        if (valid) {
            strcpy(student[found].name, input);
        }
    } while (!valid);

    // nhap so dth
    do {
        printf("So Dien Thoai (Nhap so 0 de bo qua): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "0") == 0) {
            break;
        }

        valid = 1;
        int len = strlen(input);
        if (len == 0) {
            printf("So dien thoai khong duoc de trong. Vui long nhap lai.\n");
            valid = 0;
        } else if (len < 10 || len > 11) {
            printf("So dien thoai khong hop le. Vui long nhap lai (do dai 10-11 ky tu).\n");
            valid = 0;
        } else {
            for (i = 0; i < len; i++) {
                if (!isdigit(input[i])) {
                    valid = 0;
                    printf("So dien thoai chi duoc chua so. Vui long nhap lai.\n");
                    break;
                }
            }
        }

        // ktra sdt
        for (j = 0; j < *currentLength; j++) {
            if (j != found && strcmp(student[j].phone, input) == 0) {
                valid = 0;
                printf("So dien thoai da ton tai trong danh sach. Vui long nhap so khac.\n");
                break;
            }
        }

        if (valid) {
            strcpy(student[found].phone, input);
        }
    } while (!valid);

    // nhap mail
    do {
        printf("Nhap Email (Nhap so 0 de bo qua): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "0") == 0) {
            break;
        }

        valid = 1;
        char *at = strchr(input, '@');
        char *dot = strrchr(input, '.');
        if (strlen(input) == 0) {
            printf("Email khong duoc de trong. Vui long nhap lai.\n");
            valid = 0;
        } else if (!at || !dot || at > dot) {
            valid = 0;
            printf("Email khong hop le. Vui long nhap lai (dinh dang x@y.z).\n");
        }

        // ktra email
        for (j = 0; j < *currentLength; j++) {
            if (j != found && strcmp(student[j].email, input) == 0) {
                valid = 0;
                printf("Email da ton tai trong danh sach. Vui long nhap email khac.\n");
                break;
            }
        }

        if (valid) {
            strcpy(student[found].email, input);
        }
    } while (!valid);

//    // Nhap pass
//    printf("Nhap Password (Nhap so 0 de bo qua): ");
//    fgets(input, sizeof(input), stdin);
//    input[strcspn(input, "\n")] = '\0';
//
//    if (strcmp(input, "0") != 0 && strlen(input) > 0) {
//        strcpy(student[found].password, input);
//    }

    printf("\n*** Thong tin sinh vien da duoc cap nhat thanh cong! ***\n");
}

// xoa student 
void deleteStudent(Student student[], int *currentLength){
    if (*currentLength == 0) {
        printf("Danh sach sinh vien hien dang trong. Khong co gi de xoa.\n");
        return;
    }

    int id, i, found = -1;
    char confirm;

    printf("Nhap ID sinh vien muon xoa: ");
    scanf("%d", &id);
    getchar(); // loai bo \n

    // tim vi tri id
    for (i = 0; i < *currentLength; i++) {
        if (student[i].studentId == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Khong tim thay sinh vien voi ID: %d\n", id);
        return;
    }

    // hien thi thong tin student muon xoa
    printf("Thong tin sinh vien muon xoa:\n");
    printf("ID: %d\n", student[found].studentId);
    printf("Ho Va Ten: %s\n", student[found].name);
    printf("So Dien Thoai: %s\n", student[found].phone);
    printf("Email: %s\n", student[found].email);

    printf("\nBan co chac chan muon xoa sinh vien nay? (y/n): ");
    scanf(" %c", &confirm);
    getchar(); // xoa ki tu'\n'

    if (confirm == 'y' || confirm == 'Y') {
        // dong y xoa student
        for (i = found; i < *currentLength - 1; i++) {
            student[i] = student[i + 1];
        }

        // giam so luong danh sach
        (*currentLength)--;

        printf("Sinh vien voi ID: %d da duoc xoa thanh cong.\n", id);
    } else {
        printf("Huy xoa sinh vien.\n");
    }
}
// Ham tim student
void searchStudentByName(Student student[], int currentLength) {
    if (currentLength == 0) {
        printf("Danh sach sinh vien hien dang trong. Khong co gi de tim kiem.\n");
        return;
    }
    char searchName[50];
    printf("Nhap ten sinh vien muon tim kiem: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Loai bo '\n'

    printf("\nKet qua tim kiem cho chuoi: \"%s\"\n", searchName);
    printf("|==========|====================|==============================|====================|=============|\n");
    printf("|%-10s|%-20s|%-30s|%-20s|%-13s|\n", "ID", "Name", "Email", "Phone", "NO.Course");
    printf("|==========|====================|==============================|====================|=============|\n");

    int found = 0; // Bien co ktra xem co student k
    int i;
    for (i = 0; i < currentLength; i++) {
        // Su dung strstr() de kiem tra chuoi co trong danh khong
        if (strstr(student[i].name, searchName) != NULL) {
            found = 1; // danh dau neu tim thay student
            printf("|%-10d|%-20s|%-30s|%-20s|%-13d|\n", 
                   student[i].studentId, 
                   student[i].name, 
                   student[i].email, 
                   student[i].phone, 
                   student[i].studentId);
            printf("|==========|====================|==============================|====================|=============|\n");
        }
    }
    if (found!=1) {
        printf("Khong tim thay sinh vien nao voi ten chua chuoi: \"%s\"\n", searchName);
    }
}
// Sap xep student theo ten
void sortStudentsByName(Student student[], int currentLength) {
    if (currentLength == 0) {
        printf("Danh sach sinh vien trong. Khong co gi de sap xep.\n");
        return;
    }

    int choice;
    printf("Chon thu tu sap xep danh sach:\n");
    printf("1. Tang dan theo ten\n");
    printf("2. Giam dan theo ten\n");
    printf("Nhap lua chon (1 hoac 2): ");
    scanf("%d", &choice);
    getchar(); // Xoa ki tu '\n'

    if (choice != 1 && choice != 2) {
        printf("Lua chon khong hop le. Quay lai menu chinh.\n");
        return;
    }

    // logic sap xep
    int i,j;
    for (i = 0; i < currentLength - 1; i++) {
        for (j = i + 1; j < currentLength; j++) {
            int compare = strcmp(student[i].name, student[j].name);
            if ((choice == 1 && compare > 0) || (choice == 2 && compare < 0)) {
                // hoan doi 2 sinh vien
                Student temp = student[i];
                student[i] = student[j];
                student[j] = temp;
            }
        }
    }
    printf("**** Sort Successfully \n");
}
// Ham login
void loginAdmin(const char email[], const char password[]) {
    char mail[50]; 
    char pass[50];
    
    while (1) {
        printf("======= Admin Login =======\n");
        printf("Email: ");
        fgets(mail, sizeof(mail), stdin);
        mail[strcspn(mail, "\n")] = '\0';
        
        
        printf("Password: ");
        fgets(pass, sizeof(pass), stdin);
        pass[strcspn(pass, "\n")] = '\0'; 
        
        printf("===========================\n");
        
        if (strcmp(mail, email) == 0 && strcmp(pass, password) == 0) {
            printf("Login successfully!\n");
            break;
        } else if (strcmp(mail, email) != 0) {
            printf("Sai email. Vui long nhap lai.\n");
        } else {
            printf("Sai password. Vui long nhap lai.\n");
        }
    }
}


