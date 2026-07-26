#pragma once

class CustomVector {
private:
    int arr[4]; // Phase 1: static array of fixed size
    int current_size;

public:
    CustomVector();
    void add(int value);
    int get(int index) const;
    int size() const;
};