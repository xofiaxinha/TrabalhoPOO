#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
//#include <iterator>
#include <stdexcept>
#include "CD.h"
#include "DVD.h"
#include "MainFM.h"
using namespace std;
//funções auxiliares que utilizam template
template <typename T>
void verMais(vector<T> m){
    while(1){ //loop infinito que permite ver detalhes das midias
        cout << "Digite o numero da midia para ver mais detalhes ou digite 0 para sair:\n";
        int op;
        cin >> op;
        
        if(op == 0 || op > (int) m.size()) return;
        
        m[op-1].print();
    }
    system("pause");
}
template <typename T>
void ordemAlfabetica(vector<T> *a){
    for(typename vector<T>::iterator it = a->begin(); it != a->end(); it++){
        for(typename vector<T>::iterator it2 = it + 1; it2 != a->end(); it2++){
            if(it->getTitulo() > it2->getTitulo()){
                T aux = *it;
                *it = *it2;
                *it2 = aux;
            }
        }
    }
} 

void pause(){
    cin.ignore();
    cout << "Digite qualquer tecla para continuar" << '\n';
    getchar();
    //cout << "----------------------------------------\n";
    system("clear");
}

//funcoes auxiliares pra editar
void editarArtista(Midia *m){
    cin.ignore();
    cout << "Digite o novo nome do artista:\n";
    string artista;
    getline(cin, artista);
    m->setArtista(artista);
}
void editarTitulo(Midia *m){
    cin.ignore();
    cout << "Digite o novo titulo:\n";
    string titulo;
    getline(cin, titulo);
    m->setTitulo(titulo);
}
void editarFaixas(Midia *m){
    cin.ignore();
    cout << "Escolha uma opção:\n"
        << "1. Reescrever as faixas\n"
        << "2. Adicionar uma ou mais faixas\n"
        << "3. Remover faixas\n"
        << "X. Sair\n";
    char op;
    cin >> op;
    //se o usuario desejar adicionar as faixas, o programa entra no loop, e se não quiser pula a instrução
    vector<string> faixas;
    switch(op){
        case '1':
            while(op != 'N' && op != 'n'){ // enquanto op não for não, insere faixa
                cin.ignore();
                cout << "Digite o nome da faixa:\n";
                string faixa;
                getline(cin, faixa);
                faixas.push_back(faixa);
                cout << "Deseja adicionar mais faixas?\nN para não. ";
                cin >> op;
                //cin.ignore(); //limpa o buffer do cin
            }
            break;
        case '2':
            if(m->getFaixas().size() == 1){
                if(m->getFaixas()[0] == "Não há faixas disponiveis"){
                    m->getFaixas().pop_back();
                }
            }
            while(op != 'N' && op != 'n'){ // enquanto op não for não, insere faixa
                cout << "Digite o nome da faixa:\n";
                string faixa;
                getline(cin, faixa);
                faixas.push_back(faixa);
                cout << "Deseja adicionar mais faixas?\nN para não. ";
                cin >> op;
                cin.ignore(); //limpa o buffer do cin
            }
            break;
        case '3':
            if(m->getFaixas().size() == 1){
                if(m->getFaixas()[0] == "Não há faixas disponiveis"){
                    cout << "Não há faixas para serem removidas.\n";
                }
            }
            else{
                cout << "Digite o nome da faixa a ser removida:\n";
                string faixa;
                getline(cin, faixa);
                for(vector<string>::iterator it = m->getFaixas().begin(); it != m->getFaixas().end(); it++){
                    if(*it == faixa){
                        m->getFaixas().erase(it);
                        break;
                    }
                }
            }
            break;
        default:
            break;
    }
                // }
    m->setFaixas(faixas);
}
void editarAno(Midia *m){
    cin.ignore();
    cout << "Digite o novo ano de lançamento:\n";
    int ano;
    cin >> ano;
    m->setAno(ano);
}
void editarGenero(Midia *m){
    cin.ignore();
    cout << "Digite o novo genero:\n";
    string genero;
    cin >> genero;
    m->setGenero(genero);
}
void editarPalavrasChave(Midia *m){
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
    m->setPalavrasChave(palavrasChave);
}

