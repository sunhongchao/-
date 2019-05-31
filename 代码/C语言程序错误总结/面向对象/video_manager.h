
#ifndef _VIDEO_MANAGER_H
#define _VIDEO_MANAGER_H


#define NB_BUFFER 4

struct VideoDevice;
struct VideoOpr;
typedef struct VideoDevice T_VideoDevice, *PT_VideoDevice;
typedef struct VideoOpr T_VideoOpr, *PT_VideoOpr;
typedef struct VideoOpr {
    char *name;
    int (*InitDevice)(char *strDevName, PT_VideoDevice ptVideoDevice);
    int (*ExitDevice)(PT_VideoDevice ptVideoDevice);
    int (*GetFrame)(PT_VideoDevice ptVideoDevice, PT_VideoBuf ptVideoBuf);
    int (*PutFrame)(PT_VideoDevice ptVideoDevice, PT_VideoBuf ptVideoBuf);
    int (*StartDevice)(PT_VideoDevice ptVideoDevice);
    int (*StopDevice)(PT_VideoDevice ptVideoDevice);
}T_VideoOpr, *PT_VideoOpr;
typedef struct VideoDevice {
    int iFd;
    int iPixelFormat;
    int iWidth;
    int iHeight;

    int iVideoBufCnt;
    int iVideoBufMaxLen;
    int iVideoBufCurIndex;
    unsigned char *pucVideBuf[NB_BUFFER];

    /* º¯Êý */
    PT_VideoOpr ptOPr;
}T_VideoDevice, *PT_VideoDevice;

typedef struct VideoBuf {
   
    int iPixelFormat;
}T_VideoBuf, *PT_VideoBuf;




int V4l2Init(void);

#endif /* _VIDEO_MANAGER_H */

