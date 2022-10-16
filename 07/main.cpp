#include <iostream>
#include <vector>
#include "vektorius.h"


// 2
template<typename T>
void bubbleSort(vektorius<T> &array)
{
    for (int i = 0; i < array.size() - 1; i++) {
        for (int j = 0; j < array.size() - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                std::swap(array[i], array[j]);
            }
        }
    }
}

int main()
{
//    {
//        // 1
//        std::vector<int> array;
//        int input = 1;
//        while (input)
//        {
//            std::cout << "Input:";
//            std::cin >> input;
//            if (input != 0)
//            {
//                array.push_back(input);
//            }
//        }
//        std::string input;
//        std::vector<std::string> array;
//        while (input != "-")
//        {
//            std::cout << "Input:";
//            std::cin >> input;
//            if (input != "-")
//            {
//                array.push_back(input);
//            }
//        }
//    }

    {
        // 3
        vektorius<std::string> array;
        std::string input;
        while (input != "-") {
            std::cout << "Input:";
            std::cin >> input;
            if (input != "-") {
                array.push_back(input);
            }
        }

        // 2
        bubbleSort(array);

        for (int i = 0; i < array.size(); i++) {
            std::cout << array[i] << " ";
        }
    }
    return 0;
}
