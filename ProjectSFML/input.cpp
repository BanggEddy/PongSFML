#include "input.h"

// Contructeur
Input::Input() 
{
	//Ils sont par défault false
	button.left = button.right = button.up = button.down = button.escape = false;
}
//Fonction qui accède à button (struc) et nous donne l'info private
Input::Button Input::GetButton(void) const
{
	return button;
}
void Input::InputHandler(Event event, RenderWindow& window)
{
	//Fermer la fenêtre si on clique sur la croix (Closed)
	if (event.type == Event::Closed)
	{
		window.close();
	}
	//Gestion des inputs (appuyés)
	if (event.type == Event::KeyPressed)
	{	
		// Essaye toute les possibilités avec le switch sur quel touche on a appuyé
		switch (event.key.code) // Code de la touche utilisée
		{
			//Si claivier :: truc, alors le truc deviens true
			case Keyboard::Escape:
				button.escape = true;
				break;
			case Keyboard::Left:
				button.left = true;
				break;
			case Keyboard::Right:
				button.right = true;
				break;
			case Keyboard::Down:
				button.down = true;
				break;
			case Keyboard::Up:
				button.up = true;
				break;
			default:
				break;
		}
		// Si touche ralaché (Released)
		if (event.type == Event::KeyReleased)
		{
			switch (event.key.code)
			{
			case Keyboard::Escape:
				button.escape = false;
				break;
			case Keyboard::Left:
				button.left = false;
				break;
			case Keyboard::Right:
				button.right = false;
				break;
			case Keyboard::Down:
				button.down = false;
				break;
			case Keyboard::Up:
				button.up = false;
				break;
			default:
				break;
			}
		}
	}
}