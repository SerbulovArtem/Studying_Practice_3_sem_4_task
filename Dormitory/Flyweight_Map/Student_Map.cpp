#include "Student_Map.h"

std::string FlyweightMap::Student_Map::GetKey(const std::string &name, const std::string &surname) const noexcept{
    return name + " " + surname;
}

void FlyweightMap::Student_Map::sortContainerByRoomNumber() noexcept {
    std::cout << "\nIt is impossible to sort unordered map\n";
}

void FlyweightMap::Student_Map::addStudent(Student *student) noexcept {
    auto name = student->getName();
    auto surname = student->getSurname();
    std::string key = this->GetKey(name, surname);
    if (this->student_map.find(key) == this->student_map.end()){
        this->student_map.insert
                (std::make_pair(key, student));
    }
    else{
        student_map.at(key) = student;
    }
}

void FlyweightMap::Student_Map::getInfoFromFile(const std::filesystem::path &path) noexcept {
    std::fstream input{path, std::fstream::in};
    std::string name, surname;
    size_t age, course, room_number;
    this->student_map.clear();
    while (!input.eof()) {
        input >> name >> surname >> age >> course >> room_number;
        std::string key = this->GetKey(name, surname);
        Student *student = new Student(name, surname, age, course, room_number);
        this->student_map.insert
        (std::make_pair(key, student));
    }
    input.close();
}

void FlyweightMap::Student_Map::setInfoToFile(const std::filesystem::path &path) noexcept {
    std::fstream output{path, std::fstream::out | std::fstream::trunc};
    output.clear();
    int a = 0;
    for (auto &el: student_map) {
        [[likely]]if (a > 0) output << std::endl;
        output << el.second->getName()
               << ' ' << el.second->getSurname()
               << ' ' << el.second->getAge()
               << ' ' << el.second->getCourse()
               << ' ' << el.second->getRoomNumber();
        a++;
    }
    output.close();
}

void FlyweightMap::Student_Map::operator>>(const std::filesystem::path &path) noexcept {
    this->getInfoFromFile(path);
}

void FlyweightMap::Student_Map::operator<<(const std::filesystem::path &path) noexcept {
    this->setInfoToFile(path);
}

void FlyweightMap::Student_Map::add() noexcept {
    std::string name, surname;
    size_t age, course, room_number;
    std::cout << "Enter: name, surname, age, course, room number:\n";
    std::cin >> name >> surname >> age >> course >> room_number;
    std::string key = this->GetKey(name, surname);
    Student *student = new Student(name, surname, age, course, room_number);
    if (this->student_map.find(key) == this->student_map.end()){
        this->student_map.insert
        (std::make_pair(key, student));
    }
    else{
        delete student_map.at(key);
        student_map.at(key) = new Student(name, surname, age, course, room_number);
    }
}

void FlyweightMap::Student_Map::operator+() noexcept {
    this->add();
}

void FlyweightMap::Student_Map::remove() {
    std::string name, surname;
    std::cout << "Enter name and surname:\n";
    std::cin >> name >> surname;
    auto iter = student_map.find(GetKey(name, surname));
    if (iter != student_map.end()){
        delete iter->second;
        student_map.erase(iter);
    }
}

void FlyweightMap::Student_Map::operator-() noexcept {
    this->remove();
}

void FlyweightMap::Student_Map::printAllInfo() const noexcept {
    for (auto &el: student_map) {
        el.second->printAllInfo();
    }
}

FlyweightMap::Student_Map::~Student_Map() {
    for (auto &el : student_map){
        delete el.second;
    }
}
