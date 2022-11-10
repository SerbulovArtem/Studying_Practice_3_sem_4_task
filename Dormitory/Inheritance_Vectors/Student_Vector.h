#ifndef UNIVERSITY_STUDENT_VECTOR_H
#define UNIVERSITY_STUDENT_VECTOR_H

#include "../Student.h"
#include "Person_Vector.h"
#include "../A_Vectors/A_Student_Vector.h"
#include <vector>

namespace InheritanceVector {

    class Student_Vector : private Person_Vector, public A_Student_Vector {
    public:
        explicit Student_Vector() noexcept;

        void getInfoFromFile(const std::filesystem::path &path) noexcept override;

        void operator>>(const std::filesystem::path &path) noexcept override;

        void setInfoToFile(const std::filesystem::path &path) noexcept override;

        void operator<<(const std::filesystem::path &path) noexcept override;

        void add() noexcept override;

        void operator+() noexcept override;

        void remove() noexcept override;

        void operator-() noexcept override;

        virtual void printAllInfo() const noexcept override;

        void sortVectorByRoomNumber() noexcept override;

        virtual ~Student_Vector() override;
    };
}

#endif //UNIVERSITY_STUDENT_VECTOR_H
