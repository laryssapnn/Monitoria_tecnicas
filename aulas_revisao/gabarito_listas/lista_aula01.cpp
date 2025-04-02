#include <iostream>
#include <windows.h> //Consigo alterar a língua para português com essa biblioteca
using namespace std;


//Questão 2:

/*int main(){
    SetConsoleOutputCP(CP_UTF8); //Colocando em português do Brasil...
    int a, b;

    cout << "Digite o valor de a: "; cin >> a;
    cout << "Digite o valor de b: "; cin >> b;

    cout << "\nSOMA: " << a+b << endl;
    cout << "SUBTRAÇÃO: " << a-b << endl;
    cout << "MULTIPLICAÇÃO: " << a*b << endl;

    if(b == 0){
        cout << "Operação de divisão inválida!" << endl;
        return 1;
    }
    else{
        cout << "DIVISÃO: " << (float(a))/float(b) << endl;
    }

    a++
    b++

    cout << "a deslocado: " << (a << 2) << endl;
    cout << "b deslocado: " << (b << 2) << endl;

    return 0;
}
*/

//Questão 3:

/*int main(){
    SetConsoleOutputCP(CP_UTF8); //Colocando em português do Brasil...
    int nota;

    cout << "Digite uma nota de 0 a 100: "; cin >> nota;

    if(nota < 0 || nota > 100){cout << "Valor inválido!" << endl; return 1;}

    else{

        if(nota >= 90 && nota <= 100){
            cout << "CONCEITO A" << endl;
        }
        else if(nota >= 80 && nota <= 89){
            cout << "CONCEITO B" << endl;
        }
        else if(nota >= 70 && nota <= 79){
            cout << "CONCEITO C" << endl;
        }
        else if(nota >= 60 && nota <= 79){
            cout << "CONCEITO D" << endl;
        }
        else{
            cout << "CONCEITO E" << endl;
        }
    }
    return 0;
}
*/

//Questão 4

/*int main(){
    SetConsoleOutputCP(CP_UTF8); //Colocando em português do Brasil...
    int opcao;
    float qtd;

    cout << "Para qual moeda você deseja fazer a conversão?\n" << endl;
    cout << "[1] Real(R$) --> Dólar(U$D)" << endl;
    cout << "[2] Real(R$) --> Euro(EUR)" << endl;
    cout << "[3] Real(R$) --> Libra Esterlina(GBP)" << endl;
    cin >> opcao;

    cout << "Qual a quantia em dinheiro deseja converter? "; cin >> qtd;

    switch(opcao){
        case 1:{
            cout << "R$ " << qtd << " --> " << "U$D " << qtd/5.74 << endl;
        } break;
        case 2:{
            cout << "R$ " << qtd << " --> " << "EUR " << qtd/6.19 << endl;
        } break;
        case 3:{
            cout << "R$ " << qtd << " --> " << "GBP " << qtd/7.2 << endl;
        } break;
        default:{
            cout << "Opção Inválida!" << endl;
            return 1;
        }
    }
    return 0;

}
*/

//Questão 5

/*int main(){
    SetConsoleOutputCP(CP_UTF8); //Colocando em português do Brasil...
    float nota = 0;
    int counter = 0;
    float soma = 0;

    while(nota != (-1)){

        cout << "Digite o valor da " << counter + 1 <<"ª nota: ";
        cin >> nota;

        soma += nota;
        counter++;
    }
    float media = (soma+1)/(counter-1);
    // soma + 1 e counter - 1 pois mesmo digitando -1, o código entende que aquilo é mais uma nota para somar e,
    //consequentemente aumentar o counter
    cout << "MÉDIA CALCULADA: " << media << endl;
}
*/

//Questão 6

/*int main(){
    SetConsoleOutputCP(CP_UTF8); //Colocando em português do Brasil...

    float nota = 0;
    int counter = 0;
    float soma = 0;

    do{
        cout << "Digite o valor da " << counter + 1 <<"ª nota: ";
        cin >> nota;

        soma += nota;
        counter++;
    }
    while(nota != (-1));

    float media = (soma+1)/(counter-1);
    // soma + 1 e counter - 1 pois mesmo digitando -1, o código entende que aquilo é mais uma nota para somar e,
    //consequentemente aumentar o counter

    cout << "MÉDIA CALCULADA: " << media << endl;
}
*/

//Questão 7

/*int main(){
    SetConsoleOutputCP(CP_UTF8); //Colocando em português do Brasil...

    int n;
    cout << "Digite o valor de n: "; cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j <= i; j++){
            cout << "*";
        }
        cout << endl;
    }
}
*/
