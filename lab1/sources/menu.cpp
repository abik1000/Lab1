#include "functions.h"
#include <iostream>
int interface(){
	int size,option;
        int **Matrix;
        int **Polindrom;
	do{
	system("cls");
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
		cin >> option;
	}
        switch(option){
        case 1:
                size=input();
                Matrix=CreateMatrixAuto(size);
                break;
        case 2:
                size=input();
                Matrix=CreateMatrixManual(size);
                break;
        case 3:
                Polindrom=CreatePolindromMatrix(size,Matrix);
                break;
        case 4:
                del(Matrix,Polindrom,size);
                break;
        case 5:
                Output(size,Matrix,Polindrom);
                break;
        case 6:
                del(Matrix,Polindrom,size);
                option=6;
        default:
                cout << "Error.Such option dont exist.\nPlease inter correct option\n" << endl;
		break;
	}
	}
	while(option!=6);
	return 0;
}
