#include "Inheritance_Vector_Factory.h"

A_Student_Vector *Inheritance_Vector_Factory::GetStudentVector() const noexcept {
    return new InheritanceVector::Student_Vector;
}

A_Worker_Vector *Inheritance_Vector_Factory::GetWorkerVector() const noexcept {
    return new InheritanceVector::Worker_Vector;
}