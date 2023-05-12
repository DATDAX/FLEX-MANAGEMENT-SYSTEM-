#include "header.h"
string teach = "teacher.txt";
string login = "login.txt";
string student = "student.txt";
string hod = "hod.txt";
string marks = "marks.txt";
string grade = "grade.txt";
string attendence = "attendance.txt";
string FEE = "fee.txt";
string coursee = "course.txt";
string timetablee = "timetable.txt";
string Tlogin = "tlogin.txt";
string Slogin = "Slog.txt";
string hlogin = "hlogin.txt";

Hod::Hod()
{
    teach = new Teacher[10];
}
Student::Student(){}
Teacher::Teacher(){}
Admin::Admin(){}


int validateChoice()
{
    try
    {
        int choice;
        cin >> choice;
        if (cin.fail())
        {
            throw "\033[31mInvalid input. Please enter a number\033[0m\n.";
        }
        if (choice < 0)
        {
            throw "\033[31mInvalid input.\033[0m\n.";
        }
        return choice;
    }
    catch (const char* msg)
    {
        cerr << "Error: " << msg << endl;
        ///  cin.cls();
        cin.ignore();
        validateChoice();
    }
}
void Teacher::Timetable()
{
    system("cls");

    string teacherName;
    string courseName;
    string date;
    string sTime;
    string eTime;

    ofstream file(timetablee, ios::app);

    if (file.is_open())
    {
        cout << "\033[34mEnter teacher name: \033[0m";
        getline(cin, teacherName);
        system("cls");

        cout << "\033[34mEnter Course name: \033[0m";
        getline(cin, courseName);
        system("cls");

        cout << "\033[34mEnter date: \033[0m";
        getline(cin, date);
        system("cls");

        cout << "\033[34mEnter start time (hh:mm): \033[0m";
        getline(cin, sTime);
        system("cls");
        cout << "\033[34mEnter end time (hh:mm): \033[0m";
        getline(cin, eTime);
        system("cls");
        file << "Teacher Is " << teacherName << ", Course Is " << courseName << "," << date << "," << sTime << ", to " << eTime << endl;
        file.close();

        cout << "\033[34mTimetable is uploaded successfully.\n\033[0m";
    }
    else
    {
        cout << "\033[31mFile is not opened.\033[0m" << endl;
    }
}
void Teacher::viewTimetable()
{
    system("cls");
    ifstream file(timetablee);

    if (file.is_open())
    {
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
        file.close();
    }
    else
    {
        cout << "\033[31mFile is not opened.\033[0m" << endl;
    }
}
///////////////////////////////////
void Admin::editStudentDetails(string student)
{
    system("cls");
    string file = student;
    string tempfile = "tempfile.txt";
    string line;
    string oldstr, newstr;
    ifstream filein(file);
    ofstream fileout(tempfile);

    if (filein.is_open())
    {
        cin.ignore();
        cout << "\033[34mEnter the Details to be replaced:\n \033[0m";
        getline(cin, oldstr);
        cout << "\033[34mEnter New Details:\n \033[0m";
        getline(cin, newstr);

        while (getline(filein, line))
        {
            size_t pos = line.find(oldstr);
            while (pos != string::npos)
            {
                line.replace(pos, oldstr.length(), newstr);
                pos = line.find(oldstr, pos + newstr.length());
            }
            fileout << line << endl;
        }

        filein.close();
    }
    else
    {
        cout << "\033[31mFile is not opened.\n\033[0m" << endl;
    }
}
bool stringExistsInFile(string inputString, string n)
{
    ifstream file(n);
    string line;
    while (getline(file, line))
    {
        if (line == inputString)
        {
            return true;
        }
    }
    return false;
}
////////////////////////////teacherrr//////////

