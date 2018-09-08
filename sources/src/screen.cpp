//
// EPITECH PROJECT, 2018
// 
// File description:
// 
//

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include <iostream>
#include <ostream>

#include "../inc/main.hpp"

int createWindows()
{
	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	int flags = IMG_INIT_JPG|IMG_INIT_PNG;
	int initted = IMG_Init(flags);
	
	if((initted & flags) != flags) {
		std::cerr << "Error on the initialisation on the IMG_INIT()!" << std::endl;
		std::cerr << "IMG_Init() : " << IMG_GetError() << std::endl;		

		return (-1);
	}
	
	SDL_Window * window = SDL_CreateWindow("SDL2 Displaying Image",
					       SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
					       800, 800, 0);

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
	SDL_Surface *image = IMG_Load("./ressources/assets/test.jpg");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);

	while (!quit)
	{
		SDL_WaitEvent(&event);

		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}

		SDL_Rect dstrect = { 5, 5, 320, 240 };
		SDL_RenderCopy(renderer, texture, NULL, &dstrect);
		SDL_RenderCopy(renderer, texture, NULL, NULL);
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyTexture(texture);
	SDL_FreeSurface(image);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
