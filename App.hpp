/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   App.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpopovyc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 20:17:12 by vpopovyc          #+#    #+#             */
/*   Updated: 2018/04/16 20:17:47 by vpopovyc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <QDialog>
# include <QObject>
# include <QPushButton>

class App : public QDialog {
    Q_OBJECT
public:
    App(QWidget* parent = 0);

private slots:
    void buttonClicked();

private:
    QPushButton m_button;
};
