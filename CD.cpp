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
void CD::print(){
    cout << "Artista: " << getArtista() << '\n';
    cout << "Titulo: " << getTitulo() << '\n';
    cout << "Faixas: \n";
    this->printFaixas();
    cout << "Ano: " << getAno() << '\n';
    cout << "Genero: " << getGenero() << '\n';
    cout << "Duracao: " << getDuracao() << '\n';
    cout << "Volume: " << getVolume() << '\n';
    if(getColetanea()){
        cout << "Coletanea: Sim" << '\n';}
    else{
        cout << "Coletanea: Nao" << '\n';
    }
    cout << "Palavras-chave: \n";
    this->printKeywords();
}