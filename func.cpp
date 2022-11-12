#include <iostream>
#include <string>
#include <vector>
#include "CD.h"
#include "DVD.h"
using namespace std;
//função que interage com o usuario para adicionar um CD na coleção principal de CDs
void addCD(vector<CD> v){
    cout << "Digite o nome do artista:\n";
    string artista;
    cin >> artista;
    cout << "Digite o titulo do CD:\n";
    string titulo;
    cin >> titulo;
    cout << "Deseja adicionar as faixas?\nN para não. ";
    char op;
    cin >> op;
    //se o usuario desejar adicionar as faixas, o programa entra no loop, e se não quiser pula a instrução
    vector<string> faixas;
    if(op == 'n' || op == 'N'){
        string p = "Não ha faixas cadastradas";
        faixas.push_back(p);
    }
    while(op != 'N' || op != 'n'){
        cout << "Digite o nome da faixa:\n";
        string faixa;
        cin >> faixa;
        faixas.push_back(faixa);
        cout << "Deseja adicionar mais faixas?\nN para não. ";
        cin >> op;
    }
    cout << "Digite o ano de lançamento:\n";
    int ano;
    cin >> ano;
    cout << "Digite o genero:\n";
    string genero;
    cin >> genero;
    cout << "Deseja adicionar palavras-chave?\nN para não. ";
    cin >> op;
    //se o usuario desejar adicionar as palavras-chave, o programa entra no loop, e se não quiser pula a instrução
    vector<string> palavrasChave;
    if(op == 'n' || op == 'N'){
        string k = "Não ha palavras-chave disponiveis";
        palavrasChave.push_back(k);
    }
    while(op != 'N' || op != 'n'){
        cout << "Digite a palavra-chave:\n";
        string palavraChave;
        cin >> palavraChave;
        palavrasChave.push_back(palavraChave);
        cout << "Deseja adicionar mais palavras-chave?\nN para não. ";
        cin >> op;
    }
    cout << "Digite a duração do CD:\n";
    int duracao;
    cin >> duracao;
    cout << "Digite o volume do CD:\n";
    int volume;
    cin >> volume;
    cout << "O CD faz parte de uma coletânea?\n0 para não. ";
    bool coletanea;
    cin >> coletanea;
    CD cd(artista, titulo, ano, genero, duracao, volume, coletanea);
    cd.setFaixas(faixas);
    cd.setPalavrasChave(palavrasChave);
    cd.nFaixas = faixas.size();
    cd.nKeyword = palavrasChave.size();
    v.push_back(cd);
}
//função que interage com o usuario para adicionar um DVD na coleção principal de DVDs
void addDVD(vector<DVD> v){
    cout << "Digite o nome do artista:\n";
    string artista;
    getline(cin, artista);
    cout << "Digite o titulo do DVD:\n";
    string titulo;
    getline(cin, titulo);
    cout << "Deseja adicionar as faixas?\nN para não. ";
    char op;
    cin >> op;
    //se o usuario desejar adicionar as faixas, o programa entra no loop, e se não quiser pula a instrução
    vector<string> faixas;
    if(op == 'n' || op == 'N'){
        string p = "Não ha faixas cadastradas";
        faixas.push_back(p);
    }
    while(op != 'N' || op != 'n'){
        cout << "Digite o nome da faixa:\n";
        string faixa;
        getline(cin, faixa);
        faixas.push_back(faixa);
        cout << "Deseja adicionar mais faixas?\nN para não. ";
        cin >> op;
    }
    cout << "Digite o ano de lançamento:\n";
    int ano;
    cin >> ano;
    cout << "Digite o genero:\n";
    string genero;
    cin >> genero;
    cout << "Deseja adicionar palavras-chave?\nN para não. ";
    cin >> op;
    //se o usuario desejar adicionar as palavras-chave, o programa entra no loop, e se não quiser pula a instrução
    vector<string> palavrasChave;
    if(op == 'n' || op == 'N'){
        string k = "Não ha palavras-chave disponiveis";
        palavrasChave.push_back(k);
    }
    while(op != 'N' || op != 'n'){
        cout << "Digite a palavra-chave:\n";
        string palavraChave;
        cin >> palavraChave;
        palavrasChave.push_back(palavraChave);
        cout << "Deseja adicionar mais palavras-chave?\nN para não. ";
        cin >> op;
    }
    cout << "Digite o formato de audio do DVD:\n";
    string formatoAudio;
    cin >> formatoAudio;
    cout << "Digite o formato de video do DVD:\n";
    string formatoVideo;
    cin >> formatoVideo;
    DVD dvd(artista, titulo, ano, genero, formatoAudio, formatoVideo);
    dvd.setFaixas(faixas);
    dvd.setPalavrasChave(palavrasChave);
    dvd.nFaixas = faixas.size();
    dvd.nKeyword = palavrasChave.size();
    v.push_back(dvd);
}