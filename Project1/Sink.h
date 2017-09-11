#pragma once
#include<iostream>
using namespace std;

template<typename Container>
class Sink;
template<class Container, class Iterator>
Sink<Container> sinker(Container& container, basic_ostream<char, char_traits<char> >& ostream, Iterator i, const char* delimiter);
template<class Container, class Iterator>
Sink<Container> sinker(Container& container, basic_ostream<char, char_traits<char> >& ostream, Iterator i);

template<typename Container>
class Sink
	:public iterator<output_iterator_tag, void, void, void, void>
{
public:
	typedef typename std::output_iterator_tag iterator_category;
	typedef typename Container::size_type difference_type;
	typedef typename Container::value_type value_type;
	typedef typename Container::value_type& reference_type;
	typedef typename Container::value_type* pointer_type;
	typedef basic_ostream<char, char_traits<char> > ostream_type;
	typedef typename Container::value_type value_type;
protected:
	Container* container;
	ostream_type* out_stream;
	typename Container::iterator iter;
	const char* delim;
public:
	Sink(Container& x, ostream_type& s, typename Container::iterator i, const char* delimiter)
		:container(&x), out_stream(&s) , iter(i), delim(delimiter){}
	Sink(Container& x, ostream_type& s, typename Container::iterator i)
		:container(&x), out_stream(&s), iter(i), delim(0) {}
	Sink();
	//~Sink();

	Sink<Container>& operator=(const typename Container::value_type& value);
	Sink<Container>& operator*();
	value_type* operator->();
	Sink<Container>& operator++();
	Sink<Container>& operator++(int);



};

template<class Container, class Iterator>
inline Sink<Container> sinker(Container & container, basic_ostream<char>& ostream, Iterator i,const char * delimiter)
{
	typedef typename Container::iterator iter;
	return Sink<Container>(container, ostream, iter(i), delimiter);
}

template<class Container, class Iterator>
inline Sink<Container> sinker(Container & container, basic_ostream<char>& ostream, Iterator i )
{
	typedef typename Container::iterator iter;
	return Sink<Container>(container, ostream, iter(i));
}
