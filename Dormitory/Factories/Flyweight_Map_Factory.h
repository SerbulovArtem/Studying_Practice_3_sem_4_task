#ifndef STUDYING_PRACTICE_3_SEM_4_TASK_FLYWEIGHT_MAP_FACTORY_H
#define STUDYING_PRACTICE_3_SEM_4_TASK_FLYWEIGHT_MAP_FACTORY_H

#include "A_Container_Factory.h"
#include "../Flyweight_Map/Student_Map.h"
#include "../Flyweight_Map/Worker_Map.h"


class Flyweight_Map_Factory : public A_Container_Factory{
public:
    A_Student_Container* GetStudentContainer() const noexcept override;
    A_Worker_Container* GetWorkerContainer() const noexcept override;
};


#endif //STUDYING_PRACTICE_3_SEM_4_TASK_FLYWEIGHT_MAP_FACTORY_H
