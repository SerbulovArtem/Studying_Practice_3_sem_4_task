//
// Created by Admin on 12.11.2022.
//

#include "Flyweight_Map_Factory.h"

A_Student_Container *Flyweight_Map_Factory::GetStudentContainer() const noexcept {
    return new FlyweightMap::Student_Map;
}

A_Worker_Container *Flyweight_Map_Factory::GetWorkerContainer() const noexcept {
    return new FlyweightMap::Worker_Map;
}
