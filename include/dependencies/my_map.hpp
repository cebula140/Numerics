#include <vector>
#include <string>
#include <iostream>

using namespace std;

enum State {
    EMPTY,
    OCCUPIED,
    DELETED
};

struct Slot {
    string key;
    double value;
    State state = EMPTY;
};

size_t my_hash(const string& input) {
    if (input.empty()) return 0;

    size_t hash = 0;
    for (unsigned char c : input) {
        hash = hash * 131 + c;
    }

    hash ^= hash >> 30;
    hash *= 0xbf58476d1ce4e5b9ULL;
    hash ^= hash >> 27;
    hash *= 0x94d049bb133111ebULL;
    hash ^= hash >> 31;

    return hash;
}

class my_map {
private:
    vector<Slot> data;
    size_t capacity = 256;
    size_t size = 0;

    size_t idx(const string& key) {
        return my_hash(key) % capacity;
    }

    void resize_map() {
        if ((double)(size + 1) / capacity < 0.75) return;

        vector<Slot> old = data;

        capacity *= 2;
        data.clear();
        data.resize(capacity);
        size = 0;

        for (auto& s : old) {
            if (s.state == OCCUPIED) {
                insert_slot(s.key, s.value);
            }
        }
    }

public:
    my_map() {
        data.resize(capacity);
    }

    void insert_slot(const string& key, double value) {
        size_t start = idx(key);
        size_t i = start;

        do {
            if (data[i].state == EMPTY || data[i].state == DELETED) {
                data[i].key = key;
                data[i].value = value;
                data[i].state = OCCUPIED;

                size++;
                resize_map();
                return;
            }

            if (data[i].state == OCCUPIED && data[i].key == key) {
                data[i].value = value;
                return;
            }

            i = (i + 1) % capacity;

        } while (i != start);
    }

    double* find(const string& key) {
        size_t start = idx(key);
        size_t i = start;

        do {
            if (data[i].state == EMPTY)
                return nullptr;

            if (data[i].state == OCCUPIED && data[i].key == key)
                return &data[i].value;

            i = (i + 1) % capacity;

        } while (i != start);

        return nullptr;
    }

    double& operator[](const string& key) {
        size_t start = idx(key);
        size_t i = start;

        do {
            if (data[i].state == OCCUPIED && data[i].key == key)
                return data[i].value;

            if (data[i].state == EMPTY || data[i].state == DELETED) {
                data[i].key = key;
                data[i].value = 0;
                data[i].state = OCCUPIED;

                size++;
                resize_map();

                return data[i].value;
            }

            i = (i + 1) % capacity;

        } while (i != start);

        throw runtime_error("my_map full");
    }

    void delete_slot(const string& key) {
        size_t start = idx(key);
        size_t i = start;

        do {
            if (data[i].state == EMPTY)
                return;

            if (data[i].state == OCCUPIED && data[i].key == key) {
                data[i].key = "";
                data[i].value = 0;
                data[i].state = DELETED;
                return;
            }

            i = (i + 1) % capacity;

        } while (i != start);
    }
};
