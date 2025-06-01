#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"



int main() {
    // Create a Data object
    Data myData;
    myData.id = 42;
    myData.name = "Test Object";
    myData.value = 43;


    // Serialize the pointer
    uintptr_t ptr = Serializer::serialize(&myData);
    std::cout << std::hex << ptr << std::endl;
    // Deserialize back to pointer
    Data* deserializedPtr = Serializer::deserialize(ptr);

    std::cout << deserializedPtr << std::endl;

    // Check if deserialized pointer is equal to original
    if (deserializedPtr == &myData) {
        std::cout << "Success! Pointers match." << std::endl;
        std::cout << "Deserialized Data content:" << std::endl;
        std::cout << std::dec; // volta a formatação decimal
        std::cout << "ID: " << deserializedPtr->id << std::endl;
        std::cout << "Name: " << deserializedPtr->name << std::endl;
        std::cout << "Value: " << deserializedPtr->value << std::endl;
    } else {
        std::cout << "Failure! Pointers don't match." << std::endl;
    }

    return 0;
}