void Teacher::mark_attendance()
{
    system("cls");
    string courseName;
    int numStudents;
    string date, attendance;
    ofstream attendanceFile;
    attendanceFile.open(attendence, ios::app);
    if (!attendanceFile.is_open())
    {
        cout << "Failed to open attendance file." << endl;
    }
    else
    {
        cin.ignore();
        cout << "Enter Course name: ";
        getline(cin, courseName);
        cout << "Enter the number of students in the class: ";
        cin >> numStudents;
        cin.ignore();

        for (int i = 0; i < numStudents; i++)
        {
            string studentId;
            cin.ignore();

            cout << "Enter the id of student " << i + 1 << ": ";
            getline(cin, studentId);

            cout << "Enter date in yyyy-mm-dd format: ";
            cin >> date;

            while (true)
            {
                cout << "Enter attendance for P for Present and A for Absent: ";
                cin >> attendance;
                if (attendance == "P" || attendance == "A")
                {
                    break;
                }
                cout << "Invalid input. Attendance can only be P or A." << endl;
            }

            attendanceFile << studentId << "," << courseName << "," << date << "," << attendance << endl;

            cout << "Attendance has been marked successfully for " << studentId << "." << endl;
        }
        attendanceFile.close();
    }
}
void Teacher::assign_marks()
{
    ofstream marksFile;
    system("cls");
    marksFile.open(marks, ios::app);
    if (!marksFile.is_open())
    {
        cout << "Failed to open marks file." << endl;
    }
    else
    {
        string courseName;
        string studentId;
        int studentMarks;
        cin.ignore();
        cout << "Enter Course name: ";
        getline(cin, courseName);
        while (true)
        {
            cin.ignore();
            cout << "Enter the id of the student (or 'quit' to exit): ";
            getline(cin, studentId);

            if (studentId == "quit")
            {
                break;
            }

            cout << "Enter the marks for " << studentId << ": ";
            cin >> studentMarks;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore();
                throw invalid_argument("Invalid input. Please enter a valid integer value for marks.");
            }

            if (studentMarks < 0 || studentMarks > 100)
            {
                throw out_of_range("Marks should be between 0 and 100.");
            }

            marksFile << studentId << "," << courseName << "," << studentMarks << endl;
        }

        cout << "Marks have been assigned successfully." << endl;
        marksFile.close();
    }
}

void Teacher::assign_grades()
{
    system("cls");
    ofstream gradeFile;
    gradeFile.open(grade, ios::app);
    if (!gradeFile.is_open())
    {
        cout << "Failed to open grade file." << endl;
    }
    else
    {
        string courseName;
        string studentId;
        char studentGrade;
        cin.ignore();
        cout << "Enter Course name: ";
        getline(cin, courseName);
        system("cls");
        while (true)
        {
            cin.ignore();
            cout << "Enter the id of the student (or 'quit' to exit): ";
            getline(cin, studentId);
            system("cls");

            if (studentId == "quit")
            {
                break;
            }

            cout << "Enter the grade for " << studentId << ": ";
            cin >> studentGrade;
            system("cls");
            gradeFile << studentId << "," << courseName << "," << studentGrade << endl;
        }

        cout << "Grades have been assigned successfully." << endl;
        gradeFile.close();
        system("cls");
    }
}
void Teacher::register_course()
{
    ofstream courseFile;
    courseFile.open(coursee, ios::app);
    if (!courseFile.is_open())
    {
        cout << "Failed to open course file." << endl;
    }
    else
    {
        string courseName;
        string studentId;
        string studentcourse[4];
        cin.ignore();
        cout << "Enter Course name: ";
        getline(cin, courseName);
        system("cls");
        while (true)
        {
            cin.ignore();
            cout << "Enter the id of the student (or 'quit' to exit): ";
            getline(cin, studentId);
            system("cls");

            if (studentId == "quit")
            {
                break;
            }
            courseFile << studentId << ",";

            for (int i = 0; i < 4; i++)
            {

                cout << "Enter the 4 courses  to register for " << studentId << ": ";
                cin >> studentcourse[i];
                courseFile << studentcourse[i] << ",";
            }
            courseFile << endl;
        }

        cout << "Courses have been registered successfully." << endl;
        system("cls");
        courseFile.close();
    }
}

