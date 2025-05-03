#pragma once
#include "MatchingEngine.hpp"
#include <map>
#include <deque>

class MatchingEngineOptimized : public MatchingEngine
{
private:
    std::map<int, std::deque<std::shared_ptr<Order>>, std::greater<>> buyBook;
    std::map<int, std::deque<std::shared_ptr<Order>>> sellBook;

public:
    void process(const std::shared_ptr<Order> &order) override
    {
        if (order->type == OrderType::MARKET)
        {
            auto &book = (order->side == Side::BUY) ? sellBook : buyBook;
            for (auto it = book.begin(); it != book.end(); ++it)
            {
                if (!it->second.empty())
                {
                    auto matched = it->second.front();
                    it->second.pop_front();
                    std::cout << "TRADE: " << order->id << " matched with " << matched->id << " @ " << it->first << "\n";
                    if (it->second.empty())
                        book.erase(it);
                    return;
                }
            }
        }
        else
        {
            auto &book = (order->side == Side::BUY) ? buyBook : sellBook;
            book[order->price].emplace_back(order);
        }
    }
};
