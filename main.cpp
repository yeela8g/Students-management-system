//Ye'ela Granot	-	209133107	-	group 11
//upload intials details and calling menu unless pressed '0'

 #include "students_dec.h"//due to libraries+declaration of printMenu

int main() {
	student_manager s_mng = { 0 };//making the manager
	Reading_Student(s_mng);
	Reading_Course(s_mng);
	cout << "Data Loaded.\n";
	int choose;//calling the menu unless zero pressed
	do{
		PrintMenu(choose,s_mng);
	} while (choose);
}