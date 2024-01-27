#include "functions.h"
#include <iostream>
int input(){
        int size;
	try{
		cout << "Введите целое число\n";
		cin >> size;
		if(cin.fail()==true){
			throw "error";
		}
		if(size>10){
			cout << "Size of Matrix could be more than 10 elements\n" << endl;
			return input();
		}
	}
	catch (const char * error){
		cout << "Ошибка,введите целое число\n";
		return input();
	}
        return size;
}
void Output(int size,int **one,int **second){
	 for( int i = 0 ; i < size ; i++ ){
                cout << "| ";
                for( int j = 0 ; j < size ; j++ ){
                       cout << one[i][j] << "|";
                }
                cout << "|" << endl;
        }
	for( int i = 0 ; i < size ; i++ ){
                cout << "| ";
                for( int j = 0 ; j < size ; j++ ){
                       cout << second[i][j] << "|";
                }
                cout << "|" << endl;
        }
}

