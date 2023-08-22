//
//  Builder.cpp
//  MazeGame
//
//  Created by Nemanja Popovic on 3/7/2023.
//

#include "Builder.hpp"
#include "Cell.hpp"
#include <SDL2/SDL.h>
#include <string>
Builder::Builder(int aWindowX, int aWindowY, int aCellX, int aCellY) :
    fWidth(aWindowY/aCellY),
    fHeight(aWindowX/aCellX)
{}

void Builder::BuildCell(SDL_Surface* aSurface, Cell aCell, std::string Colour) {
    SDL_Rect cell;
    cell.x = aCell.Column() * fHeight;
    cell.y = aCell.Row() * fWidth;
    cell.w = fWidth;
    cell.h = fHeight;
    if(Colour == "W"){
        SDL_FillRect(aSurface, &cell, SDL_MapRGB(aSurface->format, 255, 255, 255));
    } else if(Colour == "R"){
        SDL_FillRect(aSurface, &cell, SDL_MapRGB(aSurface->format, 255, 0, 0));
    } else if(Colour == "B"){
        SDL_FillRect(aSurface, &cell, SDL_MapRGB(aSurface->format, 0, 0, 0));
    }

    if (aCell.fWalls.top) {
        SDL_Rect topWallRect = { cell.x, cell.y, cell.w, fHeight / 20 };
        if(Colour == "B"){
            SDL_FillRect(aSurface, &topWallRect, SDL_MapRGB(aSurface->format, 0, 255, 0));
        } else {
            SDL_FillRect(aSurface, &topWallRect, SDL_MapRGB(aSurface->format, 0, 0, 255));
        }
    }

    if (aCell.fWalls.left) {
        SDL_Rect leftWallRect = { cell.x, cell.y, fWidth / 20, cell.h };
        if(Colour == "B"){
            SDL_FillRect(aSurface, &leftWallRect, SDL_MapRGB(aSurface->format, 0, 255, 0));
        } else {
            SDL_FillRect(aSurface, &leftWallRect, SDL_MapRGB(aSurface->format, 0, 0, 255));
        }
    }

    if (aCell.fWalls.right) {
        SDL_Rect rightWallRect = { cell.x + cell.w - (fWidth / 20), cell.y, fWidth / 20, cell.h };
        if(Colour == "B"){
            SDL_FillRect(aSurface, &rightWallRect, SDL_MapRGB(aSurface->format, 0, 255, 0));
        } else {
            SDL_FillRect(aSurface, &rightWallRect, SDL_MapRGB(aSurface->format, 0, 0, 255));
        }
    }

    if (aCell.fWalls.bottom) {
        SDL_Rect bottomWallRect = { cell.x, cell.y + cell.h - (fHeight / 20), cell.w, fHeight / 20 };
        if(Colour == "B"){
            SDL_FillRect(aSurface, &bottomWallRect, SDL_MapRGB(aSurface->format, 0, 255, 0));
        } else {
            SDL_FillRect(aSurface, &bottomWallRect, SDL_MapRGB(aSurface->format, 0, 0, 255));
        }
    }
}

SDL_Rect Builder::GetCellRect(const Cell& cell) {
    SDL_Rect rect;
    rect.x = cell.Column() * fWidth;
    rect.y = cell.Row() * fHeight;
    rect.w = fWidth;
    rect.h = fHeight;
    return rect;
}

Builder::Builder():
fWidth(0),
fHeight(0)
{}

void Builder::BuildButton(SDL_Surface *aSurface, GUI button, std::string aColour){
    SDL_Rect Button;
    Button.x = button.X();
    Button.y = button.Y();
    Button.w = button.Width();
    Button.h = button.Height();
    if(aColour == "B"){
        SDL_FillRect(aSurface, &Button, SDL_MapRGB(aSurface->format, 0, 0, 255));
    }
    else {
        SDL_FillRect(aSurface, &Button, SDL_MapRGB(aSurface->format, 0, 0, 0));
    }
}