///////////////////student functionnnn/////////
void Student::view_marks()
{

    string studentId;

    cout << "Enter the student ID: ";
    cin >> studentId;
    system("cls");

    ifstream marksFile(marks);
    string line;
    string id;
    string course;
    string marksStr;
    int marks;

    bool found = false;
    if (!marksFile.is_open())
    {
        cout << "Failed to open marks file." << endl;
    }

    else
    {

        while (getline(marksFile, line))
        {

            int commaPos = line.find(',');
            if (commaPos == string::npos)
            {
                continue;
            }
            id = line.substr(0, commaPos);

            int startpos = commaPos + 1;
            int endpos = line.find(',', startpos);
            if (endpos == string::npos)
            {
                continue;
            }
            course = line.substr(startpos, endpos - startpos);

            marksStr = line.substr(endpos + 1);
            marks = stoi(marksStr);

            if (id == studentId)
            {
                found = true;
                cout << "Student ID: " << id << ", Course: " << course << ", Marks: " << marks << endl;
            }
        }

        if (!found)
        {
            cout << "Student with ID " << studentId << " not found." << endl;
        }

        marksFile.close();
    }
}

void Student::view_grades()
{

    string studentId;

    cout << "Enter the student ID: ";
    cin >> studentId;
    system("cls");
    ifstream gradesFile(grade);
    string line;
    string id;
    string course;
    string gradeStr;
    string grade;
    bool found = false;
    int my = 0;
    if (!gradesFile.is_open())
    {
        my = 1;
        cout << "Failed to open grades file." << endl;
    }
    else
    {

        while (getline(gradesFile, line))
        {

            int commaPos = line.find(',');
            if (commaPos == string::npos)
            {
                continue;
            }
            id = line.substr(0, commaPos);

            int startpos = commaPos + 1;
            int endpos = line.find(',', startpos);
            if (endpos == string::npos)
            {
                continue;
            }
            course = line.substr(startpos, endpos - startpos);

            gradeStr = line.substr(endpos + 1);
            grade = gradeStr;

            if (id == studentId)
            {
                found = true;
                cout << "Student ID: " << id << ", Course: " << course << ", Grade: " << grade << endl;
            }
        }
        gradesFile.close();
    }
    if (my == 0)
    {

        if (!found)
        {
            cout << "Student with ID " << studentId << " not found.\n"
                << "ENTER 1 TO TRY AGAIN\n";
            int input;
            cin >> input;
            switch (input)
            {
            case 1:
                view_grades();
                break;
            default:
                break;
            }
        }
    }
}
void Student::view_attendance()
{
    string studentId;
    cin.ignore();
    cout << "Enter the ID of the student to view attendance: " << endl;
    getline(cin, studentId);
    system("cls");

    ifstream attendanceFile(attendence);
    string line;
    bool found = false;
    int my = 0;
    if (!attendanceFile.is_open())
    {
        my = 1;
        cout << "Failed to open attendance file.";
    }
    else
    {

        while (getline(attendanceFile, line))
        {
            size_t pos = line.find(",");
            if (pos != string::npos)
            {
                string id = line.substr(0, pos);
                if (id == studentId)
                {
                    found = true;
                    cout << line << endl;
                }
            }
        }
        attendanceFile.close();
    }
    if (my == 0)
    {

        if (!found)
        {
            cout << "Attendance not found for student with ID " << studentId << "."
                << "\nENTER 1 TO TRY AGAIN\n";
            int input;
            cin >> input;
            system("cls");
            switch (input)
            {
            case 1:
                view_attendance();
                break;
            default:
                break;
            }
        }
    }
}
void Student::view_courses()
{
    string studentId;
    cin.ignore();
    cout << "Enter the ID of the student to view course: ";
    getline(cin, studentId);
    system("cls");

    ifstream courseFile(coursee);

    string line;

    bool found = false;
    int my = 0;
    if (!courseFile.is_open())
    {
        my = 1;
        cout << "Failed to open course file." << endl;
    }

    else
    {

        while (getline(courseFile, line))
        {
            size_t pos = line.find(",");
            if (pos != string::npos)
            {
                string id = line.substr(0, pos);
                if (id == studentId)
                {
                    found = true;
                    cout << line << endl;
                }
            }
        }

        courseFile.close();
    }
    if (my == 0)
    {

        if (!found)
        {
            cout << "course not found for student with ID " << studentId << ".\n"
                << "ENTER 1 TO TRY AGAIN\n";
            int input;
            cin >> input;
            system("cls");
            switch (input)
            {
            case 1:
                view_courses();
                break;
            default:
                break;
            }
        }
    }
}
void Student::view_feestatus()
{
    string studentId;
    cout << "Enter student Id: ";
    getline(cin, studentId);
    system("cls");
    ifstream feeFile(FEE);
    string line;
    string id;
    string firstName;
    string lastName;
    string status;
    if (!feeFile.is_open())
    {
        cout << "Error." << endl;
    }
    else
    {
        cout << "Fee status for all registered students:" << endl;
        while (getline(feeFile, line))
        {

            size_t pos1 = line.find(",");
            if (pos1 != string::npos)
            {
                id = line.substr(0, pos1);
                size_t pos2 = line.find(",", pos1 + 1);
                if (pos2 != string::npos)
                {
                    firstName = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    size_t pos3 = line.find(",", pos2 + 1);
                    if (pos3 != string::npos)
                    {
                        lastName = line.substr(pos2 + 1, pos3 - pos2 - 1);
                        status = line.substr(pos3 + 1);
                    }
                }
            }
            if (id == studentId)
            {

                cout << "Student ID: " << id << endl;
                cout << "Name: " << firstName << " " << lastName << endl;
                cout << "Fee Status: " << status << endl;
                cout << endl;
            }
            else if (id != studentId)
            {
                cout << "Student With : " << studentId << " not found" << endl;
            }
        }

        feeFile.close();
    }
}
////////////////increment in teacher and student id/////////////////
void Teacher::operator++(int)
{
    ID++;
}
string Teacher::getId()
{
    ifstream inFile("t_id.txt");
    inFile >> ID;
    inFile.close();

    (*this)++;

    ofstream outFile("t_id.txt");
    outFile << ID;
    outFile.close();

    return to_string(ID);
}

