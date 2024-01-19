//Ye'ela Granot	-	209133107	-	group 11
//declartions includes structs defines

using namespace std;
#include <iostream> 
#include <stdio.h>
#include <stdlib.h>
const int Sid =10;
const int Sname = 11;
const int Scourse = 6;
const int Sgrade = 4;
#ifdef __unix
#define fopen_s(pFile,filename,mode) ((*(pFile))=fopen((filename),(mode)))==NULL
#endif

struct course {
	int CourseNum;
	int Grade;
};
struct student {
	char Name[Sname];//+1 to the '0'
	char Id[Sid];// -||-
	int	CourseCount;
	course* Pcourse;
};
struct student_manager {
	int StudentsCount;
	student** Pstudents;
};

void makeNewStudent(student_manager&);
void Reading_Student (student_manager&);
void Reading_Course(student_manager&);
void PrintMenu(int&, student_manager&);
void Add_Student(student_manager&);
void Delete_Student(student_manager&);
void Add_Course(const student_manager&, const char*, const int, const int);
void add_course(student_manager&);
void Print_Student(const student_manager&);
void Print_Student_Average(const student_manager&);
void print_All_Students(const student_manager&);
void Print_avg_Of_Avgs(const student_manager&);
void reset(student_manager&);
int Find_Student(const student_manager&, const char*);






