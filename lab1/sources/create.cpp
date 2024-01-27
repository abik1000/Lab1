#include<iostream>
#include"functions.h"
int **CreateMatrixAuto(int size){
	int **Matrix = new int*[size];
	for( int i = 0 ; i < size ; i++ ){
		Matrix[i] = new int[size];
	};
	for( int i = 0 ; i < size ; i++ ){
		for( int j = 0 ; j < size ; j++ ){
			Matrix[i][j]=i+j;
		}
	};
	cout << "\tMatrix created "<< endl;
	return Matrix;

}
int **CreateMatrixManual(int size){
	int **Matrix = new int*[size];
	for( int i = 0 ; i < size ; i++ ){
                Matrix[i] = new int[size];
        }
        for( int i = 0 ; i < size ; i++ ){
                for( int j = 0 ; j < size ; j++ ){
			int tmp;
			cout << "Enter figure" << endl;
			try{
				cin >> tmp;
				if(cin.fail()){
					cout << "Error.Inter figure"  << endl;
					throw "error";
				}
			}
			catch(const char * error){
				cin >> tmp;
			}
                        Matrix[i][j]=tmp;
                }	
	}
	cout << "\tMatrix created "<< endl;
	return Matrix;
}
int *Create(int *a,int i,int j,int size2){
        int *ar=new int[size2];
        int beg=0,end=size2-1;
        for(int k=i;k<(size2/2);k++){
                for(int l=j;l>(size2/2);l--){
                        if(a[k]==a[l]){
                                ar[beg]=a[k];
                                ar[end]=a[l];
                                beg++;
                                end--;
                        }
                        else{
                                delete[] ar;
                                ar=nullptr;
                                break;
                        }
                }
        }
	return ar;
}
int **CreatePolindromMatrix(int size,int **Matrix){
	int **Polindrom = new int*[size];
	int k=0,t=0;
	while(t!=size){
	int *a=Matrix[t];
	for(int i=0;i<size;i++){
		for(int j=size;j>0;j--){
			if(a[i]==a[j]){
				int size2=j+i-1;
				Polindrom[k]=Create(a,i,j,size2);
				k++;
			}
		}
	}
	t++;
	}
	cout << "\tPolindrom created "<< endl;
	return Polindrom;
}
void del(int **Matrix,int **Polindrom,int size){
	for( int i = 0 ; i < size ; i++ ){
                for( int j = 0 ; j < size ; j++ ){
                        delete[] Matrix[i];
        };
	delete[] Matrix;
	for( int i = 0 ; i < size ; i++ ){
                       delete[] Polindrom[i];
        };
	delete[] Polindrom;
	}
	cout << "\tMatrix and Polindrom deleted "<< endl;
}