void Student::operator++(int)
{
    ID++;
}
string Student::getId()
{
    ifstream inFile("t_id.txt");
    inFile >> ID;
    inFile.close();

    (*this)++;

    ofstream outFile("t_id.txt");
    outFile << ID;
    outFile.close();

    return to_string(ID);
}
void Admin::editTeacherDetails(string teach)
{
    system("cls");
    string file = teach;
    string tempfile = "tempfile.txt";
    string line;
    string oldstr, newstr;
    ifstream filein(file);
    ofstream fileout(tempfile);

    if (filein.is_open())
    {
        cin.ignore();
        cout << "Enter the Details to be replaced: ";
        getline(cin, oldstr);
        cout << "Enter new Details: ";
        getline(cin, newstr);

        while (getline(filein, line))
        {
            size_t pos = line.find(oldstr);
            while (pos != string::npos)
            {
                line.replace(pos, oldstr.length(), newstr);
                pos = line.find(oldstr, pos + newstr.length());
            }
            fileout << line << endl;
        }

        filein.close();
        fileout.close();

        remove(file.c_str());
        rename(tempfile.c_str(), file.c_str());
    }
    else
    {
        cout << "\033[31mERROR\033[0m" << endl;
    }
}
void Admin::viewAllTeacher(string teach)
{
    system("cls");
    ifstream teacher(teach);
    string line;

    if (teacher.is_open())
    {
        while (getline(teacher, line))
        {
            cout << line << endl;
        }
        teacher.close();
    }
    else
    {
        cout << "\033[31mERROR\033[0m" << endl;
    }
}
void Admin::viewAllStudents(string student)
{
    system("cls");
    ifstream Student(student);
    string line;

    if (Student.is_open())
    {
        while (getline(Student, line))
        {
            cout << line << endl;
        }
        Student.close();
    }
    else
    {
        cout << "\033[31mERROR\033[0m" << endl;
    }
}
void Admin::addStudent(string n)
{
    system("cls");
    string Fname, Lname, DepartmentName, RegistrationDate, Gender, ContactNo,

        Qualification, Address, id, bloodGroup, fee;

    cout << "\033[34m\nENTER TEACHERS First NAME And Last NAME:\033[0m";
    cin >> Fname >> Lname;
    cout << "\033[34m\nNATER GENDER:\033[0m";
    cin >> Gender;
    cout << "\033[34m\nENTER REGISTRATION DATE:\033[0m";
    cin >> RegistrationDate;
    cout << "\033[34m\nENTER CONTACT NO:\033[0m";
    cin >> ContactNo;
    cout << "\033[34m\nENTER QUALIFICATION:\033[0m";
    cin >> Qualification;
    cout << "\033[34m\nENTER ADDRESS:\033[0m";
    cin >> Address;
    cout << "\033[34m\nEnter BLOOD GROUP OF STUDENT:\n\033[0m";
    cin >> bloodGroup;
    cout << "\033[34mENTER FEE STATUS Y/N:\033[0m";
    cin >> fee;

    id = "22F-";

    id += getId();
    cout << id;
    string input = id + "," + Fname + "," + Lname + "," + Address + "," + Gender + "," + ContactNo + "," + Qualification + "," + RegistrationDate + "," + fee + ",";
    if (!stringExistsInFile(input, n))
    {
        ofstream writefile;
        writefile.open(n, ios::app);
        writefile << endl;
        writefile << id + ",";
        writefile << Fname + ",";
        writefile << Lname + ",";
        writefile << Address + ",";
        writefile << Gender + ",";
        writefile << ContactNo + ",";
        writefile << Qualification + ",";
        writefile << RegistrationDate + ",";
        writefile << fee + "," << endl;

        writefile.close();
    }
    else
    {
        cout << "\033[31mThis data already exists in the file. Enter different Data: \033[0m";

        addStudent(n);
    }
}

