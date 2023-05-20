//
// Created by Acer on 2023. 04. 24..
//

#ifndef NAPTAR_NAPLO_H
#define NAPTAR_NAPLO_H
#include "esemeny.h"
#include <iostream>
#include <cstring>
class Naplo{
    Esemeny **esemenyek;
    unsigned int size;
    unsigned int db;
public:
    void add(Esemeny *uj){
    if(size==db){
        size=size*2;
        Esemeny **tmp=new Esemeny *[size];
        for (int i = 0; i < db; ++i) {
            tmp[i]=esemenyek[i];
        }
        delete[] esemenyek;
        esemenyek=tmp;
    }

        esemenyek[db]=uj;
        esemenyek[db]->setId(db + 1);
        db++;

    }

    Naplo(unsigned int usize=10){
        esemenyek=new Esemeny * [usize];
        size=usize;
        db=0;
    }
    Esemeny* operator[](unsigned int idx){
        return esemenyek[idx];
    }
    void setEs(unsigned int idx,Esemeny* uj){
        esemenyek[idx]=uj;
    }
    void elemtorol(unsigned int idx){
        delete esemenyek[idx-1];
        for (unsigned int i = idx - 1; i < db - 1; ++i) {
            esemenyek[i] = esemenyek[i + 1];
            esemenyek[i]->setId(i + 1);
        }
        db--;
    }
    ~Naplo(){
        for (unsigned int i = 0; i < db; ++i) {
            delete esemenyek[i];
        }
        delete[] esemenyek;
    }
    void rendez();
    void kirajz();
    void menu();
    void beolvas();
    bool mentes();
    void modosit();
};


#endif //NAPTAR_NAPLO_H
