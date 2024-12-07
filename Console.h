// interfaces/Console.h
#ifndef CONSOLE_H
#define CONSOLE_H

#include "SimulationInterface.h"
#include <string>

/**
 * @brief Interface console pour la simulation.
 *
 * Cette classe g�re l'affichage et la mise � jour de la grille dans la console.
 */
class ConsoleInterface : public SimulationInterface {
public:
    /**
     * @brief Ex�cute la simulation en mode console.
     *
     * @param grid R�f�rence vers la grille de simulation.
     * @param delay D�lai entre chaque it�ration en millisecondes.
     * @param maxIterations Nombre maximal d'it�rations (0 pour infini).
     */
    void run(Grid& grid, int delay, int maxIterations) override;
};

#endif // CONSOLE_H
