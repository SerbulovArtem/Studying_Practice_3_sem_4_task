#ifndef UNIVERSITY_TEMPLATE_VECTOR_FACTORY_H
#define UNIVERSITY_TEMPLATE_VECTOR_FACTORY_H

#include "A_Vector_Factory.h"
#include "D:\University\Studying_Practice_Tasks\3-4_semester\Task_1\Template_Vectors\T_Vector_Student.h"
#include "D:\University\Studying_Practice_Tasks\3-4_semester\Task_1\Template_Vectors\T_Vector_Worker.h"

class Template_Vector_Factory : public A_Vector_Factory{
public:
    A_Student_Vector* GetStudentVector() const noexcept override;
    A_Worker_Vector* GetWorkerVector() const noexcept override;
};


#endif //UNIVERSITY_TEMPLATE_VECTOR_FACTORY_H
