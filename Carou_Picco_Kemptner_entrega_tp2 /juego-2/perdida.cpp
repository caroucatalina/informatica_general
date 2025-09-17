#include <iostream>
#include <ncurses.h>
#include "perdida.h"

///////////////////////////////////////////////////////////////////////////
Perdida::Perdida()
{
    m_x = rand() % 118 + 1;
    m_y = 1;
    esGanancia = false;
    dinero = 10;
}

void Perdida::update()
{
    int numeroAleatorio = rand() % 100 + 1;

    m_y = m_y + 1;

    if (m_y >= 39)
    {
        reset(); // en lugar de repetir código, usamos reset()
        if (numeroAleatorio > 0 && numeroAleatorio < 81)
        {
            esGanancia = false;
        }
        else
        {
            esGanancia = true;
        }
    }
}

void Perdida::draw()
{
    if (esGanancia == false)
    {
        mvaddch(m_y, m_x, '@');
    }
    else
    {
        mvaddch(m_y, m_x, '$');
    }
}

///////////////////////////////////////////////////////////////////////////
void Perdida::setX(int x) { m_x = x; }
void Perdida::setY(int y) { m_y = y; }

///////////////////////////////////////////////////////////////////////////
int Perdida::getX() { return m_x; }
int Perdida::getY() { return m_y; }
bool Perdida::getEsGanancia() { return esGanancia; }
int Perdida::getDinero() { return dinero; }

///////////////////////////////////////////////////////////////////////////
// Nuevo método reset()
void Perdida::reset()
{
    // Reposicionamos la pérdida arriba en X aleatoria
    m_x = rand() % 118 + 1;
    m_y = 1;

    // Opcional: decidir si es pérdida o ganancia al resetear
    int numeroAleatorio = rand() % 100 + 1;
    if (numeroAleatorio > 0 && numeroAleatorio < 81)
    {
        esGanancia = false;
    }
    else
    {
        esGanancia = true;
    }
}