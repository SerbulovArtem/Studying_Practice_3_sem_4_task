#ifndef UNIVERSITY_PERSON_VECTOR_H
#define UNIVERSITY_PERSON_VECTOR_H

#include "../Person.h"
#include <vector>

class Person_Vector {
protected:
    std::vector<Person*> person_vector;
public:
    explicit Person_Vector() noexcept;

    virtual void printAllInfo() const noexcept;

    auto begin() const noexcept;

    auto end() const noexcept;

    friend std::ostream &operator<<(std::ostream &out, Person_Vector& person_vector);

    void addPerson() noexcept;

    void deletePerson() noexcept;

    virtual ~Person_Vector();

};


#endif //UNIVERSITY_PERSON_VECTOR_H
