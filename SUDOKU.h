//
// Created by shiro on 24/11/18.
//

#ifndef SUDOKU_ULTIMATE4_SUDOKU_H
#define SUDOKU_ULTIMATE4_SUDOKU_H


#include "DEFINICIONES_SUDOKU.h"

class SUDOKU {
protected:
    TipoCaracContorno ccontorno ;
    TipoCaracInterior cinterior;
    TipoLongSudoku longitudsudoku,
            sublongitudsudoku,Lleft,Lrigth,
            Lup,Ldown,cordefi,cordeco,valorcasilla,
            **sudokuelaboradotemporal,
            **sudokuelaborado,*Vectorsub;
    TipoValidacion **sudokuelaboradoval;
public:
    /*SUDOKU(){};//Constructor
    virtual ~SUDOKU(){};//Destructor*/
    //Metodos
    void inicializamatrizceros();
    void ConstruyeMatrizdinamica();
    void DestruyeMatrizdinamica();
    void DefineCaractSudoku();
    void ImprimirSudoku();
    bool ValidaSudoku();
    void SiSudoku();
    void LlenarSudokualeat();
    bool Verificassub(int num, int pos);
    void transformada(int fila, int columna);
    bool Colision(int fila,int columna, int num);
    virtual void LlenarSudokualeatcorrect1();
    void GenerarSudokuvalidojuego();
    void ValidarCoordenada();
    void ValidarNumeroI();
    bool SudokuCompleto();
    void LlenarCasillavacia();
    void BorrarCasillaLlenada();
    void MostrarSugerencia();
    void ResolverSudoku();
    void set_ccontorno(TipoCaracContorno _ccontorno){ccontorno = _ccontorno;}
    void set_cinterior(TipoCaracInterior _cinterior){cinterior = _cinterior;}
    void set_longitudsudoku(TipoLongSudoku _longitudsudoku){longitudsudoku = _longitudsudoku;}
    void set_sublongitudsudoku(TipoLongSudoku _sublongitudsudoku){sublongitudsudoku = _sublongitudsudoku;}
    void set_Lleft(TipoLongSudoku _Lleft){Lleft= _Lleft;}
    void set_Lrigth(TipoLongSudoku _Lrigth){Lrigth= _Lrigth;}
    void set_Lup(TipoLongSudoku _Lup){Lup= _Lup;}
    void set_Ldown(TipoLongSudoku _Ldown){Ldown= _Ldown;}
    void set_cordefi(TipoLongSudoku _cordefi){cordefi= _cordefi;}
    void set_cordeco(TipoLongSudoku _cordeco){cordeco= _cordeco;}
    void set_valorcasilla(TipoLongSudoku _valorcasilla){valorcasilla= _valorcasilla;}
    TipoCaracContorno get_ccontorno(){return ccontorno;}//Getter
    TipoCaracInterior get_cinterior(){return cinterior;}
    TipoLongSudoku get_longitudsudoku(){return longitudsudoku;}
    TipoLongSudoku get_sublongitudsudoku(){return sublongitudsudoku;}
    TipoLongSudoku get_Lleft(){return Lleft;}
    TipoLongSudoku get_Lrigth(){return Lrigth;}
    TipoLongSudoku get_Lup(){return Lup;}
    TipoLongSudoku get_Ldown(){return Ldown;}
    TipoLongSudoku get_cordefi(){return cordefi;}
    TipoLongSudoku get_cordeco(){return cordeco;}
    TipoLongSudoku get_valorcasilla(){return valorcasilla;}

};


#endif //SUDOKU_ULTIMATE4_SUDOKU_H
