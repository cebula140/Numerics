#pragma once
#include <iostream>
#include <initializer_list>

template <typename T>
class my_dynamic_array {
private:
    T* data;
    size_t capacity = 2;
    size_t size = 0;

    void resize_arr() {
        if (size < capacity)
            return;

        capacity *= 2;

        T* new_data = new T[capacity];

        for (size_t i = 0; i < size; i++) {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
    }

public:
    my_dynamic_array() {
        data = new T[capacity];
    }

    size_t get_size() {
        return size;
    }

    my_dynamic_array(std::initializer_list<T> list) {
        size = list.size();
        capacity = (size > 2) ? size : 2;

        data = new T[capacity];

        size_t i = 0;
        for (const T& x : list) {
            data[i++] = x;
        }
    }

    my_dynamic_array(const my_dynamic_array& other) {
        size = other.size;
        capacity = other.capacity;

        data = new T[capacity];

        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    my_dynamic_array& operator=(const my_dynamic_array& other) {
        if (this == &other)
            return *this;

        delete[] data;

        size = other.size;
        capacity = other.capacity;

        data = new T[capacity];

        for (size_t i = 0; i < size; i++) {
            data[i] = other.data[i];
        }

        return *this;
    }

    void insert_back(const T& value) {
        resize_arr();
        data[size++] = value;
    }

    void delete_back() {
        if (size > 0)
            size--;
    }

    T& operator[](size_t index) {
        return data[index];
    }

    const T& operator[](size_t index) const {
        return data[index];
    }

    void print() const {
        std::cout << "{";

        for (size_t i = 0; i < size; i++) {
            std::cout << data[i];

            if (i + 1 < size)
                std::cout << ", ";
        }

        std::cout << "}";
    }

    ~my_dynamic_array() {
        delete[] data;
    }
};