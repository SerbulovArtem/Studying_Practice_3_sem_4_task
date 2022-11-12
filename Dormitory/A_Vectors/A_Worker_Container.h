#ifndef UNIVERSITY_A_WORKER_VECTOR_H
#define UNIVERSITY_A_WORKER_VECTOR_H

#include "..\Worker.h"
#include "A_Container.h"

class A_Worker_Container : public A_Container
{
public:
    virtual void sortContainerBySalary() noexcept = 0;

    virtual void addWorker(Worker* worker) noexcept = 0;

    virtual ~A_Worker_Container() noexcept { }
};

#endif //UNIVERSITY_A_WORKER_VECTOR_H
