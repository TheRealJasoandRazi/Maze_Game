//
//  Cell.cpp
//  MazeGame
//
//  Created by Nemanja Popovic on 1/7/2023.
//
#include "Cell.hpp"

Cell::Cell(int aRow, int aCol) :
    fRow(aRow),
    fCol(aCol),
    fVisited(false)
{
    fWalls.top = true;
    fWalls.left = true;
    fWalls.right = true;
    fWalls.bottom = true;
}
bool Cell::Visited(){
    return fVisited;
}

void Cell::Visited(bool aState){
    fVisited = aState;
}

int Cell::Row() const {return fRow;}
int Cell::Column() const {return fCol;}

bool Cell::operator==(const Cell& aOther) const {
     return (fRow == aOther.fRow) && (fCol == aOther.fCol);
}

bool Cell::operator<(const Cell& aOther) const {
    if (fRow == aOther.fRow) {
        return fCol < aOther.fCol;
    }
    return fRow < aOther.fRow;
}
