#include <iostream>
#include <chrono>

#if 1

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1>>;

    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg{clock_t::now()} {}

    void reset() 
    {
        m_beg = clock_t::now();
    }

    double elapsed() const 
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};

template <class T>
class DynamicArray
{
private:
    T *m_array;
    int m_length;

public:
    DynamicArray(int length) : m_array { new T[length]}, m_length{length} { }

    ~DynamicArray() { delete[] m_array; }

    // Copy Constructor
    // DynamicArray(const DynamicArray &arr) : m_length{arr.m_length} 
    // {
    //     m_array = new T[m_length];
    //     for(int i = 0; i < m_length; ++i)
    //     {
    //         m_array[i] = arr.m_array[i];
    //     }
    // }
    
    DynamicArray(const DynamicArray &arr) = delete;

    // Copy Assignment
    // DynamicArray& operator=(const DynamicArray &arr)
    // {
    //     if(&arr == nullptr)
    //     {
    //         return *this;
    //     }

    //     delete[] m_array;

    //     m_length = arr.m_length;
    //     m_array = new T[m_length];

    //     for(int i = 0; i < m_length; i++)
    //     {
    //         m_array[i] = arr.m_array[i];
    //     }

    //     return *this;
    // }

    DynamicArray& operator=(const DynamicArray &arr) = delete;

    // Move Constructor
    DynamicArray(DynamicArray &&arr) : m_length{arr.m_length}, m_array{arr.m_array}
    {
        arr.m_length = 0;
        arr.m_array = nullptr;
    }

    // Move Assignment
    DynamicArray& operator=(DynamicArray &&arr) 
    {
        if(&arr == nullptr)
        {
            return *this;
        }

        delete[] m_array;

        m_length = arr.m_length;
        m_array = arr.m_array;

        arr.m_length = 0;
        arr.m_array = nullptr;

        return *this;
    }


    int getLength() const { return m_length; }
    T& operator[](int index) { return m_array[index]; }
    const T& operator[] (int index) const { return m_array[index]; }
};

DynamicArray<int> cloneArrayAndDouble(const DynamicArray<int> &arr)
{
    DynamicArray<int> dbl(arr.getLength());
    for(int i = 0; i < arr.getLength(); ++i)
    {
        dbl[i] = arr[i] * 2;
    }

    return dbl;
}

int main()
{
    Timer t;

    DynamicArray<int> arr(10000000);

    for(int i = 0; i < arr.getLength(); ++i)
    {
        arr[i] = i;
    }

    arr = cloneArrayAndDouble(arr);

    std::cout << t.elapsed() << '\n';

    return 0;
}

#endif


#if 0
// Move Constructor and Move Assignment

template<class T>
class Auto_ptr3
{
private:
    T *m_ptr;
public:
    Auto_ptr3(T *ptr = nullptr) : m_ptr{ptr} {}

    ~Auto_ptr3() 
    {
        delete m_ptr;
    }

	// Copy constructor
	// Do deep copy of a.m_ptr to m_ptr
    // Auto_ptr3(const Auto_ptr3 &a)
    // {
    //     m_ptr = new T;
    //     *m_ptr = *a.m_ptr;
    // }

    // no copying allowed.
    Auto_ptr3(const Auto_ptr3 &a) = delete;

    // Move constructor
    // Transfer ownership of a.m_ptr to m_ptr
    Auto_ptr3(Auto_ptr3 &&a) : m_ptr(a.m_ptr)
    {
        a.m_ptr = nullptr;
    }

    // Copy assignment
	// Do deep copy of a.m_ptr to m_ptr
    // Auto_ptr3& operator=(const Auto_ptr3 &a)
    // {
    //     if(&a == nullptr)
    //     {
    //         return *this;
    //     }

    //     delete m_ptr;

    //     m_ptr = new T;
    //     *m_ptr = *a.m_ptr;

    //     return *this;
    // }

    // Copy Assignment - no copying allowed!
    Auto_ptr3& operator= (const Auto_ptr3 &a) = delete;

    // Move assignment
    // Transfer ownership of a.m_ptr to m_ptr
    Auto_ptr3& operator=(Auto_ptr3 &&a)
    {
        if(&a == this)
            return *this;

        delete m_ptr;

        m_ptr = a.m_ptr;
        a.m_ptr = nullptr;

        return *this;
    }


    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
private:
public:
    Resource() { std::cout << "Resource Acquired! \n"; }
    ~Resource() { std::cout << "Resource Deployed! \n"; }
};

Auto_ptr3<Resource> generatorResource()
{
    Auto_ptr3<Resource> res(new Resource);
    return res; // this return value will invoke  the move constructor.
}

int main()
{
    Auto_ptr3<Resource> mainres;
    mainres = generatorResource();

    return 0;
}


#endif

#if 0

// Copy Consturctor and Copy assignment
template<class T>
class Auto_ptr3
{
private:
    T *m_ptr;
public:
    Auto_ptr3(T *ptr = nullptr) : m_ptr{ptr} {}

    ~Auto_ptr3() 
    {
        delete m_ptr;
    }

    Auto_ptr3(const Auto_ptr3 &a)
    {
        m_ptr = new T;
        *m_ptr = *a.m_ptr;
    }

    Auto_ptr3& operator=(const Auto_ptr3 &a)
    {
        if(&a == nullptr)
        {
            return *this;
        }

        delete m_ptr;

        m_ptr = new T;
        *m_ptr = *a.m_ptr;

        return *this;
    }

    T& operator*() const { return *m_ptr; }
    T* operator->() const { return m_ptr; }
    bool isNull() const { return m_ptr == nullptr; }
};

class Resource
{
private:
public:
    Resource() { std::cout << "Resource Acquired! \n"; }
    ~Resource() { std::cout << "Resource Deployed! \n"; }
};

Auto_ptr3<Resource> generatorResource()
{
    Auto_ptr3<Resource> res(new Resource);
    return res;
}

int main()
{
    Auto_ptr3<Resource> mainres;
    mainres = generatorResource();

    return 0;
}

#endif