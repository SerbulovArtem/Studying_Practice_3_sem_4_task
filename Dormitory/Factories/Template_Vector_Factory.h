#ifndef UNIVERSITY_TEMPLATE_VECTOR_FACTORY_H
#define UNIVERSITY_TEMPLATE_VECTOR_FACTORY_H

#include "A_Container_Factory.h"
#include "../Template_Vectors/T_Vector_Student.h"
#include "../Template_Vectors/T_Vector_Worker.h"

class Template_Vector_Factory : public A_Container_Factory{
public:
    A_Student_Container* GetStudentContainer() const noexcept override;
    A_Worker_Container* GetWorkerContainer() const noexcept override;
};


#endif //UNIVERSITY_TEMPLATE_VECTOR_FACTORY_H
