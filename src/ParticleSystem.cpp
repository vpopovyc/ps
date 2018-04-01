/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ParticleSystem.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 16:36:15 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/04/01 16:36:18 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ParticleSystem.hpp>

ParticleSystem::ParticleSystem() :
	m_gl(new GLManager()),
	m_cl(new CLManager()),
	m_sdl(new SDLManager())
{
	std::cout << "ParticleSystem created\n";
}

ParticleSystem::~ParticleSystem()
{
	std::cout << "ParticleSystem destroyed\n";
}