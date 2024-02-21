#pragma once

#include "Array.hpp"

namespace ods {
    template<class T>
    class DualArrayDeque;

    template<class T>
    class ArrayStack {
    protected:
        friend class DualArrayDeque<T>;

        Array<T> a;
        int n{};

        virtual void resize();

    public:
        /// Default constructor
        ArrayStack();

        /// Destructor
        virtual ~ArrayStack() = default;

        /// Returns the number of elements in the stack
        [[nodiscard]] int size() const;

        /// Returns the element at index i in the stack
        T get(int i);

        /// Replaces the element at index i with x and returns the original element
        T set(int i, T x);

        /// Inserts element x at index i
        virtual void add(int i, T x);

        /// Adds element x to the end of the array
        virtual void add(T x);

        /// Removes the element at index i
        virtual T remove(int i);

        /// Resets the stack by setting the size to 0 and creating a new array of size 1
        virtual void clear();
    };

    template<class T>
    ArrayStack<T>::ArrayStack() : a(1) {}

    template<class T>
    void ArrayStack<T>::resize() {
        Array<T> b(std::max(2 * n, 1));
        for (int i = 0; i < n; ++i) {
            b[i] = a[i];
        }
        a = b;
    }

    template<class T>
    int ArrayStack<T>::size() const {
        return n;
    }

    template<class T>
    T ArrayStack<T>::get(int i) {
        return a[i];
    }

    template<class T>
    T ArrayStack<T>::set(int i, T x) {
        T y = a[i];
        a[i] = x;
        return y;
    }

    template<class T>
    void ArrayStack<T>::add(int i, T x) {
        if (n + 1 > a.length) resize();
        for (int j = n; j > i; --j) {
            a[j] = a[j - 1];
        }
        a[i] = x;
        ++n;
    }

    template<class T>
    void ArrayStack<T>::add(T x) {
        add(size(), x);
    }

    template<class T>
    T ArrayStack<T>::remove(int i) {
        T x = a[i];
        for (int j = i; j < n - 1; ++j) {
            a[j] = a[j + 1];
        }
        --n;
        if (a.length >= 3 * n) resize();
        return x;
    }

    template<class T>
    void ArrayStack<T>::clear() {
        n = 0;
        a = Array<T>(1);
    }
} // namespace ods
