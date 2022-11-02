#include <iostream>
#include <string>
using namespace std;

class Midia{
    private:
        string artista;
        string titulo;
        string *faixas; //vetor de string para armazenar as faixas
        int nFaixas; //numero de faixas
        int ano;
        string genero;
        string *palavrasChave; //ponteiro de string para armazenar as palavras chave
        int nKeyword; //número de palavras-chave
    public:
        Midia(string artista, string titulo, int ano, string genero);
        void setArtista(string artista);
        void setTitulo(string titulo);
        void setFaixas(string *faixas);
        void setAno(int ano);
        void setGenero(string genero);
        void setPalavrasChave(string *palavrasChave);
        void addFaixa(string faixa);
        void addPalavraChave(string palavraChave);
        string getArtista();
        string getTitulo();
        string *getFaixas();
        int getAno();
        string getGenero();
        string *getPalavrasChave();
};