#include <string>
#include <iostream>

class Djur {
public:
        Djur(std::string namn) : namn(namn) {}

        std::string namn;
};

class Fagel : public Djur {
public:
        Fagel(std::string namn, int vingspann)
                : Djur(namn)
                , vingspann(vingspann)
        {}

        int vingspann;
};

class Fisk : public Djur {
public:
        Fisk(std::string namn, int maxdjup)
                : Djur(namn)
                , maxdjup(maxdjup)
        {}

        int maxdjup;
};

class Haj : public Fisk {
public:
        Haj(std::string namn, int maxdjup, int antal_tänder)
                : Fisk(namn, maxdjup)
                , antal_tänder(antal_tänder)
        {}

        int antal_tänder;
};

class Torsk : public Fisk {
public:
        Torsk(std::string namn, int maxdjup, int hastighet)
                : Fisk(namn, maxdjup)
                , hastighet(hastighet)
        {}

        int hastighet;
};

bool fånga(Haj haj, Torsk torsk)
{
        return (torsk.hastighet < 30 && haj.maxdjup >= torsk.maxdjup);
}

int main()
{
        Haj vithaj("Vithaj", 300, 300);
        Torsk torsk("Torsk", 100, 10);
        std::cout << fånga(vithaj, torsk); // Skriver ut 1

        return 0;
}
