/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParticleSystem.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 16:16:44 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/04/01 16:17:28 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARTICLESYSTEM_HPP
# define __PARTICLESYSTEM_HPP

# include <CLManager.hpp>
# include <GLManager.hpp>
# include <SDLManager.hpp>

# include <iostream>
# include <memory>

class ParticleSystem {

public:
	ParticleSystem();
	~ParticleSystem();

private:

	std::unique_ptr<GLManager> m_gl;
	std::unique_ptr<CLManager> m_cl;
	std::unique_ptr<SDLManager> m_sdl;
};

#endif
