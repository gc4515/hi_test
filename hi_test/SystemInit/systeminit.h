#ifndef SYSTEMINIT_H
#define SYSTEMINIT_H

#include <QObject>
#include "chead.h"
#include "vdec.h"
#include "venc.h"

class SystemInit : public QObject
{
    Q_OBJECT
public:
    explicit SystemInit(QObject *parent = 0);
    ~SystemInit();
    HI_S32 Mpp_ModuleInit();
    HI_S32 Vi_ModuleInit();
    HI_S32 Venc_ModuleInit();
    HI_S32 Vpss_ModuleInit();
    HI_S32 Vdec_ModuleInit();
    HI_S32 Vo_ModuleInit();
    HI_VOID ViBindVo();
    //HI_S32 ModulesInit();
    HI_S32 HifbInit();

    HI_S32 SAMPLE_Vdec_CreateVdecChn(HI_S32 s32ChnId,SIZE_S *pstSize,PAYLOAD_TYPE_E enType,VIDEO_MODE_E enVdecMode);
signals:

public slots:
    void slotVideoPlayStart();
private:
    VO_DEV m_Vodev;
    VIDEO_NORM_E gs_enNorm;//定义输出视频设备制式
    HI_U32 m_u32ViFrmRate;  //定义输入SrcFrmRate

    VB_CONF_S stVbConf; //定义视频缓存池属性结构体
    HI_U32 u32BlkSize;
    HI_S32 s32Ret;  //函数返回值：success or error code;
    HI_U32 u32ViChnCnt;//定义输入通道总数
    SAMPLE_VI_MODE_E enViMode;//定义输入模式
    SIZE_S stSize;      //定义图像大小


};

#endif // SYSTEMINIT_H
