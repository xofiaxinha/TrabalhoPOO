#include <iostream>
#include <string>
#include <vector>
#include "midia.h"
using namespace std;

class DVD: public Midia{
    private:
        string formatoAudio;
        string formatoTela;
        vector<string> legendas;
    public:
        DVD(string artista, string titulo, int ano, string genero, string formatoAudio, string formatoTela, vector<string> legendas);
        void setFormatoAudio(string formatoAudio);
        void setFormatoTela(string formatoTela);
        void setLegendas(vector<string> legendas);
        string getFormatoAudio();
        string getFormatoTela();
        vector<string> getLegendas();
};