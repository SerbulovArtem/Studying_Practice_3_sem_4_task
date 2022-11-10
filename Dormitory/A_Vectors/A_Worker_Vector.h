#ifndef UNIVERSITY_A_WORKER_VECTOR_H
#define UNIVERSITY_A_WORKER_VECTOR_H

#include "..\Worker.h"
#include "A_TVector.h"

class A_Worker_Vector : public A_TVector
{
public:
    virtual void sortVectorBySalary() noexcept = 0;

    virtual ~A_Worker_Vector() noexcept { }
};

#endif //UNIVERSITY_A_WORKER_VECTOR_H
