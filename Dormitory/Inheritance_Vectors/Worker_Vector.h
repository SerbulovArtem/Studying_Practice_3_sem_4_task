#ifndef UNIVERSITY_WORKER_VECTOR_H
#define UNIVERSITY_WORKER_VECTOR_H

#include "Person_Vector.h"
#include "../Worker.h"
#include "D:\University\Studying_Practice_Tasks\3-4_semester\Task_1\A_Vectors\A_Worker_Vector.h"
#include <vector>

namespace InheritanceVector {

    class Worker_Vector : private Person_Vector, public A_Worker_Vector {
    public:
        explicit Worker_Vector() noexcept;

        void getInfoFromFile(const std::filesystem::path &path) noexcept override;

        void operator>>(const std::filesystem::path &path) noexcept override;

        void setInfoToFile(const std::filesystem::path &path) noexcept override;

        void operator<<(const std::filesystem::path &path) noexcept override;

        void add() noexcept override;

        void operator+() noexcept override;

        void remove() noexcept override;

        void operator-() noexcept override;

        virtual void printAllInfo() const noexcept override;

        void sortVectorBySalary() noexcept override;

        virtual ~Worker_Vector() override;

    };
}

#endif //UNIVERSITY_WORKER_VECTOR_H
