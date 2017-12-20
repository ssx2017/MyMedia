// Mixer.h: interface for the CMixer class.     
//     
//////////////////////////////////////////////////////////////////////     
    
//#ifdefined(AFX_MIXER_H__7369BAA5_012E_467E_AD1E_A383E4474C58__INCLUDED_)     
#define AFX_MIXER_H__7369BAA5_012E_467E_AD1E_A383E4474C58__INCLUDED_     
#define WIN32_LEAN_AND_MEAN   // Exclude rarely-used stuff from Windows headers     
    
#include "windows.h"     
#include <mmsystem.h>     
#if _MSC_VER > 1000     
#pragma once     
#endif // _MSC_VER > 1000     
    
class CMixer      
{     
public:     
	CMixer();     
	CMixer(const int VolRange);     
	virtual ~CMixer();     
	enum MixerDeice{     
		SPEAKERS=0,     
		WAVEOUT,     
		SYNTHESIZER,     
		MICROPHONE     
	};     
    
	bool GetMute(MixerDeice dev);   //����豸�Ƿ���     
	bool SetMute(MixerDeice dev,bool vol);     //�����豸����     
	bool SetVolume(MixerDeice dev,long vol);   //�����豸������     
	unsigned GetVolume(MixerDeice dev);    //�õ��豸������dev=0��������1WAVE ,2MIDI ,3 LINE IN     
    
private:     
	bool GetVolumeControl(HMIXER hmixer ,long componentType,long ctrlType,MIXERCONTROL* mxc);     
	bool SetVolumeValue(HMIXER hmixer ,MIXERCONTROL *mxc, long volume);     
	bool SetMuteValue(HMIXER hmixer ,MIXERCONTROL *mxc, bool mute);     
	unsigned GetVolumeValue(HMIXER hmixer ,MIXERCONTROL *mxc);     
	long GetMuteValue(HMIXER hmixer ,MIXERCONTROL *mxc);     
    
    
	long m_VolRange ;     
}; 