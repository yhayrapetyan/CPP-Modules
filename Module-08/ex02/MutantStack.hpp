#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <vector>
#include <deque>
#include <iostream>
#include <exception>

template <typename T>
class MutantStack : public std::stack<T> {

public:

	MutantStack();
	MutantStack(const MutantStack& other);
	MutantStack& operator=(const MutantStack& other); 
	~MutantStack();

	typedef	std::deque<T> cont;
	typedef	typename cont::iterator iterator;
	typedef	typename cont::const_iterator const_iterator;

	iterator				begin();
	const_iterator			begin() const;
	iterator				end();
	const_iterator			end() const;

};

#include "MutantStack.tpp"

#endif