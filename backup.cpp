#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

string teach = "teacher.txt";
string login = "login.txt";
string student = "student.txt";
string hod = "hod.txt";

class User
{
private:
    string UserName;
    string Password;

public:
    virtual void signIn(string n) = 0;
};
class Student : public User
{
private:
    string UserName;
    string Password;

public:
    Student() {}
    void signIn(string n) override;
    virtual string getId();

};
class Teacher : public Student
{
private:
    string UserName;
    string Password;

public:
    Teacher() {}

    void signIn(string n) override;
    string getId() override;
    
};
class Hod : public Teacher
{
private:
    string UserName;
    string Password;
    Teacher *t;

public:
    Hod() {}
    void signIn(string n) override;
    ~Hod(){};
};

class Admin : public Hod
{
private:
    string UserName;
    string Password;
public:
    
    Admin() {}
    void signIn(string n) override;

    void addTeacher(string n);

    void addStudent(string n);

    void registerMe();

    void registerPassword();

    void writetofile(string n);

    void viewAllTeacher(string n);

    void viewAllStudents(string n);

    void editTeacherDetails(string n);

    void editStudentDetails(string n);

    friend bool stringExistsInFile(string inputString, string n);

    ~Admin(){}

    // friend class Hod;
};
void Admin::editStudentDetails(string student)
{
    string file = student;
    string tempfile = "tempfile.txt";
    string line;
    string oldstr, newstr;
    ifstream filein(file);
    ofstream fileout(tempfile);

    if (filein.is_open())
    {
        cout << "Enter the Details to be replaced: ";
        getline(cin, oldstr);
        cout << "Enter New Details: ";
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
    }
    else
    {
        cout << "ERROR";
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
string Teacher::getId(){
     ifstream inFile("t_id.txt"); 
    int ID;
    inFile >> ID;
    inFile.close();

    ID++;

    ofstream outFile("t_id.txt"); 
    outFile << ID;
    outFile.close();
    return to_string(ID);
    
    }
string Student::getId(){
     ifstream inFile("t_id.txt"); 
    int ID;
    inFile >> ID;
    inFile.close();

    ID++;

    ofstream outFile("t_id.txt"); 
    outFile << ID;
    outFile.close();
    return to_string(ID);
    
    }
void Admin::editTeacherDetails(string teach)
{
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
        cout << "ERROR";
    }
}
void Admin::viewAllTeacher(string teach)
{

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
        cout << "ERROR\n";
    }
}
void Admin::viewAllStudents(string student)
{
    
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
        cout << "ERROR\n";
    }
}
void Admin::addStudent(string n)
{

    string Fname, Lname, DepartmentName, RegistrationDate, Gender, ContactNo,

        Qualification, Address, id, bloodGroup,fee;

    cout << "\nENTER TEACHERS First NAME And Last NAME:";
    cin >> Fname >> Lname;
    cout << "\nNATER GENDER:";
    cin >> Gender;
    cout << "\nENTER REGISTRATION DATE:";
    cin >> RegistrationDate;
    cout << "\nENTER CONTACT NO;";
    cin >> ContactNo;
    cout << "\nENTER QUALIFICATION:";
    cin >> Qualification;
    cout << "\nENTER ADDRESS:";
    cin >> Address;
    cout << "\nEnter BLOOD GROUP OF STUDENT:\n";
    cin >> bloodGroup;
    cout<<"ENTER FEE STATUS Y/N:";
    cin>>fee;
    id = "22F-";
     
    id += getId();
    cout<<id;
    string input=id+","+Fname+","+Lname+","+Address+","+Gender+","+ContactNo+","+Qualification+","+RegistrationDate+","+fee+",";
    if(!stringExistsInFile(input,n)){
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
    writefile << fee + ","<<endl;

    writefile.close();
    }
    else{
        cout << "This data already exists in the file. Enter different Data: ";
        addStudent(n);
    }
}

