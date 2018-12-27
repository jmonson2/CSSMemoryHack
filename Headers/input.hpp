#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "../Headers/memmod.hpp"

class input{
    public:
        int select(memMod);
        void maindisplay();
        void subdisplay(memMod);

        int newval;
        unsigned short int selection;
};