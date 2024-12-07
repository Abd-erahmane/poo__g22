// interfaces/Console.cpp
#include "Console.h"
#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

void ConsoleInterface::run(Grid& grid, int delay, int maxIterations) {
    int iterationsCount = 0;
    while (maxIterations == 0 || iterationsCount < maxIterations) {
        grid.print();
        grid.update();
        iterationsCount++;

        // V�rifier si l'automate est stable
        if (grid.hasStableState()) {
            cout << "La grille a atteint un �tat stable. Fin de la simulation." << endl;
            break;
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }

    cout << "Simulation termin�e apr�s " << iterationsCount << " it�rations." << endl;
}
