//
// Created by Acer on 2023. 04. 24..
//
#ifndef NAPTAR_ESEMENY_H
#define NAPTAR_ESEMENY_H
#include "datum.h"
#include "Ido.h"
#include <iostream>
using std::string;
class Esemeny{
    unsigned int id;
    Datum date;
    Ido idotartam;
    std::string nev;
    std::string hely;
public:
    Esemeny(unsigned int idx,Datum ujdate,Ido ujido,string ujnev,string ujhely):id(idx),date(ujdate), idotartam(ujido),nev(ujnev),hely(ujhely){}
    unsigned int getId()const{
        return id;
    }
    string getnev()const{
        return nev;
    }
    string gethely()const{
        return hely;
    }
    Datum getdate()const{
        return date;
    }
    Ido getido()const{
        return idotartam;
    }
    void setId(unsigned int ujid){
        id=ujid;
    }
    virtual void kiir() {}
    virtual char kiirando(){}
    virtual ~Esemeny(){}
    virtual string adatok(){}
};

class WorkE:public Esemeny{
    int projektid;
    int fazis;
public:
   WorkE(unsigned int widx,Datum wdate, Ido wid,string wnev, string whely, int projid, int faz): Esemeny(widx,wdate,wid,wnev,whely),projektid(projid),fazis(faz){}
   void setAdat(int projid,int faz){
       projektid=projid;
       fazis=faz;
   }
  void kiir(){
       std::cout<<"\tId: #"<<this->getId()<<"\tDatum: "<<this->getdate()<<"\tIdoszak: "<<this->getido().getKora()<<":"<<this->getido().getKperc()<<"-"<<this->getido().getVora()<<":"<<this->getido().getVperc()<<"\tHely: "<<this->gethely()<<"\tProjektid: "<<projektid<<"\tFazis: "<<fazis<<std::endl;
   }

   int getProjid(){
       return projektid;
   }
   int getFazis(){
       return fazis;
   }
   char kiirando(){
       return 'W';
   }
   string adatok(){
       string uj=(char*)projektid;
       uj+=" ";
       uj+=(char*)fazis;
       return uj;
   }
};



class PersonalE:public Esemeny{
    string megjegyzes;
public:
    PersonalE(unsigned int widx,Datum wdate, Ido wid,string wnev, string whely, string megj): Esemeny(widx,wdate,wid,wnev,whely),megjegyzes(megj) {}
    void setMegj(string uj){
        megjegyzes=uj;
    }
    void kiir(){
        std::cout<<"\tId: #"<<this->getId()<<"\tDatum: "<<this->getdate()<<"\tIdoszak: "<<this->getido().getKora()<<":"<<this->getido().getKperc()<<"-"<<this->getido().getVora()<<":"<<this->getido().getVperc()<<"\tHely: "<<this->gethely()<<"\nMegjegyzes: "<<megjegyzes<<std::endl;
    }

    string getMegj(){
        return megjegyzes;
    }
    char kiirando(){
        return 'P';
    }
    string adatok(){
        return megjegyzes;
    }
};





#endif //NAPTAR_ESEMENY_H
