#include <iostream>
#include <tuple>

#if 1

class CounterSnapShot
{
public:

    /**
     * Constructs the Counter SnapShot
     */
    CounterSnapShot(const int & value, const int & units) : value_(value), units_(units) { };

    /**
     * Returns the current counter value
     */
    const int & getValue() const { return value_; }

    /**
     * Returns the units of the Value
     */
    const int & getUnits() const { return units_; }

    friend std::ostream& operator<<(std::ostream &out, CounterSnapShot &css)
    {
        out << "value : " << css.value_ << " units : " << css.units_; 
        return out;
    }

    friend CounterSnapShot& operator=(CounterSnapShot &css)
    {
        
    }

private:
    int value_;
    int units_;
};

int main()
{
    CounterSnapShot css{1,2};
    std::tuple<int, CounterSnapShot>  foo {1, css};

    // CounterSnapShot css1 = std::get<1>(css);

    std::cout <<  css << '\n';

    int v1 = 0;
    CounterSnapShot c1{0,0};

    std::tie<v1, c1> = foo;

    std::cout << v1 << " " << c1 << '\n';

    return 0;
}

#endif

#if 0
int main()
{
    std::tuple<int, char> foo {10, 'x'};
    std::cout << "foo contains : " << std::get<0>(foo) << " " << std::get<1>(foo) << "\n";

    auto bar = std::make_tuple("test", 3.1, 14, 'y');
    printf("1 bar contains : %s, %.2f, %d, %d \n", std::get<0>(bar), std::get<1>(bar),std::get<2>(bar),std::get<3>(bar));

    std::get<2>(bar) = 100;
    printf("2 bar contains : %s, %.2f, %d, %d \n", std::get<0>(bar), std::get<1>(bar),std::get<2>(bar),std::get<3>(bar));

    int myint;
    char mychar;

    printf("before tie : %d, %c \n", myint, mychar);
    std::tie(myint, mychar) = foo;
    printf("after tie : %d, %c \n", myint, mychar);

    std::tie(std::ignore, std::ignore, myint, mychar) = bar;
    printf("after tie from bar : %d, %c \n", myint, mychar);

    mychar = std::get<3>(bar);
    printf("mychar : %c \n", mychar);

    std::get<0>(foo) = std::get<2>(bar);
    std::get<1>(foo) = mychar;

    std::cout << "final foo contains : " << std::get<0>(foo) << " " << std::get<1>(foo) << "\n";
    
    return 0;
}
#endif