#include <iostream>
#include "vektorius.h"

// 4
template<typename T, class FunkcinisObjektas>
void bubbleSort(victor<T> &array, FunkcinisObjektas fnct)
{
    for (iter<T> i = array.begin(); i != array.end(); ++i) {
        for (iter<T> j = array.begin(); j < i; ++j) {
            if (fnct(*i, *j)) {
                std::iter_swap(i, j);
            }
        }
    }
}

// 1
int sumcmp(int a, int b)
{
    int sumA = 0;
    int sumB = 0;

    while (a > 0) {
        sumA += a % 10;
        a /= 10;
    }
    while (b != 0) {
        sumB += b % 10;
        b /= 10;
    }

    if (sumA < sumB) {
        return 1;
    }
    else {
        return 0;
    }
}

// 2
int stringcmp(std::string a, std::string b)
{
    std::regex vowels("[aeiouAEIOU]");

    a = std::regex_replace(a, vowels, "");
    b = std::regex_replace(b, vowels, "");

    if (a < b) {
        return 1;
    }
    else {
        return 0;
    }
}

int main()
{
    // 3
    SkaiciuPalyginimas fnct;

    {
        std::cout << "Integer" << std::endl;
        /*vector<int>*/ victor<int> array;
        int input = 1;
        while (input != 0) {
            std::cout << "Input:";
            std::cin >> input;
            if (input != 0) {
                array.push_back(input);
            }
        }
        bubbleSort(array, fnct);

        for (iter<int> it = array.begin(); it != array.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    {
        std::cout << "String" << std::endl;
        /*vector<std::string>*/ victor<std::string> array;
        std::string input;
        while (input != "-") {
            std::cout << "Input:";
            std::cin >> input;
            if (input != "-") {
                array.push_back(input);
            }
        }
        bubbleSort(array, fnct);

        for (iter<std::string> it = array.begin(); it != array.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }


    return 0;
}
