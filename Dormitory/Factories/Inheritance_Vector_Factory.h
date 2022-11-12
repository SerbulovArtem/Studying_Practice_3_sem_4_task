#ifndef UNIVERSITY_INHERITANCE_VECTOR_FACTORY_H
#define UNIVERSITY_INHERITANCE_VECTOR_FACTORY_H

#include "A_Container_Factory.h"
#include "../Inheritance_Vectors/Worker_Vector.h"
#include "../Inheritance_Vectors/Student_Vector.h"

class Inheritance_Vector_Factory : public A_Container_Factory{
public:
    A_Student_Container* GetStudentContainer() const noexcept override;
    A_Worker_Container* GetWorkerContainer() const noexcept override;
};

#endif //UNIVERSITY_INHERITANCE_VECTOR_FACTORY_H
