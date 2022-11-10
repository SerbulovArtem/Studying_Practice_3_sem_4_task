
#ifndef UNIVERSITY_A_VECTOR_FACTORY_H
#define UNIVERSITY_A_VECTOR_FACTORY_H

#include "../A_Vectors/A_Student_Vector.h"
#include "../A_Vectors/A_Worker_Vector.h"


class A_Vector_Factory{
public:
    virtual A_Student_Vector* GetStudentVector() const noexcept = 0;
    virtual A_Worker_Vector* GetWorkerVector() const noexcept = 0;
};

#endif //UNIVERSITY_A_VECTOR_FACTORY_H
