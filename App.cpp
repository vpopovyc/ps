/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:17:55 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/04/16 20:18:13 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <App.hpp>
#include <QMessageBox>

App::App(QWidget *parent) : QDialog(parent), m_button(this)
{
	m_button.setText("Hello world!");
	m_button.resize(100, 30);
	connect(&m_button, &QPushButton::clicked, this, &App::buttonClicked);
}

void App::buttonClicked()
{
      QMessageBox box;
      box.setWindowTitle("Howdy");
      box.setText("You clicked the button");
      box.show();
      box.exec();
}
