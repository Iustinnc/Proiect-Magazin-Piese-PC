

#ifndef ExceptieStocNegativ_H
#define ExceptieStocNegativ_H
#include <stdexcept>
#include "exception"
class ExceptieStocNegativ:public std::exception{
public:
    const char* what() const noexcept override{
        return "Eroare: Stocul nu poate fi negativ";
    }
};

#endif
