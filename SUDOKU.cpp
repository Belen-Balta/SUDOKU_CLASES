//
// Created by shiro on 24/11/18.
//

#include "SUDOKU.h"

void SUDOKU::inicializamatrizceros() {
    for (int fil=0;fil<get_longitudsudoku();fil++){
        for(int col=0;col<get_longitudsudoku();col++){
            sudokuelaborado[fil][col]=0;
            sudokuelaboradotemporal[fil][col]=0;
            sudokuelaboradoval[fil][col]=true;}}
}

void SUDOKU::ConstruyeMatrizdinamica() {
    sudokuelaborado=new int*[get_longitudsudoku()];
    sudokuelaboradoval=new bool*[get_longitudsudoku()];
    sudokuelaboradotemporal=new int*[get_longitudsudoku()];
    for (int fil=0;fil<get_longitudsudoku();fil++){
        sudokuelaborado[fil]=new int[get_longitudsudoku()];
        sudokuelaboradoval[fil]=new bool[get_longitudsudoku()];
        sudokuelaboradotemporal[fil]=new int[get_longitudsudoku()]; }
    inicializamatrizceros();
}

void SUDOKU::DestruyeMatrizdinamica() {
    for (int fil=0;fil<get_longitudsudoku();fil++){
        delete sudokuelaborado[fil];
        delete sudokuelaboradoval[fil];
        delete sudokuelaboradotemporal[fil]; }
    delete []sudokuelaborado;
    delete []sudokuelaboradoval;
    delete []sudokuelaboradotemporal;
}

void SUDOKU::DefineCaractSudoku() {
    TipoCaracContorno contorno;TipoCaracInterior interior;
    cout<<"Que simbolo desea como contorno de la estructura:"<<'\n';cin>>contorno;
    cout<<"Que simbolo desea en las casillas vacias internas:"<<'\n';cin>>interior;
    set_ccontorno(contorno);
    set_cinterior(interior);
}

void SUDOKU::ImprimirSudoku() {
    int carentrefila=0;
    if (get_longitudsudoku()==longitud3x3)
        carentrefila=14;
    else if (get_longitudsudoku()==longitud2x2)
        carentrefila=10;
    cout<< " \ ";//FILA INICIAL  \      0   1   2     3   4   5     6   7   8
    for (int filc=0;filc<get_longitudsudoku();filc++) {
        if (filc%get_sublongitudsudoku()==0)
            cout <<"     "<<filc;
        else
            cout <<"   "<<filc;//coordenadas de las columnas
    }    cout<<endl;

    for(int fila=0;fila<get_longitudsudoku();fila++){
        if( fila%get_sublongitudsudoku()==0 ){ //si la fila es 0, 3 o 6 hago una linea para remarcar las regiones de 3x3
            cout<<"     ";
            for (int cantci=0;cantci<carentrefila*get_sublongitudsudoku();cantci++){
                cout<<get_ccontorno();} cout<<endl;
        }
        cout<<fila<<"   "<<get_ccontorno(); //cada vez que inicie una fila me muestrar el numero de la coordenada y colocar una |
        for(int columna=0;columna<get_longitudsudoku();columna++){
            if(columna%get_sublongitudsudoku()==0){
                cout<<get_ccontorno()<<" "; //si estoy comenzando en una region de 3x3 coloca una barra
            }
            if(!sudokuelaboradoval[fila][columna]){//si esta ocupada me encierra el numero entre corchetes
                cout<<"["<<sudokuelaborado[fila][columna]<<"] ";
            }

            else{ //Si no está ocupada procede lo siguiente

                if(sudokuelaborado[fila][columna]!=0){  //si es un numero diferente de 0 muestra el numero
                    cout<<" "<<sudokuelaborado[fila][columna]<<"  ";
                }
                else{ //si no es diferente de 0 muestra la casilla con un punto, eso querrá decir que esta libre
                    cout<<" "<<get_cinterior()<<"  ";
                }
            }
            //una vez muestro el valor de la casilla
            if(columna==get_longitudsudoku()-1){
                cout<<get_ccontorno()<<get_ccontorno(); //si columna==8 es dicir al final de la casilla coloco una doble barra para que se vea mejor el cuadro
            }
        }
        cout<<endl;
    }
    cout<<"     ";
    for (int cantci=0;cantci<carentrefila*get_sublongitudsudoku();cantci++){
        cout<<get_ccontorno();} cout<<endl<<endl;
}

