#include "Worker.h"

Worker::Worker(const std::string &name, const std::string &surname, size_t age, const std::string &position,
               size_t salary) {
    if (!isValid(name, surname, age, position, salary)){
        throw "Invalid data";
    }
    this->name = name;
    this->surname = surname;
    this->age = age;
    this->position = position;
    this->salary = salary;
}

const std::string &Worker::getPosition() const noexcept { return this->position; }

void Worker::setPosition(const std::string &position) noexcept { this->position = position; }

size_t Worker::getSalary() const noexcept { return this->salary; }

void Worker::setSalary(size_t salary) noexcept { this->salary = salary; }

void Worker::printAllInfo() const noexcept {
    std::cout << this->name << ' ' << this->surname << ' ' << this->age << ' ' <<
              this->position << ' ' << this->salary << '\n';
}

std::ostream &Worker::operator<<(std::ostream &os) noexcept {
    os << this->getStr();
    return os;
}

std::string Worker::getStr() const noexcept {
    std::stringstream stringstream;
    stringstream << getName() << ' ' << getSurname()
                 << ' ' << getAge() << ' ' << getPosition()
                 << ' ' << getSalary() << "$\n";
    return stringstream.str();
}

std::istream &Worker::operator>>(std::istream &is) {
    this->input(is);
    return is;
}

void Worker::input(std::istream &is) {
    if (&is == &std::cin) {
        std::cout << "Enter: name, surname, age, position, salary:\n";
    }
    is >> this->name >> this->surname >> this->age >> this->position >> this->salary;
}

bool Worker::isValid(std::string name, std::string surname, size_t age, std::string position, size_t salary) {
    AValidator *validator = new StringValidator{name};
    validator->SetNext(new StringValidator(surname))
            ->SetNext(new AgeValidator(age))
            ->SetNext(new StringValidator(position))
            ->SetNext(new SalaryValidator(salary));
    return validator->Validate();
}

Worker::~Worker() noexcept {}
