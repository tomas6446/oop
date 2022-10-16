#ifndef VEKTORIUS_H
#define VEKTORIUS_H

template<class T>
class iter;

template<class T>
class victor {
    friend class iter<T>;

    typedef iter<T> iterator;

private:
    T *array;
    int current{};
    int capacity{};
    int step = 5;

public:
    victor()
    {
        this->array = new T[1];
        this->capacity = 1;
        this->current = 0;
    }

    victor(int capacity)
    {
        this->array = new T[capacity];
        this->capacity = capacity;
        this->current = 0;
    }

    ~victor()
    {
        delete[] this->array;
        this->current = 0;
    }

    void push_back(T val)
    {
        if (this->current >= this->capacity) {
            T *temp = new T[this->capacity + this->step];

            for (int i = 0; i < this->capacity; ++i) {
                temp[i] = this->array[i];
            }

            delete[] this->array;
            this->capacity += this->step;
            this->array = temp;
        }
        this->array[this->current] = val;
        this->current++;
    }

    T &operator[](int index)
    {
        if (index < 0 || index > this->capacity) {
            throw std::out_of_range("out of range exception");
        }
        return this->array[index];
    }

    int size() { return this->current; }

    iterator begin()
    {
        return iterator(*this, 0);
    };

    iterator end()
    {
        return iterator(*this, current);
    }
};

template<class T>
class iter {
private:
    victor<T> &vect;
    int current{};
public:
    iter() = default;

    iter(victor<T> &p, int c) : vect(p), current(c) {}

    ~iter() = default;

    iter &operator++()
    {
        current++;
        return *this;
    }

    T &operator*() const { return vect.array[current]; }

    T *operator->() const { return vect.array[current]; }

    bool operator<(const iter &b)
    {
        return &this->vect == &b.vect && this->current < b.current;
    };

    bool operator!=(const iter &b)
    {
        return &this->vect == &b.vect && this->current != b.current;
    };
};


#endif
