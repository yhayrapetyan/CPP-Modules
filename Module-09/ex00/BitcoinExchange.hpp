#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <sstream>
#include <string.h>

class BitcoinExchange {

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &filename);
        BitcoinExchange(const BitcoinExchange &copy);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void    exchange();

    private:
		enum Months {
			January = 1,
			February,
			March,
			April,
			May,
			June,
			Jule,
			August,
			September,
			October,
			November,
			December
		};
        std::string _input;
        std::map<std::string, double> _database;
		double 	stringToDouble(const std::string& str);
        bool 	isValidDateFormat(std::string &date);
		bool 	isValidFloat(const std::string& str);
        bool	isValidDate(const std::string &date);
        bool 	isLeapYear(int year);
};

#endif