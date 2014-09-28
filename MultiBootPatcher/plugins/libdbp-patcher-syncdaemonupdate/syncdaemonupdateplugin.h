/*
 * Copyright (C) 2014  Xiao-Long Chen <chenxiaolong@cxl.epac.to>
 *
 * This file is part of MultiBootPatcher
 *
 * MultiBootPatcher is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * MultiBootPatcher is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with MultiBootPatcher.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SYNCDAEMONUPDATEPLUGIN_H
#define SYNCDAEMONUPDATEPLUGIN_H

#include <libdbp/plugininterface.h>

#include <QtCore/QtPlugin>


class SyncdaemonUpdatePlugin : public QObject,
                               public IPatcherFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.github.chenxiaolong.libdbp.IPatcherFactory/1.0" FILE "libdbp-patcher-syncdaemonupdate.json")
    Q_INTERFACES(IPatcherFactory)

public:
    explicit SyncdaemonUpdatePlugin(QObject *parent = 0);

    virtual QStringList patchers() const;

    virtual QList<PartitionConfig *> partConfigs() const;
    virtual QString patcherName(const QString &id) const;

    virtual QSharedPointer<Patcher> createPatcher(const PatcherPaths * const pp,
                                                  const QString &id) const;
};

#endif // SYNCDAEMONUPDATEPLUGIN_H
