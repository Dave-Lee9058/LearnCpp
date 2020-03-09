#include <iostream>
#include <vector>
#include <memory>

#if 1  // embrace_back

template <class T>
void printVector(const std::vector<T> &v)
{
    std::cout << "myvector contained : ";
    for(auto &x: v)
    {
        std::cout << x << " ";
    }
    std::cout << '\n';
}

class TestStub
{
private:
    int m_num;
public:
    TestStub(int num) : m_num(num) { std::cout << "Test Constructed. \n"; }

    TestStub() {std::cout << "Test Default Constructed. \n";} 

    TestStub(const TestStub &t) : m_num{t.m_num}
    {
        std::cout << "Test Copy Constructed. \n";
    }

    TestStub(TestStub &&t) : m_num{t.m_num}
    {
        std::cout << "Test Move Samantic Constructed. \n";
    }

    virtual ~TestStub() { std::cout << "Test Deployed. \n" << std::flush; }

    friend std::ostream& operator<< (std::ostream &out, const TestStub &ts)
    {
        out << "num : " << ts.m_num;
        return out;
    }
};

int main()
{
    // std::unique_ptr<TestStub> ts1 {std::make_unique<TestStub>(1)};
    // std::unique_ptr<TestStub> ts2 {std::make_unique<TestStub>(2)};
    // TestStub t1{1};
    // TestStub t2{2};
    

    std::vector<TestStub> v;

    std::cout << v.size() <<'\n' << std::flush;
    

    // v.push_back(t1);
    // v.push_back(t2);

    v.emplace_back(TestStub{1});
    v.emplace_back(TestStub{2});

    std::cout << v.size() <<'\n'<< std::flush;

    // v.emplace_back(*(ts1.release()));
    // v.emplace_back(*(ts2.release()));
    


    // std::vector<int> myvector = {10, 20, 30};

    // printVector(myvector);

    // myvector.emplace_back(100);
    // myvector.emplace_back(200);
    
    // printVector(myvector);

    // auto it = myvector.emplace(myvector.begin()+1, 500);
    // printVector(myvector);

    // myvector.emplace(it, 600);
    // printVector(myvector);

    // myvector.emplace(myvector.end(), 300);
    // printVector(myvector);


    return 0;
}

#endif


#if 0
int main()
{
    std::vector<int> v;
    std::vector<int> v1;

    std::cout << "vector size : " << v.size() << '\n';

    v.push_back(100);
    v.push_back(200);
    v.push_back(300);

    for(int i = 0; i < v.size(); ++i)
    {
        std::cout << v[i] << " ";  
    }

    std::cout << '\n';
    std::cout << "vector size : " << v.size() << '\n';

    v.clear();

    std::cout << "after clear, vector size : " << v.size() << '\n';

    v.push_back(100);
    v.push_back(200);

    v1 = v;

    std::cout << &v1 << " " << &v << '\n';
    std::cout << v1[0] << " " << v[0] << '\n';
 
    return 0;
}

#endif