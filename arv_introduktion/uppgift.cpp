#include <string>
#include <iostream>

class Djur {
public:
        Djur(std::string namn) : namn(namn) {}

        virtual void at() const;
        void sov() const;

        std::string const& get_namn() const
        {
                return namn;
        }

protected:
        std::string namn;
};

void Djur::at() const
{
        std::cout << namn << " äter" << std::endl;
}

void Djur::sov() const
{
        std::cout << namn << " sover" << std::endl;
}

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

        void simma() const;

        int maxdjup;
};

void Fisk::simma() const
{
        std::cout << namn << " simmar" << std::endl;
}

class Haj : public Fisk {
public:
        Haj(std::string namn, int maxdjup, int antal_tänder)
                : Fisk(namn, maxdjup)
                , antal_tänder(antal_tänder)
        {}

        void at(Djur djur) const;

        int antal_tänder;
};

void Haj::at(Djur djur) const
{
        std::cout << namn << " äter en " << djur.get_namn() << std::endl;
}

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

        std::cout << fånga(vithaj, torsk) << std::endl; // Skriver ut 1
        if (fånga(vithaj, torsk)) {
                vithaj.at(torsk);
        }

        return 0;
}
