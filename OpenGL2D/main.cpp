#include "stdafx.h"
#include "InputHandler.h"
#include "Renderer.h"
#include "Sprite.h"
#include "Map.h"
#include "../3rd-party/freeglut3/include/GL/freeglut.h"
#include "Tank.h"
#include "CollisionHandler.h"
#include "TankEnemy.h"



int main(int argc, char** argv)
{
	Renderer renderer;
	InputHandler inputHandler(renderer);
	CollisionHandler collisionHandler;

	renderer.initialize(argc, argv);
	inputHandler.initialize();


	//We create a tank
	Tank *tank = new Tank();

	tank->setColor(255,0,0);
	tank->setPosition(0,0);
	tank->setSize(0.02);
	tank->setRotation(0);
	tank->setDepth(1.5);

	tank->setName("tank1");
	tank->setVel(0,0);

	renderer.addObject(tank);

	//We create a tank 2
	TankEnemy *tank2 = new TankEnemy();

	tank2->setColor(0, 0, 255);
	tank2->setPosition(0.5, 0);
	tank2->setSize(0.02);
	tank2->setRotation(0);
	tank2->setDepth(1.5);

	tank2->setName("tank2");
	tank2->setVel(0, 0);

	renderer.addObject(tank2);

	Map map("Map1.txt");
	while (1)
	{
		//UPDATE////////////////////
		////////////////////////////
		//process queued events
		glutMainLoopEvent();

	/*	std::vector<Drawable> vectorObjects = renderer.getVector();
		for each (Drawable var in vectorObjects)
		{
			Sprite theObject = (Sprite)var;
		}
		tank->tick();*/

		//RENDER////////////////////
		////////////////////////////
		glutPostRedisplay();
		glutSwapBuffers();
	}
   
	return 0;

}