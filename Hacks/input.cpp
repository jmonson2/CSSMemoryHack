#include "../Headers/input.hpp"

int input::select(memMod m){
    while(1){
        maindisplay();
        subdisplay(m);
    }
    
}

void input::maindisplay(){
    system("clear");
    std::cout << "1. Wireframe" << std::endl;
    std::cout << "2. Fog" << std::endl;
    std::cin >> selection;
}

void input::subdisplay(memMod m){
    system("clear");
    if(selection == 1){
        std::cout << "New Wireframe value: ";
        std::cin >> newval;
        m.setwireframe(newval);
        
    }
    else if(selection == 2){
        std::cout << "New Fog value: ";
        std::cin >> newval;
        m.setfogoverride(newval);
    }
}
