#ifndef DATUM_H
#define DATUM_H

/**
 * \file datum.h
 *
 * Datum osztály deklarációja és globális függvényei
 */

#include <iostream>

class Datum {
    int ev;     ///< év
    int ho;     ///< hónap
    int nap;    ///< nap
  public:
    /// Paraméter nélkül hívható konstruktor.
    /// Mai napot állítja be
    Datum();

    /// Adott napot beállító konstruktor
    /// @param ev - év
    /// @param hó - hónap
    /// @param nap - nap
    Datum(int ev, int ho, int nap) :ev(ev), ho(ho), nap(nap) {}
    Datum(const Datum& uj):ev(uj.ev),ho(uj.ho),nap(uj.nap){}
    /// Év lekérdezése
    /// @return ev
    int getEv() const { return ev;}

    /// Hónap lekérdezése
    /// @return honap
    int getHo() const { return ho;}

    /// Nap lekérdezése
    /// @return nap
    int getNap() const { return nap;}

    /// Két dátum egyezőségét vizsgálja
    /// @param d - jobb oldali operandus
    /// @return true, ha egyezik a két dátum
    bool operator==(const Datum& d) const {
        return ev == d.ev && ho == d.ho && nap == d.nap;
    }
    int kisebb(const Datum& masik)const{
        if(ev<masik.ev)return 1;
        else if(ev==masik.ev&&ho<masik.ho) return 1;
        else if(ev==masik.ev&&ho==masik.ho&&nap<masik.nap)return 1;
        else if(ev==masik.ev&&ho==masik.ho&&nap==masik.nap)return 0;
        else return 2;
    }
};

/// Globális inserter
/// @param os - output stream referencia
/// @param s - Datum referencia
/// @return output stream referencia
std::ostream& operator<<(std::ostream& os, const Datum& d);

#endif // DATUM_H
