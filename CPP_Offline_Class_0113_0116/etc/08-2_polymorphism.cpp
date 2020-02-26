#include <iostream>

class AI
{
private:

public:
    // virtual void play()
    // {
    //     printf("call parent play() \n");
    // }

    virtual void play() = 0; //

};

class Alphago : public AI
{
private:

public:
    Alphago()
    {

    }

    void play() override
    {
        printf("call Alphago::play() \n");
    }
};

class Betago : public AI
{
private:

public:
    Betago()
    {

    }

    void play() override
    {
        printf("call Betago::play() \n");
    }
};

class Game
{
private:
    AI *p_;
public:
    Game(AI *p) : p_(p)
    {
        printf("Start Game with Alphago or Betago. \n");
    }

    void play()
    {
        p_->play();
    }
};

int main()
{
    Game b1(new Alphago); // Injection (DI : Defendence Injection)
    b1.play();

    Game b2(new Betago);
    b2.play();

    return 0;
}