/*
	Copyright (c) 2013-2015 EasyDarwin.ORG.  All rights reserved.
	Github: https://github.com/EasyDarwin
	WEChat: EasyDarwin
	Website: http://www.easydarwin.org
*/
#ifndef _Easy_Types_H
#define _Easy_Types_H

#ifdef _WIN32
#define Easy_API  __declspec(dllexport)
#define Easy_APICALL  __stdcall
#define WIN32_LEAN_AND_MEAN
#else
#define Easy_API
#define Easy_APICALL 
#endif

// Handle Type
#define Easy_RTSP_Handle void*
#define Easy_Pusher_Handle void*
#define Easy_HLS_Handle void*

typedef int						Easy_I32;

typedef unsigned char           Easy_U8;
typedef unsigned char           Easy_UChar;
typedef unsigned short          Easy_U16;
typedef unsigned int            Easy_U32;
typedef unsigned char			Easy_Bool;

enum
{
    Easy_NoErr						= 0,
    Easy_RequestFailed				= -1,
    Easy_Unimplemented				= -2,
    Easy_RequestArrived				= -3,
    Easy_OutOfState					= -4,
    Easy_NotAModule					= -5,
    Easy_WrongVersion				= -6,
    Easy_IllegalService				= -7,
    Easy_BadIndex					= -8,
    Easy_ValueNotFound				= -9,
    Easy_BadArgument				= -10,
    Easy_ReadOnly					= -11,
	Easy_NotPreemptiveSafe			= -12,
    Easy_NotEnoughSpace				= -13,
    Easy_WouldBlock					= -14,
    Easy_NotConnected				= -15,
    Easy_FileNotFound				= -16,
    Easy_NoMoreData					= -17,
    Easy_AttrDoesntExist			= -18,
    Easy_AttrNameExists				= -19,
    Easy_InstanceAttrsNotAllowed	= -20,
	Easy_InvalidSocket				= -21,
	Easy_MallocError				= -22,
	Easy_ConnectError				= -23,
	Easy_SendError					= -24
};
typedef int Easy_Error;


typedef enum __EASY_ACTIVATE_ERR_CODE_ENUM
{
	EASY_ACTIVATE_INVALID_KEY		=		-1,			/* ��ЧKey */
	EASY_ACTIVATE_TIME_ERR			=		-2,			/* ʱ����� */
	EASY_ACTIVATE_PROCESS_NAME_LEN_ERR	=	-3,			/* �������Ƴ��Ȳ�ƥ�� */
	EASY_ACTIVATE_PROCESS_NAME_ERR	=		-4,			/* �������Ʋ�ƥ�� */
	EASY_ACTIVATE_VALIDITY_PERIOD_ERR=		-5,			/* ��Ч��У�鲻һ�� */
	EASY_ACTIVATE_PLATFORM_ERR		=		-6,			/* ƽ̨��ƥ�� */
	EASY_ACTIVATE_COMPANY_ID_LEN_ERR=		-7,			/* ��Ȩʹ���̲�ƥ�� */
	EASY_ACTIVATE_SUCCESS			=		0,			/* ����ɹ� */

}EASY_ACTIVATE_ERR_CODE_ENUM;


/* ��Ƶ���� */
#define EASY_SDK_VIDEO_CODEC_H264	0x1C		/* H264  */
#define EASY_SDK_VIDEO_CODEC_H265	0x48323635	/* 1211250229 */
#define	EASY_SDK_VIDEO_CODEC_MJPEG	0x08		/* MJPEG */
#define	EASY_SDK_VIDEO_CODEC_MPEG4	0x0D		/* MPEG4 */

/* ��Ƶ���� */
#define EASY_SDK_AUDIO_CODEC_AAC	0x15002		/* AAC */
#define EASY_SDK_AUDIO_CODEC_G711U	0x10006		/* G711 ulaw*/
#define EASY_SDK_AUDIO_CODEC_G711A	0x10007		/* G711 alaw*/
#define EASY_SDK_AUDIO_CODEC_G726	0x1100B		/* G726 */

#define EASY_SDK_EVENT_CODEC_ERROR	0x63657272	/* ERROR */
#define EASY_SDK_EVENT_CODEC_EXIT	0x65786974	/* EXIT */

/* ����Ƶ֡��ʶ */
#define EASY_SDK_VIDEO_FRAME_FLAG	0x00000001		/* ��Ƶ֡��־ */
#define EASY_SDK_AUDIO_FRAME_FLAG	0x00000002		/* ��Ƶ֡��־ */
#define EASY_SDK_EVENT_FRAME_FLAG	0x00000004		/* �¼�֡��־ */
#define EASY_SDK_RTP_FRAME_FLAG		0x00000008		/* RTP֡��־ */
#define EASY_SDK_SDP_FRAME_FLAG		0x00000010		/* SDP֡��־ */
#define EASY_SDK_MEDIA_INFO_FLAG	0x00000020		/* ý�����ͱ�־*/

