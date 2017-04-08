// Implementatie van klasse Stand.

#include <iostream>
#include <iomanip>
#include <fstream>
#include "stand.h"
#include "standaard.h"
using namespace std;

//*************************************************************************

Stand::Stand()
{
  n = 5;
  m = 5;

}

//*************************************************************************

Stand::Stand (int waardeM, int waardeN)
{
	n = waardeN;
	m = waardeM;
}

//*************************************************************************

Stand::~Stand ()
{
  // eventueel TODO: implementeren

}  // ~Stand

//*************************************************************************

int Stand::getM ()
{
  return m;
}

//*************************************************************************

int Stand::getN ()
{
  return n;
}

//*************************************************************************

void Stand::drukaf ()
{
	cout << '\t';
	for(int i = 1; i < getM(); i++)
		cout << i << "  ";
	cout << endl;
	for(int i = 0; i < getM(); i++){
	  cout << i+1 << '\t';
	  for(int j = 0; j < getN(); j++){
		  if(bord[i][j] > 9)
			  cout << bord[i][j] <<  " ";
		  else
			  cout << bord[i][j] <<  "  ";
	  }
	  cout << endl;
  }

}  // drukaf

//*************************************************************************

void Stand::leesstenen (const char *invoernaam)
{
	ifstream fin(invoernaam, ifstream::in);


}  // leesstenen

//*************************************************************************

bool Stand::legsteenneer (int rij, int kolom, int steennr, int orient)
{
  cout << "Methode Stand::legsteenneer is nog niet geimplementeerd." << endl;
  // TODO: implementeren

  return true;

}  // legsteenneer

//*************************************************************************

void Stand::bepaaloplossing (long long &aantal, bool slim) 
{
  cout << "Methode Stand::bepaaloplossing is nog niet geimplementeerd." << endl;
  // TODO: implementeren

}  // bepaaloplossing

//*************************************************************************

long long Stand::teloplossingen (long long &aantal, bool slim)
{
  cout << "Methode Stand::teloplossingen is nog niet geimplementeerd." << endl;
  // TODO: implementeren

  return 0;

}  // teloplossingen

//*************************************************************************

