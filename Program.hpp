//
//  Program.hpp
//  MazeGame
//
//  Created by Nemanja Popovic on 17/7/2023.
//

#ifndef Program_hpp
#define Program_hpp
#include "Maze.hpp"
#include "Builder.hpp"
#include <stdio.h>

class Program{
public:
    void Render(int size, Maze maze, SDL_Window* window, SDL_Surface* surface, Builder builder, int& playerposition, Cell& playerpos);
};
#endif /* Program_hpp */
