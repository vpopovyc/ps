/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 16:16:10 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/04/01 16:16:11 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ParticleSystem.hpp>

int main(void)
{
	// Init particle system for defined size
	ParticleSystem particleSystem;

	do {
		// Draw particles
		// Receive event from sdl => update gl's vbo using cl_mem obj
	}
	while (particleSystem.receiveEvent());
	
	return (EXIT_SUCCESS);
}