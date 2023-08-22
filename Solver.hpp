//
//  Solver.hpp
//  MazeGame
//
//  Created by Nemanja Popovic on 11/7/2023.
//

#ifndef Solver_hpp
#define Solver_hpp

#include <stdio.h>
#include "Cell.hpp"
#include "Maze.hpp"
#include <queue>
#include <stack>
#include "Builder.hpp"
#include <SDL2/SDL.h>


class Solver{
private:
    std::queue<Cell> Queue;
    
    std::stack<Cell> GetNeighbours(Maze& maze, Cell cell);
    int GetIndex(Cell Current, Maze maze);
public:
    std::vector<int> Solve(Maze& maze);
    void OutputSolution(std::vector<int> Solution, Maze maze, Builder builder, SDL_Surface* aSurface, SDL_Window* window);
};
#endif /* Solver_hpp */
