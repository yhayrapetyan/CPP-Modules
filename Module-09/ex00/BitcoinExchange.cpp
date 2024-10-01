#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(){};
BitcoinExchange::~BitcoinExchange(){};
BitcoinExchange::BitcoinExchange(const BitcoinExchange &copy): _input(copy._input), _database(copy._database){}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other)   {
	if (this == &other)
		return (*this);
	this->_input = other._input;
	this->_database = other._database;
	return (*this);
}

BitcoinExchange::BitcoinExchange(const std::string &filename): _input(filename)    {
    std::ifstream   datafile("data.csv");
    if(!datafile) {
        std::cout << "Error: could not find data.csv\n";
        exit (1);
    }

    std::string header;
    if (!getline(datafile, header)) {
        std::cout << "Error: data.csv or file is empty\n";
        exit(1);
    }

	if (header != "date,exchange_rate") {
        std::cout << "Error: invalid database file header\n";
        exit(1);
    }

    std::string     line;
    while (getline(datafile, line)) {
        size_t      delim_position = line.find(',');
        if (delim_position == std::string::npos) {
            std::cout << "Error: invalid data format in data.csv.\n";
            exit (1);  
        }

		std::string     date = line.substr(0, delim_position);
		if (!this->isValidDateFormat(date)|| !isValidDate(date)) {
			std::cout << "Error: not valid date: " << date << "\n";
			exit(1);
		}

		std::string		price_value = line.substr(delim_position + 1);
		if (!this->isValidFloat(price_value)) {
			std::cout << "Error: not valid price: " << price_value << "\n";
			exit(1);
		}

		double          price = stringToDouble(price_value);
		if (price < 0) {
			std::cout << "Error: price can't be negative value\n";
			exit(1);
		}
		this->_database[date] = price;
    }
    datafile.close();
}

bool BitcoinExchange::isValidFloat(const std::string& str) {
    std::stringstream ss(str);
    double x;
    ss >> x;
    return ss.eof() && !ss.fail();
}

bool BitcoinExchange::isValidDateFormat(std::string &date)    {
    if (date.length() != 10) {
        return false;
    }
	for (size_t i = 0; i < date.size(); ++i) {
        if ((i == 4 || i == 7)) {
            if (date[i] != '-') {
                return false;
            }
        } else {
            if (!isdigit(date[i])) {
                return false;
            }
        }
    }
    return true;
}

bool BitcoinExchange::isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

bool BitcoinExchange::isValidDate(const std::string &date)  {
    int year, month, day;
    if (sscanf(date.c_str(), "%4d-%2d-%2d", &year, &month, &day) != 3) {
        return false;
    }
    if (month < 1 || month > 12 || day < 1 || year == 0) {
        return false;
    }
    switch (month) {
        case BitcoinExchange::February:
            return (day <= (isLeapYear(year) ? 29 : 28));
        case BitcoinExchange::April: 
		case BitcoinExchange::June:
		case BitcoinExchange::September:
		case BitcoinExchange::November:
            return (day <= 30);
        default:
            return (day <= 31);
    }
}

double BitcoinExchange::stringToDouble(const std::string& str) {
    std::stringstream ss(str);
    double result;

    ss >> result;
    if (ss.fail()) {
        return -1;
    }
    return result;
}

void    BitcoinExchange::exchange()   {

	std::ifstream   infile(this->_input);
    if (!infile.is_open()) {
        std::cout << "Error: could not open file: " << this->_input << "\n";
        exit (1);         
    }

	std::string line;
    if (!getline(infile, line)) {
		std::cout << "Error: input file is empty\n";
		exit(1);
	}

	if (line != "date | value") {
        std::cout << "Error: invalid or missing input file header\n";
        exit(1);
    }
	while (getline(infile, line))
	{
		if (line.empty())
			continue;

		size_t	delim_position = line.find('|');
		if (delim_position == std::string::npos) {
            std::cerr << "Error: bad input: [" << line << "]\n";
            continue ;  
        }

		std::string     data = line.substr(0, delim_position - 1);
		if (!isValidDateFormat(data) || !isValidDate(data))
        {
			std::cout << "Error: invalid date format: " << data << "\n";
			continue;
		}

		std::string earliestDate = this->_database.begin()->first;
		if (data < earliestDate) {
			std::cout << "Error: no info for date " << data << "\n";
			continue;
		}

		std::string     value = line.substr(delim_position + 2);
		try {
            double  price = stringToDouble(value);
			if (price < 0 || price > 1000) {
				std::cout << "Error: values should be in range [0-1000] not: " << value << "\n";
				continue;
			}

			std::map<std::string, double>::iterator current_price = this->_database.lower_bound(data);
			if (current_price == this->_database.end()) {
                --current_price;
			} else if (current_price != this->_database.begin() && current_price->first != data) {
					std::map<std::string, double>::iterator prevIt = current_price;
					current_price--;
					--prevIt;
					if ((data.compare(current_price->first) - data.compare(prevIt->first)) > 0)
						current_price = prevIt;  
            }
			double exchangeRate = current_price->second;
            double result = price * exchangeRate;
            std::cout << data << "=> " << value << " = " << result << "\n";
		} catch (...) {
			std::cout << "Error: bad input " << line << "\n";
		}
	}
	infile.close();
}