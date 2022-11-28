#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include "MainFM.h"
using namespace std;
void pause();
int main(){
    vector<CD> cd = cd::lerArq();
    vector<DVD> dvd = dvd::lerArq();
    int opcao;
    while(true){
        menu();
        cin >> opcao;
        if(opcao == 0) break;
        switch(opcao){
            case 1:{
                int op;
                cout << "----------------------------------------\n";
                cout << "1 - CD" << '\n';
                cout << "2 - DVD" << '\n';
                cin >> op;
                if(op == 1)
                    cd::add(&cd);
                else if(op == 2)
                    dvd::add(&dvd);
                else
                    cout << "Opcao invalida" << '\n';
                cout << "----------------------------------------\n";
            }
              break;

            case 2:{
                int op;
                cout << "1 - CD" << '\n';
                cout << "2 - DVD" << '\n';
                cin >> op;
                if(op == 1)
                    cd::remove(&cd);
                else if(op == 2)
                    dvd::remove(&dvd);
                else
                    cout << "Opcao invalida" << '\n';
            }
                break;

            case 3:{
                cout << "----------------------------------------\n";
                cout << "CDs disponíveis:" << '\n';
                cd::lista(cd);
                cout << "----------------------------------------\n";
                cout << "DVDs disponíveis:" << '\n';
                dvd::lista(dvd);
                cout << "----------------------------------------\n";

            }
                break;
            case 4:
                {cout << "----------------------------------------\n";
                cout << "Deseja ver as midias?";
                cout << "1 - Sim" << '\n';
                cout << "2 - Nao" << '\n';
                int op;
                cin >> op;
                if(op == 1) {
                    cout << "----------------------------------------\n";
                    cout << "CDs disponíveis:" << '\n';
                    cd::lista(cd);
                    cout << "----------------------------------------\n";
                    cout << "DVDs disponíveis:" << '\n';
                    dvd::lista(dvd);
                    cout << "----------------------------------------\n";
                    op = 2;}
                if(op == 2){
                    cout << "----------------------------------------\n";
                    cout << "Escolha uma opção:" << '\n';
                    cout << "1 - CD" << '\n';
                    cout << "2 - DVD" << '\n';
                    cin >> op;
                    if(op == 1)
                        cd::editar(&cd);
                    else if(op == 2)
                        dvd::editar(&dvd);
                    else
                        cout << "Opcao invalida" << '\n';
                }
                else
                    cout << "Opcao invalida" << '\n';
                }
                break;
            case 5:{
                int op;
                cout << "----------------------------------------\n";
                    cout << "Escolha uma opção:" << '\n';
                    cout << "1 - CD" << '\n';
                    cout << "2 - DVD" << '\n';
                    cout << "3 - Todos" << '\n';
                    cin >> op;
                if(op == 1) cd::mostrarOrdenadoData(cd);
                else if(op == 2) dvd::mostrarOrdenadoData(dvd);
                else if(op == 3)mostrarOrdenadoData(cd, dvd);
                else
                    cout << "Opcao invalida" << '\n';
                cout << "----------------------------------------\n";}
                break;
            case 6:{
                string nome;
                bool key = false;
                cout << "Digite o titulo da midia: ";
                getline(cin, nome);
                CD cdBuscado = cd::buscar(cd, nome, &key);
                DVD dvdBuscado = dvd::buscar(dvd, nome, &key);
                if(key) mostrarFaixasEmComum(cdBuscado, dvdBuscado);
                else cout << "Midia nao encontrada" << '\n';
            }
                break;
            case 7:
                mostrarPorGenero(cd, dvd);
                break;
            case 8:
                break;
            case 9:
                exibirKeywords(cd, dvd);
                break;
            default:
                cout << "Opcao invalida" << '\n';
                break;
        }
    }
    cd::paraArq(cd);
    dvd::paraArq(dvd);
}