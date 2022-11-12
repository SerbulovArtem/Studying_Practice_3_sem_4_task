#ifndef UNIVERSITY_PERSON_H
#define UNIVERSITY_PERSON_H
#include <iostream>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <ranges>
#include <sstream>
#include <unordered_map>
#include <memory>
#include "Validators/Validator.h"

class Person {
private:
    bool isValid(std::string name, std::string surname, size_t age);
protected:
    std::string name;
    std::string surname;
    size_t age;
public:
    Person(std::string name = "", std::string surname = "", size_t age = 0);

    const std::string &getName() const noexcept;

    void setName(const std::string &name) noexcept;

    const std::string &getSurname() const noexcept;

    void setSurname(const std::string &surname) noexcept;

    size_t getAge() const noexcept;

    void setAge(size_t age) noexcept;

    virtual void printAllInfo() const noexcept;

    virtual std::ostream &operator<<(std::ostream &os) noexcept;

    virtual std::string getStr() const noexcept;

    virtual std::istream &operator>>(std::istream &is);

    virtual void input(std::istream &is);

    virtual ~Person();
};


#endif //UNIVERSITY_PERSON_H
