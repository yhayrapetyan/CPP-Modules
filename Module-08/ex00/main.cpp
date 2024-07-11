#include "easyfind.hpp"
#include <set>
#include <list>
#include <deque>
#include <vector>

# define RESET			"\033[0m"
# define RED			"\033[31m"				/* Red */
# define GREEN			"\033[32m"				/* Green */
# define YELLOW			"\033[33m"				/* Yellow */
# define MAGENTA		"\033[35m"				/* Magenta */
# define CYAN			"\033[36m"				/* Cyan */

int	main(void)
{
	 int a = 7;
    int b = 1;
    int c = 0;
    int e = 5;
    int f = 42;

    std::set<int>       set;
    std::list<int>      list;
    std::deque<int>     deque;
    std::vector<int>    vector;

    for (int i = 0; i < 10; i++)
    {
        set.insert(i);
        list.push_back(i);
        deque.push_front(i);
        vector.push_back(i);
    }

    std::cout << YELLOW << "======================= SET =======================" << std::endl;

    std::cout << MAGENTA << "Set:";
    for (std::set<int>::iterator it = set.begin(); it != set.end(); it++)
        std::cout << CYAN << " " << *it;
    std::set<int>::iterator s = easyfind(set, a);
    std::cout << MAGENTA << " Is " << a <<  " in the set: " << GREEN << (s != set.end() ? "yes" : "no") << RESET;

    std::cout << std::endl << YELLOW << "====================== LISTS ======================" << std::endl;

    std::cout << MAGENTA << "List:";
    for (std::list<int>::iterator it = list.begin(); it != list.end(); it++)
        std::cout << CYAN << " " << *it;
    std::list<int>::iterator l = easyfind(list, b);
     std::cout << MAGENTA << " Is " << b <<  " in the list: " << GREEN << (l != list.end() ? "yes" : "no") << RESET;

    std::cout << std::endl << YELLOW << "====================== DEQUE ======================" << std::endl;

    std::cout << MAGENTA << "Deque:";
    for (std::deque<int>::iterator it = deque.begin(); it != deque.end(); it++)
        std::cout << CYAN << " " << *it;
    std::deque<int>::iterator d = easyfind(deque, c);
    std::cout << MAGENTA << " Is " << c <<  " in the deque: " << GREEN << (d != deque.end() ? "yes" : "no") << RESET;

    std::cout << std::endl << YELLOW << "====================== VECTOR =====================" << std::endl;

    std::cout << MAGENTA << "Vector:";
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
        std::cout << CYAN << " " << *it;
    std::vector<int>::iterator v = easyfind(vector, e);
    std::cout << MAGENTA << " Is " << e <<  " in the vector: " << GREEN << (v != vector.end() ? "yes" : "no") << RESET;

    std::cout << std::endl << YELLOW << "======================= NON =======================" << std::endl;

    std::cout << MAGENTA << "Non:";
    for (std::vector<int>::iterator it = vector.begin(); it != vector.end(); it++)
        std::cout << CYAN << " " << *it;
    std::vector<int>::iterator n = easyfind(vector, f);
    std::cout << MAGENTA << " Is " << f <<  " in the vector: " << RED << (n != vector.end() ? "yes" : "no") << RESET << std::endl;
}