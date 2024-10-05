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

BitcoinExchange::DefaultException::DefaultException(){}
BitcoinExchange::DefaultException::DefaultException(const std::string &message):_message(message) {}
BitcoinExchange::DefaultException::~DefaultException() throw() {}
BitcoinExchange::DefaultException::DefaultException(const DefaultException &other): _message(other._message){};
BitcoinExchange::DefaultException &BitcoinExchange::DefaultException::operator=(const DefaultException &other) {
	if (this == &other)
		return (*this);
	this->_message = other._message;
	return (*this);
};


char	const *BitcoinExchange::InvalidDateFormat::what() 	const throw(){ return (("Not valid date: " + _line).c_str());}
char	const *BitcoinExchange::InvalidPrice::what() 		const throw(){ return (("Not valid price: " + _line).c_str());}
char	const *BitcoinExchange::DefaultException::what() 	const throw(){ return (_message.c_str());}


BitcoinExchange::BitcoinExchange(const std::string &filename): _input(filename)    {
    std::ifstream   datafile("data.csv");
    if(!datafile)
		throw DefaultException("Could not find data.csv");

    std::string header;
    if (!getline(datafile, header)) 
		throw DefaultException("Missing data.csv header");

	if (header != "date,exchange_rate") 
		throw DefaultException("Invalid data.csv header");

    std::string     line;
    while (getline(datafile, line)) {
        size_t      delim_position = line.find(',');
        if (delim_position == std::string::npos)
			throw DefaultException("Missing data.csv delimetr");

		std::string     date = line.substr(0, delim_position);
		if (!this->isValidDateFormat(date)|| !isValidDate(date))
			throw InvalidDateFormat(line);

		if (delim_position == line.length() - 1)
			throw DefaultException("Missing price value");
		std::string		price_value = line.substr(delim_position + 1);
		if (!this->isValidFloat(price_value))
			throw InvalidPrice(line);

		double          price = stringToDouble(price_value);
		if (price < 0) 
			throw DefaultException("Price can't be negative value");
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
    if (ss.fail() && !ss.eof()) {
        return -1;
    }
    return result;
}


std::map<std::string, double> BitcoinExchange::isValidInput(std::string line)
{
	std::map<std::string, double> result;

	if (line.empty()){
		return result;
	}

	size_t	delim_position = line.find('|');
	if (delim_position == std::string::npos) {
		std::cout << "Error: bad input: [" << line << "]\n";
		return result ;  
	}

	if (delim_position == line.length() - 1) {
		std::cout << "Error: missing price value for line => " << line << "\n";
		return result;
	}

	if (delim_position == 0) {
		std::cout << "Error: missing date => " << line << "\n";
		return result;
	}

	if (line[delim_position + 1] != ' ' || line[delim_position - 1] != ' ') {
		std::cout << "Error: delimetr should be surounded by spaces => " << line << "\n" ;
		return result;
	}

	std::string     data = line.substr(0, delim_position - 1);
	if (!isValidDateFormat(data) || !isValidDate(data)) {
		std::cout << "Error: invalid date format: " << data << "\n";
		return result;
	}

	std::string earliestDate = this->_database.begin()->first;
	if (data < earliestDate) {
		std::cout << "Error: no info for date " << data << "\n";
		return result;
	}

	std::string     value = line.substr(delim_position + 2);
	if (!this->isValidFloat(value)) {
		std::cout << "Error: not valid price: " << value << "\n";
		return result;
	}
	
	double  price = stringToDouble(value);
	if (price < 0 || price > 1000) {
		std::cout << "Error: values should be in range [0-1000] not: " << value << "\n";
		return result;
	}
	result[data] = price;
	return (result);
}

void    BitcoinExchange::exchange()   {
	std::map<std::string, double> input;

	std::ifstream   infile(this->_input);
    if (!infile.is_open())
		throw DefaultException("Could not open input file");

	std::string line;
    if (!getline(infile, line))
		throw DefaultException("Input file is empty");

	if (line != "date | value")
		throw DefaultException("Invalid or missing input file header");
	
	while (getline(infile, line))
	{	
		input = isValidInput(line);
		if (input.size() == 0)
			continue;
		try {
			std::map<std::string, double>::iterator current_price = this->_database.lower_bound(input.begin()->first);
			if (current_price == this->_database.end()) {
                --current_price;
			} else if (current_price != this->_database.begin() && current_price->first != input.begin()->first) {
					std::map<std::string, double>::iterator prevIt = current_price;
					current_price--;
					--prevIt;
					if ((input.begin()->first.compare(current_price->first) -input.begin()->first.compare(prevIt->first)) > 0)
						current_price = prevIt;  
            }
			double exchangeRate = current_price->second;
            double result = input.begin()->second * exchangeRate;
            std::cout << input.begin()->first << "=> " << input.begin()->second << " = " << result << "\n";
		} catch (...) {
			std::cout << "Error: bad input " << line << "\n";
		}
	}
	infile.close();
}