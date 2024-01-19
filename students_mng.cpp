//Ye'ela Granot	-	209133107	-	group 11
//menu orinting + calling to function only

#include "students_dec.h"//libraries+functions declarations

void PrintMenu(int& choose, student_manager &s_mng) {//print the menu
	do {
		cout << "1) Add student" << endl;
		cout << "2) Delete student" << endl;
		cout << "3) Add course to student" << endl;
		cout << "4) Print student" << endl;
		cout << "5) Print average for student" << endl;
		cout << "6) Print all students" << endl;
		cout << "7) Print average of all students" << endl;
		cout << "8) Reset" << endl;
		cout << "0) Exit" << endl;
		cout << "Choose: " << endl;
		cin >> choose;
	} while (choose < 0 && choose > 8);//input_validation
	switch (choose){
	case 1: 
		Add_Student(s_mng);//add new pointer in the pointers array
		makeNewStudent(s_mng);//fill in the new student details:,
		break;
	case 2:
		Delete_Student(s_mng);
		break;
	case 3:
		add_course(s_mng);
		break;
	case 4:
		Print_Student(s_mng);
		break;
	case 5:
		Print_Student_Average(s_mng);
		break;
	case 6:
		print_All_Students(s_mng);
		break;
	case 7:
		Print_avg_Of_Avgs(s_mng);
		break;
	case 8:
		reset(s_mng);
		break;
	case 0:
		reset(s_mng);
		return;
	}//call function
}

