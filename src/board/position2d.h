
#ifndef POSITION_2D_H
#define POSITION_2D_H

class Position2D {
private:
  int xPos;
  int yPos;
public:
  Position2D(int x, int y);
  int getX();
  int getY();
  void setX(int x);
  void setY(int y);
};

#endif
