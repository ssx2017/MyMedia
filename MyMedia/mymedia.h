#ifndef MYMEDIA_H
#define MYMEDIA_H

#include <QtGui/QMainWindow>
#include <QFileDialog>
#include <QStringListModel>
#include <QAbstractItemView>
#include <QTextCodec>
#include "ui_mymedia.h"
#include "Myplay.h"
//#include "Mixer.h"
class MyMedia : public QMainWindow
{
	Q_OBJECT

public:
	MyMedia(QWidget *parent = 0, Qt::WFlags flags = 0);
	~MyMedia();

private:
	Ui::MyMediaClass ui;
private:
	Myplay *m_player;
	QStringListModel *m_listModel;
private:
	/*void Make_Not_To_Repeat(QStringList &);*/
	bool m_isPlaying;//标记是否正在播放
	bool m_IsMute;//标记是否静音
protected slots:
	void on_clicked_phBtn_play();
	void on_clicked_phBtn_stop();
	void on_triggered_action_open();
	void on_triggered_action_chose();
	void on_doubleClicked(const QModelIndex &);
	void on_Time_change();
	void on_start_Play(int Lingth_medi);
	void on_mouse_change_value(int arg_Position);
	void on_sign_mouse_Press();
	void on_sign_mouse_Release();
	void on_clicked_phBtn_Vlm();
protected:
	//::mixerSetControlDetails()
	//bool SetVolumeLabel
};

#endif // MYMEDIA_H
