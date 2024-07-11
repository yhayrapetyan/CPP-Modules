#include "Serializer.hpp"
#include "Data.hpp"

void test(Data *originalPtr) {
    std::cout << "Original Pointer:     " << originalPtr  << std::endl;

    uintptr_t serializedPtr = Serializer::serialize(originalPtr);
    std::cout  << "Serialized Pointer:   " << serializedPtr  << std::endl;

    Data *deserializedPtr = Serializer::deserialize(serializedPtr);
    std::cout << "Deserialized Pointer: " << deserializedPtr << std::endl;

    if (deserializedPtr == originalPtr)
        std::cout << "Serializer and deserializer successful!"  << std::endl;
    else
        std::cout << "Serializer and deserializer failed!"  << std::endl;
}

int main() {
    Data obj1;
    obj1.value = 42;

    Data obj2;
    obj2.value = 99;

    std::cout << "Testing Serializer and Deserializer"  << std::endl;
    std::cout << "---------------------------------------" << std::endl;

    std::cout  << "Test 1: Serialize and Deserialize obj1"  << std::endl;
    test(&obj1);
    std::cout << "---------------------------------------" << std::endl;

    std::cout << "Test 2: Serialize and Deserialize obj2"  << std::endl;
    test(&obj2);
    std::cout << "---------------------------------------" << std::endl;

    return 0;
}