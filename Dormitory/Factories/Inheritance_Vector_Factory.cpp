#include "Inheritance_Vector_Factory.h"

A_Student_Container *Inheritance_Vector_Factory::GetStudentContainer() const noexcept {
    return new InheritanceVector::Student_Vector;
}

A_Worker_Container *Inheritance_Vector_Factory::GetWorkerContainer() const noexcept {
    return new InheritanceVector::Worker_Vector;
}