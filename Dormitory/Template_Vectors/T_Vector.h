#ifndef UNIVERSITY_T_VECTOR_H
#define UNIVERSITY_T_VECTOR_H

#include "vector"

template <class T>
class T_Vector{
protected:
    std::vector<T> vector;
public:
    explicit T_Vector() noexcept;
    ~T_Vector() noexcept;

    void printAllInfo() const noexcept;
};

template <class T>
T_Vector<T>::T_Vector() noexcept { }

template <class T>
T_Vector<T>::~T_Vector() noexcept { }

template<class T>
void T_Vector<T>::printAllInfo() const noexcept {
    for (auto &el : vector){
        el.printAllInfo();
    }
}

#endif //UNIVERSITY_T_VECTOR_H
