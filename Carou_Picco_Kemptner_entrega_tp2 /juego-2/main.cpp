#include <ncurses.h>
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // usleep
// Incluimos la clase persona.
#include "persona.h"
#include "perdida.h"

using namespace std;

//=========================================================================
// DECLARACION DE LAS CONSTANTES
//=========================================================================

const int ANCHO = 120;
const int ALTO = 40;
const int DELAY = 40; //velocidad del juego

//=========================================================================
// DEFINICION DE LAS VARIABLES GLOBALES
//=========================================================================

bool game_over;
int puntaje;
bool salir;
int vidas;
int dinero;


//=========================================================================
// DECLARACION DE LAS FUNCIONES GLOBALES
//=========================================================================

void setup();
void input(Persona unaPersona, int tecla);
void update(Persona unaPersona, Perdida perdidas[]);
void draw(Persona unaPersona, Perdida perdidas[]);
void gameover();
void colisionar(Persona unaPersona, Perdida unaPerdida);

//=========================================================================
// MAIN
//=========================================================================

int main()
{
	int opcion = 1;
	bool continuar = true;

	system("clear");
 //titulo                                                                                                                     
 std::cout <<"                                      .                                              ..:lddxxxxxdoc,.                    " << std::endl;
 std::cout <<"    .coooc.                          ck,                                          .,okkdl:,'..',;coxkxc.                 " << std::endl;
 std::cout <<"   'OO:.''  ,cll:..;cloc. ,lll;. 'lolOX: .cool,  ;c:l,                          .:kOo,.     .,.     .cxOd'               " << std::endl;
 std::cout <<"   lXo      ;oo0Xc .:OKc..:odKX;.k0c,kX:.k0c,xK:.kXd;.                         ,kOl.       .dK:        ,x0l.             " << std::endl;
 std::cout <<"   ;Kk'... :0xckNl ,kO;..l0dcOX:'0O'.dX:'OO'.oXc.k0'                          :0x'       ,ox0KOxc.      .c0x.            " << std::endl;
 std::cout <<"    ;dxoo:.,xdclx:.oOdl:':kdcox, ;xdcdx, ,ddodc..od.                         :Kx.       cKx;..'cOO,       :Kd.           " << std::endl;
 std::cout <<"       ..    .             .       .        .                               .k0'       .xK,     cKc       .dK:           " << std::endl;
 std::cout <<"                                                                            ;Kd.        c0k;.   ...        ;Kx.          " << std::endl;
 std::cout <<"                                                                            cXl          'lkkd;.           '0k.          " << std::endl;
 std::cout <<"                                                                            ;Kd             'lxOd,         ,Kx.          " << std::endl;
 std::cout <<"                        :xdool,                                             .O0'        ,,     'kK;        oXc           " << std::endl;
 std::cout <<"                       .dXl.,xKc .clll:.                                     :Kx.      .k0,    .dXc       :Kx.           " << std::endl;
 std::cout <<"                       .dK;  ;Xx'dNkoOK:                                      cKx.      ,kOdllokOl.      :0k.            " << std::endl;
 std::cout <<"                       .dXc.,xKc.dNkccc.                                       ;OOc.     .'l0Nx;.      'x0o.             " << std::endl;
 std::cout <<"                        :kdool'  .loll:.                                        .cOOl'      cx'     .;xOx,               " << std::endl;
 std::cout <<"                                                                                  .:dkkdc;'.''..,:lxkxl'                 " << std::endl;
 std::cout <<"                                                          'dkxxxxxxxd'     .,:clll:;'',codxxxxxxxdl;.         .:c:'      " << std::endl;
 std::cout <<"                                                          :Xk;,''',xN0ooodkkxdollloxkkd:.   ...            .,dOkox0o.    " << std::endl;
 std::cout <<"                                                          cXo.     lNOccc:,.        .'lOOddddddddddo:.   .ckOo,  .O0'    " << std::endl;
 std::cout <<"       ;kxoo;               .;.                           cXo.     lXc                 .,;;;;;;;;::o0x',dOkc.  .:kOc     " << std::endl;
 std::cout <<"       cXd'.. 'ododc. cdlo;;OXx;.;d' .oc..ooloxc. .clod,  cXl.     lXl                            .,OWKOd,   'oOkc.      " << std::endl;
 std::cout <<"       cN0ol'.k0;.oXl.xXo...OK;  oX: '0k.,KO,'kK, ,llxNk. :Xo.     lXl                 ;xxxxxxxxxxxOOxc.  .:xOd,.        " << std::endl;
 std::cout <<"       cXo.  .k0:.oXc.xK,  .xKc..lXo.cXk.,Kx..dK;,00ldXk. :Xd',cl:'lXc                  .............   .lOkl.           " << std::endl;
 std::cout <<"       'o,    .cooo:. :l.   ,dd:..ldlco:..l:  ;o..cdlcl:. :XX0XOd00OXd'''..                          .;xOx;.             " << std::endl;
 std::cout <<"                                                          cXX0X0kK0ONKxxxkkxdl:,.                  .ckOo'                " << std::endl;
 std::cout <<"                                                          ;O0OKXXX000:    .':ldxkkdoc,..       ..;dOx:.                  " << std::endl;
 std::cout <<"                                                           ..........           .';ldxkkxddoddxxxxl'                     " << std::endl;
 std::cout <<"                                                                                      ..,;:::;'..                        " << std::endl;
	
	while(continuar == true)
	{
		std::cout << "\n ========== MENU PRINCIPAL==========\n ";
		std::cout << "\n 1. Jugar \n";
		std::cout << "\n 2. Instrucciones \n";
		std::cout << "\n 3.Creditos\n";
		std::cout << "\n 4. Salir\n";
		std::cout << "\n=========================================================\n";
		std::cin >> opcion;
		switch(opcion)
		{
			case 1:
			continuar = false;
			std::cout << "En caso uno";
			break;
			case 2:
			system("clear");
			std::cout << "\n ========== Instrucciones==========\n";
			std::cout << "\n 1. Tenes que mover la persona de lado a lado, vas a tener 3 vidas y $0 dinero\n";
			std::cout << "\n 2. Mientras te vas moviendo debes de recolectando los signos $ y ir jutando plata \n";
			std::cout << "\n 3. Al llegar a juntar $500, ganas \n";
			std::cout << "\n 4. En cambio durante la partida si recolectas el signo @, vas a ir perdiendo vida y plata\n";
			std::cout << "\n Si usted llega a perder la partida, se le mostrara un cartel, el cula le otrogara dos opciones \n";
			std::cout << "\n Primera opción letra S, esta dejara que usted tenga otra oportunidad para jugar. \n";
			std::cout << "\n Segunda opción es la letra N, al seleccionar esta opción ustedes volvera al menu principal. \n";
			std::cout << "\n Que tengas mucha suerte y esperamos que te diviertas \n";
			std::cout << "\n aprieta Enter para volver al menu \n";
			cin.ignore();
			cin.get();
			system("clear");
			break;

			case 3:
			system("clear");
			std::cout << "\n ========== Creditos==========\n";
			std::cout << "\n Idea: Carou Catalina\n";
			std::cout << "\n Codigo: Carou Catalina,Florencia picco y Danisa Kemptner \n";
			std::cout << "\n aprieta Enter para volver al menu \n";
			cin.ignore();
			cin.get();
			system("clear");
			break;

			case 4:
			continuar = false;
			std::cout << "\n Gracias por jugar, hasta la proxima\n";
			break;

			default:
			std::cout << "\n opcion no valida. Intenta de nuevo\n";
			break;
		}
	}
	initscr();
	refresh();
	noecho();
	curs_set(false);
	keypad(stdscr, true);
	nodelay(stdscr, true);

	// Creamos un objeto del tipo "Persona llamado "unaPersona".
	Persona unaPersona=Persona();
	Perdida perdidas[3] = { Perdida(), Perdida(), Perdida() };
	
	/*
	if (LINES < ALTO || COLS < ANCHO)
	{
		endwin();
		printf("La terminal tiene que tener como mínimo %dx%d\n\n", ANCHO, ALTO);
		exit(1);
	}
	*/
	setup();

	salir = false;

	while (!salir)
	{
		while (!game_over)
		{
			int tecla = getch();
			update(unaPersona, perdidas);
			draw(unaPersona,perdidas);
			unaPersona.input(tecla);
		}
		gameover();
	}


	cout << endl;
	endwin();
	return 0;
}

