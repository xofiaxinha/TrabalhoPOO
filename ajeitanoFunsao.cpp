#include <iostream>
#include <vector>
#include "CD.h"
#include "func.h"
#include "DVD.h"
#include <string>
//#include "func.h"
using namespace std;
int main(){
    vector<CD> cd = cd::lerArq();
    vector<DVD> dvd = dvd::lerArq();
    int opcao;
    do{
        cout << "Adicionando pra testar\n";
        cout << "1 - CD" << endl;
        cout << "2 - DVD" << endl;
        cout << "3 - Sair" << endl;
        cin >> opcao;
        switch(opcao){
            case 1:
                cd::add(&cd);
                break;
            case 2:
                dvd::add(&dvd);
                break;
            case 3:
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
    }while(opcao != 3);

    do{
        cout << "1 - CD" << endl;
        cout << "Digite uma opcao para testar:\n"
            << "1 - Adcionar\n"
            << "2 - Remover\n"
            << "3 - Listar\n"
            << "4 - Editar\n"
            << "5 - Mostrar ordenado por data\n"
            << "6 - Sair\n";
        cin >> opcao;
        switch(opcao){
            case 1:
                cd::add(&cd);
                break;
            case 2:
                cd::remove(&cd);
                break;
            case 3:
                cd::lista(cd);
                break;
            case 4:
                cd::editar(&cd);
                break;
            case 5:
                cd::mostrarOrdenadoData(cd);
                break;
            case 6:
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
        cout << "----------------------------------------" << endl;
    }while(opcao != 6);

    do{
        cout << "2 - DVD" << endl;
        cout << "Digite uma opcao para testar:\n"
            << "1 - Adcionar\n"
            << "2 - Remover\n"
            << "3 - Listar\n"
            << "4 - Editar\n"
            << "5 - Mostrar ordenado por data\n"
            << "6 - Sair\n";
        cin >> opcao;
        switch(opcao){
            case 1:
                dvd::add(&dvd);
                break;
            case 2:
                dvd::remove(&dvd);
                break;
            case 3:
                dvd::lista(dvd);
                break;
            case 4:
                dvd::editar(&dvd);
                break;
            case 5:
                dvd::mostrarOrdenadoData(dvd);
                break;
            case 6:
                break;
            default:
                cout << "Opcao invalida" << endl;
        }
        cout << "----------------------------------------" << endl;
    }while(opcao != 6);

     cd::paraArq(cd);
     dvd::paraArq(dvd);
    return 0;
}