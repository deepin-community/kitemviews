/*
    SPDX-FileCopyrightText: 2007-2008 Omat Holding B .V. <info@omat.nl>

    SPDX-License-Identifier: LGPL-2.0-or-later
*/

#ifndef KFILTERPROXYSEARCHLINE_H
#define KFILTERPROXYSEARCHLINE_H

#include <kitemviews_export.h>

#if KITEMVIEWS_ENABLE_DEPRECATED_SINCE(5, 50)

#include <QWidget>
#include <memory>

class KFilterProxySearchLinePrivate;

class QLineEdit;
class QSortFilterProxyModel;

/**
 * @class KFilterProxySearchLine kfilterproxysearchline.h KFilterProxySearchLine
 *
 * Responsible for the quick search when you are using a QSortFilterProxyModel.
 * This will give you an widget which you can embed in your application, call
 * the setProxy() function to indicate on which QSortFilterProxyModel this
 * search line should operate.
 *
 * @author Tom Albers <tomalbers@kde.nl>
 * @since 4.2
 * @deprecated since 5.50, use QLineEdit directly. If filtering is expensive,
 * consider a short timer to not act on every keypress, and if results are large,
 * consider not reacting until 3 letters.
 */

class KITEMVIEWS_EXPORT KFilterProxySearchLine : public QWidget
{
    Q_OBJECT

public:
    /**
     * Constructor
     */
    KITEMVIEWS_DEPRECATED_VERSION(5, 50, "See class API docs")
    explicit KFilterProxySearchLine(QWidget *parent = nullptr);

    /**
     * Destructor
     */
    ~KFilterProxySearchLine() override;

    /**
     * Associate a proxy
     * @param proxy The proxy to operate with.
     */
    void setProxy(QSortFilterProxyModel *proxy);

    /**
     * To set the search to a text.
     */
    void setText(const QString &text);

    /**
     * Returns the pointer of the lineedit..
     */
    QLineEdit *lineEdit() const;

private:
    std::unique_ptr<class KFilterProxySearchLinePrivate> const d;

    Q_DISABLE_COPY(KFilterProxySearchLine)
    Q_PRIVATE_SLOT(d, void slotSearchLineChange(const QString &newText))
    Q_PRIVATE_SLOT(d, void slotSearchLineActivate())
};

#endif

#endif
