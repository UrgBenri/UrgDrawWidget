/*
	This file is part of the UrgBenri application.

	Copyright (c) 2016 Mehrez Kristou.
	All rights reserved.

	Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

	1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

	2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

	3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.

	THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

	Please contact kristou@hokuyo-aut.jp for more details.

*/

#ifndef CIRCLEITEM_H
#define CIRCLEITEM_H

#include "DataItem.h"

#include <QPointF>
#include <QColor>

class CircleItem : public DataItem
{
public:
    CircleItem(qint64 timestamp, const QPointF &center, qreal radius, const QColor &color);
    virtual ~CircleItem();

    void drawPoints(qreal drawSize
                    , const QVector<QColor> &colors
                    , const QVector<bool> &flags
                    , qreal ratio
                    , const QPointF &offset
                    , qreal alpha
                    , int selectedStep);

    inline QPointF center() const { return m_center; }
    inline void setCenter(const QPointF &center) { m_center = center; }

    inline qreal radius() const { return m_radius; }
    inline void setRadius(qreal radius) { m_radius = radius; }

    inline QColor color() const { return m_color; }
    inline void setColor(const QColor &color) { m_color = color; }

private:
    QPointF m_center;
    qreal m_radius;
    QColor m_color;
};

#endif // CIRCLEITEM_H

