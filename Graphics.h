// interfaces/Graphics.h
#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "SimulationInterface.h"
#include "Grid.h"
#include "Button.h"
#include <SFML/Graphics.hpp>
#include <string>

/**
 * @brief Interface graphique pour la simulation utilisant SFML.
 *
 * Cette classe g�re l'affichage de la grille, les boutons interactifs,
 * et les interactions utilisateur via une fen�tre graphique.
 */
class GraphicsInterface : public SimulationInterface {
public:
    /**
     * @brief Ex�cute la simulation en mode graphique.
     *
     * @param grid R�f�rence vers la grille de simulation.
     * @param delay D�lai entre chaque it�ration en millisecondes.
     * @param maxIterations Nombre maximal d'it�rations (0 pour infini).
     */
    void run(Grid& grid, int delay, int maxIterations) override;
};

#endif // GRAPHICS_H
