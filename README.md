# stock_analysis_1
# 📈 Stock Market Data Analyzer (C++)

A C++ based stock market analysis project that reads real-world stock data from CSV files and performs statistical and technical analysis.

## 🔍 Features
- Reads real Yahoo Finance–style CSV datasets
- Supports multiple stock tickers
- Filters data by selected ticker
- Calculates:
  - Average closing price
  - Highest and lowest price
  - Market trend
  - Volatility
  - Simple Moving Average (SMA)
  - SMA crossover trading signal (BUY / SELL / HOLD)

## 🧠 Technologies Used
- C++
- STL (vector, string, algorithms)
- File handling (CSV)
- Object-Oriented Design

## 📂 Project Structure
Stock-Market-Analyzer-Cpp/
│
├── src/
│   ├── main.cpp
│   ├── CSVReader.cpp
│   └── Analyzer.cpp
│
├── include/
│   ├── Stock.h
│   ├── CSVReader.h
│   └── Analyzer.h
│
├── data/
│   └── sample_stocks.csv
│
├── README.md
├── .gitignore
└── LICENSE   (optional)


## ▶️ How to Run
bash
g++ src/*.cpp -I include -o stock_analyzer
./stock_analyzer


🎓 Academic Use

This project is suitable as a college-level data analytics / C++ mini project.

🚀 Future Enhancements

SQL database integration

Advanced technical indicators (EMA, RSI)

Performance optimization for large datasets

👤 Author: Purvesh Hande
🎓 Second Year IT Student
