#include <iostream>
#include <string>
#include "PlacaDeBaza.h"
#include "Procesor.h"
#include "MemorieRAM.h"
#include "Stocare.h"

using namespace std;



int main() {
    MemorieRam Kingston8GB(8,3200,180, 20);
    PlacaDeBaza AsusX570("ATX","AM4", 4000 );
    Procesor Ryzen3500x("AM4", 3900, 6);
    Stocare Kingston500GB("SSD",500,1024,312,30);

    string soket1=AsusX570.getSoket();
    if(soket1==Ryzen3500x.getSoket())
        cout<<"Sunt compatibile";
    else cout<<"Nu sunt compatibile";

    Kingston8GB.setStele(3.5);

    Componente *e=Kingston8GB.clone();
    if(auto *p=dynamic_cast<MemorieRam*>(e))
    cout<<'\n'<<p->notaProdus()<<'\n';



    try { // NOLINT(*-misleading-indentation)
        MemorieRam a(8, -2000);
    }catch (const exception& e){
        cerr<<"Eroare: "<<e.what()<<'\n';
    }

    try{
        MemorieRam b(8,3200,-200);
    }catch (const exception &e){
        cerr<<"Eroare: "<<e.what()<<'\n';
    }

    return 0;
}
