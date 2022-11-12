#ifndef STUDYING_PRACTICE_3_SEM_4_TASK_STUDENT_MAP_H
#define STUDYING_PRACTICE_3_SEM_4_TASK_STUDENT_MAP_H

#include "../Student.h"
#include "../A_Vectors/A_Student_Container.h"

namespace FlyweightMap {
    class Student_Map : public A_Student_Container {
    private:
        std::unordered_map<std::string, Student*> student_map;

        std::string GetKey(const std::string &name, const std::string &surname) const noexcept;

    public:
        void sortContainerByRoomNumber() noexcept override;

        void addStudent(Student *student) noexcept override;

        void getInfoFromFile(const std::filesystem::path &path) noexcept override;

        void setInfoToFile(const std::filesystem::path &path) noexcept override;

        void operator>>(const std::filesystem::path &path) noexcept override;

        void operator<<(const std::filesystem::path &path) noexcept override;

        void add() noexcept override;

        void operator+() noexcept override;

        void remove() override;

        void operator-() noexcept override;

        void printAllInfo() const noexcept override;

        virtual ~Student_Map();

    };
}

#endif //STUDYING_PRACTICE_3_SEM_4_TASK_STUDENT_MAP_H
