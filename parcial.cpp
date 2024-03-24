#include <iostream>
#include <malloc.h>
using namespace std;

struct Cliente { 
    int numeroCuenta;
    int tipoCuenta;
    Cliente *sig;
};

Cliente *cabPreferencial = NULL;
Cliente *cabTradicional = NULL;

void registrarCliente ( int numeroCuenta , int tipoCuenta) {
    Cliente *nuevoCliente = ( Cliente* ) malloc (sizeof (Cliente));
    cout<< "registrar numero de cuenta: ";
    cin>>nuevoCliente->numeroCuenta;
    cout<< "registar tipo de cunente: ";
    cin>>nuevoCliente->tipoCuenta;
    nuevoCliente-> sig = NULL;

    if (tipoCuenta == 1 ){
        if (cabPreferencial == NULL){
            cabPreferencial = nuevoCliente;
        }else {
            Cliente* temp = cabPreferencial;
            while (temp->sig != NULL) {
                temp = temp->sig;
            }
            temp->sig = nuevoCliente;
        }
    }else if (tipoCuenta == 2) {
        if (cabTradicional == NULL) {
            cabTradicional = nuevoCliente;
        }else {
            Cliente* temp = cabTradicional;
            while (temp ->sig != NULL) {
                temp = temp->sig;
            }
            temp->sig = nuevoCliente;
        }
     }

     int countTradicional = 0;
     Cliente* temp = cabTradicional;
     while (temp != NULL) {
        countTradicional++;
        temp = temp ->sig;
     }
     
     int countPreferencial = 0;
     temp = cabPreferencial;
     while ( temp != NULL) {
        countPreferencial++;
        temp = temp ->sig;
     }

     if ( countTradicional >= 5 && countPreferencial <= 2 ) {

        Cliente* clienteAMover=  cabTradicional;
        Cliente* anterior = NULL;
        for (int i = 0; i < 2; i++) {
            anterior = clienteAMover;
            clienteAMover = clienteAMover->sig;

        }
        anterior ->sig = clienteAMover->sig;
        clienteAMover-> sig = NULL;
        clienteAMover->tipoCuenta = 1;

        temp = cabPreferencial;
        while (temp -> sig != NULL) {
            temp = temp->sig;
        }
        temp->sig = clienteAMover;
     }
}

void visualizarFila(Cliente* cabeza) {
Cliente* temp = cabeza;
int count = 1;
while (temp != NULL) {
    cout << "Cliente" << count << " : " << temp->numeroCuenta << endl;
    temp = temp ->sig;
    count++;

 }
}
void reasignarTurnos(){

    Cliente* temp = cabPreferencial;
    int count = 1;
    while (temp != NULL) {
        temp -> numeroCuenta = count;
        temp = temp->sig;
        count++;

    }

    temp = cabTradicional;
    count =1;
    while (temp != NULL) {
        temp-> numeroCuenta = count;
        temp = temp ->sig;
        count++;
    }

}

void atenderCliente(int tipoCuenta) {
    if (tipoCuenta == 1 && cabPreferencial != NULL){ 
           Cliente* clienteAtendido = cabPreferencial;
    cabPreferencial = cabPreferencial-> sig;
    free(clienteAtendido);
} else if (tipoCuenta == 2 && cabTradicional != NULL) {
    Cliente* clienteAtendido = cabTradicional;
    cabTradicional = cabTradicional->sig;
    free(clienteAtendido);

}
}


int main(){
    int opcion;
    do{
        cout<< "Menu de opciones:" << endl;
        cout<< "1. Registrar cliente preferencial" << endl;
        cout<< "2. Registrar cliente tradidcional" << endl;
        cout<< "3. Visualizar filas" << endl;
        cout<< "4. Reasignar turnos" << endl;
        cout<< "5. Atender cliente preferencial" << endl;
        cout<< "6. Atender cliente tradicional" << endl;
        cout<< "7. salir" << endl;
        cout<< "Seleccione una opcion: ";
        cin>> opcion;

        switch (opcion ) {
            case 1:
                 registrarCliente(12345,1);
                 break;
           case 2:
                registrarCliente(67890,2);
                break;

           case 3:
                 cout << "Fila Preferencial:" << endl;
                 visualizarFila(cabPreferencial);
                 cout << "Fila Tradicional:" << endl;
                 visualizarFila(cabTradicional);
                 break;
           case 4:
                reasignarTurnos();

                break;
            case 5:
                 atenderCliente(1);
                 break;
           case 6:
                atenderCliente(2);
                break;
            case 7:
                cout << "Gracias por usar el sistema." << endl;
                break;
            default:
            cout << "Opcion no valida, intente de nuevo." << endl;
                   
        }
    } while (opcion != 7);
    
    return 0;

}