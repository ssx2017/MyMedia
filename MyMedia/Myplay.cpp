#include "Myplay.h"

Myplay::Myplay(QObject *parent)
	: QObject(parent)
{
	p_instance =NULL;
	player_ = NULL;
	//const char* vlcArgs[] = {     
	//	"--demux", "avformat"    
	//};
	//p_instance = libvlc_new(sizeof(vlcArgs) / sizeof(vlcArgs[0]), vlcArgs);//防止关闭软件或停止视频是卡顿
	//p_instance = libvlc_new(0,0);
	m_play_time = 0;
	change_time_str = new QTimer(this);
	connect(change_time_str,SIGNAL(timeout()),this,SLOT(on_timeout_change_time_str()));
}

Myplay::~Myplay()
{
	if (player_)
	{
		libvlc_media_player_stop(player_);
		libvlc_media_player_release(player_);
	}
	
}

void Myplay::play(QString strFilePath,HWND parent)
{
	//if ()
	//{
	//}
	if (p_instance) libvlc_release(p_instance);
	const char* vlcArgs[] = {     
		"--demux", "avformat"    
	};
	p_instance = libvlc_new(sizeof(vlcArgs) / sizeof(vlcArgs[0]), vlcArgs);//防止关闭软件或停止视频是卡顿

	if (!p_instance)
	{
		QMessageBox::warning(NULL,"警告","播放器初始化失败！");
		return;
	}

	//通过文件路径创建媒体实体
	libvlc_media_t *path_ = libvlc_media_new_path(p_instance,strFilePath.toUtf8().data());

	if (!player_)
	{
		//为媒体创建一个播放器
		player_ =libvlc_media_player_new_from_media(path_);
		//return;
		if (!player_)
		{
			return;
		}
	}
	 
	libvlc_media_player_set_hwnd(player_,parent);//为播放器指定父窗口

	libvlc_media_player_play(player_);//播放

	libvlc_media_release(path_);//一旦调用上面的播放函数，媒体的实体指针就没有再存在的意义了，释放掉

	change_time_str->start(1); // 媒体开始播放就立即检测时间
	emit start_Play(m_all_time);

}

void Myplay::Pause()
{
	if (player_)
	{
		libvlc_media_player_pause(player_);
	}
	change_time_str->stop();
}

void Myplay::stop()
{
	if (player_)
	{
		libvlc_media_player_stop(player_);
		libvlc_media_player_release(player_);
		player_ = NULL;
	}
	change_time_str->stop();
}
QString Myplay::getAlllTimeAndUseTime()
{
	if (!player_)
	{
		return "00:00:00/00:00:00";
	}
	int all_tinme = libvlc_media_player_get_length(player_);
	m_all_time = all_tinme;
	int use_time = libvlc_media_player_get_time(player_);
	return time_t2time_str(use_time) +"/"+ time_t2time_str(all_tinme);
}

QString Myplay::time_t2time_str( int arg_time )
{
	int h_t,m_t,s_t;
	s_t = arg_time/1000;
	m_t = s_t/60;
	s_t = s_t%60;
	h_t = m_t/60;
	m_t = m_t%60;
	QString str_return = QString("%1:%2:%3").arg(h_t,2,10,QLatin1Char('0')).arg(m_t,2,10,QLatin1Char('0')).arg(s_t,2,10,QLatin1Char('0'));
	return str_return;
}

void Myplay::on_timeout_change_time_str()
{
	int temp = libvlc_media_player_get_time(player_);
	if (temp>m_play_time)
	{
		temp = m_play_time;
		emit Time_change();
	}
}
int Myplay::getPlayTimes_t()
{
	int tmp = libvlc_media_player_get_time(player_);
	if(tmp>0) return tmp;
	else return 0;
}
int Myplay::getAllTimes_t()
{
	int tmp = libvlc_media_player_get_length(player_);
	if(tmp>0) return tmp;
	else return 0;
}

void Myplay::setPlayTime( float arg_time )
{
	if (player_)
	{
		libvlc_media_player_set_position(player_,arg_time);
	}
}

void Myplay::Play_Next( QString filePath )
{
	if (p_instance) libvlc_release(p_instance);
	const char* vlcArgs[] = {     
		"--demux", "avformat"    
	};
	p_instance = libvlc_new(sizeof(vlcArgs) / sizeof(vlcArgs[0]), vlcArgs);//防止关闭软件或停止视频是卡顿

	if (!p_instance)
	{
		QMessageBox::warning(NULL,"警告","播放器初始化失败！");
		return;
	}

	//通过文件路径创建媒体实体
	libvlc_media_t *path_ = libvlc_media_new_path(p_instance,filePath.toUtf8().data());

	if (!player_)
	{
		//为媒体创建一个播放器
		player_ =libvlc_media_player_new_from_media(path_);
		//return;
		if (!player_)
		{
			return;
		}
	}

	//libvlc_media_player_set_hwnd(player_,parent);//为播放器指定父窗口

	libvlc_media_player_play(player_);//播放

	libvlc_media_release(path_);//一旦调用上面的播放函数，媒体的实体指针就没有再存在的意义了，释放掉

	change_time_str->start(1); // 媒体开始播放就立即检测时间
	emit start_Play(m_all_time);
}