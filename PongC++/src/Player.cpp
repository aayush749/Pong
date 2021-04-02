#include "Player.h"

Player::Player(Renderer* renderer, Vector2<int>& pos, Vector2<int>& dimensions)
{
	//Initialize the renderer ref
	m_RendererPtr = renderer;

	//position player in the world
	m_pos = pos;
	m_dimension = dimensions;

	//This will initialize the player rect data
	UpdateRectData();
}

void Player::Move(int deltaY)
{
	m_pos.y += deltaY;
}

void Player::Shoot()
{
	//Implementation needs the ball's reference, so blank for now.
}

void Player::Render()
{
	SDL_Renderer* rendererPtr = m_RendererPtr->GetRendererPtr();

	//Fill Color
	SDL_SetRenderDrawColor(rendererPtr, 100, 3, 20, 255);

	//Get the latest updated positions, and update the rect data
	UpdateRectData();

	//Draw a rectangle for the player
	SDL_RenderDrawRect(rendererPtr, &m_Player_rect);
	SDL_RenderFillRect(rendererPtr, &m_Player_rect);
}

void Player::UpdateRectData()
{
	m_Player_rect = {
		m_pos.x,
		m_pos.y,
		m_dimension.x,
		m_dimension.y
	};
}