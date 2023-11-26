
#ifndef PlacaDeBaza_H
#define PlacaDeBaza_H

#include <string>
#include <iostream>
#include <utility>
#include "Componente.h"
using namespace std;
class PlacaDeBaza:public Componente{
    string soket;
    int frecventa;
    string format;

public:

    explicit PlacaDeBaza(string format1="", string soket1="", int frecventa1=0, float pret1=0, int stoc1=0): Componente(pret1, stoc1){
        this->soket=std::move(soket1);
        this->format=std::move(format1);
        this->frecventa=frecventa1;

        if(frecventa<0)
            throw std::invalid_argument("Frecventa nu poate fi negativa");

    }
    PlacaDeBaza(const PlacaDeBaza& p) : Componente(p) {
        format=p.format;
        soket=p.soket;
        frecventa=p.frecventa;

    }

    Componente *clone() override{return new PlacaDeBaza(*this);}

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


    friend ostream& operator <<(ostream& out, PlacaDeBaza& a ){
        out<<"Format:"<<a.format<<"\n"<<"Soket:"<<a.soket<<"\n"<<"Frecventa:"<<a.frecventa<<"MHz";
        return out;
    }

    PlacaDeBaza operator=(const PlacaDeBaza& a){
        if(this!=&a)
        {
            Componente::operator=(a);
            format=a.format;
            soket=a.soket;
            frecventa=a.frecventa;
        }
        return *this;
    }
    static void infoComune(){
        cout<<"Atributele standard ale unei Placi de baza sunt:\n Frecventa: 2000MHz";

    }


};
#endif
