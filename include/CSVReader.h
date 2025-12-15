#ifndef CSVREADER_H
#define CSVREADER_H

#include <string>
#include <vector>
#include "Stock.h"

class CSVReader{
    public:
    static std::vector<Stock> readCSV (const std::string& filename);
};

#endif
