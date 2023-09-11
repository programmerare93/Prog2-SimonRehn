#include <string>
#include <iostream>

class Elev {
public:
        Elev(std::string namn, int ålder, bool godkänd)
                : namn(namn)
                , ålder(ålder)
                , glad(godkänd)
        {}

        void presentera() const;

        std::string namn;
        int ålder;
        bool glad;
};

void Elev::presentera() const
{
        std::cout << "Hej! Jag heter " << namn << std::endl;
}

int main()
{
        Elev nils("Nils", 17, false);
        nils.presentera();
        return 0;
}
