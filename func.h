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
void add(vector<DVD> *v);
void remove(vector<DVD> *v);
void lista(vector<DVD> dvd);
void editar(vector<DVD> *dvd);
vector<DVD> lerArq();
void paraArq(vector<DVD> dvd);
void mostrarOrdenadoData(vector<DVD> v);
}
void mostrarOrdenadoData(vector<CD> v, vector<DVD> d);
void mostrarFaixasEmComum(CD cd, DVD dvd);
void mostrarPorGenero(vector<CD> cd, vector<DVD> dvd);
void exibirKeywords(vector<CD> cd, vector<DVD> dvd);