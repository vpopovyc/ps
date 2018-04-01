/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GLManager.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/01 16:00:58 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/04/01 16:01:00 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ParticleSystem.hpp>
#include <fstream>

GLManager::GLManager()
{
	std::cout << "GLManager created\n"; 
}

GLManager::~GLManager()
{
	std::cout << "GLManager destroyed\n";
}

static void loadShaderProgram(const char *vert_shader, const char *frag_shader)
{
	const auto &printCompileLog = [this](const Gluint &glID, const GLenum &pname) {
	    int maxLenght = 0;
	    int lenght = 0;
	    GLchar *infoLog;

	    glGetShaderiv(glID, pname, &maxLenght);
	    if (maxLenght > 1)
	    {
	        infoLog = new GLchar[maxLenght];
	        glGetShaderInfoLog(glID, maxLenght, &lenght, infoLog);
	        std::cout << "Error while loadShaderProgram: " << infoLog << std::endl;
	        delete [] infoLog;
	    }
	    exit(EXIT_FAILURE);
	}
	const auto &checkStatusOf = [this](const GLuint &glID, const GLenum &pname) {
		GLint status;

		glGetShaderiv(glID, pname, &status);
		if (!status) {
			printCompileLog(glID, pname);
		}
	}
	const auto &loadFile = [this](const char *filename, GLuint &filesize) -> const char * {
		std::ifstream file(filename, std::ifstream::in|std::ifstream::binary|std::ifstream::ate);
		if (file.isOpen()) {
	        filesize = file.tellg();
	        char *raw_mem = new char[filesize];
	        file.seekg(0, std::ifstream::beg);
	        file.read(raw_mem, filesize);
	        file.close();
	        return (raw_mem);
		} else {
			return (NULL);
		}
	}
	const auto &compile = [this](const char *shader) -> GLuint {
		GLuint size = 0;
		GLuint glID;

		const char *filebinary = loadFile(shader, size);
		
		glShaderSource(glID, 1, &filebinary, &size);
		glCompileShader(glID);
	    
		checkStatus(glID);
		delete [] filebinary;
		return (glID);
	}

	GLuint vertID = compile(vert_shader);
	GLuint fragID = compile(frag_shader);
	GLuint shaderProgram = glCreatePRogram();

	glAttachShader(shaderProgram, vertID);
	glAttachShader(shaderProgram, fragID);

	glLinkProgram(shaderProgram);

	m_shaderProgram = shaderProgram;
}