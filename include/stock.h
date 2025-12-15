#ifndef STOCK_H
#define STOCK_H

#include<string>

struct Stock{
   std::string date;
   std::string symbol ;
   double open ;
   double high ;
   double low ;
   double close ;
   long long volume ;
};

#endif 
