#pragma once

#include "iterator_traits.h"


namespace ft
{
    template<class Iterator>
    class random_access_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename ft::iterator_traits<iterator_type>::value_type value_type;
            typedef typename ft::iterator_traits<iterator_type>::difference_type difference_type;
            typedef typename ft::iterator_traits<iterator_type>::pointer pointer;
            typedef typename ft::iterator_traits<iterator_type>::reference reference;
            typedef typename ft::iterator_traits<iterator_type>::iterator_category iterator_category;

            random_access_iterator() : ptr(0) { }
            random_access_iterator(iterator_type ptr) : ptr(ptr) { }
            random_access_iterator(const random_access_iterator& src) : ptr(src.ptr) { }

            ~random_access_iterator() { }

            //template<class T>
            //random_access_iterator(const random_access_iterator<T>& src) : ptr(src.ptr) { }

            random_access_iterator& operator=(const random_access_iterator& src) {
                if(this != &src)
                    this->ptr = src.ptr;
                return *this;
            }

            reference operator*() const {
                return *ptr;
            }

            pointer operator->() const {
                return &(operator*());
            }

            random_access_iterator& operator++() {
                ++ptr;
                return *this;
            }

            random_access_iterator operator++(int) {
                random_access_iterator tmp(*this);
                ++(*this);
                return tmp;
            }

            random_access_iterator& operator--() {
                --ptr;
                return *this;
            }

            random_access_iterator operator--(int) {
                random_access_iterator tmp(*this);
                --(*this);
                return tmp;
            }

            random_access_iterator operator+(const difference_type& n) const {
                random_access_iterator tmp(*this);
                return tmp.ptr + n;
            }

            random_access_iterator& operator+=(const difference_type& n) {
                ptr += n;
                return *this;
            }

            random_access_iterator operator-(const difference_type& n) const {
                return *this + (-n);
            }

            random_access_iterator& operator-=(const difference_type& n) {
                ptr -= n;
                return *this;
            }

            reference operator[](difference_type n) const {
                return ptr[n];
            }

            template <typename It1, typename It2>
            friend bool operator==(const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
                return lhs.ptr == rhs.ptr;
            }

            template <typename It1, typename It2>
            friend bool operator!=(const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
                return !(lhs.ptr == rhs.ptr);
            }


            template <typename It1, typename It2>
            friend bool operator<(const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
                return lhs.ptr < rhs.ptr;
            }

            template <typename It1, typename It2>
            friend bool operator<=(const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
                return lhs.ptr <= rhs.ptr;
            }

            template <typename It1, typename It2>
            friend bool operator>(const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
                return lhs.ptr > rhs.ptr;
            }

            template <typename It1, typename It2>
            friend bool operator>=(const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
                return lhs.ptr >= rhs.ptr;
            }

            template<typename It>
            friend random_access_iterator<It> operator+(typename random_access_iterator<It>::difference_type n, random_access_iterator<It>& src) {
                src += n;
                return src;
            }


            template<typename It1, typename It2>
            friend typename random_access_iterator<It1>::difference_type operator-(const random_access_iterator<It1>& lhs, const random_access_iterator<It2>& rhs) {
                return lhs.ptr - rhs.ptr;
            }



        private:
            iterator_type ptr;
    };

}