#include <string>

class Student {
public:
        Student(std::string namn);

        std::string get_name() const;
        int get_alder() const;

        static std::string skola;
private:
        std::string namn;
        std::string personnr;
};

std::string Student::skola {"Åva"};

Student::Student(std::string namn)
        : namn(namn)
{}

std::string Student::get_name() const
{
        return namn;
}

int Student::get_alder() const
{
}
