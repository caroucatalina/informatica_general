#include <iostream>
#include <ncurses.h>
#include "persona.h"
#include "perdida.h"

///////////////////////////////////////////////////////////////////////////
Persona::Persona()
{
  // Al inicial el juego colocamos la nave en el centro de la pantalla.
  m_x = 60;
  m_y = 20;
  vidas = 3;
  dinero = 0;
}

///////////////////////////////////////////////////////////////////////////

 void Persona::draw() {

    // --- CABEZA ---
    mvaddch(m_y + 4, m_x + 4, '.');
    mvaddch(m_y + 4, m_x + 5, '-');
    mvaddch(m_y + 4, m_x + 6, '-');
    mvaddch(m_y + 4, m_x + 7, '-');
    mvaddch(m_y + 4, m_x + 8, '.');

    mvaddch(m_y + 5, m_x + 3, '/');
    mvaddch(m_y + 5, m_x + 9, '\\');

    mvaddch(m_y + 6, m_x + 2, '|');
    mvaddch(m_y + 6, m_x + 4, '(');
    mvaddch(m_y + 6, m_x + 5, 'o');
    mvaddch(m_y + 6, m_x + 6, ' ');
    mvaddch(m_y + 6, m_x + 7, 'o');
    mvaddch(m_y + 6, m_x + 8, ')');
    mvaddch(m_y + 6, m_x + 10, '|');

    mvaddch(m_y + 7, m_x + 2, '|');
    mvaddch(m_y + 7, m_x + 5, ' ');
    mvaddch(m_y + 7, m_x + 6, '^');
    mvaddch(m_y + 7, m_x + 7, ' ');
    mvaddch(m_y + 7, m_x + 10, '|');

    mvaddch(m_y + 8, m_x + 2, '|');
    mvaddch(m_y + 8, m_x + 5, '\'');
    mvaddch(m_y + 8, m_x + 6, '-');
    mvaddch(m_y + 8, m_x + 7, '\'');
    mvaddch(m_y + 8, m_x + 10, '|');

    mvaddch(m_y + 9, m_x + 3, '\\');
    mvaddch(m_y + 9, m_x + 9, '/');

    mvaddch(m_y + 10, m_x + 4, '_');
    mvaddch(m_y + 10, m_x + 5, '_');
    mvaddch(m_y + 10, m_x + 6, '_');
    mvaddch(m_y + 10, m_x + 7, '_');
    mvaddch(m_y + 10, m_x + 8, '_');

    // --- CUELLO ---
    mvaddch(m_y + 11, m_x + 6, '|');
    mvaddch(m_y + 12, m_x + 6, '|');

    // --- BRAZOS ---
    mvaddch(m_y + 12, m_x + 3, '-');
    mvaddch(m_y + 12, m_x + 4, '-');
    mvaddch(m_y + 12, m_x + 5, '-');
    mvaddch(m_y + 12, m_x + 7, '-');
    mvaddch(m_y + 12, m_x + 8, '-');
    mvaddch(m_y + 12, m_x + 9, '-');

    // --- TORSO ---
    mvaddch(m_y + 13, m_x + 5, '|');
    mvaddch(m_y + 13, m_x + 7, '|');

    mvaddch(m_y + 14, m_x + 5, '|');
    mvaddch(m_y + 14, m_x + 7, '|');

    // --- PIERNAS ---
    mvaddch(m_y + 15, m_x + 5, '/');
    mvaddch(m_y + 15, m_x + 7, '\\');

    mvaddch(m_y + 16, m_x + 4, '/');
    mvaddch(m_y + 16, m_x + 8, '\\');

    // --- PIES ---
    mvaddch(m_y + 17, m_x + 4, 'o');
    mvaddch(m_y + 17, m_x + 8, 'o');
}

void Persona::input(int tecla)
{
	// Agregamos el movimiento de la nave.
	if(tecla == KEY_LEFT && m_x > 2)
  {
		m_x--;
	}
	if(tecla == KEY_RIGHT && m_x < 75)
  {
		m_x++;
	}
}
void Persona::colisionar(Perdida unaPerdida)
{
  if (m_x == unaPerdida.getX() && m_y == unaPerdida.getY())
  {
    if (unaPerdida.getEsGanancia())
    {
      dinero += 10;
    }
    else
    {
      vidas--;
      dinero -= 10;
      if (dinero < 0) dinero = 0;
    }
  }
}

void update(Persona& unaPersona, Perdida perdidas[], bool& game_over)
{
  for (int i = 0; i < 3; i++)
  {
    perdidas[i].update();
    unaPersona.colisionar(perdidas[i]);
  }
  if (unaPersona.getVidas() <= 0)
  {
    game_over = true;
  }
}


///////////////////////////////////////////////////////////////////////////
void Persona::setX(int x) { m_x = x; }
void Persona::setY(int y) { m_y = y; }
void Persona::setVidas(int v) { vidas = vidas; }
void Persona::setDinero(int d) { dinero = dinero; }

///////////////////////////////////////////////////////////////////////////
int Persona::getX() { return m_x; }
int Persona::getY() { return m_y; }
int Persona::getVidas() { return vidas; }
int Persona::getDinero() { return dinero; }