/* Copyright (C) 2015, multimediaApp
 * Written by shadow-code <achbill12@gmail.com>
 *
 *
 *
 * ========LICENCE========
 * This file is part of the library LinBox.
 *
 * multimediaApp is free software: you can redistribute it and/or modify
 * it under the terms of the  GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.	 See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 *  "Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in
 *     the documentation and/or other materials provided with the
 *     distribution.
 *
 * ========LICENCE========
 */

#ifndef PEERMANAGER_H
#define PEERMANAGER_H

#include <QByteArray>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QUdpSocket>

class Client;
class Connection;

class PeerManager : public QObject
{
    Q_OBJECT

public:
    PeerManager(Client *client);

    void setServerPort(int port);
    QByteArray userName() const;
    void startBroadcasting();
    bool isLocalHostAddress(const QHostAddress &address);

signals:
    void newConnection(Connection *connection);

private slots:
    void sendBroadcastDatagram();
    void readBroadcastDatagram();

private:
    void updateAddresses();

    Client *client;
    QList<QHostAddress> broadcastAddresses;
    QList<QHostAddress> ipAddresses;
    QUdpSocket broadcastSocket;
    QTimer broadcastTimer;
    QByteArray username;
    int serverPort;
};

#endif
