cmake_minimum_required(VERSION 3.21)
project(Dormitory)

set(CMAKE_CXX_STANDARD 20)

add_library(Dormitory STATIC
        A_Vectors/A_Student_Vector.h
        A_Vectors/A_TVector.h
        A_Vectors/A_Worker_Vector.h

        File_Management.cpp
        File_Management.h
        Person.cpp
        Person.h
        Student.cpp
        Student.h
        Worker.cpp
        Worker.h

        Factories/A_Vector_Factory.h
        Factories/Inheritance_Vector_Factory.cpp
        Factories/Inheritance_Vector_Factory.h
        Factories/Template_Vector_Factory.cpp
        Factories/Template_Vector_Factory.h
        Factories/Vector_Factory_Provider.cpp
        Factories/Vector_Factory_Provider.h

        Inheritance_Vectors/Person_Vector.cpp
        Inheritance_Vectors/Person_Vector.h
        Inheritance_Vectors/Student_Vector.cpp
        Inheritance_Vectors/Student_Vector.h
        Inheritance_Vectors/Worker_Vector.cpp
        Inheritance_Vectors/Worker_Vector.h

        Template_Vectors/T_Vector.h
        Template_Vectors/T_Vector_Student.cpp
        Template_Vectors/T_Vector_Student.h
        Template_Vectors/T_Vector_Worker.cpp
        Template_Vectors/T_Vector_Worker.h)