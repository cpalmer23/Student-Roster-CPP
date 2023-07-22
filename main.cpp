//
//  main.cpp
//  C867Task1
//
//  Created by Christopher Palmer on 5/5/23.

//#include "student.hpp"
#include "roster.hpp"

int main(int argc, const char * argv[]){
    
    std::cout
    << "**********************************************************************************************"
    << std::endl << std::endl
    << "Scripting and Programming - Applications - C867 in C++ by Chris Palmer (Student id: 007593243)"
    << std::endl << std::endl
    << "**********************************************************************************************"
    << std::endl << std::endl;
    
    // STUDENT DATA
    const std::string studentData[] =
    {
        "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
        "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
        "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
        "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
        "A5,Chris,Palmer,cpal146@wgu.edu,29,30,31,32,SOFTWARE"
    };
    
    // COUNT ITEMS IN STUDENT DATA
    int arrCount = 0;
    for (auto i: studentData){
        arrCount++;
    }
    
    Roster classRoster;
    
    // THE DATA PARSER (ADDS EACH STUDENT TO ROSTER)
    for (int i = 0; i < arrCount; i++){
        
        std::string studentLine = studentData[i];
        std::istringstream inSS(studentLine);
        std::string token;
        
        std::getline(inSS, token, ',');
        std::string id = token;
        
        std::getline(inSS, token, ',');
        std::string fName = token;
        
        std::getline(inSS, token, ',');
        std::string lName = token;
        
        std::getline(inSS, token, ',');
        std::string eMail = token;
        
        std::getline(inSS, token, ',');
        int age = std::stoi(token);
        
        std::getline(inSS, token, ',');
        int courseDays1 = std::stoi(token);
        
        std::getline(inSS, token, ',');
        int courseDays2 = std::stoi(token);
        
        std::getline(inSS, token, ',');
        int courseDays3 = std::stoi(token);
        
        std::getline(inSS, token, ',');
        std::string program = "NONE";
        DegreeProgram degree = NONE;
        
        if (token == "SECURITY"){
            degree = SECURITY;
        }
        if (token == "NETWORK"){
            degree = NETWORK;
        }
        if (token == "SOFTWARE"){
            degree = SOFTWARE;
        }
        
        classRoster.Add(id, fName, lName, eMail, age, courseDays1, courseDays2, courseDays3, degree);
        
    }
    
    classRoster.PrintAll();
    classRoster.PrintInvalidEmails();
    for (int i = 0; i < arrCount; i++){
        std::string student = classRoster.classRosterArray[i]->GetID();
        classRoster.PrintAverageDaysInCourse(student);
    }
    classRoster.PrintByDegreeProgram(SOFTWARE);
    classRoster.Remove("A4");
    classRoster.PrintAll();
    classRoster.Remove("A4");

    return 0;
}
