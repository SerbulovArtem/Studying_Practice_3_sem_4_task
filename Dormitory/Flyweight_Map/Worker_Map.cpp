//
// Created by Admin on 12.11.2022.
//

#include "Worker_Map.h"

std::string FlyweightMap::Worker_Map::GetKey(const std::string &name, const std::string &surname) const noexcept{
    return name + " " + surname;
}

void FlyweightMap::Worker_Map::sortContainerBySalary() noexcept {
    std::cout << "\nIt is impossible to sort unordered map\n";
}

void FlyweightMap::Worker_Map::addWorker(Worker *worker) noexcept {
    auto name = worker->getName();
    auto surname = worker->getSurname();
    std::string key = this->GetKey(name, surname);
    if (this->worker_map.find(key) == this->worker_map.end()){
        this->worker_map.insert
                (std::make_pair(key, worker));
    }
    else{
        worker_map.at(key) = worker;
    }
}

void FlyweightMap::Worker_Map::getInfoFromFile(const std::filesystem::path &path) noexcept {
    std::fstream input{path, std::fstream::in};
    std::string name, surname, position;
    size_t age, salary;
    this->worker_map.clear();
    while (!input.eof()) {
        input >> name >> surname >> age >> position >> salary;
        std::string key = this->GetKey(name, surname);
        Worker *worker = new Worker(name, surname, age, position, salary);
        this->worker_map.insert
                (std::make_pair(key, worker));
    }
    input.close();
}

void FlyweightMap::Worker_Map::setInfoToFile(const std::filesystem::path &path) noexcept {
    std::fstream output{path, std::fstream::out | std::fstream::trunc};
    output.clear();
    int a = 0;
    for (auto &el: worker_map) {
        [[likely]]if (a > 0) output << std::endl;
        output << el.second->getName()
               << ' ' << el.second->getSurname()
               << ' ' << el.second->getAge()
               << ' ' << el.second->getPosition()
               << ' ' << el.second->getSalary();
        a++;
    }
    output.close();
}

void FlyweightMap::Worker_Map::operator>>(const std::filesystem::path &path) noexcept {
    this->getInfoFromFile(path);
}

void FlyweightMap::Worker_Map::operator<<(const std::filesystem::path &path) noexcept {
    this->setInfoToFile(path);
}

void FlyweightMap::Worker_Map::add() noexcept {
    std::string name, surname, position;
    size_t age, salary;
    std::cout << "Enter: name, surname, age, position, salary:\n";
    std::cin >> name >> surname >> age >> position >> salary;
    std::string key = this->GetKey(name, surname);
    Worker *worker = new Worker(name, surname, age, position, salary);
    if (this->worker_map.find(key) == this->worker_map.end()){
        this->worker_map.insert
                (std::make_pair(key, worker));
    }
    else{
        delete worker_map.at(key);
        worker_map.at(key) = new Worker(name, surname, age, position, salary);
    }
}

void FlyweightMap::Worker_Map::operator+() noexcept {
    this->add();
}

void FlyweightMap::Worker_Map::remove() {
    std::string name, surname;
    std::cout << "Enter name and surname:\n";
    std::cin >> name >> surname;
    auto iter = worker_map.find(GetKey(name, surname));
    if (iter != worker_map.end()){
        delete iter->second;
        worker_map.erase(iter);
    }
}

void FlyweightMap::Worker_Map::operator-() noexcept {
    this->remove();
}

void FlyweightMap::Worker_Map::printAllInfo() const noexcept {
    for (auto &el: worker_map) {
        el.second->printAllInfo();
    }
}

FlyweightMap::Worker_Map::~Worker_Map() {
    for (auto &el : worker_map){
        delete el.second;
    }
}