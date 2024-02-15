#pragma once

#include <algorithm>
#include <stdexcept>

namespace ods {
    template<class T>
    class Array {
    protected:
        T *a{nullptr};
    public:
        int length{};

        /// Constructor
        explicit Array(int len);

        /// Constructor with initial value
        Array(int len, T init);

        /// Fill the array with a value
        void fill(T x);

        /// Destructor
        virtual ~Array();

        /// Assignment operator
        Array<T> &operator=(const Array<T> &b);

        /// Subscript operator
        T &operator[](int i);

        /// Pointer arithmetic
        T *operator+(int i);

        /// Swap two elements
        void swap(int i, int j);

        /// Copy a range of elements from \p a to \p a0
        static void copyRange(Array<T> &a, Array<T> &a0, int i, int j);

        /// Resize the array
        void resize(int newLength);

        /// Reverse the array
        virtual void reverse();

    };

    template<class T>
    Array<T>::Array(int len) {
        length = len;
        a = new T[length];
    }

    template<class T>
    Array<T>::Array(int len, T init) {
        length = len;
        a = new T[length];
        fill(init);
    }

    template<class T>
    void Array<T>::fill(T x) {
        std::fill(a, a + length, x);
    }

    template<class T>
    Array<T>::~Array() {
        delete[] a; // Deleting a nullptr is safe
    }

    template<class T>
    Array<T> &Array<T>::operator=(const Array<T> &b) {
        if (this != &b) {
            if (length != b.length) {
                delete[] a;
                length = b.length;
                a = new T[length];
            }
            std::copy(b.a, b.a + length, a);
        }
        return *this;
    }

    template<class T>
    void Array<T>::reverse() {
        for (int i = 0; i < length / 2; i++) {
            swap(i, length - i - 1);
        }
    }

    template<class T>
    void Array<T>::resize(int newLength) {
        if (newLength == length) return;

        T *b = new T[newLength];
        int n = std::min(length, newLength);
        std::move(a, a + n, b);
        delete[] a;
        a = b;
        length = newLength;
    }

    template<class T>
    void Array<T>::copyRange(Array<T> &a, Array<T> &a0, int i, int j) {
        int rangeSize = j - i;
        if (rangeSize > 0 && i >= 0 && j <= a.length) {
            a0.resize(rangeSize);
            std::copy(a.a + i, a.a + j, a0.a);
        }
    }

    template<class T>
    void Array<T>::swap(int i, int j) {
        std::swap(a[i], a[j]);
    }

    template<class T>
    T *Array<T>::operator+(int i) {
        return &a[i];
    }

    template<class T>
    T &Array<T>::operator[](int i) {
        if (i >= 0 && i < length)
            return a[i];
        else
            throw std::out_of_range("Index out of range");
    }

} // ods
