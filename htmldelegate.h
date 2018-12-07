#ifndef HTMLDELEGATE_H
#define HTMLDELEGATE_H

#include "mysettings.h"

#include "mainwindow.h"

#include <QPainter>

#include <QStyledItemDelegate>
#include <QTextDocument>
#include <qtextdocument.h>
#include<QApplication>
#include<QAbstractTextDocumentLayout>

class HtmlDelegate : public QStyledItemDelegate
{
public: HtmlDelegate(const QString str){

       set=new MySettings;
        font=set->getFont1();

        this->str=str;

    }

protected:
    MySettings *set;
    QString str;
    QFont font;
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
    {


            QStyleOptionViewItem optionV4 = option;
            initStyleOption(&optionV4, index);
            QStyle *style = optionV4.widget? optionV4.widget->style() : QApplication::style();
            QTextDocument doc;


            //index.data().setValue(1);

            QColor text=set->getColorText();
            QString s=optionV4.text;
            if(s.contains(str)){
                MainWindow::getSetSelect()->insert(index.row());
                s.replace(str,"<font color=\"Red\">"+this->str+"</font>");
            }

            if (optionV4.state & QStyle::State_Selected){
                s="<font color=\""+set->getColorselectetedText().name()+"\">"+s+"</font>";
            }else{
                s="<font color=\""+text.name()+"\">"+s+"</font>";
            }

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
            QSize result = QStyledItemDelegate::sizeHint(option, index);

            double sd=this->set->getValueHeigcht();
            result.setHeight(static_cast<int>(result.height()*sd));
            return result;
//            QStyleOptionViewItemV4 optionV4 = option;
//            initStyleOption(&optionV4, index);

//            QTextDocument doc;
//            doc.setHtml(optionV4.text);
//            doc.setTextWidth(optionV4.rect.width());
//            return QSize(doc.idealWidth(), doc.size().height());

        }
    }
};





#endif // HTMLDELEGATE_H
