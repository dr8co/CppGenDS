#include <iostream>
#include <chrono>
#include <cassert>
#include "ArrayStack.hpp"

constexpr unsigned RA = 0x01; // Random access
constexpr unsigned FM = 0x02; // Front modifications

template<class List>
void ListTests(List &ell, const int n, const unsigned flags) {
    std::cout.setf(std::ios::fixed, std::ios::floatfield);
    std::cout.precision(5);

    ell.clear();
    std::cout << "Adding " << n << " elements..." << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        ell.add(ell.size(), i);
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::cout << "Done in " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

    if (flags & RA) {
        std::cout << "Random access..." << std::endl;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; ++i) {
            assert(ell.get(i) == i);
        }
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Done in " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

        std::cout << "Setting..." << std::endl;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; ++i) {
            ell.set(i, 2 * i);
        }
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Done in " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    } else {
        std::cout << "Reading 2log(" << n << ") elements..." << std::endl;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i < n; i *= 2) {
            assert(ell.get(i) == i);
            assert(ell.get(n - i - 1) == n - i - 1);
        }
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Done in " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

        std::cout << "Setting 2log(" << n << ") elements..." << std::endl;
        start = std::chrono::high_resolution_clock::now();

        for (int i = 1; i < n; i *= 2) {
            ell.set(i, 2 * i);
            ell.set(n - i - 1, 2 * (n - i - 1));
        }
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Done in " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    if (flags & FM) {
        std::cout << "Adding " << n << " elements to the front..." << std::endl;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; ++i) {
            ell.add(0, i);
        }
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Done in " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

        std::cout << "Removing " << n << " elements from the front..." << std::endl;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 0; i < n; ++i) {
            ell.remove(0);
        }
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Done in " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    } else {
        std::cout << "Adding log(" << n << ") elements to the front..." << std::endl;

        start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i < n; i *= 2) {
            ell.add(0, i);
        }
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Done in " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;

        std::cout << "Removing log(" << n << ") elements from the front..." << std::endl;
        start = std::chrono::high_resolution_clock::now();
        for (int i = 1; i < n; i *= 2) {
            ell.remove(0);
        }
        end = std::chrono::high_resolution_clock::now();
        std::cout << "Done in " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
    }

    std::cout << "Removing " << n << " elements..." << std::endl;
    start = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < n; ++i) {
        ell.remove(ell.size() - 1);
    }
    end = std::chrono::high_resolution_clock::now();
    std::cout << "Done in " << std::chrono::duration<double, std::milli>(end - start).count() << " ms" << std::endl;
}

int main() {
    constexpr int n = 1000;
    ods::ArrayStack<int> as;
    ListTests(as, n, RA | FM);
    return 0;
}
