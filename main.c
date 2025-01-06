#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "function.h"
int main(int argc, char *argv[]) {
	int choice,firstChoice,secondChoice;
	int length =0 ;
	int lengthTeacher=0;
	char email[20]="tpq0904@gmail.com";
	char password[20]="1";
	Student student[1000];
	Teacher teacher[1000];
	readFile(student,&length);
	readFileTeacher(teacher,&lengthTeacher);
	do{
		displayMenu();
		scanf("%d",&firstChoice);	
		getchar();
		system("cls");
		switch(firstChoice){
			case 1:
				loginAdmin(email,password);
				system("cls");
				menuAdmin();
				scanf("%d",&secondChoice);
				getchar();
				switch(secondChoice){
					case 1:
						chooseYourRole(&choice,student,&length,&firstChoice);
						break;
					case 2:
						choiceTeacher(teacher,&lengthTeacher,&firstChoice);
					case 0:
						system("cls");
						end();
						break;
					default:
						printf("Lua chon sai. Vui long chon lai\n");
						break; 
				}
				break;
			case 2:
				system("cls");
				printfStudent(student,&length);
    			break;
    		case 3:
    			printfTeacher(teacher,&lengthTeacher);
    			break;
    		case 0:
    			end();
    			break;
			default:
				printf("Lua chon sai. Vui long chon lai\n");
				break;
		}
	}while(firstChoice!=0);
	return 0;
}
