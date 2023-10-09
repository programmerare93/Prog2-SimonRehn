#include <string>
#include <vector>
#include <iostream>

using uint = unsigned int;

struct Item {
        uint value;
        uint weight;
};

// NOTE: Kunde använt en std::tuple<Item, std::size_t> istället
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

        static void m_s_best_items_append(std::vector<ItemWithIndex>& best_items,
                                          Item const& item,
                                          std::size_t index,
                                          uint& capacity);
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
                        current_cap -= item.weight;
                } else {
                        Knapsack::m_s_best_items_append(best_items,
                                                        item,
                                                        i,
                                                        current_cap);
                }
        }

        output += std::to_string(best_items.size()) + "\n";
        for (auto item : best_items) {
                output += std::to_string(item.index) + " ";
        }

        return output;
}

void Knapsack::m_s_best_items_append(std::vector<ItemWithIndex>& best_items,
                                     Item const& item,
                                     std::size_t index,
                                     uint& capacity)
{
        Item const& first_item = best_items[0].item;

        Item const* worst_item = &first_item;
        double worst_item_ratio = (double)first_item.value / first_item.weight;
        std::size_t worst_index = 0;

        for (std::size_t i = 0; i < best_items.size(); ++i) {
                Item const& current_item = best_items[i].item;
                double current_item_ratio = (double)current_item.value / current_item.weight;

                if (current_item_ratio < worst_item_ratio) {
                        worst_item_ratio = current_item_ratio;
                        worst_index = i;
                        worst_item = &current_item;
                }
        }

        double item_ratio = (double)item.value / item.weight;
        if (item_ratio > worst_item_ratio) {
                capacity += worst_item->weight;
                capacity -= item.weight;
                best_items[worst_index] = {item, index};
        }
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
