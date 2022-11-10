#ifndef UNIVERSITY_ADMINMENU_H
#define UNIVERSITY_ADMINMENU_H

#include "D:\Studying _Practice_3_sem_4_task\Dormitory\File_Management.h"
#include "D:\Studying _Practice_3_sem_4_task\Dormitory\A_Vectors\A_Student_Vector.h"
#include "D:\Studying _Practice_3_sem_4_task\Dormitory\A_Vectors\A_Worker_Vector.h"
#include "D:\Studying _Practice_3_sem_4_task\Dormitory\Factories\Vector_Factory_Provider.h"

class Admin_Management_Console : private File_Management{
private:
    size_t user_input;
    A_Student_Vector* students;
    A_Worker_Vector* workers;

public:

    explicit Admin_Management_Console() noexcept;

    void admin();

    ~Admin_Management_Console() noexcept;
};

#endif //UNIVERSITY_ADMINMENU_H
