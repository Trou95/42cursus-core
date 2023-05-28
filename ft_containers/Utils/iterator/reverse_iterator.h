#pragma once

#include "iterator_traits.h"

namespace ft
{
    template<class Iterator>
    class reverse_iterator
    {
        public:
            typedef Iterator iterator_type;
            typedef typename iterator_traits<Iterator>::value_type value_type;
            typedef typename iterator_traits<Iterator>::difference_type difference_type;
            typedef typename iterator_traits<Iterator>::pointer pointer;
            typedef typename iterator_traits<Iterator>::reference reference;
            typedef typename iterator_traits<Iterator>::iterator_category iterator_category;

            reverse_iterator() : ptr(0) { }
            explicit reverse_iterator(iterator_type ptr) : ptr(ptr) { }

            template<typename Iter>
            reverse_iterator(reverse_iterator<Iter> const &rev_it) : ptr(rev_it.ptr) { }

            reverse_iterator& operator=(const reverse_iterator<Iterator> &rev_it) {
                if(this != &rev_it)
                    this->ptr = rev_it.ptr;
                return *this;
            }

            reference operator*() const {
                iterator_type tmp = ptr;
                return *--tmp;
            }

            pointer operator->() const {
                return &(operator*());
            }

            reverse_iterator& operator++() {
                --ptr;
                return *this;
            }

            reverse_iterator operator++(int) {
                reverse_iterator tmp(*this);
                --ptr;
                return tmp;
            }

            reverse_iterator& operator--() {
                ++ptr;
                return *this;
            }

            reverse_iterator operator--(int) {
                reverse_iterator tmp(*this);
                ++ptr;
                return tmp;
            }

            reverse_iterator operator+(difference_type n) const {
                return reverse_iterator(ptr - n);
            }

            reverse_iterator& operator+=(difference_type n) {
                ptr -= n;
                return *this;
            }

            reverse_iterator operator-(difference_type n) const {
                return reverse_iterator(ptr + n);
            }

            reverse_iterator& operator-=(difference_type n) {
                ptr += n;
                return *this;
            }

            reference operator[](difference_type n) const {
                return *(*this + n);
            }

            template <typename It1, typename It2>
            friend bool operator==(const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) {
                return lhs.ptr == rhs.ptr;
            }

            template <typename It1, typename It2>
            friend bool operator!=(const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) {
                return !(lhs.ptr == rhs.ptr);
            }

            template <typename It1, typename It2>
            friend bool operator<(const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) {
                return lhs.ptr > rhs.ptr;
            }

            template <typename It1, typename It2>
            friend bool operator<=(const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) {
                return lhs.ptr >= rhs.ptr;
            }

            template <typename It1, typename It2>
            friend bool operator>(const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) {
                return lhs.ptr < rhs.ptr;
            }

            template <typename It1, typename It2>
            friend bool operator>=(const reverse_iterator<It1>& lhs, const reverse_iterator<It2>& rhs) {
                return lhs.ptr <= rhs.ptr;
            }

        private:
            iterator_type ptr;

    };

}