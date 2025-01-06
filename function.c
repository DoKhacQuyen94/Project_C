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
	printf("[3]: Teacher.\n");
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
	printf("[2]: Teacher management.\n");
//	printf("[3]: ClassRooms managemment.\n");
//	printf("[4]: User Guideline.\n");
//	printf("[5]: About Us.\n");
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
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
				}
				break;
			case 2:
				printf("Nhap so luong sinh vien: ");
				scanf("%d", &n);
				getchar();
				inputStudent(student,n,length);
				saveFile(student,*length);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					*firstChoice=0;
					*choice = 0;
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
				}
				break;
			case 3:
				searchStudentByName(student,*length);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				if (strcmp(choiceSub, "0") == 0) {
					end();
					*firstChoice=0;
					*choice = 0;
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
				}
				break;
			case 4:
				printfStudent(student,length);
				editStudent(student,length);
				saveFile(student,*length);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					*firstChoice=0;
					*choice = 0;
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
				}
				break;
			case 5: 
				deleteStudent(student,length);
				saveFile(student,*length);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				if (strcmp(choiceSub, "0") == 0) {
					end();
					*firstChoice=0;
					*choice = 0;
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
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
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
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
void inputStudent(Student student[], int n, int *currentLength) {
    int j, i;
    for (j = 0; j < n; j++) {
        // ID student tang tu dong, dam bao khong bi trung
        int newId = *currentLength + j + 1;
        int isDuplicate;
        do {
            isDuplicate = 0;
            for (i = 0; i < *currentLength; i++) {
                if (student[i].studentId == newId) {
                    isDuplicate = 1;
                    newId++; // Neu trung thi tang len 1
                    break;
                }
            }
        } while (isDuplicate);
        student[*currentLength + j].studentId = newId;

        printf("Nhap thong tin sinh vien thu %d: \n", student[*currentLength + j].studentId);

        // Nhap va kiem tra ten
        int valid = 0;
        do {
            printf("Ho Va Ten: ");
            fgets(student[*currentLength + j].name, sizeof(student[*currentLength + j].name), stdin);
            student[*currentLength + j].name[strcspn(student[*currentLength + j].name, "\n")] = '\0'; // Loai bo '\n'

            // Kiem tra xem ten co rong hoac toan dau cach khong
            if (strlen(student[*currentLength + j].name) == 0) {
                printf("Ten khong duoc de trong. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            int onlySpaces = 1;
            for (i = 0; student[*currentLength + j].name[i] != '\0'; i++) {
                if (!isspace(student[*currentLength + j].name[i])) {
                    onlySpaces = 0;
                    break;
                }
            }
            if (onlySpaces) {
                printf("Ten khong duoc toan dau cach. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            // Kiem tra ky tu hop le
            valid = 1;
            for (i = 0; student[*currentLength + j].name[i] != '\0'; i++) {
                if (!isalpha(student[*currentLength + j].name[i]) && !isspace(student[*currentLength + j].name[i])) {
                    valid = 0;
                    printf("Ten khong hop le. Vui long nhap lai (chi chu va khoang trang).\n");
                    break;
                }
            }
        } while (!valid);

        // Nhap va kiem tra so dien thoai
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

            for (i = 0; i < *currentLength; i++) {
                if (strcmp(student[i].phone, student[*currentLength + j].phone) == 0) {
                    valid = 0;
                    printf("So dien thoai da ton tai. Vui long nhap so khac.\n");
                    break;
                }
            }
        } while (!valid);

        // Nhap va kiem tra email
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
            char *at = strstr(student[*currentLength + j].email, "@gmail.com");
            if (!at || at == student[*currentLength + j].email) {
                valid = 0;
                printf("Email khong hop le. Vui long nhap lai (dinh dang x@gmail.com).\n");
            } else if (*(at - 1) == ' ') {
                valid = 0;
                printf("Email khong duoc co khoang trang truoc '@'. Vui long nhap lai.\n");
            }

            for (i = 0; i < *currentLength; i++) {
                if (strcmp(student[i].email, student[*currentLength + j].email) == 0) {
                    valid = 0;
                    printf("Email da ton tai. Vui long nhap email khac.\n");
                    break;
                }
            }
        } while (!valid);

        // Nhap va kiem tra mat khau
        do {
            printf("Nhap Password: ");
            fgets(student[*currentLength + j].password, sizeof(student[*currentLength + j].password), stdin);
            student[*currentLength + j].password[strcspn(student[*currentLength + j].password, "\n")] = '\0';

            if (strlen(student[*currentLength + j].password) == 0) {
                printf("Password khong duoc de trong. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            valid = 1;
            int onlySpaces = 1;
            for (i = 0; i < strlen(student[*currentLength + j].password); i++) {
                if (!isspace(student[*currentLength + j].password[i])) {
                    onlySpaces = 0;
                    break;
                }
            }
            if (onlySpaces) {
                printf("Password khong duoc toan dau cach. Vui long nhap lai.\n");
                valid = 0;
            }
        } while (!valid);
    }

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
	    input[strcspn(input, "\n")] = '\0'; // Loai bo ky tu xuong dong
	
	    if (strcmp(input, "0") == 0) {
	        break; // Nguoi dung muon bo qua
	    }
	
	    valid = 1; // Gia dinh email hop ly
	    char *at = strstr(input, "@gmail.com");
	    if (!at || at == input) { // Kiem tra dinh dang "@gmail.com"
	        valid = 0;
	        printf("Email khong hop le. Vui long nhap lai (dinh dang x@gmail.com).\n");
	    } else if (*(at - 1) == ' ') { // Khong duoc co khoang trang truoc '@'
	        valid = 0;
	        printf("Email khong duoc co khoang trang truoc '@'. Vui long nhap lai.\n");
	    } else if (strlen(input) == 0) { // Email khong duoc de trong
	        valid = 0;
	        printf("Email khong duoc de trong. Vui long nhap lai.\n");
	    }
	
	    // Kiem tra email trung lap trong danh sach sinh viên
	    for (j = 0; j < *currentLength; j++) {
	        if (j != found && strcmp(student[j].email, input) == 0) {
	            valid = 0;
	            printf("Email da ton tai trong danh sach. Vui long nhap email khac.\n");
	            break;
	        }
	    }
	
	    if (valid) {
	        strcpy(student[found].email, input); // Gan email hop le vao danh sách
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
        printf("Khong tim thay sinh vien nao voi ten : \"%s\"\n", searchName);
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
    printf("**** Sort Successfully **** \n");
}
// Ham login
void loginAdmin(const char email[], const char password[]) {
    char mail[50]; 
    char pass[50];
    
    while (1) {
        printf("======= Admin Login =======\n");
        printf("Email (tpq0904@gmail.com): ");
        fgets(mail, sizeof(mail), stdin);
        mail[strcspn(mail, "\n")] = '\0';
        
        
        printf("Password (1): ");
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
void saveFile(Student student[], int length){
    FILE *fptr=fopen("student.dat","wb");
    if(fptr==NULL){
        printf("Khong the mo file\n");
        return;
    }
    fwrite(student, sizeof(Student), length, fptr);
    printf("Them thanh cong\n");
    fclose(fptr);
}
void readFile(Student student[], int *length){
    FILE *fptr=fopen("student.dat","rb");
    if(fptr==NULL){
        printf("Khong the mo file\n");
        return;
    }
    *length=fread(student, sizeof(Student), 1000, fptr);
    printf("Doc file thanh cong\n");
    fclose(fptr);
}



// Teacher 
void printfTeacher(Teacher teacher[],int *lengthTeacher){
    printf("\n**** All Teacher ****\n\n");
    printf("|==========|====================|==============================|====================|=============|\n");
    printf("|%-10s|%-20s|%-30s|%-20s|%-13s|\n", "ID", "Name", "Email", "Phone", "Class_Id");
    printf("|==========|====================|==============================|====================|=============|\n");
    int i;
    for (i = 0; i < *lengthTeacher; i++) {
    	if(teacher[i].teacherId==0){
    		break;
		}
        printf("|%-10d|%-20.*s|%-30.*s|%-20.*s|%-13s|\n", 
               teacher[i].teacherId, 
               20, teacher[i].name, 
               30, teacher[i].email, 
               20, teacher[i].phone, 
               teacher[i].classId);
        printf("|==========|====================|==============================|====================|=============|\n");
    }
	
}
void menuTeacher(void){
	printf("\n***Teacher Management System Using C***\n");
	printf("		Teacher Menu\n");
	printf("==============================\n");
	printf("[1]: Show all teacher.\n");
	printf("[2]: Add a new teacher.\n");
	printf("[3]: Search a teacher.\n");
	printf("[4]: Edit a teacher.\n");
	printf("[5]: Delete a teacher.\n");
	printf("[6]: Sort Teacher By Name.\n");
	printf("[0]: Menu.\n");
	printf("Enter The Choice: ");
}
void choiceTeacher(Teacher teacher[],int *lengthTeacher,int *firstChoice){
	int choice;
	char choiceSub[5];
	do{
		system("cls");
		menuTeacher();
		scanf("%d",&choice);
		getchar();
		system("cls");
		switch(choice){
			case 1:
				printfTeacher(teacher,lengthTeacher);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					choice = 0;
					*firstChoice=0;
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
				}
				break;
			case 2:
				addTeacher(teacher,lengthTeacher);
				saveFileTeacher(teacher,*lengthTeacher);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					choice = 0;
					*firstChoice=0;
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
				}
				break;
			case 3:
				searchTeacherByName(teacher,*lengthTeacher);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					choice = 0;
					*firstChoice=0;
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
				}
				break;
			case 4:
				printfTeacher(teacher,lengthTeacher);
				editTeacher(teacher, lengthTeacher);
				saveFileTeacher(teacher,*lengthTeacher);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					choice = 0;
					*firstChoice=0;
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
				}
				break;
			case 5:
				printfTeacher(teacher,lengthTeacher);
				deleteTeacher(teacher, lengthTeacher);
				saveFileTeacher(teacher,*lengthTeacher);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					choice = 0;
					*firstChoice=0;
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
				}
				break;
			case 6:
				sortTeachersByName(teacher, *lengthTeacher);
				printf("Go Back(b)? or Exit(0): ");
				fgets(choiceSub, sizeof(choiceSub), stdin);
				choiceSub[strcspn(choiceSub, "\n")] = '\0';
				if (strcmp(choiceSub, "0") == 0) {
					end();
					choice = 0;
					*firstChoice=0;
				}else if(strcmp(choiceSub, "b") == 0){
					break;
				}else{
					break;
				}
				break;
			case 0: 
				printf("Ban da thoat\n");
				break;
			default:
				printf("Lua chon sai. Vui long chon lai\n");
				break;	
		}
	}while(choice!=0);
}
void addTeacher(Teacher teacher[], int *lengthTeacher) {
    int j, i;
    int n; // So luong giao vien can them
    printf("Nhap so luong giao vien muon them: ");
    scanf("%d", &n);
    getchar(); // Loai bo ky tu '\n' 

    for (j = 0; j < n; j++) {        
        // check xem id co trung khong, tang tu dong
        int newId = *lengthTeacher + j + 1;
        int isDuplicate;
        do {
            isDuplicate = 0;
            for (i = 0; i < *lengthTeacher + j; i++) {
                if (teacher[i].teacherId == newId) {
                    isDuplicate = 1;
                    newId++;
                    break;
                }
            }
        } while (isDuplicate);

        teacher[*lengthTeacher + j].teacherId = newId;
        printf("Nhap thong tin giao vien thu %d:\n", *lengthTeacher + j + 1);

        // Nhap va check ten
        int valid = 0;
        do {
            printf("Ho Va Ten: ");
            fgets(teacher[*lengthTeacher + j].name, sizeof(teacher[*lengthTeacher + j].name), stdin);
            teacher[*lengthTeacher + j].name[strcspn(teacher[*lengthTeacher + j].name, "\n")] = '\0';

            if (strlen(teacher[*lengthTeacher + j].name) == 0) {
                printf("Ten khong duoc de trong. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            int onlySpaces = 1;
            for (i = 0; teacher[*lengthTeacher + j].name[i] != '\0'; i++) {
                if (!isspace(teacher[*lengthTeacher + j].name[i])) {
                    onlySpaces = 0;
                    break;
                }
            }
            if (onlySpaces) {
                printf("Ten khong duoc toan dau cach. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            valid = 1;
            for (i = 0; teacher[*lengthTeacher + j].name[i] != '\0'; i++) {
                if (!isalpha(teacher[*lengthTeacher + j].name[i]) && !isspace(teacher[*lengthTeacher + j].name[i])) {
                    valid = 0;
                    printf("Ten khong hop le. Vui long nhap lai (chi chu va khoang trang).\n");
                    break;
                }
            }
        } while (!valid);

        // Nhap va check classId
        do {
            printf("Nhap Class ID: ");
            fgets(teacher[*lengthTeacher + j].classId, sizeof(teacher[*lengthTeacher + j].classId), stdin);
            teacher[*lengthTeacher + j].classId[strcspn(teacher[*lengthTeacher + j].classId, "\n")] = '\0';

            if (strlen(teacher[*lengthTeacher + j].classId) == 0) {
                printf("Class ID khong duoc de trong. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }
            if (strlen(teacher[*lengthTeacher + j].classId) > 9) {
                printf("Class ID khong duoc dai hon 9 ky tu. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            valid = 1;
            for (i = 0; teacher[*lengthTeacher + j].classId[i] != '\0'; i++) {
                if (isspace(teacher[*lengthTeacher + j].classId[i])) {
                    printf("Class ID khong duoc chua dau cach. Vui long nhap lai.\n");
                    valid = 0;
                    break;
                }
            }

            for (i = 0; i < *lengthTeacher; i++) {
                if (strcmp(teacher[i].classId, teacher[*lengthTeacher + j].classId) == 0) {
                    printf("Class ID da ton tai. Vui long nhap lai.\n");
                    valid = 0;
                    break;
                }
            }
        } while (!valid);

        // Nhap va kiem tra sdt
        do {
            printf("So Dien Thoai: ");
            fgets(teacher[*lengthTeacher + j].phone, sizeof(teacher[*lengthTeacher + j].phone), stdin);
            teacher[*lengthTeacher + j].phone[strcspn(teacher[*lengthTeacher + j].phone, "\n")] = '\0';

            if (strlen(teacher[*lengthTeacher + j].phone) == 0) {
                printf("So dien thoai khong duoc de trong. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            valid = 1;
            int len = strlen(teacher[*lengthTeacher + j].phone);
            if (len < 10 || len > 11) {
                valid = 0;
                printf("So dien thoai khong hop le. Vui long nhap lai (do dai 10-11 ky tu).\n");
            } else {
                for (i = 0; i < len; i++) {
                    if (!isdigit(teacher[*lengthTeacher + j].phone[i])) {
                        valid = 0;
                        printf("So dien thoai chi duoc chua so. Vui long nhap lai.\n");
                        break;
                    }
                }
            }

            for (i = 0; i < *lengthTeacher; i++) {
                if (strcmp(teacher[i].phone, teacher[*lengthTeacher + j].phone) == 0) {
                    valid = 0;
                    printf("So dien thoai da ton tai. Vui long nhap so khac.\n");
                    break;
                }
            }
        } while (!valid);

        // Nhap va kiem tra email
        do {
            printf("Nhap Email: ");
            fgets(teacher[*lengthTeacher + j].email, sizeof(teacher[*lengthTeacher + j].email), stdin);
            teacher[*lengthTeacher + j].email[strcspn(teacher[*lengthTeacher + j].email, "\n")] = '\0';

            if (strlen(teacher[*lengthTeacher + j].email) == 0) {
                printf("Email khong duoc de trong. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            valid = 1;
            char *at = strstr(teacher[*lengthTeacher + j].email, "@gmail.com");
            if (!at || at == teacher[*lengthTeacher + j].email) {
                valid = 0;
                printf("Email khong hop le. Vui long nhap lai (dinh dang x@gmail.com).\n");
            } else if (*(at - 1) == ' ') {
                valid = 0;
                printf("Email khong duoc co khoang trang truoc '@'. Vui long nhap lai.\n");
            }

            for (i = 0; i < *lengthTeacher; i++) {
                if (strcmp(teacher[i].email, teacher[*lengthTeacher + j].email) == 0) {
                    valid = 0;
                    printf("Email da ton tai. Vui long nhap email khac.\n");
                    break;
                }
            }
        } while (!valid);

        // Nhap va kiem tra password
        do {
            printf("Nhap Password: ");
            fgets(teacher[*lengthTeacher + j].password, sizeof(teacher[*lengthTeacher + j].password), stdin);
            teacher[*lengthTeacher + j].password[strcspn(teacher[*lengthTeacher + j].password, "\n")] = '\0';

            if (strlen(teacher[*lengthTeacher + j].password) == 0) {
                printf("Password khong duoc de trong. Vui long nhap lai.\n");
                valid = 0;
                continue;
            }

            valid = 1;
            int onlySpaces = 1;
            for (i = 0; i < strlen(teacher[*lengthTeacher + j].password); i++) {
                if (!isspace(teacher[*lengthTeacher + j].password[i])) {
                    onlySpaces = 0;
                    break;
                }
            }
            if (onlySpaces) {
                printf("Password khong duoc toan dau cach. Vui long nhap lai.\n");
                valid = 0;
            }
        } while (!valid);
    }

    *lengthTeacher += n;
    printf("\n*** Teacher Added Successfully ***\n");
}

void searchTeacherByName(Teacher teacher[], int currentLength) {
    if (currentLength == 0) {
        printf("Danh sach giao vien hien dang trong. Khong co gi de tim kiem.\n");
        return;
    }
    char searchName[50];
    printf("Nhap ten giao vien muon tim kiem: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; // Loai bo '\n'

    printf("\nKet qua tim kiem cho chuoi: \"%s\"\n", searchName);
    printf("|==========|====================|==============================|====================|=============|\n");
    printf("|%-10s|%-20s|%-30s|%-20s|%-13s|\n", "ID", "Name", "Email", "Phone", "NO.Course");
    printf("|==========|====================|==============================|====================|=============|\n");

    int found = 0; // Bien co ktra xem co teacher k
    int i;
    for (i = 0; i < currentLength; i++) {
        // Su dung strstr() de kiem tra chuoi co trong danh khong
        if (strstr(teacher[i].name, searchName) != NULL) {
            found = 1; // danh dau neu tim thay teacher
            printf("|%-10d|%-20s|%-30s|%-20s|%-13d|\n", 
                   teacher[i].teacherId, 
                   teacher[i].name, 
                   teacher[i].email, 
                   teacher[i].phone, 
                   teacher[i].teacherId);
            printf("|==========|====================|==============================|====================|=============|\n");
        }
    }
    if (found!=1) {
        printf("Khong tim thay giao vien nao voi ten : \"%s\"\n", searchName);
    }
}
void editTeacher(Teacher teacher[], int *currentLength) {
    if (*currentLength == 0) {
        printf("Danh sach giao vien hien dang trong. Khong co gi de sua.\n");
        return;
    }

    int id, i, j, valid;
    char input[100]; // Bien luu chuoi nhap vao

    printf("Nhap ID giao vien muon sua: ");
    scanf("%d", &id);
    getchar(); // Loai bo ky tu "\n"

    // Kiem tra ID hop le
    if (id < 1) {
        printf("ID giao vien khong hop le: %d\n", id);
        return;
    }

    int found = -1;
    for (i = 0; i < *currentLength; i++) {
        if (teacher[i].teacherId == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Khong tim thay giao vien voi ID: %d\n", id);
        return;
    }

    printf("\nThong tin hien tai cua giao vien:\n");
    printf("ID: %d\n", teacher[found].teacherId);
    printf("Ho Va Ten: %s\n", teacher[found].name);
    printf("Class ID: %s\n", teacher[found].classId);
    printf("So Dien Thoai: %s\n", teacher[found].phone);
    printf("Email: %s\n", teacher[found].email);

    printf("\nNhap thong tin moi cho giao vien (Nhap so 0 de bo qua):\n");

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
            strcpy(teacher[found].name, input);
        }
    } while (!valid);

    // Nhap Class ID
    do {
        printf("Class ID (Nhap so 0 de bo qua): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "0") == 0) {
            break;
        }

        valid = 1;
        if (strlen(input) == 0) {
            printf("Class ID khong duoc de trong. Vui long nhap lai.\n");
            valid = 0;
        } else if (strlen(input) > 9) {
            printf("Class ID khong duoc dai hon 9 ky tu. Vui long nhap lai.\n");
            valid = 0;
        } else {
            for (i = 0; input[i] != '\0'; i++) {
                if (isspace(input[i])) {
                    printf("Class ID khong duoc chua dau cach. Vui long nhap lai.\n");
                    valid = 0;
                    break;
                }
            }
        }

        if (valid) {
            strcpy(teacher[found].classId, input);
        }
    } while (!valid);

    // Nhap so dien thoai
    do {
        printf("So Dien Thoai (Nhap so 0 de bo qua): ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "0") == 0) {
            break;
        }

        valid = 1;
        int len = strlen(input);
        if (len < 10 || len > 11) {
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

        for (j = 0; j < *currentLength; j++) {
            if (j != found && strcmp(teacher[j].phone, input) == 0) {
                valid = 0;
                printf("So dien thoai da ton tai trong danh sach. Vui long nhap so khac.\n");
                break;
            }
        }

        if (valid) {
            strcpy(teacher[found].phone, input);
        }
    } while (!valid);

    // Nhap email
	do {
		printf("Nhap Email (Nhap so 0 de bo qua): ");
		fgets(input, sizeof(input), stdin);
		input[strcspn(input, "\n")] = '\0';
	
		if (strcmp(input, "0") == 0) {
			break;
		}
	
		valid = 1;
	
	    // Kiem tra dinh dang email
		char *at = strstr(input, "@gmail.com");
		if (!at || at == input) {
			valid = 0;
			printf("Email khong hop le. Vui long nhap lai (dinh dang x@gmail.com).\n");
		} else {
	        // Kiem tra khoang trang truoc @
			if (*(at - 1) == ' ') {
				valid = 0;
				printf("Email khong duoc co khoang trang truoc '@'. Vui long nhap lai.\n");
			}
		}
	
	    // Kiem tra email trung
		for (j = 0; j < *currentLength; j++) {
			if (j != found && strcmp(teacher[j].email, input) == 0) {
				valid = 0;
				printf("Email da ton tai trong danh sach. Vui long nhap email khac.\n");
				break;
			}
		}
		if (valid) {
			strcpy(teacher[found].email, input);
		}
	} while (!valid);
    printf("\n*** Thong tin giao vien da duoc cap nhat thanh cong! ***\n");
}
void deleteTeacher(Teacher teacher[], int *currentLength) {
    if (*currentLength == 0) {
        printf("Danh sach giao vien hien dang trong. Khong co gi de xoa.\n");
        return;
    }

    int id, i, found = -1;
    char confirm;

    printf("Nhap ID giao vien muon xoa: ");
    scanf("%d", &id);
    getchar(); // loai bo \n

    // tim vi tri id
    for (i = 0; i < *currentLength; i++) {
        if (teacher[i].teacherId == id) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Khong tim thay giao vien voi ID: %d\n", id);
        return;
    }

    // hien thi thong tin teacher muon xoa
    printf("Thong tin giao vien muon xoa:\n");
    printf("ID: %d\n", teacher[found].teacherId);
    printf("Ho Va Ten: %s\n", teacher[found].name);
    printf("So Dien Thoai: %s\n", teacher[found].phone);
    printf("Email: %s\n", teacher[found].email);

    printf("\nBan co chac chan muon xoa giao vien nay? (y/n): ");
    scanf(" %c", &confirm);
    getchar(); // xoa ki tu '\n'

    if (confirm == 'y' || confirm == 'Y') {
        // dong y xoa teacher
        for (i = found; i < *currentLength - 1; i++) {
            teacher[i] = teacher[i + 1];
        }

        // giam so luong danh sach
        (*currentLength)--;

        printf("Giao vien voi ID: %d da duoc xoa thanh cong.\n", id);
    } else {
        printf("Huy xoa giao vien.\n");
    }
}
void sortTeachersByName(Teacher teacher[], int currentLength) {
    if (currentLength == 0) {
        printf("Danh sach giao vien trong. Khong co gi de sap xep.\n");
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

    // Logic sap xep
    int i, j;
    for (i = 0; i < currentLength - 1; i++) {
        for (j = i + 1; j < currentLength; j++) {
            int compare = strcmp(teacher[i].name, teacher[j].name);
            if ((choice == 1 && compare > 0) || (choice == 2 && compare < 0)) {
                // Hoan doi 2 giao vien
                Teacher temp = teacher[i];
                teacher[i] = teacher[j];
                teacher[j] = temp;
            }
        }
    }
    printf("**** Sort Successfully ****\n");
}
void saveFileTeacher(Teacher teacher[], int length) {
    FILE *fptr = fopen("teacher.dat", "wb");
    if (fptr == NULL) {
        printf("Khong the mo file\n");
        return;
    }
    fwrite(teacher, sizeof(Teacher), length, fptr);
    printf("Them thanh cong teacher\n");
    fclose(fptr);
}
void readFileTeacher(Teacher teacher[], int *length) {
    FILE *fptr = fopen("teacher.dat", "rb");
    if (fptr == NULL) {
        printf("Khong the mo file\n");
        return;
    }
    *length = fread(teacher, sizeof(Teacher), 1000, fptr);
    printf("Doc file thanh cong teacher\n");
    fclose(fptr);
    system("cls");
}


