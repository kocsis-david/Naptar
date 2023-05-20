//
// Created by Acer on 2023. 05. 10..
//
#include "naplo.h"
//
// Created by Acer on 2023. 05. 04..
//
#include "esemeny.h"
#include "naplo.h"
#include <iostream>
#include <fstream>

void Naplo::beolvas(){
    std::ifstream be("naptar.txt");
    unsigned idx=1;
    if(be.is_open()) {
        delete[] esemenyek;
        unsigned int hossz = 0;
        be >> hossz;
        esemenyek=new Esemeny* [hossz];
        size=hossz;
        for (int i = 0; i < hossz; ++i) {
            int ev, ho, nap;
            int kezdo, vego, kezdp, vegp;
            be >>ev>>ho>>nap;
            be >> kezdo;
            be.ignore();
            be >> kezdp;
            be.ignore();
            be >> vego;
            be.ignore();
            be>>vegp;
            be.ignore();
            string unev, uhely;
            getline(be, unev);
            getline(be, uhely);
            char c;
            be>>c;

            if(c=='W'){
                int prid,all;
                be>>prid>>all;
                this->add(new WorkE(idx++,Datum(ev,ho,nap), Ido(kezdp,kezdp,vego,vegp),unev,uhely,prid,all));
                db++;

            }
            if(c=='S'){
                string megj;
                getline(be,megj);
                this->add(new PersonalE(idx++,Datum(ev,ho,nap),Ido(kezdo,kezdp,vego,vegp),unev,uhely,megj));
                db++;
            }


        }
    }

}