/* ��Ƶ�ؼ��ֱ�ʶ */
#define EASY_SDK_VIDEO_FRAME_I		0x01		/* I֡ */
#define EASY_SDK_VIDEO_FRAME_P		0x02		/* P֡ */
#define EASY_SDK_VIDEO_FRAME_B		0x03		/* B֡ */
#define EASY_SDK_VIDEO_FRAME_J		0x04		/* JPEG */

/* �������� */
typedef enum __EASY_RTP_CONNECT_TYPE
{
	EASY_RTP_OVER_TCP	=	0x01,		/* RTP Over TCP */
	EASY_RTP_OVER_UDP					/* RTP Over UDP */
}EASY_RTP_CONNECT_TYPE;

/* ý����Ϣ */
typedef struct __EASY_MEDIA_INFO_T
{
	Easy_U32 u32VideoCodec;				/* ��Ƶ�������� */
	Easy_U32 u32VideoFps;				/* ��Ƶ֡�� */
	Easy_U32 u32VideoQueueSize;			/* ��Ƶ�����С	*/

	Easy_U32 u32AudioCodec;				/* ��Ƶ�������� */
	Easy_U32 u32AudioSamplerate;		/* ��Ƶ������ */
	Easy_U32 u32AudioChannel;			/* ��Ƶͨ���� */
	Easy_U32 u32AudioBitsPerSample;		/* ��Ƶ�������� */
	Easy_U32 u32AudioQueueSize;			/* ��Ƶ�����С	*/

	Easy_U32 u32VpsLength;			/* ��Ƶvps֡���� */
	Easy_U32 u32SpsLength;			/* ��Ƶsps֡���� */
	Easy_U32 u32PpsLength;			/* ��Ƶpps֡���� */
	Easy_U32 u32SeiLength;			/* ��Ƶsei֡���� */
	Easy_U8	 u8Vps[255];			/* ��Ƶvps֡���� */
	Easy_U8	 u8Sps[255];			/* ��Ƶsps֡���� */
	Easy_U8	 u8Pps[128];				/* ��Ƶsps֡���� */
	Easy_U8	 u8Sei[128];				/* ��Ƶsei֡���� */
}EASY_MEDIA_INFO_T;


typedef enum __EASY_PLAY_CTRL_CMD_ENUM
{
	EASY_PLAY_CTRL_CMD_GET_DURATION	=	0x00000001,	//��ȡ¼��ʱ��
	EASY_PLAY_CTRL_CMD_PAUSE	=	0x00000002,	//��ͣ
	EASY_PLAY_CTRL_CMD_RESUME,					//�ָ�
	EASY_PLAY_CTRL_CMD_SCALE,					//��������
	EASY_PLAY_CTRL_CMD_SEEK_STREAM,				//��תʱ��
	//EASY_PLAY_CTRL_CMD_FRAME_BY_FRAME,			//��֡
}EASY_PLAY_CTRL_CMD_ENUM;
typedef struct __EASY_PLAY_CONTROL_INFO_T
{
	EASY_PLAY_CTRL_CMD_ENUM	ctrlCommand;
	float		scale;
	Easy_U8		startTime[36];
	Easy_U8		endTime[36];

	char		suffix[256];
}EASY_PLAY_CONTROL_INFO_T;


/* ֡��Ϣ */
typedef struct 
{
	unsigned int	codec;				/* ����Ƶ��ʽ */

	unsigned int	type;				/* ��Ƶ֡���� */
	unsigned char	fps;				/* ��Ƶ֡�� */
	unsigned short	width;				/* ��Ƶ�� */
	unsigned short  height;				/* ��Ƶ�� */

	unsigned int	reserved1;			/* �������1 */
	unsigned int	reserved2;			/* �������2 */

	unsigned int	sample_rate;		/* ��Ƶ������ */
	unsigned int	channels;			/* ��Ƶ������ */
	unsigned int	bits_per_sample;	/* ��Ƶ�������� */

	unsigned int	length;				/* ����Ƶ֡��С */
	unsigned int    timestamp_usec;		/* ʱ���,΢�� */
	unsigned int	timestamp_sec;		/* ʱ��� �� */
	
	float			bitrate;			/* ������ */
	float			losspacket;			/* ������ */
}RTSP_FRAME_INFO;

#endif
