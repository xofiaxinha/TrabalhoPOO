#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Midia{
    private:
        string artista;
        string titulo;
        vector<string> faixas; //vetor de string para armazenar as faixas
        int ano;
        string genero;
        vector<string> palavrasChave; //ponteiro de string para armazenar as palavras chave
    public:
        int nFaixas; //numero de faixas
        int nKeyword; //número de palavras-chave
        Midia(string artista, string titulo, int ano, string genero);
        void setArtista(string artista);
        void setTitulo(string titulo);
        void setAno(int ano);
        void setGenero(string genero);
        void setFaixas(vector<string> faixas);
        void setPalavrasChave(vector<string> palavrasChave);
        string getArtista();
        string getTitulo();
        int getAno();
        string getGenero();
        void printFaixas();
        void prinntKeywords();
        virtual void addFaixa(string);
        virtual void addKeyword(string);
        virtual void print() = 0;
};