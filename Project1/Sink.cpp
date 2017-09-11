#include "Sink.h"

template<typename Container>
Sink<typename Container>::Sink()
{
}

/*
template<typename Container>
Sink<typename Container>::~Sink()
{
}
*/

template<typename Container>
typename Sink<Container>& Sink<Container>::operator=(const value_type & value)
{
	out_stream << value;
	if (delim != 0)
		out_stream << delim;
	iter = container->insert(iter, value);
	++iter;
	return *this;
}

template<typename Container>
typename Sink<Container>& Sink<Container>::operator*()
{
	return *this;
}

template<typename Container>
typename Container::value_type * Sink<Container>::operator->()
{
	return &value;
}

template<typename Container>
Sink<Container>& Sink<Container>::operator++()
{
	return *this;
}

template<typename Container>
Sink<Container>& Sink<Container>::operator++(int)
{
	return *this;
}
