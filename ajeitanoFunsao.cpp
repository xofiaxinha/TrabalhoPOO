#include <iostream>
#include <vector>
#include "CD.h"
#include "DVD.h"
#include <string>
//#include "func.h"
using namespace std;

namespace cd{
void addCD(vector<CD> *v){
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
void listaCDs(vector<CD> cd){
    cout << "Lista de CDs:\n";
    cout << "=======================================\n";
    for(int i = 0; i < cd.size(); i++){
        cout << cd[i].getTitulo() << " por " << cd[i].getArtista() << '\n';
    }
}

void remove(vector<CD> *v){
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
}
}
/*void mostrarOrdenadoData(vector<CD> cd, vector<DVD> dvd)""{
    bool travaCD, travaDVD;
    //alterar as funcoes que mostram ordenado
    //pra realmente ordenar;
    int a = 0, b = 0;
    while(1){
        if(travaCD == 1 && travaDVD == 1) break;
        if(cd[a].getAno() < dvd[b].getAno()
               && travaCD == 0)
            {cd[a].print();
                a++;}
        else if (cd[a].getAno() > dvd[b].getAno()
               && travaDVD == 0){dvd[b].print();
            b++;}
            
        if(a == cd.size()) travaCD = 1;
        if(b == dvd.size()) travaDVD = 1;
    }
}*/
/*void mostrarMidiaAno(vector<CD> cd, vector<DVD> dvd, int ano){
    //supondo que ta oedenado por ano
    int a=0, b=0;
    while(cd[a].getAno() != ano) a++;
    while(dvd[b].getAno() != ano) b++;
    
    cout << "CDs;\n";
    while(cd[a].getAno == ano){
        cd[a].print();
        a++;}
    cout << "DVDs:\n";
    while(dvd[b].getAno == ano){
        dvd[b].print();
        b++;}
}*/
int main(){
  CD a("Miku", "00", 2017, "jpop", 49, 0,0), b("Luka", "00 - reissue", 2019, "jpop", 49,0,0);
  vector<CD> cds;
  cds.push_back(a);
  cds.push_back(b);
  cd::remove(&cds);
}