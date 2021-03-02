/**
 * Hirsch3D Renderengine v.0.9.6
 * For more informations see README.md
 * or read the documentation in the doc folder
 * GitHub Repository: https://github.com/hackfleisch1337/Hirsch3D_Release_v1.0
 * Licence: MIT Licence
 * Last changes: 02.03.2021 (DD.MM.YYYY)
 * 
 * @file Hirsch3D/error/Exception
 * @ref Hirsch3d/error
 *
 * @author Emanuel Zache
 * @version 0.9.6
 * @copyright (C) 2021 Emanuel Zache
 *
 *
 * 
 * 
 * 
 * 
 * 
 * 
 *
 */


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