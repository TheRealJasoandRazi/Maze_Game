//
//  Player.cpp
//  MazeGame
//
//  Created by Nemanja Popovic on 10/7/2023.
//

#include "Player.hpp"
#include <string>
#include "Maze.hpp"
#include <SDL2/SDL.h>
#include <queue>

int Player::MovePlayer(std::string Direction, SDL_Surface* aSurface, Cell& aCell, Maze& maze, Builder builder, bool Colour){
    int currentindex = ((maze.Row() * aCell.Row()) + aCell.Column());
    int indexright = currentindex + 1;
    int indexleft = currentindex - 1;
    int indexdown = currentindex + maze.Column();
    int indexup = currentindex - maze.Column();
    if (Direction == "W") {
        if(indexup >= 0 && indexup < maze.Size()){
            Cell cell = maze.Grid(static_cast<int>(indexup));
            if(CheckWalls(aCell, cell, "W")){
                UpdatePlayer(aSurface, aCell, cell, builder, Colour);
                return indexup;
            }
        }
    } else if (Direction == "A") {
        if(indexleft >= 0 && indexleft < maze.Size()){
            Cell cell = maze.Grid(static_cast<int>(indexleft));
            if(CheckWalls(aCell, cell, "A")){
                UpdatePlayer(aSurface, aCell, cell, builder, Colour);
                return indexleft;
            }
        }
    } else if (Direction == "S") {
        if(indexdown >= 0 && indexdown < maze.Size()){
            Cell cell = maze.Grid(static_cast<int>(indexdown));
            if(CheckWalls(aCell, cell, "S")){
                UpdatePlayer(aSurface, aCell, cell, builder, Colour);
                return indexdown;
            }
        }
    } else if (Direction == "D") {
        if(indexright >= 0 && indexright < maze.Size()){
            Cell cell = maze.Grid(static_cast<int>(indexright));
            if(CheckWalls(aCell, cell, "D")){
                UpdatePlayer(aSurface, aCell, cell, builder, Colour);
                return indexright;
            }
        }
    }
    return currentindex;
}

Player::Player() :
    fRow(0),
    fCol(0)
{}

bool Player::CheckWalls(Cell aCurrentCell, Cell aNextCell, std::string Direction){
    if(Direction == "W"){
        return aCurrentCell.fWalls.top == false && aNextCell.fWalls.bottom == false;
    }
    if(Direction == "A"){
        return aCurrentCell.fWalls.left == false && aNextCell.fWalls.right == false;
    }
    if(Direction == "S"){
        return aCurrentCell.fWalls.bottom == false && aNextCell.fWalls.top == false;
    }
    if(Direction == "D"){
        return aCurrentCell.fWalls.right == false && aNextCell.fWalls.left == false;
    }
    return false;
}

void Player::UpdatePlayer(SDL_Surface* aSurface, Cell& aCell, Cell& aNextCell, Builder builder, bool Colour){
    if(!Colour){
        builder.BuildCell(aSurface, aCell, "W"); //rebuilds old cell
    }else{
        builder.BuildCell(aSurface, aCell, "B"); //rebuilds old cell
    }
    builder.BuildCell(aSurface, aNextCell, "R"); //builds new cell
}


