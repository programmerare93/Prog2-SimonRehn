#include <vector>
#include <iostream>

using uint = unsigned int;

struct Item {
        uint value;
        uint weight;
};

struct ItemWithIndex {
        Item item;
        std::size_t index;
};

class Knapsack {
public:
        Knapsack(uint capacity);

        void add_item(Item item);
        std::string choose_items() const;
private:
        uint m_capacity;
        std::vector<Item> m_items {};

        static void m_s_update_best_items(std::vector<ItemWithIndex>& best_items,
                                          Item const& item, uint& capacity);

        static bool m_s_item_weight_worth_it(Item const& orig_item,
                                             Item const& new_item);
};

Knapsack::Knapsack(uint capacity)
        : m_capacity {capacity}
{}

void Knapsack::add_item(Item item)
{
        m_items.emplace_back(item);
}

std::string Knapsack::choose_items() const
{
        std::string output;

        std::vector<ItemWithIndex> best_items;

        uint current_cap = m_capacity;
        for (std::size_t i = 0; i < m_items.size(); ++i) {
                Item const& item = m_items[i];
                if (item.weight <= current_cap) {
                        best_items.push_back({item, i});
                } else {
                        Knapsack::m_s_update_best_items(best_items, item,
                                                        current_cap);
                }
        }

        return output;
}

void Knapsack::m_s_update_best_items(std::vector<ItemWithIndex>& best_items,
                                     Item const& item, uint& capacity)
{
        for (std::size_t i = 0; i < best_items.size(); ++i) {
                Item const& best_item = best_items[i].item;

                if (item.value > best_item.value) {
                        if (Knapsack::m_s_item_weight_worth_it(best_item,
                                                               item))
                        {}
                } else if (item.value == best_item.value) {
                } else {
                }
        }
}

bool Knapsack::m_s_item_weight_worth_it(Item const& orig_item,
                                        Item const& new_item)
{
        return (new_item.weight <= orig_item.weight);
}

int main()
{
        uint test_cases;
        std::cin >> test_cases;
        for (; test_cases > 0; --test_cases) {
                uint C, n;
                uint value, weight;

                std::cin >> C >> n;

                Knapsack knapsack(C);
                for (; n > 0; --n) {
                        std::cin >> value >> weight;
                        knapsack.add_item({value, weight});
                }

                std::cout << knapsack.choose_items() << std::endl;
        }
        return 0;
}