bool SUDOKU::ValidaSudoku() {
    for (int numero = 1; numero < get_longitudsudoku() + 1; numero++) {
        int contfil = 0, contcol = 0, contsub = 0;
        for (int fil = 0; fil < get_longitudsudoku(); fil++) {
            contfil = 0;
            contcol = 0;
            for (int col = 0; col < get_longitudsudoku(); col++) {
                if (numero == sudokuelaborado[fil][col])
                    contfil++;
                if (numero == sudokuelaborado[col][fil])
                    contcol++;
                if (contfil >= 2 || contcol >= 2)
                    return true;
            }
        }
        for (int subfi = 0; subfi < get_sublongitudsudoku(); subfi++) {
            for (int subco = 0; subco < get_sublongitudsudoku(); subco++) {
                contsub = 0;
                for (int fil = 0; fil < get_sublongitudsudoku(); fil++) {
                    for (int col = 0; col < get_sublongitudsudoku(); col++) {
                        if (numero ==
                            sudokuelaborado[subfi * get_sublongitudsudoku() + fil][subco * get_sublongitudsudoku() +
                                                                                   col])
                            contsub++;
                        if (contsub >= 2)
                            return true;
                    }
                }
            }
        }
    }
    return false;
}

void SUDOKU::SiSudoku() {
    cout<<"***#####  VALIDACION SUDOKU  #####***"<<endl<<endl;
    if (ValidaSudoku())//==true
        cout<<"El Sudoku no es valido D= sorry v;"<<endl;
    else
        cout<<"El Sudoku es valido =D Yeah!"<<endl;
}

void SUDOKU::LlenarSudokualeat() {
    inicializamatrizceros();
    srand(time(NULL));
    for (int fila=0;fila<get_longitudsudoku();fila++)
    {
        for(int col=0;col<get_longitudsudoku();col++){
            sudokuelaborado[fila][col]=(rand()%get_longitudsudoku())+1;}
    }
    ImprimirSudoku();
    SiSudoku();
}

bool SUDOKU::Verificassub(int num, int pos) {
    for (int i=0;i<pos;i++){
        if(num==Vectorsub[i])
            return true;
    }
    return false;
}

void SUDOKU::transformada(int fila, int columna) {
    int l=0,r=0,u=0,d=0;
    l=columna-(columna%get_sublongitudsudoku());
    set_Lleft(l);
    r=get_Lleft()+get_sublongitudsudoku()-1;
    set_Lrigth(r);
    u=fila-(fila%get_sublongitudsudoku());
    set_Lup(u);
    d=get_Lup()+get_sublongitudsudoku()-1;
    set_Ldown(d);
}

bool SUDOKU::Colision(int fila, int columna, int num) {
    for (int col=0;col<columna;col++){
        if (num==sudokuelaborado[fila][col])
            return true;
    }
    for (int fil=0;fil<fila;fil++){
        if (num==sudokuelaborado[fil][columna])
            return true;
    }
    transformada(fila,columna);
    for (int f=get_Lup();f<=get_Ldown();f++){
        for (int c=get_Lleft();c<=get_Lrigth();c++){
            if (num==sudokuelaborado[f][c])
                return true;
        }
    }
    return false;
}

