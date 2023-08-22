//
//  GUI.cpp
//  MazeGame
//
//  Created by Nemanja Popovic on 17/7/2023.
//

#include "GUI.hpp"
#include <SDL2/SDL_ttf.h>
#include <iostream>

GUI::GUI(int aX, int aY) :
    fX(aX),
    fY(aY),
    fWidth(50),
    fHeight(20)
{

}

GUI::GUI(int aX, int aY, int aWidth, int aHeight):
    fX(aX),
    fY(aY),
    fWidth(aWidth),
    fHeight(aHeight)
{}

bool GUI::IfPressed(){
    int mouseX, mouseY;
    SDL_GetMouseState(&mouseX, &mouseY);
    return (mouseX >= this->X() && mouseX <= this->X() + this->Width() &&
            mouseY >= this->Y() && mouseY <= this->Y() + this->Height());
}

void GUI::PrintText(SDL_Surface* surface, std::string aText) {
    if (TTF_Init() < 0) {
        std::cerr << "Failed to initialize SDL_ttf: " << TTF_GetError() << std::endl;
        return;
    }

    TTF_Font* font = TTF_OpenFont("/Library/Fonts/Arial Unicode.ttf", 16);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        TTF_Quit(); // Cleanup SDL_ttf before returning
        return;
    }

    SDL_Color text_color = { 255, 255, 255 };
    SDL_Surface* text_surface = TTF_RenderText_Solid(font, aText.c_str(), text_color);

    SDL_Rect text_rect;
    text_rect.x = this->X();
    text_rect.y = this->Y();
    text_rect.w = this->Width();
    text_rect.h = this->Height();

    SDL_BlitSurface(text_surface, NULL, surface, &text_rect);
    SDL_FreeSurface(text_surface);

    TTF_CloseFont(font);
    TTF_Quit(); // Cleanup SDL_ttf
}



int GUI::Width(){
    return fWidth;
}
int GUI::Height(){
    return fHeight;
}
int GUI::X(){
    return fX;
}
int GUI::Y(){
    return fY;
}
    
