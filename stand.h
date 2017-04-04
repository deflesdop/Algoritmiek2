// Definitie van klasse Stand.

#ifndef StandHVar  // om te voorkomen dat dit .h bestand meerdere keren
#define StandHVar  // wordt ge-include 

#include <fstream>
#include "steen.h"

const int Mmax = 20;
const int Nmax = 20;
const int maxnrstenen = 20; // maximum aantal stenen

class Stand
{ public:
    // default constructor, misschien niet zo hard nodig
    // voor deze opdracht...
    Stand ();

    // constructor voor een bord met waardeM rijen en waardeN kolommen
    Stand (int waardeM, int waardeN);

    // destructor
    ~Stand ();

    // Geef waarde van m.
    int getM ();
    // Geef waarde van n.
    int getN ();

    // Druk bord af op het scherm.
    void drukaf ();

    // Lees stenen in vanuit tekstbestand met naam invoernaam.
    void leesstenen (const char *invoernaam);

    // Leg indien mogelijk steen `steennr' in orientatie orient op het bord,
    // in een bounding box met linker boven vakje (rij, kolom).
    // Retourneer:
    //   - true, als het lukt om de steen neer te leggen
    //   - false, als het niet lukt om de steen neer te leggen
    bool legsteenneer (int rij, int kolom, int steennr, int orient);

    // Bepaal zo mogelijk 1 oplossing, uitgaande van de huidige stand.
    // Als slim==true, controleer dan na iedere zet of het aantal vakjes
    // in elk gebied nog een veelvoud van de grootste gemene deler is.
    // Als een oplossing gevonden is, druk deze dan af op het scherm
    // en stop met zoeken.
    // Post: aantal is opgehoogd met het aantal standen dat we hebben
    //         bekeken bij deze zoektocht.
    void bepaaloplossing (long long &aantal, bool slim);

    // Tel en retourneer het aantal oplossingen, uitgaande van
    // de huidige stand.
    // Als slim==true, controleer dan na iedere zet of het aantal vakjes
    // in elk gebieden nog een veelvoud van de grootste gemene deler is.
    // Post: aantal is opgehoogd met het aantal standen dat we hebben
    //         bekeken bij deze zoektocht.
    long long teloplossingen (long long &aantal, bool slim);

  private:
    int m, n,        // aantal rijen/kolommen van het bord
        bord[Mmax][Nmax];
          // Bovenste rij is rij 0, onderste rij is rij m-1.
          // Meest linker kolom is kolom 0, meest rechter kolom is kolom n-1.

    // TODO: uw eigen methodes en velden
};

#endif

