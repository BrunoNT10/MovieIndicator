#include <iostream>
#include <iomanip>
#include <cmath>
#include <fstream>
#include <cstring>
#include <stdlib.h>
// #include <conio.h>

using namespace std;

#define GRN "\e[0;33m"

void cadastrarNovoUsuario(){
    cout << "Cadastrando novo usuario...";
    
    cin.ignore();
    
    system("cls");
    
    cout << "***** CADASTRAR NOVO USUARIO *****" << endl;
    
    char nome[50];
    
    cout << "Nome do usuario: ";
    cin >> nome;
    
    int tam_str_nome = strlen(nome);
    
    int tamanho_caminho_completo = 9 + tam_str_nome + 4;
    
    string caminho_pasta = "clients/";
    
    caminho_pasta += nome;
    caminho_pasta += ".txt";
    
    char* char_array = new char[tamanho_caminho_completo];
    
    strcpy(char_array, caminho_pasta.c_str());
         
    ofstream arquivo;
    
    arquivo.open((char_array));
    
    cout << "Senha: ";
    
    char senha[20];
    
    cin.ignore();
    cin.getline(senha, 20);
    
    arquivo << senha << endl;
    
    cout << endl;
    
    cout << "1 - Entretenimento" << endl;
    cout << "2 - Comedia" << endl;
    cout << "3 - Romance" << endl;
    cout << "4 - Acao" << endl;
    cout << "5 - Infantil" << endl;
    
    cout << endl;
    
    cout << "Categorias preferidas(escolha 3 categorias e coloque todas as escolhas separadas por um espaco): ";
    
    int categoria;
    for(int i=0; i<3; i++){
        cin >> categoria;
        switch(categoria) {
            case 1:
                arquivo << "entretenimento" << endl;
                break;
            case 2:
                arquivo << "comedia" << endl;
                break;
            case 3:
                arquivo << "romance" << endl;
                break;
            case 4:
                arquivo << "acao" << endl;
                break;
            case 5:
                arquivo << "infantil" << endl;
                break;    
            default:
                break;
        }
    }
    
    arquivo.close();
    
}

void login(){
    system("cls");
    cout << "***** LOGIN *****" << endl;
    cout << "Usuario: ";
    
    char usuario[50];
    
    cin.ignore();
    cin.getline(usuario, 50);
    
    char senha[20];
    
    cout << "Senha: ";
    
    cin.ignore();
    cin.getline(senha, 20);
    
    string caminho_pasta = "clients/";
    
    caminho_pasta += usuario;
    caminho_pasta += ".txt";
    
    int tam_str_nome = strlen(usuario);
    
    int tamanho_caminho_completo = 9 + tam_str_nome + 4;
    
    char* char_array = new char[tamanho_caminho_completo];
    
    strcpy(char_array, caminho_pasta.c_str());
         
    fstream arquivo;

    arquivo.open((char_array), ios::in);
    arquivo.seekp(0, arquivo.beg);
    
    struct filme {
        char nome[50];
        // int ano;
    };
    
    struct filme categorias;
    
    char ch;
    
    string nome_filme = "";
    
    int cont = 0;
    int i = 0;
    while (arquivo.get(ch)){
        cout << ch;
        nome_filme += ch;
        if (ch == '\n') {
            
            cont += 1;
        }
        
    }
    
}

void excluirConta(){
    cout << "Excluindo conta" << endl;
}

void visualizarFilmes(){
    cout << "Visualizando filmes" << endl;
}

void renderizarTelaInicial() {
    system("cls");

    cout << GRN "**************** INFINITY STREAM ****************" << endl;
    cout << "Bem vindo ao Infinity stream!" << endl;
    cout << "O que deseja?" << endl;
    cout << "1 - Cadastrar um novo usuario." << endl;
    cout << "2 - Fazer login na plataforma." << endl;
    cout << "3 - Excluir uma conta." << endl;
    cout << "4 - Visualizar filmes por genero." << endl;
    
    int escolha = -1;
    
    // do{
        cout << "Insira o numero correspondente a sua escolha: ";
        cin >> escolha;
    // }
    // while(escolha < 1 || escolha > 4);
    
    switch (escolha){
        case 1:
            cadastrarNovoUsuario();
            break;
        
        case 2:
            login();
            break;
        
        case 3:
            excluirConta();
            break;
        
        case 4:
            visualizarFilmes();
            break;
    }
    
}

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    renderizarTelaInicial();
    
    return 0;
}