/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
** Author: Frank Osterfeld, KDAB (frank.osterfeld@kdab.com)
**
** This file is part of Qt Creator.
**
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
****************************************************************************/

#ifndef LIBVALGRIND_PROTOCOL_ANNOUNCETHREAD_H
#define LIBVALGRIND_PROTOCOL_ANNOUNCETHREAD_H

#include <QSharedDataPointer>

QT_BEGIN_NAMESPACE
template <typename T> class QVector;
QT_END_NAMESPACE

namespace Valgrind {
namespace XmlProtocol {

class Frame;

class AnnounceThread {
public:
    AnnounceThread();
    AnnounceThread(const AnnounceThread &other);
    ~AnnounceThread();
    AnnounceThread &operator=(const AnnounceThread &other);
    void swap(AnnounceThread &other);
    bool operator==(const AnnounceThread &other) const;

    qint64 helgrindThreadId() const;
    void setHelgrindThreadId(qint64 id);

    QVector<Frame> stack() const;
    void setStack(const QVector<Frame> &stack);

private:
    class Private;
    QSharedDataPointer<Private> d;
};

} // namespace XmlProtocol
} // namespace Valgrind

#endif // LIBVALGRIND_PROTOCOL_ANNOUNCETHREAD_H
