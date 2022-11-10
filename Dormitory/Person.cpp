#include "Person.h"

Person::Person(std::string name, std::string surname, size_t age) noexcept
: name{name}, surname{surname}, age{age < 0 ? 0 : age} {}

const std::string &Person::getName() const noexcept { return this->name; }

void Person::setName(const std::string &name) noexcept { this->name = name; }

const std::string &Person::getSurname() const noexcept { return this->surname; }

void Person::setSurname(const std::string &surname) noexcept { this->surname = surname; }

size_t Person::getAge() const noexcept { return this->age; }

void Person::setAge(size_t age) noexcept { this->age = age; }

void Person::printAllInfo() const noexcept {
    std::cout << this->name << ' ' << this->surname << ' ' << this->age << '\n';
}

std::ostream &Person::operator<<(std::ostream &os) noexcept{
    os << this->getStr();
    return os;
}

std::string Person::getStr() const noexcept{
    std::stringstream stringstream;
    stringstream << getName() << ' ' << getSurname()
                 << ' ' << getAge()<< '\n';
    return stringstream.str();
}

std::istream &Person::operator>>(std::istream &is){
    this->input(is);
    return is;
}

void Person::input(std::istream &is){
    if (&is == &std::cin){
        std::cout << "Enter: name, surname, age:\n";
    }
    is >> this->name >> this->surname >> this->age;
}

Person::~Person() { }