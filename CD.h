#pragma once
#include <iostream>
#include <string>
#include "Midia.h"
using namespace std;

class CD: public Midia{
    private:
        int duracao;
        int volume;
        bool coletanea; //true se fizer parte de uma coletânea
    public:
        CD(string artista, string titulo, int ano, string genero, int duracao, int volume, bool coletanea);
        void setDuracao(int duracao);
        void setVolume(int volume);
        void setColetanea(bool coletanea);
        int getDuracao();
        int getVolume();
        bool getColetanea();
        void print();
};