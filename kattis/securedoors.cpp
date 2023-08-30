#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

#include <cctype>
#include <cassert>

class Employees {
public:
        Employees() = default;

        bool employee_exists(std::string const& name);

        void add_employee(std:: string const& name);
        void remove_employee(std:: string const& name);

private:
        std::vector<std::string> m_employees;
};

bool Employees::employee_exists(std::string const& name)
{
        return (std::find(m_employees.cbegin(), m_employees.cend(), name)
                != m_employees.cend());
}

void Employees::add_employee(std:: string const& name)
{
        m_employees.push_back(name);
}

void Employees::remove_employee(std::string const& name)
{
        m_employees.erase(std::find(m_employees.cbegin(),
                                    m_employees.cend(), name),
                          m_employees.cend());
}

void log_employee(std::string const& employee_action)
{
        static Employees employees;

        if (employee_action.substr(0, 5).compare("entry") == 0) {
                std::string name(employee_action.substr(6,
                                                        (employee_action.size()
                                                         - 6)));
                if (!employees.employee_exists(name)) {
                        std::cout << name << " entered\n";
                        employees.add_employee(name);
                } else {
                        std::cout << name << " entered (ANOMALY)\n";
                }

        } else if (employee_action.substr(0, 4).compare("exit") == 0) {
                std::string name(employee_action.substr(5,
                                                        (employee_action.size()
                                                         - 5)));
                if (employees.employee_exists(name)) {
                        std::cout << name << " exited\n";
                        employees.remove_employee(name);
                } else {
                        std::cout << name << " exited (ANOMALY)\n";
                }
        } else {
                std::cout << "Unknown action\n";
        }
}

int main()
{
        std::cout << "Enter length of log: ";
        int log_len;
        std::cin >> log_len;
        /* std::cin.ignore() ser till så att std::getline() i loopen
           ignorerar '\n' som lämnades efter 'std::cin >>'*/
        std::cin.ignore();
        assert(log_len <= 1000 && log_len >= 1);

        while (log_len > 0) {
                std::string employee_action;
                std::getline(std::cin, employee_action);
                log_employee(employee_action);

                --log_len;
        }
        return 0;
}
