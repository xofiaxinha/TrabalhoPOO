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
    cout << "Artista: " << getArtista() << endl;
    cout << "Titulo: " << getTitulo() << endl;
    cout << "Ano: " << getAno() << endl;
    cout << "Genero: " << getGenero() << endl;
    cout << "Formato de Audio: " << getFormatoAudio() << endl;
    cout << "Formato de Tela: " << getFormatoTela() << endl;
}