#include <string>
#include <iostream>

class Fordon {
public:
        Fordon() = default;
        void kör() const;
};

void Fordon::kör() const
{
        std::cout << "Nu kör vi!" << std::endl;
}

class Bil : public Fordon {
public:
        Bil() = default;
        void tuta() const;
};

void Bil::tuta() const
{
        std::cout << "Tuuut!!" << std::endl;
}

class Sportbil : public Bil {
public:
        Sportbil() = default;
        void kör() const;
};

void Sportbil::kör() const
{
        std::cout << "Nu kör vi snabbt!" << std::endl;
}

class Cykel : public Fordon {
public:
        Cykel() = default;
        void plinga() const;
};

void Cykel::plinga() const
{
        std::cout << "Pling!" << std::endl;
}

int main()
{
        Fordon fordon;
        Bil bil;
        Sportbil sportbil;
        Cykel cykel;

        fordon.kör();
        bil.tuta();
        sportbil.kör();
        cykel.plinga();

        return 0;
}
