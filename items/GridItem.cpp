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

#include "GridItem.h"
#include "glextensions.h"

GridItem::GridItem(qint64 timestamp
                   , const QRect &rect
                   , const QSize &cellSize)
    : DataItem(timestamp)
    , m_rect(rect)
    , m_cellSize(cellSize)
{

}

GridItem::~GridItem()
{

}

void GridItem::drawPoints(qreal drawSize
                          , const QVector<QColor> &colors
                          , const QVector<bool> &flags
                          , qreal ratio
                          , const QPointF &offset
                          , qreal alpha
                          , int selectedStep)
{
    double zoom_ratio = ratio;
    QColor line_color = colors.size() > 0 ? colors[0] : QColor(Qt::blue);

    glLineWidth(drawSize);

    glColor4d(line_color.redF(), line_color.greenF(), line_color.blueF(), alpha);

    for (long index = 0; index < m_rect.width() + 1; index += m_cellSize.width()) {
        double x1 = ((m_rect.x() + index) * zoom_ratio) - offset.x();
        double y1 = (m_rect.y() * zoom_ratio) - offset.y();
        double y2 = ((m_rect.y() + m_rect.height()) * zoom_ratio) - offset.y();

        glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x1, y2);
        glEnd();
    }

    for (long index = 0; index < m_rect.height() + 1; index += m_cellSize.height()) {
        double x1 = ((m_rect.x()) * zoom_ratio) - offset.x();
        double y1 = ((m_rect.y() + index) * zoom_ratio) - offset.y();
        double x2 = ((m_rect.x() +  + m_rect.width()) * zoom_ratio) - offset.x();

        glBegin(GL_LINES);
        glVertex2d(x1, y1);
        glVertex2d(x2, y1);
        glEnd();
    }
    glLineWidth(1);
    glColor4d(0, 0, 0, 1);
}

