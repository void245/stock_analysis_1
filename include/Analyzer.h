
#ifndef ANALYZER_H
#define ANALYZER_H

#include <vector>
#include "Stock.h"

class Analyzer{
    public :
    static double averageClose(const std::vector<Stock>& data);
    static double maxHigh(const std::vector<Stock>& data);
    static double minLow(const std::vector<Stock>& data);
    static std::string detectTrend(const std::vector<Stock>& data);
    static std::vector<double> simpleMovingAverage(const std::vector<Stock>& data , int window);
    static double volatility(const std::vector<Stock>& data);
    static std::string smaCrossoverSignal(const std::vector<Stock>& data , int shortWindow , int longWindow);
};

#endif