void SUDOKU::LlenarSudokualeatcorrect1() {
    for (int fila=0;fila<get_longitudsudoku();fila++){
        for(int col=0;col<get_longitudsudoku();col++){
            sudokuelaborado[fila][col]=0;
        }
    }
    if (get_longitudsudoku()==4){
        srand(time(NULL));
        /*random_device rd;   // non-deterministic generator
        mt19937 gen(rd());  // to seed mersenne twister.
        uniform_int_distribution<int> dist(1,get_longsudoku()); //distribute results between 1 and 6 inclusive.            num=dist(gen);*/
        int num=0;
        for (int fila=0;fila<get_longitudsudoku();fila++){
            srand(time(NULL));
            for(int col=0;col<get_longitudsudoku();col++){
                srand(time(NULL));
                num=(rand()%get_longitudsudoku())+1;
                while(Colision(fila,col,num)==true){
                    num=(rand()%get_longitudsudoku())+1;
                }
                sudokuelaborado[fila][col]=num;
            }
            cout<<endl;
        }
        ImprimirSudoku();
        SiSudoku();
    }







    else if(get_longitudsudoku()==9){
        srand(time(NULL));
        Vectorsub=new TipoLongSudoku[get_longitudsudoku()];
        int num=0,i=-1;
        for (int fila=0;fila<get_sublongitudsudoku();fila++){
            for(int col=0;col<get_sublongitudsudoku();col++){
                i++;
                num=(rand()%9)+1;
                bool repitici=true;
                while(Verificassub(num,i)==true){
                    num=(rand()%9)+1;
                }
                Vectorsub[i]=num;
                sudokuelaborado[fila][col]=num;
            }
        }
        sudokuelaborado[0][3]=sudokuelaborado[2][0];
        sudokuelaborado[0][4]=sudokuelaborado[2][1];
        sudokuelaborado[0][5]=sudokuelaborado[2][2];

        sudokuelaborado[1][3]=sudokuelaborado[0][0];
        sudokuelaborado[1][4]=sudokuelaborado[0][1];
        sudokuelaborado[1][5]=sudokuelaborado[0][2];

        sudokuelaborado[2][3]=sudokuelaborado[1][0];
        sudokuelaborado[2][4]=sudokuelaborado[1][1];
        sudokuelaborado[2][5]=sudokuelaborado[1][2];

        sudokuelaborado[0][6]=sudokuelaborado[1][0];
        sudokuelaborado[0][7]=sudokuelaborado[1][1];
        sudokuelaborado[0][8]=sudokuelaborado[1][2];

        sudokuelaborado[1][6]=sudokuelaborado[2][0];
        sudokuelaborado[1][7]=sudokuelaborado[2][1];
        sudokuelaborado[1][8]=sudokuelaborado[2][2];

        sudokuelaborado[2][6]=sudokuelaborado[0][0];
        sudokuelaborado[2][7]=sudokuelaborado[0][1];
        sudokuelaborado[2][8]=sudokuelaborado[0][2];
        //Se rellenan los cuadros de la izquierda

        sudokuelaborado[3][0]=sudokuelaborado[0][2];
        sudokuelaborado[4][0]=sudokuelaborado[1][2];
        sudokuelaborado[5][0]=sudokuelaborado[2][2];

        sudokuelaborado[3][1]=sudokuelaborado[0][0];
        sudokuelaborado[4][1]=sudokuelaborado[1][0];
        sudokuelaborado[5][1]=sudokuelaborado[2][0];

        sudokuelaborado[3][2]=sudokuelaborado[0][1];
        sudokuelaborado[4][2]=sudokuelaborado[1][1];
        sudokuelaborado[5][2]=sudokuelaborado[2][1];

        sudokuelaborado[6][0]=sudokuelaborado[0][1];
        sudokuelaborado[7][0]=sudokuelaborado[1][1];
        sudokuelaborado[8][0]=sudokuelaborado[2][1];

        sudokuelaborado[6][1]=sudokuelaborado[0][2];
        sudokuelaborado[7][1]=sudokuelaborado[1][2];
        sudokuelaborado[8][1]=sudokuelaborado[2][2];

        sudokuelaborado[6][2]=sudokuelaborado[0][0];
        sudokuelaborado[7][2]=sudokuelaborado[1][0];
        sudokuelaborado[8][2]=sudokuelaborado[2][0];

        //Se rellena el cuadro central y derecho-centro
        sudokuelaborado[3][3]=sudokuelaborado[5][0];
        sudokuelaborado[3][4]=sudokuelaborado[5][1];
        sudokuelaborado[3][5]=sudokuelaborado[5][2];

        sudokuelaborado[4][6]=sudokuelaborado[5][0];
        sudokuelaborado[4][7]=sudokuelaborado[5][1];
        sudokuelaborado[4][8]=sudokuelaborado[5][2];

        sudokuelaborado[5][3]=sudokuelaborado[4][0];
        sudokuelaborado[5][4]=sudokuelaborado[4][1];
        sudokuelaborado[5][5]=sudokuelaborado[4][2];

        sudokuelaborado[3][6]=sudokuelaborado[4][0];
        sudokuelaborado[3][7]=sudokuelaborado[4][1];
        sudokuelaborado[3][8]=sudokuelaborado[4][2];

        sudokuelaborado[5][6]=sudokuelaborado[3][0];
        sudokuelaborado[5][7]=sudokuelaborado[3][1];
        sudokuelaborado[5][8]=sudokuelaborado[3][2];

        sudokuelaborado[4][3]=sudokuelaborado[3][0];
        sudokuelaborado[4][4]=sudokuelaborado[3][1];
        sudokuelaborado[4][5]=sudokuelaborado[3][2];

        // Se rellena el cuadro central y derecho-centro
        sudokuelaborado[6][3]=sudokuelaborado[8][0];
        sudokuelaborado[6][4]=sudokuelaborado[8][1];
        sudokuelaborado[6][5]=sudokuelaborado[8][2];

        sudokuelaborado[6][6]=sudokuelaborado[7][0];
        sudokuelaborado[6][7]=sudokuelaborado[7][1];
        sudokuelaborado[6][8]=sudokuelaborado[7][2];

        sudokuelaborado[7][3]=sudokuelaborado[6][0];
        sudokuelaborado[7][4]=sudokuelaborado[6][1];
        sudokuelaborado[7][5]=sudokuelaborado[6][2];

        sudokuelaborado[7][6]=sudokuelaborado[8][0];
        sudokuelaborado[7][7]=sudokuelaborado[8][1];
        sudokuelaborado[7][8]=sudokuelaborado[8][2];

        sudokuelaborado[8][3]=sudokuelaborado[7][0];
        sudokuelaborado[8][4]=sudokuelaborado[7][1];
        sudokuelaborado[8][5]=sudokuelaborado[7][2];

        sudokuelaborado[8][6]=sudokuelaborado[6][0];
        sudokuelaborado[8][7]=sudokuelaborado[6][1];
        sudokuelaborado[8][8]=sudokuelaborado[6][2];


        ImprimirSudoku();
        SiSudoku();
    }

    for (int fila=0;fila<get_longitudsudoku();fila++)
        for (int columna=0;columna<get_longitudsudoku();columna++)
            sudokuelaboradotemporal[fila][columna]=sudokuelaborado[fila][columna];
}

