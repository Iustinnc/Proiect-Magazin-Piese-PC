
#ifndef Stocare_H
#define Stocare_H
#include "Componente.h"
#include <iostream>
#include <string>

class Stocare:public Componente{
    string tip;
    int capacitate;
    float vitezaScriere;

public:
    Stocare(string tip="", int capacitate=0, float vitezaScriere=0, float pret=0, int stoc=0): Componente(pret,stoc){
        this->tip=tip;
        this->capacitate=capacitate;
        this->vitezaScriere=vitezaScriere;

        if(capacitate<0 || vitezaScriere<0)
            throw invalid_argument("Argument invalid");
    }

    Stocare(Stocare& x){
        this->vitezaScriere=x.vitezaScriere;
        this->tip=x.tip;
        this->capacitate=x.capacitate;
    }
    Componente * clone() override{return new Stocare(*this);}

    float notaProdus() const override{
        float pret1=pret;
        while(pret1>=1)
            pret1=pret1/10;

        return stele * 2 + 1 - pret1 > 10 ? 10 : stele * 2 + 1 - pret1;

    }

    void setStele(float a) override{stele=a;}

    void setPret(float pret1) override {pret=pret1;}

    friend ostream& operator <<(ostream& out, Stocare& a){
        out<<"Tip: "<<a.tip<<"Capacitate:"<<a.capacitate<<"GB\nViteza Scriere:"<<a.vitezaScriere<<"Mb/s";
        return out;
    }

   Stocare operator=(const Stocare& a){
        if(this!=&a){
            Componente::operator=(a);
            capacitate=a.capacitate;
            tip=a.tip;
            vitezaScriere=a.vitezaScriere;
        }
        return *this;
    }

    static void infoComune(){
        cout<<"Atributele standard ale unei Memorii Externe sunt:\nTip: SSD\nCapacitate: 500GB\nViteza de scriere: 512Mb/s";

    }

};
#endif
