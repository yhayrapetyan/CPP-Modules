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

BitcoinExchange::InvalidDateFormat::InvalidDateFormat(){}
BitcoinExchange::InvalidDateFormat::InvalidDateFormat(const std::string &line):_line(line) {}
BitcoinExchange::InvalidDateFormat::~InvalidDateFormat() throw() {}
BitcoinExchange::InvalidDateFormat::InvalidDateFormat(const InvalidDateFormat &other): _line(other._line){};
BitcoinExchange::InvalidDateFormat &BitcoinExchange::InvalidDateFormat::operator=(const InvalidDateFormat &other) {
	if (this == &other)
		return (*this);
	this->_line = other._line;
	return (*this);
};

BitcoinExchange::InvalidPrice::InvalidPrice(){}
BitcoinExchange::InvalidPrice::InvalidPrice(const std::string &line):_line(line) {}
BitcoinExchange::InvalidPrice::~InvalidPrice() throw() {}
BitcoinExchange::InvalidPrice::InvalidPrice(const InvalidPrice &other): _line(other._line){};
BitcoinExchange::InvalidPrice &BitcoinExchange::InvalidPrice::operator=(const InvalidPrice &other) {
	if (this == &other)
		return (*this);
	this->_line = other._line;
	return (*this);
};

char	const *BitcoinExchange::DataOpenException::what() 	const throw(){ return ("Error: could not find data.csv");}
char	const *BitcoinExchange::MissingDataHeader::what() 	const throw(){ return ("Error: missing data.csv header");}
char	const *BitcoinExchange::InvalidDataHeader::what() 	const throw(){ return ("Error: invalid data.csv header");}
char	const *BitcoinExchange::MissingDataDelim::what() 	const throw(){ return ("Error: invalid date format in data.csv");}
char	const *BitcoinExchange::InvalidDateFormat::what() 	const throw(){ return (("Error: not valid date: " + _line).c_str());}
char	const *BitcoinExchange::MissingPrice::what() 		const throw(){ return ("Error: missing price value");}
char	const *BitcoinExchange::InvalidPrice::what() 		const throw(){ return (("Error: not valid price: " + _line).c_str());}
char	const *BitcoinExchange::InvalidPriceValue::what() 	const throw(){ return ("Error: price can't be negative value ");}
char	const *BitcoinExchange::InputOpenException::what() 	const throw(){ return ("Error: could not open input file");}
char	const *BitcoinExchange::InputEmptyException::what() const throw(){ return ("Error: input file is empty");}
char	const *BitcoinExchange::InvalidInputHeader::what() 	const throw(){ return ("Error: invalid or missing input file header");}



BitcoinExchange::BitcoinExchange(const std::string &filename): _input(filename)    {
    std::ifstream   datafile("data.csv");
    if(!datafile)
		throw DataOpenException();

    std::string header;
    if (!getline(datafile, header)) 
		throw MissingDataHeader();

	if (header != "date,exchange_rate") 
		throw InvalidDataHeader();

    std::string     line;
    while (getline(datafile, line)) {
        size_t      delim_position = line.find(',');
        if (delim_position == std::string::npos) 
			throw MissingDataDelim();

		std::string     date = line.substr(0, delim_position);
		if (!this->isValidDateFormat(date)|| !isValidDate(date))
			throw InvalidDateFormat(line);

		if (delim_position == line.length() - 1)
			throw MissingPrice();
		std::string		price_value = line.substr(delim_position + 1);
		if (!this->isValidFloat(price_value))
			throw InvalidPrice(line);

		double          price = stringToDouble(price_value);
		if (price < 0) 
			throw InvalidPriceValue();
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
    if (!infile.is_open())
		throw InputOpenException();

	std::string line;
    if (!getline(infile, line))
		throw InputEmptyException();

	if (line != "date | value")
		throw InvalidInputHeader();
	
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

		if (delim_position == line.length() - 1) {
			std::cout << "Error: missing price value for line => " << line << "\n";
			continue;
		}
		std::string     value = line.substr(delim_position + 2);
		if (!this->isValidFloat(value)) {
			std::cout << "Error: not valid price: " << value << "\n";
			continue;
		}
		
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