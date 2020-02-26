#include <iostream>

using namespace std;

template<typename T = int, int Tcap = 100>
class Array
{
private:
    T *buf;
    int size;
    int capacity;
public:
    explicit Array(int cap = 100) : buf(0), size(0), capacity(Tcap) 
    {
        buf = new T[capacity];
    }

    ~Array()
    {
        delete[] buf;
    }

    void add(T add)
    {
        buf[size++] = add;
    }

    T operator[] (int idx)
    {
        return buf[idx];
    }

    int getSize() const
    {
        return size;
    }

    void print() const
    {
        for(int i = 0; i < size; i++)
        {
            std::cout << buf[i] << " ";
        }
        std::cout << '\n';
    }
};

int main()
{
    Array<int> arrs;
    Array<int, 200> arrs1;
    Array<> arrs2;
    arrs2.add(10);
    arrs2.add(20);
    arrs2.add(30);
    arrs2.print();
    return 0;
}