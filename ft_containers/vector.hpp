#pragma once

#include <memory>
#include <stdexcept>
#include <cstring>
#include "Utils/enable_if/enable_if.h"
#include "Utils/is_integral/is_integral.h"
#include "Utils/iterator/reverse_iterator.h"
#include "Utils/iterator/random_access_iterator.h"
#include "Utils/Utils.h"


namespace ft
{
    template<class T, class Allocator = std::allocator<T> >
            class vector
            {
                public:

                    typedef T value_type;
                    typedef Allocator allocator_type;

                    typedef value_type& reference;
                    typedef const value_type& const_reference;
                    typedef typename allocator_type::pointer pointer;
                    typedef typename allocator_type::const_pointer const_pointer;
                    typedef ft::random_access_iterator<pointer> iterator;
                    typedef ft::random_access_iterator<const_pointer> const_iterator;
                    typedef ft::reverse_iterator<iterator> reverse_iterator;
                    typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;


                    typedef typename ft::iterator_traits<iterator>::difference_type difference_type;
                    typedef typename allocator_type::size_type size_type;


                public:

                    iterator begin() { return arr; }

                    const_iterator begin() const { return arr; }

                    iterator end() { return arr + _size; }

                    const_iterator end() const { return arr + _size; }

                    reverse_iterator rbegin() { return reverse_iterator(end()); }

                    const_reverse_iterator rbegin() const { return const_reverse_iterator(end()); }

                    reverse_iterator rend() { return reverse_iterator(begin()); }

                    const_reverse_iterator rend() const { return const_reverse_iterator(begin()); }


                    explicit vector(const allocator_type& alloc = allocator_type()) :
                        arr(NULL) , _size(0) , _capacity(0) , _alloc(alloc) { }

                    explicit vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type())  :
                        arr(NULL), _size(0), _capacity(0), _alloc(alloc)
                    {
                        resize(n,val);
                    }

                    template<class InputIterator>
                    vector(InputIterator first, InputIterator last,
                           const allocator_type& alloc = allocator_type(),
                           typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0) :
                           arr(NULL), _size(0) , _capacity(0), _alloc(alloc)
                    {
                        assign(first,last);
                    }

                    vector(const vector& x) :
                        _size(x._size), _capacity(x._capacity), _alloc(x._alloc)
                    {
                        arr = _alloc.allocate(_capacity);
                        for(size_type i = 0; i < _size; i++)
                            _alloc.construct(&arr[i],x.arr[i]);
                    }

                    ~vector()
                    {
                        clear();
                        _alloc.deallocate(arr,_capacity);
                    }

                    vector& operator=(const vector& x)
                    {
                        if(this == &x)
                            return *this;

                        for(size_type i = 0; i < _size; i++)
                            _alloc.destroy(&arr[i]);

                        _size = x._size;
                        _capacity = x._capacity;
                        arr = _alloc.allocate(_capacity);

                        for(size_type i = 0; i < _size; i++)
                            _alloc.construct(&arr[i],&x.arr[i]);

                        return *this;
                    }

                    reference operator[](size_type n)
                    {
                        return arr[n];
                    }

                    const_reference operator[](size_type n) const
                    {
                        return arr[n];
                    }

                    template<class InputIterator>
                    void assign(InputIterator first, InputIterator last,
                            typename ft::enable_if<!ft::is_integral<InputIterator>::value,InputIterator>::type*)
                    {
                        clear();
                        for(; first != last; first++)
                            push_back(*first);
                    }

                    void assign(size_type n, const value_type& val)
                    {
                        clear();
                        for(size_type i = 0; i < n; i++)
                            push_back(val);
                    }

                    void push_back(const value_type& val)
                    {
                        if(_size == _capacity)
                            reserve(_size > 0 ? _size * 2 : 1);
                        _alloc.construct(&arr[_size], val);
                        _size++;
                    }

                    void pop_back()
                    {
                        _alloc.destroy(&arr[_size - 1]);
                        _size--;
                    }

                    void clear()
                    {
                        if(arr != NULL) {
                            for(size_type i = 0; i < _size; i++)
                                _alloc.destroy(&arr[i]);
                            _size = 0;
                        }
                    }

                    iterator insert(iterator position, const value_type& val)
                    {
                        const size_type index = position - begin();

                        insert(position, 1, val);

                        return position;
                    }



                    void insert(iterator position, size_type n, const value_type& val)
                    {
                        const size_type index = position - begin();

                        if(_size + n >= _capacity)
                            reserve(_size > 0 ? _size * 2 : 1);

                        std::copy_backward(arr + index, arr + _size, arr + _size + n);
                        for(size_type i = index, count = index + n; i < count; i++)
                            _alloc.construct(&arr[i],val);
                        _size += n;
                    }



