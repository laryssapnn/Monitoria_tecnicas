#include <iostream>
#include <cmath>
using namespace std;

//Vd = eta * Vt * ln(Id/Is)

int main(){

    double Is = 2.6e-15;
    double Vt = 0.025852;
    double Vd;

    for(double Id = 0.0001; Id <= 0.00075; Id+=0.0001){
        cout << "VD quando Id = " << Id << ": " << endl;
        for(double eta = 1; eta <= 2; eta+=0.01){
            Vd = eta * Vt * log(Id/Is);
            cout << "eta = " << eta << " >>>>>>> VD = " << Vd << endl;
        }
    }
}