void Naplo::menu(){
    std::cout<<"Lehetosegek:\n1:Naptaram kirajzolása \n2: Naptaram modositasa\n3: Kereses \n4: Mentes es kilepes\n";
    int valasz;
    std::cin>>valasz;
    switch (valasz) {
        case 1:
            this->kirajz();
            this->menu();
            break;
        case 2:
            this->modosit();
            this->menu();
            break;
        case 3:
            //this.keres;
            this->menu();
            break;
        case 4:
            std::cout<<"Kilepes elott menes?(ha igen, irja be, hogy:mentes\n";
            std::string ment="";
            std::cin>>ment;
            if(!strcmp(ment.c_str(),"mentes")){
                this->kirajz();
                if(this->mentes()){
                    std::cout<<"Sikeres volt a mentes!\n";
                }
            }

            std::cout<<"EXIT"<<std::endl;
            break;
        /*default:
            std::cout<<"Nincs ilyen lehetoseg!"<<std::endl;
            this->menu();*/

    }

}
void Naplo::rendez(){
    for (unsigned int i = 1; i <size ; ++i) {
        bool kisebbe=esemenyek[i]->getdate().kisebb(esemenyek[i-1]->getdate());
        if(kisebbe==0){
            if(esemenyek[i]->getido().hamarabb(esemenyek[i-1]->getido())==1)kisebbe=1;
        }
        if(kisebbe==1){
            unsigned int j=i;
            while(kisebbe==1||j!=1){
                Esemeny* tmp=esemenyek[j-1];
                esemenyek[j-1]=esemenyek[j];
                esemenyek[j]=tmp;
                esemenyek[j]->setId(j);
                esemenyek[j-1]->setId(j-1);
                j--;
                kisebbe=esemenyek[j]->getdate().kisebb(esemenyek[j-1]->getdate());
                if(kisebbe==0){
                    if(esemenyek[j]->getido().hamarabb(esemenyek[j-1]->getido())==1)kisebbe=1;
                }
            }


        }
    }
}
void Naplo::kirajz() {
    std::cout<<"Milyen formatumban szeretne kiirni?\n0.Mindet\n1.Ev\t2.Honap\t3.Nap\n(Eleg a szamot megadni)";
    int valasz;
    std::cin>>valasz;
    switch (valasz) {
        case 0:
            for (unsigned int i = 0; i <this->db; ++i) {
                esemenyek[i]->kiir();
            }
            break;
        case 1:
            int uev;
            std::cout<<"Kerem az evet: ";
            std::cin>>uev;
            for (int i = 0; i < db; ++i) {
                if(esemenyek[i]->getdate().getEv()==uev)
                    esemenyek[i]->kiir();
            }
            break;
        case 2:
            int uho;
            std::cout<<"Kerem az evet: ";
            std::cin>>uev;
            std::cout<<"Kerem a honapot: ";
            std::cin>>uho;
            for (int i = 0; i < db; ++i) {
                if(esemenyek[i]->getdate().getHo()==uho&&esemenyek[i]->getdate().getEv()==uev)
                    esemenyek[i]->kiir();
            }
            break;
        case 3:
            int unap;
            std::cout<<"Kerem az evet: ";
            std::cin>>uev;
            std::cout<<"Kerem a honapot: ";
            std::cin>>uho;
            std::cout<<"Kerem a napot: ";
            std::cin>>uev;
            for (int i = 0; i < db; ++i) {
                if(esemenyek[i]->getdate().getNap()==unap&&esemenyek[i]->getdate().getHo()==uho&&esemenyek[i]->getdate().getEv()==uev)
                    esemenyek[i]->kiir();
            }
            break;
    }
}
bool Naplo::mentes() {
    std::ofstream ki("naptar.txt");

    if(ki.is_open()) {
        ki<<db;
        for (int i = 0; i < db; ++i){
            ki<<esemenyek[i]->getdate().getEv()<<"."<<esemenyek[i]->getdate().getHo()<<"."<<esemenyek[i]->getdate().getNap()<<std::endl;
            ki<<esemenyek[i]->getido().getKora()<<":"<<esemenyek[i]->getido().getKperc()<<"-"<<esemenyek[i]->getido().getVora()<<":"<<esemenyek[i]->getido().getVperc()<<std::endl;
            ki<<esemenyek[i]->getnev()<<std::endl;
            ki<<esemenyek[i]->gethely()<<std::endl;
            ki<<esemenyek[i]->kiirando()<<std::endl;
            ki<<esemenyek[i]->adatok()<<std::endl;
        }
        return true;
    }
    return false;
}
void Naplo::modosit() {
    std::cout<<"Uj esemenyt(1) vagy letezo esemenyt(2) szeretne letrehozni/modositani:";
    int valasz=1;
    std::cin>>valasz;
    while (valasz<1&&2<valasz){
        std::cout<<"Kerem valasszon a ket lehetoseg kozul a szamukkal!";
        std::cin>>valasz;
    }

    if(valasz==1){
       std::cout<<"\nKerem a datumot:";
       int ev,ho,nap;
       std::cin>>ev>>ho>>nap;
       /*while(ho<1&&12<ho){
           std::cout<<"\nRosszul adta meg a honapot, kerem ujra:";
           std::cin>>ho;
       }
       while(nap<0||31<nap){
           std::cout<<"\nRosszul adta meg a napot, kerem ujra:";
           std::cin>>nap;
       }*/

       int kezdo,kezdp,vego,vegp;
        std::cout<<"\nKezdes oraja:";
        std::cin>>kezdo;
        /*while(kezdo<0||24<kezdo){
                std::cout<<"\nRosszul adta meg az órát, kerem ujra:";
                std::cin>>kezdo;
        }*/

        std::cout<<"\nKezdes perce:";
        std::cin>>kezdp;
       /* while(kezdp<0||60<kezdp){
                std::cout<<"\nRosszul adta meg az percet, kerem ujra:";
                std::cin>>kezdp;
        }*/
        std::cout<<"\nIdotartam vegenek oraja:";
        std::cin>>vego;
        /*while(vego<0||24<vego){
                std::cout<<"\nRosszul adta meg az orat, kerem ujra:";
                std::cin>>kezdo;
        }*/
        std::cout<<"\nIdotartam vegenek perce:";
        std::cin>>vegp;
        /*while(vegp<0||60<vegp){
            std::cout<<"\nRosszul adta meg az percet, kerem ujra:";
            std::cin>>kezdp;
        }*/
        std::string nev,hely;
        std::cout<<"\nKerem az esemeny nevet: ";
        std::cin>>nev;
        std::cout<<"\nKerem az esemeny helyet: ";
        std::cin>>hely;
        std::cout<<"\nKerem az esemeny tipusat (1)Munka vagy (2)Szemelyes: ";
        int melyik;
        std::cin>>melyik;
        /*while(melyik!=1||melyik!=2){
            std::cout<<"\nNincs ilyen valaszlehetoseg, kerem ujra: ";
            std::cin>>melyik;
        }*/
        if(melyik==1){
            std::cout<<"\nKerem a projekt Id-t: ";
            int pid, faz;
            while (pid<0){
                std::cout<<"\nNem letezhet ilyen id!Adjon egy ujat: ";
                std::cin>>pid;
            }
            std::cout<<"\nKerem a projekt fazisat: ";
            std::cin>>faz;
            this->add(new WorkE(db++,Datum(ev,ho,nap),Ido(kezdo,kezdp,vego,vegp),nev,hely,pid,faz));
            if(esemenyek[db-1]!=NULL)esemenyek[db-1]->kiir();


        }else{
            std::cout<<"Mit szeretne meg hozzafuzni az esemenyhez:";
            string megjegyzes;
            std::cin>>megjegyzes;
            this->add(new PersonalE(db++,Datum(ev,ho,nap),Ido(kezdo,kezdp,vego,vegp),nev,hely,megjegyzes));
            if(esemenyek[db-1]!=NULL)esemenyek[db-1]->kiir();

        }
    }

}
