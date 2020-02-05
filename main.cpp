/*
Konto
---------------------------
- inhaber: string
- nummer: long
. stand: doubleS
---------------------------
+ Konto()
+ ~Konto()
+ setInhaber(i: string): void
+ getInhaber(): string
+ setNummer(n: long): void
+ getNummer(): long
+ setStand(s: double): void
+ getStand(): double
+ display(): void
---------------------------

Sparkonto
---------------------------
- habenzins: float
---------------------------
+ Sparkonto()
+ ~Sparkonto()
+ setzins(hz: float): void
+ setstand(): void
---------------------------

Girokonto
---------------------------
- sollzins: float
---------------------------
+ Stand_aendern(): void
+ setstand(): void
---------------------------
*/

#include <iostream>

using namespace std;

class Konto
{
    private:
        string inhaber;
        long nummer;
        double stand;
    public:
        Konto();
        ~Konto();
        void setInhaber(string i);
        string getInhaber();
        void setNummer(long n);
        long getNummer();
        void setStand(double s);
        double getStand();
        void display();
};

class Sparkonto : public Konto
{
    private:
        float habenzins;
    public:
        Sparkonto();
        void setzins(float hz);
        void setstand();
};

class Girokonto : public Konto
{
    private:
        float sollzins;
    public:
        Girokonto();
        void Stand_aendern();
        void setstand();
};

Konto::Konto()
{
    inhaber = "none";
    nummer = 0;
    stand = 0.0;
}

Konto::~Konto()
{
    cout << "Klasse Konto abgebaut." << endl;
}

Sparkonto::Sparkonto()
{
    habenzins = 0;
}

Girokonto::Girokonto()
{
    sollzins = 5;
}

void Konto::setInhaber(string i)
{
    inhaber = i;
}

string Konto::getInhaber()
{
    return inhaber;
}

void Konto::setNummer(long n)
{
    nummer = n;
}

long Konto::getNummer()
{
    return nummer;
}

void Konto::setStand(double s)
{
    stand = s;
}

double Konto::getStand()
{
    return stand;
}

void Sparkonto::setzins(float hz)
{
    habenzins = hz;
}

void Sparkonto::setstand()
{
    float p;
    p = getStand() * (habenzins / 100);
    setStand(p + getStand());
}

void Girokonto::setstand()
{
    if(getStand() < 0)
    {
        float p;
        p = getStand() * (sollzins / 100); //Zinsberechnung
        setStand(p + getStand());
    }
}

void Konto::display()
{
    cout << "Kontoinhaber: " << getInhaber() << endl;
    cout << "Kontonummer: " << getNummer() << endl;
    cout << "Neuer Kontostand: " << getStand() << " Euro" << endl;
}

void Girokonto::Stand_aendern()
{
    char modus;
    float betrag;
    cout << "Aktion: (E)inzahlen oder (A)uszahlen: ";
    cin >> modus;
    if (modus == 'e' || modus == 'E')
    {
        cout << "Betrag zur Einzahlung: ";
        cin >> betrag;
        setStand(getStand() + betrag);
    }
    else if (modus == 'a' || modus == 'A')
    {
        cout << "Betrag zur Auszahlung: ";
        cin >> betrag;
        setStand(getStand() - betrag);
    }
    else
    {
        cout << "Fehler bei Eingabe." << endl;
    }
    cout << "-------------------------------------" << endl;
    cout << "Kontostand: " << getStand();
}

int main()
{
    Sparkonto ValentinSparkonto;
    ValentinSparkonto.setInhaber("Valentin");
    ValentinSparkonto.setNummer(1804);
    ValentinSparkonto.setStand(5000);

    ValentinSparkonto.setzins(17.0);
    ValentinSparkonto.setstand();
    ValentinSparkonto.display();

    Girokonto ValentinGirokonto;
    ValentinGirokonto.setInhaber("Valentin");
    ValentinGirokonto.setNummer(1234);
    ValentinGirokonto.setStand(10000);
    ValentinGirokonto.display();

    ValentinGirokonto.Stand_aendern();
    return 0;
}
