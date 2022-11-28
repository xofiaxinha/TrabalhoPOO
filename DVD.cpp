#include <iostream>
#include <string>
#include <vector>
#include "DVD.h"
using namespace std;

DVD::DVD(string artista, string titulo, int ano, string genero, string formatoAudio, string formatoTela):
        Midia(artista, titulo, ano, genero){
    setFormatoAudio(formatoAudio);
    setFormatoTela(formatoTela);
}
void DVD::setFormatoAudio(string formatoAudio){
    this->formatoAudio = formatoAudio;
}
void DVD::setFormatoTela(string formatoTela){
    this->formatoTela = formatoTela;
}
string DVD::getFormatoAudio(){
    return formatoAudio;
}
string DVD::getFormatoTela(){
    return formatoTela;
}
void DVD::print(){
    cout << "Artista: " << getArtista() << '\n';
    cout << "Titulo: " << getTitulo() << '\n';
    cout << "Faixas: \n";
    this->printFaixas();
    cout << "Ano: " << getAno() << '\n';
    cout << "Genero: " << getGenero() << '\n';
    cout << "Formato de Audio: " << getFormatoAudio() << '\n';
    cout << "Formato de Tela: " << getFormatoTela() << '\n';
    cout << "Palavras-chave: \n";
    this->printKeywords();
}