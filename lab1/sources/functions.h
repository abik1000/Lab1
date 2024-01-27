#pragma once
using namespace std;
int **CreateMatrixAuto(int size);
int **CreateMatrixManual(int size);
int **CreatePolindromMatrix(int size,int **Matrix);
int menu(int option);
int input();
void Output(int size,int **one,int **second);
int interface();
int *create(int *ar,int i,int j,int size2);
void del(int **Matrix,int **Polindrom,int size);