void Admin::addTeacher(string n)
{
    system("cls");
    string Fname, Lname, DepartmentName, RegistrationDate, Gender, ContactNo,

        Qualification, Address, id;

    cout << "\033[34m\nENTER TEACHERS First NAME And Last NAME:\033[0m";
    cin >> Fname >> Lname;
    cout << "\033[34m\nEATER GENDER:\033[0m";
    cin >> Gender;
    cout << "\033[34m\nENTER REGISTRATION DATE:\033[0m";
    cin >> RegistrationDate;
    cout << "\033[34m\nENTER CONTACT NO:\033[0m";
    cin >> ContactNo;
    cout << "\033[34m\nENTER QUALIFICATION:\033[0m";
    cin >> Qualification;
    cout << "\033[34m\nENTER ADDRESS:\033[0m";
    cin >> Address;

    id = "22T-";
    id += getId();

    ofstream writefile;
    writefile.open(n, ios::app);
    writefile << id + ",";
    writefile << Fname + ",";
    writefile << Lname + ",";
    writefile << Address + ",";
    writefile << Gender + ",";
    writefile << ContactNo + ",";
    writefile << Qualification + ",";
    writefile << RegistrationDate + "," << endl;

    writefile.close();
}

////////////////////////////////////////////////////////////////// SIGN IN FUNCTIONS /////////////////////////////////////////////////////////////////

