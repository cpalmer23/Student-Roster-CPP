//
//  roster.cpp
//  C867Task1
//
//  Created by Christopher Palmer on 5/5/23.
//

#include "roster.hpp"

Roster::Roster()
{
    return;
}
void Roster::Add(std::string studentID, std::string sFirstName, std::string sLastName, std::string sEmailAddress, int sAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram)
{
    const int NUM_ELEMENTS = 3;
    int courseDaysToAdd[NUM_ELEMENTS] = {daysInCourse1, daysInCourse2, daysInCourse3};
    
    classRosterArray[++index] = new Student(studentID, sFirstName, sLastName, sEmailAddress, sAge, courseDaysToAdd, degreeProgram);
}
void Roster::PrintAll()
{
    std::cout << "--->> Printing Student Roster <<---"
    << std::endl
    << std::endl;
    for (int i = 0; i < MAX_STUDENTS; i++){
        classRosterArray[i]->Print();
    }
}
void Roster::Remove(std::string studentID)
{
    std::cout << "--->> Removing student with ID: " << studentID << " <<---" << std::endl
    << std::endl;
    bool found = false;
    
    for (int i = 0; i < MAX_STUDENTS; i++){
        std::string matchId = classRosterArray[i]->GetID();
            if (matchId == studentID){
                found = true;
                std::cout
                << "      ..."
                << classRosterArray[i]->GetFirstName() << " "
                << classRosterArray[i]->GetLastName() << " "
                << "removed from roster" << std::endl
                << std::endl;
                delete classRosterArray[i];
                classRosterArray[i] = new Student;
            }
    }
    if (found == false){
        std::cout << "      ...student not found" << std::endl;
    }
}
void Roster::PrintAverageDaysInCourse(std::string studentID)
{
    std::cout << "--->> Averaging days per course for student with ID: " << studentID << " <<---"
    << std::endl
    << std::endl;
    int totalDays = 0;
    int averegeDays = 0;
    
    for (int i = 0; i < MAX_STUDENTS; i++){
        std::string currStudent = classRosterArray[i]->GetID();
        if (currStudent == studentID){
            for (int j = 0; j < 3; j++){
                auto currCourseDays = classRosterArray[i]->GetDaysInCourse();
                totalDays += currCourseDays[j];
            }
            averegeDays = (totalDays / 3);
            if (averegeDays){
                std::cout
                << "      Average days for "
                << classRosterArray[i]->GetFirstName() << " "<< classRosterArray[i]->GetLastName() << ": "
                << averegeDays << std::endl;
            }
            if (!averegeDays){
                std::cout
                << "     "
                << classRosterArray[i]->GetFirstName() << " "<< classRosterArray[i]->GetLastName()
                << "...no data"
                << std::endl;
            }
        }
        totalDays = 0;
    }
    std::cout << std::endl;
}
void Roster::PrintInvalidEmails()
{
    std::cout << "--->> Checking for invalid emails <<---"
    << std::endl
    << std::endl;
    
    for (int i = 0; i < MAX_STUDENTS; i++){
        std::string currEmail = classRosterArray[i]->GetEmailAddress();
        char* currLetter = new char[currEmail.length()];
        int At = -1, Dot = -1, Spc = 0;
        
        for (int j = 0; j < currEmail.length(); j++){
            currLetter[j] = currEmail[j];
            if (currLetter[j] == '@') {
                At = j;
            }
            if (currLetter[j] == '.') {
                Dot = j;
            }
            if (currLetter[j] == ' ') {
                Spc -= 1;
            }
        }
        delete[] currLetter;
        if (At == -1 || Dot == -1 || Spc < 0){
            std::cout << "      Invalid Email: "
            << classRosterArray[i]->GetEmailAddress() << " "
            << "(Student ID: " << classRosterArray[i]->GetID() << ")"
            << std::endl;
        }
        else if (At > Dot){
            std::cout << "      Invalid Email: "
            << classRosterArray[i]->GetEmailAddress() << " "
            << "(Student ID: " << classRosterArray[i]->GetID() << ")"
            << std::endl;
        }
    }
    std::cout << std::endl;
}
void Roster::PrintByDegreeProgram(DegreeProgram degree)
{
    std::string specifiedDegree;
    
    if (degree == SECURITY){
        specifiedDegree = "Security";
    }
    if (degree == NETWORK){
        specifiedDegree = "Network";
    }
    if (degree == SOFTWARE){
        specifiedDegree = "Software";
    }
    
    std::cout << "--->> Getting students with degree program: " << specifiedDegree << " <<---"
    << std::endl
    << std::endl;

    for (int i = 0; i < MAX_STUDENTS; i++) {
        DegreeProgram currProgram = classRosterArray[i]->GetDegreeProgram();
        if (currProgram == degree){
            classRosterArray[i]->Print();
        }
    }
}
Roster::~Roster()
{    
    for ( int i = 0; i < MAX_STUDENTS; i++){
        delete classRosterArray[i];
    }
    
}
