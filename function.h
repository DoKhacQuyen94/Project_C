#include"datatypes.h"
// Khai bao nguyen mau ham



void displayMenu(void);
void end(void);
void menuAdmin(void);

// students
void menuStudent(void);
void printfStudent(Student std[],int *length);
void inputStudent(Student student[], int n, int *currentLength);
void chooseYourRole(int *choice,Student student[], int *length,int *firstChoice);
void editStudent(Student student[], int *currentLength);
void deleteStudent(Student student[], int *currentLength);
void searchStudentByName(Student student[], int currentLength);
void sortStudentsByName(Student student[], int currentLength);
void loginAdmin(const char email[], const char password[]);
void saveFile(Student student[], int length);
void readFile(Student student[], int *length);

// Tearcher 
void printfTeacher(Teacher teacher[],int *lengthTeacher);
void menuTeacher(void);
void choiceTeacher(Teacher teacher[],int *lengthTeacher,int *firstChoice);
void addTeacher(Teacher teacher[],int *lengthTeacher);
void searchTeacherByName(Teacher teacher[], int currentLength);
void editTeacher(Teacher teacher[],int *currentLength);
void deleteTeacher(Teacher teacher[], int *currentLength);
void sortTeachersByName(Teacher teacher[], int currentLength);
void saveFileTeacher(Teacher teacher[], int length);
void readFileTeacher(Teacher teacher[], int *length);
