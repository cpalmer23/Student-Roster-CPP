//
//  roster.hpp
//  C867Task1
//
//  Created by Christopher Palmer on 5/5/23.
//
#include "student.hpp"

#ifndef roster_hpp
#define roster_hpp

class Roster{
public:
    // DEFAULT CONSTRUCTOR
    Roster();
    
    // ADDS STUDENT OBJECT (POINTER) TO CLASS ROSTER ARRAY
    void Add(std::string studentID, std::string sFirstName, std::string sLastNameName, std::string sEmailAddress, int sAge, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    
    // REMOVES STUDENT BY ID
    void Remove(std::string studentID);
    
    // PRINTS ALL STUDENTS IN CLASS ROSTER
    void PrintAll();
    
    // PRINTS AVERAGE DAYS IN 3 COURSES OF A STUDENT
    void PrintAverageDaysInCourse(std::string studentID);
    
    // CHECKS FOR INVALID EMAILS AND PRINTS THEM
    // VALID HAS (@), (.), AND NO (" ")
    void PrintInvalidEmails();
    
    // PRINTS STUDENTS WITH GIVEN ENUM TYPE
    void PrintByDegreeProgram(DegreeProgram degree);
    
    // THE INDEXER
    int index = -1;
    
    // THE CLASS ROSTER
    static const int MAX_STUDENTS = 5;
    Student* classRosterArray[MAX_STUDENTS];
    
    // DECONSTRUCTOR
    ~Roster();
    
private:

    Student student;

};

#endif /* roster_hpp */
