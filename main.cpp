#include <stdlib.h>
#include <unistd.h>
#include "CellGrid.hpp"

#define LIFETIME 120

int main() {
  CellGrid game = CellGrid();

  for (int i = 5*LIFETIME; i > 0; i--) {
    game.Draw();
    usleep(200*1000);
    //system("cls");
    system("clear");
    game.Grow();
  }

  return 0;
}

