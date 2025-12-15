#include "CSVReader.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>

std::vector<Stock> CSVReader::readCSV(const std::string& filename){
    std::vector<Stock> stocks;
    std::ifstream file(filename);

    if(!file.is_open()){
        throw std::runtime_error("Error : Could not open file" + filename);

    }
    std::string line;
    //skip header line 
    std::getline(file, line);
    //read each line
    while(std::getline(file , line)){
        std::stringstream ss(line);
        Stock stock;
        std::string temp;
        try {
        // Ticker
        std::getline(ss, stock.symbol, ',');

        // Date
        std::getline(ss, stock.date, ',');

        // Open
        std::getline(ss, temp, ',');
        stock.open = std::stod(temp);

        // High
        std::getline(ss, temp, ',');
        stock.high = std::stod(temp);

        // Low
        std::getline(ss, temp, ',');
        stock.low = std::stod(temp);

        // Close
        std::getline(ss, temp, ',');
        stock.close = std::stod(temp);

        // Adj Close (ignore)
        std::getline(ss, temp, ',');

        // Volume
        std::getline(ss, temp, ',');
        stock.volume = std::stoll(temp);

        stocks.push_back(stock);

        }
        catch(...){
            continue;
        }
    }
    file.close();
    return stocks;
}

