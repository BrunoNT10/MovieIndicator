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
    
    // struct filme {
    //     char nome[50];
    //     // int ano;
    // };
    
    // struct filme categorias[10];
    
    struct filme {
        char nome[50];
    };
    
    struct filme categorias[10];
    
    char ch;
    
    string nome_filme = "";
    
    int cont = 0;
    int i = 0;
    while (arquivo.get(ch)){
        nome_filme += ch;
        if (ch == '\n') {
            char nome_filme_char[50];
            nome_filme.erase(nome_filme.length() - 1);
            
            strcpy(nome_filme_char, nome_filme.c_str());
            
            if (cont > 0){
                strcpy(categorias[i-1].nome, nome_filme_char);
            }
            
            cont += 1;
            i+=1;
            nome_filme = "";
        }
        
    }
    
    arquivo.close();
    system("cls");
    
    cout << "Aqui estao alguns filmes para voce: " << endl;
    
    string categoria;
    char char_categoria[50];
    struct filme filmes[100];
    int num_filmes = 0;
    int j = 0;
    
    for(int i=0; i<3; i++){
        // cout << "Rodando uma vez" << endl;
        categoria = "movies/";
        categoria += categorias[i].nome;
        categoria += ".txt";
        
        strcpy(char_categoria, categoria.c_str());
        
        arquivo.open(char_categoria, ios::in);
        char ch;
        string filme = "";
        while(arquivo.get(ch)){
            filme += ch;
            if (ch == '\n'){
                filme.erase(filme.length() - 1);
                strcpy(filmes[j].nome, filme.c_str());
                
                j += 1;
                
                filme = "";
                num_filmes += 1;
            }
        }
        arquivo.close();
        
    }
    for(int i=0; i<num_filmes; i++){
        cout << filmes[i].nome << endl;
    }
    char escolha;
    cout << "Deseja visualizar mais alguns filmes (Y/N): ";
    
    cin >> escolha;
    
    if(escolha == 'Y' || escolha == 'y'){
        cout << "Qual a categoria de filmes pretende pesquisar?" << endl;
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