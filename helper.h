#ifndef _HELPER
#define _HELPER
#include <iostream>
#include <string>
#include <utility>

struct ID_not_found_pJ {

    std::string _message;

 friend std::ostream& operator<<(std::ostream& out, const ID_not_found_pJ& message) { return out << message._message; }
};

struct ID_not_found {
    std::string _message;
    friend std::ostream& operator<<(std::ostream& out, const ID_not_found& message) { return out << message._message; }
};


#endif