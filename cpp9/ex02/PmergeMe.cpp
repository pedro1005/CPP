#include "PmergeMe.hpp"
#include <climits>     // For INT_MAX
#include <cstdlib>     // For strtol, atoi
#include <vector>
#include <deque>
#include <iostream>
#include <stdexcept>   // For std::invalid_argument
#include <sys/time.h>  // For gettimeofday
#include <iomanip> // for std::setprecision and std::fixed

// Default constructor
PmergeMe::PmergeMe() {}

// Copy constructor
PmergeMe::PmergeMe(const PmergeMe& other) {(void)other;}

// Copy assignment operator
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return *this;
}

// Destructor
PmergeMe::~PmergeMe() {}

void PmergeMe::checkInput(char** input, int count) {
    std::vector<int> seen;

    for (int i = 1; i < count; ++i) {
        std::string s = input[i];

        // Empty check
        if (s.empty())
            throw std::invalid_argument("Error");

        // Digit-only check
        for (size_t j = 0; j < s.length(); ++j) {
            if (!std::isdigit(s[j]))
                throw std::invalid_argument("Error");
        }

        // Range check
        long val = std::strtol(s.c_str(), NULL, 10);
        if (val < 0 || val > INT_MAX)
            throw std::out_of_range("Error");

        // Duplicate check
        for (size_t j = 0; j < seen.size(); ++j) {
            if (seen[j] == static_cast<int>(val))
                throw std::invalid_argument("Error");
        }

        seen.push_back(static_cast<int>(val));
    }
}


std::vector<int> PmergeMe::parseInput(char** input, int count) {
    std::vector<int> result;

    for (int i = 1; i < count; ++i) {
        long val = std::strtol(input[i], NULL, 10);
        result.push_back(static_cast<int>(val));
    }

    return result;
}


void PmergeMe::insertionSort(std::vector<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::merge(std::vector<int>& arr, int left, int mid, int right) {
    std::vector<int> L(arr.begin() + left, arr.begin() + mid + 1);
    std::vector<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < (int)L.size() && j < (int)R.size())
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < (int)L.size()) arr[k++] = L[i++];
    while (j < (int)R.size()) arr[k++] = R[j++];
}

void PmergeMe::mergeInsertSort(std::vector<int>& arr, int left, int right) {
    if (right - left <= 16)
        insertionSort(arr, left, right);
    else {
        int mid = (left + right) / 2;
        mergeInsertSort(arr, left, mid);
        mergeInsertSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// For deque
void PmergeMe::insertionSort(std::deque<int>& arr, int left, int right) {
    for (int i = left + 1; i <= right; ++i) {
        int key = arr[i];
        int j = i - 1;
        while (j >= left && arr[j] > key) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
    }
}

void PmergeMe::merge(std::deque<int>& arr, int left, int mid, int right) {
    std::deque<int> L(arr.begin() + left, arr.begin() + mid + 1);
    std::deque<int> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0, j = 0, k = left;
    while (i < (int)L.size() && j < (int)R.size())
        arr[k++] = (L[i] <= R[j]) ? L[i++] : R[j++];
    while (i < (int)L.size()) arr[k++] = L[i++];
    while (j < (int)R.size()) arr[k++] = R[j++];
}

void PmergeMe::mergeInsertSort(std::deque<int>& arr, int left, int right) {
    if (right - left <= 16)
        insertionSort(arr, left, right);
    else {
        int mid = (left + right) / 2;
        mergeInsertSort(arr, left, mid);
        mergeInsertSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

#include <ctime>  // For clock_gettime

double getTimeUs() {
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    return ts.tv_sec * 1e6 + ts.tv_nsec / 1e3;
}
/*
std::vector stores data contiguously in memory — so cache-friendly, faster random access, and generally better for algorithms like merge-insert sort.
std::deque uses segmented memory blocks — so more pointer indirections, less cache-friendly, and that overhead adds up with large data.*/
void PmergeMe::sortAndMeasure(char** input, int count) {
    double start, end;

    start = getTimeUs();
    checkInput(input, count);
    std::vector<int> vec = parseInput(input, count);
    end = getTimeUs();
    double parseTime = end - start;

    // Print "Before"
    std::cout << "Before:";
    for (int i = 1; i < count && i < 11; ++i)
        std::cout << " " << input[i];
    if (count > 10)
        std::cout << " [...]";
    std::cout << std::endl;

    // Prepare deque from vector
    std::deque<int> deq(vec.begin(), vec.end());

    // Sort vector
    start = getTimeUs();
    mergeInsertSort(vec, 0, static_cast<int>(vec.size()) - 1);
    end = getTimeUs();
    double vecSortTime = end - start;

    // Print "After"
    std::cout << "After:";
    for (size_t i = 0; i < vec.size() && i < 10; ++i)
        std::cout << " " << vec[i];
    if (vec.size() > 10)
        std::cout << " [...]";
    std::cout << std::endl;

    // Sort deque
    start = getTimeUs();
    mergeInsertSort(deq, 0, static_cast<int>(deq.size()) - 1);
    end = getTimeUs();
    double deqSortTime = end - start;

    // Print timings
    std::cout << std::fixed << std::setprecision(6);
    std::cout << "Parsing time: " << parseTime << " us" << std::endl;
    std::cout << "Sorting time " << vec.size() << " elements with std::vector: " << vecSortTime << " us" << std::endl;
    std::cout << "Sorting time " << deq.size() << " elements with std::deque:  " << deqSortTime << " us" << std::endl;
}

