//
// Created by David Kocsis on 2023. 05. 06..
//

#ifndef NAPTAR_IDO_H
#define NAPTAR_IDO_H
#include <iomanip>
#include <iostream>
class Ido{
    int kora;
    int vora;
    int kperc;
    int vperc;
public:
    Ido(int ko=0,int kp=0,int vo=0,int vp=0):kora(ko),vora(vo),kperc(kp),vperc(vp){}
    Ido(const Ido& uj):kora(uj.kora),vora(uj.vora),kperc(uj.kperc),vperc(uj.vperc){}
    void setIdo(int ko=0,int kp=0,int vo=0,int vp=0){
        kora=ko;
        vora=vo;
        kperc=kp;
        vperc=vp;
    }
    int getKora()const{return kora;}
    int getKperc()const{return kperc;}
    int getVora()const{return vora;}
    int getVperc()const{return vperc;}
    int hamarabb(const Ido& masik){
        if(masik.getKora()>vora)return 1;
        else if(kora>masik.getVora())return 2;
        else if(masik.kperc>vperc)return 1;
        else if(kperc>masik.vperc)return 2;
        else return 0;
    }
};

/*std::ostream& operator<<(std::ostream& os, const Ido& ki) {
    return os << ki.getKora() <<":"<<ki.getKperc()<<"-"<<ki.getVora()<<":"<<ki.getVperc();

}*/
#endif //NAPTAR_IDO_H
