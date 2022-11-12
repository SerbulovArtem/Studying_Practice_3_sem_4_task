
#ifndef UNIVERSITY_A_VECTOR_FACTORY_H
#define UNIVERSITY_A_VECTOR_FACTORY_H

#include "../A_Vectors/A_Student_Container.h"
#include "../A_Vectors/A_Worker_Container.h"


class A_Container_Factory{
public:
    virtual A_Student_Container* GetStudentContainer() const noexcept = 0;
    virtual A_Worker_Container* GetWorkerContainer() const noexcept = 0;
};

#endif //UNIVERSITY_A_VECTOR_FACTORY_H
