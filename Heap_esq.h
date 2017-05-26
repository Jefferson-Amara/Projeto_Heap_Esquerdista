/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heap_esq.h
 * Author: amara
 *
 * Created on 26 de Maio de 2017, 18:49
 */

#ifndef HEAP_ESQ_H
#define HEAP_ESQ_H

class Heap_esq
{
    private:
        no* H;
        int calculaDist(no* n);
        void troca(no* H1, no* H2);
        int menor(int a, int b);
    public:
        Heap_esq();
        no* criaHeap(int v);
        void remove(int v);
        void insere(int v);
        no* uniaoHeap(no* H1, no* H2);        
        ~Heap_esq();
}

#endif /* HEAP_ESQ_H */
