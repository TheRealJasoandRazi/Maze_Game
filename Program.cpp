//
//  Program.cpp
//  MazeGame
//
//  Created by Nemanja Popovic on 17/7/2023.
//

#include "Program.hpp"
#include "Builder.hpp"
#include "Maze.hpp"
#include<SDL2/SDL.h>

void Program::Render(int size, Maze maze, SDL_Window* window, SDL_Surface* surface, Builder builder, int& playerposition, Cell& playerpos){
    SDL_DestroyWindow(window);
    window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 0x00, 0x00, 0x00, 0xFF));
    
    maze = Maze(size, size);
    builder = Builder(600, 600, size, size);
    for (int i = 0; i < maze.Size(); i++) {
        builder.BuildCell(surface, maze.Grid(i), "W");
    }

    int lastCellIndex = maze.Size() - 1;
    SDL_Rect lastCellRect = builder.GetCellRect(maze.Grid(lastCellIndex));
    SDL_FillRect(surface, &lastCellRect, SDL_MapRGB(surface->format, 0, 255, 0));

    SDL_Rect firstCellRect = builder.GetCellRect(maze.Grid(0));
    SDL_FillRect(surface, &firstCellRect, SDL_MapRGB(surface->format, 255, 0, 0));

    playerposition = 0;
    playerpos = maze.Grid(playerposition);
}
