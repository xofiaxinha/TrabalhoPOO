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

//funcoes de cd
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
    int i = 0;
    for(vector<CD>::iterator it = v->begin(); it != v->end() ; it++){
        i++;
        CD auxiliar = *it;
        if(auxiliar.getArtista() == artista && auxiliar.getTitulo() == titulo){
            cout << "\tCD a ser removido:\n"
                << "=======================================\n";
            auxiliar.print();
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
//funcoes auxiliares pra editar
void editarArtista(Midia *cd){
    cin.ignore();
    cout << "Digite o novo nome do artista:\n";
    string artista;
    getline(cin, artista);
    cd->setArtista(artista);
}
void editarTitulo(Midia *cd){
    cin.ignore();
    cout << "Digite o novo titulo do CD:\n";
    string titulo;
    getline(cin, titulo);
    cd->setTitulo(titulo);
}
void editarFaixas(Midia *cd){
    cin.ignore();
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
    cd->setFaixas(faixas);
}
void editarAno(Midia *cd){
    cin.ignore();
    cout << "Digite o novo ano de lançamento:\n";
    int ano;
    cin >> ano;
    cd->setAno(ano);
}
void editarGenero(Midia *cd){
    cin.ignore();
    cout << "Digite o novo genero:\n";
    string genero;
    cin >> genero;
    cd->setGenero(genero);
}
void editarPalavrasChave(Midia *cd){
    cin.ignore();
    cout << "Deseja adicionar palavras-chave?\nN para não. ";
    char op;
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
    cd->setPalavrasChave(palavrasChave);
}
void editarDuracao(CD *cd){
    cin.ignore();
    cout << "Digite a nova duração do CD:\n";
    int duracao;
    cin >> duracao;
    cd->setDuracao(duracao);
}
void editarVolume(CD *cd){
    cin.ignore();
    cout << "Digite o novo volume do CD:\n";
    int volume;
    cin >> volume;
    cd->setVolume(volume);
}
void editarColetanea(CD *cd){
    cin.ignore();
    cout << "Digite o novo valor da coletanea:\n";
    bool coletanea;
    cin >> coletanea;
    cd->setColetanea(coletanea);
}
void cd::editar(vector<CD> *cd){
    cin.ignore();
    cout << "Digite o nome do CD que deseja editar:\n";
    string titulo;
    getline(cin, titulo);
    for(vector<CD>::iterator it = cd->begin(); it != cd->end(); it++){
        CD auxiliar = *it;
        if(auxiliar.getTitulo() == titulo){
            cout << "Escolha o que você deseja editar:\n"
                << "1 - Artista\n"
                << "2 - Titulo\n"
                << "3 - Faixas\n"
                << "4 - Ano de lançamento\n"
                << "5 - Genero\n"
                << "6 - Palavras-chave\n"
                << "7 - Duração\n"
                << "8 - Volume\n"
                << "9 - Coletânea\n";
            int op;
            cin >> op;
            cin.ignore();
            switch(op){
                case 1:
                    editarArtista(&auxiliar);
                    break;
                case 2:
                    editarTitulo(&auxiliar);
                    break;
                case 3:
                    editarFaixas(&auxiliar);
                    break;
                case 4:
                    editarAno(&auxiliar);
                    break;
                case 5:
                    editarGenero(&auxiliar);
                    break;
                case 6:
                    editarPalavrasChave(&auxiliar);
                    break;
                case 7:
                    editarDuracao(&auxiliar);
                    break;
                case 8:
                    editarVolume(&auxiliar);
                    break;
                case 9:
                    editarColetanea(&auxiliar);
                    break;
                default:
                    cout << "Opção inválida.\n";
                    break;
            }
            *it = auxiliar;
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
        vector<string> keywords = cd[i].getPalavrasChave();
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

//funcoes de dvd
void dvd::add(vector<DVD> *v){
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
  cout << "Digite o formato de audio:\n";
    string audio;
    cin >> audio;
    cout << "Digite o formato de video:\n";
    string video;
    cin >> video;
    DVD aux(artista, titulo, ano, genero, audio, video);
    aux.setPalavrasChave(palavrasChave);
    aux.setFaixas(faixas);
    v->push_back(aux);
    cout << "DVD adicionado com sucesso!\n";
}
void dvd::remove(vector<DVD> *v){
    cin.ignore();
    int tam = v->size();
    cout << "Digite o nome do artista:\n";
    string artista;
    getline(cin, artista);
    cout << "Digite o titulo do DVD:\n";
    string titulo;
    getline(cin, titulo);
    int i = 0;
    for(vector<DVD>::iterator it = v->begin(); it != v->end() ; it++){
        i++;
        DVD auxiliar = *it;
        if(auxiliar.getArtista() == artista && auxiliar.getTitulo() == titulo){
            cout << "\tDVD a ser removido:\n"
                << "=======================================\n";
            auxiliar.print();
            for(int j = i; j < v->size(); j++){
                v[j] = v[j+1];
            }
            v->pop_back();
            cout << "DVD removido com sucesso!\n";
            break;
            return;
        }
    }cout << "DVD nao encontrado.\n";
}
void dvd::lista(vector<DVD> dvd){
    cout << "Lista de DVDs:\n";
    cout << "=======================================\n";
    for(int i = 0; i < dvd.size(); i++){
        cout << dvd[i].getTitulo() << " por " << dvd[i].getArtista() << '\n';
    }
}
void editarFormatoAudio(DVD *dvd){
    cin.ignore();
    cout << "Digite o novo formato de audio:\n";
    string audio;
    getline(cin, audio);
    dvd->setFormatoAudio(audio);
    cout << "Formato de audio alterado com sucesso!\n";
}
void editarFormatoVideo(DVD *dvd){
    cin.ignore();
    cout << "Digite o novo formato de tela:\n";
    string tela;
    getline(cin, tela);
    dvd->setFormatoTela(tela);
    cout << "Formato de tela alterado com sucesso!\n";
}
void dvd::editar(vector<DVD> *dvd){
    cin.ignore();
    cout << "Digite o nome do DVD que deseja editar:\n";
    string titulo;
    getline(cin, titulo);
    for(vector<DVD>::iterator it = dvd->begin(); it != dvd->end(); it++){
        DVD auxiliar = *it;
        if(auxiliar.getTitulo() == titulo){
            cout << "Escolha o que você deseja editar:\n"
                << "1 - Artista\n"
                << "2 - Titulo\n"
                << "3 - Faixas\n"
                << "4 - Ano de lançamento\n"
                << "5 - Genero\n"
                << "6 - Palavras-chave\n"
                << "7 - Formato de audio\n"
                << "8 - Formato de tela\n";
            int op;
            cin >> op;
            cin.ignore();
            switch(op){
                case 1:
                    editarArtista(&auxiliar);
                    break;
                case 2:
                    editarTitulo(&auxiliar);
                    break;
                case 3:
                    editarFaixas(&auxiliar);
                    break;
                case 4:
                    editarAno(&auxiliar);
                    break;
                case 5:
                    editarGenero(&auxiliar);
                    break;
                case 6:
                    editarPalavrasChave(&auxiliar);
                    break;
                case 7:
                    editarFormatoAudio(&auxiliar);
                    break;
                case 8:
                    editarFormatoVideo(&auxiliar);
                    break;
                default:
                    cout << "Opção inválida.\n";
                    break;
            }
            *it = auxiliar;
        }
    }
}
vector<DVD> dvd::lerArq(){
ifstream f;
  f.open("DVD.txt", ios::in);
  if(!f.is_open()) {throw runtime_error("ERRO\n");}

  string artista;
  string titulo;
  int ano;
  string genero;
  int duracao;
  int volume;
  bool coletanea;
  vector<DVD> dvd;
  string audio;
    string video;
  string sAno; // string auxiliar pra usar stringstream
  while(!f.eof()){
    getline(f, artista);
    getline(f, titulo);
    getline(f, sAno);        //bloco que
      stringstream sa(sAno);  //le um int
      sa >> ano;               //para ano
    getline(f, genero);
    getline(f, audio);
    getline(f, video);
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
    DVD aux(artista, titulo, ano, genero, audio, video);
    aux.setPalavrasChave(palavrasChave);
    aux.setFaixas(faixas);
    dvd.push_back(aux);
    }
    f.close();
    return dvd;
}
void dvd::paraArq(vector<DVD> dvd){
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
        f << dvd[i].nKeyword << '\n';
        vector<string> palavrasChave = dvd[i].getPalavrasChave();
        f << palavrasChave.size() << '\n';
        for(int j = 0; j < palavrasChave.size(); j++){
            f << palavrasChave[j] << '\n';
        }
        f << dvd[i].nFaixas << '\n';
        vector<string> faixas = dvd[i].getFaixas();
        f << faixas.size() << '\n';
        for(int j = 0; j < faixas.size(); j++){
            f << faixas[j] << '\n';
        }
    }
    f.close();
}
void dvd::mostrarOrdenadoData(vector<DVD> v){
    vector<DVD> aux = v;
    for(int i = 0; i < aux.size(); i++){
        for(int j = i + 1; j < aux.size(); j++){
            if(aux[i].getAno() > aux[j].getAno()){
                DVD auxiliar = aux[i];
                aux[i] = aux[j];
                aux[j] = auxiliar;
            }
        }
    }
    for(int i = 0; i < aux.size(); i++){
        aux[i].print();
    }
}
//funcoes gerais
void mostrarOrdenadoData(vector<CD> v, vector<DVD> d){
    bool travaCD = 0, travaDVD = 0;
    int i=0, j=0;
    //ordenando os vetores
    for(int i = 0; i < v.size(); i++){
        for(int j = i + 1; j < v.size(); j++){
            if(v[i].getAno() > v[j].getAno()){
                CD auxiliar = v[i];
                v[i] = v[j];
                v[j] = auxiliar;
            }
        }
    }
    for(int i = 0; i < d.size(); i++){
        for(int j = i + 1; j < d.size(); j++){
            if(d[i].getAno() > d[j].getAno()){
                DVD auxiliar = d[i];
                d[i] = d[j];
                d[j] = auxiliar;
            }
        }
    }
    i = 0; j = 0;
    while(1){
        if(travaCD = 1 && travaDVD == 1) break;
        if(v[i].getAno() < d[j].getAno() && travaCD == 0){
            v[i].print();
            i++;
            if(i == v.size()) travaCD = 1;
        }
        else{
            d[j].print();
            j++;
            if(j == d.size()) travaDVD = 1;
        }
    }
}
void mostrarFaixasEmComum(CD cd, DVD dvd);
void mostrarPorGenero(vector<CD> cd, vector<DVD> dvd);
void exibirKeywords(vector<CD> cd, vector<DVD> dvd);
void ordemAlfabetica(vector<Midia> *midia);
    