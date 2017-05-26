/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   no.h
 * Author: amara
 *
 * Created on 26 de Maio de 2017, 17:36
 */

#ifndef NO_H
#define NO_H

class no
{
    private:
        no* esq;
        no* dir;
        int valor;
        int marca;
        
    public:
        no();
        void setEsq(no* n);
        void setDir(no* n);
        void setVal(int v);
        void setMarca(int m);
        no* getEsq();
        no* getDir();
        int getVal();
        int getMarca();
        ~no();    
};

#endif /* NO_H */

