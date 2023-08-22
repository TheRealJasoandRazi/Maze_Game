//
//  Solver.cpp
//  MazeGame
//
//  Created by Nemanja Popovic on 11/7/2023.
//

#include "Solver.hpp"
#include "Cell.hpp"
#include "Maze.hpp"
#include <stack>
#include <iostream>
#include <unordered_map>
#include <SDL2/SDL.h>
#include "Builder.hpp"
#include <chrono>
#include <thread>

std::vector<int> Solver::Solve(Maze& maze){
    std::queue<Cell> myQueue;
    std::unordered_map<int, int> parents;
    maze.ResetVisited();
    
    Cell start = maze.Grid(0);
    Cell target = maze.Grid(maze.Size()-1);
    int targetindex = GetIndex(target, maze);
    int startindex = GetIndex(start, maze);
    maze.Grid(startindex).Visited(true);
    
    myQueue.push(start);
       
    while (!myQueue.empty()) {
        Cell current = myQueue.front();
        myQueue.pop();
           
        if (current == target) {
            // Found the target, reconstruct the path
            std::vector<int> path;
            path.push_back(targetindex);
            
            while (path.back() != startindex) {
                int parent = parents[path.back()];
                path.push_back(parent);
            }
               
            std::reverse(path.begin(), path.end());
            return path;
        }
           
        // Explore neighboring cells
        std::stack<Cell> myStack = GetNeighbours(maze, current);
        while(!myStack.empty()){
            Cell neighbour = myStack.top();
            myStack.pop();
            if(neighbour.Visited() == false){
                myQueue.push(neighbour);
                int neighbourindex = GetIndex(neighbour, maze);
                maze.Grid(neighbourindex).Visited(true);
                parents[neighbourindex] = GetIndex(current, maze);
            }
        }
    }
       
    // No path found
    return std::vector<int>();
}

std::stack<Cell> Solver::GetNeighbours(Maze& maze, Cell cell){
    std::stack<Cell> Neighbours;
    int currentindex = ((maze.Column() * cell.Row()) + cell.Column());
    int indexright = currentindex + 1;
    int indexleft = currentindex - 1;
    int indexdown = currentindex + maze.Column();
    int indexup = currentindex - maze.Column();
    if (cell.Row() > 0) {
        if(cell.fWalls.top == false && maze.Grid(indexup).fWalls.bottom == false){
            Neighbours.push(maze.Grid(indexup));
        }
    }
    if (cell.Column() > 0) {
        if(cell.fWalls.left == false && maze.Grid(indexleft).fWalls.right == false){
            Neighbours.push(maze.Grid(indexleft));
        }
    }
    if (cell.Row() < maze.Row() - 1) {
        if(cell.fWalls.bottom == false && maze.Grid(indexdown).fWalls.top == false){
            Neighbours.push(maze.Grid(indexdown));
        }
    }
    if (cell.Column() < maze.Column() - 1) {
        if(cell.fWalls.right == false && maze.Grid(indexright).fWalls.left == false){
            Neighbours.push(maze.Grid(indexright));
        }
    }
    return Neighbours;
}

int Solver::GetIndex(Cell Current, Maze maze){
    return (maze.Column() * Current.Row() + Current.Column());
}

void Solver::OutputSolution(std::vector<int> Solution, Maze maze, Builder builder, SDL_Surface* aSurface, SDL_Window* window){
    for (int i = 0; i < Solution.size(); i++) {
        builder.BuildCell(aSurface, maze.Grid(Solution[i]), "R");
        
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
        SDL_UpdateWindowSurface(window);
    }
}
