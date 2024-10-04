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

		class InvalidPrice : public std::exception {
		public:
			InvalidPrice();
			InvalidPrice(const InvalidPrice &other);
			InvalidPrice &operator=(const InvalidPrice &other);
			InvalidPrice(const std::string &line);
			virtual ~InvalidPrice() throw();
			char const  *what() const throw();
		private:
			std::string _line;
		};

		class InvalidDateFormat : public std::exception { 
		public:
			InvalidDateFormat();
			InvalidDateFormat(const InvalidDateFormat &other);
			InvalidDateFormat &operator=(const InvalidDateFormat &other);
			InvalidDateFormat(const std::string &line);
			virtual ~InvalidDateFormat() throw();
			char const  *what() const throw();
		private:
			std::string _line;
		};
		class InvalidPriceValue : public std::exception { public: char const  *what() const throw(); };
		class DataOpenException : public std::exception { public: char const  *what() const throw(); };
		class MissingDataHeader : public std::exception { public: char const  *what() const throw(); };
		class InvalidDataHeader : public std::exception { public: char const  *what() const throw(); };
		class MissingDataDelim : public std::exception { public: char const  *what() const throw(); };
		class MissingPrice : public std::exception { public: char const  *what() const throw(); };
		class InputOpenException : public std::exception { public: char const  *what() const throw(); };
		class InputEmptyException : public std::exception { public: char const  *what() const throw(); };
		class InvalidInputHeader : public std::exception { public: char const  *what() const throw(); };
};

#endif