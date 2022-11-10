#include "File_Management.h"


size_t File_Management::counter_default_created_files = 0;
std::filesystem::path File_Management::default_creation_input_output_file_student = R"(D:\Studying _Practice_3_sem_4_task\Default_input_output_file_student.txt)";
std::filesystem::path File_Management::default_creation_input_output_file_worker = R"(D:\Studying _Practice_3_sem_4_task\Default_input_output_file_worker.txt)";

File_Management::File_Management(const std::filesystem::path &input_output_file_student,
                                 const std::filesystem::path &input_output_file_worker)
        : input_output_file_student{input_output_file_student}, input_output_file_worker{input_output_file_worker}{

    setInputOutputFileStudent(this->input_output_file_student);
    setInputOutputFileWorker(this->input_output_file_worker);
    if (counter_default_created_files > 0) throw -1;
}

void File_Management::setInputOutputFileStudent(const std::filesystem::path &input_output_file_student) {
    if (!std::filesystem::exists(input_output_file_student)) {
        std::ofstream inp{input_output_file_student};
        this->input_output_file_student = input_output_file_student;
        inp.close();
        counter_default_created_files++;
    } else this->input_output_file_student = input_output_file_student;
}

void File_Management::setInputOutputFileWorker(const std::filesystem::path &input_output_file_worker) {
    if (!std::filesystem::exists(input_output_file_worker)) {
        std::ofstream inp{input_output_file_worker};
        this->input_output_file_worker = input_output_file_worker;
        inp.close();
        counter_default_created_files++;
    } else this->input_output_file_worker = input_output_file_worker;
}
