#ifndef UNIVERSITY_WORKER_H
#define UNIVERSITY_WORKER_H
#include "Person.h"

class Worker : public Person{
protected:
    std::string position;
    size_t salary;
public:

    Worker(const std::string &name = "", const std::string &surname = "",size_t age = 0
            ,const std::string& position = "", size_t salary = 0) noexcept;

    const std::string &getPosition() const noexcept;

    void setPosition(const std::string &position) noexcept;

    size_t getSalary() const noexcept;

    void setSalary(size_t salary) noexcept;

    virtual void printAllInfo() const noexcept override;

    virtual std::ostream &operator<<(std::ostream &os) noexcept override;

    virtual std::string getStr() const noexcept override ;

    virtual std::istream &operator>>(std::istream &is) override;

    virtual void input(std::istream &is) override;

    virtual ~Worker() override;

};


#endif //UNIVERSITY_WORKER_H
