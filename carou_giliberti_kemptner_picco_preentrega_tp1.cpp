#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // Para usar sleep()

using namespace std;

// Enumeración para las opciones del menú
enum MenuOpciones { JUGAR = 1, INSTRUCCIONES, CREDITOS, SALIR };

// Prototipos de funciones
void mostrarTitulo();
void mostrarMenu();
void mostrarInstrucciones();
void mostrarCreditos();
void iniciarJuego();
void mostrarPregunta(const string& pregunta, const string opciones[], int respuestaCorrecta, int& vidas, bool& respuestaCorrectaFlag);
void dibujarEscenario(int puertaActual, int vidas);

int main() {
    int opcion;
    bool continuar = true;

    while (continuar) {
        system("clear"); // Limpia pantalla (en Windows usar "cls")
        mostrarTitulo();
        mostrarMenu();

        cout << "\nElige una opción: ";
        cin >> opcion;

        switch (opcion) {
            case JUGAR:
                iniciarJuego();
                break;
            case INSTRUCCIONES:
                mostrarInstrucciones();
                break;
            case CREDITOS:
                mostrarCreditos();
                break;
            case SALIR:
                continuar = false;
                cout << "\n¡Gracias por jugar! Hasta pronto.\n";
                break;
            default:
                cout << "\nOpción no válida. Intenta de nuevo.\n";
                sleep(2);
                break;
        }
    }

    return 0;
}

void mostrarTitulo() {
    std::cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░░███░░░░░░███████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░███░░░░░░░░░░░░░░████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░███░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░███████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████████████████████░░░░░░░░░░░░░░░░░░░░░░████████████░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░███████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████████████░░░░░░░░░░░░░░░░░░░░██████████░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░███████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░██████████████████░░░░░░░░░░░░█████░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░██████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████████████████░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░░░████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░░░░░████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░███████████████████████████░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░░░░██████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░█████████████████████████████░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░░░░████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████████████████░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░░░████░░░███░░███░░░░███░░░███████░░░███░░░░░░███░░░░░███░░█████░░░░░░░███░░███░░░████░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░░████░░░███░░░░░██░███░░░░███████░░░███░░░░░░████░░░░███░░███░███░░░░░███░░███░░░████░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░████░░░███░░░░░░░███░░░░░████░░░░░░███░░░░░░███░░█░░███░░███░░░███░░░███░░███░░░████░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░████░░░███░░░░░░████░░░░░███████░░░███░░░░░░███░░░█░███░░█████████░░░███░░███░░░████░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░████░░░███░░░░░███░░██░░░████░░░░░░███░░░░░░███░░░░░███░░███░░░░███░░███░░███░░░████░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░████░░░███░░░░███░░░░░██░████████░░████████░███░░░░░███░░███░░░░███░░████████░░░████░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░░██████████████████████████████████████████████████████████████████████████████████████████░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████████████░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░█░░░░░░░░░░░░░░░░░░░░░░░░░░████████████████████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░█░░░░░░░░░░░░░██████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;
    std::cout << "░░░░░░░░█████████████░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░" << std::endl;

    }

void mostrarMenu() {
    cout << "\nMENÚ PRINCIPAL:\n";
    cout << "1. Jugar\n";
    cout << "2. Instrucciones\n";
    cout << "3. Créditos\n";
    cout << "4. Salir\n";
}

void mostrarInstrucciones() {
    system("clear");
    mostrarTitulo();
    cout << "\nINSTRUCCIONES:\n";
    cout << "1. Responde correctamente las preguntas para avanzar por las puertas.\n";
    cout << "2. Si fallas, perderás una vida. Pierdes el juego al perder las 3 vidas.\n";
    cout << "3. ¡Buena suerte y diviértete!\n";
    cout << "\nPresiona ENTER para volver al menú...";
    cin.ignore();
    cin.get();
}

