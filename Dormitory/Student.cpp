#include "Student.h"

size_t Student::getCourse() const noexcept { return this->course; }

void Student::setCourse(size_t course) noexcept { this->course = course; }

size_t Student::getRoomNumber() const noexcept { return this->room_number; }

void Student::setRoomNumber(size_t roomNumber) noexcept { this->room_number = roomNumber; }

Student::Student(const std::string &name, const std::string &surname, size_t age, size_t course, size_t roomNumber) {
    if (!isValid(name, surname, age, course, roomNumber)) {
        throw "Invalid data";
    }
    this->name = name;
    this->surname = surname;
    this->age = age;
    this->course = course;
    this->room_number = roomNumber;
}

void Student::printAllInfo() const noexcept {
    std::cout << this->name << ' ' << this->surname << ' ' << this->age << ' ' <<
              this->course << ' ' << this->room_number << '\n';
}

std::ostream &Student::operator<<(std::ostream &os) noexcept {
    os << this->getStr();
    return os;
}

std::string Student::getStr() const noexcept {
    std::stringstream stringstream;
    stringstream << getName() << ' ' << getSurname()
                 << ' ' << getAge() << ' ' << getCourse()
                 << ' ' << getRoomNumber() << '\n';
    return stringstream.str();
}

std::istream &Student::operator>>(std::istream &is) {
    this->input(is);
    return is;
}

void Student::input(std::istream &is) {
    if (&is == &std::cin) {
        std::cout << "Enter: name, surname, age, course, room number:\n";
    }
    is >> this->name >> this->surname >> this->age >> this->course >> this->room_number;
}

bool Student::isValid(std::string name, std::string surname, size_t age, size_t course, size_t room_number) {
    AValidator *validator = new StringValidator(name);
    validator->SetNext(new StringValidator(surname))
            ->SetNext(new AgeValidator(age))
            ->SetNext(new CourseValidator(course))
            ->SetNext(new RoomNumberValidator(room_number));
    return validator->Validate();
}

Student::~Student() {}
