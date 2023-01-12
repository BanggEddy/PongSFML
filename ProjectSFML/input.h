/*Permet de d�finir INPUT_H*/
#ifndef INPUT_H
/*Permet de faire un IF*/
#define INPUT_H

#include <SFML/Graphics.hpp>
/*Permet d'utiliser la fonction de la SFML sans taper = sf::eeee*/
using namespace sf;

class Input
{
/*Structure bool�en qui permet de savoir si l'utilisateur appuye sur les 5 touches o� pas*/
	struct Button { bool left, right, up, down, escape; };

/* Pour d�terminer ce qui est public*/
public:
	//Proto du constructeur
	Input();
	//Porots
	Button GetButton(void) const;
	//Permet de g�rer l'�tat du button
	void InputHandler(Event event, RenderWindow& window);
/*Permet de d�terminer ce qui est priv�e*/
private:
	Button button;
};

#endif 