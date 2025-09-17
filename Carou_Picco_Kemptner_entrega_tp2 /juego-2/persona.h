#pragma once
#include <ncurses.h>
#include "perdida.h"

class Persona
{
public:
  // Método para inicializar los valores que necesita la Persona.
  Persona();

  // Método para dibujar la Persona.
  void draw();
  void input(int tecla);
  void perderVida();
  void ganarDinero();
  void colisionar(Perdida unaPerdida);

  // Getters y Setters.
  void setX(int x);
  void setY(int y);
  void setVidas(int vidas);
  void setDinero(int dinero);
  int getX();
  int getY();
  int getVidas();
  int getDinero();

private:
  int m_x, m_y, vidas, dinero;
};