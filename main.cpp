/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:13:55 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/04/16 20:14:01 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <qapplication.h>
#include <App.hpp>

int main(int argc, char** argv)
{
	QApplication app(argc, argv);

  	App myApp;

  	myApp.show();

	return app.exec();
}
