#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
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
void removeCD(vector<CD> v){
    cout << "Digite o nome do artista:\n";
    string artista;
    getline(cin, artista);
    cout << "Digite o titulo do CD:\n";
    string titulo;
    getline(cin, titulo);
    for(int i = 0; i < v.size(); i++){
        if(v[i].getArtista() == artista && v[i].getTitulo() == titulo){
            cout << "\tCD a ser removido:\n"
                << "=======================================\n";
            v[i].print();
            for(int j = i; j < v.size(); j++){
                v[j] = v[j+1];
            }
            v.pop_back();
            break;
        }
    }cout << "CD removido com sucesso!\n";
}
void removeDVD(vector<DVD> v){
    cout << "Digite o nome do artista:\n";
    string artista;
    getline(cin, artista);
    cout << "Digite o titulo do DVD:\n";
    string titulo;
    getline(cin, titulo);
    for(int i = 0; i < v.size(); i++){
        if(v[i].getArtista() == artista && v[i].getTitulo() == titulo){
            cout << "\tDVD a ser removido:\n"
                << "=======================================\n";
            v[i].print();
            for(int j = i; j < v.size(); j++){
                v[j] = v[j+1];
            }
            v.pop_back();
            cout << "DVD removido com sucesso!\n";
            return;
        }
    }cout << "DVD não encontrado!\n";
}
void listaCDs(vector<CD> cd){
    cout << "Lista de CDs:\n";
    cout << "=======================================\n";
    for(int i = 0; i < cd.size(); i++){
        cout << cd[i].getTitulo() << " por " << cd[i].getArtista() << '\n';
    }
}
void listaDVDs(vector<DVD> dvd){
    cout << "Lista de DVDs:\n";
    cout << "=======================================\n";
    for(int i = 0; i < dvd.size(); i++){
        cout << dvd[i].getTitulo() << " por " << dvd[i].getArtista() << '\n';
    }
}
void editarDVD(vector<DVD> dvd){
    cout << "Digite o nome do DVD que deseja editar:\n";
    string titulo;
    getline(cin, titulo);
    for(int i = 0; i<dvd.size(); i++){
        if(dvd[i].getTitulo() == titulo){
            ///so eh possivel editar o formato de audio e video, e as palavras-chave
            cout << "O que deseja editar?\n"
                << "1 - Formato de audio\n"
                << "2 - Formato de video\n"
                << "3 - Palavras-chave\n";
            int op;
            cin >> op;
            if(op == 1){
                cout << "Digite o novo formato de audio:\n";
                string formatoAudio;
                cin >> formatoAudio;
                dvd[i].setFormatoAudio(formatoAudio);
            }else if(op == 2){
                cout << "Digite o novo formato de video:\n";
                string formatoVideo;
                cin >> formatoVideo;
                dvd[i].setFormatoTela(formatoVideo);
            }else if(op == 3){
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
                dvd[i].setPalavrasChave(palavrasChave);
            }
            dvd[i].print();
            return;
        }
    }
}
void editarCD(vector<CD> cd){
    cout << "Digite o nome do CD que deseja editar:\n";
    string titulo;
    getline(cin, titulo);
    for(int i = 0; i<cd.size(); i++){
        if(cd[i].getTitulo() == titulo){
            ///so eh possivel editar as palavras-chave
            cout << "Deseja adicionar palavras-chave?\nN para não. ";
            int op;
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
            cd[i].setPalavrasChave(palavrasChave);
            cd[i].print();
            return;
        }
    }
}
vector<CD> lerArqCD(){
  ifstream f;
  f.open("CD.txt", ios::in);
  if(!f.is_open()) {cout << "ERRO\n";
    return;}

  string artista;
  string titulo;
  int ano;
  string genero;
  int duracao;
  int volume;
  bool coletanea;
    vector<CD> cd;
  string sAno, sDuracao, sVolume, sColetanea; // string auxiliar pra usar stringstream
  while(!f.eof()){
    getline(f, artista);
    getline(f, titulo);
    getline(f, sAno);        //bloco que
      stringstream sa(sAno);  //le um int
      sa >> ano;               //para ano
    getline(f, genero);
      getline(f, sDuracao);        //bloco que
      stringstream sd(sDuracao);  //le um int
      sd >> duracao;           //para duracao

      getline(f, sVolume);        //bloco que
      stringstream sv(sVolume);  //le um int
      sv >> volume;               //para volume

     getline(f, sColetanea);        //bloco que
      stringstream sc(sColetanea);  //le um bool
      sc >> coletanea;         //para coletanea
    string sPalavrasChave;
    getline(f, sPalavrasChave);
    vector<string> palavrasChave;
    stringstream sp(sPalavrasChave);
    int nPalavrasChave;
    sp >> nPalavrasChave;
    for(int i = 0; i < nPalavrasChave; i++){
        getline(f, sPalavrasChave);
        palavrasChave.push_back(sPalavrasChave);
    }
    string sFaixas;
    getline(f, sFaixas);
    vector<string> faixas;
    stringstream sf(sFaixas);
    int nFaixas;
    sf >> nFaixas;
    for(int i = 0; i < nFaixas; i++){
        getline(f, sFaixas);
        faixas.push_back(sFaixas);
    }
    cout << "Arquivo lido!";
    CD aux(artista, titulo, ano, genero, duracao, volume, coletanea);
    aux.setPalavrasChave(palavrasChave);
    aux.setFaixas(faixas);
    cd.push_back(aux);
    }
    f.close();
    return cd;
}
void paraArqCD(vector<CD> cd){
    ofstream f;
    f.open("CD.txt", ios::out);
    if(!f.is_open()) {cout << "ERRO\n";
        return;}
    for(int i = 0; i < cd.size(); i++){
        f << cd[i].getArtista() << '\n';
        f << cd[i].getTitulo() << '\n';
        f << cd[i].getAno() << '\n';
        f << cd[i].getGenero() << '\n';
        f << cd[i].getDuracao() << '\n';
        f << cd[i].getVolume() << '\n';
        f << cd[i].getColetanea() << '\n';
        f << cd[i].nFaixas << '\n';
        for(int j = 0; j < cd[i].nFaixas; j++){
            f << cd[i].faixas[j] << '\n';
        }
        f << cd[i].nKeywords << '\n';
        for(int j = 0; j < cd[i].nKeywords; j++){
            f << cd[i].keywords[j] << '\n';
        }
    }
    f.close();
}
