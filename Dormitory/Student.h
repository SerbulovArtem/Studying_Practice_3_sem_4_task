#ifndef UNIVERSITY_STUDENT_H
#define UNIVERSITY_STUDENT_H
#include "Person.h"

class Student : public Person{
private:
    bool isValid(std::string name, std::string surname, size_t age
                 , size_t course, size_t room_number);
protected:
    size_t course;
    size_t room_number;
public:

    Student(const std::string &name = "", const std::string &surname = "",size_t age = 0
            , size_t course = 0, size_t roomNumber = 0);

    size_t getCourse() const noexcept;

    void setCourse(size_t course) noexcept;

    size_t getRoomNumber() const noexcept;

    void setRoomNumber(size_t roomNumber) noexcept;

    virtual void printAllInfo() const noexcept override;

    virtual std::ostream &operator<<(std::ostream &os) noexcept override;

    virtual std::string getStr() const noexcept override ;

    virtual std::istream &operator>>(std::istream &is) override;

    virtual void input(std::istream &is) override;

    virtual ~Student() override;
};


#endif //UNIVERSITY_STUDENT_H
