// interfaces/SimulationInterface.h
#ifndef SIMULATIONINTERFACE_H
#define SIMULATIONINTERFACE_H

#include "Grid.h"

/**
 * @brief Classe de base abstraite pour les interfaces de simulation.
 *
 * Cette classe d�finit une interface commune pour diff�rentes impl�mentations
 * de l'interface utilisateur de la simulation (console, graphique, etc.).
 */
class SimulationInterface {
public:
    virtual ~SimulationInterface() = default;

    /**
     * @brief Ex�cute la simulation.
     *
     * @param grid R�f�rence vers la grille de simulation.
     * @param delay D�lai entre chaque it�ration en millisecondes.
     * @param maxIterations Nombre maximal d'it�rations (0 pour infini).
     */
    virtual void run(Grid& grid, int delay, int maxIterations) = 0;
};

#endif // SIMULATIONINTERFACE_H
