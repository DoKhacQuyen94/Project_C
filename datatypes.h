#include<stdbool.h>
// khai bao kieu du lieu
typedef struct{
	int studentId;
	char name[20];
	char phone[20];
	char email[30];
	char password[20];
}Student;

typedef struct {
	int month,day,year;
}Date;

typedef struct{
	int teacherId;
	char classId[20];
	char name[20];
	char phone[20];
	char email[20];
	char password[20];
}Teacher;
