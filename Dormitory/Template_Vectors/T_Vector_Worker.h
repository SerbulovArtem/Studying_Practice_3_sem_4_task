//
// Created by Admin on 26.10.2022.
//

#ifndef UNIVERSITY_T_VECTOR_WORKER_H
#define UNIVERSITY_T_VECTOR_WORKER_H

#include "../A_Vectors/A_Worker_Vector.h"
#include "../Worker.h"
#include "T_Vector.h"

namespace Template_Vector {
    class T_Vector_Worker : private T_Vector<Worker>, public A_Worker_Vector{
    public:
        explicit T_Vector_Worker() noexcept;

        void getInfoFromFile(const std::filesystem::path &path) noexcept override;

        void operator>>(const std::filesystem::path &path) noexcept override;

        void setInfoToFile(const std::filesystem::path &path) noexcept override;

        void operator<<(const std::filesystem::path &path) noexcept override;

        void add() noexcept override;

        void operator+() noexcept override;

        void remove() noexcept override;

        void operator-() noexcept override;

        void sortVectorBySalary() noexcept override;

        virtual ~T_Vector_Worker() override;

        virtual void printAllInfo() const noexcept override;
    };
}


#endif //UNIVERSITY_T_VECTOR_WORKER_H
