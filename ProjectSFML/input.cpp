#include "input.h"

// Contructeur
Input::Input() 
{
	//Ils sont par d�fault false
	button.left = button.right = button.up = button.down = button.escape = false;
}
//Fonction qui acc�de � button (struc) et nous donne l'info private
Input::Button Input::GetButton(void) const
{
	return button;
}
void Input::InputHandler(Event event, RenderWindow& window)
{
	//Fermer la fen�tre si on clique sur la croix (Closed)
	if (event.type == Event::Closed)
	{
		window.close();
	}
	//Gestion des inputs (appuy�s)
	if (event.type == Event::KeyPressed)
	{	
		// Essaye toute les possibilit�s avec le switch sur quel touche on a appuy�
		switch (event.key.code) // Code de la touche utilis�e
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
		// Si touche ralach� (Released)
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