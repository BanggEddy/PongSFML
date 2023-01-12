//Includes
#include <iostream>
#include <SFML/Graphics.hpp>
#include "input.h"

// Constantes du programme
const int WIN_WIDTH = 800;
const int WIN_HEIGHT = 600;

//Namespaces
using namespace sf;
using namespace std;

//Prototypes
//Afficher le score des joueurs
void SetText(Text& txt, String str);
//Détecter les touches utilisés par le joueur
void CheckBtn();