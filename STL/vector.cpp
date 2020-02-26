#include <iostream>
#include <vector>

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