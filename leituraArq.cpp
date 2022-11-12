#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "CD.h"
/*void passaArqCD(vector<class> c){
  ofstream f;
  f.open("CD.txt", ios::app);

  f << 
}*/
void lerArqCD(){
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
    cout << "Arquivo lido!";
    CD aux(artista, titulo, ano, genero, duracao, volume, coletanea)
    }
}

int main(){
  lerArqCD();
}