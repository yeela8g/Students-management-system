//Ye'ela Granot	-	209133107	-	group 11

#include "students_dec.h"//due to struct using+libraries

int BinarySearch(int left, int right, int id, const student_manager& s_mng) { //making a binar search with recursion 
	int middle = (left + right) / 2;//take the middle
	if (atoi(s_mng.Pstudents[middle]->Id) == id) { return middle; }
	if (middle == left) {//stop condition - only two remains
		if (atoi(s_mng.Pstudents[right]->Id) == id) { return right; }//it must be right because of the condition and line 7
		else {	return -1;}//the student not found
	}
	if (atoi(s_mng.Pstudents[middle]->Id) > id) {
		return BinarySearch(left, middle, id, s_mng);
	}
	else {
		return BinarySearch(middle, right, id, s_mng);
	}
 }

int Find_Student(const student_manager& s_mng, const char* id) {// return the index of the pointer to specific studet from binary search
	int ID = atoi(id);
	int right_index = (s_mng.StudentsCount - 1);
	int left_index = 0;
	return BinarySearch(left_index, right_index, ID, s_mng);
}

void Add_Course(const student_manager& s_mng, const char* id, const int courseNum, const int grade) { //3
	int index = Find_Student(s_mng, id);	//find the student with Id
	if (index == -1) {//if the student doesn't exist 
		cout << "ERROR: NO STUDENT "<< " " << id<< endl;
		return;
	}
	int courseCount = ++(s_mng.Pstudents[index]->CourseCount);	//number of courses he takes now
	if (courseCount == 1) {		//the first course in the array --> create array
		s_mng.Pstudents[index]->Pcourse = new course[courseCount];	//add array of courses in the size of course count
	}
	else {	//make bigger array of courses
		course* temp = new course[courseCount];	//make bigger array
		for (int i = 0; i < courseCount - 1; i++) {	//copy all courses to the new one
			temp[i] = s_mng.Pstudents[index]->Pcourse[i];
		}
		delete[] s_mng.Pstudents[index]->Pcourse;	// delete the old array
		s_mng.Pstudents[index]->Pcourse = temp;	// pont to the new array
		temp = NULL;	// null the temp pointer
	}
	s_mng.Pstudents[index]->Pcourse[courseCount-1].CourseNum = courseNum;	//enter course number
	s_mng.Pstudents[index]->Pcourse[courseCount-1].Grade = grade; //enter grade
}

int insert_index(const student_manager& s_mng, const char* id) {//make room for the new id in the array and return the relevant index
	int new_id = atoi(id);
	bool done = 0;
	int i = (s_mng.StudentsCount - 1);//begin with the last place on the array
	while (i>0 && !done) {//if it is the smallest index or bigger value in the comparison.
		if ((atoi(s_mng.Pstudents[i - 1]->Id) > new_id)) {
			student* temp = s_mng.Pstudents[i];//temporary hold the pointer to the bigger
			s_mng.Pstudents[i] = s_mng.Pstudents[i - 1]; // copy the bigger right 
			s_mng.Pstudents[i - 1] = temp;//swap
			temp = NULL;
			i--;
		}
		else { done = 1; }
	}
	return i;
}

void Add_Name_Id(const student_manager& s_mng, const char* name, const char* id) {//enter the name and ID with the right order
	int i = 0;
	int index = insert_index(s_mng, id);
	while (name[i] != '\0'){//input the name to the student profile
		s_mng.Pstudents[index]->Name[i] = name[i];
		++i;
	}
	s_mng.Pstudents[index]->Name[i] = '\0';
	for (int j=0; j< Sid; j++) {//input the name to the student profile - includes '\0'
		s_mng.Pstudents[index]->Id[j] = id[j];
	}
}

void Add_Student(student_manager& s_mng) {//add 1 students to the students_Array
	s_mng.StudentsCount++;//update number of students in manager
	if (s_mng.StudentsCount == 1) { // first student 
		s_mng.Pstudents = new student* [s_mng.StudentsCount];//create new dinamic array of pointers to the first student 
	}
	else {
		student** temp = new student* [s_mng.StudentsCount];//create temp array of pointers to students
		for (int i = 0; i < s_mng.StudentsCount - 1; i++){ // copy the old array to the new one
			temp[i] = s_mng.Pstudents[i];
		}
		delete [] s_mng.Pstudents;//delete old array
		s_mng.Pstudents = temp;//hold the new array
		temp = NULL;//reset the temp pointer
	}
	s_mng.Pstudents [s_mng.StudentsCount-1] = new student;//adding new student
	s_mng.Pstudents[s_mng.StudentsCount - 1]->CourseCount = 0;//reset the coure int
}


