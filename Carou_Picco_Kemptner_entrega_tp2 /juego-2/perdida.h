#pragma once
#include <ncurses.h>

class Perdida
{
public:
  // Método para inicializar los valores que necesita la Persona.
  Perdida();
  void update();
  void draw();


  // Getters y Setters.
  void setX(int x);
  void setY(int y);
  int getX();
  int getY();
  bool getEsGanancia();
  int getDinero();
  void reset();


private:
  int m_x, m_y, dinero;
  bool esGanancia;
};