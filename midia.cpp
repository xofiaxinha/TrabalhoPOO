#include "midia.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

Midia::Midia(string artista, string titulo, int ano, string genero){
    this->artista = artista;
    this->titulo = titulo;
    this->ano = ano;
    this->genero = genero;
}
void Midia::setArtista(string artista){
    this->artista = artista;
}
void Midia::setTitulo(string titulo){
    this->titulo = titulo;
}
void Midia::setFaixas(string *faixas){
    this->faixas = faixas;
}
void Midia::setAno(int ano){
    this->ano = ano;
}
void Midia::setGenero(string genero){
    this->genero = genero;
}
void Midia::setPalavrasChave(string *palavrasChave){
    this->palavrasChave = palavrasChave;
}
void Midia::addFaixa(string faixa){
    faixas = (string*) realloc(faixas, sizeof(string) * (nFaixas + 1));
    faixas[nFaixas] = faixa;
    nFaixas++;
}
void Midia::addPalavraChave(string palavraChave){
    palavrasChave = (string *) realloc(palavrasChave, sizeof(string) * (nKeyword + 1));
    palavrasChave[nKeyword] = palavraChave;
    nKeyword++;
}
string Midia::getArtista(){
    return artista;
}
string Midia::getTitulo(){
    return titulo;
}
string* Midia::getFaixas(){
    return faixas;
}
int Midia::getAno(){
    return ano;
}
string Midia::getGenero(){
    return genero;
}
string *Midia::getPalavrasChave(){
    return palavrasChave;
}