void mostrarCreditos() {
    system("clear");
    mostrarTitulo();
    cout << "\nCRÉDITOS:\n";
    cout << "1. Idea: Carou, Picco.\n";
    cout << "2. Diseño: Giliberti, Kemptner.\n";
    cout << "3. Organización: como se pudo.\n";
    cout << "4. Código: Carou, Giliberti, Kemptner, Picco.\n";
    cout << "5. Participantes: Carou Catalina, Giliberti Leonardo Carlo, Kemptner Danisa, Picco Florencia Ayelen.\n";
    cout << "\nPresiona ENTER para volver al menú...";
    cin.ignore();
    cin.get();
}

void iniciarJuego() {
    system("clear");
    mostrarTitulo();
    cout << "\n¡Bienvenido a la aventura! Responde correctamente para avanzar.\n";

    int vidas = 3;
    int puertaActual = 1;
    bool jugando = true;

    string preguntas[] = {
        "¿Qué es un compilador?",
        "¿Cuál es el propósito del comando \"chmod\" en LINUX?",
        "¿Qué es el Creative Coding?",
        "¿Qué herramienta de código abierto es usada para arte digital en LINUX?"
    };

    string opciones[4][4] = {
        { "1. Ejecuta código línea por línea", "2. Combierte el código fuente a lenguaje de máquina", "3. Comprueba la ortografía del código", "4. Administra memoria RAM" },
        { "1. Cambiar la fecha del sistema", "2. Modificar permisos de archivos", "3. Editar archivos de audio", "4. Crear una partición" },
        { "1. Código para comercio electrónico", "2. Programación para aplicaciones bancarias", "3. Uso de código como medio creativo", "4. Código sin errores" },
        { "1. Photoshop", "2. GIMP", "3. Illustrator", "4. Paint.NET" }
    };

    int respuestasCorrectas[] = { 3, 2, 3, 2 }; // Opción correcta (1-4)

    while (jugando) {
        system("clear");
        dibujarEscenario(puertaActual, vidas);

        bool respuestaCorrectaFlag = false;
        mostrarPregunta(preguntas[puertaActual - 1], opciones[puertaActual - 1], respuestasCorrectas[puertaActual - 1], vidas, respuestaCorrectaFlag);

        if (respuestaCorrectaFlag) {
            puertaActual++;
            if (puertaActual > 4) {
                cout << "\n¡Felicidades! Has completado la aventura.\n";
                jugando = false;
            }
        } else {
            if (vidas <= 0) {
                cout << "\n¡Has perdido todas tus vidas! El juego se reiniciará.\n";
                sleep(3);
                return;
            }
        }
    }

    cout << "\nVolviendo al menú principal...\n";
    sleep(3);
}

void mostrarPregunta(const string& pregunta, const string opciones[], int respuestaCorrecta, int& vidas, bool& respuestaCorrectaFlag) {
    cout << "\nPregunta: " << pregunta << "\n";
    for (int i = 0; i < 4; i++) {
        cout << opciones[i] << "\n";
    }

    int respuesta;
    cout << "\nElige una opción (1-4): ";
    cin >> respuesta;

    if (respuesta == respuestaCorrecta) {
        cout << "\n¡Correcto! Avanzaste a la siguiente puerta.\n";
        respuestaCorrectaFlag = true;
    } else {
        cout << "\nIncorrecto. Pierdes 1 vida.\n";
        vidas--;
        respuestaCorrectaFlag = false;
    }

    sleep(2);
}

void dibujarEscenario(int puertaActual, int vidas) {
    cout << "\n=========================================\n";
    cout << "                ESCENARIO                \n";
    cout << "=========================================\n";
    cout << "|                                       |\n";
    cout << "|        Puerta actual: " << puertaActual << "                     |\n";
    cout << "|        Vidas restantes: " << vidas << "                   |\n";
    cout << "|                                       |\n";
    cout << "=========================================\n";
}