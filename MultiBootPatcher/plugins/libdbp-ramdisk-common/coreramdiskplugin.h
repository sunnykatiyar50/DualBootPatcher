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

#ifndef CORERAMDISKPLUGIN_H
#define CORERAMDISKPLUGIN_H

#include <libdbp/plugininterface.h>

#include <QtCore/QtPlugin>
#include <QtCore/QObject>
#include <QtCore/QString>
#include <QtCore/QStringList>


class CoreRamdiskPlugin : public QObject,
                          public IRamdiskPatcherFactory
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID "com.github.chenxiaolong.libdbp.IRamdiskPatcherFactory/1.0" FILE "libdbp-ramdisk-common.json")
    Q_INTERFACES(IRamdiskPatcherFactory)

public:
    CoreRamdiskPlugin(QObject *parent = 0);

    virtual QStringList ramdiskPatchers() const;

    virtual QSharedPointer<RamdiskPatcher> createRamdiskPatcher(const PatcherPaths * const pp,
                                                                const QString &id,
                                                                const FileInfo * const info,
                                                                CpioFile * const cpio) const;
};

#endif // CORERAMDISKPLUGIN_H
