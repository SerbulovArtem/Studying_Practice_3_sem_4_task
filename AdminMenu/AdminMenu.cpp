#include "AdminMenu.h"

Admin_Management_Console::Admin_Management_Console() noexcept : user_input{0} {
    Vector_Factory_Provider factoryProvider;
    A_Vector_Factory* vectorFactory = factoryProvider.GetVectorFactory();

    this->students = vectorFactory->GetStudentVector();
    this->workers = vectorFactory->GetWorkerVector();

    *this->students >> this->input_output_file_student;
    *this->workers >> this->input_output_file_worker;
};

void Admin_Management_Console::admin() {
    std::cout << "~~~~~~Management menu successfully invoked~~~~~~\n";
    do{
        std::cout << "Options:\n"
                     "0: Exit from the program\n"
                     "1: Print All students and workers on terminal\n"
                     "2: Add new student\n"
                     "3: Add new worker\n"
                     "4: Delete student by name\n"
                     "5: Delete worker by name\n"
                     "6: Sort student vector by room number\n"
                     "7: Sort worker vector by salary\n";
        do {
            std::cout << "Enter number from 0-9:";
            std::cin >> this->user_input;
        } while(this->user_input < 0 || this->user_input > 9);

        switch (this->user_input) {
            case (1):
                *this->students >> this->input_output_file_student;
                *this->workers >> this->input_output_file_worker;
                std::cout << "\nStudents:\n";
                //std::cout << this->students;
                this->students->printAllInfo();
                std::cout << "\nWorkers:\n";
                //std::cout << this->workers;
                this->workers->printAllInfo();
                break;
            case (2):
                +*this->students;
                *this->students << this->input_output_file_student;
                break;
            case (3):
                +*this->workers;
                *this->workers << this->input_output_file_worker;
                break;
            case (4):
                -*this->students;
                *this->students << this->input_output_file_student;
                break;
            case (5):
                -*this->workers;
                *this->workers << this->input_output_file_worker;
                break;
            case (6):
                this->students->sortVectorByRoomNumber();
                *this->students << this->input_output_file_student;
                break;
            case (7):
                this->workers->sortVectorBySalary();
                *this->workers << this->input_output_file_worker;
                break;
        }
        if (this->user_input >= 1 && this->user_input <= 7)
            std::cout << "\nCommand executed\n\n";

    } while(this->user_input != 0);
    std::cout << "\n~~~~~~Management menu successfully terminated~~~~~~\n";
}

Admin_Management_Console::~Admin_Management_Console() {
    *this->students << this->input_output_file_student;
    *this->workers << this->input_output_file_worker;

    delete this->students;
    delete this->workers;
}