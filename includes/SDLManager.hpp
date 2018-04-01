/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDLManager.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 17:27:45 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/04/01 17:29:37 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SDLMANAGER_HPP
# define __SDLMANAGER_HPP

# include <SDL2/SDL.h>

class SDLManager {

public:
	explicit SDLManager(const unsigned int x, const unsigned int y, const char *windowName);
	~SDLManager();

	bool receiveEvent() const;

protected:
	void raiseRunTimeError() const;

private:
	SDLManager();

private:
	SDL_Window *m_win;
	SDL_GLContext m_glWindowContext;
};

#endif
