#pragma once
#include <iostream>
#include <initializer_list>
#include <vector>



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

    my_dynamic_array(size_t size_) {
        size = size_;
        capacity = size;
        data = new T[capacity];
    }
    my_dynamic_array(T init_value) {
        size = capacity;
        data = new T[capacity];
        for (int i = 0; i < capacity; i++) {
            data[i] = init_value;
        }
    }
    my_dynamic_array(size_t size_, T init_value) {
        size = size_;
        capacity = size;
        data = new T[capacity];
        for (size_t i = 0; i < size; i++) {
            data[i] = init_value;
        }
    }

    size_t get_size() const {
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

    my_dynamic_array(const std::vector<T>& v) {
        size_t n = v.size();
        data = new T[n];
        size = n;
        capacity = n;
        for (size_t i = 0; i < n; ++i) {
            data[i] = v[i];
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

template <typename T>
T* dynamic_array_to_static(my_dynamic_array<T>& array) {
    size_t n = array.get_size();
    T* static_array = new T[n];

    for (size_t i = 0; i < n; ++i) {
        static_array[i] = array[i];
    }

    return static_array;
}