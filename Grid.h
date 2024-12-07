// components/Grid.h
#ifndef GRID_H
#define GRID_H

#include "Cellule.h"
#include <vector>
#include <stack>
#include <string>
#include <SFML/Graphics.hpp>

/**
 * @brief Classe repr�sentant la grille de simulation.
 *
 * Cette classe g�re l'�tat de chaque cellule, les mises � jour de la grille,
 * les op�rations d'annulation, et le dessin de la grille dans l'interface graphique.
 */
class Grid {
private:
    std::vector<std::vector<CellState>> cells;
    std::stack<std::vector<std::vector<CellState>>> history; // Pile pour stocker les �tats pr�c�dents
    int rows;
    int cols;

    /**
     * @brief Compte le nombre de voisins vivants autour d'une cellule.
     *
     * @param x Position X de la cellule.
     * @param y Position Y de la cellule.
     * @return int Nombre de voisins vivants.
     */
    int countLivingNeighbors(int x, int y);

    /**
     * @brief Sauvegarde l'�tat actuel de la grille dans l'historique.
     */
    void saveState();

public:
    /**
     * @brief Constructeur de la grille.
     *
     * @param r Nombre de lignes.
     * @param c Nombre de colonnes.
     */
    Grid(int r, int c);

    /**
     * @brief Initialise la grille � partir d'un fichier.
     *
     * @param filename Nom du fichier contenant la configuration initiale.
     */
    void initializeFromInput(const std::string& filename);

    /**
     * @brief Met � jour la grille selon les r�gles de la simulation.
     */
    void update();

    /**
     * @brief Annule la derni�re mise � jour de la grille.
     */
    void undo();

    /**
     * @brief V�rifie si la grille a atteint un �tat stable.
     *
     * @return true Si la grille est stable.
     * @return false Sinon.
     */
    bool hasStableState() const;

    /**
     * @brief Dessine la grille dans une fen�tre SFML.
     *
     * @param window R�f�rence � la fen�tre SFML.
     * @param cellSize Taille de chaque cellule en pixels.
     */
    void draw(sf::RenderWindow& window, int cellSize) const;

    /**
     * @brief Bascule l'�tat d'une cellule en fonction des coordonn�es de la souris.
     *
     * @param mouseX Position X de la souris.
     * @param mouseY Position Y de la souris.
     * @param cellSize Taille de chaque cellule en pixels.
     * @param state Nouvel �tat � attribuer � la cellule.
     */
    void toggleCell(int mouseX, int mouseY, int cellSize, CellState state);

    /**
     * @brief Affiche la grille dans la console.
     */
    void print() const;

    // Getters
    int getRows() const { return rows; }
    int getCols() const { return cols; }
};

#endif // GRID_H