                    template<class InputIterator>
                    void insert(iterator position, InputIterator first, InputIterator last,
                                typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
                    {
                        size_type index = position - begin();
                        size_type n = last - first;

                        _size += n;
                        if(_size >= _capacity)
                            reserve(_size);

                        for(size_type i = (_size - 1) - index; i < _size; i++)
                            arr[i] = arr[i - n];
                        for(size_type i = index, count = index + n; i < count; i++,first++)
                            _alloc.construct(&arr[i],*first);
                    }

                    iterator erase(iterator position)
                    {
                        size_type index = position - begin();

                        _alloc.destroy(&arr[index]);
                        for(; index < _size; index++)
                            arr[index] = arr[index + 1];
                        _size--;
                        return position;
                    }

                    template<class InputIterator>
                    iterator erase(InputIterator first, InputIterator last,
                               typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0)
                    {
                        size_type index = first - begin();
                        size_type count = last - first;

                        for(size_type i = index,size = index + count; i < size; i++)
                            _alloc.destroy(&arr[i]);
                        _size -= count;
                        for(; index < _size; index++)
                            arr[index] = arr[index + count];
                        return first;
                    }

                    void swap(vector& x)
                    {
                        value_type *tmp_arr = x.arr;
                        size_type tmp_size = x._size;
                        size_type tmp_capacity = x._capacity;

                        x.arr = arr;
                        x._size = _size;
                        x._capacity = _capacity;
                        arr = tmp_arr;
                        _size = tmp_size;
                        _capacity = tmp_capacity;
                    }

                    void resize(size_type n, value_type val = value_type())
                    {
                        if(n > _capacity)
                            reserve(n);
                        if(n < _size) {
                            for(size_type i = n; i < _size; i++)
                                _alloc.destroy(&arr[i]);
                        }
                        else {
                            for(size_type i = _size; i < n; i++)
                                _alloc.construct(&arr[i],val);
                        }
                        _size = n;
                    }

                    void reserve(size_type n)
                    {
                        if(n > _alloc.max_size())
                            throw std::length_error("vector::reserve");
                        if(n > _capacity) {
                            value_type* tmpArr = _alloc.allocate(n);
                            if(arr != NULL) {
                                for(size_type i = 0; i < _capacity; i++) {
                                    _alloc.construct(&tmpArr[i],arr[i]);
                                    _alloc.destroy(&arr[i]);
                                }
                                _alloc.deallocate(arr,_capacity);
                            }
                            arr = tmpArr;
                            _capacity = n;
                        }
                    }


                    reference at(size_type n)
                    {
                        if(n >= _size)
                            throw std::out_of_range("vector");
                        return arr[n];
                    }

                    const_reference at(size_type n) const
                    {
                        if(n >= _size)
                            throw std::out_of_range("vector");
                        return arr[n];
                    }

                    reference front()
                    {
                        return arr[0];
                    }

                    const_reference front() const
                    {
                        return arr[0];
                    }

                    reference back()
                    {
                        return arr[_size - 1];
                    }

                    const_reference back() const
                    {
                        return arr[_size - 1];
                    }

                    bool empty() const
                    {
                        return _size == 0;
                    }

                    size_type size() const
                    {
                        return _size;
                    }

                    size_type max_size() const
                    {
                        return _alloc.max_size();
                    }

                    size_type capacity() const
                    {
                        return _capacity;
                    }




                private:
                    value_type* arr;
                    size_type _size;
                    size_type _capacity;
                    allocator_type  _alloc;


                friend bool operator==(const vector& lhs, const vector& rhs) {
                    if(lhs.size() != rhs.size())
                        return false;
                    return equal(lhs.begin(), lhs.end(), rhs.begin());
                }

                friend bool operator!=(const vector& lhs, const vector& rhs) {
                    if(lhs.size() != rhs.size())
                        return true;
                    return !(equal(lhs.begin(), lhs.end(), rhs.begin()));
                }

                friend bool operator<(const vector& lhs, const vector& rhs) {
                    return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
                }

                friend bool operator<=(const vector& lhs, const vector& rhs) {
                    return !(lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end()));
                }

                friend bool operator>(const vector& lhs, const vector& rhs) {
                    return lexicographical_compare(rhs.begin(), rhs.end(), lhs.begin(), lhs.end());
                }

                friend bool operator>=(const vector& lhs, const vector& rhs) {
                    return !(lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
                }


            };

}
