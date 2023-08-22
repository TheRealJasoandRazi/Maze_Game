//
//  main.cpp
//  MazeGame
//
//  Created by Nemanja Popovic on 1/7/2023.
//

#include <iostream>
#include "Maze.hpp"
#include <SDL2/SDL.h>
#include "Builder.hpp"
#include "Player.hpp"
#include "Solver.hpp"
#include "GUI.hpp"

int main(int argc, const char * argv[]) {
    bool Colour = false;
    int size = 30;
    int windowsize = 600;
    Maze maze(size, size);
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
        printf("\nThere is a error:%s\n",SDL_GetError());
    }
    SDL_Window* window;
    window=SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowsize + 200   , windowsize, SDL_WINDOW_SHOWN);
    if(window == NULL){
        printf("\nerror is %s\n",SDL_GetError());
    }
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 0x00, 0x00, 0x00, 0xFF));
    
    Builder builder(windowsize, windowsize, size, size); //Displays cells
    for(int i = 0; i < maze.Size(); i++){
        builder.BuildCell(surface, maze.Grid(i), "W");
    }
    int lastCellIndex = maze.Size() - 1;
    SDL_Rect lastCellRect = builder.GetCellRect(maze.Grid(lastCellIndex));
    SDL_FillRect(surface, &lastCellRect, SDL_MapRGB(surface->format, 0, 255, 0));

    SDL_Rect firstCellRect = builder.GetCellRect(maze.Grid(0));
    SDL_FillRect(surface, &firstCellRect, SDL_MapRGB(surface->format, 255, 0, 0));

    int playerposition = 0;
    Cell playerpos = maze.Grid(playerposition);
    Player player;
    Solver solver;
    
    GUI Button12(615, 50);
    GUI Button20(675, 50);
    GUI Button30(735, 50);
    GUI ChangeSizeText(615, 25);
    GUI Solve(675, 150);
    GUI Pallet1(615, 100);
    GUI Pallet2(675, 100);
    
    builder.BuildButton(surface, Button12, "B");
    Button12.PrintText(surface, "12");
    builder.BuildButton(surface, Button20, "B");
    Button20.PrintText(surface, "20");
    builder.BuildButton(surface, Button30, "B");
    Button30.PrintText(surface, "30");
    builder.BuildButton(surface, Solve, "B");
    Solve.PrintText(surface, "Solve");
    
    builder.BuildButton(surface, ChangeSizeText, "N");
    ChangeSizeText.PrintText(surface, "Change Size of Maze");
    
    builder.BuildButton(surface, Pallet1, "B");
    Pallet1.PrintText(surface, "Pallet 1");
    builder.BuildButton(surface, Pallet2, "B");
    Pallet2.PrintText(surface, "Pallet2");
    
    SDL_UpdateWindowSurface(window);
    
    SDL_bool quit = SDL_FALSE;
    while (!quit && playerposition != maze.Size()-1) {
        SDL_Event e;
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = SDL_TRUE;
            }else if(e.type == SDL_MOUSEBUTTONDOWN){
                if(Button12.IfPressed()){
                    size = 12;
                    SDL_DestroyWindow(window);
                    window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowsize + 200, windowsize, SDL_WINDOW_SHOWN);
                    surface = SDL_GetWindowSurface(window);
                    SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 0x00, 0x00, 0x00, 0xFF));
                    
                    maze = Maze(size, size);
                    builder = Builder(windowsize, windowsize, size, size);
                    for (int i = 0; i < maze.Size(); i++) {
                        builder.BuildCell(surface, maze.Grid(i), "W");
                    }

                    lastCellIndex = maze.Size() - 1;
                    SDL_Rect lastCellRect = builder.GetCellRect(maze.Grid(lastCellIndex));
                    SDL_FillRect(surface, &lastCellRect, SDL_MapRGB(surface->format, 0, 255, 0));

                    SDL_Rect firstCellRect = builder.GetCellRect(maze.Grid(0));
                    SDL_FillRect(surface, &firstCellRect, SDL_MapRGB(surface->format, 255, 0, 0));

                    playerposition = 0;
                    playerpos = maze.Grid(playerposition);
                    builder.BuildButton(surface, Button12, "B");
                    Button12.PrintText(surface, "12");
                    builder.BuildButton(surface, Button20, "B");
                    Button20.PrintText(surface, "20");
                    builder.BuildButton(surface, Button30, "B");
                    Button30.PrintText(surface, "30");
                    builder.BuildButton(surface, Solve, "B");
                    Solve.PrintText(surface, "Solve");
                    
                    builder.BuildButton(surface, ChangeSizeText, "N");
                    ChangeSizeText.PrintText(surface, "Change Size of Maze");
                    
                    builder.BuildButton(surface, Pallet1, "B");
                    Pallet1.PrintText(surface, "Pallet 1");
                    builder.BuildButton(surface, Pallet2, "B");
                    Pallet2.PrintText(surface, "Pallet2");
                    
                    SDL_UpdateWindowSurface(window);

                } else if(Button20.IfPressed()){
                    size = 20;
                    SDL_DestroyWindow(window);
                    window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowsize + 200, windowsize, SDL_WINDOW_SHOWN);
                    surface = SDL_GetWindowSurface(window);
                    SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 0x00, 0x00, 0x00, 0xFF));
                    
                    maze = Maze(size, size);
                    builder = Builder(windowsize, windowsize, size, size);
                    for (int i = 0; i < maze.Size(); i++) {
                        builder.BuildCell(surface, maze.Grid(i), "W");
                    }

                    lastCellIndex = maze.Size() - 1;
                    SDL_Rect lastCellRect = builder.GetCellRect(maze.Grid(lastCellIndex));
                    SDL_FillRect(surface, &lastCellRect, SDL_MapRGB(surface->format, 0, 255, 0));

                    SDL_Rect firstCellRect = builder.GetCellRect(maze.Grid(0));
                    SDL_FillRect(surface, &firstCellRect, SDL_MapRGB(surface->format, 255, 0, 0));

                    playerposition = 0;
                    playerpos = maze.Grid(playerposition);
                    builder.BuildButton(surface, Button12, "B");
                    Button12.PrintText(surface, "12");
                    builder.BuildButton(surface, Button20, "B");
                    Button20.PrintText(surface, "20");
                    builder.BuildButton(surface, Button30, "B");
                    Button30.PrintText(surface, "30");
                    builder.BuildButton(surface, Solve, "B");
                    Solve.PrintText(surface, "Solve");
                    
                    builder.BuildButton(surface, Pallet1, "B");
                    Pallet1.PrintText(surface, "Pallet 1");
                    builder.BuildButton(surface, Pallet2, "B");
                    Pallet2.PrintText(surface, "Pallet2");
                    
                    builder.BuildButton(surface, ChangeSizeText, "N");
                    ChangeSizeText.PrintText(surface, "Change Size of Maze");
                    
                    SDL_UpdateWindowSurface(window);

                } else if(Button30.IfPressed()){
                    size = 30;
                    SDL_DestroyWindow(window);
                    window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, windowsize + 200, windowsize, SDL_WINDOW_SHOWN);
                    surface = SDL_GetWindowSurface(window);
                    SDL_FillRect(surface, NULL, SDL_MapRGBA(surface->format, 0x00, 0x00, 0x00, 0xFF));
                    
                    maze = Maze(size, size);
                    builder = Builder(windowsize, windowsize, size, size);
                    for (int i = 0; i < maze.Size(); i++) {
                        builder.BuildCell(surface, maze.Grid(i), "W");
                    }

                    lastCellIndex = maze.Size() - 1;
                    SDL_Rect lastCellRect = builder.GetCellRect(maze.Grid(lastCellIndex));
                    SDL_FillRect(surface, &lastCellRect, SDL_MapRGB(surface->format, 0, 255, 0));

                    SDL_Rect firstCellRect = builder.GetCellRect(maze.Grid(0));
                    SDL_FillRect(surface, &firstCellRect, SDL_MapRGB(surface->format, 255, 0, 0));

                    playerposition = 0;
                    playerpos = maze.Grid(playerposition);
                    builder.BuildButton(surface, Button12, "B");
                    Button12.PrintText(surface, "12");
                    builder.BuildButton(surface, Button20, "B");
                    Button20.PrintText(surface, "20");
                    builder.BuildButton(surface, Button30, "B");
                    Button30.PrintText(surface, "30");
                    builder.BuildButton(surface, Solve, "B");
                    Solve.PrintText(surface, "Solve");
                    
                    builder.BuildButton(surface, ChangeSizeText, "N");
                    ChangeSizeText.PrintText(surface, "Change Size of Maze");
                    
                    builder.BuildButton(surface, Pallet1, "B");
                    Pallet1.PrintText(surface, "Pallet 1");
                    builder.BuildButton(surface, Pallet2, "B");
                    Pallet2.PrintText(surface, "Pallet2");
                    
                    SDL_UpdateWindowSurface(window);

                } else if(Solve.IfPressed()){
                    std::vector<int> path;
                    path = solver.Solve(maze);
                    if(!Colour){
                        builder.BuildCell(surface, maze.Grid(playerposition), "W");
                    } else {
                        builder.BuildCell(surface, maze.Grid(playerposition), "B");
                    }
                    solver.OutputSolution(path, maze, builder, surface, window);
                    break;
                } else if(Pallet1.IfPressed()){
                    Colour = false;
                    for (int i = 0; i < maze.Size(); i++) {
                        builder.BuildCell(surface, maze.Grid(i), "W");
                    }
                    SDL_Rect firstCellRect = builder.GetCellRect(maze.Grid(playerposition));
                    SDL_FillRect(surface, &lastCellRect, SDL_MapRGB(surface->format, 0, 255, 0));
                    SDL_FillRect(surface, &firstCellRect, SDL_MapRGB(surface->format, 255, 0, 0));
                    SDL_UpdateWindowSurface(window);
                } else if(Pallet2.IfPressed()){
                    Colour = true;
                    for (int i = 0; i < maze.Size(); i++) {
                        builder.BuildCell(surface, maze.Grid(i), "B");
                    }
                    SDL_Rect firstCellRect = builder.GetCellRect(maze.Grid(playerposition));
                    SDL_FillRect(surface, &lastCellRect, SDL_MapRGB(surface->format, 0, 255, 0));
                    SDL_FillRect(surface, &firstCellRect, SDL_MapRGB(surface->format, 255, 0, 0));
                    SDL_UpdateWindowSurface(window);
                }
            } else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                    case SDLK_w:
                        playerposition = player.MovePlayer("W", surface, playerpos, maze, builder, Colour);
                        playerpos = maze.Grid(playerposition);
                        SDL_UpdateWindowSurface(window); // Update the screen after player movement
                        break;
                    case SDLK_a:
                        playerposition = player.MovePlayer("A", surface, playerpos, maze, builder, Colour);
                        playerpos = maze.Grid(playerposition);
                        SDL_UpdateWindowSurface(window); // Update the screen after player movement
                        break;
                    case SDLK_s:
                        playerposition = player.MovePlayer("S", surface, playerpos, maze, builder, Colour);
                        playerpos = maze.Grid(playerposition);
                        SDL_UpdateWindowSurface(window); // Update the screen after player movement
                        break;
                    case SDLK_d:
                        playerposition = player.MovePlayer("D", surface, playerpos, maze, builder, Colour);
                        playerpos = maze.Grid(playerposition);
                        SDL_UpdateWindowSurface(window); // Update the screen after player movement
                        break;
                    case SDLK_q:
                        quit = SDL_TRUE;
                        break;
                    case SDLK_o:
                        std::vector<int> path;
                        path = solver.Solve(maze);
                        builder.BuildCell(surface, maze.Grid(playerposition), "W");
                        solver.OutputSolution(path, maze, builder, surface, window);
                        break;
                }
            }
        }
    }




     SDL_DestroyWindow(window);
     SDL_Quit();
}
