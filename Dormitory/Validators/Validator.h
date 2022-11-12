#ifndef STUDYING_PRACTICE_3_SEM_4_TASK_VALIDATOR_H
#define STUDYING_PRACTICE_3_SEM_4_TASK_VALIDATOR_H

class AValidator{
public:
    virtual AValidator* SetNext(AValidator*) = 0;
    virtual bool Validate() = 0;
};

class BaseValidator : public AValidator{
private:
    AValidator* next;
public:
    BaseValidator(){
        next = nullptr;
    }

    AValidator* SetNext(AValidator* next) override{
        this->next = next;
        return next;
    }

    bool Validate() override{
        if (next != nullptr)
            return next->Validate();
        return true;
    }
};

class StringValidator : public BaseValidator{
private:
    std::string string;
public:
    StringValidator(std::string string){
        this->string = string;
    }

    bool Validate() override{
        if (string.size() > 20){
            return false;
        }

        return BaseValidator::Validate();
    }
};

class AgeValidator : public BaseValidator{
private:
    size_t age;
public:
    AgeValidator(size_t age){
        this->age = age;
    }

    bool Validate() override{
        if (age < 0 || age > 125){
            return false;
        }

        return BaseValidator::Validate();
    }
};

class CourseValidator : public BaseValidator{
private:
    size_t course;
public:
    CourseValidator(size_t course){
        this->course = course;
    }

    bool Validate() override{
        if (course < 1 || course > 7){
            return false;
        }

        return BaseValidator::Validate();
    }
};

class RoomNumberValidator : public BaseValidator{
private:
    size_t roomnumber;
public:
    RoomNumberValidator(size_t roomnumber){
        this->roomnumber = roomnumber;
    }

    bool Validate() override{
        if (roomnumber < 0 || roomnumber > 500){
            return false;
        }

        return BaseValidator::Validate();
    }
};

class SalaryValidator : public BaseValidator{
private:
    size_t salary;
public:
    SalaryValidator(size_t salary){
        this->salary = salary;
    }

    bool Validate() override{
        if (salary < 0 || salary > 10000){
            return false;
        }

        return BaseValidator::Validate();
    }
};

#endif //STUDYING_PRACTICE_3_SEM_4_TASK_VALIDATOR_H