void Reading_Student(student_manager&s_mng) {//read each student details from the file
	cout << "Reading Student info file......\n";
	FILE* fp;
	char ID[Sid];//ID+(0)
	char ch;
	bool done = 0;
	char Name[Sname];//max name +(0)
	fopen_s(&fp, "Student_info.txt", "rt");
	if (fp)
	{
		do { 
			fread(ID, sizeof(char), Sid-1, fp);
			ID[Sid-1] = '\0';//ID ready
			int i = 0; // index to the name array
			do {  // Go over all characters after the ID untill end of line or EOF
				ch = fgetc(fp);
				if (ch == -1) {done = 1; }
				if (ch != ' ' && ch != '\n' && ch != EOF && !done) {
					Name[i] = ch;
					i++;
				}
			} while (ch != '\n' && ch != EOF && !done);
			Name[i] = '\0';//Name ready
			if (!done) {
				Add_Student(s_mng);
				Add_Name_Id(s_mng, Name, ID);
			}
		} while (ch != EOF && !done); // Line loop end 
	}
	else {
		cout << "File not found!\n";
		fclose(fp); -
		exit(1);
	}
	fclose(fp);-
}

void Reading_Course(student_manager& mng) { //read each student details from the file
	cout << "Reading Course info file......\n";
	FILE* fp1;
	char ID2[Sid];//ID+(0)
	char C_course[Scourse] = { 0 };//course+(0)
	char Grade[Sgrade];//grade+(0)
	int courseNum;
	int grade;
	char ch2 = 'S';//initaling
	bool done = 0;
	fopen_s(&fp1, "Course_info.txt", "rt");
	if (fp1){	
		do { // At least one loop will always occur
			do{
				ch2 = fgetc(fp1);
				if (ch2 == 'EOF' || ch2 == -1) { done = 1; }
			} while (ch2 == ' '|| ch2 == '\n');//eat spaces or new lines
			ID2[0] = ch2;	//get id
			for (int i = 1; i < Sid - 1; i++) {
				ch2 = fgetc(fp1);
				ID2[i] = ch2;
			}
			ID2[Sid - 1] = '\0';//ID ready
			int inspace = 1; //get course number
			int j = 0;
			while (!done && (ch2 != ' ' || inspace)) {
				ch2 = fgetc(fp1);//increament
				if (ch2 == 'EOF' || ch2 == -1) { done = 1; }
				if (ch2 != ' ') {//in the number
					C_course[j++] = ch2;
					inspace = 0;
				}//enter course number to string
			}
			C_course[Scourse - 1] = '\0';
			courseNum = atoi(C_course);//convert to integer - course number is ready
			int i = 0;//get grade
			while ((ch2 != '\n') && (ch2 != EOF) && !done) {
				ch2 = fgetc(fp1);//read first char
				if (ch2 == 'EOF' || ch2 == -1) { done = 1; }
				if (ch2 != ' ' && ch2 != '\n' && !done) {// if it is a number
					Grade[i++] = ch2;//enter it
				}
			}
			if (!done) {
				Grade[i] = '\0';
				grade = atoi(Grade);
				Add_Course(mng, ID2, courseNum, grade);
			}
		} while (ch2 != 'EOF' && !done);
	}
	else {
		cout << "File not found!\n";
		exit(1);
	}
	fclose(fp1);
 }

void makeNewStudent(student_manager& s_mng) {	//get the student details from the user
	char name[Sname];
	char id[Sid];
	int CoursCount;
	int Num_of_Course;
	int grade;
	cout << "Name: ";//name
	cin >> name;
	cout << "Id: ";//id
	cin >> id;
	Add_Name_Id(s_mng, name, id);
	cout << "Number of courses: ";//how many courses he has
	cin >> CoursCount;
	for (int i = 0; i < CoursCount; i++){
		cout << "Number: ";	//number of courses
		cin >> Num_of_Course;
		cout << "Grade: ";//grades
		cin >> grade;
		Add_Course(s_mng, id, Num_of_Course, grade);
	}
}

