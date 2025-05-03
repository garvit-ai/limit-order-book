#pragma once
#include "MatchingEngine.hpp"
#include <vector>

class MatchingEngineNaive : public MatchingEngine
{
private:
    std::vector<std::shared_ptr<Order>> book;

public:
    void process(const std::shared_ptr<Order> &order) override
    {
        if (order->type == OrderType::MARKET)
        {
            for (auto it = book.begin(); it != book.end(); ++it)
            {
                auto &o = *it;
                if (o->side != order->side && o->quantity == order->quantity)
                {
                    std::cout << "TRADE: " << order->id << " matched with " << o->id << "\n";
                    book.erase(it);
                    return;
                }
            }
        }
        else
        {
            book.emplace_back(order);
        }
    }
};
