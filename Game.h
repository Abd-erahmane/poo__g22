// services/Game.h
#ifndef GAME_H
#define GAME_H

#include "Grid.h"
#include "SimulationInterface.h"
#include <memory> // Pour std::unique_ptr

/**
 * @brief Classe principale contr�lant le flux de l'application.
 *
 * Cette classe g�re la s�lection du mode d'interface (console ou graphique),
 * l'initialisation de la grille, et l'ex�cution de la simulation via
 * l'interface s�lectionn�e.
 */
class Game {
public:
    /**
     * @brief Ex�cute le jeu.
     */
    void run();
};

#endif // GAME_H