//funcoes de cd
void cd::add(vector<CD> *v){
    system("clear");
    cout << "----------------------------------------\n";
    cout << "\t- Adicionando CD -\n";
    cout << "----------------------------------------\n";
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
            faixas.push_back(p);
        }
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

    v->push_back(cd); //empurra o novo cd no vetor
    //mensagem de confirmação
    cout << "- CD adicionado com sucesso!\n";
    ordemAlfabetica(v);
    pause();
}
void cd::remove(vector<CD> *v){
    system("clear");
    cout << "----------------------------------------\n";
    cout << "\t- Removendo CD-\n";
    cout << "----------------------------------------\n";
    cin.ignore();
    int tam = v->size(); //pega o tamanho do vetor

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
                << "----------------------------------------\n";
            auxiliar.print();
            for(int j = i; j < tam; j++){
                v[j] = v[j+1];
            }
            v->pop_back();
            cout << "CD removido com sucesso!\n";
            break;
            return;
        }
    }cout << "CD nao encontrado.\n";
    pause();
}
//funções auxiliares de editar especificamente de cd
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
    system("clear");
    cout << "----------------------------------------\n";
    cout << "\t- Editando CD-\n";
    cout << "----------------------------------------\n";
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
            cout << "CD editado com sucesso!\n";
            auxiliar.print();
        }
    }
    pause();
}
void cd::lista(vector<CD> cd){
    cout << "Lista de CDs:\n";
    cout << "----------------------------------------\n";
    int tam = cd.size();
    for(int i = 0; i < tam; i++){
        cout << i + 1 << ". " << cd[i].getTitulo() << " por " << cd[i].getArtista() << '\n';
    }
    cout << "----------------------------------------\n";
    verMais(cd);
    pause();
}
vector<CD> cd::lerArq(){
    vector<CD> cd;
    ifstream arq;
    arq.open("CD.txt", ios::in);
    string artista, titulo, genero;
    int ano, duracao, volume;
    bool coletanea;
    string linha;
    if(!arq.is_open()) throw runtime_error("Erro ao abrir o arquivo\n");
        while(getline(arq, artista) && getline(arq, titulo) && getline(arq, linha)){ //condição que pega o artista, titulo e ano, e, se chegar no fim do arquivo, ao menos um desses vai dar erro
            stringstream ss(linha);
            ss >> ano;
            //arq.ignore(7);
            getline(arq, genero); // pega o genero
            getline(arq, linha); // pega a duração
            stringstream ss1(linha);
            ss1 >> duracao;
            getline(arq, linha); // pega o volume
            stringstream ss2(linha);
            ss2 >> volume;
            getline(arq, linha); // pega o valor da coletanea
            stringstream ss3(linha);
            ss3 >> coletanea;
            getline(arq, linha); // pega o numero de faixas
            int nFaixas;
            stringstream ss4(linha);
            ss4 >> nFaixas;
            CD aux(artista, titulo, ano, genero, duracao, volume, coletanea);
            vector<string> faixas;
            //arq >> nFaixas;
            for(int i = 0; i < nFaixas; i++){
                string faixa;
                getline(arq, faixa);
                faixas.push_back(faixa);
            }
            aux.setFaixas(faixas);
            int nKeyword;
            getline(arq, linha);
            stringstream ss5(linha);
            ss5 >> nKeyword;
            vector<string> palavrasChave;
            for(int i = 0; i < nKeyword; i++){
                string palavraChave;
                getline(arq, palavraChave);
                palavrasChave.push_back(palavraChave);
            }
            //getline(arq, linha); // ler a quebra de linha
            aux.setPalavrasChave(palavrasChave);
            cd.push_back(aux);
        }
    arq.close();
    return cd;
}
void cd::paraArq(vector<CD> cd){
    ofstream f;
    f.open("CD.txt", ios::out);
    if(!f.is_open()) {throw runtime_error("ERRO\n");}

    int tamanho = cd.size();
    if(cd.size() == 0) return;
    for(int i = 0; i<tamanho; i++){
        f << cd[i].getArtista() << '\n';
        f << cd[i].getTitulo() << '\n';
        f << cd[i].getAno() << '\n';
        f << cd[i].getGenero() << '\n';
        f << cd[i].getDuracao() << '\n';
        f << cd[i].getVolume() << '\n';
        f << cd[i].getColetanea() << '\n';
        f << cd[i].nFaixas << '\n';
        vector<string> faixas = cd[i].getFaixas();
        for(int j = 0; j < cd[i].nFaixas; j++){
            f << faixas[j] << '\n';
        }
        f << cd[i].nKeyword << '\n';
        vector<string> palavrasChave = cd[i].getPalavrasChave();
        for(int j = 0; j < cd[i].nKeyword; j++){
            f << palavrasChave[j] << '\n';
        }
    }
    //f << '-' << '\n';
    f.close();
}
void cd::mostrarOrdenadoData(vector<CD> v){
    system("clear");
    cout << "----------------------------------------\n";
    cout << "\t- CDs por data (crescente) -\n";
    cout << "----------------------------------------\n";
    vector<CD> auxiliar = v;
    int tam = auxiliar.size();
    if((tam < 2)){
        auxiliar[0].print();
        cout << "----------------------------------------\n";
        pause();
        return;
    }
    for(int i=0; i<tam; i++){
        int a = i;
        for(int j = i+1; j<tam; j++){
            if(auxiliar[j].getAno() < auxiliar[a].getAno()) a = j;
        }
        
        CD obj = auxiliar[i];
        auxiliar[i] = auxiliar[a];
        auxiliar[a] = obj;
    }

    for(int i=0; i<tam; i++){
        auxiliar[i].print();
        cout << "----------------------------------------\n";
    }
    pause();
}

