#include <iostream>

class Animal
{
private:
    int num;
public:
    virtual void cry()
    {
        printf("cry! \n");
    }
};

class Dog : public Animal
{
public:
    void cry() override
    {
        printf("Dog cry! Mung!Mung! \n");
    }
};

class Cat : public Animal
{
public:
    void cry() override
    {
        printf("Cat cry! Yaong!Yaong! \n");
    }
};

class Snake : public Animal
{
public:
    // void cry() override
    // {
    //     printf("Cat cry! Yaong!Yaong! \n");
    // }
};

class Zoo
{
public:
    void sound(Animal* d)
    {
        d->cry();
        delete d;
    }

    // void sound(Dog* d)
    // {
    //     d->cry();
    //     delete d;
    // }

    // void sound(Cat* d)
    // {
    //     d->cry();
    //     delete d;
    // }
};

int main()
{
    Zoo zoo;
    zoo.sound(new Dog);
    zoo.sound(new Cat);
    zoo.sound(new Snake);

    // int num = 0;
    // Animal *ani;

    // switch(num)
    // {
    //     case 0:
    //         Animal *dog = new Dog;
    //         dog->cry();
    //         delete dog;
    //         break;
    //     case 1:
    //         Animal *cat = new Cat;
    //         cat->cry();
    //         delete cat;
    //         break;
    //     case 2:
    //         Animal *snake = new Snake;
    //         snake->cry();
    //         delete snake;
    //         break;

    // }

    Animal *animal[3] = {new Dog, new Cat, new Snake};
    for(int i = 0; i < 3; i ++)
    {
        animal[i]->cry();
    }

    return 0;
}