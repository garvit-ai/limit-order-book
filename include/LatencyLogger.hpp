#pragma once
#include <fstream>
#include <chrono>
#include <string>

class LatencyLogger
{
private:
    std::ofstream file;

public:
    LatencyLogger(const std::string &filename)
    {
        file.open(filename);
        file << "order_id,latency_ns,type\n";
    }

    void log(int id, long latency, const std::string &type)
    {
        file << id << "," << latency << "," << type << "\n";
    }

    ~LatencyLogger()
    {
        if (file.is_open())
            file.close();
    }
};
