/****************************************************************************
 **
 ** Copyright (C) Qxt Foundation. Some rights reserved.
 **
 ** This file is part of the QxtGui module of the Qxt library.
 **
 ** This library is free software; you can redistribute it and/or modify it
 ** under the terms of the Common Public License, version 1.0, as published
 ** by IBM, and/or under the terms of the GNU Lesser General Public License,
 ** version 2.1, as published by the Free Software Foundation.
 **
 ** This file is provided "AS IS", without WARRANTIES OR CONDITIONS OF ANY
 ** KIND, EITHER EXPRESS OR IMPLIED INCLUDING, WITHOUT LIMITATION, ANY
 ** WARRANTIES OR CONDITIONS OF TITLE, NON-INFRINGEMENT, MERCHANTABILITY OR
 ** FITNESS FOR A PARTICULAR PURPOSE.
 **
 ** You should have received a copy of the CPL and the LGPL along with this
 ** file. See the LICENSE file and the cpl1.0.txt/lgpl-2.1.txt files
 ** included with the source distribution for more information.
 ** If you did not receive a copy of the licenses, contact the Qxt Foundation.
 **
 ** <http://libqxt.org>  <foundation@libqxt.org>
 **
 ****************************************************************************/
#ifndef QXTITEMDELEGATE_P_H
#define QXTITEMDELEGATE_P_H

#include "qxtitemdelegate.h"
#include <QPersistentModelIndex>
#include <QBasicTimer>
#include <QPointer>
#include <QMultiHash>

QT_FORWARD_DECLARE_CLASS(QPainter)
QT_FORWARD_DECLARE_CLASS(QTreeView)
QT_FORWARD_DECLARE_CLASS(QTextDocument)

class QxtItemDelegatePrivate : public QObject, public QxtPrivate<QxtItemDelegate>
{
    Q_OBJECT

public:
    QXT_DECLARE_PUBLIC(QxtItemDelegate)
    QxtItemDelegatePrivate();

    void paintButton(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index, const QTreeView* view) const;
    void paintMenu(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index, const QTreeView* view) const;
    void paintProgress(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const;
    void setCurrentEditor(QWidget* editor, const QModelIndex& index) const;

    bool textVisible;
    QString progressFormat;
    Qt::TextElideMode elide;
    Qxt::DecorationStyle style;
    typedef QPointer<QtWidgets/QWidget> QWidgetPointer;
    mutable QWidgetPointer currentEditor;
    mutable QPersistentModelIndex currentEdited;
    mutable QMultiHash<QWidget*, QPersistentModelIndex> updatedItems;
    mutable QBasicTimer updateTimer;
    mutable QTextDocument* document;

protected:
    void timerEvent(QTimerEvent* event);

private Q_SLOTS:
    void viewDestroyed();
    void closeEditor(QWidget* editor);
};

#endif // QXTITEMDELEGATE_P_H
