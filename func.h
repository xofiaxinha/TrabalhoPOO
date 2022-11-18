#pragma once
#include <iostream>
#include <vector>
#include "CD.h"
#include "DVD.h"
using namespace std;
namespace cd{
void add(vector<CD> *v);
void remove(vector<CD> *v);
void lista(vector<CD> cd);
void editar(vector<CD> *cd);
vector<CD> lerArq();
void paraArq(vector<CD> cd);
void mostrarOrdenadoData(vector<CD> v);
}
namespace dvd{
void addDVD(vector<DVD> *v);
void removeDVD(vector<DVD> *v);
void listaDVDs(vector<DVD> dvd);
void editarDVD(vector<DVD> *dvd);
vector<DVD> lerArqDVD();
void paraArqDVD(vector<DVD> dvd);
}