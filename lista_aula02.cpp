#include <iostream>
#include <windows.h>
#include <string>
#include <cctype>

using namespace std;

class estoque{
    int qtd_acucar;
    int qtd_leite;
    int qtd_cafe;
    int qtd_arroz;
    int qtd_feijao;

    public:
    estoque(){
        qtd_acucar = 0;
        qtd_leite = 0;
        qtd_cafe = 0;
        qtd_arroz = 0;
        qtd_feijao = 0;
    }
    ~estoque(){cout << "Objeto Destruído!" << endl;}

    void set_acucar(int a){qtd_acucar = a;}
    void set_leite(int a){qtd_leite = a;}
    void set_cafe(int a){qtd_cafe = a;}
    void set_arroz(int a){qtd_arroz = a;}
    void set_feijao(int a){qtd_feijao = a;}

    int get_acucar(){return qtd_acucar;}
    int get_leite(){return qtd_leite;}
    int get_cafe(){return qtd_cafe;}
    int get_arroz(){return qtd_arroz;}
    int get_feijao(){return qtd_feijao;}

    void comprar(int, int);
    void repor(int, int);
};

void estoque::comprar(int a, int b){
    switch(a){
        case 1:{
            qtd_acucar -= b;
        }break;
        case 2:{
            qtd_leite -= b;
        }break;
        case 3:{
            qtd_cafe -= b;
        }break;
        case 4:{
            qtd_arroz -= b;
        }break;
        case 5:{
            qtd_feijao -= b;
        }break;
    }
}

void estoque::repor(int a, int b){
    switch(a){
        case 1:{
            qtd_acucar += b;
        }break;
        case 2:{
            qtd_leite += b;
        }break;
        case 3:{
            qtd_cafe += b;
        }break;
        case 4:{
            qtd_arroz += b;
        }break;
        case 5:{
            qtd_feijao += b;
        }break;
    }
}