//funcoes de dvd
void dvd::add(vector<DVD> *v){
    system("clear");
    cout << "----------------------------------------\n";
    cout << "\t- Adicionando DVD -\n";
    cout << "----------------------------------------\n";
    cin.ignore(); //limpa o buffer do cin

    string artista;
    cout << "Digite o nome do artista:\n";
    getline(cin, artista); //pega a string artista

    string titulo;
    cout << "Digite o titulo do DVD:\n";
    getline(cin, titulo); //pega a string texto

    cout << "Deseja adicionar as faixas?\nN para não. ";
    char op;
    cin >> op;
    //se o usuario desejar adicionar as faixas, o programa entra no loop, e se não quiser pula a instrução
    vector<string> faixas;
        if(op == 'n' || op == 'N'){
            string p = "Não ha faixas cadastradas";
            cout << p << '\n'; // mostra que não há faixas
            faixas.push_back(p);
            }
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

    //declarando o objeto
    DVD aux(artista, titulo, ano, genero, audio, video);
    aux.setPalavrasChave(palavrasChave);
    aux.setFaixas(faixas);
    v->push_back(aux);
    cout << "DVD adicionado com sucesso!\n";
    ordemAlfabetica(v);
    pause();
}
void dvd::remove(vector<DVD> *v){
    system("clear");
    cout << "----------------------------------------\n";
    cout << "\t- Removendo CD -\n";
    cout << "----------------------------------------\n";
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
            for(int j = i; j < tam; j++){
                v[j] = v[j+1];
            }
            v->pop_back();
            cout << "DVD removido com sucesso!\n";
            system("pause");
            break;
            return;
        }
    }cout << "DVD nao encontrado.\n";
    pause();
}
void dvd::lista(vector<DVD> dvd){
    int tam = dvd.size();
    cout << "Lista de DVDs:\n";
    cout << "----------------------------------------\n";
    for(int i = 0; i < tam; i++){
        cout << i + 1 << ". " << dvd[i].getTitulo() << " por " << dvd[i].getArtista() << '\n';
    }
    verMais(dvd);
    pause();
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
    system("clear");
    cout << "----------------------------------------\n";
    cout << "\t- Editando DVD -\n";
    cout << "----------------------------------------\n";
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
            cout << "DVD editado com sucesso!\n";
            auxiliar.print();
            system("pause");
            return;
        }
    }

    cout << "DVD não encontrado.\n";
    pause();
}
vector<DVD> dvd::lerArq(){
    vector<DVD> dvd;
    ifstream arq;
    arq.open("DVD.txt", ios::in);
    if(!arq.is_open()) throw runtime_error("Erro ao abrir o arquivo\n");
    string artista, titulo, genero, audio, video;
    int ano;
    string linha;
        while(getline(arq, artista) && getline(arq, titulo) && getline(arq, linha)){
            stringstream ss(linha);
            ss >> ano;
            getline(arq, genero); // pega o genero
            getline(arq, audio); // pega o formato de audio
            getline(arq, video); // pega o formato de video
            getline(arq, linha); // pega o numero de faixas
            int nFaixas;
            stringstream ss2(linha);
            ss2 >> nFaixas;
            DVD aux(artista, titulo, ano, genero, audio, video);
            vector<string> faixas;
            for(int i = 0; i < nFaixas; i++){
                string faixa;
                getline(arq, faixa);
                faixas.push_back(faixa);
            }
            aux.setFaixas(faixas);
            int nKeyword;
            getline(arq, linha);
            stringstream ss3(linha);
            ss3 >> nKeyword;
            vector<string> palavrasChave;
            for(int i = 0; i < nKeyword; i++){
                string palavraChave;
                getline(arq, palavraChave);
                palavrasChave.push_back(palavraChave);
            }
            aux.setPalavrasChave(palavrasChave);
            dvd.push_back(aux);
        }
    arq.close();
    return dvd;
}
void dvd::paraArq(vector<DVD> dvd){
    ofstream f;
    f.open("DVD.txt", ios::out);
    if(!f.is_open()) {throw runtime_error("ERRO\n");}

    int tam = dvd.size();
    if(tam == 0) return;
    for(int i = 0; i<tam; i++){
        f << dvd[i].getArtista() << '\n';
        f << dvd[i].getTitulo() << '\n';
        f << dvd[i].getAno() << '\n';
        f << dvd[i].getGenero() << '\n';
        f << dvd[i].getFormatoAudio() << '\n';
        f << dvd[i].getFormatoTela() << '\n';
        f << dvd[i].nFaixas << '\n';
        vector<string> faixas = dvd[i].getFaixas();
        for(int j = 0; j < dvd[i].nFaixas; j++){
            f << faixas[j] << '\n';
        }
        f << dvd[i].nKeyword << '\n';
        vector<string> palavrasChave = dvd[i].getPalavrasChave();
        for(int j = 0; j < dvd[i].nKeyword; j++){
            f << palavrasChave[j] << '\n';
        }
    }
    f.close();
}
void dvd::mostrarOrdenadoData(vector<DVD> v){
    system("clear");
    cout << "----------------------------------------\n";
    cout << "\t- DVDs por data (crescente) -\n";
    cout << "----------------------------------------\n";
    vector<DVD> aux = v;
    int tam = aux.size();
    if(tam < 2){
        aux[0].print();
        cout << "----------------------------------------\n";
        pause();
        return;
    }

    for(int i = 0; i < tam; i++){
        for(int j = i + 1; j < tam; j++){
            if(aux[i].getAno() > aux[j].getAno()){
                DVD auxiliar = aux[i];
                aux[i] = aux[j];
                aux[j] = auxiliar;
            }
        }
    }
    for(int i = 0; i < tam; i++){
        aux[i].print();
        cout << "----------------------------------------\n";
    }
    pause();
}

