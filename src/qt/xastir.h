/* -*- c-basic-offset: 4; indent-tabs-mode: nil -*-
 *
 * XASTIR, Amateur Station Tracking and Information Reporting
 * Copyright (C) 1999,2000  Frank Giannandrea
 * Copyright (C) 2000-2018 The Xastir Group
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 *
 * Look at the README for more information on the program.
 */

#ifndef XASTIR_H
#define XASTIR_H

#include <QMainWindow>
#include <QtNetwork>
#include "packetinterface.h"
#include "interfacemanager.h"
#include "interfacecontroldialog.h"
#include "stationconfigurationdialog.h"
#include "stationsettings.h"
#include "incomingdatadialog.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void interfaceControlAction();
    void stationSettingsAction();

private slots:
    void newInterface(PacketInterface*);
    void newData(PacketInterface *, QString);
    //void closeConnection();
    //void statusChanged(PacketInterface::Device_Status newState);

    void on_action_Incoming_Data_triggered();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    InterfaceControlDialog *interfaceControlDialog;
    StationConfigurationDialog *stationConfigurationDialog;
    IncomingDataDialog *incomingDataDialog;

    QTcpSocket tcpSocket;
    InterfaceManager interfaceManager;
    StationSettings stationSettings;
    QString packetDisplay;
    int total_lines;
};

#endif // XASTIR_H
