#ifndef UNIVERSITY_USERMENU_H
#define UNIVERSITY_USERMENU_H

#include "D:\Studying _Practice_3_sem_4_task\Dormitory\File_Management.h"
#include "D:\Studying _Practice_3_sem_4_task\Dormitory\A_Vectors\A_Student_Vector.h"
#include "D:\Studying _Practice_3_sem_4_task\Dormitory\A_Vectors\A_Worker_Vector.h"
#include "D:\Studying _Practice_3_sem_4_task\Dormitory\Factories\Vector_Factory_Provider.h"

class User_Management_Console : private File_Management{
private:
    size_t user_input;
    A_Student_Vector* students;
    A_Worker_Vector* workers;

public:

    explicit User_Management_Console() noexcept;

    void user();

    ~User_Management_Console() noexcept;
};


#endif //UNIVERSITY_USERMENU_H
