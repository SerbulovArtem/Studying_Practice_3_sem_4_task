#ifndef UNIVERSITY_A_TVECTOR_H
#define UNIVERSITY_A_TVECTOR_H

#include <iostream>
#include <filesystem>
#include <vector>

class A_Container{
public:
    virtual void getInfoFromFile(const std::filesystem::path &path) noexcept = 0;

    virtual void setInfoToFile(const std::filesystem::path &path) noexcept = 0;

    virtual void operator>>(const std::filesystem::path &path) noexcept = 0;

    virtual void operator<<(const std::filesystem::path &path) noexcept = 0;

    virtual void add() noexcept = 0;

    virtual void operator+() noexcept = 0;

    virtual void remove() = 0;

    virtual void operator-() noexcept = 0;

    virtual void printAllInfo() const noexcept = 0;
};

#endif //UNIVERSITY_A_TVECTOR_H
