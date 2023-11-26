
#ifndef Componente_H
#define Componente_H
#include <iostream>
#include "ExceptiePretNegativ.h"
#include "ExceptieStocNegativ.h"
using namespace std;

class Componente{
    int stoc;
protected:
    float stele;
    float pret;
public:

    explicit Componente(float pret1=0, int stoc1=0, float stele=0){
        this->pret=pret1;
        this->stoc=stoc1;
        this->stele=stele;

        if(pret<0)
            throw ExceptiePretNegativ();

        if(stoc<0)
            throw ExceptieStocNegativ();
    }
    Componente(const Componente&x){
        stoc=x.stoc;
        pret=x.pret;
        stele=x.stele;
    }

    virtual Componente* clone(){}

    virtual float notaProdus() const {return stele*2;}

    virtual void setPret(float pret1){this->pret=pret1;}

    float getPret()const {return pret;}

    friend ostream& operator <<(ostream& out, const Componente& a){
        if(a.stoc==0)
            out<<"Pret: "<<a.pret<<"RON\nStoc: Epuizat";
        else
        out<<"Pret: "<<a.pret<<"RON\n"<<"Stoc: "<<a.stoc<<"buc";
        return out;
    }

    Componente operator=(const Componente& a){
        if(this!=&a)
        {
            pret=a.pret;
            stoc=a.stoc;
            stele=a.stele;
        }
        return *this;
    }

   virtual void setStele(float a){this->stele=a;}

   virtual ~Componente() = default;



};
#endif
