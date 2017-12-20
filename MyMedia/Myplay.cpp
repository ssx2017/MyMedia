#include "Myplay.h"

Myplay::Myplay(QObject *parent)
	: QObject(parent)
{
	p_instance =NULL;
	player_ = NULL;
	//const char* vlcArgs[] = {     
	//	"--demux", "avformat"    
	//};
	//p_instance = libvlc_new(sizeof(vlcArgs) / sizeof(vlcArgs[0]), vlcArgs);//��ֹ�ر������ֹͣ��Ƶ�ǿ���
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
	p_instance = libvlc_new(sizeof(vlcArgs) / sizeof(vlcArgs[0]), vlcArgs);//��ֹ�ر������ֹͣ��Ƶ�ǿ���

	if (!p_instance)
	{
		QMessageBox::warning(NULL,"����","��������ʼ��ʧ�ܣ�");
		return;
	}

	//ͨ���ļ�·������ý��ʵ��
	libvlc_media_t *path_ = libvlc_media_new_path(p_instance,strFilePath.toUtf8().data());

	if (!player_)
	{
		//Ϊý�崴��һ��������
		player_ =libvlc_media_player_new_from_media(path_);
		//return;
		if (!player_)
		{
			return;
		}
	}
	 
	libvlc_media_player_set_hwnd(player_,parent);//Ϊ������ָ��������

	libvlc_media_player_play(player_);//����

	libvlc_media_release(path_);//һ����������Ĳ��ź�����ý���ʵ��ָ���û���ٴ��ڵ������ˣ��ͷŵ�

	change_time_str->start(1); // ý�忪ʼ���ž��������ʱ��
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
	p_instance = libvlc_new(sizeof(vlcArgs) / sizeof(vlcArgs[0]), vlcArgs);//��ֹ�ر������ֹͣ��Ƶ�ǿ���

	if (!p_instance)
	{
		QMessageBox::warning(NULL,"����","��������ʼ��ʧ�ܣ�");
		return;
	}

	//ͨ���ļ�·������ý��ʵ��
	libvlc_media_t *path_ = libvlc_media_new_path(p_instance,filePath.toUtf8().data());

	if (!player_)
	{
		//Ϊý�崴��һ��������
		player_ =libvlc_media_player_new_from_media(path_);
		//return;
		if (!player_)
		{
			return;
		}
	}

	//libvlc_media_player_set_hwnd(player_,parent);//Ϊ������ָ��������

	libvlc_media_player_play(player_);//����

	libvlc_media_release(path_);//һ����������Ĳ��ź�����ý���ʵ��ָ���û���ٴ��ڵ������ˣ��ͷŵ�

	change_time_str->start(1); // ý�忪ʼ���ž��������ʱ��
	emit start_Play(m_all_time);
}