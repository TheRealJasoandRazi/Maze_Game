//
//  GUI.hpp
//  MazeGame
//
//  Created by Nemanja Popovic on 17/7/2023.
//

#ifndef GUI_hpp
#define GUI_hpp

#include <stdio.h>
#include <SDL2/SDL.h>
#include <string>

class GUI{
private:
    int fWidth;
    int fHeight;
    int fX;
    int fY;
public:
    GUI(int aX, int aY);
    GUI(int aX, int aY, int aWidth, int aHeight);
    bool IfPressed();
    void PrintText(SDL_Surface* surface, std::string aText);
    int Width();
    int Height();
    int X();
    int Y();
};
#endif /* GUI_hpp */