void Delete_Student(student_manager& s_mng) {//remove the student and update the size
	char id[Sid];//get id
	cout << "Id: ";
	cin >> id;
	int index = Find_Student(s_mng, id);//get index
	if (index == -1) {//if the student doesn't exist 
		cout << "ERROR: NO STUDENT "<< endl;
		return;
	}
	--s_mng.StudentsCount;//update students number
	if (s_mng.StudentsCount == 0) {//if we delete the last student (kinda sad:\)
		delete[] s_mng.Pstudents[s_mng.StudentsCount]->Pcourse;//delete courses array
		delete s_mng.Pstudents[s_mng.StudentsCount];//delete student
		delete[] s_mng.Pstudents;//delete the pointers2students array
		s_mng.Pstudents = NULL;//reset the mng pointer
	}
	else {
		
		student** temp = new student * [4*s_mng.StudentsCount];
		for (int i = 0; i < index; i++) {//copy all students before the hole
			temp[i] = s_mng.Pstudents[i];
		}
		for (int i = index; i < s_mng.StudentsCount; i++) {//copy all students after the hole
			temp[i] = s_mng.Pstudents[i + 1];
		}
		delete[] s_mng.Pstudents[index]->Pcourse;//delete courses array of the student
		delete s_mng.Pstudents[index];//delete the student
		delete[] s_mng.Pstudents;//delete old array
		s_mng.Pstudents = temp;//point to the new array
		temp = NULL;//remove old pointer
	}
}

void add_course(student_manager& s_mng) { //add new course to student from the user
	int Num_of_Course;
	int grade;
	char id[Sid];
	cout << "Id: " ;//get id
	cin >> id;
	cout << "Number: " ;	//number of courses
	cin >> Num_of_Course;
	cout << "Grade: " ;//grades
	cin >> grade;
	Add_Course(s_mng, id, Num_of_Course, grade);
}

void Print_Student(const student_manager& s_mng) { //print student details
	char id[Sid];
	cout << "Id: " ;//get id
	cin >> id; 
	int index=Find_Student(s_mng, id);
	if (index == -1) {//if the student doesn't exist 
		cout << "ERROR: NO STUDENT "<< endl;
		return;
	}
	cout << s_mng.Pstudents[index]->Name << " " << s_mng.Pstudents[index]->Id << endl;
	cout << s_mng.Pstudents[index]->CourseCount << endl;
	for (int i = 0; i < s_mng.Pstudents[index]->CourseCount; i++){
		cout << s_mng.Pstudents[index]->Pcourse[i].CourseNum << " " << s_mng.Pstudents[index]->Pcourse[i].Grade << endl;
	}
}

void Print_Student_Average(const student_manager& s_mng){ //print average ..
	char id[Sid];
	cout << "Id: " ;//get id
	cin >> id;
	int index = Find_Student(s_mng,id);
	if (index == -1) {//if the student doesn't exist 
		cout << "ERROR: NO STUDENT "<< endl;
		return;
	}
	int sum = 0;
	for (int i = 0; i < (s_mng.Pstudents[index]->CourseCount); i++)
	{
		sum += (s_mng.Pstudents[index]->Pcourse[i].Grade);
	}//loop sums all the grades
	if (s_mng.Pstudents[index]->CourseCount != 0) {
		cout << "Average grade : \n" << sum / (s_mng.Pstudents[index]->CourseCount) << endl;
	}
	else return;
 }

void print_All_Students(const student_manager& s_mng) {
	for (int index = 0; index < s_mng.StudentsCount; index++) {//outer loop runs studentsize times
		cout << s_mng.Pstudents[index]->Name << " " << s_mng.Pstudents[index]->Id << endl;
		cout << s_mng.Pstudents[index]->CourseCount << endl;
		for (int i = 0; i < s_mng.Pstudents[index]->CourseCount; i++) {//inside loop goes over the courses of each student
			cout << s_mng.Pstudents[index]->Pcourse[i].CourseNum << " " << s_mng.Pstudents[index]->Pcourse[i].Grade << endl;
		}
	}
}

void Print_avg_Of_Avgs(const student_manager& s_mng) {
	int NOcourses = 0;
	int Average = 0;
	for (int index = 0; index < s_mng.StudentsCount; index++) {//amount of students
		int sum = 0;
		for (int i = 0; i < (s_mng.Pstudents[index]->CourseCount); i++)//calcualte avrage of each student
		{
			sum += (s_mng.Pstudents[index]->Pcourse[i].Grade);
		}//loop sums all the grades for one student
		if ((s_mng.Pstudents[index]->CourseCount) != 0) { Average += (sum / (s_mng.Pstudents[index]->CourseCount)); }
		else {
			NOcourses++;
			continue;
		}
	}
	if (Average) {
		cout << "Average grade : \n" << Average / (s_mng.StudentsCount - NOcourses) << endl;
	}
}

void reset(student_manager& s_mng) { //8
	if (s_mng.StudentsCount) {//make sure there are students to reset
		for (int i = 0; i < s_mng.StudentsCount; i++) {
			delete[] s_mng.Pstudents[i]->Pcourse;	//delete array of courses
			delete s_mng.Pstudents[i];	//delete student
		}
		delete[] s_mng.Pstudents;	//delete array of pointers to students
		s_mng.Pstudents = NULL;
		s_mng.StudentsCount = 0;//reset number of students
	}
}


