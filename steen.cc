// Implementatie van klasse Steen.

#include <iostream>
#include "steen.h"
#include "standaard.h"
#include <fstream>
using namespace std;

//*************************************************************************

Steen::Steen (ifstream &fin)
{ 
	int row, col;
	fin >> row >> col;
	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			fin >> inhoud[i][j];
		}
	}
	m = row;
	n = col;
}  // Steen

//*************************************************************************

int Steen::getM ()
{
  return m;
}

//*************************************************************************

int Steen::getN ()
{
  return n;
}

//*************************************************************************

int Steen::grootte ()
{
	int count;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			if(inhoud[i][j] == 'x'){
				count++;
			}
		}
	}
	return count;
}

//*************************************************************************

void Steen::drukaf ()
{
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			cout << inhoud[i][j] << " ";
		}
		cout << endl;
	}
}  // drukaf

//*************************************************************************

void Steen::kopieerArray(char arr[][5]){
	for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				inhoud[i][j] = arr[i][j];
			}
		}
}

void Steen::roteerArray(int row, int col, char arr2[][5]){
	for(int i = 0; i < col; i++){
		for(int j = 0; j < row; j++){
			arr2[i][j] = inhoud[row-1-j][i];
		}
	}

}

void Steen::roteer (int aantalkeer)
{
	char temp[5][5];
	switch(aantalkeer){
	  case 1:
		  roteerArray(m,n,temp);
		  break;
	  case 2:
		  for(int i = 0; i < 2; i++)
			  roteerArray(m,n,temp);
		  break;
	  case 3:
		  for(int i = 0; i < 3; i++)
			  roteerArray(m,n,temp);
		  break;
	  case 4:
		  spiegelhorizontaleas(m,inhoud);
		  break;
	  case 5:
		  spiegelhorizontaleas(m,inhoud);
		  roteerArray(m,n,temp);
		  break;
	  case 6:
		  spiegelhorizontaleas(m,inhoud);
		  for(int i = 0; i < 2; i++)
			  roteerArray(m,n,temp);
		  break;
	  case 7:
		  spiegelhorizontaleas(m,inhoud);
		  for(int i = 0; i < 3; i++)
			  roteerArray(m,n,temp);
		  break;
  }

kopieerArray(temp);

}  // roteer

//*************************************************************************

void Steen::spiegelhorizontaleas (int row, char arr[][5])
{
	for(int i = 0; i < row/2; i++){
		std::swap(arr[0], arr[row-1]);
	}

}  // spiegelhorizontaleas

//*************************************************************************

