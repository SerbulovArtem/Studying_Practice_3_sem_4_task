#include "UserMenu.h"

User_Management_Console::User_Management_Console() noexcept : user_input{0}{
    Vector_Factory_Provider factoryProvider;
    A_Vector_Factory* vectorFactory = factoryProvider.GetVectorFactory();

    this->students = vectorFactory->GetStudentVector();
    this->workers = vectorFactory->GetWorkerVector();

    *this->students >> this->input_output_file_student;
    *this->workers >> this->input_output_file_worker;
}

void User_Management_Console::user() {
    std::cout << "~~~~~~Management menu successfully invoked~~~~~~\n";
    do{
        std::cout << "Options:\n"
                     "0: Exit from the program\n"
                     "1: Print All students and workers on terminal\n"
                     "2: Print student vector sorted by room number\n"
                     "3: Print worker vector sorted by salary\n";
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
                *this->students >> this->input_output_file_student;
                this->students->sortVectorByRoomNumber();
                std::cout << "\nStudents:\n";
                this->students->printAllInfo();
                break;
            case (3):
                *this->workers >> this->input_output_file_worker;
                this->workers->sortVectorBySalary();
                std::cout << "\nWorkers:\n";
                this->workers->printAllInfo();
                break;
        }
            if (this->user_input >= 1 && this->user_input <= 3)
                std::cout << "\nCommand executed\n\n";

    } while(this->user_input != 0);
    std::cout << "\n~~~~~~Management menu successfully terminated~~~~~~\n";
}

User_Management_Console::~User_Management_Console() noexcept {

    delete this->students;
    delete this->workers;
}
