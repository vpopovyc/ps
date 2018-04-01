/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDLManager.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:27:14 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/04/01 17:27:15 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ParticleSystem.hpp>

SDLManager::SDLManager(const unsigned int x, const unsigned int y, const char *windowName)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		raiseRunTimeError();
	}

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    m_win = SDL_CreateWindow(windowName, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_OPENGL);
    if (!m_win) {
    	raiseRunTimeError();
    }

    m_glWindowContext = SDL_GL_CreateContext(m_win);

	SDL_GL_SetSwapInterval(1);
    
    glViewport(0, 0, x, y);
    glEnable(GL_DEPTH_TEST);

    glewExperimental = 1;
    if (glewInit() != GLEW_OK)
    	raiseRunTimeError();

    SDL_GL_SetSwapInterval(1);
    glClearColor(0.863, 0.863, 0.863, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    SDL_GL_SwapWindow(m_win);
}

SDLManager::~SDLManager()
{
	SDL_GL_DeleteContext(m_glWindowContext);
	SDL_DestroyWindow(m_win);
	SDL_Quit();
}

void SDLManager::raiseRunTimeError() const
{
	std::cout << "SDL error: " << SDL_GetError() << std::endl;
	exit(EXIT_FAILURE);
}

bool SDLManager::receiveEvent() const
{
	SDL_Event event;
	uint8_t *state = (unsigned char *)SDL_GetKeyboardState(NULL);

	SDL_PollEvent(&event);
	return (event.type != SDL_QUIT && !state[SDL_SCANCODE_ESCAPE]);
}
