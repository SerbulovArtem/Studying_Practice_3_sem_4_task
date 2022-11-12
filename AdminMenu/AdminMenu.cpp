#include "AdminMenu.h"

Admin_Management_Console::Admin_Management_Console() noexcept : user_input{0} {
    Factory_Provider factoryProvider;
    A_Container_Factory* ContainerFactory = factoryProvider.GetVectorFactory();

    this->students = ContainerFactory->GetStudentContainer();
    this->workers = ContainerFactory->GetWorkerContainer();

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
                     "4: Delete student\n"
                     "5: Delete worker\n"
                     "6: Sort student container by room number\n"
                     "7: Sort worker container by salary\n";
        do {
            std::cout << "Enter number from 0-9:";
            std::cin >> this->user_input;
        } while(this->user_input < 0 || this->user_input > 9);

        switch (this->user_input) {
            case (1):
                *this->students >> this->input_output_file_student;
                *this->workers >> this->input_output_file_worker;
                std::cout << "\nStudents:\n";
                this->students->printAllInfo();
                std::cout << "\nWorkers:\n";
                this->workers->printAllInfo();
                break;
            case (2):
                handleAddStudent();
                *this->students << this->input_output_file_student;
                break;
            case (3):
                handleAddWorker();
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
                this->students->sortContainerByRoomNumber();
                *this->students << this->input_output_file_student;
                break;
            case (7):
                this->workers->sortContainerBySalary();
                *this->workers << this->input_output_file_worker;
                break;
        }
        if (this->user_input >= 1 && this->user_input <= 7)
            std::cout << "\nCommand executed\n\n";

    } while(this->user_input != 0);
    std::cout << "\n~~~~~~Management menu successfully terminated~~~~~~\n";
}

void Admin_Management_Console::handleAddStudent() {
    std::string name, surname;
    size_t age, course, room_number;
    std::cout << "Enter: name, surname, age, course, room number:\n";
    std::cin >> name >> surname >> age >> course >> room_number;
    try {
        Student *student = new Student(name, surname, age, course, room_number);
        this->students->addStudent(student);
    }
    catch(const char* err){
        std::cout << "\nInvalid value!\n"
                     "Student is not added!\n";
    }
}

void Admin_Management_Console::handleAddWorker() {
    std::string name, surname, position;
    size_t age, salary;
    std::cout << "Enter: name, surname, age, position, salary:\n";
    std::cin >> name >> surname >> age >> position >> salary;
    try{
        Worker *worker = new Worker(name, surname, age, position, salary);
        this->workers->addWorker(worker);
    }
    catch(const char* err){
        std::cout << "\nInvalid value!\n"
                     "Worker is not added!\n";
    }
}

Admin_Management_Console::~Admin_Management_Console() {
    *this->students << this->input_output_file_student;
    *this->workers << this->input_output_file_worker;

    delete this->students;
    delete this->workers;
}