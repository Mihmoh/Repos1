#pragma once
#include "Root.h"
#include "Leaf.h"
#include "Fruit.h"

namespace green
{
    class Stick :
        public Root, public Leaf, public Fruit
    {
    protected:
        int stick_length;
    public:
        Stick();
        Stick(int root_length, int age, std::string name, string color, string taste, int stick_length);
        ~Stick();
        void setStick_length(int stick_length);
        int getStick_length();
        void showStickInfo();
    };

}