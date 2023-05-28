#pragma once

#include "vector.hpp"

namespace ft
{

    template<class T, class Container = ft::vector<T> >
            class stack
            {
                public:

                    typedef Container container_type;
                    typedef typename Container::value_type value_type;
                    typedef typename Container::size_type size_type;
                    typedef typename Container::reference reference;
                    typedef typename Container::const_reference const_reference;

                    explicit stack(const container_type& cntr = container_type()) : c(cntr) { }

                    value_type& top()
                    {
                        return c.back();
                    }

                    const value_type& top() const
                    {
                        return c.back();
                    }

                    void push(const value_type& val)
                    {
                        c.push_back(val);
                    }

                    void pop()
                    {
                        c.pop_back();
                    }

                    bool empty() const
                    {
                        return c.empty();
                    }

                    size_type size() const
                    {
                        return c.size();
                    }


                protected:

                    Container c;

                friend bool	operator==(const stack &lhs, const stack &rhs)
                {
                    return lhs.c == rhs.c;
                }
                friend bool	operator!=(const stack &lhs, const stack &rhs)
                {
                    return !(lhs == rhs);
                }
                friend bool	operator<(const stack &lhs, const stack &rhs)
                {
                    return lhs.c < rhs.c;
                }
                friend bool	operator>(const stack &lhs, const stack &rhs)
                {
                    return rhs < lhs;
                }
                friend bool	operator<=(const stack &lhs, const stack &rhs)
                {
                    return !(lhs > rhs);
                }
                friend bool	operator>=(const stack &lhs, const stack &rhs)
                {
                    return !(lhs < rhs);
                }


            };





}