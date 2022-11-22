#include "Midia.h"
#include <iostream>
#include <string>
#include <vector>
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
void Midia::setAno(int ano){
    this->ano = ano;
}
void Midia::setGenero(string genero){
    this->genero = genero;
}
string Midia::getArtista(){
    return artista;
}
string Midia::getTitulo(){
    return titulo;
}
int Midia::getAno(){
    return ano;
}
string Midia::getGenero(){
    return genero;
}
void Midia::printFaixas(){
    for(int i = 0; i < nFaixas; i++){
        cout << '\t' << faixas[i] << endl;
    }
    cout << '\n';
}
void Midia::printKeywords(){
    for(int i = 0; i < nKeyword; i++){
        cout << palavrasChave[i] << " ";
    }
    cout << '\n';
}
void Midia::addFaixa(string faixa){
    faixas.push_back(faixa);
    nFaixas++;
}
void Midia::addKeyword(string keyword){
    palavrasChave.push_back(keyword);
    nKeyword++;
}
void Midia::setFaixas(vector<string> faixas){
    this->faixas = faixas;
    this->nFaixas = faixas.size();
}
void Midia::setPalavrasChave(vector<string> palavrasChave){
    this->palavrasChave = palavrasChave;
    this->nKeyword = palavrasChave.size();
}
vector<string> Midia::getFaixas(){
  return faixas;
}
vector<string> Midia::getPalavrasChave(){
  return palavrasChave;
}