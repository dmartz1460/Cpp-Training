#include "CustomVector.h"
#include <stdexcept>

CustomVector::CustomVector() : current_size(0) {}

void CustomVector::add(int value) {
    if (current_size < 10) {
        arr[current_size] = value;
        current_size++;
    }
}

int CustomVector::get(int index) const {
    if (index >= 0 && index < current_size) {
        return arr[index];
    }
    throw std::out_of_range("Index out of bounds");
}

int CustomVector::size() const {
    return current_size;
}