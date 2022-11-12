#include "Person_Vector.h"

Person_Vector::Person_Vector() noexcept {}

void Person_Vector::printAllInfo() const noexcept {
    for (auto &el: person_vector) {
        el->printAllInfo();
    }
}

auto Person_Vector::begin() const noexcept {
    return person_vector.begin();
}

auto Person_Vector::end() const noexcept {
    return person_vector.end();
}

std::ostream &operator<<(std::ostream &out, Person_Vector &person_vector) {
    for (auto &person : person_vector) {
        out << person->getStr();
    }
    return out;
}

void Person_Vector::addPerson() noexcept {
    std::string name, surname;
    size_t age;
    std::cout << "Enter: name, surname, age:\n";
    std::cin >> name >> surname >> age;
    Person *person = new Person(name, surname, age);
    this->person_vector.emplace_back(person);
}

void Person_Vector::deletePerson() noexcept {
    std::string name;
    std::cout << "Enter name:\n";
    std::cin >> name;
    auto iter = person_vector.begin();
    for(auto &el : person_vector){
        if (el->getName() == name) person_vector.erase(iter);
        iter++;
    }
}

Person_Vector::~Person_Vector() {
    for (auto &el : person_vector){
        delete el;
    }
}
