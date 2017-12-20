#include "mymedia.h"

MyMedia::MyMedia(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);
	//ui.pushButton->setWindowFlags(Qt::WindowStaysOnTopHint);
	QTextCodec::setCodecForCStrings(QTextCodec::codecForName("system"));
	QTextCodec::setCodecForTr(QTextCodec::codecForName("system"));
	QTextCodec::setCodecForLocale(QTextCodec::codecForName("system"));
	// 初始化操作
	m_IsMute = false;
	m_isPlaying = false;
	m_player = new Myplay(this);
	m_listModel = new QStringListModel(this);
	ui.listView->setEditTriggers(QAbstractItemView::NoEditTriggers);
	// 绑定信号和槽
	connect(ui.phBtn_play,SIGNAL(clicked()),SLOT(on_clicked_phBtn_play()));
	connect(ui.phBtn_stop,SIGNAL(clicked()),SLOT(on_clicked_phBtn_stop()));
	connect(ui.action_open,SIGNAL(triggered()),SLOT(on_triggered_action_open()));
	connect(ui.action_chose,SIGNAL(triggered()),SLOT(on_triggered_action_chose()));
	connect(ui.listView,SIGNAL(doubleClicked (const QModelIndex & )),SLOT(on_doubleClicked(const QModelIndex &)));
	connect(m_player,SIGNAL(Time_change()),this,SLOT(on_Time_change()));
	connect(m_player,SIGNAL(start_Play(int)),this,SLOT(on_start_Play(int)));
	connect(ui.horizontalSlider,SIGNAL(sliderMoved(int)),this,SLOT(on_mouse_change_value(int)));
	connect(ui.horizontalSlider,SIGNAL(sliderPressed()),this,SLOT(on_sign_mouse_Press()));
	connect(ui.horizontalSlider,SIGNAL(sliderReleased()),this,SLOT(on_sign_mouse_Release()));
	connect(ui.phBtn_Vlm,SIGNAL(clicked()),this,SLOT(on_clicked_phBtn_Vlm()));
}

MyMedia::~MyMedia()
{
	
}

void MyMedia::on_clicked_phBtn_play()
{
	if (m_isPlaying)
	{
		m_player->Pause();
		m_isPlaying = false;
		ui.phBtn_play->setStyleSheet("QPushButton#phBtn_play{\
							border-image: url(:/MyMedia/img/playnormal.png);\
							}\
							QPushButton#phBtn_play:pressed{\
							border: 0px ; \
							border-image: url(:/MyMedia/img/playpressed.png);\
							}");
	} 
	else
	{
		m_isPlaying = true;
		QModelIndex curModel =  ui.listView->currentIndex();
		QString str = curModel.data().toString();
		m_player->play(str,(HWND)ui.widget->winId());
		ui.horizontalSlider->setRange(0,m_player->getAllTimes_t());
		ui.phBtn_play->setStyleSheet("QPushButton#phBtn_play{\
							border-image: url(:/MyMedia/img/pausenormal.png);\
							}\
							QPushButton#phBtn_play:pressed{\
							border: 0px ; \
							border-image: url(:/MyMedia/img/pausepressed.png);\
							}");
	}

}

void MyMedia::on_clicked_phBtn_stop()
{
	m_player->stop();
	m_isPlaying = false;
	ui.phBtn_play->setStyleSheet("QPushButton#phBtn_play{\
								 border-image: url(:/MyMedia/img/playnormal.png);\
								 }\
								 QPushButton#phBtn_play:pressed{\
								 border: 0px ; \
								 border-image: url(:/MyMedia/img/playpressed.png);\
								 }");
	ui.label->setText("00:00:00/00:00:00");
	ui.horizontalSlider->setValue(0);
}

void MyMedia::on_triggered_action_open()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open File"),"./", tr("Files (*.mp4 *.wmv *.3gp *.flv *.avi)"));
	fileName.replace("/","\\");
	QAction *temp = new QAction(fileName,NULL);
	QStringList lstStr =  m_listModel->stringList();
	lstStr.removeDuplicates();
	lstStr.append(fileName);
	m_listModel->setStringList(lstStr);
	ui.listView->setModel(m_listModel);
	m_player->play(fileName,(HWND)ui.widget->winId());
	m_isPlaying = true;
	ui.phBtn_play->setStyleSheet("QPushButton#phBtn_play{\
								 border-image: url(:/MyMedia/img/pausenormal.png);\
								 }\
								 QPushButton#phBtn_play:pressed{\
								 border: 0px ; \
								 border-image: url(:/MyMedia/img/pausepressed.png);\
								 }");
}

void MyMedia::on_triggered_action_chose()
{
	QStringList files = QFileDialog::getOpenFileNames(
		this,
		tr("Select one or more files to open"),
		"./",
		"(*.mp4 *.wmv *.3gp *.flv *.avi)");
	QStringList lstStr =  m_listModel->stringList();
	lstStr.append(files);
	lstStr.removeDuplicates();
	m_listModel->setStringList(lstStr);
	ui.listView->setModel(m_listModel);
}

void MyMedia::on_doubleClicked( const QModelIndex & who_is_clicked)
{
	m_player->stop();
	QString str = who_is_clicked.data().toString();
	m_player->play(str,ui.widget->winId());
	ui.horizontalSlider->setRange(0,m_player->getAllTimes_t());

	m_isPlaying = true;
	ui.phBtn_play->setStyleSheet("QPushButton#phBtn_play{\
								 border-image: url(:/MyMedia/img/pausenormal.png);\
								 }\
								 QPushButton#phBtn_play:pressed{\
								 border: 0px ; \
								 border-image: url(:/MyMedia/img/pausepressed.png);\
								 }");
}

void MyMedia::on_Time_change()
{
	QString str = m_player->getAlllTimeAndUseTime();
	ui.horizontalSlider->setRange(0,m_player->getAllTimes_t());
	ui.horizontalSlider->setSliderPosition(m_player->getPlayTimes_t());
	ui.label->setText(str);
}

void MyMedia::on_start_Play( int Lingth_medi )
{
	ui.horizontalSlider->setRange(0,Lingth_medi);
}

void MyMedia::on_mouse_change_value(int arg_Position)
{
	int temp_value = ui.horizontalSlider->value();
	int temp_max = ui.horizontalSlider->maximum();
	float arg_= (float)temp_value/(float)temp_max;
	m_player->setPlayTime(arg_);
}

void MyMedia::on_sign_mouse_Press()
{
	disconnect(m_player,SIGNAL(Time_change()),this,SLOT(on_Time_change()));
}

void MyMedia::on_sign_mouse_Release()
{
	connect(m_player,SIGNAL(Time_change()),this,SLOT(on_Time_change()));
}

void MyMedia::on_clicked_phBtn_Vlm()
{
	if (!m_IsMute)
	{
		m_IsMute = true;
		ui.phBtn_Vlm->setStyleSheet("QPushButton#phBtn_Vlm{\
									border-image: url(:/MyMedia/img/soundoffpress.png);\
									}\
									QPushButton#phBtn_Vlm:pressed{\
									border: 0px ; \
									border-image: url(:/MyMedia/img/soundoffnormal.png);\
									}");
	} 
	else
	{
		m_IsMute = false;
		ui.phBtn_Vlm->setStyleSheet("QPushButton#phBtn_Vlm{\
									border-image: url(:/MyMedia/img/volumenormalblue.png);\
									}\
									QPushButton#phBtn_Vlm:pressed{\
									border: 0px ; \
									border-image: url(:/MyMedia/img/volumepressedblue.png);\
									}");
	}
}