void Admin::addTeacher(string n)
{

    string Fname, Lname, DepartmentName, RegistrationDate, Gender, ContactNo,

        Qualification, Address, id;

    cout << "\nENTER TEACHERS First NAME And Last NAME:";
    cin >> Fname >> Lname;
    cout << "\nNATER GENDER:";
    cin >> Gender;
    cout << "\nENTER REGISTRATION DATE:";
    cin >> RegistrationDate;
    cout << "\nENTER CONTACT NO;";
    cin >> ContactNo;
    cout << "\nENTER QUALIFICATION:";
    cin >> Qualification;
    cout << "\nENTER ADDRESS:";
    cin >> Address;
    
    id = "22T-";
    id+=getId();

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

    cin.ignore();
    cout << "\x1B[36mPlease enter your UserName:\033[0m\t\t\n" << endl;
    getline(cin, this->UserName);

    cout << "\x1B[36mPlease enter your Password:\033[0m\t\t\n " << endl;
    getline(cin, this->Password);

    if (!validateLogin(n, UserName, Password)) // checks the information in file
    {
        cout << "\x1B[36mINVALID CREDENTIALS:\033[0m\t\t\n" << endl;
        cin.ignore();
        signIn(login);
    }

    else
    {
        cout << "LOGIN SUCCESSFULL" << endl;
        cout << "WELCOME " << UserName << endl;
    }
}
void Hod::signIn(string n)
{

    cin.ignore();
    cout << "Please enter your UserName: " << endl;
    getline(cin, this->UserName);

    cout << "Please enter your Password: " << endl;
    getline(cin, this->Password);

    if (!validateLogin(n, UserName, Password)) // checks the information in file
    {
        cout << "INVALID CREDENTIALS" << endl;
        cin.ignore();
        signIn(login);
    }
    else
    {
        cout << "LOGIN SUCCESSFULL" << endl;
        cout << "WELCOME " << UserName << endl;
    }
}
void Teacher::signIn(string n)
{

    cin.ignore();
    cout << "Please enter your UserName: " << endl;
    getline(cin, this->UserName);

    cout << "Please enter your Password: " << endl;
    getline(cin, this->Password);

    if (!validateLogin(n, UserName, Password)) // checks the information in file
    {
        cout << "INVALID CREDENTIALS" << endl;
        cin.ignore();
        signIn(login);
    }

    else
    {
        cout << "LOGIN SUCCESSFULL" << endl;
        cout << "WELCOME " << UserName << endl;
    }
}
void Student::signIn(string n)
{

    cin.ignore();
    cout << "Please enter your UserName: " << endl;
    getline(cin, this->UserName);

    cout << "Please enter your Password: " << endl;
    getline(cin, this->Password);

    if (!validateLogin(n, UserName, Password)) // checks the information in file
    {
        cout << "INVALID CREDENTIALS" << endl;
        cin.ignore();
        signIn(login);
    }

    else
    {
        cout << "LOGIN SUCCESSFULL" << endl;
        cout << "WELCOME " << UserName << endl;
    }
}
int validateChoice()
{
    try
    {
        int choice;
        cin >> choice;
        if (cin.fail())
        {
            throw "Invalid input. Please enter a number.";
        }
        if (choice < 0)
        {
            throw "INVALID INPUT";
        }
        return choice;
    }
    catch (const char *msg)
    {
        cerr << "Error: " << msg << endl;
        cin.clear();
        cin.ignore();
        validateChoice();
    }
}
void AdminMenu(Admin a)
{
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
        break;
        AdminMenu(a);
    case 7:
       break;
    default:
        system("clear");
        cout << "\033[3;41;30INVALID CHOICE: ENTER CHOICE AGAIN\033[0m\t\t"<< endl;;
        AdminMenu(a);
    }
}
void startMenu(Admin a, Teacher t, Student S, Hod h)
{
    cout << "\033[3;43;30mENTER 1 FOR STUDENT\033[0m\t\t\n\033[2;47;35mENTER 2 FOR TEACHER:\033[0m\t\t\n\033[3;47;35mENTER 3 FOR ADMIN:\033[0m\t\t\n\033[3;42;30mENTER 4 FOR HOD:\033[0m\t\t\n\033[3;100;30mENTER 5 TO EXIT:\033[0m\n";

    switch (validateChoice())
    {
    case 1:
        S.signIn(login);
        startMenu(a, t, S, h);
        break;
    case 2:
        t.signIn(login);
        startMenu(a, t, S, h);
        break;
    case 3:
        a.signIn(login);
        AdminMenu(a);
        startMenu(a, t, S, h);
        break;
    case 4:
        h.signIn(login);
        startMenu(a, t, S, h);
        break;
    case 5:
        break;    
    default:
        system("clear");
        cout << "INVALID CHOICE: ENTER CHOICE AGAIN\n";
        startMenu(a, t, S, h);
    }
}

int main()
{

    Admin ad;
    Teacher t;
    Student S;
    Hod h;
     
    /*cout<<"\033[3;42;30mTexting\033[0m\t\t"<< endl;
    cout<<"\033[3;43;30mTexting\033[0m\t\t"<< endl;
    cout<<"\033[3;44;30mTexting\033[0m\t\t"<< endl;
    cout<<"\033[3;104;30mTexting\033[0m\t\t"<< endl;
    cout<<"\033[3;100;30mTexting\033[0m\n"<< endl;

    cout<<"\033[3;47;35mTexting\033[0m\t\t"<< endl;
    cout<<"\033[2;47;35mTexting\033[0m\t\t"<< endl;
    cout<<"\033[1;47;35mTexting\033[0m\t\t"<< endl;*/
    startMenu(ad, t, S, h);
    
/////colorsss//////
    // cout << "\x1B[31mTexting\033[0m\t\t" << endl;
    // cout<<"\x1B[36mTexting\033[0m\t\t"<< endl;
    // cout<<"\x1B[36mTexting\033[0m\t\t"<< endl;
    // cout<<"\x1B[36mTexting\033[0m\t\t"<< endl;
    // cout<<"\x1B[37mTexting\033[0m\t\t"<< endl;
    // cout<<"\x1B[93mTexting\033[0m\n"<< endl;
   ///////
 
    cout<<"\033[3;41;30mTexting\033[0m\t\t"<< endl;
    cout<<"\033[3;42;30mTexting\033[0m\t\t"<< endl;
    cout<<"\033[3;43;30mTexting\033[0m\t\t"<< endl;
    cout<<"\033[3;44;30mTexting\033[0m\t\t"<< endl;
    cout<<"\033[3;104;30mTexting\033[0m\t\t"<< endl;
    cout<<"\033[3;100;30mTexting\033[0m\n"<< endl;

    cout<<"\033[3;47;35mTexting\033[0m\t\t"<< endl;
    cout<<"\033[2;47;35mTexting\033[0m\t\t"<< endl;
    cout<<"\033[1;47;35mTexting\033[0m\t\t"<< endl;

    // User* student=&S;
    // User* teacher=&t;
    // User* hod=&h;
    // a->signIn(login);
    // a.signIn(login);
    // t.signIn(login);
    // a.addTeacher(teach);
    //*/
}