//
//  student.hpp
//  C867Task1
//
//  Created by Christopher Palmer on 5/5/23.
//
#include "degree.hpp"

#ifndef student_hpp
#define student_hpp

class Student {
public:
    // DEFAULT CONSTRUCTOR
    Student();
    
    // OVERLOADED CONSTRUCTOR
    Student (std::string ID, std::string firstName, std::string lastName, std::string emailAddress, int age, int daysPerCourseArr[], DegreeProgram degree);
    
    // SETTERS
    void SetID (std::string IDToSet);
    void SetFirtsName (std::string firstNameToSet);
    void SetLastName (std::string lastNameToSet);
    void SetEmailAddress (std::string emailToSet);
    void SetAge (int ageToSet);
    void SetDaysInCourse (int coursesToSet[3]);
    void SetDegreeProgram(DegreeProgram degreeToSet);
    
    // GETTERS
    std::string GetID() const;
    std::string GetFirstName() const;
    std::string GetLastName() const;
    std::string GetEmailAddress() const;
    int GetAge() const;
    int* GetDaysInCourse();
    DegreeProgram GetDegreeProgram() const;
    
    // PRINT FUNCTION
    void Print();
    
    ~Student();
    
private:
    std::string ID;
    std::string firstName;
    std::string lastName;
    std::string emailAddress;
    int age;
    static const int MAX_COURSES = 3;
    int daysPerCourseArr[MAX_COURSES];
    DegreeProgram degreeProgram;
};

#endif /* student_hpp */
