#include "T_Vector_Student.h"
using namespace Template_Vector;

T_Vector_Student::T_Vector_Student() noexcept { }

void T_Vector_Student::getInfoFromFile(const std::filesystem::path &path) noexcept {
    std::fstream input{path, std::fstream::in};
    std::string name, surname;
    size_t age, course, room_number;
    this->vector.clear();
    while (!input.eof()) {
        input >> name >> surname >> age >> course >> room_number;
        Student student(name, surname, age, course, room_number);
        this->vector.emplace_back(student);
    }
    input.close();
}

void T_Vector_Student::operator>>(const std::filesystem::path &path) noexcept {
    this->getInfoFromFile(path);
}

void T_Vector_Student::setInfoToFile(const std::filesystem::path &path) noexcept {
    std::fstream output{path, std::fstream::out | std::fstream::trunc};
    output.clear();
    int a = 0;
    for (auto &elem: vector) {
        [[likely]]if (a > 0) output << std::endl;
        output << elem.getName()
               << ' ' << elem.getSurname()
               << ' ' << elem.getAge()
               << ' ' << elem.getCourse()
               << ' ' << elem.getRoomNumber();
        a++;
    }
    output.close();
}

void T_Vector_Student::operator<<(const std::filesystem::path &path) noexcept {
    this->setInfoToFile(path);
}

void T_Vector_Student::add() noexcept {
    std::string name, surname;
    size_t age, course, room_number;
    std::cout << "Enter: name, surname, age, course, room number:\n";
    std::cin >> name >> surname >> age >> course >> room_number;
    Student student(name, surname, age, course, room_number);
    this->vector.emplace_back(student);
}

void T_Vector_Student::operator+() noexcept {
    this->add();
}

void T_Vector_Student::remove() noexcept {
    std::string name;
    std::cout << "Enter name:\n";
    std::cin >> name;
    auto iter = vector.begin();
    for (auto &el: vector) {
        if (el.getName() == name) vector.erase(iter);
        iter++;
    }
}

void T_Vector_Student::operator-() noexcept {
    this->remove();
}

void T_Vector_Student::sortContainerByRoomNumber() noexcept {
    std::ranges::sort(this->vector, [](Student &student1, Student &student2) {
        return student1.getRoomNumber()
               < student2.getRoomNumber();
    });
}

T_Vector_Student::~T_Vector_Student() { }

void T_Vector_Student::printAllInfo() const noexcept {
    T_Vector<Student>::printAllInfo();
}

void T_Vector_Student::addStudent(Student *student) noexcept {

}
