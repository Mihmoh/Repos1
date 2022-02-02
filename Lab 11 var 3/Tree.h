#pragma once
#include "Stick.h"
namespace green
{
    class Tree :
        public Stick
    {
    private:
        double trunk;
    public:
        Tree();
        Tree(int root_length, int age, std::string name, string color, string taste, int stick_length, double trunk);
        ~Tree();
        void setTrunk_length(int trunk);
        double getTrunk_length();
        void showTrunkInfo();
        bool operator ==(const Tree other);
    };

}