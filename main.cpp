#include "DEFINICIONES_SUDOKU.h"
#include "SUDOKU_3x3.h"
#include "SUDOKU_2x2.h"

void menu(SUDOKU_3x3 &SUDOKU_3x3_1, SUDOKU_2x2 &SUDOKU_2x2_1);

int main() {

    SUDOKU_3x3 SUDOKU_3x3_1;
    SUDOKU_2x2 SUDOKU_2x2_1;
    menu(SUDOKU_3x3_1, SUDOKU_2x2_1);

    return 0;
}



void menu(SUDOKU_3x3 &SUDOKU_3x3_1, SUDOKU_2x2 &SUDOKU_2x2_1){
    TipoUnsigned Opcion=0,Opcionsub1=0,Opcionsub2=0,
            Opcionsub3=0,Opcionsub4=0;
    TipoLongSudoku tamanio=0, subtamanio=0, veces=0;
    do{
        Menu();
        do{
            cout<<"Selecciona una opcion: ";
            cin>>Opcion;
        } while(Opcion<1 || Opcion>3);
        switch (Opcion){
            case 1:
                do{
                    Submenu1();
                    do{//Submenu1
                        cout<<"Selecciona una Subopcion 1: ";
                        cin>>Opcionsub1;
                    } while(Opcionsub1<1 || Opcionsub1>3);
                    switch (Opcionsub1){
                        case 1://CREA SUDOKU 3x3
                            tamanio=longitud3x3;
                            subtamanio=sublongitud3x3;
                            SUDOKU_3x3_1.set_sublongitudsudoku(subtamanio);
                            SUDOKU_3x3_1.set_longitudsudoku(tamanio);
                            SUDOKU_3x3_1.ConstruyeMatrizdinamica();
                            do{//Submenu2
                                Submenu2();
                                do{
                                    cout<<"Selecciona una Subopcion 2: ";
                                    cin>>Opcionsub2;
                                } while(Opcionsub2<1 || Opcionsub2>4);
                                switch (Opcionsub2){
                                    case 1:
                                        SUDOKU_3x3_1.DefineCaractSudoku();
                                        break;
                                    case 2:
                                        do{//Submenu3
                                            Submenu3();
                                            do{
                                                cout<<"Selecciona una Subopcion 3: ";
                                                cin>>Opcionsub3;
                                            } while(Opcionsub3<1 ||
                                                    Opcionsub3>5);
                                            switch (Opcionsub3){
                                                case 1:
                                                    SUDOKU_3x3_1.ImprimirSudoku();
                                                    break;
                                                case 2:
                                                    SUDOKU_3x3_1.LlenarSudokualeat();
                                                    break;
                                                case 3:
                                                    SUDOKU_3x3_1.LlenarSudokualeatcorrect1();
                                                    break;
                                                case 4:
                                                    SUDOKU_3x3_1.GenerarSudokuvalidojuego();
                                                    break;
                                            }
                                        }while(Opcionsub3!=5);//
                                        break;
                                    case 3:
                                        do{//Submenu4
                                            Submenu4();
                                            do{
                                                cout<<"Selecciona una Subopcion 4: ";
                                                cin>>Opcionsub4;
                                            } while(Opcionsub4<1 ||
                                                    Opcionsub4>5);
                                            switch (Opcionsub4){
                                                case 1:
                                                    SUDOKU_3x3_1.LlenarCasillavacia();
                                                    break;
                                                case 2:
                                                    SUDOKU_3x3_1.BorrarCasillaLlenada();
                                                    break;
                                                case 3:
                                                    if(veces<3) {
                                                        veces++;
                                                        SUDOKU_3x3_1.MostrarSugerencia();
                                                    }
                                                    else{
                                                        cout<<"\n Superaste las cantidades de sugerencias admisibles";
                                                    }
                                                    break;
                                                case 4:
                                                    SUDOKU_3x3_1.ResolverSudoku();
                                                    break;
                                            }
                                            if (!SUDOKU_3x3_1.SudokuCompleto()){
                                                cout<<"--~~~++++##### FELICIDADES TERMINASTE EL JUEGO #####++++~~~--"<<endl;
                                                SUDOKU_3x3_1.SiSudoku();
                                                Opcionsub4=5;
                                            }
                                        }while(Opcionsub4!=5 && Opcionsub4!=4);//
                                        break;
                                }
                            }while(Opcionsub2!=4);//
                            break;
                        case 2://CREA SUDOKU 2x2
                            tamanio=longitud2x2;
                            subtamanio=sublongitud2x2;
                            SUDOKU_2x2_1.set_sublongitudsudoku(subtamanio);
                            SUDOKU_2x2_1.set_longitudsudoku(tamanio);
                            SUDOKU_2x2_1.ConstruyeMatrizdinamica();
                            do{//Submenu2
                                Submenu2();
                                do{
                                    cout<<"Selecciona una Subopcion 2: ";
                                    cin>>Opcionsub2;
                                } while(Opcionsub2<1 || Opcionsub2>4);
                                switch (Opcionsub2){
                                    case 1:
                                        SUDOKU_2x2_1.DefineCaractSudoku();
                                        break;
                                    case 2:
                                        do{//Submenu3
                                            Submenu3();
                                            do{
                                                cout<<"Selecciona una Subopcion 3: ";
                                                cin>>Opcionsub3;
                                            } while(Opcionsub3<1 ||
                                                    Opcionsub3>5);
                                            switch (Opcionsub3){
                                                case 1:
                                                    SUDOKU_2x2_1.ImprimirSudoku();
                                                    break;
                                                case 2:
                                                    SUDOKU_2x2_1.LlenarSudokualeat();
                                                    break;
                                                case 3:
                                                    SUDOKU_2x2_1.LlenarSudokualeatcorrect1();
                                                    break;
                                                case 4:
                                                    SUDOKU_2x2_1.GenerarSudokuvalidojuego();
                                                    break;
                                            }
                                        }while(Opcionsub3!=5);//
                                        break;
                                    case 3:
                                        do{//Submenu4
                                            Submenu4();
                                            do{
                                                cout<<"Selecciona una Subopcion 4: ";
                                                cin>>Opcionsub4;
                                            } while(Opcionsub4<1 ||
                                                    Opcionsub4>5);
                                            switch (Opcionsub4){
                                                case 1:
                                                    SUDOKU_2x2_1.LlenarCasillavacia();
                                                    break;
                                                case 2:
                                                    SUDOKU_2x2_1.BorrarCasillaLlenada();
                                                    break;
                                                case 3:
                                                    //FALTA MOSTRAR SUGERENCIA
                                                    break;
                                                case 4:
                                                    SUDOKU_2x2_1.ResolverSudoku();
                                                    break;
                                            }
                                            if (!SUDOKU_2x2_1.SudokuCompleto()){
                                                cout<<"--~~~++++##### FELICIDADES TERMINASTE EL JUEGO #####++++~~~--"<<endl;
                                                SUDOKU_2x2_1.SiSudoku();
                                                Opcionsub4=5;
                                            }
                                        }while(Opcionsub4!=5 && Opcionsub4!=4);//
                                        break;
                                }
                            }while(Opcionsub2!=4);//
                            break;
                    }
                }while(Opcionsub1!=3);
                break;
            case 2:
                cout<<"\n Ft. Kimberly \n Ft. Belen \n Ft. Julian \n";
                break;
        }
    }while(Opcion!=3 && Opcionsub4!=5 && Opcionsub4!=4);

    if (tamanio==9)
        SUDOKU_3x3_1.DestruyeMatrizdinamica();
    else if (tamanio==4)
        SUDOKU_2x2_1.DestruyeMatrizdinamica();

    cout<<"\n ¿Qué pasa causa? ;v \n";
}