#include "T_Vector_Worker.h"
using namespace Template_Vector;

T_Vector_Worker::T_Vector_Worker() noexcept { }

void T_Vector_Worker::getInfoFromFile(const std::filesystem::path &path) noexcept {
    std::fstream input{path, std::fstream::in};
    std::string name, surname, position;
    size_t age, salary;
    this->vector.clear();
    while (!input.eof()) {
        input >> name >> surname >> age >> position >> salary;
        Worker worker(name, surname, age, position, salary);
        this->vector.emplace_back(worker);
    }
    input.close();
}

void T_Vector_Worker::operator>>(const std::filesystem::path &path) noexcept {
    this->getInfoFromFile(path);
}

void T_Vector_Worker::setInfoToFile(const std::filesystem::path &path) noexcept {
    std::fstream output{path, std::fstream::out | std::fstream::trunc};
    output.clear();
    int a = 0;
    for (const auto &elem: vector) {
        [[likely]]if (a > 0) output << std::endl;
        output << elem.getName()
               << ' ' << elem.getSurname()
               << ' ' << elem.getAge()
               << ' ' << elem.getPosition()
               << ' ' << elem.getSalary();
        a++;
    }
    output.close();
}

void T_Vector_Worker::operator<<(const std::filesystem::path &path) noexcept {
    this->setInfoToFile(path);
}

void T_Vector_Worker::add() noexcept {
    std::string name, surname, position;
    size_t age, salary;
    std::cout << "Enter: name, surname, age, position, salary:\n";
    std::cin >> name >> surname >> age >> position >> salary;
    Worker worker(name, surname, age, position, salary);
    this->vector.emplace_back(worker);
}

void T_Vector_Worker::operator+() noexcept {
    this->add();
}

void T_Vector_Worker::remove() noexcept {
    std::string name;
    std::cout << "Enter name:\n";
    std::cin >> name;
    auto iter = vector.begin();
    for(auto &el : vector){
        if (el.getName() == name) vector.erase(iter);
        iter++;
    }
}

void T_Vector_Worker::operator-() noexcept {
    this->remove();
}

void T_Vector_Worker::sortContainerBySalary() noexcept {
    std::ranges::sort(this->vector, [](Worker &worker1, Worker &worker2) {
        return worker1.getSalary()
               < worker2.getSalary();
    });
}

T_Vector_Worker::~T_Vector_Worker() {

}

void T_Vector_Worker::printAllInfo() const noexcept {
    T_Vector<Worker>::printAllInfo();
}

void T_Vector_Worker::addWorker(Worker *worker) noexcept {

}
