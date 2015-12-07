#ifndef MAINW_H
#define MAINW_H

#include <QMainWindow>
#include <QtWidgets>

class MainW : public QMainWindow{
	Q_OBJECT
	QTreeView *view;

	void loadSuffix(QStandardItemModel *model){
		QSettings *reg = new QSettings("HKEY_CLASSES_ROOT", QSettings::NativeFormat);
		QStringList groupList = reg->childGroups();
		foreach(QString part, groupList){
			if(part.startsWith(".")){
				QStandardItem *item = new QStandardItem(part);
				model->appendRow(item);
				QString value = reg->value(part + "\\").toString();
				qDebug() << value;
				model->setItem(model->indexFromItem(item).row(), 1, new QStandardItem(value));
			}
		}
	}

public:
	MainW(QWidget *parent = 0);
	~MainW();
};

#endif // MAINW_H
