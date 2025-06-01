#include "Serializer.hpp"

Serializer::Serializer() {}
Serializer::Serializer(const Serializer&) {}
Serializer& Serializer::operator=(const Serializer&) { return *this; }
Serializer::~Serializer() {}

/**
 * @brief Converts a pointer to a uintptr_t integer representation.
 *
 * This function takes a pointer to a Data object and converts it into
 * an unsigned integer type (uintptr_t) capable of safely holding a
 * pointer value. This can be useful for storing or transmitting
 * pointer values as raw numbers.
 *
 * @param ptr Pointer to a Data object to serialize.
 * @return uintptr_t The raw integer representation of the pointer.
 */
uintptr_t Serializer::serialize(Data* ptr)
{
    // reinterpret_cast is used here for low-level, bitwise conversion
    // of the pointer value to an unsigned integer type.
    return reinterpret_cast<uintptr_t>(ptr);
}

/**
 * @brief Converts a uintptr_t integer back to a pointer to Data.
 *
 * This function takes a raw integer value (previously obtained from
 * serialize()) and converts it back into a pointer to a Data object.
 * It uses reinterpret_cast to safely reinterpret the bits of the
 * integer as a pointer.
 *
 * @param raw The raw integer representation of a pointer.
 * @return Data* The pointer reconstructed from the integer value.
 */
Data* Serializer::deserialize(uintptr_t raw)
{
    // reinterpret_cast is used here to convert the raw integer value
    // back into a pointer to a Data object.
    return reinterpret_cast<Data*>(raw);
}
