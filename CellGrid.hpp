#include <stdlib.h>
#include <iostream>
#include <array>
#include <vector>
#include <memory>

#define COLS 60
#define ROWS 50

class Cell {
  bool alive;
  bool alive_next;

public:

  Cell() : alive(rand() < (RAND_MAX / 2)) {}

  std::vector< std::shared_ptr<Cell> > neighbors;

  void Draw() const;
  void PrepGrowth();
  void Grow();
};

class CellGrid {
  std::array< std::array<Cell, COLS>, ROWS > cells;

public:

  CellGrid();
  void Draw() const;
  void Grow();
};

