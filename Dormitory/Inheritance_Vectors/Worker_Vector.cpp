#include "Worker_Vector.h"
using namespace InheritanceVector;

Worker_Vector::Worker_Vector() noexcept {}

void Worker_Vector::getInfoFromFile(const std::filesystem::path &path) noexcept {
    std::fstream input{path, std::fstream::in};
    std::string name, surname, position;
    size_t age, salary;
    this->person_vector.clear();
    while (!input.eof()) {
        input >> name >> surname >> age >> position >> salary;
        Worker *worker = new Worker(name, surname, age, position, salary);
        this->person_vector.emplace_back(worker);
    }
    input.close();
}

void Worker_Vector::operator>>(const std::filesystem::path &path) noexcept {
    this->getInfoFromFile(path);
}

void Worker_Vector::setInfoToFile(const std::filesystem::path &path) noexcept {
    std::fstream output{path, std::fstream::out | std::fstream::trunc};
    output.clear();
    int a = 0;
    for (const auto &el: person_vector) {
        Worker* elem = dynamic_cast<Worker *>(el);
        [[likely]]if (a > 0) output << std::endl;
        output << elem->getName()
               << ' ' << elem->getSurname()
               << ' ' << elem->getAge()
               << ' ' << elem->getPosition()
               << ' ' << elem->getSalary();
        a++;
    }
    output.close();
}

void Worker_Vector::operator<<(const std::filesystem::path &path) noexcept {
    this->setInfoToFile(path);
}

void Worker_Vector::add() noexcept {
    std::string name, surname, position;
    size_t age, salary;
    std::cout << "Enter: name, surname, age, position, salary:\n";
    std::cin >> name >> surname >> age >> position >> salary;
    Worker *worker = new Worker(name, surname, age, position, salary);
    this->person_vector.emplace_back(worker);
}

void Worker_Vector::operator+() noexcept{
    this->add();
}

void Worker_Vector::remove() noexcept {
    std::string name;
    std::cout << "Enter name:\n";
    std::cin >> name;
    auto iter = person_vector.begin();
    for(auto &el : person_vector){
        if (el->getName() == name) person_vector.erase(iter);
        iter++;
    }
}

void Worker_Vector::operator-() noexcept{
    this->remove();
}

void Worker_Vector::sortVectorBySalary() noexcept {
    std::ranges::sort(this->person_vector, [](Person *&worker1, Person *&worker2) {
        return dynamic_cast<Worker *>(worker1)->getSalary()
               < dynamic_cast<Worker *>(worker2)->getSalary();
    });
}

Worker_Vector::~Worker_Vector() noexcept {}

void Worker_Vector::printAllInfo() const noexcept {
    Person_Vector::printAllInfo();
}
