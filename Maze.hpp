//
//  Maze.hpp
//  MazeGame
//
//  Created by Nemanja Popovic on 1/7/2023.
//
#include "Cell.hpp"
#ifndef Maze_hpp
#define Maze_hpp

#include <stdio.h>
#include <set>
#include <stack>
#include <vector>

class Maze {
private:
    int fRow;
    int fCol;
    std::vector<Cell> grid;
    
    void GenerateMaze();
    Cell RandomNeighbour(std::stack<Cell>& Neighbours);
    std::stack<Cell> GetNeighbours(Cell& cell);
    void RemoveWall(Cell& Current, Cell& Random);
    bool IsCellVisited(const Cell& cell, std::stack<Cell>& Visited);
    void CleanUp();
public:
    Maze(int aRow, int aCol);
    int Size();
    void PrintMaze();
    Cell& Grid(int aIndex);
    int Row();
    int Column();
    void ResetVisited();
};

#endif /* Maze_hpp */
