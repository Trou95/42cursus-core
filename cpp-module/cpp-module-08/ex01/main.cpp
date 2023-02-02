#include "Span.h"

int main()
{
	Span sp = Span(10);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

    std::vector<int> v;
    for(int i = 1; i < 5; i++)
        v.push_back(i);
    sp.addNumber(v.begin(),v.end());

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;


}