void SUDOKU::GenerarSudokuvalidojuego() {
    int dificultad;
    cout<<"Generador de sudokus\n\nIntroduce una dificultad (5-75): ";
    cin>>dificultad;
    if (!dificultad) dificultad = 40;
    else if (dificultad<5) dificultad = 5;
    else if (dificultad>75) dificultad = 75;
    printf("\nDificultad seleccionada: %i\nSudoku:\n",dificultad);

    for (int i=0;i<get_longitudsudoku();i++) {
        for (int j=0;j<get_longitudsudoku();j++) {
            if((rand()%(81))<dificultad)
                sudokuelaborado[i][j]=0;
        }
    }

    for (int i=0;i<get_longitudsudoku();i++){
        for(int j=0;j<get_longitudsudoku();j++){
            if (sudokuelaborado[i][j]!=0)
                sudokuelaboradoval[i][j]=false;
        }
    }
    cout<<endl<<"***#####  INICIO DEL JUEGO  #####***"<<endl;
    ImprimirSudoku();
}

void SUDOKU::ValidarCoordenada() {
    int fi, co;
    cout<<"\n \n Ingrese fila"<<endl;  //leo la fila
    cin>>fi;set_cordefi(fi);
    while(!(get_cordefi()>=0 && get_cordefi()<get_longitudsudoku())){ //valido la fila
        cout<<"Ingrese la fila de nuevo"<<endl;
        cin>>fi;
    }
    set_cordefi(fi);

    cout<<"Ingrese columna"<<endl;  //leo columna
    cin>>co;set_cordeco(co);
    while(!(get_cordeco()>=0 && get_cordeco()<get_longitudsudoku())){ //valido la columna
        cout<<"Ingrese la columna de nuevo"<<endl;
        cin>>co;
    }
    set_cordeco(co);
}

void SUDOKU::ValidarNumeroI() {
    int valornumerico;
    cout<<"ingrese valor de la casilla"<<endl;
    cin>>valornumerico;set_valorcasilla(valornumerico);
    while(!(get_valorcasilla()>=1 && get_valorcasilla()<=get_longitudsudoku())){ //mientra el numero no este entre 1 y 9 se vuelve a pedir que lo ingrese
        cout<<"ingrese el numero de nuevo"<<endl;
        cin>>valornumerico;
    }
    set_valorcasilla(valornumerico);
}

