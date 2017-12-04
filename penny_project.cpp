#include <iostream>
#include <stdlib.h> // rand()
#include <time.h> // do random

using namespace std ;

const int ileNominalow = 9 ;
int nominaly[ileNominalow] = {500, 200, 100, 50, 20, 10, 5, 2, 1} ;
int kasa[ileNominalow] = {0} ;

//*********************************************************************
void reset()
{
    for (int i = 0; i < 9; i++)
    {
        *(kasa + i) = *(nominaly + i) * 10 ;
    }
}
//*********************************************************************

//*********************************************************************
bool wydajReszte(float ile)
{
    ile *= 100 ;
    int reszta = static_cast<int> (ile) ;
    int *wKasa = kasa ;
    int *wNominaly = nominaly ;

    for (int i = 0; i < 9; i++)
    {
        while( (*wKasa != 0) && (reszta - *wNominaly >= 0) ) // dopoki mozna wykorzystac dany nominal
        {
            reszta -= *wNominaly ; // odjecie wydanej monety od pozostalej reszty
            *wKasa -= *wNominaly ; // odjecie monety z kasy
            if (reszta == 0)  return true ; // reszta wydana co do grosza
        }
        wKasa++ ; // przejscie do nast. monety
        wNominaly++ ;
    }
    return false ; // zabraklo monet
}
//*********************************************************************


int main()
{
    srand(time(NULL)) ;
    float ile = 0 ;
    bool saMonety = true ;
    int liczbaTranskacji = 0 ;

    reset() ;
    while (saMonety)
    {
//        ile = (rand() % 999 + 1) / 100.0 ;
        cin >> ile;
        saMonety = wydajReszte(ile) ;
        if (saMonety) liczbaTranskacji++ ;
    }

    cout << "Transakcji: " << liczbaTranskacji ;

    return 0 ;
}