bool validateLogin(string n, string UserName, string Password)
{ // string n is the name of text file to be opened
    ifstream file(n);

    if (file.is_open())
    { // login file opens

        string line;

        while (getline(file, line))
        {

            string fileUsername = line.substr(0, line.find(','));

            string filePassword = line.substr(line.find(',') + 1);

            if (UserName == fileUsername && Password == filePassword)
            {

                file.close();

                return true; // returns true if information entered is correct
            }
        }

        file.close();
    }
    else
    {
        cout << "payeen file ni kholi";
    }
    return false; // returns false if information is not true
}
void Admin::signIn(string n)
{
    // system("cls");
    cin.ignore();
    cout << "\x1B[36mPlease enter your UserName:\033[0m\t\t\n"
        << endl;
    getline(cin, this->UserName);
    // system("cls");
    cout << "\x1B[36mPlease enter your Password:\033[0m\t\t\n " << endl;
    getline(cin, this->Password);

    if (!validateLogin(n, UserName, Password)) // checks the information in file
    {
        cout << "\x1B[36mINVALID CREDENTIALS:\033[0m\t\t\n"
            << endl;
        cin.ignore();
        signIn(login);
    }

    else
    {
        cout << "\033[32mLOGIN SUCCESSFULL\033[0m" << endl;
        cout << "\033[32mWELCOME " << UserName << "\033[0m" << endl;
    }
}
void Hod::signIn(string n)
{
    // system("cls");
    cin.ignore();
    cout << "\033[34mPlease enter your UserName: \033[0m" << endl;

    getline(cin, this->UserName);
    // system("cls");
    cout << "\033[34mPlease enter your Password: \033[0m" << endl;

    getline(cin, this->Password);

    if (!validateLogin(n, UserName, Password)) // checks the information in file
    {
        cout << "\033[31mINVALID CREDENTIALS\033[0m" << endl;

        cin.ignore();
        signIn(login);
    }
    else
    {
        cout << "\033[32mLOGIN SUCCESSFULL\033[0m" << endl;
        cout << "\033[32mWELCOME " << UserName << "\033[0m" << endl;
    }
}
void Teacher::signIn(string n)
{
    // system("cls");
    cin.ignore();
    cout << "\033[34mPlease enter your UserName: \033[0m" << endl;

    getline(cin, this->UserName);
    cin.ignore();
    /// system("cls");
    cout << "\033[34mPlease enter your Password: \033[0m" << endl;

    getline(cin, this->Password);
    if (!validateLogin(n, UserName, Password)) // checks the information in file
    {
        cout << "\033[31mINVALID CREDENTIALS\033[0m" << endl;
        cin.ignore();
        //  system("cls");
        signIn(login);
    }

    else
    {
        cout << "\033[32mLOGIN SUCCESSFULL\033[0m" << endl;
        cout << "\033[32mWELCOME " << UserName << "\033[0m" << endl;
    }
}
void Student::signIn(string n)
{
    // system("cls");
    cin.ignore();
    cout << "\033[34mPlease enter your UserName: \033[0m" << endl;

    getline(cin, this->UserName);
    // system("cls");
    cout << "\033[34mPlease enter your Password: \033[0m" << endl;
    getline(cin, this->Password);
    // system("cls");

    if (!validateLogin(n, UserName, Password)) // checks the information in file
    {
        cout << "\033[31mINVALID CREDENTIALS\033[0m" << endl;
        cin.ignore();
        //    system("cls");
        signIn(login);
    }

    else
    {
        cout << "\033[32mLOGIN SUCCESSFULL\033[0m" << endl;
        cout << "\033[32mWELCOME " << UserName << "\033[0m" << endl;
    }
}

