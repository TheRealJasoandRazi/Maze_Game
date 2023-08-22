//
//  Player.hpp
//  MazeGame
//
//  Created by Nemanja Popovic on 10/7/2023.
//

#ifndef Player_hpp
#define Player_hpp
#include "Cell.hpp"
#include <stdio.h>
#include "Builder.hpp"
#include <string>
#include "Maze.hpp"

class Player{
private:
    size_t fRow;
    size_t fCol;
    
    void UpdatePlayer(SDL_Surface* aSurface, Cell& aCell, Cell& aNextCell, Builder builder, bool Colour);
    bool CheckWalls(Cell aCurrentCell, Cell aNextCell, std::string Direction);
public:
    Player();
    int MovePlayer(std::string Direction, SDL_Surface* aSurface, Cell& aCell, Maze& maze, Builder builder, bool Colour);
};
#endif /* Player_hpp */
