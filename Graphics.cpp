// interfaces/Graphics.cpp
#include "Graphics.h"
#include <iostream>
#include <thread>
#include <chrono>

void GraphicsInterface::run(Grid& grid, int delay, int maxIterations) {
    int rows = grid.getRows();
    int cols = grid.getCols();
    int cellSize = 19; // Taille des cellules (doit correspondre � celle utilis�e dans Grid)

    sf::RenderWindow window(sf::VideoMode(cols * cellSize, rows * cellSize + 100), "Jeu de la Vie");

    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Erreur lors du chargement de la police" << std::endl;
        return;
    }

    Button startButton(10, rows * cellSize + 10, 150, 40, font, "D�marrer", sf::Color::Green);
    Button stopButton(170, rows * cellSize + 10, 150, 40, font, "Arr�ter", sf::Color::Red);
    Button undoButton(330, rows * cellSize + 10, 150, 40, font, "Annuler", sf::Color::Blue);

    bool simulationRunning = false;
    CellState currentState = VIVANT; // Commencer avec l'�tat 'VIVANT'
    int iterationsCount = 0;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    if (startButton.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                        simulationRunning = true;   // D�marrer la simulation
                        startButton.setColor(sf::Color::Red);
                        stopButton.setColor(sf::Color::Green);
                    }
                    if (stopButton.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                        simulationRunning = false;  // Arr�ter la simulation
                        startButton.setColor(sf::Color::Green);
                        stopButton.setColor(sf::Color::Red);
                    }
                    if (undoButton.isClicked(event.mouseButton.x, event.mouseButton.y)) {
                        simulationRunning = false;  // Arr�ter la simulation
                        startButton.setColor(sf::Color::Green);  // R�initialiser l'�tat des boutons
                        stopButton.setColor(sf::Color::Red);
                        grid.undo();  // Restaurer l'�tat pr�c�dent de la grille
                    }
                    grid.toggleCell(event.mouseButton.x, event.mouseButton.y, cellSize, currentState); // Basculer l'�tat de la cellule
                }
                else if (event.mouseButton.button == sf::Mouse::Right) {
                    grid.toggleCell(event.mouseButton.x, event.mouseButton.y, cellSize, OBSTACLE); // Ajouter un obstacle
                }
            }

            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::V) {
                    currentState = VIVANT;
                }
                else if (event.key.code == sf::Keyboard::D) {
                    currentState = VIDE;
                }
                else if (event.key.code == sf::Keyboard::O) {
                    currentState = OBSTACLE;
                }
            }
        }

        if (simulationRunning) {
            grid.update();
            iterationsCount++;

            // V�rification si la simulation doit �tre arr�t�e
            if (maxIterations > 0 && iterationsCount >= maxIterations) {
                // Arr�ter la simulation apr�s le nombre d'it�rations maximum
                simulationRunning = false;
                startButton.setColor(sf::Color::Green);
                stopButton.setColor(sf::Color::Red);
            }
            else if (grid.hasStableState()) {
                // Arr�ter la simulation si la grille est stable
                simulationRunning = false;
                startButton.setColor(sf::Color::Green);
                stopButton.setColor(sf::Color::Red);
                std::cout << "La grille a atteint un �tat stable. Fin de la simulation." << std::endl;
            }
        }

        window.clear();
        grid.draw(window, cellSize);
        startButton.draw(window);
        stopButton.draw(window);
        undoButton.draw(window);

        // Affichage du nombre d'it�rations effectu�es
        sf::Text iterationsText;
        iterationsText.setFont(font);
        iterationsText.setCharacterSize(18);
        iterationsText.setFillColor(sf::Color::Black);
        iterationsText.setPosition(10, rows * cellSize + 50);
        iterationsText.setString("Iterations: " + std::to_string(iterationsCount));
        window.draw(iterationsText);

        window.display();
        std::this_thread::sleep_for(std::chrono::milliseconds(delay));
    }
}
