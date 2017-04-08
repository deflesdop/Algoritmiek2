// Hoofdprogramma voor oplossing voor tweede programmeeropdracht Algoritmiek,
// voorjaar 2017: Stenen Leggen (2).
//
// Biedt de gebruiker een menustructuur om
// * een voor een zelf stenen te leggen op een bord
// * te vragen
//   - om een oplossing te bepalen vanaf de huidige stand
//   - of om het aantal oplossingen vanaf de huidige stand te tellen.
//
// Naam 1 (studentnummer 1)
// Naam 2 (studentnummer 2)
// Datum

#include <iostream>
#include <ctime>  // voor clock() en clock_t
#include "standaard.h"
#include "stand.h"
#include <fstream>
using namespace std;
const int MaxBestandsNaamLengte = 30; // maximale lengte van een bestandsnaam

//*************************************************************************

// Speel het spel vanaf stand s1.
// Hierbij krijgt de gebruiker herhaaldelijk de kans om
// * een steen in een bepaalde orientatie op het bord neer te leggen.
//   Als dat een toegestane zet is, wordt die uitgevoerd.
//   Na iedere zet wordt de stand afgedrukt.
// * te vragen
//   - om een oplossing te bepalen vanaf de huidige stand
//   - of om het aantal oplossingen vanaf de huidige stand te tellen.
//
// Dit alles gaat door totdat de gebruiker aangeeft dat hij wil stoppen
// met het huidige spel.
void doespel (Stand *s1)
{ int m, n,
      keuze,
      rij, kolom, steennr, orient;
  long long aantal,  // aantal bekeken standen bij aanroep van bepaaloplossing
                     // of teloplossingen
            aantalopl;  // aantal oplossingen gevonden met teloplossingen
  clock_t t1, t2;

  m = s1 -> getM ();
  n = s1 -> getN ();

  do
  { cout << endl;
    cout << "1. Een zet doen" << endl;
    cout << "2. Bepaal een oplossing (dom)" << endl;
    cout << "3. Bepaal een oplossing (slim)" << endl;
    cout << "4. Tel oplossingen (dom)" << endl;
    cout << "5. Tel oplossingen (slim)" << endl;
    cout << "6. Stoppen met dit spel" << endl;
    cout << endl;
    cout << "Maak een keuze: ";
    cin >> keuze;

    switch (keuze)
    { case 1: cout << endl;
              cout << "Geef het nummer van een rij (0.." << m-1
                   << " vanaf boven): ";
              cin >> rij;
              cout << "Geef het nummer van een kolom (0.." << n-1
                   << " vanaf links): ";
              cin >> kolom;
              cout << "Geef het nummer van een steen: ";
              cin >> steennr;
              cout << "Geef een orientatie van deze steen: ";
              cin >> orient;

              if (s1->legsteenneer (rij, kolom, steennr, orient))
                s1 -> drukaf ();
              else
              { cout << endl;
                cout << "De opgegeven zet was niet mogelijk." << endl;
              }
              break;
      case 2:
      case 3: aantal = 0;
              t1 = clock ();
              if (keuze==2)
                s1 -> bepaaloplossing (aantal, false);
              else
                s1 -> bepaaloplossing (aantal, true);
              t2 = clock ();
              cout << endl;
              cout << "We hebben " << aantal << " standen bekeken." << endl;
              cout << "Dit kostte " << (t2-t1) << " clock ticks, ofwel "
                   << (((double)(t2-t1))/CLOCKS_PER_SEC) << " seconden."
                   << endl;

              break;
      case 4:
      case 5: aantal = 0;
              t1 = clock ();
              if (keuze==4)
                aantalopl = s1 -> teloplossingen (aantal, false);
              else
                aantalopl = s1 -> teloplossingen (aantal, true);
              t2 = clock ();
              cout << endl;
              cout << "We hebben " << aantal << " standen bekeken." << endl;
              cout << "We vonden " << aantalopl << " oplossingen." << endl;
              cout << "Dit kostte " << (t2-t1) << " clock ticks, ofwel "
                   << (((double)(t2-t1))/CLOCKS_PER_SEC) << " seconden."
                   << endl;
              break;
      case 6: break;
      default: cout << endl;
               cout << "Voer een goede keuze in!" << endl;
    }  // switch

  } while (keuze!=6);

}  // doespel

//*************************************************************************

void hoofdmenu ()
{ Stand *s1;  // pointer, om makkeijk nieuwe objecten te kunnen maken
              // en weer weg te gooien
  int keuze,
      m, n;
  char invoernaam[MaxBestandsNaamLengte+1];

  do
  {
    cout << endl;
    cout << "Geef een waarde voor het aantal rijen van het bord (m): ";
    cin >> m;
    cout << "Geef een waarde voor het aantal kolommen van het bord (n): ";
    cin >> n;
    if (integerInBereik ("m", m, 1, Mmax)
        && integerInBereik ("n", n, 1, Nmax))
    { s1 = new Stand (m, n);
      s1 -> drukaf ();

      cout << endl;
      cout << "Geef de naam van het tekstbestand met de stenen: ";
      cin >> invoernaam;
      s1 -> leesstenen (invoernaam);

      doespel (s1);

      delete s1;  // netjes opruimen

      do
      { cout << endl;
        cout << "1. Een nieuw spel spelen" << endl;
        cout << "2. Stoppen" << endl;
        cout << endl;
        cout << "Maak een keuze: ";
        cin >> keuze;

        if (keuze<1 || keuze>2)
        { cout << endl;
          cout << "Voer een goede keuze in!" << endl;
        }
      } while (keuze<1 || keuze>2);

    }  // if integerInBereik

  } while (keuze!=2);

}  // hoofdmenu

//*************************************************************************

int main ()
{
 //hoofdmenu ();
  return 0;

}
