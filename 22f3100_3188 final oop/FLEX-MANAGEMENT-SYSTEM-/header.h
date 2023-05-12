#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;

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
    int ID;

public:
    Student();
    void view_marks();
    void view_grades();
    void view_attendance();
    void view_courses();
    void view_feestatus();
    void operator++(int);
    void signIn(string n) override;
    virtual string getId();
};

class Teacher : public Student
{
private:
    string UserName;
    string Password;
    int ID;

public:
    Teacher();

    void signIn(string ) override;
    string getId() override;
    void mark_attendance();
    void assign_marks();
    void assign_grades();
    void operator++(int);
    void register_course();
    void Timetable();
    void viewTimetable();
};

class Hod : public Student
{
private:
    string UserName;
    string Password;

public:
    Teacher* teach;
    Hod();
    void signIn(string ) override;
    ~Hod(){}
};
class Admin : public Hod
{
private:
    string UserName;
    string Password;

public:
    Admin();
    void signIn(string );

    void addTeacher(string );

    void addStudent(string );

    void registerMe();

    void registerPassword();

    void writetofile(string );

    void viewAllTeacher(string );

    void viewAllStudents(string );

    void editTeacherDetails(string );

    void editStudentDetails(string );

    friend bool stringExistsInFile(string , string );

    ~Admin(){}
};
int validateChoice();
void startMenu(Admin , Teacher , Student , Hod );
void studentMenu(Student );
void teacherMenu(Teacher );
void hodMenu(Hod );
void AdminMenu(Admin );

