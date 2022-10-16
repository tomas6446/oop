#include <iostream>
#include <vector>
#include "vektorius.h"


// 2
template<class Iterator>
inline void bubbleSort(Iterator begin, Iterator end)
{
    for (Iterator i = begin; i != end; ++i) {
        for (Iterator j = begin; j < i; ++j) {
            if (*i < *j) {
                std::iter_swap(i, j);
            }
        }
    }
}

int main()
{
    // 1 sveiki skaiciai
    /*{

        std::vector<int> array;
        int input = 1;
        while (input != 0) {
            std::cout << "Input:";
            std::cin >> input;
            if (input != 0) {
                array.push_back(input);
            }
        }

        bubbleSort(array.begin(), array.end());

        std::vector<int>::iterator it;
        for (it = array.begin(); it != array.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }*/
    // 1 string
    /*{

        std::vector<std::string> array;
        std::string input;
        while (input != "-") {
            std::cout << "Input:";
            std::cin >> input;
            if (input != "-") {
                array.push_back(input);
            }
        }

        bubbleSort(array.begin(), array.end());

        std::vector<std::string>::iterator it;
        for (it = array.begin(); it != array.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }*/
    // 5
    {

        /*vector<int>*/ victor<int> array;
        int input = 1;
        while (input != 0) {
            std::cout << "Input:";
            std::cin >> input;
            if (input != 0) {
                array.push_back(input);
            }
        }

        bubbleSort(array.begin(), array.end());

        for (iter<int> it = array.begin(); it < array.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        for (iter<int> it = array.begin(); it != array.end(); ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

    }
    return 0;
}
