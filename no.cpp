
#include "no.h"

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
no::no()
{
    esq=NULL;
    dir=NULL;
}
void no::setEsq(no* n)
{
    esq=n;
}
void no::setDir(no* n)
{
    dir=n;
}
void no::setVal(int v)
{
    val=v;
}
void no::setMarca(int m)
{
    marca=m;
}

no* no::getEsq()
{
    return esq;
}
no* no::getDir()
{
    return dir;
}
int no::getVal()
{
    return val;
}
int no::getMarca()
{
    return marca;
}
no::~no()
{

}