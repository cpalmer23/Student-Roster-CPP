//
//  student.cpp
//  C867Task1
//
//  Created by Christopher Palmer on 5/5/23.
//

#include "student.hpp"

Student::Student()
{
    return;
}

Student::Student (std::string ID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysPerCourseArr[], DegreeProgram degree)
{
    this->ID = ID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < 3; i++){
        this->daysPerCourseArr[i] = daysPerCourseArr[i];
    }
    this->degreeProgram = degree;
}

// SETTERS
void Student::SetID (std::string IDToSet)
{
    ID = IDToSet;
    
}
void Student::SetFirtsName (std::string firstNameToSet)
{
    firstName = firstNameToSet;
    
}
void Student::SetLastName (std::string lastNameToSet)
{
    lastName = lastNameToSet;
    
}
void Student::SetEmailAddress (std::string emailToSet)
{
    emailAddress = emailToSet;
    
}
void Student::SetAge (int ageToSet) {
    age = ageToSet;
    
}
void Student::SetDaysInCourse(int coursesToSet[3])
{
    for (int i = 0; i < 3; i++){
        daysPerCourseArr[i] = coursesToSet[i];
    }
    
}
void Student::SetDegreeProgram(DegreeProgram degreeToSet)
{
    degreeProgram = degreeToSet;
}

// GETTERS
std::string Student::GetID() const
{
    return ID;
    
}
std::string Student::GetFirstName() const
{
    return firstName;
    
}
std::string Student::GetLastName() const
{
    return lastName;
    
}
std::string Student::GetEmailAddress() const
{
    return emailAddress;
    
}
int Student::GetAge() const
{
    return age;
    
}
int* Student::GetDaysInCourse()
{
    return this->daysPerCourseArr;
}
DegreeProgram Student::GetDegreeProgram() const
{
    return degreeProgram;
}

// PRINT
void Student::Print()
{
    std::cout
    << "      "
    << GetID()  << "    "
    << "First Name: " << GetFirstName()  << "    "
    << "Last Name: " << GetLastName()  << "    "
    << "Email Address: " << GetEmailAddress() << "    "
    << "Age: " << GetAge() << "    "
    << "Days in each Course: ";
    
    for (int i = 0; i < MAX_COURSES; i++){
        auto numCourseDays = GetDaysInCourse();
        std::cout << numCourseDays[i] << " ";
    }
    
    if (degreeProgram == SECURITY){
        std::cout << "   Degree Program: Security" << std::endl;
    }
    if (degreeProgram == NETWORK){
        std::cout << "   Degree Program: Network" << std::endl;
    }
    if (degreeProgram == SOFTWARE){
        std::cout << "   Degree Program: Software" << std::endl;
    }
    if (degreeProgram == NONE){
        std::cout << "   No Degree Program" << std::endl;
    }
    std::cout << std::endl;
}

Student::~Student(){}
