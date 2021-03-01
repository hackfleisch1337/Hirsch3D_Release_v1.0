#ifndef HIRSCH3D_EXCEPTION_HPP
#define HIRSCH3D_EXCEPTION_HPP
#include <string>
#include <iostream>
#ifndef RED
#define RED "\033[91m"
#define RESET_CLR "\x1B[0m"
#endif
namespace h3d
{
    class Exception {
    public:
        Exception(std::string message): errormessage(message){}
        void printErrorMessage() {
            std::cout << RED << "[FAILED] Exception catched: " << this->errormessage << RESET_CLR << std::endl;
        }
    private:
        std::string errormessage;

    };
}


#endif