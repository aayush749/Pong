#pragma once

#include "Core_Components.h"

class Player
{
public:
	
	//Ctor
	Player(Renderer* renderer, Vector2<int>& pos, Vector2<int>& dimensions);


	/*
	Player shall move only up or down
	1. deltaY will be negative for moving up.
	2. deltaY will be positve for moving down.
	Because origin of screen is in the top left corner of the window.
	*/ 
	void Move(int deltaY);
	
	//Player will shoot only once
	void Shoot();

	//Render functions
	void RenderPlayer();

	//Dtor
	~Player()
	{
		//Nothing here because player doesnot hold any such data
	}

private:
	Renderer* m_RendererPtr;
	Vector2<int> m_pos;
	Vector2<int> m_dimension;

	SDL_Rect m_Player_rect;
};

