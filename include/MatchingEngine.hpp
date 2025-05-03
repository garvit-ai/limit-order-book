#pragma once
#include "Order.hpp"
#include <memory>

class MatchingEngine
{
public:
    virtual void process(const std::shared_ptr<Order> &order) = 0;
    virtual ~MatchingEngine() = default;
};
