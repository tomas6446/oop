#ifndef VEKTORIUS_H
#define VEKTORIUS_H

template<class T>
class vektorius {
private:
    T *t;
    int current;
    int capacity;
public:
    vektorius()
    {
        this->t = new T[1];
        this->capacity = 1;
        this->current = 0;
    }

    vektorius(int capacity)
    {
        this->t = new T[capacity];
        this->capacity = capacity;
        this->current = 0;
    }

    ~vektorius()
    {
        delete[] this->t;
    }

    int size()
    {
        return this->capacity;
    }

    void push_back(T val)
    {
        if (this->current == this->capacity) {
            T *temp = new T[this->capacity + 5];

            for (int i = 0; i < this->capacity; ++i) {
                temp[i] = this->t[i];
            }

            delete[] this->t;
            this->capacity += 5;
            this->t = temp;
        }
        this->t[this->current] = val;
        this->current++;
    }


    T &operator[](int index)
    {
        if (index < 0 || index > this->capacity) {
            throw std::out_of_range("out of range exception");
        }
        return this->t[index];
    }
};

#endif
