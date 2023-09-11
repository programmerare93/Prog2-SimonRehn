#include <iomanip>
#include <iostream>

constexpr double ONE_THOUSANDTH = 0.001;

double calculate_weight(int kuvert_weight, int affisch_weight, int blad_weight)
{
        const int ark_weight = blad_weight;

        const double kuvert_area = (229 * ONE_THOUSANDTH) * (324 * ONE_THOUSANDTH);
        const double affisch_area = (297 * ONE_THOUSANDTH) * (420 * ONE_THOUSANDTH);
        const double blad_area = (210 * ONE_THOUSANDTH) * (297 * ONE_THOUSANDTH);
        const double ark_area = kuvert_area;

        const int num_of_ark = 2;
        const int num_of_affisch = 2;
        const int num_of_blad = 1;

        double total_weight = (kuvert_weight * kuvert_area * num_of_ark)
                               + (blad_weight * blad_area * num_of_blad)
                               + (affisch_weight * affisch_area * num_of_affisch);

        return total_weight;
}

int main()
{
        int kuvert_weight, affisch_weight, blad_weight;
        std::cout << "Kuvert? ";
        std::cin >> kuvert_weight;
        std::cout << "Affisch? ";
        std::cin >> affisch_weight;
        std::cout << "Blad? ";
        std::cin >> blad_weight;

        // NOTE: Kollar inte ifall variablerna faktiskt är >= 50 och <= 200
        std::cout << "Svar: "
                  << std::setprecision(6) << std::fixed
                  << calculate_weight(kuvert_weight, affisch_weight, blad_weight)
                  << std::endl;

        return 0;
}
