#ifndef UNIVERSITY_FILE_MANAGEMENT_H
#define UNIVERSITY_FILE_MANAGEMENT_H
#include <iostream>
#include <fstream>
#include <filesystem>

class File_Management{
private:
    static size_t counter_default_created_files;
    static std::filesystem::path default_creation_input_output_file_student;
    static std::filesystem::path default_creation_input_output_file_worker;

    void setInputOutputFileStudent(const std::filesystem::path &input_output_file_student);
    void setInputOutputFileWorker(const std::filesystem::path &input_output_file_worker);

protected:
    std::filesystem::path input_output_file_student;
    std::filesystem::path input_output_file_worker;

public:
    File_Management(const std::filesystem::path &input_output_file_student = default_creation_input_output_file_student
            , const std::filesystem::path &input_output_file_worker = default_creation_input_output_file_worker);
};


#endif //UNIVERSITY_FILE_MANAGEMENT_H
