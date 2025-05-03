#include "Order.hpp"
#include <fstream>
#include <random>
#include <iostream>

void generate_orders(const std::string &filename, int count = 1000000)
{
    std::ofstream out(filename);
    if (!out)
    {
        std::cerr << "Error: Cannot create order file.\n";
        return;
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> qtyDist(1, 1000);
    std::uniform_int_distribution<> priceDist(250, 350);
    std::bernoulli_distribution typeDist(0.7); // 70% limit, 30% market
    std::bernoulli_distribution sideDist(0.5);

    for (int i = 1; i <= count; ++i)
    {
        std::string type = typeDist(gen) ? "LIMIT" : "MARKET";
        std::string side = sideDist(gen) ? "BUY" : "SELL";
        int qty = qtyDist(gen);
        int price = type == "LIMIT" ? priceDist(gen) : 0;

        out << i << " " << type << " " << side << " " << qty;
        if (type == "LIMIT")
            out << " " << price;
        out << "\n";
    }

    std::cout << "Generated " << count << " orders into: " << filename << "\n";
}