//funcoes gerais
void mostrarOrdenadoData(vector<CD> v, vector<DVD> d){
    system("clear");
    cout << "----------------------------------------\n";
    cout << "\t- Midias por data (crescente) -\n";
    cout << "----------------------------------------\n";
    bool travaCD = 0, travaDVD = 0;
    int i=0, j=0, tamCD = v.size(), tamDVD = d.size();
    //ordenando os vetores
    for(i = 0; i < tamCD; i++){
        for(j = i + 1; j < tamCD; j++){
            if(v[i].getAno() > v[j].getAno()){
                CD auxiliar = v[i];
                v[i] = v[j];
                v[j] = auxiliar;
            }
        }
    }
    for(i = 0; i < tamDVD; i++){
        for(j = i + 1; j < tamDVD; j++){
            if(d[i].getAno() > d[j].getAno()){
                DVD auxiliar = d[i];
                d[i] = d[j];
                d[j] = auxiliar;
            }
        }
    }
    i = 0; j = 0;
    while(1){
        if(travaCD == 1 && travaDVD == 1) break;
        if(v[i].getAno() < d[j].getAno() && travaCD == 0){
            cout << "CD:\n";
            v[i].print();
            cout << "----------------------------------------\n";
            i++;
            if(i == tamCD) travaCD = 1;
        }
        else{
            cout << "DVD:\n";
            d[j].print();
            cout << "----------------------------------------\n";
            j++;
            if(j == tamDVD) travaDVD = 1;
        }
    }

    pause();
}
void mostrarFaixasEmComum(CD cd, DVD dvd){
    system("clear");
    cout << "----------------------------------------\n";
    cout << "\t- Faixas em comum (crescente) -\n";
    cout << "----------------------------------------\n";
    vector<string> cdFaixas = cd.getFaixas();
    vector<string> dvdFaixas = dvd.getFaixas();
    for(int i = 0; i < cd.nFaixas; i++){
        for(int j = 0; j < cd.nFaixas; j++){
            if(cdFaixas[i] == dvdFaixas[j]){
                cout << cdFaixas[i] << '\n';
            }
        }
    }
    pause();
    //system("pause");
}
void mostrarPorGenero(vector<CD> cd, vector<DVD> dvd){
    system("clear");
    cout << "----------------------------------------\n";
    cout << "    - Midia organizada por genero -\n";
    cout << "----------------------------------------\n";
    vector<string> generosCD;
    generosCD.push_back(cd[0].getGenero());
    int tamCD = cd.size();
    int tamGen = generosCD.size();
    for(int i = 0; i < tamCD; i++){
        for(int j = i + 1; j < tamGen; j++){
            if(cd[i].getGenero() == generosCD[j]) break;
            if(j == tamGen - 1) generosCD.push_back(cd[i].getGenero());
        }
    }

    cout << "CDs:\n";
    for(int i = 0; i < tamGen; i++){
        cout << generosCD[i] << ":\n";
        for(int j = 0; j < tamCD; j++){
            if(cd[j].getGenero() == generosCD[i]) {cd[j].print();
            cout << "----------------------------------------\n";}
        }
    }

    vector<string> generosDVD;
    generosDVD.push_back(dvd[0].getGenero());
    int tamDVD = dvd.size();
    int tamGenDVD = generosDVD.size();
    for(int i = 0; i < tamDVD; i++){
        for(int j = 0; j < tamGenDVD; j++){
            if(dvd[i].getGenero() == generosDVD[j]) break;
            if(j == tamGenDVD - 1) generosDVD.push_back(dvd[i].getGenero());
        }
    }
    pause();
}
void exibirKeywords(vector<CD> cd, vector<DVD> dvd){
    system("clear");
    cout << "----------------------------------------\n";
    cout << "\t- Keywords -\n";
    cout << "----------------------------------------\n";
    vector<string> palavrasChaveCD = cd[0].getPalavrasChave();
    int tamCD = cd.size();
    for(int i = 1; i<tamCD; i++){
        vector<string> aux = cd[i].getPalavrasChave();
        for(int j = 0; j < (int) aux.size(); j++){
            for(int k = 0; k< (int) palavrasChaveCD.size(); k++){
            if(aux[j] == palavrasChaveCD[k]) break;
            palavrasChaveCD.push_back(aux[j]);}
        }
    }
    tamCD = palavrasChaveCD.size();
    for(int i = 0; i<(int) dvd.size(); i++){
        vector<string> aux = dvd[i].getPalavrasChave();
        for(int j = 0; j < (int) aux.size(); j++){
            for(int k = 0; k<tamCD; k++){
            if(aux[j] == palavrasChaveCD[k]) break;
            palavrasChaveCD.push_back(aux[j]);}
        }
    }
    for(int i = 0; i < (int) palavrasChaveCD.size(); i++){
        cout << palavrasChaveCD[i] << '\n';
    }
    pause();
}
void menu(){
    cout << "----------------------------------------\n";
    cout << "\t\t- Main.fm -\n";
    cout << "----------------------------------------\n";
    
    cout << "1. Adicionar Midia\n"
        << "2. Remover Midia\n"
        << "3. Mostrar Midia\n"
        << "4. Editar Midia\n"
        << "5. Mostrar Ordenado por Data\n"
        << "7. Mostrar Faixas em Comum\n"
        << "8. Mostrar por Genero\n"
        << "9. Exibir Keywords disponíveis\n"
        << "0. Sair\n";
}
CD cd::buscar(vector<CD> v, string nome, bool *key){
    for(vector<CD>::iterator it = v.begin(); it != v.end(); it++){
        CD aux = *it;
        if(aux.getTitulo() == nome){
            *key = 1;
            return *it;
        }
    }
    cout << "Midia nao encontrada\n";
    pause();
    return v[0];
}
DVD dvd::buscar(vector<DVD> v, string nome, bool *key){
    for(vector<DVD>::iterator it = v.begin(); it != v.end(); it++){
        DVD aux = *it;
        if(aux.getTitulo() == nome){
            *key = 1;
            return *it;
        }
    }
    cout << "Midia nao encontrada\n";
    pause();
    return v[0];
}