bool SUDOKU::SudokuCompleto() {
    for (int i=0; i<9; i++){
        for(int j=0;j<9;j++){
            if(sudokuelaborado[i][j]==0){ //si hay un cero en la matriz retorna falso
                return true;
            }
        }
    }
    return false;}

void SUDOKU::LlenarCasillavacia() {
    int continuar=0;
    do{
        cout<<"***#####  JUGANDO  #####***"<<endl;
        ValidarCoordenada();
        if(sudokuelaboradoval[get_cordefi()][get_cordeco()]){  //si la casilla de esas coordenas esta libre leo el valor
            ValidarNumeroI();
            sudokuelaborado[get_cordefi()][get_cordeco()]=get_valorcasilla();
            sudokuelaboradoval[get_cordefi()][get_cordeco()]=false;
        }//cierro el if princpal

        ImprimirSudoku(); //muestro mi tablaro con mis nuevo datos
        do{
            cout<<"\n\n Quiere seguir ingresando valores? "
                  "\n 1.- Sí \n 2.- No \n";
            cin>>continuar;
        }while(continuar<1 || continuar>2);
    }while(continuar!=2); //Termina al accion

    if(SudokuCompleto()&&ValidaSudoku())
        cout<<"--~~~++++##### FELICIDADES GANASTE, SUDOKU VALIDO #####++++~~~--"<<endl;
    else if (SudokuCompleto()&&!ValidaSudoku())
        cout<<"--~~~++++##### FELICIDADES COMPLETASTE EL SUDOKU, PERO NO ES VALIDO #####++++~~~--"<<endl;
}

void SUDOKU::BorrarCasillaLlenada() {
    int continuarb=0;
    do{
        cout<<"***#####  BORRANDO CASILLA  #####***"<<endl;
        ValidarCoordenada();
        if(sudokuelaboradoval[get_cordefi()][get_cordeco()]){  //si la casilla de esas coordenas esta libre leo el valor
            cout<<"Esta casilla está vacia D="<<endl;
        }//cierro el if princpal
        else{  //si la casilla no esta libre
            sudokuelaborado[get_cordefi()][get_cordeco()]=0;
            sudokuelaboradoval[get_cordefi()][get_cordeco()]=true;
            cout<<"Esta casilla ha sido borrada"<<endl;
        }

        ImprimirSudoku(); //muestro mi tablaro con mis nuevo datos
        do{
            cout<<"\n\n Quiere seguir borrando valores? "
                  "\n 1.- Sí \n 2.- No \n";
            cin>>continuarb;
        }while(continuarb<1 || continuarb>2);
    }while(continuarb!=2); //Termina al accion
}

void SUDOKU::MostrarSugerencia() {
    int numsug=0,continuar=0;
    srand(time(NULL));
    do{
        int vectorsug[3]={};
        cout<<"***#####  SUGERENCIA SUDOKU  #####***"<<endl;
        ValidarCoordenada();
        if(sudokuelaboradoval[get_cordefi()][get_cordeco()]){  //si la casilla de esas coordenas esta libre leo el valor
            for (int i=0;i<3;i++) {
                numsug = (rand() % get_longitudsudoku()) + 1;
                while (Colision(get_cordefi(), get_cordeco(),
                                numsug)) { //si se puede asignar. incerto el valor en la matriz
                    numsug = (rand() % get_longitudsudoku()) + 1;
                }
                vectorsug[i] = numsug;
            }
            cout<<"Numeros sugeridos: ";
            for(int i=0;i<3;i++){
                cout<<vectorsug[i]<<" ";
            }
            cout<<endl;
        }//cierro el if princpal
        else{  //si la casilla no esta libre
            cout<<"Esta casilla esta inicializada como ocupada. NO LA PUEDE LLENAR"<<endl;
        }

        do{
            cout<<"\n\n Quiere tener otra sugerencia? \n(Tiene para pedir 3 veces sugerencia como máximo) "
                  "\n 1.- Sí \n 2.- No \n";
            cin>>continuar;
        }while(continuar<1 || continuar>2);
    }while(continuar!=2); //Termina al accion

}

void SUDOKU::ResolverSudoku() {
    for (int i=0; i<get_longitudsudoku(); i++){
        for(int j=0;j<get_longitudsudoku();j++){
            sudokuelaborado[i][j]=sudokuelaboradotemporal[i][j];
        }
    }
    ImprimirSudoku();
}
