#include <iostream>
#include <vector>
#include <string>

const int MAX_SIZE = 100; // maximum array size

void bubbleSortArray(int array[], int size) // BubbleSort for integer array
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                // swap
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void bubbleSortInt(std::vector<int> &array) // BubbleSort for integer vector
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[i] > array[j])
            {
                // swap
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void bubbleSortString(std::vector<std::string> &array) // BubbleSort for string vector
{
    for (int i = 0; i < array.size(); i++)
    {
        for (int j = i + 1; j < array.size(); j++)
        {
            if (array[i] > array[j])
            {
                // swap
                std::string temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main()
{
    // 2 uzd
    //_________________________________
    int array[MAX_SIZE];
    int size = 0, input = 1;

    while (input)
    {
        std::cout << "Input:";
        std::cin >> input;
        if (input != 0)
        {
            array[size++] = input;
        }
    }
    // 3 uzd
    bubbleSortArray(array, size);

    for (int x = 0; x < size; x++)
    {
        std::cout << array[x] << " ";
    }
    //_________________________________


//    // 4 uzd
//    //_________________________________
//    std::vector<int> array;
//    int input = 1;
//    while (input)
//    {
//        std::cout << "Input:";
//        std::cin >> input;
//        if (input != 0)
//        {
//            array.push_back(input);
//        }
//    }
//    bubbleSortInt(array);
//    for (auto &i: array)
//    {
//        std::cout << i << " ";
//    }
//    //_________________________________


//    // 5 uzd
//    //_________________________________
//    std::string input = "";
//    std::vector<std::string> array;
//
//    while (input != "-")
//    {
//        std::cout << "Input:";
//        std::cin >> input;
//        if (input != "-")
//        {
//            array.push_back(input);
//        }
//    }
//    bubbleSortString(array);
//
//    for (auto &i: array)
//    {
//        std::cout << i << std::endl;
//    }
//    //_________________________________

    return 0;
}
