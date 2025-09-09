# Simple High-Frequency Trading (HFT) Simulator

This project is a simple **High-Frequency Trading (HFT)** simulation written in **C++**.  
It processes a stream of trade data (time, price, and volume), computes moving averages, evaluates price changes, and executes basic buy/sell strategies.

---

## 📂 Project Structure
- `main.cpp` → Contains the full implementation of the HFT simulator.

---

## ⚙️ Features
- **Tape Processing**  
  Reads trade data and calculates:
  - 5-period **moving average of price**  
  - **Percentage price change** between consecutive trades  

- **Trading Strategy**  
  - **Buy**: If the price change is positive and there is enough cash  
  - **Sell**: If the price change is negative and there is at least one unit of position  

- **Portfolio Tracking**  
  Keeps track of:
  - Current cash  
  - Open positions  
  - Final results after running the tape  

---

## 🧾 Example Trade Data
The simulator works on a vector of trade data:

```cpp
vector<tape> trades = {
    {"2024-01-01 00:00", 100, 1000},
    {"2024-01-01 00:01", 101, 1500},
    {"2024-01-01 00:02", 102, 1200},
    {"2024-01-01 00:03", 101, 1300},
    {"2024-01-01 00:04", 100, 1400},
    {"2024-01-01 00:05", 99, 1100},
    {"2024-01-01 00:06", 98, 1600},
    {"2024-01-01 00:07", 97, 1700},
    {"2024-01-01 00:08", 98, 1800},
    {"2024-01-01 00:09", 99, 1500}
};
