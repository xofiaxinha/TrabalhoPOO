#include <iostream>
#include <string>
#include "CD.h"
using namespace std;

CD::CD(string artista, string titulo, int ano, string genero, int duracao, int volume, bool coletanea):
        Midia(artista, titulo, ano, genero){
    this->duracao = duracao;
    this->volume = volume;
    this->coletanea = coletanea;
}
void CD::setDuracao(int duracao){
    this->duracao = duracao;
}
void CD::setVolume(int volume){
    this->volume = volume;
}
void CD::setColetanea(bool coletanea){
    this->coletanea = coletanea;
}
int CD::getDuracao(){
    return duracao;
}
int CD::getVolume(){
    return volume;
}
bool CD::getColetanea(){
    return coletanea;
}