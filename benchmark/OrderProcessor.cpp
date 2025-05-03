#include "Order.hpp"
#include "MatchingEngineNaive.hpp"
#include "MatchingEngineOptimized.hpp"
#include "LatencyLogger.hpp"

#include <iostream>
#include <fstream>
#include <memory>
#include <chrono>

void process_orders(const std::string &filePath, bool useOptimized)
{
    std::ifstream infile(filePath);
    if (!infile)
    {
        std::cerr << "Error: Cannot open input file.\n";
        return;
    }

    LatencyLogger logger("benchmark/latency_report.csv");
    MatchingEngineNaive naiveEngine;
    MatchingEngineOptimized optEngine;

    std::string line;
    while (std::getline(infile, line))
    {
        auto order = std::make_shared<Order>(Order::from_string(line));

        auto start = std::chrono::high_resolution_clock::now();
        if (useOptimized)
            optEngine.process(order);
        else
            naiveEngine.process(order);
        auto end = std::chrono::high_resolution_clock::now();

        long latency = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
        logger.log(order->id, latency, useOptimized ? "OPT" : "NAIVE");
    }
}
