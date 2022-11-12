#include <iostream>
#include <string>
#include <vector>
#include "DVD.h"
using namespace std;

DVD::DVD(string artista, string titulo, int ano, string genero, string formatoAudio, string formatoTela, vector<string> legendas):
        Midia(artista, titulo, ano, genero){
    setFormatoAudio(formatoAudio);
    setFormatoTela(formatoTela);
    setLegendas(legendas);
}
void DVD::setFormatoAudio(string formatoAudio){
    this->formatoAudio = formatoAudio;
}
void DVD::setFormatoTela(string formatoTela){
    this->formatoTela = formatoTela;
}
void DVD::setLegendas(vector<string> legendas){
    this->legendas = legendas;
}
string DVD::getFormatoAudio(){
    return formatoAudio;
}
string DVD::getFormatoTela(){
    return formatoTela;
}
vector<string> DVD::getLegendas(){
    return legendas;
}
void DVD::print(){
  cout << getFormatoTela();
}