#include "AdminMenu.h"

int main(){
    try {
        Admin_Management_Console demo;
        demo.admin();
    }
    catch (int e){
        std::cout << "\n~~~~~~Default files were created~~~~~~\n"
                     "~~~~~~Please Enter information~~~~~~\n";
    }

    return 0;
}