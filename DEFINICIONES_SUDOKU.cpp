//
// Created by shiro on 24/11/18.
//

#include "DEFINICIONES_SUDOKU.h"


void Menu() {
    cout << "\n\n~~~ M E N U ~~~ S U D O K U ~~~\n\n";
    cout << "1. Escoger tipo de SUDOKU que desea"
            "(3x3 o 2x2...) \n";//Submenu1
    cout << "2. Ver los créditos B/! \n";//Horacio
    cout << "3. No quiero jugar. Salir D= ... \n\n";//Fin
}

void Submenu1() {
    cout << "\n\n~~~ T I P O ~~~ S U D O K U ~~~\n\n";
    cout << "1. SUDOKU 3x3  ... \n";//Submenu2
    cout << "2. SUDOKU 2x2  ... \n";//Submenu2
    cout << "3. Volver al Menu anterior ... \n\n";
}

void Submenu2() {
    cout << "\n\n~~~ P A N E L ~~~ S U D O K U ~~~\n\n";
    cout << "1. Definir características del SUDOKU "
            "(simbolos borde, casillas vacias...) \n";
    cout << "2. Acciones \n";//Submenu 3
    cout << "3. Empezar a jugar SUDOKU \n";//Submenu 4
    cout << "4. Regresar al Menu anterior ... \n\n";
}

void Submenu3() {
    cout << "\n\n~~~ A C C I O N E S ~~~ S U D O K U ~~~\n\n";
    cout << "1. Construir el Esqueleto SUDOKU  ... \n";
    cout << "2. Elaborar un SUDOKU lleno aleatoriamente  ... \n";
    cout << "3. Elaborar un SUDOKU lleno aleatoriamente correcto ... \n";
    cout << "4. Elaborar un SUDOKU para iniciar el juego ... \n";
    cout << "5. Regresar al Menu anterior ... \n\n";
}

void Submenu4() {
    cout << "\n\n~~~ M O D O ~~~ J U E G O ~~~ S U D O K U ~~~\n\n";
    cout << "1. Llenar una casilla vacia  ... \n";
    cout << "2. Borrar casilla llenada  ... \n";
    cout << "3. Mostrar Sugerencia según casilla ... \n";
    cout << "4. Resolver el SUDOKU y Terminar el juego  ... \n";
    cout << "5. Me rindo  ... \n\n";
}
