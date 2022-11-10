//
// Created by Admin on 26.10.2022.
//

#ifndef UNIVERSITY_T_VECTOR_STUDENT_H
#define UNIVERSITY_T_VECTOR_STUDENT_H

#include "D:\University\Studying_Practice_Tasks\3-4_semester\Task_1\A_Vectors\A_Student_Vector.h"
#include "../Student.h"
#include "T_Vector.h"

namespace Template_Vector {
    class T_Vector_Student : private T_Vector<Student>, public A_Student_Vector{
    public:
        explicit T_Vector_Student() noexcept;

        void getInfoFromFile(const std::filesystem::path &path) noexcept override;

        void operator>>(const std::filesystem::path &path) noexcept override;

        void setInfoToFile(const std::filesystem::path &path) noexcept override;

        void operator<<(const std::filesystem::path &path) noexcept override;

        void add() noexcept override;

        void operator+() noexcept override;

        void remove() noexcept override;

        void operator-() noexcept override;

        void sortVectorByRoomNumber() noexcept override;

        virtual ~T_Vector_Student() override;

        virtual void printAllInfo() const noexcept override;
    };
}

#endif //UNIVERSITY_T_VECTOR_STUDENT_H
