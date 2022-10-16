// your are allowed to modify the code inside the class,
// you are NOT allowed to change anything outside of it

#include <algorithm>

class Object {
    class iter {
        int *arr;
        int current{};
    public:
        iter() = default;

        iter(int *arr, int current) : arr(arr), current(current) {};

        iter &operator++() {
            current++;
            return *this;
        }

        iter &operator+(int v) {
            current + v;
            return *this;
        }

        int &operator*() const {
            return arr[current];
        }

        int operator->() const {
            return arr[current];
        }

        bool operator<(const iter &b) {
            return &this->arr == &b.arr && this->current < b.current;
        };

        bool operator!=(const iter &b) {
            return &this->arr == &b.arr && this->current != b.current;
        };
    };

    int *arr{};
    int current = 0;
public:
    iter *Iterator;

    Object() {
        Iterator = new iter(arr, 0);
    }

    iter operator+(int v) {
        return *Iterator + v;
    }

    int *f() {
        return arr;
    }

    iter begin() {
        return {this->arr, 0};
    };

    iter end() {
        return {this->arr, current};
    }
};

template<typename Object>
void test() {
    Object o;
    std::transform(o, o + 5, o, &Object::f);
}

int main(int argc, char **argv) {
    test<Object>();
    return 0;
}

