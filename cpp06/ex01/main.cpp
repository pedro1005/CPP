#include <iostream>
#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    // Create a Data object
    Data myData;
    myData.id = 42;
    myData.name = "Test Object";
    myData.value = 43;

    // Serialize the pointer to an integer
    uintptr_t ptr = Serializer::serialize(&myData);

    // Print the serialized integer value (address as number)
    std::cout << "Serialized ptr value: " << ptr << std::endl;

    // Deserialize it back to a Data*
    Data* deserializedPtr = Serializer::deserialize(ptr);

    // Print the deserialized pointer (should match &myData)
    std::cout << "Deserialized pointer: " << deserializedPtr << std::endl;
    std::cout << "Original pointer:     " << &myData << std::endl;

    // Test modifying the original object
    myData.id = 45;

    // Check if deserialized pointer equals original
    if (deserializedPtr == &myData) {
        std::cout << "✅ Success! Pointers match.\n";
        std::cout << "Deserialized Data content:\n";
        std::cout << "ID: " << deserializedPtr->id << "\n";
        std::cout << "Name: " << deserializedPtr->name << "\n";
        std::cout << "Value: " << deserializedPtr->value << "\n";
    } else {
        std::cout << "❌ Failure! Pointers don't match.\n";
    }

    return 0;
}

