#include <iostream>
#include <string>


using namespace std;

class PlacaDeBaza{
    string soket;
    int frecventa;
    string format;

public:
    PlacaDeBaza() {this->soket="";
        this->format="";
        this->frecventa=0;};
    PlacaDeBaza(string format1, string soket1, int frecventa1){
        this->soket=std::move(soket1);
        this->format=std::move(format1);
        this->frecventa=frecventa1;

    }
    PlacaDeBaza(const PlacaDeBaza& p){
        format=p.format;
        soket=p.soket;
        frecventa=p.frecventa;

    }

    string get_soket(){
        return soket;
    }


    friend ostream& operator <<(ostream& out, PlacaDeBaza& a ){
        out<<"Format:"<<a.format<<"\n"<<"Soket:"<<a.soket<<"\n"<<"Frecventa:"<<a.frecventa<<"MHz";
        return out;
    }

    PlacaDeBaza operator=(const PlacaDeBaza& a){
        if(this!=&a)
        {
            format=a.format;
            soket=a.soket;
            frecventa=a.frecventa;
        }
        return *this;
    }

};

class Procesor{

    string soket;
    int frecventa{};
    int nuclee{};

public:

    Procesor(){
        this->soket="";
        this->frecventa=0;
        this->nuclee=0; }
    Procesor( string soket1, int frecventa1, int nuclee1)
    {
        this->soket=std::move(soket1);
        this->frecventa=frecventa1;
        this->nuclee=nuclee1;
    }
    Procesor(const Procesor& x)
    {
        soket=x.soket;
        frecventa=x.frecventa;
        nuclee=x.nuclee;
    }

    string get_soket(){
        return soket;
    }

    friend ostream& operator <<(ostream& out, Procesor& a){
        out<<"Soket:"<<a.soket<<"\n"<<"Frecventa:"<<a.frecventa<<"MHz\n"<<"Nuclee:"<<a.nuclee;
        return out;
    }

    Procesor operator=(const Procesor& a){
        if(this!=&a){
            soket=a.soket;
            frecventa=a.frecventa;
            nuclee=a.nuclee;
        }
        return *this;
    }

};

class MemorieRam {
    int capacitate;
    int frecventa;

public:
    MemorieRam() {
        this->frecventa = 0;
        this->capacitate = 0;
    }

    MemorieRam(int capacitate1, int frecventa1) {
        this->capacitate = capacitate1;
        this->frecventa = frecventa1;
    }

    MemorieRam(const MemorieRam &x) {
        capacitate = x.capacitate;
        frecventa = x.frecventa;
    }

    friend ostream& operator <<(ostream& out, MemorieRam& a){
        out<<"Capacitate:"<<a.capacitate<<"GB\nFrecventa:"<<a.frecventa<<"MHz";
        return out;
    }
    MemorieRam operator=(const MemorieRam& a){
        if(this!=&a){
            capacitate=a.capacitate;
            frecventa=a.frecventa;
        }
        return *this;
    }
};





int main() {
    MemorieRam Kingston8GB(8,3200);
    PlacaDeBaza AsusX570("ATX","AM4", 4000 );
    Procesor Ryzen3500x("AM4", 3900, 6);

    string soket1=AsusX570.get_soket();


    if(soket1==Ryzen3500x.get_soket())
        cout<<"Sunt compatibile";
    else cout<< "Nu sunt compatibile";
    cout<<'\n'<<Kingston8GB;

    return 0;
}
