//
//  Cell.hpp
//  MazeGame
//
//  Created by Nemanja Popovic on 1/7/2023.
//
#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
#include "Wall.hpp"

class Cell {
private:
    int fRow;
    int fCol;
    bool fVisited;
    
public:
    Wall::Walls fWalls;
    bool Visited();
    void Visited(bool aState);
    Cell(int aRow, int aCol);
    void UpdateWall(bool aWall);
    int Row() const;
    int Column() const;
    bool operator==(const Cell& aOther) const;
    bool operator<(const Cell& aOther) const;
};
#endif /* Cell_hpp */
