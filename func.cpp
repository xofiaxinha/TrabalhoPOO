#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "CD.h"
#include "DVD.h"
#include "func.h"
using namespace std;

void cd::add(vector<CD> *v){
  cin.ignore(); //limpa o buffer do cin
  string artista;
  cout << "Digite o nome do artista:\n";
  getline(cin, artista); //pega a string artista
  string titulo;
  cout << "Digite o titulo do CD:\n";
  getline(cin, titulo); //pega a string texto
  
  cout << "Deseja adicionar as faixas?\nN para não. ";
  char op;
  cin >> op;
  //se o usuario desejar adicionar as faixas, o programa entra no loop, e se não quiser pula a instrução
  vector<string> faixas;
  if(op == 'n' || op == 'N'){
      string p = "Não ha faixas cadastradas";
      cout << p << '\n'; // mostra que não há faixas
      faixas.push_back(p);}
  cin.ignore(); // limpa o buffer
  while(op != 'N' && op != 'n'){ // enquanto op não for não, insere faixa
      cout << "Digite o nome da faixa:\n";
      string faixa;
      getline(cin, faixa);
      faixas.push_back(faixa);
      cout << "Deseja adicionar mais faixas?\nN para não. ";
      cin >> op;
      cin.ignore(); //limpa o buffer do cin
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
      cout << k << '\n';
      palavrasChave.push_back(k);
    }
  cin.ignore();
  while(op != 'N' && op != 'n'){
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
  
  //declara um objeto do tipo CD
  CD cd(artista, titulo, ano, genero, duracao, volume, coletanea);
  cd.setFaixas(faixas); // pôe as faixas
  cd.setPalavrasChave(palavrasChave); // pôe as palavras-chave
  cd.nFaixas = faixas.size();
  cd.nKeyword = palavrasChave.size();
  
  v->push_back(cd); //empurra o novo cd no vetor
  //mensagem de confirmação
  cout << "- CD adicionado com sucesso!\n";
}
void cd::remove(vector<CD> *v){
    cin.ignore();
    int tam = v->size();
    cout << "Digite o nome do artista:\n";
    string artista;
    getline(cin, artista);
    cout << "Digite o titulo do CD:\n";
    string titulo;
    getline(cin, titulo);
  
    for(int i = 0; i < tam; i++){
        if(v[i].getArtista() == artista && v[i].getTitulo() == titulo){
            cout << "\tCD a ser removido:\n"
                << "=======================================\n";
            v[i].print();
            for(int j = i; j < v->size(); j++){
                v[j] = v[j+1];
            }
            v->pop_back();
            cout << "CD removido com sucesso!\n";
            break;
            return;
        }
    }cout << "CD nao encontrado.\n";
} // ajeitar
void cd::editar(vector<CD> *cd){
    cin.ignore();
    cout << "Digite o nome do CD que deseja editar:\n";
    string titulo;
    getline(cin, titulo);
    for(int i = 0; i<cd->size(); i++){
        if(cd[i]->getTitulo() == titulo){
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
                cin.ignore();
                cout << "Digite a palavra-chave:\n";
                string palavraChave;
                cin >> palavraChave;
                palavrasChave.push_back(palavraChave);
                cout << "Deseja adicionar mais palavras-chave?\nN para não. ";
                cin >> op;
            }
            cd[i]->setPalavrasChave(palavrasChave);
            cd[i]->print();
            return;
        }
    }
} // ajeitar
void cd::lista(vector<CD> cd){
    cout << "Lista de CDs:\n";
    cout << "=======================================\n";
    for(int i = 0; i < cd.size(); i++){
        cout << cd[i].getTitulo() << " por " << cd[i].getArtista() << '\n';
    }
}
vector<CD> cd::lerArq(){
  ifstream f;
  f.open("CD.txt", ios::in);
  if(!f.is_open()) {throw runtime_error("ERRO\n");}

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
void cd::paraArq(vector<CD> cd){
    ofstream f;
    f.open("CD.txt", ios::out);
    if(!f.is_open()) {throw runtime_error("ERRO\n");}
    for(int i = 0; i < cd.size(); i++){
        f << cd[i].getArtista() << '\n';
        f << cd[i].getTitulo() << '\n';
        f << cd[i].getAno() << '\n';
        f << cd[i].getGenero() << '\n';
        f << cd[i].getDuracao() << '\n';
        f << cd[i].getVolume() << '\n';
        f << cd[i].getColetanea() << '\n';
        f << cd[i].nFaixas << '\n';
        vector<string> faixas = cd[i].getFaixas();
        f << cd[i].nFaixas << '\n';
        for(int j = 0; j < cd[i].nFaixas; j++){
            f << faixas[j] << '\n';
        }
        vector<string> keywords = cd[i].getKeywords();
        f << cd[i].nKeyword << '\n';
        for(int j = 0; j < cd[i].nKeyword; j++){
            f << keywords[j] << '\n';
        }
    }
    f.close();
}
void cd::mostrarOrdenadoData(vector<CD> v){
  vector<CD> auxiliar = v;
  if(!(v.size() >= 2)) return;
  for(int i=0; i<auxiliar.size(); i++){
    int a = i;
    for(int j = i+1; j<auxiliar.size(); j++){
      if(auxiliar[j].getAno() < auxiliar[a].getAno()) a = j;
    }
    CD obj = auxiliar[i];
    auxiliar[i] = auxiliar[a];
    auxiliar[a] = obj;
  }

  for(int i=0; i<auxiliar.size(); i++){
    auxiliar[i].print();
  }
} // ajeitar
namespace dvd{
void addDVD(vector<DVD> *v){
  cin.ignore(); //limpa o buffer do cin
  string artista;
  cout << "Digite o nome do artista:\n";
  getline(cin, artista); //pega a string artista
  string titulo;
  cout << "Digite o titulo do CD:\n";
  getline(cin, titulo); //pega a string texto
  
  cout << "Deseja adicionar as faixas?\nN para não. ";
  char op;
  cin >> op;
  //se o usuario desejar adicionar as faixas, o programa entra no loop, e se não quiser pula a instrução
  vector<string> faixas;
  if(op == 'n' || op == 'N'){
      string p = "Não ha faixas cadastradas";
      cout << p << '\n'; // mostra que não há faixas
      faixas.push_back(p);}
  cin.ignore(); // limpa o buffer
  while(op != 'N' && op != 'n'){ // enquanto op não for não, insere faixa
      cout << "Digite o nome da faixa:\n";
      string faixa;
      getline(cin, faixa);
      faixas.push_back(faixa);
      cout << "Deseja adicionar mais faixas?\nN para não. ";
      cin >> op;
      cin.ignore(); //limpa o buffer do cin
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
      cout << k << '\n';
      palavrasChave.push_back(k);
    }
  cin.ignore();
  while(op != 'N' && op != 'n'){
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
    v->push_back(dvd);
}
void removeDVD(vector<DVD> *v){
    cin.ignore();
    cout << "Digite o nome do artista:\n";
    string artista;
    getline(cin, artista);
    cout << "Digite o titulo do DVD:\n";
    string titulo;
    getline(cin, titulo);
    for(int i = 0; i < v->size(); i++){
        if(v[i]->getArtista() == artista && v[i]->getTitulo() == titulo){
            cout << "\tDVD a ser removido:\n"
                << "=======================================\n";
            v[i]->print();
            for(int j = i; j < v->size(); j++){
                v[j] = v[j+1];
            }
            v->pop_back();
            cout << "DVD removido com sucesso!\n";
            return;
        }
    }cout << "DVD não encontrado!\n";
} // ajeitar
void editarDVD(vector<DVD> *dvd){
    cin.ignore();
    cout << "Digite o nome do DVD que deseja editar:\n";
    string titulo;
    getline(cin, titulo);
    for(int i = 0; i<dvd->size(); i++){
        if(dvd[i]->getTitulo() == titulo){
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
                dvd[i]->setFormatoAudio(formatoAudio);
            }else if(op == 2){
                cout << "Digite o novo formato de video:\n";
                string formatoVideo;
                cin >> formatoVideo;
                dvd[i]->setFormatoTela(formatoVideo);
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
                    cin.ignore();
                    cout << "Digite a palavra-chave:\n";
                    string palavraChave;
                    cin >> palavraChave;
                    palavrasChave.push_back(palavraChave);
                    cout << "Deseja adicionar mais palavras-chave?\nN para não. ";
                    cin >> op;
                }
                dvd[i]->setPalavrasChave(palavrasChave);
            }
            dvd[i]->print();
            return;
        }
    }
} // ajeitar
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
vector<DVD> lerArqDVD(){
  ifstream f;
  f.open("DVD.txt", ios::in);
  if(!f.is_open()) {throw runtime_error("ERRO\n");}

  string artista;
  string titulo;
  int ano;
  string genero;
  string formatoAudio;
  string formatoTela;
  vector<DVD> dvd;
  string sAno; // string auxiliar pra usar stringstream
  while(!f.eof()){
    getline(f, artista);
    getline(f, titulo);
    getline(f, sAno);        //bloco que
      stringstream sa(sAno);  //le um int
      sa >> ano;               //para ano
    getline(f, genero);
    getline(f, formatoAudio);
    getline(f, formatoTela);
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
    DVD aux(artista, titulo, ano, genero, formatoAudio, formatoTela);
    aux.setPalavrasChave(palavrasChave);
    aux.setFaixas(faixas);
    dvd.push_back(aux);
    }
    f.close();
    return dvd;
}
void paraArqDVD(vector<DVD> dvd){
    ofstream f;
    f.open("DVD.txt", ios::out);
    if(!f.is_open()) {throw runtime_error("ERRO\n");}
    for(int i = 0; i < dvd.size(); i++){
        f << dvd[i].getArtista() << '\n';
        f << dvd[i].getTitulo() << '\n';
        f << dvd[i].getAno() << '\n';
        f << dvd[i].getGenero() << '\n';
        f << dvd[i].getFormatoAudio() << '\n';
        f << dvd[i].getFormatoTela() << '\n';
        vector<string> faixas = dvd[i].getFaixas();
        f << dvd[i].nFaixas << '\n';
        for(int j = 0; j < dvd[i].nFaixas; j++){
            f << faixas[j] << '\n';
        }
        vector<string> keywords = dvd[i].getKeywords();
        f << dvd[i].nKeyword << '\n';
        for(int j = 0; j < dvd[i].nKeyword; j++){
            f << keywords[j] << '\n';
        }
    }
    f.close();

}
}