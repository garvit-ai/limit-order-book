# Limit Order Book and Matching Engine

A high-performance, modular C++ project that simulates a real-time order matching engine similar to those used in electronic exchanges. Optimized to handle over **1.4 million orders/sec** with sub-microsecond latency.

---


## 🧱 Component Design Summary

| Folder/File      | Purpose                                                   |
|------------------|-----------------------------------------------------------|
| `include/`       | All headers: logic, OOP interfaces, structs               |
| `src/`           | Matching engine logic and utility implementations         |
| `benchmark/`     | Main run logic: loads, processes, logs, generates orders  |
| `scripts/`       | Visualization using Python                                |
| `test/`          | GoogleTest or Catch2-based testing                        |
| `main.cpp`       | Initializes order processor (CLI style)                   |

---
## 🚀 Features

- Supports **Market** and **Limit** orders.
- Two engines:
  - Naive (linear scan)
  - Optimized (map + deque)
- **A/B Testing**: Compare naive vs optimized engines for latency.
- Processes **5M+ synthetic orders** with detailed latency logging.
- Built using modern **C++17**, leveraging `map`, `deque`, `shared_ptr`, `chrono`.

---

## 🗂️ Project Structure

```
LimitOrderBookEngine/
├── include/            # Headers for core modules
├── src/                # Implementation files
├── benchmark/          # Load, process, and log latency
├── scripts/            # Python scripts for visualization
├── test/               # Unit tests (optional)
├── main.cpp            # Entry point
└── CMakeLists.txt      # Build config
```

---

## 📦 Build & Run

### Prerequisites
- CMake >= 3.10
- C++17 compiler (e.g. g++ or clang++)
- Python (for latency plotting)

### Build
```bash
mkdir build && cd build
cmake ..
make
```

### Run Matching Engine
```bash
./matching_engine ../benchmark/orders.txt 1   # 1 = optimized, 0 = naive
```

### Generate Visualization
```bash
python3 scripts/visualize_latency.py
```

---

## 📈 Output
- `benchmark/latency_report.csv`: Logs latency per order
- Visual plots (latency histogram, TPS over time)

---

## 📌 Key Metrics

- **Throughput**: 1.4M+ orders/sec
- **Avg Latency**: <800ns (optimized)
- **Latency Gain**: ~76% reduction vs naive engine

---

## 📁 Sample Input Format (orders.txt)

```
1 LIMIT BUY 100 305
2 LIMIT SELL 100 310
3 MARKET BUY 100
```

---

## ✅ Future Enhancements
- Add support for Stop/Cancel/Modify
- Multi-threaded I/O handling
- Custom AVL or skip list for deeper control

---
