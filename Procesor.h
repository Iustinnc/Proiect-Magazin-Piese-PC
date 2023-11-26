
#ifndef Procesor_H
#define Procesor_H
#include <string>
#include "Componente.h"
using namespace std;

class Procesor: public Componente{

    string soket;
    int frecventa{};
    int nuclee{};

public:


    explicit Procesor( string soket1="", int frecventa1=0, int nuclee1=0, float pret1=0, int stoc1=0): Componente(pret1, stoc1)
    {
        this->soket=std::move(soket1);
        this->frecventa=frecventa1;
        this->nuclee=nuclee1;

        if(frecventa<0)
        throw std::invalid_argument("Frecventa nu poate fi negativa");

        if(nuclee<0)
            throw std::invalid_argument("Nu poate avea un numar negativ de nuclee");
    }
    Procesor(const Procesor& x): Componente(x){
        soket=x.soket;
        frecventa=x.frecventa;
        nuclee=x.nuclee;
    }

    Componente * clone() override{return new Procesor(*this);}

    string getSoket(){
        return soket;
    }

    float notaProdus() const override{
        float pret1=pret;
        while(pret1>=1)
            pret1=pret1/10;

        return stele * 2 + 1 - pret1 > 10 ? 10 : stele * 2 + 1 - pret1;

    }
    void setStele(float a) override{stele=a;}

    friend ostream& operator <<(ostream& out, Procesor& a){
        out<<"Soket:"<<a.soket<<"\n"<<"Frecventa:"<<a.frecventa<<"MHz\n"<<"Nuclee:"<<a.nuclee;
        return out;
    }

    Procesor operator=(const Procesor& a){
        if(this!=&a){
            Componente::operator=(a);
            soket=a.soket;
            frecventa=a.frecventa;
            nuclee=a.nuclee;
        }
        return *this;
    }

    static void infoComune(){
        cout<<"Atributele standard ale unui Procesor sunt:\n Nuclee: 4\n Frecventa: 3.0 GHz";

    }

};
#endif
