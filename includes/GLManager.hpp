/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CGLManager.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 15:51:19 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/04/01 15:59:16 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __GLMANAGER_HPP
# define __GLMANAGER_HPP

class GLManager {

public:
	GLManager();
	~GLManager();

	static void loadShaderProgram(const char *vert_shader, const char *frag_shader);

private:
	GLuint m_shaderProgram;
};

#endif

