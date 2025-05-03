#include <iostream>
#include <string>

// Forward declarations
void generate_orders(const std::string &filename, int count = 1000000);
void process_orders(const std::string &filePath, bool useOptimized);

int main(int argc, char **argv)
{
    if (argc < 3)
    {
        std::cerr << "Usage:\n"
                  << "  ./engine gen <output_file> [num_orders]\n"
                  << "  ./engine run <input_file> <0|1> (0 = naive, 1 = optimized)\n";
        return 1;
    }

    std::string mode = argv[1];

    if (mode == "gen")
    {
        std::string filename = argv[2];
        int num = (argc >= 4) ? std::stoi(argv[3]) : 1000000;
        generate_orders(filename, num);
    }
    else if (mode == "run")
    {
        std::string filename = argv[2];
        bool useOptimized = std::stoi(argv[3]);
        process_orders(filename, useOptimized);
    }
    else
    {
        std::cerr << "Unknown mode: " << mode << "\n";
        return 1;
    }

    return 0;
}
