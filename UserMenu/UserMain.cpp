#include <iostream>
#include "UserMenu.h"

/*Studying_Practice_Tasks/3-4_semester/Task_1/Task_1.cpp
        Studying_Practice_Tasks/3-4_semester/Task_1/File_Management.cpp
        Studying_Practice_Tasks/3-4_semester/Task_1/Student.cpp
        Studying_Practice_Tasks/3-4_semester/Task_1/Dormitory_Management_Console.cpp
        Studying_Practice_Tasks/3-4_semester/Task_1/Worker.cpp
        Studying_Practice_Tasks/3-4_semester/Task_1/Person.cpp
        Studying_Practice_Tasks/3-4_semester/Task_1/Student_Vector.cpp
        Studying_Practice_Tasks/3-4_semester/Task_1/Worker_Vector.cpp*/

int main(){
    try {
        User_Management_Console demo;
        demo.user();
    }
    catch (int e){
        std::cout << "\n~~~~~~Default files were created~~~~~~\n"
                     "~~~~~~Please Enter information~~~~~~\n";
    }

    return 0;
}