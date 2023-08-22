//
//  Maze.cpp
//  MazeGame
//
//  Created by Nemanja Popovic on 1/7/2023.
//
#include "Maze.hpp"
#include "Cell.hpp"
#include <iostream>
#include <set>
#include <stack>
#include <random>
#include <string>

int Maze::Size(){
    return fRow * fCol;
}

Maze::Maze(int aRow, int aCol) :
    fRow(aRow),
    fCol(aCol)
{
    for (int j = 0; j < fRow; j++) {
        for (int i = 0; i < fCol; i++) {
            Cell cell(j, i);
            grid.push_back(cell);
        }
    }
    GenerateMaze();
    CleanUp();
}

void Maze::CleanUp(){
    for (int i = 0; i < Size(); i++) {
        int indexright = i + 1;
        int indexleft = i - 1;
        int indexdown = i + fCol;
        int indexup = i - fCol;
        if(indexright >= 0 && indexright < Size()){
            if(grid[i].fWalls.right != grid[indexright].fWalls.left){
                grid[i].fWalls.right = false;
                grid[indexright].fWalls.left = false;
            }
        }
        if(indexleft >= 0 && indexleft < Size()){
            if(grid[i].fWalls.left != grid[indexleft].fWalls.right){
                grid[i].fWalls.left = false;
                grid[indexleft].fWalls.right = false;
            }
        }
        if(indexup >= 0 && indexup < Size()){
            if(grid[i].fWalls.top != grid[indexup].fWalls.bottom){
                grid[i].fWalls.top = false;
                grid[indexup].fWalls.bottom = false;
            }
        }
        if(indexdown >= 0 && indexdown < Size()){
            if(grid[i].fWalls.bottom != grid[indexdown].fWalls.top){
                grid[i].fWalls.bottom = false;
                grid[indexdown].fWalls.top = false;
            }
        }
    }
}

void Maze::GenerateMaze() {
    std::stack<Cell> Visited;
    grid[0].Visited(true);
    Visited.push(grid[0]);

    while (!Visited.empty()) {
        Cell current = Visited.top();
        Visited.pop();
        std::stack<Cell> Neighbours = GetNeighbours(current); //this might have an issue

        if (!Neighbours.empty()) {
            Visited.push(current);
            Cell neighbour = RandomNeighbour(Neighbours);
            RemoveWall(current, neighbour);
            size_t index = (fCol * neighbour.Row() + neighbour.Column());
            neighbour.Visited(true);
            grid[index].Visited(true);
            Visited.push(neighbour);
        }
    }
}

void Maze::RemoveWall(Cell& Current, Cell& Random){
    if (Random.Column() > Current.Column()){
           Random.fWalls.left = false;
           Current.fWalls.right = false;
       } else if (Random.Column() < Current.Column()){
           Random.fWalls.right = false;
           Current.fWalls.left = false;
       } else if (Random.Row() > Current.Row()){
           Random.fWalls.top = false;
           Current.fWalls.bottom = false;
       } else if (Random.Row() < Current.Row()){
           Random.fWalls.bottom = false;
           Current.fWalls.top = false;
       }
    size_t currentindex = (fCol * Current.Row() + Current.Column());
    size_t randomindex = (fCol * Random.Row() + Random.Column());
    grid[currentindex] = Current;
    grid[randomindex] = Random;
}

Cell Maze::RandomNeighbour(std::stack<Cell>& Neighbours){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<size_t> dist(0, Neighbours.size() - 1);
    size_t randomIndex = dist(gen);
    
    std::stack<Cell> tempStack;
    while (randomIndex > 0) {
        tempStack.push(Neighbours.top());
        Neighbours.pop();
        randomIndex--;
    }

    Cell randomElement = Neighbours.top();
    Neighbours.pop();
    
    while (!tempStack.empty()) {
        Neighbours.push(tempStack.top());
        tempStack.pop();
    }

    return randomElement;
}

std::stack<Cell> Maze::GetNeighbours(Cell& cell){
    std::stack<Cell> Neighbours;
    size_t currentindex = ((fCol * cell.Row()) + cell.Column());
    size_t indexright = currentindex + 1;
    size_t indexleft = currentindex - 1;
    size_t indexdown = currentindex + fCol;
    size_t indexup = currentindex - fCol;
    if (cell.Row() > 0 && grid[indexup].Visited() == false) {
        Neighbours.push(grid[indexup]);
    }
    if (cell.Column() > 0 && grid[indexleft].Visited() == false) {
        Neighbours.push(grid[indexleft]);
    }
    if (cell.Row() < fRow - 1 && grid[indexdown].Visited() == false) {
        Neighbours.push(grid[indexdown]);
    }
    if (cell.Column() < fCol - 1 && grid[indexright].Visited() == false) {
        Neighbours.push(grid[indexright]);
    }
    return Neighbours;
}
bool Maze::IsCellVisited(const Cell& cell, std::stack<Cell>& Visited) {
    std::stack<Cell> tempStack;
    bool isVisited = false;

    while (!Visited.empty()) {
        Cell current = Visited.top();
        Visited.pop();

        if (current == cell) {
            isVisited = true;
        }

        tempStack.push(current);
    }

    while (!tempStack.empty()) {
        Visited.push(tempStack.top());
        tempStack.pop();
    }

    return isVisited;
}

void Maze::PrintMaze() {
    std::cout << "{" << std::endl;
    for (size_t j = 0; j < Size(); j++) {
        std::cout << grid[j].fWalls.top;
        std::cout << grid[j].fWalls.right;
        std::cout << grid[j].fWalls.bottom;
        std::cout << grid[j].fWalls.left;
        if( j != Size() - 1){
            std::cout << ", ";
        }
        if ((j + 1) % fRow == 0) { // Creates new row after printing each column
            std::cout << std::endl;
        }
    }
    std::cout << "}" << std::endl;
}

Cell& Maze::Grid(int aIndex) {
    return grid[aIndex];
}
int Maze::Row() {return fRow;}
int Maze::Column() {return fCol;}

void Maze::ResetVisited(){
    for(int i = 0; i < Size(); i++){
        if(grid[i].Visited() == true){
            grid[i].Visited(false);
        }
    }
}
