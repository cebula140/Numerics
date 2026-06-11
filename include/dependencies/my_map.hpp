#pragma once
#include <dependencies/my_dynamic_array.hpp>
#include <string>
#include <iostream>

using namespace std;

// open-addressing slot states
enum State {
    EMPTY,
    OCCUPIED,
    DELETED
};

size_t my_hash(const string& input) {
    if (input.empty()) return 0;

    size_t hash = 0;
    for (unsigned char c : input) {
        hash = hash * 131 + c;
    }

    // splitmix64-style avalanche: mix bits so similar keys scatter well
    hash ^= hash >> 30;
    hash *= 0xbf58476d1ce4e5b9ULL;
    hash ^= hash >> 27;
    hash *= 0x94d049bb133111ebULL;
    hash ^= hash >> 31;

    return hash;
}

const double _capacity_factor = 2;


template <typename T>
class my_map {
private:
    struct Slot {
        std::string key;
        T value{};
        State state = EMPTY;
    };

    my_dynamic_array<Slot> data;
    size_t capacity = 256;
    size_t m_size = 0;

    size_t idx(const std::string& key) const {
        return my_hash(key) % capacity;
    }

    double load_factor() const {
        return (double)(m_size + 1) / capacity;
    }

    // double the table and re-insert all occupied slots
    void rehash() {
        my_dynamic_array<Slot> old = data;

        capacity *= _capacity_factor;
        data = my_dynamic_array<Slot>();
        for (size_t i = 0; i < capacity; i++) {
            data.insert_back(Slot{});
        }

        m_size = 0;

        for (size_t i = 0; i < old.get_size(); i++) {
            if (old[i].state == OCCUPIED) {
                insert_slot(old[i].key, old[i].value);
            }
        }
    }

    void maybe_reget_size() {
        if (load_factor() > 0.75) {
            rehash();
        }
    }

public:
    my_map() {
        for (size_t i = 0; i < capacity; i++) {
            data.insert_back(Slot{});
        }
    }

    // linear probing: insert into first empty or deleted slot
    void insert_slot(const std::string& key, const T& value) {
        maybe_reget_size();

        size_t i = idx(key);
        size_t start = i;

        do {
            if (data[i].state == EMPTY || data[i].state == DELETED) {
                data[i].key = key;
                data[i].value = value;
                data[i].state = OCCUPIED;

                m_size++;
                return;
            }

            if (data[i].state == OCCUPIED && data[i].key == key) {
                data[i].value = value;
                return;
            }

            i = (i + 1) % capacity;

        } while (i != start);
    }

    // linear probing: stop at first empty slot (key not found)
    T* find(const std::string& key) {
        size_t i = idx(key);
        size_t start = i;

        do {
            if (data[i].state == EMPTY)
                return nullptr;

            if (data[i].state == OCCUPIED && data[i].key == key)
                return &data[i].value;

            i = (i + 1) % capacity;

        } while (i != start);

        return nullptr;
    }

    T& operator[](const std::string& key) {
        size_t i = idx(key);
        size_t start = i;

        do {
            if (data[i].state == OCCUPIED && data[i].key == key)
                return data[i].value;

            if (data[i].state == EMPTY || data[i].state == DELETED) {
                maybe_reget_size();

                data[i].key = key;
                data[i].value = T{};
                data[i].state = OCCUPIED;

                m_size++;
                return data[i].value;
            }

            i = (i + 1) % capacity;

        } while (i != start);

        throw std::runtime_error("map full");
    }

    // mark slot as DELETED so linear probing stays intact
    void delete_slot(const std::string& key) {
        size_t i = idx(key);
        size_t start = i;

        do {
            if (data[i].state == EMPTY)
                return;

            if (data[i].state == OCCUPIED && data[i].key == key) {
                data[i].state = DELETED;
                m_size--;
                return;
            }

            i = (i + 1) % capacity;

        } while (i != start);
    }
};