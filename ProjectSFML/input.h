/*Permet de définir INPUT_H*/
#ifndef INPUT_H
/*Permet de faire un IF*/
#define INPUT_H

#include <SFML/Graphics.hpp>
/*Permet d'utiliser la fonction de la SFML sans taper = sf::eeee*/
using namespace sf;

class Input
{
/*Structure booléen qui permet de savoir si l'utilisateur appuye sur les 5 touches où pas*/
	struct Button { bool left, right, up, down, escape; };

/* Pour déterminer ce qui est public*/
public:
	//Proto du constructeur
	Input();
	//Porots
	Button GetButton(void) const;
	//Permet de gérer l'état du button
	void InputHandler(Event event, RenderWindow& window);
/*Permet de déterminer ce qui est privée*/
private:
	Button button;
};

#endif 