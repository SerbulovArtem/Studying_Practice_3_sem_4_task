#include "Student_Vector.h"
using namespace InheritanceVector;

Student_Vector::Student_Vector() noexcept {}

void Student_Vector::getInfoFromFile(const std::filesystem::path &path) noexcept {
    std::fstream input{path, std::fstream::in};
    std::string name, surname;
    size_t age, course, room_number;
    this->person_vector.clear();
    while (!input.eof()) {
        input >> name >> surname >> age >> course >> room_number;
        Student *student = new Student(name, surname, age, course, room_number);
        this->person_vector.emplace_back(student);
    }
    input.close();
}

void Student_Vector::operator>>(const std::filesystem::path &path) noexcept {
    this->getInfoFromFile(path);
}

void Student_Vector::setInfoToFile(const std::filesystem::path &path) noexcept {
    std::fstream output{path, std::fstream::out | std::fstream::trunc};
    output.clear();
    int a = 0;
    for (auto &el: person_vector) {
        Student *elem = dynamic_cast<Student *>(el);
        [[likely]]if (a > 0) output << std::endl;
        output << elem->getName()
               << ' ' << elem->getSurname()
               << ' ' << elem->getAge()
               << ' ' << elem->getCourse()
               << ' ' << elem->getRoomNumber();
        a++;
    }
    output.close();
}

void Student_Vector::operator<<(const std::filesystem::path &path) noexcept {
    this->setInfoToFile(path);
}

void Student_Vector::add() noexcept {
    std::string name, surname;
    size_t age, course, room_number;
    std::cout << "Enter: name, surname, age, course, room number:\n";
    std::cin >> name >> surname >> age >> course >> room_number;
    Student *student = new Student(name, surname, age, course, room_number);
    this->person_vector.emplace_back(student);
}

void Student_Vector::operator+() noexcept {
    this->add();
}

void Student_Vector::remove() noexcept {
    std::string name;
    std::cout << "Enter name:\n";
    std::cin >> name;
    auto iter = person_vector.begin();
    for (auto &el: person_vector) {
        if (el->getName() == name) person_vector.erase(iter);
        iter++;
    }
}

void Student_Vector::operator-() noexcept {
    this->remove();
}

void Student_Vector::printAllInfo() const noexcept {
    Person_Vector::printAllInfo();
}

void Student_Vector::sortVectorByRoomNumber() noexcept {
    std::ranges::sort(this->person_vector, [](Person *&student1, Person *&student2) {
        return dynamic_cast<Student *>(student1)->getRoomNumber()
               < dynamic_cast<Student *>(student2)->getRoomNumber();
    });
}

Student_Vector::~Student_Vector() noexcept {}
