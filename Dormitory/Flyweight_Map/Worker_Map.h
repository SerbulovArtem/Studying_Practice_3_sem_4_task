#ifndef STUDYING_PRACTICE_3_SEM_4_TASK_WORKER_MAP_H
#define STUDYING_PRACTICE_3_SEM_4_TASK_WORKER_MAP_H

#include "../Worker.h"
#include "../A_Vectors/A_Worker_Container.h"

namespace FlyweightMap {
    class Worker_Map : public A_Worker_Container{
    private:
        std::unordered_map<std::string, Worker*> worker_map;

        std::string GetKey(const std::string &name, const std::string &surname) const noexcept;

    public:

        void getInfoFromFile(const std::filesystem::path &path) noexcept override;

        void setInfoToFile(const std::filesystem::path &path) noexcept override;

        void operator>>(const std::filesystem::path &path) noexcept override;

        void operator<<(const std::filesystem::path &path) noexcept override;

        void add() noexcept override;

        void operator+() noexcept override;

        void remove() override;

        void operator-() noexcept override;

        void printAllInfo() const noexcept override;

        void sortContainerBySalary() noexcept override;

        void addWorker(Worker *worker) noexcept override;

        virtual ~Worker_Map();
    };
}

#endif //STUDYING_PRACTICE_3_SEM_4_TASK_WORKER_MAP_H
