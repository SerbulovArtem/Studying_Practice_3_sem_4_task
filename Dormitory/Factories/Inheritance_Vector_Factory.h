#ifndef UNIVERSITY_INHERITANCE_VECTOR_FACTORY_H
#define UNIVERSITY_INHERITANCE_VECTOR_FACTORY_H

#include "A_Vector_Factory.h"
#include "../Inheritance_Vectors/Worker_Vector.h"
#include "../Inheritance_Vectors/Student_Vector.h"

class Inheritance_Vector_Factory : public A_Vector_Factory{
public:
    A_Student_Vector* GetStudentVector() const noexcept override;
    A_Worker_Vector* GetWorkerVector() const noexcept override;
};

#endif //UNIVERSITY_INHERITANCE_VECTOR_FACTORY_H
