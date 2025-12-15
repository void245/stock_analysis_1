#include <iostream>
#include <vector>
#include <string>

#include "CSVReader.h"
#include "Analyzer.h"
#include "Stock.h"

int main() {
    // 1️⃣ Read CSV file (all stocks)
    std::string filename = "data/stocks.csv";  
    std::vector<Stock> data = CSVReader::readCSV(filename);

    if (data.empty()) {
        std::cout << "CSV file is empty or not found!" << std::endl;
        return 0;
    }

    // 2️⃣ Ask user which stock to analyze
    std::string selectedSymbol;
    std::cout << "Enter stock symbol to analyze (AAPL, TSLA, INFY): ";
    std::cin >> selectedSymbol;

    // 3️⃣ Filter data for selected stock
    std::vector<Stock> filteredData;

    for (const auto& stock : data) {
        if (stock.symbol == selectedSymbol) {
            filteredData.push_back(stock);
        }
    }

    // 4️⃣ Safety check
    if (filteredData.empty()) {
        std::cout << "No data found for stock: " << selectedSymbol << std::endl;
        return 0;
    }

    // 5️⃣ Perform analysis
    std::cout << "\n========== STOCK ANALYSIS REPORT ==========\n";
    std::cout << "Stock Symbol: " << selectedSymbol << "\n";
    std::cout << "Total Records: " << filteredData.size() << "\n\n";

    std::cout << "Average Close Price : "
              << Analyzer::averageClose(filteredData) << std::endl;

    std::cout << "Highest Price      : "
              << Analyzer::maxHigh(filteredData) << std::endl;

    std::cout << "Lowest Price       : "
              << Analyzer::minLow(filteredData) << std::endl;

    std::cout << "Market Trend       : "
              << Analyzer::detectTrend(filteredData) << std::endl;

    std::cout << "Volatility         : "
              << Analyzer::volatility(filteredData) << std::endl;

    // SMA & Trading Signal
    int shortWindow = 5;
    int longWindow = 20;

    std::string signal = Analyzer::smaCrossoverSignal(
        filteredData, shortWindow, longWindow
    );

    std::cout << "Trading Signal     : " << signal << std::endl;

    std::cout << "==========================================\n";

    return 0;
}
