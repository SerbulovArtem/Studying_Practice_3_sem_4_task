#include "Template_Vector_Factory.h"

A_Student_Container *Template_Vector_Factory::GetStudentContainer() const noexcept {
    return new Template_Vector::T_Vector_Student;
}

A_Worker_Container *Template_Vector_Factory::GetWorkerContainer() const noexcept {
    return new Template_Vector::T_Vector_Worker;
}
