// Definitie van klasse Steen.

#ifndef SteenHVar  // om te voorkomen dat dit .h bestand meerdere keren
#define SteenHVar  // wordt ge-include 

#include <fstream>

const int MaxDim = 5;

class Steen
{ public:
    // constructor
    Steen (std::ifstream &fin);

    // Geef waarde van m.
    int getM ();

    // Geef waarde van n.
    int getN ();

    // Geef het aantal vakjes dat de steen bedekt.
    int grootte ();

    // Druk steen af op het scherm.
    void drukaf ();

    // Roteer steen een aantal keer 90 graden met de klok mee.
    void roteer (int aantalkeer);  // of een soortgelijke methode

    // Spiegel steen in horizontale as.
    void spiegelhorizontaleas (int row, char arr[][5]);  // of een soortgelijke methode

    // TODO: uw eigen methodes en velden

  private:
    char inhoud[MaxDim][MaxDim];
      // Bovenste rij is rij 0, onderste rij is rij MaxDim-1.
      // Meest linker kolom is kolom 0, meest rechter kolom is kolom MaxDim-1.
    int m, n;  // Feitelijk aantal rijen (vanaf boven) / kolommen (vanaf links)
               // van steen dat in gebruik (deels gevuld) is.
               // Deze waardes worden gezet bij het inlezen van een steen.

    // TODO: uw eigen methodes en velden

    void roteerArray(int row, int col, char arr2[][5]);
    void kopieerArray(char arr[][5]);
};

#endif

