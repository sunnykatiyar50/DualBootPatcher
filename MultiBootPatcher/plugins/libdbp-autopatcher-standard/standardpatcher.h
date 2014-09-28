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

#ifndef STANDARDPATCHER_H
#define STANDARDPATCHER_H

#include "libdbp-autopatcher-standard_global.h"

#include <libdbp/device.h>
#include <libdbp/plugininterface.h>

#include <QtCore/QtPlugin>

class StandardPatcherPrivate;

class LIBDBPAUTOPATCHERSTANDARDSHARED_EXPORT StandardPatcher : public AutoPatcher
{
public:
    explicit StandardPatcher(const PatcherPaths * const pp,
                             const QString &id,
                             const FileInfo * const info,
                             const PatchInfo::AutoPatcherArgs &args);
    ~StandardPatcher();

    static const QString UpdaterScript;

    static const QString Name;

    static const QString ArgLegacyScript;

    virtual PatcherError::Error error() const;
    virtual QString errorString() const;

    virtual QString name() const;

    virtual QStringList newFiles() const;
    virtual QStringList existingFiles() const;

    virtual bool patchFile(const QString &file,
                           QByteArray * const contents,
                           const QStringList &bootImages);

    // These are public so other plugins can use them
    static void removeDeviceChecks(QStringList *lines);
    static void insertDualBootSh(QStringList *lines, bool legacyScript);
    static void insertWriteKernel(QStringList *lines, const QString &bootImage);

    static void replaceMountLines(QStringList *lines, Device *device);
    static void replaceUnmountLines(QStringList *lines, Device *device);
    static void replaceFormatLines(QStringList *lines, Device *device);

    static int insertMountSystem(int index, QStringList *lines);
    static int insertMountCache(int index, QStringList *lines);
    static int insertMountData(int index, QStringList *lines);
    static int insertUnmountSystem(int index, QStringList *lines);
    static int insertUnmountCache(int index, QStringList *lines);
    static int insertUnmountData(int index, QStringList *lines);
    static int insertUnmountEverything(int index, QStringList *lines);
    static int insertFormatSystem(int index, QStringList *lines);
    static int insertFormatCache(int index, QStringList *lines);
    static int insertFormatData(int index, QStringList *lines);

    static int insertSetPerms(int index, QStringList *lines,
                              bool legacyScript, const QString &file,
                              uint mode);

private:
    const QScopedPointer<StandardPatcherPrivate> d_ptr;
    Q_DECLARE_PRIVATE(StandardPatcher)
};

#endif // STANDARDPATCHER_H
