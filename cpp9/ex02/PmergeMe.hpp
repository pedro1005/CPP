#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <set>
#include <string>
#include <iostream>
#include <stdexcept>
#include <sstream>
#include <algorithm>
#include <ctime>
#include <sys/time.h>
#include <climits>     // For INT_MAX
#include <cstdlib>     // For strtol, atoi
#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>   // For std::invalid_argument
#include <sys/time.h>  // For gettimeofday

class PmergeMe {
public:
    // Default constructor
    PmergeMe();
    // Copy constructor
    PmergeMe(const PmergeMe& other);
    // Copy assignment operator
    PmergeMe& operator=(const PmergeMe& other);
    // Destructor
    ~PmergeMe();
    static void sortAndMeasure(char** input, int count);
private:
    static void checkInput(char** input, int count);
    static std::vector<int> parseInput(char** input, int count);
    static void mergeInsertSort(std::vector<int>& arr, int left, int right);
    static void merge(std::vector<int>& arr, int left, int mid, int right);
    static void insertionSort(std::vector<int>& arr, int left, int right);

    static void mergeInsertSort(std::deque<int>& arr, int left, int right);
    static void merge(std::deque<int>& arr, int left, int mid, int right);
    static void insertionSort(std::deque<int>& arr, int left, int right);
};

#endif
