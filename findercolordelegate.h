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

        QTextDocument doc;
        QString s=options.text;
        s.replace(str,"<font color=\"Red\">"+str+"</font>");

        doc.setDefaultFont(this->font);
        doc.setHtml(s);




        if( option.state & QStyle::State_Selected )//it is your selection
          {
              if(index.row()%2)//here we try to see is it a specific item
                  painter->fillRect( option.rect,Qt::green );//special color
              else
                  painter->fillRect( option.rect, option.palette.highlight() );
              painter->drawText(option.rect,s);//text of item
          }else{
            options.text = "";
            options.widget->style()->drawControl(QStyle::CE_ItemViewItem, &options, painter);

            painter->translate(options.rect.left(), options.rect.top());
            //QRect clip(0, 0, options.rect.width(), options.rect.height());
            doc.drawContents(painter);

        }
        painter->restore();
    }

    QSize sizeHint ( const QStyleOptionViewItem & option, const QModelIndex & index ) const
    {
        QStyleOptionViewItem options = option;
        initStyleOption(&options, index);

        QTextDocument doc;
        doc.setHtml(options.text);
        doc.setTextWidth(options.rect.width());
        return QSize(doc.idealWidth(), doc.size().height());
    }
};

#endif // FINDERCOLORDELEGATE_H
