#include <iostream>
#include <cmath>
using namespace std;

double velocidade (double lambda, double f0, double ff){
    double v = 0;
    int qtd_it = 0;
    for(double i = f0; i <= ff; i++){
        v += lambda * i;
        qtd_it += 1;
    }
    double v_media = v / (qtd_it);
    return v_media;
}

float eq2grau(float a, float b, float c){
    //ax2 + bx + c = 0
    // delta = b2 - 4*a*c
    float x1, x2;
    if(a == 0){
        //Equação do 1º grau
        //bx + c = 0 >> bx = -c >> x = -c/b;
        cout << "Equação do primeiro grau, raíz única!" << endl;
        cout << "X = " << -c/b << endl;
    }
    float delta = b*b - 4 * a * c;
    if(delta == 0){
        //x = (-b + 0)/2*a
        cout << "Raízes reais iguais!" << endl;
        cout << "X' = X'' = " << -b/(2*a) << endl;
    }
    else if(delta > 0){
        x1 = (-b + sqrt(delta)) / (2*a);
        x2 = (-b - sqrt(delta)) / (2*a);

        cout << "Raízes reais distintas!" << endl;
        cout << "X1 = " << x1 << endl;
        cout << "X2 = " << x2 << endl;
    }
    else{
        x1 = (-b + sqrt(abs(delta))) / (2*a);
        x2 = (-b - sqrt(abs(delta))) / (2*a);

        cout << "Raízes imaginárias distintas!" << endl;
        cout << "X' = " << x1 << " + " << abs(x2) << "i" << endl;
        cout << "X' = " << x1 << " - " << abs(x2) << "i" << endl;
    }
    return 0;

}

int main(){
    int opcao = 100;
    while(opcao != 0){
    cout << "Escolha a opção desejada de 1 a 5. Digite 0 para sair." << endl;
    cin >> opcao;

    if(opcao > 5){
        cout << "ERRO" << endl;
    }
    
    switch(opcao){
        case 1:{
            int x, y;

            cout << "Digite x e y, respectivamente: " << endl;
            cin >> x >> y;

            if(x < y)
            cout << x << " < " << y;

            else if (x == y)
            cout << x << " = " << y;

            else{
                cout << x << " é maior que " << y << " em " << x-y << " unidades\n\n";
                cout << "Números entre " << y << " e " << x << ":\n\n";

                for(int i = y+1; i < x; i++){
                    cout << i << " ";
                }
                cout << endl;
            }
            break;
        }
        case 2:{
            // a = 01100001
            // a << 2 = 10000100
            // (a << 2) & 128 = 10000100 & 10000000 = 10000000
            char a;
            int n;

            cout << "Digite o caracter: ";
            cin >> a;

            cout << "Bit: ";
            cin >> n;

            if(n < 1 || n > 8){cout << "ERRO!" << endl; return 1;}

            int bit = (a << n-1) & 128;

            if(bit == 128){cout << "1" << endl;}
            else{cout << "0" << endl;}

            break;

        }
        case 3:{
            //assumindo o passo de 1 Hz
            double lambda, f0, ff;
            cout << "Digite o valor de lambda: ";
            cin >> lambda;
            cout << "f0 (em Hz): ";
            cin >> f0;
            cout << "ff (em Hz): ";
            cin >> ff;

            double v = velocidade(lambda, f0, ff);
            cout << "Velocidade Média: " << v << "m/s" << endl;
            break;
        }
        case 4:{

            float a, b, c;
            cout << "a: "; cin >> a;
            cout << "b: "; cin >> b;
            cout << "c: "; cin >> c;

            eq2grau(a, b, c);
            break;
        }
        case 5:{
            int n;
            cout << "Digite um valor entre 2 e 10: "; cin >> n;

            if(n < 2 || n > 10){cout << "ERRO!" << endl;}

            int cont = 0;

            for(int i = n; i > 0; i--){
                for(int y = 0; y < cont; y++){
                    cout << " ";
                }
                for(int x = 2*i; x > 0; x--){
                    cout << "*";
                }
                cont += 1;
                cout << endl;
            }
            
        }

    }
}
}
