#include <stdlib.h>
#include <iostream>
#include <array>
#include <vector>
#include <memory>

#define COLS 50
#define ROWS 50 
#define LIFETIME 120

struct Cell {
  bool alive = (rand() < (RAND_MAX / 2));
  bool next_state = false;
  std::vector< std::shared_ptr<Cell> > neighbors;

  void Draw() const;
  void PrepGrowth();
  void Grow();
};

class CellGrid {
  std::array< std::array<Cell,ROWS>,COLS > cells;

public:

  CellGrid();
  void Draw() const;
  void Grow();
};

