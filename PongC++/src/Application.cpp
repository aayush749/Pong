#include "Core_Components.h"
#include "Player.h"
#include "Ball.h"

//Globals
int game_is_running = FALSE;

void Start(Renderer&), ProcessInput(Player&), Update(Ball&, Player&), Render(Renderer&, Player&, Ball&), ManageKeyBoardInput(SDL_Event& event, Player&);

int main()
{
	std::cout << "Initializing renderer\n";
	Renderer renderer;
	
	//Ball Data
	Vector2<int> ballPos = { WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2 };
	Vector2<int> ballDimension = { 10, 10 };
	Vector2<int> initialVelocity = { 5, 5 };

	Ball ball(&renderer, ballPos, ballDimension, initialVelocity);


	//Player Data
	Vector2<int> playerPos = { 0, WINDOW_HEIGHT / 2 };
	Vector2<int> playerDimension = { 30, 70 };

	Player player(&renderer, playerPos, playerDimension, &ball);

	


	Start(renderer);


	while (game_is_running)
	{
		ProcessInput(player);
		Update(ball, player);
		Render(renderer, player, ball);
	}
	return 0;
}

void Start(Renderer& renderer)
{
	renderer.FillScreen(0, 0, 255, 255);
}

void ProcessInput(Player& player)
{
	SDL_Event event;
	SDL_PollEvent(&event);

	//TODO: May add confirmation to quit game as a win32 api dialog box
	switch (event.type)
	{

	case SDL_QUIT:
		game_is_running = false;
		printf("Closing game!\n");
		break;

	case SDL_KEYDOWN:
		ManageKeyBoardInput(event, player);
		break;

	}
}

void Update(Ball& ball, Player& player)
{
	SDL_Delay(FRAME_TARGET_TIME);
	ball.Move();
	player.CheckCollisionsWithBall();
}

void Render(Renderer& renderer, Player& player, Ball& ball)
{
	renderer.FillScreen(0, 155, 20, 255);
	player.Render();
	ball.Render();
	renderer.SwapBuffers();
}

void ManageKeyBoardInput(SDL_Event& event, Player& player)
{
	switch (event.key.keysym.sym)
	{
	case SDLK_ESCAPE:
		game_is_running = FALSE;
		printf("Closing Game!\n");
		break;

	case SDLK_UP:
		printf("Up arrow pressed!\n");
		player.Move(-10);
		break;

	case SDLK_DOWN:
		printf("Down arrow pressed!\n");
		player.Move(10);
		break;
	}
}