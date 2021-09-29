#include "CellGrid.hpp"

void Cell::Draw() const {
  if (alive)
    std::cout << 'X';
  else
    std::cout << ' ';
}

void Cell::PrepGrowth() {
  std::size_t sum = 0;
  for (const auto& neighbor : neighbors)
    if (neighbor->alive)
      sum++;

  if(sum == 3 || (sum == 2 && alive))
    alive_next = true;
  else
    alive_next = false;
}

void Cell::Grow() {
  alive = alive_next;
}

CellGrid::CellGrid() {
  for(std::size_t i = 0; i < COLS; i++) {
    for(std::size_t j = 0; j < ROWS; j++) {
        auto& neighbors = cells[i][j].neighbors;
        neighbors.emplace_back(&(cells[(i+1)%ROWS][(j  )%COLS]));
        neighbors.emplace_back(&(cells[(i  )%ROWS][(j+1)%COLS]));
        neighbors.emplace_back(&(cells[(i-1)%ROWS][(j  )%COLS]));
        neighbors.emplace_back(&(cells[(i  )%ROWS][(j-1)%COLS]));
        neighbors.emplace_back(&(cells[(i+1)%ROWS][(j+1)%COLS]));
        neighbors.emplace_back(&(cells[(i-1)%ROWS][(j+1)%COLS]));
        neighbors.emplace_back(&(cells[(i+1)%ROWS][(j-1)%COLS]));
        neighbors.emplace_back(&(cells[(i-1)%ROWS][(j-1)%COLS]));
    }
  }
}

void CellGrid::Draw() const {
  system("clear");
  for(const auto& row : cells) {
    for (const auto& cell : row)
      cell.Draw();
    std::cout << '\n';  
  }
}

void CellGrid::Grow() {
  for(auto& row : cells)
    for (auto& cell : row)
      cell.PrepGrowth();
  for(auto& row : cells)
    for (auto& cell : row)
      cell.Grow();
}

