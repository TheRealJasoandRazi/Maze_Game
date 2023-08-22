//
//  Builder.hpp
//  MazeGame
//
//  Created by Nemanja Popovic on 3/7/2023.
//

#ifndef Builder_hpp
#define Builder_hpp
#include <SDL2/SDL.h>
#include "Cell.hpp"
#include <stdio.h>
#include <string>
#include "GUI.hpp"

class Builder{
private:
    int fWidth;
    int fHeight;
public:
    Builder(int aWindowX, int aWindowY, int aCellX, int aCellY);
    void BuildCell(SDL_Surface* aSurface, Cell aCell, std::string Colour);
    SDL_Rect GetCellRect(const Cell& cell);
    Builder();
    void BuildButton(SDL_Surface* aSurface, GUI button, std::string aColour);
};
#endif /* Builder_hpp */
