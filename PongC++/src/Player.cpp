#include "Player.h"

Player::Player(Renderer* renderer, Vector2<int>& pos, Vector2<int>& dimensions)
{
	//Initialize the renderer ref
	m_RendererPtr = renderer;

	//position player in the world
	m_pos = pos;
	m_dimension = dimensions;

	//Create the player rect
	m_Player_rect = {
		m_pos.x,
		m_pos.y,
		m_dimension.x,
		m_dimension.y
	};
}

void Player::Move(int deltaY)
{
	m_pos.y += deltaY;

	//modify the player rect according to the updated position. But the dimension will remain the same
	m_Player_rect = {
		m_pos.x,
		m_pos.y,
		m_dimension.x,
		m_dimension.y
	};
}

void Player::Shoot()
{
	//Implementation needs the ball's reference, so blank for now.
}

void Player::RenderPlayer()
{
	SDL_Renderer* rendererPtr = m_RendererPtr->GetRendererPtr();

	//Fill Color
	SDL_SetRenderDrawColor(rendererPtr, 100, 3, 20, 255);

	//Draw a rectangle for the player
	SDL_RenderDrawRect(rendererPtr, &m_Player_rect);
	SDL_RenderFillRect(rendererPtr, &m_Player_rect);
}