//=========================================================================
// DEFINICION DE LAS FUNCIONES GLOBALES
//=========================================================================

void setup()
{
	game_over = false;
	vidas = 3;
	dinero = 0;
}

///////////////////////////////////////////////////////////////////////////
void input(Persona unaPersona, int tecla)
{
	// Agregamos el movimiento de la nave.
	if(tecla == KEY_LEFT && unaPersona.getX() > 2)
	{
		unaPersona.setX(unaPersona.getX() - 1);
	}
	if(tecla == KEY_RIGHT && unaPersona.getX() < 75)
	{
		unaPersona.setX(unaPersona.getX() + 1);
	}
}

///////////////////////////////////////////////////////////////////////////
void update(Persona unaPersona, Perdida perdidas[])
{
	perdidas[0].update();
	perdidas[1].update();
	perdidas[2].update();
	colisionar(unaPersona, perdidas[0]);
	colisionar(unaPersona, perdidas[1]);
	colisionar(unaPersona, perdidas[2]);
	
	if (vidas <= 0) {
        game_over = true;
        }
}

///////////////////////////////////////////////////////////////////////////
void draw(Persona unaPersona, Perdida perdidas[])
{
	erase();
	//box(stdscr, 0, 0);

	// Dibujamos la persona.
	mvprintw(2, 2, "Vidas: %d", vidas);
  	mvprintw(2, 15, "Dinero: %d", dinero);
	unaPersona.draw();

	perdidas[0].draw();
	perdidas[1].draw();
	perdidas[2].draw();

	refresh();
	delay_output(DELAY);
}

