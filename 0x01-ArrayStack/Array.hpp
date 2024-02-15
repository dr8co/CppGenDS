#pragma once

namespace ods {
    template<class T>
    class Array {
    protected:
            T* a;
    public:
        int length;

        /// Constructor
        Array(int len);

        /// Constructor with initial value
        Array(int len, T init);

        /// Fill the array with a value
        void fill(T x);

        /// Destructor
        virtual ~Array();

        /// Assignment operator
        Array<T>& operator=(Array<T> &b);

        /// Subscript operator
        T& operator[](int i);

        /// Pointer arithmetic
        T* operator+(int i);

        /// Swap two elements
        void swap(int i, int j);

        /// Copy a range of elements from \p a to \p a0
        static void copyRange(Array<T> &a, Array<T> &a0, int i, int j);

        /// Reverse the array
        virtual void reverse();

    };

} // ods

