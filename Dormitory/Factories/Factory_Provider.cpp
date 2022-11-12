#include "Factory_Provider.h"

//D:\University\Studying_Practice_Tasks\3-4_semester\Task_1\txt_files\Default_Factory.txt

A_Container_Factory *Factory_Provider::GetVectorFactory() const noexcept {
    std::filesystem::path path = R"(D:\Studying _Practice_3_sem_4_task\Default_Factory.txt)";
    std::fstream input{path, std::fstream::in};
    size_t n;
    input >> n;
    input.close();
    switch (n) {
        case 1:
            return new Inheritance_Vector_Factory();
        case 2:
            return new Template_Vector_Factory();
        case 3:
            return new Flyweight_Map_Factory();
    }
}