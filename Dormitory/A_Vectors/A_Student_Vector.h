#ifndef UNIVERSITY_A_STUDENT_VECTOR_H
#define UNIVERSITY_A_STUDENT_VECTOR_H

#include "..\Student.h"
#include "A_TVector.h"

class A_Student_Vector : public A_TVector
{
public:
    virtual void sortVectorByRoomNumber() noexcept = 0;

    virtual ~A_Student_Vector() noexcept { }
};

#endif //UNIVERSITY_A_STUDENT_VECTOR_H
