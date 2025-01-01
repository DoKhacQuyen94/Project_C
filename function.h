#include"datatypes.h"
// Khai bao nguyen mau ham
void printfStudent(Student std[], int *length);
void displayMenu(void);
void end(void);
void menuAdmin(void);
void inputStudent(Student student[],int n,int *length);
void chooseYourRole(int *choice,Student student[], int *length,int *firstChoice);
void editStudent(Student student[], int *currentLength);
void deleteStudent(Student student[], int *currentLength);
void searchStudentByName(Student student[], int currentLength);
void sortStudentsByName(Student student[], int currentLength);
void loginAdmin(const char email[], const char password[]);
