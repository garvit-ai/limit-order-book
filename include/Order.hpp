#pragma once
#include <string>
#include <sstream>

enum class OrderType
{
    MARKET,
    LIMIT
};
enum class Side
{
    BUY,
    SELL
};

class Order
{
public:
    int id;
    OrderType type;
    Side side;
    int quantity;
    int price; // ignored for market orders

    Order(int id, OrderType type, Side side, int qty, int price)
        : id(id), type(type), side(side), quantity(qty), price(price) {}

    static Order from_string(const std::string &line)
    {
        std::istringstream ss(line);
        std::string type_str, side_str;
        int id, qty, price = 0;
        ss >> id >> type_str >> side_str >> qty;
        if (type_str == "LIMIT")
            ss >> price;

        OrderType type = (type_str == "LIMIT") ? OrderType::LIMIT : OrderType::MARKET;
        Side side = (side_str == "BUY") ? Side::BUY : Side::SELL;

        return Order(id, type, side, qty, price);
    }
};
