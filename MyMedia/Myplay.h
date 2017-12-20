#ifndef MYPLAY_H
#define MYPLAY_H

#include <QObject>
#include <Windows.h>
// #include "include/libvlc.h"
// #include "include/libvlc_media_library.h"
#include "include/vlc.h"
#include <QMessageBox>
#include <QTextCodec>
#include <QTimer>
class Myplay : public QObject
{
	Q_OBJECT

public:
	Myplay(QObject *parent);
	~Myplay();

private:
	QTimer *change_time_str;
	libvlc_instance_t *p_instance;
	libvlc_media_player_t * player_;//播放器实体
	int m_play_time;//记录已播放时间
	int m_all_time;
public:
	/************************************************************************/
	/* 播放函数
		文件路径
		父窗口句柄
	*/
	/************************************************************************/
	void play(QString strFilePath = "",HWND parent=NULL);
	/************************************************************************/
	/* 暂停                                                                 */
	/************************************************************************/
	void Pause();
	/************************************************************************/
	/* 停止                                                                 */
	/************************************************************************/
	void stop();
	/************************************************************************/
	/* 获取已播放时间和总时间的字符串                                       */
	/************************************************************************/
	QString getAlllTimeAndUseTime();
	/************************************************************************/
	/*  获取当前播放时间     必须文件几经开始播放才能获取                   */
	/************************************************************************/
	int getPlayTimes_t();
	/************************************************************************/
	/* //必须文件几经开始播放才能获取    必须文件几经开始播放才能获取       */
	/************************************************************************/
	int getAllTimes_t();
	/************************************************************************/
	/*  设置当前播放时间，用于改变播放进度                                 */
	/************************************************************************/
	void setPlayTime(float arg_time);
	/************************************************************************/
	/* 播放下一个                                                           */
	/************************************************************************/
	void Play_Next(QString filePath);
protected:
	/************************************************************************/
	/* 播放时间转换，传入参数为毫秒，返回时间字符串如00:00:00               */
	/************************************************************************/
	QString time_t2time_str(int arg_time);
signals:
	void Time_change();//播放时间改变
	void start_Play(int Length_medi);//开始播放,参数为播放文件的总时间
public slots:
	void on_timeout_change_time_str();

};

#endif // MYPLAY_H
