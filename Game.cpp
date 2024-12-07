// services/Game.cpp
#include "Game.h"
#include "Console.h"
#include "Graphics.h"
#include <iostream>
#include <string>
#include <memory>

using namespace std;

void Game::run() {
    int rows = 25;
    int cols = 25;
    int cellSize = 19;
    int maxIterations = 0;
    int delay = 500; // Temps d'attente en millisecondes pour ralentir les it�rations
    string mode;
    string filename;

    cout << "Choisissez le mode (console ins�rez C et pour le mode graphique ins�rez G) : ";
    cin >> mode;

    if (mode != "C" && mode != "G") {
        cout << "Mode invalide, veuillez red�marrer et choisir 'C' ou 'G'." << endl;
        return;
    }

    cout << "Entrez le d�lai entre chaque it�ration en millisecondes (par d�faut 500 ms) : ";
    cin >> delay;

    Grid grid(rows, cols);

    // Utilisation de std::unique_ptr pour la gestion de la m�moire
    unique_ptr<SimulationInterface> interface;

    if (mode == "G") {
        cout << "Entrez le nombre d'it�rations (0 pour une simulation infinie) : ";
        cin >> maxIterations;

        interface = make_unique<GraphicsInterface>();
    }
    else if (mode == "C") {
        cout << "Entrez le nom du fichier pour initialiser la grille (ou appuyez sur Entr�e pour cr�er une grille vide) : ";
        cin.ignore(); // Pour ignorer le caract�re de nouvelle ligne restant dans le buffer
        getline(cin, filename);

        try {
            if (!filename.empty()) {
                grid.initializeFromInput(filename);
            }
        }
        catch (const runtime_error& e) {
            cout << "Erreur : " << e.what() << endl;
            return;
        }

        interface = make_unique<ConsoleInterface>();
    }

    if (interface) {
        interface->run(grid, delay, maxIterations);
    }
}
