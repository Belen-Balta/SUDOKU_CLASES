//
// Created by shiro on 24/11/18.
//

#ifndef SUDOKU_ULTIMATE4_DEFINICIONES_SUDOKU_H
#define SUDOKU_ULTIMATE4_DEFINICIONES_SUDOKU_H


#include <iostream>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

const int longitud3x3=9;
const int longitud2x2=4;
const int sublongitud3x3=3;
const int sublongitud2x2=2;

typedef char TipoCaracContorno;
typedef char TipoCaracInterior;
typedef int TipoLongSudoku;
typedef bool TipoValidacion;
typedef unsigned int TipoUnsigned;

void Menu();
void Submenu1();
void Submenu2();
void Submenu3();
void Submenu4();


#endif //SUDOKU_ULTIMATE4_DEFINICIONES_SUDOKU_H
