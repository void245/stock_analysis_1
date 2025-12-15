#include "Analyzer.h"
#include <stdexcept>
#include <string>
#include <cmath>

double Analyzer::averageClose(const std::vector<Stock>& data){
    if(data.empty()){
        throw std::runtime_error("No Stock data available");
    }
double sum = 0.0 ;
    for(const auto& stock : data){
        sum += stock.close ;
    }
    return sum / data.size() ;
}

double Analyzer::maxHigh(const std::vector<Stock>& data){
    if(data.empty()){
        throw std::runtime_error("No Stock data available");
    }
    double maxValue = data[0].high ;
    for(const auto& stock : data){
        if(stock.high > maxValue){
            maxValue = stock.high ;
        }
    }

    return maxValue ;
}

double Analyzer::minLow(const std::vector<Stock>& data){
    if(data.empty()){
        throw std::runtime_error("No Stock data available");
    }
    double minValue = data[0].low ;
    for(const auto& stock : data){
        if(stock.low < minValue){
            minValue = stock.low ;
        }
    }
    return minValue ;
}

std::string Analyzer::detectTrend(const std::vector<Stock>& data){
    if(data.size() < 2 ){
        throw std::runtime_error("Not enough data to detect trend.");
    }
    double firstClose = data.front().close ;
    double lastClose = data.back().close ;

    double percentChange = ((lastClose - firstClose) / firstClose) * 100 ; 

    if(percentChange > 2.0){
        return "Bullish 📈" ;
    }
    else if(percentChange < -2.0){
        return "Bearish 📉" ;
    }
    else{
        return "Sideways ➖";
    }
}

std::vector<double> Analyzer::simpleMovingAverage(const std::vector<Stock>& data , int window){
    if(window <= 0 || data.size() < window){
        throw std::runtime_error("Invalid window size for SMA");
    }
    std::vector<double> sma ;
    double windowSum = 0.0 ;

    //first window
    for(int i = 0 ; i < window ; i++){
        windowSum += data[i].close ;
    }
    sma.push_back(windowSum / window);

    //sliding window
    for(size_t i = window ; i < data.size() ; i++){
        windowSum += data[i].close ;
        windowSum -=data[i - window].close ;
        sma.push_back(windowSum / window);
    }

    return sma ;
}

double Analyzer::volatility(const std::vector<Stock>& data){
    if(data.size() < 2){
        throw std::runtime_error("Not enough data to calculate volatility.");
    }
    std::vector<double> returns ;

    //calculate daily return 

    for(size_t i = 1 ; i < data.size() ; i++){
        double dailyReturn = (data[i].close - data[i-1].close) / data[i-1].close;
        returns.push_back(dailyReturn);
    }
    //mean of return 
    double mean = 0.0 ;
    for(double r : returns){
        mean += r ;
    }
    mean /= returns.size() ;

    //finding variance 

    double variance = 0.0 ;
    for(double r : returns){
        variance += (r - mean) * (r - mean) ;
    }
    variance /= returns.size();

    // finding standard deviation 

    return std::sqrt(variance) ;
}

std::string Analyzer::smaCrossoverSignal(const std::vector<Stock>& data , int shortWindow , int longWindow){
        if(shortWindow <= 0 || longWindow <= 0 || shortWindow >= longWindow){
            throw std::runtime_error("Invalid SMA window sizes.");
        }

        if(data.size() < longWindow + 1){
            throw std::runtime_error("Not enough data for SMA crossover .");
        }

        auto shortSMA = simpleMovingAverage(data , shortWindow);
        auto longSMA = simpleMovingAverage(data , longWindow);

        int offset = longWindow - shortWindow ;

        double pervShort = shortSMA[shortSMA.size() - 2 - offset];
        double pervLong = longSMA[longSMA.size() - 2];

        double currShort = shortSMA.back();
        double currLong = longSMA.back();

        if(pervShort <= pervLong && currShort > currLong){
            return "BUY ✅";
        }
        else if(pervShort > pervLong && currShort <= currLong){
            return "SELL ❌" ;
        }
        else{
            return "HOLD ⏸️" ;
        }
}


