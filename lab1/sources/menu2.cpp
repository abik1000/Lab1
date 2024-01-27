#include "functions.h"
#include <iostream>
int menu (int option){
	//int size;
	int **Matrix;
	int **Polindrom;
	switch(option){
	case 1:
		size=input();
		Matrix=CreateMatrixAuto(size);
		return interface();
	case 2:
		size=input();
		Matrix=CreateMatrixManual(size);
		return interface();
	case 3:
		Polindrom=CreatePolindromMatrix(size,Matrix);
		return interface();
	case 4:
		del(Matrix,Polindrom,size);
		return interface();
	case 5:
		Output(size,Matrix,Polindrom);
		return interface();
	case 6:
		del(Matrix,Polindrom,size);
		return 0;
	default:
		cout << "Error.Such option dont exist.\nPlease inter correct option\n" << endl;
		return interface();
	}
	return 0;
}
int interface(){
	system("cls");
	int option;
	cout << "To chose option inter corespond number\n" << "\t[Menu]" << endl;
	cout << "1)Create Matrix Auto\n" << "2)Create Matrix Manual\n" << "3)Create Polindromic Matrix\n" << "4)Delete Matrixes\n" << "5)Display Matrixes\n" << "6)End the programm\n" << "Tap Enter to end programm\n"<< endl;
	try{
		cin >> option;
		if(cin.fail()){
			cout << "Enter number\n" << endl;
			throw "error";
		}
		if(option > 6){
			cout << "Such option not exist,Choose option again\n";
			throw "error";
		}
	}
	catch(const char * error){
		return interface();
	}
	menu(option);
	return 0;
}
