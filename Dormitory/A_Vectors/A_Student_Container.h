#ifndef UNIVERSITY_A_STUDENT_VECTOR_H
#define UNIVERSITY_A_STUDENT_VECTOR_H

#include "..\Student.h"
#include "A_Container.h"

class A_Student_Container : public A_Container
{
public:
    virtual void sortContainerByRoomNumber() noexcept = 0;

    virtual void addStudent(Student* student) noexcept = 0;

    virtual ~A_Student_Container() noexcept { }
};

#endif //UNIVERSITY_A_STUDENT_VECTOR_H
