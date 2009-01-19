/* ***************************************************************************
 *  ,=³ .%%% %%%%%%%. .%%%%%.  .%%%%%.   %%%%%.%%. %. %%%%%%%% %% Rheinisch-
 * [==].%%%   %%   %% %%   %%  %%   %%   %%  %%'%%.%%.%% %% %% %% Westfälische
 *  //l%%%    %%   %% %%%%. ' %%       @ %%%%%' '%%%%%%% %% %%%%% Technische
 * [==]%%     %%|=%%   %%=>%  %%         %%  %%  '%%'%%% %% %% %% Hochschule
 * [==]%%%    %%   %% . '%%%% %%  '%%%   %%   %%  '% '%% %% %% %% Aachen
 * [==]'%%%   %%   %% %%   %%  %%   %%   http://kbsg.rwth-aachen.de/
 * o^^o '%%% %%%%%%%' '%%%%%'O '%%%%%'   Knowledge Based Systems Group
 * ***************************************************************************
 *
 *           $Id$
 *        author: Alexander Ferrein <ferrein@cs.rwth-aachen.de>
 *        mod by: Stefan Schiffer <schiffer@cs.rwth-aachen.de>
 *        mod by: Dennis Pannhausen <Dennis.Pannhausen@rwth-aachen.de>
 *   description: encapsulation of X-based grid display
 *
 * ************************************************************************ */

//extern "C" {

#ifndef _decl_display_h_
#define _decl_display_h_

// ///////////////////////////////////////
//  INCLUDES
// ///////////////////////////////////////

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
#include <string>
#include "graphics.h" /* include graphics header file */
#include "grid-world.h"
//#include "qlearner.h"

// ///////////////////////////////////////
//  DEFINES
// ///////////////////////////////////////

#define MAX_COLORS 100  /* lots of colors */

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 1200
#define GRID_X 0
#define GRID_Y 0
#define GRID_SIZE WINDOW_WIDTH
#define ROW_SIZE GRID_SIZE/SIZE
#define OFFSET ROW_SIZE/2

#define SIZE_OF_GRIDCELL WINDOW_WIDTH/SIZE

// ///////////////////////////////////////
//  STRUCTS
// ///////////////////////////////////////

typedef struct {
  int x1,y1,x2,y2;
} wall_t;

typedef struct {
  int x,y;
} pit_t;

typedef struct {
  int x,y;
} breeze_t;

typedef struct {
  int x,y;
} stench_t;

typedef struct {
  int x,y;
} shade_t;

typedef struct {
  int x,y;
} cell_t;

typedef struct {
  int X; 
  int Y; 
  int toX; 
  int toY; 
  std::string act; 
  ACTION action;
  float value; 
  float prob;
} value_t;

typedef struct {
  int X; 
  int Y; 
  int toX; 
  int toY; 
  std::string act; 
  ACTION action;
} action_t;

// ///////////////////////////////////////
//  MEMORY
// ///////////////////////////////////////

extern std::vector<wall_t>   Walls;
extern std::vector<pit_t>    Pits;
extern std::vector<breeze_t> Breezes;
extern std::vector<stench_t> Stenches;
extern std::vector<shade_t>  Shades;
extern std::vector<cell_t>   Cells;
extern std::vector<value_t>  Values;
extern std::vector<value_t>  OptPolicy;
extern std::vector<action_t> Actions;

// ///////////////////////////////////////
//  FUNCTIONS
// ///////////////////////////////////////

/** Start display.
 *  starts display with size X * Y.
 */
extern void start_display(int,  int );


extern jwin *WINDOW; ;/* define reference to a global variable for the window */

//static int COLORS[MAX_COLORS];/* define an array for storing colors */

void init_win(int wd, int ht);

void draw_columns();

void draw_walls();

void draw_pits();

void draw_breezes();

void draw_stench();

void draw_cells();

void draw_shades();

void draw_rows();

void draw_world(); /* draw grid world */

void draw_actions(); /* draw history of actions */

int state_x_location(STATE s);

int state_y_location(STATE s);

void draw_goal(STATE g);

void draw_direction(ACTION a, STATE s);

void display_policy(STATE g);

void start_up_window();

int convert_xloc_to_row(int x);

int convert_yloc_to_col(int y);

STATE get_goal_from_user();

void draw_dir(ACTION a, int X, int y);
void draw_turn(ACTION a, int x, int y);
void draw_goto(ACTION a, int toX, int toY,  int X, int y);
void draw_pol(ACTION a, int X, int Y);
void draw_start( int X, int Y) ;
void draw_goal( int X, int Y);
void draw_gold( int X, int Y);
void draw_item( int X, int Y);
void draw_agent( int X, int Y);
void draw_arrow( int X, int Y, std::string D );
void draw_wumpus_hunter( int X, int Y, std::string D, int A );
void draw_wumpus( int X, int Y, int A );
void draw_human( int X, int Y);
void draw_opt_vals();

void redraw();

void clear();

void clear_history();

#endif
 

//}; // extern "C"
