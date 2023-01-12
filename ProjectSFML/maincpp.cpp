#include "main.h";

//Variables
//La fen�tre du jeu
RenderWindow window;
//Pour la gestion des inputs
Input input;
//Pour stocker la fonte
Font font;
//Pour stocker le texte
Text txt;

//26:40

// Pos raquettes 1
//Se place � 50 pixels d'�cal� vers la droite de l'�cran � gauche pour pas qu'il se colle
int posRaquettesLeftX = 50;
//
int posRaquettesRightX = WIN_WIDTH /*800 - 70*/ - 70 /*prsk raquettesWidth+posRaquettesLeftX = 50+20 */;
int posRaquettesLeftY = WIN_HEIGHT / 2;
int posRaquettesRightY = posRaquettesLeftY;
//Vitesse de la raquette
int raquettesSpeed = 5;
//Hauteur de la raquette
int raquettesHeight = 150;
//Largeur de la raquette
int raquettesWidth = 20;

//Infos balles
float ballSpeed = 0.8; //Variable pour la vitesse
Vector2f ballDir = Vector2f(1.5f, 2.0f); //Mouvement de la ball
float ballPosX = WIN_WIDTH / 2; //Position X de la ball au d�but
float ballPosY = WIN_HEIGHT / 2; //Position Y de la ball au d�but

//Stocker le score
int scoreJ1 = 0;
int scoreJ2 = 0;

void RaquetteIA () {
	posRaquettesRightY = ballPosY;
}

void UpdateBall() {
	// Pos ball
	ballPosX += ballDir.x * ballSpeed;
	ballPosY += ballDir.y * ballSpeed;

	//Collisions ball
	//Raquette gauche touch�e?
	if ((ballPosX < posRaquettesLeftX + raquettesWidth &&
		ballPosX > posRaquettesLeftX &&
		ballPosY < posRaquettesLeftY + raquettesHeight &&
		ballPosY > posRaquettesLeftY)
		||
		//Raquette droite touch�e?
		(ballPosX > posRaquettesRightX - raquettesWidth &&
			ballPosX < posRaquettesRightX &&
			ballPosX < posRaquettesRightY + raquettesHeight &&
			ballPosY > posRaquettesRightY))
	{
		ballDir.x *= -1;
	}
	// mur gauche
	if (ballPosX < 0)
	{
		scoreJ2++;
		//Recentre la balle
		ballPosX = WIN_WIDTH / 2;
		ballPosY = WIN_HEIGHT / 2;
		ballDir.x = fabs(ballDir.x);
		ballDir.y *= -1;
		SetText(txt, std::to_string(scoreJ1) + "|" + std::to_string(scoreJ2));

	}
	// mur droite
	if (ballPosX > WIN_WIDTH)
	{
		scoreJ1++;
		ballPosX = WIN_WIDTH / 2;
		ballPosY = WIN_HEIGHT / 2;
		ballDir.x = - fabs(ballDir.x);
		ballDir.y *= -1;
		SetText(txt, std::to_string(scoreJ1) + "|" + std::to_string(scoreJ2));
	}
	// mur haut ou bas
	if (ballPosY > WIN_HEIGHT || ballPosY < 0) {
		ballDir.y *= -1;
	}
}

//Fonction main
int main() //30:50
{
	//Cr�ation d'une fen�tre type RenderWindow(Fen�tre cr�� par l'SFML)
	window.create(VideoMode(WIN_WIDTH/*largeur*/, WIN_HEIGHT/*longueur*/, 32/*Taille en bits*/), "Pong SFML C++" /*Titre du projet*/, Style::Default);
	//Chargement fonte
	font.loadFromFile("res/Poppins-Bold.otf");
	//On r�gle toutes les propri�t�s de celui-ci
	SetText(txt, to_string(scoreJ1) + " | " + to_string(scoreJ2));

	//Pr�paration des formes
	//Balle
	CircleShape circleShape(15); // Circle de rayon 15
	circleShape.setPosition(ballPosX, ballPosY); //D�finis la position de la ball sur l'�cran
	// Raquette gauche
	RectangleShape rectangleShape(Vector2f(raquettesWidth, raquettesHeight)); //Cr�ation de la raquette avec la L et la l de la raquette
	rectangleShape.setPosition(posRaquettesLeftX, posRaquettesLeftY); //Position la raquette sur l'�cran
	// Raquette droite
	RectangleShape rectangleShape2(Vector2f(raquettesWidth, raquettesHeight));
	rectangleShape2.setPosition(posRaquettesRightX, posRaquettesRightY);

	//Boucle qui tourne tant que la fen�tre est ouverte
	while (window.isOpen())
	{
		Event event; // Variable pour g�rer l'�v�nement
		// On boucle sur les �v�nements
		while (window.pollEvent(event))
		{
			//Gestion des inputs / events
			input.InputHandler(event, window); //Appel notre fonction pour fermer
		}
		//Gestion clavier
		CheckBtn();
		//IA
		RaquetteIA();
		//Position raquettes, balle
		rectangleShape.setPosition(posRaquettesLeftX, posRaquettesLeftY);
		rectangleShape2.setPosition(posRaquettesRightX, posRaquettesRightY);

		//Update ball
		UpdateBall();
		circleShape.setPosition(ballPosX, ballPosY); //Position la ball 
		//Couleur de la fen�tre en noir
		window.clear(Color::Black);
		// C'est ici que l'on dessine les �l�ments du jeu
		window.draw(txt);
		window.draw(circleShape);
		window.draw(rectangleShape);
		window.draw(rectangleShape2);
		///Dessiner � l'�cran tous les �l�ments
		window.display();
	}
	//Fin du programme
	return 0;
}

void SetText(Text& txt, String str) 
{
	//On lui indique quelle police utiliser
	txt.setFont(font);
	//On indique la cha�ne de caract�res � afficher
	txt.setString(str);
	//On indique la taille de la police d'�criture
	txt.setCharacterSize(26);
	// On donne la couleur
	txt.setFillColor(Color::White);
	//Pos
	txt.setPosition((WIN_WIDTH /*largeur de la fen�tre */ / 2) - 40, 10/*d�cale le txt de 10p*/);

}

void CheckBtn()
{
	//Raquette gauche
	if (input.GetButton().up == true)/*Si l est true*/ {
		posRaquettesLeftY -= raquettesSpeed; //Diminuer la position de la raquette pour la faire monter
		if (posRaquettesLeftY < 0)
			posRaquettesLeftY = 0;
	}
	if (input.GetButton().down ==true)
	{
		posRaquettesLeftY += raquettesSpeed; //Augmenter la position de la raquette pour la faire descendre
		if (posRaquettesLeftY + raquettesHeight > WIN_HEIGHT)
			posRaquettesLeftY = WIN_HEIGHT - raquettesHeight; //Si c'est le cas, bloqu�e la hauteur de la raquette pour pas d�passer la limite(sortira de l'�cran)
	}
	//Raquette droite
	if (input.GetButton().left == true)
	{
		posRaquettesRightY -= raquettesSpeed;
		if (posRaquettesRightY < 0)
			posRaquettesRightY = 0;
	}
	if (input.GetButton().right == true)
	{
		posRaquettesRightY += raquettesSpeed; //Augmenter la position de la raquette pour la faire descendre
		if (posRaquettesRightY + raquettesHeight > WIN_HEIGHT)
			posRaquettesRightY = WIN_HEIGHT - raquettesHeight;
	}
	if (input.GetButton().escape == true)
	{
		window.close();
	}
	//42.16
}