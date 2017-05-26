/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Heap_esq.c
 * Author: amara
 * 
 * Created on 26 de Maio de 2017, 18:49
 */

#include "Heap_esq.h"
#include "no.h"
//Construtor
Heap_esq::Heap_esq()
{
    
}
/*Calcula distancia de um nó até sua folha mais distante
Se o nó já for folha, retorna zero
Senão retorna 1+menor distância entre os filhos esq e dir*/
int Heap_esq::calculaDist(no* n)
{
    if(n==NULL)
        return 0;
    else
        return(1+menor(calculaDist(n->getEsq(),calculaDist(n->getDir()))));
}
/*Realiza a troca entre dois nós*/
void Heap_esq::troca(no* H1, no* H2)
{
    no* aux=H1;
    H1=H2;
    H2=aux;
}
/*Devolve o menor entre dois numeros*/
int Heap_esq::menor(int a, int b)
{
    if (a<b)
        return a;
    else
        return b;
}
/*Cria e retorna um novo heap, que, basicamente, é um novo nó com filhos esq e dir = NULL*/
no* Heap_esq::criaHeap(int v)
{
    no* aux = new no();
    aux->setEsq(NULL);
    aux->setDir(NULL);
    aux->setVal(v);
    aux->setMarca(1);
    
    return aux;    
}
/*Faz a uniao entre dois heaps*/
no* Heap_esq::uniaoHeap(no* H1, no* H2)
{
    if(H1==NULL)//Se dos heaps é NULL, retorna o outro
        return H2;
    if(H2==NULL)
        return H1;
    if(H1->getVal()>H2->getVal())//Queremos fixar H1 como menor heap, por isso, se H1<H2, trocamos
        troca(H1,H2);
    if(H1->getEsq()==NULL)//Se o filho esq do menor heap for NULL, o setamos com a maior heap
        H1->setEsq(H2);
    else//Caso não seja exceção o caso, caimos na regra
    {
        no* H3 = new no();//Criamos um novo heap
        H3=H1->getDir();//o no criado recebe a direita do menor heap
        H3=uniaoHeap(H3,H2);//fazemos a uniao do filho dir do menor heap com o heap maior (H2)
        H1->setDir(H3);//a direita do menor heap recebe o resultado dessa uniao
        H1->getEsq()->setMarca(calculaDist(H1->getEsq()));//atualiza a marca do filho esq
        H1->getDir()->setMarca(calculaDist(H1->getDir()));//atualiza a marca do filho dir
        if(H1->getEsq()->getMarca()<H1->getDir()->getMarca())//se nao é um heap esquerdista
            troca(H1->getDir(),H1->getEsq());//faz uma rotação 
        H1->setMarca(1+calculaDist(H1));//Atualiza a dis geral do heap
        return H1;//retorna o min heap esquerdista resultante
    }
}