#include <iostream>
#include <string>
#include <vector>
#include "midia.h"
using namespace std;

class DVD: public Midia{
    private:
        string formatoAudio;
        string formatoTela;
    public:
        DVD(string artista, string titulo, int ano, string genero, string formatoAudio, string formatoTela);
        void setFormatoAudio(string formatoAudio);
        void setFormatoTela(string formatoTela);
        string getFormatoAudio();
        string getFormatoTela();
        void print();
};