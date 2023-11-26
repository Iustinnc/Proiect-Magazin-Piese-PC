
#ifndef ExceptiePretNegativ_H
#define ExceptiePretNegativ_H
#include <stdexcept>
#include "exception"

class ExceptiePretNegativ:public std::exception{
public:
    const char* what() const noexcept override{
        return "Eroare: Pretul nu poate fi negativ";
    }
};

#endif
