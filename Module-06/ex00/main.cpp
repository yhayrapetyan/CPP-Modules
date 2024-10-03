#include <iostream>
#include <string>
#include "ScalarConverter.hpp"

void runTest(const std::string& literal) {
    std::cout << "-----------------------------" << std::endl;
    std::cout << "Testing literal: " << literal << std::endl;
    ScalarConverter::convert(literal);
    std::cout << "-----------------------------\n" << std::endl;
}

int main() {
	//Zeros
    runTest("0");//check
    runTest("0.0f");//check
    runTest("0.0");//check

	std::cout << "\n";
    runTest("a");
    runTest("Z");
    runTest("!");
	std::cout << "\n";
	
    
    // Test int literals
    runTest("0");//check
    runTest("-42");
    runTest("42");
    runTest("214748");
    runTest("2147483");
    runTest("2147483646");
    runTest("2147483647"); // Max int
    runTest("-2147483648"); // Min int
	std::cout << "\n";

    // Test float literals
    runTest("0.0f");//check
    runTest("-4.2f");
	runTest("27.18");
    runTest("4.2f");
    runTest("-inff");
    runTest("+inff");
    runTest("nanf");
	std::cout << "\n";

    // Test double literals
    runTest("0.0");//check
    runTest("-4.2");
    runTest("4.2");
    runTest("-inf");
    runTest("+inf");
    runTest("nan");
	std::cout << "\n";

    // Test invalid literals
    runTest("invalid");
    runTest("123abc");
    runTest("4.2.2");
	std::cout << "\n";


    return 0;
}
