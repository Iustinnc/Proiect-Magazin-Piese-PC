
#ifndef MemorieRAM_H
#define MemorieRAM_H
#include <iostream>
#include <string>
#include "Componente.h"
using namespace std;

class MemorieRam:public Componente {
    int capacitate;
    int frecventa;

public:


    explicit MemorieRam(int capacitate1=0, int frecventa1=0,float pret1=0, int stoc1=0): Componente(pret1, stoc1) {
        this->capacitate = capacitate1;
        this->frecventa = frecventa1;

        if(frecventa<0)
            throw std::invalid_argument("Frecventa nu poate fi negativa");

        if(capacitate<0)
            throw std::invalid_argument("Capacitatea nu poate fi negativa");
    }

    MemorieRam(const MemorieRam &x)  : Componente(x) {
        capacitate = x.capacitate;
        frecventa = x.frecventa;
    }

    Componente * clone() override{return new MemorieRam(*this);}

    float notaProdus() const override{
        float pret1=pret;
        while(pret1>=1)
        pret1=pret1/10;

        return stele * 2 + 1 - pret1 > 10 ? 10 : stele * 2 + 1 - pret1;

    }
    void setStele(float a) override{stele=a;}

    void setPret(float pret1) override {pret=pret1;}

    friend ostream& operator <<(ostream& out, MemorieRam& a){
        out<<"Capacitate:"<<a.capacitate<<"GB\nFrecventa:"<<a.frecventa<<"MHz";
        return out;
    }
    MemorieRam operator=(const MemorieRam& a){
        if(this!=&a){
            Componente::operator=(a);
            capacitate=a.capacitate;
            frecventa=a.frecventa;
        }
        return *this;
    }

    static void infoComune(){
        cout<<"Atributele standard ale unei MemoriiRam sunt:\n Capacitate: 4GB\n Frecventa: 2000MHz";

    }


};

#endif
