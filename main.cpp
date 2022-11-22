#include <iostream>
#include <vector>
#include <cstdlib>
#include "MainFM.h"
using namespace std;
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
                mostrarOrdenadoData(cd, dvd);
                break;
            case 5:{
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
            // case 6:
            //     break;
            // case 7:
            //     break;
            case 8:
                break;
            default:
                cout << "Opcao invalida" << '\n';
                break;
        }
        system("clear");
    }
}
