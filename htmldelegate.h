#ifndef HTMLDELEGATE_H
#define HTMLDELEGATE_H

#include <QPainter>
#include <QStyleOptionViewItem>
#include <QStyledItemDelegate>
#include <QTextDocument>
#include <qtextdocument.h>
#include<QApplication>
#include<QAbstractTextDocumentLayout>

class HtmlDelegate : public QStyledItemDelegate
{
public: HtmlDelegate(const QString str){

        font.setFamily("Times New Roman");
        font.setPointSize(12);
        this->str=str;

    }

protected:
    QString str;
    QFont font;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {


            QStyleOptionViewItemV4 optionV4 = option;
            initStyleOption(&optionV4, index);
            QStyle *style = optionV4.widget? optionV4.widget->style() : QApplication::style();
            QTextDocument doc;



            QString s=optionV4.text;
            s.replace(str,"<font color=\"Red\">"+this->str+"</font>");
            doc.setDefaultFont(this->font);
            doc.setHtml(s);
            /// Painting item without text
            optionV4.text = QString();
            style->drawControl(QStyle::CE_ItemViewItem, &optionV4, painter);
            QAbstractTextDocumentLayout::PaintContext ctx;

            // Highlighting text if item is selected
            if (optionV4.state & QStyle::State_Selected)
                ctx.palette.setColor(QPalette::Text, optionV4.palette.color(QPalette::Active, QPalette::HighlightedText));


            QRect textRect = style->subElementRect(QStyle::SE_ItemViewItemText, &optionV4);

            painter->save();
            painter->translate(textRect.topLeft());
            painter->setClipRect(textRect.translated(-textRect.topLeft()));
            doc.documentLayout()->draw(painter, ctx);

            painter->restore();

    }
    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const{
        {
            QStyleOptionViewItemV4 optionV4 = option;
            initStyleOption(&optionV4, index);

            QTextDocument doc;
            doc.setHtml(optionV4.text);
            doc.setTextWidth(optionV4.rect.width());
            return QSize(doc.idealWidth(), doc.size().height());

        }
    }
};





#endif // HTMLDELEGATE_H
