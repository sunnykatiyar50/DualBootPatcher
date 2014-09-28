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

#ifndef MULTIBOOTPATCHER_P_H
#define MULTIBOOTPATCHER_P_H

#include <libdbp/fileinfo.h>
#include <libdbp/patchererror.h>


class MultiBootPatcherPrivate
{
public:
    const PatcherPaths *pp;
    QString id;
    const FileInfo *info;

    int progress;

    PatcherError::Error errorCode;
    QString errorString;
};

#endif // MULTIBOOTPATCHER_P_H
