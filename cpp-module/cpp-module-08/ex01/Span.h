#ifndef _SPAN_H_
#define _SPAN_H_

#include <iostream>
#include <vector>

class Span {
public:
    typedef std::vector<int>::iterator iterator;

	Span();
	Span(unsigned int n);
	Span(Span const & span);
	Span& operator=(Span const & span);

	void addNumber(int number);
    void addNumber(iterator begin,iterator end);
	int shortestSpan();
	int longestSpan();

	class VectorIsFullException : public std::exception {
	public:
		const char* what() const throw();
	};

	class VectorIsTooSmallException : public std::exception {
	public:
		const char* what() const throw();
	};

	~Span();
private:
	std::vector<int> v;
	unsigned int size;

};


#endif