int main(){ SetConsoleOutputCP(CP_UTF8); // Colocando em português...

    int opcao = 0;
    while(opcao != 5){
        cout << "\n\nSELECIONE A QUESTÃO QUE DESEJA EXECUTAR:\n\n";
        cout << "[1] Solicite ao usuário 5 valores inteiros e armazene os valores em uma array. Retorne ao usuário o maior valor entre os valores digitados\n";
        cout << "[2] Peça para o usuário adivinhar a senha. A senha deve ser um array e você deve fazer uma comparação entre a senha real e a senha digitada pelo usuário. Seu código deve se repetir até que o usuário acerte.\n";
        cout << "[3] Faça um código que solicite uma senha a um usuário. A senha deve conter pelo menos 1 letra maiúscula e 1 número, caso não contenha, peça que o usuário digite outra senha até que satisfaça às condições.\n";
        cout << "[4] Faça um programa que simule o funcionamento de uma loja de alimentos.\n";
        cout << "[5] SAIR DO PROGRAMA\n";
        cout << "[6] RETORNAR AO MENU PRINCIPAL\n\n";
        cin >> opcao;

        switch(opcao){
            case 1:{
                int array[5];
                //Setar os 5 valores do array
                for(int i = 0; i < 5; i++){
                    cout << i+1 << "º valor: "; cin >> array[i];
                }
                int maior = array[0];
                //Comparar valor a valor para descobrir qual o maior e armazenar a resposta na variável maior
                for(int i = 1; i < 5; i++){
                    if(maior < array[i]){
                        maior = array[i];
                    }
                }
                cout << "Maior número da array: " << maior << endl;
            } break;

            case 2:{
                int cmp = 100, counter = 1;
                //Entro no meu looping, até que a pessoa acerte a senha, ou seja, quando cmp == 0
                while(cmp != 0){
                    //definição da senha e variável onde será armazenada a tentativa
                    char senha[5] = "caju";
                    char tentativa[5];

                    cout << "Digite a senha (Deve conter apenas 4 caracteres): "; cin >> tentativa;

                    //minha variável assumirá os valores de -1 ou 1 se a senha estiver incorreta e 0 se estiver correta
                    //Reveja os slides para lembrar, se necessário!
                    cmp = strcmp(senha, tentativa);


                    // Se cmp for 1 ou -1, significa que o usuário errou a senha!
                    if(cmp == 1 || cmp == -1){
                        cout << "Senha incorreta! Tente novamente!" << endl;
                    }

                    //Esse counter não é necessário, é apenas uma brincadeirinha que eu fiz rs
                    counter ++;

                    if(counter == 5){
                        cout << "Tá difícil né? Toma mais uma dica: É uma fruta!" << endl;
                    }
                    if(counter == 10){
                        cout << "Desista, a senha é caju!!!" << endl;
                    }
                }

                // Se o usuário saiu do looping, significa que ele acertou a senha, então printei uma mensagem de parabens!
                cout << "Senha correta! Parabéns!" << endl;
            }break;
            case 3:{
                char senha[8];
                bool cond = TRUE;
                bool teste_letra = FALSE;
                bool teste_num = FALSE;

                while(cond){
                    cout << "Digite sua senha: "; cin >> senha;

                    for(int i = 0; i < 8; i++){
                        teste_letra = isupper(senha[i]);

                        if(teste_letra == TRUE){break;}
                    }
                    for(int i = 0; i < 8; i++){
                        teste_num = isdigit(senha[i]);

                        if(teste_num == TRUE){break;}
                    }
                    if(teste_letra && teste_num){
                        cond = FALSE;
                    }
                    else if(teste_letra && teste_num == FALSE){
                        cout << "Sua senha deve conter pelo menos um número! Tente novamente" << endl;
                    }
                    else if(teste_letra == FALSE && teste_num){
                        cout << "Sua senha deve conter pelo menos uma letra maiúscula! Tente novamente" << endl;
                    }
                    else{
                        cout << "Sua senha deve conter pelo menos um número e uma letra maiúscula! Tente novamente" << endl;
                    }
                }
                cout << "\nSENHA VALIDADA COM SUCESSO!" << endl;

            }break;

            case 4:{
                estoque loja1;
                int opcao1;
                while(opcao1 != 5){
                    cout << "BEM-VINDO AO SEU ESTOQUE! SELECIONE A OPERAÇÃO QUE DESEJA REALIZAR!" << endl;
                    cout << "[1] SETAR QUANTIDADE DE TODOS OS ALIMENTOS;" << endl;
                    cout << "[2] VER QUANTIDADE DISPONÍVEL EM ESTOQUE;" << endl;
                    cout << "[3] REALIZAR UMA COMPRA;" << endl;
                    cout << "[4] REPOR O ESTOQUE;" << endl;
                    cout << "[5] SAIR DA NAVEGAÇÃO." << endl;
                    cin >> opcao1;

                    switch(opcao1){
                        case 1:{
                            int acucar, leite, cafe, arroz, feijao;
                            cout << "AÇÚCAR: "; cin >> acucar;
                            cout << "LEITE: "; cin >> leite;
                            cout << "CAFÉ: "; cin >> cafe;
                            cout << "ARROZ: "; cin >> arroz;
                            cout << "FEIJÃO: "; cin >> feijao;

                            loja1.set_acucar(acucar); loja1.set_arroz(arroz); loja1.set_cafe(cafe);
                            loja1.set_feijao(feijao); loja1.set_leite(leite);

                        }break;
                        case 2:{
                            cout << "QUANTIDADE DISPONÍVEL EM ESTOQUE!\n" << endl;
                            cout << "AÇÚCAR: "<< loja1.get_acucar() << endl;
                            cout << "LEITE: "<< loja1.get_leite() << endl;
                            cout << "CAFÉ: "<< loja1.get_cafe() << endl;
                            cout << "ARROZ: "<< loja1.get_arroz() << endl;
                            cout << "FEIJÃO: "<< loja1.get_feijao() << endl;
                        }break;
                        case 3:{
                            int acucar = loja1.get_acucar(), leite = loja1.get_leite(), cafe = loja1.get_cafe(), arroz = loja1.get_arroz(), feijao = loja1.get_feijao();
                            int op = 0;
                            int total[5] = {0, 0, 0, 0, 0};

                            while(op!=6){
                                cout << "SELECIONE QUAL PRODUTO DESEJA COMPRAR:\n" << endl;
                                cout << "[1] AÇÚCAR; [2] LEITE; [3] CAFÉ; [4] ARROZ; [5] FEIJÃO; [6] FINALIZAR COMPRA" << endl;
                                cin >> op;
    
                                int qtd = 0;
                                    switch(op){
                                        case 1:{
                                            if(acucar == 0){cout << "Produto indisponível!" << endl; break;}
                                            else{
                                                cout << "Selecione a quantidade desejada: "; cin >> qtd;
                                                if(qtd > acucar){
                                                    cout << "Quantidade indisponível! Total em estoque: " << acucar << endl;
                                                }
                                                else{
                                                    cout << "Compra realizada com sucesso!" << endl;
                                                    total[0] = qtd;
                                                    loja1.comprar(1, qtd);
                                                }
                                            }
                                        }break;
                                        case 2:{
                                            if(leite == 0){cout << "Produto indisponível!" << endl; break;}
                                            else{
                                                cout << "Selecione a quantidade desejada: "; cin >> qtd;
                                                if(qtd > leite){
                                                    cout << "Quantidade indisponível! Total em estoque: " << leite << endl;
                                                }
                                                else{
                                                    cout << "Compra realizada com sucesso!" << endl;
                                                    total[1] = qtd;
                                                    loja1.comprar(2, qtd);
                                                }
                                            }
                                        }break;
                                        case 3:{
                                            if(cafe == 0){cout << "Produto indisponível!" << endl; break;}
                                            else{
                                                cout << "Selecione a quantidade desejada: "; cin >> qtd;
                                                if(qtd > cafe){
                                                    cout << "Quantidade indisponível! Total em estoque: " << cafe << endl;
                                                }
                                                else{
                                                    cout << "Compra realizada com sucesso!" << endl;
                                                    total[2] = qtd;
                                                    loja1.comprar(3, qtd);
                                                }
                                            }
                                        }break;
                                        case 4:{
                                            if(arroz == 0){cout << "Produto indisponível!" << endl; break;}
                                            else{
                                                cout << "Selecione a quantidade desejada: "; cin >> qtd;
                                                if(qtd > arroz){
                                                    cout << "Quantidade indisponível! Total em estoque: " << arroz << endl;
                                                }
                                                else{
                                                    cout << "Compra realizada com sucesso!" << endl;
                                                    total[3] = qtd;
                                                    loja1.comprar(4, qtd);
                                                }
                                            }
                                        }break;
                                        case 5:{
                                            if(feijao == 0){cout << "Produto indisponível!" << endl; break;}
                                            else{
                                                cout << "Selecione a quantidade desejada: "; cin >> qtd;
                                                if(qtd > feijao){
                                                    cout << "Quantidade indisponível! Total em estoque: " << feijao << endl;
                                                }
                                                else{
                                                    cout << "Compra realizada com sucesso!" << endl;
                                                    total[4] = qtd;
                                                    loja1.comprar(5, qtd);
                                                }
                                            }
                                        }break;
                                    }
                            }
                            cout << "PRODUTOS COMPRADOS:" << endl;
                            cout << "AÇÚCAR: " << total[0] << endl;
                            cout << "LEITE: " << total[1] << endl;
                            cout << "CAFÉ: " << total[2] << endl;
                            cout << "ARROZ: " << total[3] << endl;
                            cout << "FEIJÃO: " << total[4] << endl;
                        }break;
                        case 4:{
                            int op = 0;
                            int acucar = loja1.get_acucar(), leite = loja1.get_leite(), cafe = loja1.get_cafe(), arroz = loja1.get_arroz(), feijao = loja1.get_feijao();
                            while(op != 6){
                                cout << "REPOSIÇÃO DE ESTOQUE! SELECIONE QUAL PRODUTO VOCÊ DESEJA REPOR:" << endl;
                                cout << "[1] AÇÚCAR; [2] LEITE; [3] CAFÉ; [4] ARROZ; [5] FEIJÃO; [6] FINALIZAR REPOSIÇÃO" << endl;
                                cin >> op;

                                int qtd;

                                switch(op){
                                    case 1:{
                                        cout << "OPÇÃO SELECIONADA: [1] AÇÚCAR" << endl;
                                        cout << "Quantidade a acrescentar: "; cin >> qtd;

                                        if(qtd < 0){
                                            cout << "Quantidade inválida!" << endl;
                                            break;
                                        }
                                        else{
                                            loja1.repor(1, qtd);
                                        }
                                    }break;
                                    case 2:{
                                        cout << "OPÇÃO SELECIONADA: [2] LEITE" << endl;
                                        cout << "Quantidade a acrescentar: "; cin >> qtd;

                                        if(qtd < 0){
                                            cout << "Quantidade inválida!" << endl;
                                            break;
                                        }
                                        else{
                                            loja1.repor(2, qtd);
                                        }
                                    }break;
                                    case 3:{
                                        cout << "OPÇÃO SELECIONADA: [3] CAFÉ" << endl;
                                        cout << "Quantidade a acrescentar: "; cin >> qtd;

                                        if(qtd < 0){
                                            cout << "Quantidade inválida!" << endl;
                                            break;
                                        }
                                        else{
                                            loja1.repor(3, qtd);
                                        }
                                    }break;
                                    case 4:{
                                        cout << "OPÇÃO SELECIONADA: [4] ARROZ" << endl;
                                        cout << "Quantidade a acrescentar: "; cin >> qtd;

                                        if(qtd < 0){
                                            cout << "Quantidade inválida!" << endl;
                                            break;
                                        }
                                        else{
                                            loja1.repor(4, qtd);
                                        }
                                    }break;
                                    case 5:{
                                        cout << "OPÇÃO SELECIONADA: [5] FEIJÃO" << endl;
                                        cout << "Quantidade a acrescentar: "; cin >> qtd;

                                        if(qtd < 0){
                                            cout << "Quantidade inválida!" << endl;
                                            break;
                                        }
                                        else{
                                            loja1.repor(5, qtd);
                                        }
                                    }break;
                                }
                            }
                        }
                    }
                }
            }break;
        }

    }
    return 0;

}