void AdminMenu(Admin a)
{
    // system("cls");
    cout << "\033[3;47;35mENTER 1 TO ADD TEACHER:\033[0m\t\t\n\033[3;47;35mENTER 2 TO VIEW ALL TEACHERS :\033[0m\t\t\n\033[3;44;30mENTER 3 TO EDIT TEACHER:\033[0m\t\t\nENTER 4 TO VIEW ALL STUDENTS:\nENTER 5 TO EDIT STUDENT DETAILS:\nENTER 6 TO ADD STUDENT:\nENTER 7 TO LOG-OUT:";

    switch (validateChoice())
    {
    case 1:
        a.addTeacher(teach);

        AdminMenu(a);
        break;
    case 2:
        a.viewAllTeacher(teach);

        AdminMenu(a);
        break;
    case 3:
        a.editTeacherDetails(teach);
        AdminMenu(a);
        break;
    case 4:
        a.viewAllStudents(student);
        AdminMenu(a);
        break;
    case 5:
        a.editStudentDetails(student);
        AdminMenu(a);
        break;
    case 6:
        a.addStudent(student);
        AdminMenu(a);
        break;
    case 7:
        break;
    default:
        system("cls");
        cout << "\033[3;41;30INVALID CHOICE: ENTER CHOICE AGAIN\033[0m\t\t" << endl;
        ;
        AdminMenu(a);
    }
}
void studentMenu(Student s)
{
    // system("cls");
    cout << "\x1B[36mENTER 1 TO VIEW GRADES:\nENTER 2 TO VIEW ATTENDENCE:\nENTER 3 TO VIEW FEE STATUS\nENTER 4 TO VIEW COURSES:\nENTER 5 TO LOG OUT:\n\033[0m\t\t";

    switch (validateChoice())
    {
    case 1:
        s.view_grades();

        studentMenu(s);
        break;
    case 2:
        s.view_attendance();
        studentMenu(s);
        break;
    case 3:
        s.view_feestatus();
        studentMenu(s);
        break;
    case 4:
        s.view_courses();
        studentMenu(s);
    case 5:
        break;
    default:
        cout << "\x1B[36mINVALID INPUT\n\033[0m\t\t";
        cout << "\x1B[36mENTER INPUT AGAIN\n\033[0m\t\t";
        studentMenu(s);
        break;
    }
}
void hodMenu(Hod h)
{
    // system("cls");
    cout << "\033[38;2;255;255;0mENTER 0 TO VIEW TIMETABLE\nENTER 1 TO MARK GRADES:\nENTER 2 TO ASSIGN MARKS:\nENTER 3 TO MARK ATTENDENCE:\nENTER 4 TO REGISTER COURSE:\nENTER 5 TO VIEW TIMETABLE:\nENTER 6 TO VIEW ATTENDENCE OF STUDENR\nENTER 7 TO VIEW COURSES:\nENTER 8 TO VIEW GRADES:\n ENTER 9 TO VIEW MARKS:\nENTER 10 TO EXIT:\n\033[0m";

    switch (validateChoice())
    {
    case 0:
        h.teach->Timetable();
    case 1:
        h.teach->assign_grades();
        break;
    case 2:
        h.teach->assign_marks();
        break;
    case 3:
        h.teach->mark_attendance();
        break;
    case 4:
        h.teach->register_course();
        break;
    case 5:
        h.teach->viewTimetable();
        break;
    case 6:
        h.teach->view_attendance();
        break;
    case 7:
        h.teach->view_courses();
        break;
    case 8:
        h.teach->view_grades();
        break;
    case 9:
        h.teach->view_marks();
        break;
    case 10:
        break;
    default:
        cout << "\033[31mINVALID CHOICE:\n ENTER CHOICE AGAIN\n\033[0m\n";
        hodMenu(h);
        break;
    }
}
void teacherMenu(Teacher t)
{
    // system("cls");
    cout << "\033[38;2;255;255;0mENTER 1 TO MARK ATTENDENCE:\nENTER 2 TO ASSIGN MARKS:\nENTER 3 TO MARK GRADES:\nENTER 4 TO SET TIMETABLE:\nENTER 5 TO VIEW TIMETABLE:\nENTER 6 TO LOGOUT\n\033[0m";

    switch (validateChoice())
    {
    case 1:
        t.mark_attendance();
        break;
    case 2:
        t.assign_marks();
        break;
    case 3:
        t.assign_grades();
        break;
    case 4:
        t.Timetable();
        break;
    case 5:
        t.viewTimetable();
        break;
    case 6:
        break;
    default:
        cout << "\033[31mINVALID CHOICE:\n ENTER CHOICE AGAIN\n\033[0m\n";
        teacherMenu(t);
        break;
    }
}
void startMenu(Admin a, Teacher t, Student S, Hod h)
{

    // system("cls");
    cout << "\033[3;34;46mENTER 1 FOR STUDENT\033[0m\t\t\n\033[2;46;35mENTER 2 FOR TEACHER:\033[0m\t\t\n\033[3;46;35mENTER 3 FOR ADMIN:\033[0m\t\t\n\033[3;44;37mENTER 4 FOR HOD:\033[0m\t\t\n\033[3;100;37mENTER 5 TO EXIT:\033[0m\n";

    switch (validateChoice())
    {
    case 1:
        // system("cls");
        S.signIn(Slogin);
        // system("cls");
        studentMenu(S);
        startMenu(a, t, S, h);
        break;
    case 2:
        // system("cls");
        t.signIn(Tlogin);
        // system("cls");
        teacherMenu(t);
        // system("cls");
        startMenu(a, t, S, h);
        break;
    case 3:
        // system("cls");
        a.signIn(login);
        // system("cls");
        AdminMenu(a);
        // system("cls");
        startMenu(a, t, S, h);
        break;
    case 4:
        // system("cls");
        h.signIn(hlogin);
        //  system("cls");
        hodMenu(h);

        startMenu(a, t, S, h);
        break;
    case 5:
        break;
    default:
        cout << "\033[31mINVALID CHOICE: ENTER CHOICE AGAIN\033[0m\n";
        // system("cls");

        startMenu(a, t, S, h);
    }
}