///////////////////////////////////////////////////////////////////////////

void colisionar(Persona unaPersona, Perdida unaPerdida)
{
    int centroX = unaPersona.getX() + 13 / 2;  // ANCHO_PERSONAJE/2
    int centroY = unaPersona.getY() + 12 / 2;  // ALTO_PERSONAJE/2

    int px = unaPerdida.getX();
    int py = unaPerdida.getY();

    // Caja de colisión 3x3 alrededor del centro
    if (abs(px - centroX) <= 1 && abs(py - centroY) <= 1)
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
            if (vidas <= 0) game_over = true;
        }
        unaPerdida.reset(); // ahora sí se aplica al objeto real
    }
}


///////////////////////////////////////////////////////////////////////////

void gameover()
{
	for (int y = 10; y < 16; y++) mvhline(y, 40, ' ', 40);

	mvaddch(9, 39, ACS_ULCORNER);
	mvaddch(9, 80, ACS_URCORNER);
	mvaddch(16, 39, ACS_LLCORNER);
	mvaddch(16, 80, ACS_LRCORNER);
	mvhline(9, 40, ACS_HLINE, 40);
	mvhline(16, 40, ACS_HLINE, 40);
	mvvline(10, 39, ACS_VLINE, 6);
	mvvline(10, 80, ACS_VLINE, 6);

	mvprintw(12, 55, "GAME OVER");
	mvprintw(13, 50, "VOLVER A JUGAR? (S/N)");

	int opcion = getch();

	if (opcion == 's' || opcion == 'S')
	{
		setup();
	}
	else if (opcion == 'n' || opcion == 'N')
	{
		salir = true;
	}
}