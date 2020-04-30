cmake_minimum_required(VERSION 3.15)
project(Project C)

set(CMAKE_C_STANDARD 99)

add_executable(Project main.c game_init.c game_init.h input_output.c input_output.h player_move.c player_move.h check_game.c check_game.h)