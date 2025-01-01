#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include "function.h"
int main(int argc, char *argv[]) {
	int choice,firstChoice;
	int length =0 ;
	char email[20]="tpq0904@gmail.com";
	char password[20]="1111";
	Student student[1000];
	do{
		displayMenu();
		scanf("%d",&firstChoice);	
		getchar();
		system("cls");
		switch(firstChoice){
			case 1:
				loginAdmin(email,password);
				system("cls");
    			chooseYourRole(&choice,student,&length,&firstChoice);
				break;
			case 2:
				system("cls");
				printfStudent(student,&length);
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
