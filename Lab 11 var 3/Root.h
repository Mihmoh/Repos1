#pragma once
#include "Plant.h"
namespace green
{
    class Root :
        public Plant
    {
    protected:
        int root_length;
    public:
        Root();
        Root(int root_length, int age, std::string name);
        ~Root();
        void setRoot_length(int root_length);
        int getRoot_length();
        void showRootInfo();
    };

}