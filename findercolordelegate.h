#ifndef FINDERCOLORDELEGATE_H
#define FINDERCOLORDELEGATE_H

#include <QPainter>
#include <QStyleOptionViewItem>
#include <QStyledItemDelegate>
#include <QTextDocument>



class FinderColorDelegate : public QStyledItemDelegate
{

protected:
    QString str;
    QFont font;
public:
    FinderColorDelegate(const QString str){


        font.setFamily("Times New Roman");
        font.setPointSize(14);
        this->str=str;
    }



    void paint(QPainter* painter, const QStyleOptionViewItem & option, const QModelIndex &index) const
    {
        QStyleOptionViewItem options = option;
        initStyleOption(&options, index);
        painter->setFont(this->font);

        painter->save();

        QString s=options.text;




        if( option.state & QStyle::State_Selected )//it is your selection
        {
            painter->fillRect( options.rect, option.palette.highlight() );

        }
        painter->drawText(options.rect,s);//text of item

        if(s.contains(str)){
            QRect r3( option.rect.left(), option.rect.top()+5, 11, 16 );
            painter->drawRect(r3);
        }


//         else {
//            QTextDocument doc;

//            s.replace(str,"<font color=\"Red\">"+str+"</font>");

//            doc.setDefaultFont(this->font);
//            doc.setHtml(s);
//            options.text = "      ";
//            options.widget->style()->drawControl(QStyle::CE_ItemViewItem, &options, painter);


//            painter->translate(options.rect.left(), options.rect.top());
//            QRect clip(0, 0, options.rect.width(), options.rect.height());
//            doc.drawContents(painter,clip);
//        }



        painter->restore();
    }

    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const
    {
        //        QStyleOptionViewItem options = option;
        //        initStyleOption(&options, index);

        //        QTextDocument doc;
        //        doc.setHtml(options.text);
        //        doc.setTextWidth(options.rect.width());
        //        return QSize(doc.idealWidth(), doc.size().height());
        QSize result = QStyledItemDelegate::sizeHint(option, index);
        result.setHeight(result.height()*2);
        return result;
    }
};

#endif // FINDERCOLORDELEGATE_H
