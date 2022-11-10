#include "Template_Vector_Factory.h"

A_Student_Vector *Template_Vector_Factory::GetStudentVector() const noexcept {
    return new Template_Vector::T_Vector_Student;
}

A_Worker_Vector *Template_Vector_Factory::GetWorkerVector() const noexcept {
    return new Template_Vector::T_Vector_Worker;
}
