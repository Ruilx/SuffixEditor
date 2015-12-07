#include "MainW.h"

MainW::MainW(QWidget *parent)
	: QMainWindow(parent)
{
	this->view = new QTreeView(this);
	//view->setModel(model);
	QStandardItemModel *model = new QStandardItemModel;
	QStringList header;
	header << QStringLiteral("后缀名") << QStringLiteral("链接信息") << QStringLiteral("显示信息");
	model->setHorizontalHeaderLabels(header);

	view->setModel(model);

	this->setCentralWidget(view);

	this->loadSuffix(model);
}



MainW::~MainW()
{

}
