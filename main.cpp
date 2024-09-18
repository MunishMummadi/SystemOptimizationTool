#include <iostream>
#include <vector>
#include <chrono>
#include <cstdlib>

// Mock memory allocation function for simulation
void memoryIntensiveTask() {
    const size_t size = 10000000;  // Simulate memory-intensive task
    int* arr = new int[size];
    
    for (size_t i = 0; i < size; ++i) {
        arr[i] = rand() % 100;  // Fill the array with random data
    }

    delete[] arr;
}

void optimizeMemoryUsage() {
    const size_t size = 10000000;
    std::vector<int> arr(size);  // Use vector for automatic memory management

    for (size_t i = 0; i < size; ++i) {
        arr[i] = rand() % 100;  // Fill the vector with random data
    }
}

void profileMemory(void (*func)()) {
    auto start = std::chrono::high_resolution_clock::now();
    func();  // Execute the function to profile
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Memory task took: " << elapsed.count() << " seconds." << std::endl;
}

int main() {
    std::cout << "Profiling memory-intensive task (manual allocation)..." << std::endl;
    profileMemory(memoryIntensiveTask);

    std::cout << "Optimizing memory usage using vector..." << std::endl;
    profileMemory(optimizeMemoryUsage);

    return 0;
}
