#ifndef __HC_USB_SDK_H__
#define __HC_USB_SDK_H__

#if defined _WIN32 || defined _WIN64
#define USB_SDK_API  extern "C" __declspec(dllimport)
#elif defined __linux__ || defined __APPLE__
#define USB_SDK_API  extern "C"
#endif

#if defined _WIN32 || defined _WIN64
#define CALLBACK __stdcall
#elif defined __linux__ || defined __APPLE__
#define CALLBACK  
#endif

#if (defined(_WIN32)) //windows
#include <Windows.h>
typedef  unsigned __int64   UINT64;
typedef  signed   __int64   INT64;
#elif defined(__linux__) || defined(__APPLE__) //linux
    #define  BOOL  int
    typedef  unsigned int       DWORD;
    typedef  unsigned short     WORD;
    typedef  unsigned short     USHORT;
    typedef  short              SHORT;
    typedef  int                LONG;
    typedef  unsigned long      ULONG;
    typedef  unsigned char      BYTE;
    typedef  unsigned int       UINT;
    typedef  void*              LPVOID;
    typedef  void*              HANDLE;
    typedef  unsigned int*      LPDWORD;
    typedef  unsigned long long UINT64;
    typedef  signed long long   INT64;

    #ifndef TRUE
        #define TRUE  1
    #endif
    #ifndef FALSE
        #define FALSE 0
    #endif
    #ifndef NULL
        #define NULL 0
    #endif

    #define __stdcall 
    #define CALLBACK  

    typedef unsigned int   COLORKEY;
    typedef unsigned int   COLORREF;

    #ifndef __HWND_defined
        #define __HWND_defined
        #if defined(__APPLE__) || defined(ANDROID)
            typedef void* HWND;
        #elif defined(__linux__)
            typedef unsigned int HWND;
        #else
            typedef void* HWND;
        #endif
    #endif

    #ifndef __HDC_defined
        #define __HDC_defined
        #if defined(__linux__)
            typedef struct __DC
            {
                void*   surface;        //SDL Surface
                HWND    hWnd;           //HDC window handle
            }DC;
            typedef DC* HDC;
        #else
          typedef void* HDC;
        #endif
    #endif

    typedef struct tagInitInfo
    {
        int uWidth;
        int uHeight;
    }INITINFO;
#endif

#if defined(_WIN64)
    #define OS_WINDOWS64    1
#endif

#if defined(__LP64__)
    #define OS_POSIX64    1 
#endif

#define USB_INVALID_UPGRADE_HANDLE -1
#define USB_UPGRADE_FAILED     0
#define USB_UPGRADE_SUCCESS    1
#define USB_UPGRADE_TRANS      2
#define USB_UPGRADE_FLASH_FAILED 4
#define USB_UPGRADE_TYPE_UNMATCH 5
#define USB_UPGRADE_WRITE_FLASH  6

//-----------------------------------------------------------------------------------------
#define USB_ERROR_BASE                 0

#define USB_SUCCESS                    (USB_ERROR_BASE+0)   // Success (no error)

    //SDK�ڲ�������
#define USB_ERROR_INIT_SDK             (USB_ERROR_BASE+1)
#define USB_ERROR_SDK_NOT_INIT         (USB_ERROR_BASE+2)
#define USB_ERROR_NO_DEVICE            (USB_ERROR_BASE+3)   // No such device (it may have been disconnected)

#define USB_ERROR_ACCESS               (USB_ERROR_BASE+4)   // Access denied (insufficient permissions)
#define USB_ERROR_OPEN                 (USB_ERROR_BASE+5)
#define USB_ERROR_DEV_NOT_READY        (USB_ERROR_BASE+6)
#define USB_ERROR_IO                   (USB_ERROR_BASE+7)   // Input/output error
#define USB_ERROR_WRITE                (USB_ERROR_BASE+8)
#define USB_ERROR_READ                 (USB_ERROR_BASE+9)
#define USB_ERROR_TIMEOUT              (USB_ERROR_BASE+10)   // Operation timed out
#define USB_ERROR_WRITE_TIMEOUT        (USB_ERROR_BASE+11)
#define USB_ERROR_READ_TIMEOUT         (USB_ERROR_BASE+12)
#define USB_ERROR_BUSY                 (USB_ERROR_BASE+13)   // Resource busy
#define USB_ERROR_WRITE_BUSY           (USB_ERROR_BASE+14)
#define USB_ERROR_READ_BUSY            (USB_ERROR_BASE+15)
#define USB_ERROR_CLOSE                (USB_ERROR_BASE+16)  //
#define USB_ERROR_OVERFLOW             (USB_ERROR_BASE+17)  // Overflow
#define USB_ERROR_NO_MEM               (USB_ERROR_BASE+18)  // Insufficient memory
#define USB_ERROR_PIPE                 (USB_ERROR_BASE+19)  // Pipe error
#define USB_ERROR_INTERRUPTED          (USB_ERROR_BASE+20)  // System call interrupted (perhaps due to signal)
#define USB_ERROR_NOT_SUPPORTED        (USB_ERROR_BASE+21)  // Operation not supported or unimplemented on this platform
#define USB_ERROR_WAIT_OBJ             (USB_ERROR_BASE+22)

#define USB_ERROR_RECV_PACK_TIMEOUT    (USB_ERROR_BASE+27)
#define USB_ERROR_RECV_DATA_LEN        (USB_ERROR_BASE+28)
#define USB_ERROR_PARAM_INVALID        (USB_ERROR_BASE+29)
#define USB_ERROR_INVALID_PORT          (USB_ERROR_BASE+30)   // ��ЧPort
#define USB_ERROR_INVALID_PATH          (USB_ERROR_BASE+31)   // ��Ч·��
#define USB_ERROR_INVALID_CMD           (USB_ERROR_BASE+32)   // ��Ч������
#define USB_ERROR_INVALID_POINTER       (USB_ERROR_BASE+33)   // ��Чָ��

#define USB_ERROR_INVALID_HANDLE       (USB_ERROR_BASE+38)    // ��Ч���
#define USB_ERROR_INVALID_USER_ID      (USB_ERROR_BASE+39)
#define USB_ERROR_INVALID_DEVICE_ID    (USB_ERROR_BASE+40)
#define USB_ERROR_INVALID_SEESSION_ID  (USB_ERROR_BASE+41)
#define USB_ERROR_CHECKSUM_FAILED      (USB_ERROR_BASE+42)
#define USB_ERROR_INTER_STRUCT_SIZE    (USB_ERROR_BASE+43)
#define USB_ERROR_EXTER_STRUCT_SIZE    (USB_ERROR_BASE+44)
#define USB_ERROR_STRUCT_HEAD_VER      (USB_ERROR_BASE+45)
#define USB_ERROR_REG_SEESION          (USB_ERROR_BASE+46)
#define USB_ERROR_CONVERT_PARAM        (USB_ERROR_BASE+47)
#define USB_ERROR_INTER_CMD_NOT_DEF    (USB_ERROR_BASE+48)
#define USB_ERROR_EXTERNAL_CMD_NOT_DEF (USB_ERROR_BASE+49)
#define USB_ERROR_GET_DEV_ENCRY        (USB_ERROR_BASE+50)
#define USB_ERROR_GET_DEV_AES          (USB_ERROR_BASE+51)
#define USB_ERROR_DEV_NOT_SUPPOTR_AES  (USB_ERROR_BASE+52)
#define USB_ERROR_DEV_NOT_SUPPOTR_CRC  (USB_ERROR_BASE+53)
#define USB_ERROR_SDK_AES_MOD          (USB_ERROR_BASE+54)
#define USB_ERROR_SDK_AES_KEY          (USB_ERROR_BASE+55)
#define USB_ERROR_SDK_AES_KEY_LEN      (USB_ERROR_BASE+56)
#define USB_ERROR_SDK_AES_KEY_TYPE     (USB_ERROR_BASE+57)
#define USB_ERROR_SDK_AES_PROCESS      (USB_ERROR_BASE+58)
#define USB_ERROR_AES_INPUT_DATA_LEN   (USB_ERROR_BASE+59)
#define USB_ERROR_GET_DEV_AES_KEY      (USB_ERROR_BASE+60)
#define USB_ERROR_DEV_REG              (USB_ERROR_BASE+61)
#define USB_ERROR_LOGIN                (USB_ERROR_BASE+62)
#define USB_ERROR_RELOGIN              (USB_ERROR_BASE+63)
#define USB_ERROR_LOGOUT               (USB_ERROR_BASE+64)
#define USB_ERROR_RET_HEAD_LENGTH      (USB_ERROR_BASE+65)
#define USB_ERROR_RET_HEAD_VERSION     (USB_ERROR_BASE+66)
#define USB_ERROR_RET_HEAD             (USB_ERROR_BASE+67)
#define USB_ERROR_RET_DATA_LEN         (USB_ERROR_BASE+68)
#define USB_ERROR_READ_FILE            (USB_ERROR_BASE+69)
#define USB_ERROR_INACTIVED            (USB_ERROR_BASE+70)   //The device don't be actived
#define USB_ERROR_ACTIVED              (USB_ERROR_BASE+71)   //The device has actived
#define USB_ERROR_NO_RIGHTS            (USB_ERROR_BASE+72)   //no rights
#define USB_ERROR_NO_LOGIN             (USB_ERROR_BASE+73)  
#define USB_ERROR_RECEIVED_DATA        (USB_ERROR_BASE+74)   // The data is invalid received from device
#define USB_ERROR_RISKY_PASSWORD       (USB_ERROR_BASE+75)   //The risky password
#define USB_ERROR_LOAD_LIBRARY         (USB_ERROR_BASE+76)  //���ؿ�ʧ��
#define USB_ERROR_ALLOC_RESOURCE       (USB_ERROR_BASE+77)  //��Դ����������̣߳�����

#define USB_ERROR_FILE_OPEN            (USB_ERROR_BASE+80)  // �ļ���ʧ��
#define USB_ERROR_FILE_WRITE           (USB_ERROR_BASE+81)  // �ļ�дʧ��
#define USB_ERROR_CALL_DISORDER        (USB_ERROR_BASE+82)  // ����˳�򲻶�
#define USB_ERROR_INITOBSERVER         (USB_ERROR_BASE+83)  // ��ʼ���۲���ʧ��
#define USB_ERROR_NOT_SUPPORTED_FORMAT (USB_ERROR_BASE+84)  // ��֧�ֵ�����Ƶ��ʽ
#define USB_ERROR_NOT_SUPPORTED_AUDIO  (USB_ERROR_BASE+85)  // ���豸��֧����Ƶ
#define USB_ERROR_INIT_LIBUSB          (USB_ERROR_BASE+86)  // ��ʼ��libusbʧ��
#define USB_ERROR_INIT_LIBUVC          (USB_ERROR_BASE+87)  // ��ʼ��libuvcʧ��
#define USB_ERROR_INIT_DIRECTSHOW      (USB_ERROR_BASE+88)  // ��ʼ��directshowʧ��
#define USB_ERROR_NO_MATCH_IR_FRAME    (USB_ERROR_BASE+89)  // δƥ�䵽IR֡

//�豸��ش�����
#define USB_ERROR_DEV_OPER_FAILED      (USB_ERROR_BASE+257)  // ����ʧ��
#define USB_ERROR_DEV_OPER_NOT_SUPPORT (USB_ERROR_BASE+258)  // �豸��֧�ָò���
#define USB_ERROR_DEV_CHECK_SUM        (USB_ERROR_BASE+259)  // У��ʹ���
#define USB_ERROR_DEV_USER_ID          (USB_ERROR_BASE+260)  // �Ƿ���UserID
#define USB_ERROR_DEV_SESSION_ID       (USB_ERROR_BASE+261)  // �Ƿ���SessionID
#define USB_ERROR_DEV_OPER_TIMEOUT     (USB_ERROR_BASE+262)  // �豸������ʱ
#define USB_ERROR_DEV_PASSWORD_ERROR   (USB_ERROR_BASE+266)  // Username or Password Error
#define USB_ERROR_DEV_USER_LOCKED      (USB_ERROR_BASE+267)  // Device locked
#define USB_ERROR_DEV_UNKNOW_OPER_RES  (USB_ERROR_BASE+512)  // δ֪���豸����������


/************************************************************************
* ת��װ�������
************************************************************************/
#define USB_ERROR_SYSTRANS_HANDLE       (USB_ERROR_BASE+600)  //ת���������
#define USB_ERROR_SYSTRANS_SUPPORT      (USB_ERROR_BASE+601)  //���Ͳ�֧��
#define USB_ERROR_SYSTRANS_RESOURCE     (USB_ERROR_BASE+602)  //��Դ������ͷŴ���
#define USB_ERROR_SYSTRANS_PARA         (USB_ERROR_BASE+603)  //��������
#define USB_ERROR_SYSTRANS_PRECONDITION (USB_ERROR_BASE+604)  //ǰ������δ���㣬����˳��
#define USB_ERROR_SYSTRANS_OVERFLOW     (USB_ERROR_BASE+605)  //�������
#define USB_ERROR_SYSTRANS_STOP         (USB_ERROR_BASE+606)  //ֹͣ״��
#define USB_ERROR_SYSTRANS_FILE         (USB_ERROR_BASE+607)  //�ļ�����
#define USB_ERROR_SYSTRANS_MAX_HANDLE   (USB_ERROR_BASE+608)  //���·������
#define USB_ERROR_SYSTRANS_MUXER        (USB_ERROR_BASE+609)  //�ײ�mp4�����������
#define USB_ERROR_SYSTRANS_FAIL         (USB_ERROR_BASE+610)  //̽��ʧ��
#define USB_ERROR_SYSTRANS_ENCAP        (USB_ERROR_BASE+611)  //��ʽģʽ��֧�֣���ASF��AVI��MP4��

/************************************************************************
* ת��������
************************************************************************/
#define USB_ERROR_FC_HANDLE         (USB_ERROR_BASE+700)  ///< �������Ч�ľ��
#define USB_ERROR_FC_SUPPORT        (USB_ERROR_BASE+701)  ///< ��֧�ֵĹ���
#define USB_ERROR_FC_BUFOVER        (USB_ERROR_BASE+702)  ///< ��������
#define USB_ERROR_FC_CALLORDER      (USB_ERROR_BASE+703)  ///< ��������˳�����
#define USB_ERROR_FC_PARAMETER      (USB_ERROR_BASE+704)  ///< ����Ĳ���
#define USB_ERROR_FC_NEEDMOREDATA   (USB_ERROR_BASE+705)  ///< ��Ҫ���������
#define USB_ERROR_FC_RESOURCE       (USB_ERROR_BASE+706)  ///< ��Դ����ʧ��
#define USB_ERROR_FC_STREAM         (USB_ERROR_BASE+707)  ///< ��������
#define USB_ERROR_FC_DEMUXER        (USB_ERROR_BASE+708)  ///< �����쳣
#define USB_ERROR_FC_MUXER          (USB_ERROR_BASE+709)  ///< ����쳣
#define USB_ERROR_FC_DECODER        (USB_ERROR_BASE+710)  ///< �����쳣
#define USB_ERROR_FC_ENCODER        (USB_ERROR_BASE+711)  ///< �����쳣
#define USB_ERROR_FC_POSTPROC       (USB_ERROR_BASE+712)  ///< �����쳣
#define USB_ERROR_FC_FILE           (USB_ERROR_BASE+713)  ///< �ļ������쳣

/************************************************************************
* ���ſ������
************************************************************************/
#define  USB_ERROR_PLAYM4_PARA_OVER                       (USB_ERROR_BASE+801)   //input parameter is invalid;
#define  USB_ERROR_PLAYM4_ORDER_ERROR                     (USB_ERROR_BASE+802)   //The order of the function to be called is error.
#define  USB_ERROR_PLAYM4_TIMER_ERROR                     (USB_ERROR_BASE+803)   //Create multimedia clock failed;
#define  USB_ERROR_PLAYM4_DEC_VIDEO_ERROR                 (USB_ERROR_BASE+804)   //Decode video data failed.
#define  USB_ERROR_PLAYM4_DEC_AUDIO_ERROR                 (USB_ERROR_BASE+805)   //Decode audio data failed.
#define  USB_ERROR_PLAYM4_ALLOC_MEMORY_ERROR              (USB_ERROR_BASE+806)   //Allocate memory failed.
#define  USB_ERROR_PLAYM4_OPEN_FILE_ERROR                 (USB_ERROR_BASE+807)   //Open the file failed.
#define  USB_ERROR_PLAYM4_CREATE_OBJ_ERROR                (USB_ERROR_BASE+808)   //Create thread or event failed
#define  USB_ERROR_PLAYM4_CREATE_DDRAW_ERROR              (USB_ERROR_BASE+809)   //Create DirectDraw object failed.
#define  USB_ERROR_PLAYM4_CREATE_OFFSCREEN_ERROR          (USB_ERROR_BASE+810)  //failed when creating off-screen surface.
#define  USB_ERROR_PLAYM4_BUF_OVER                        (USB_ERROR_BASE+811)  //buffer is overflow
#define  USB_ERROR_PLAYM4_CREATE_SOUND_ERROR              (USB_ERROR_BASE+812)  //failed when creating audio device.	
#define  USB_ERROR_PLAYM4_SET_VOLUME_ERROR                (USB_ERROR_BASE+813)  //Set volume failed
#define  USB_ERROR_PLAYM4_SUPPORT_FILE_ONLY               (USB_ERROR_BASE+814)  //The function only support play file.
#define  USB_ERROR_PLAYM4_SUPPORT_STREAM_ONLY             (USB_ERROR_BASE+815)  //The function only support play stream.
#define  USB_ERROR_PLAYM4_SYS_NOT_SUPPORT                 (USB_ERROR_BASE+816)  //System not support.
#define  USB_ERROR_PLAYM4_FILEHEADER_UNKNOWN              (USB_ERROR_BASE+817)  //No file header.
#define  USB_ERROR_PLAYM4_VERSION_INCORRECT               (USB_ERROR_BASE+818)  //The version of decoder and encoder is not adapted.  
#define  USB_ERROR_PLAYM4_INIT_DECODER_ERROR              (USB_ERROR_BASE+819)  //Initialize decoder failed.
#define  USB_ERROR_PLAYM4_CHECK_FILE_ERROR                (USB_ERROR_BASE+820)  //The file data is unknown.
#define  USB_ERROR_PLAYM4_INIT_TIMER_ERROR                (USB_ERROR_BASE+821)  //Initialize multimedia clock failed.
#define  USB_ERROR_PLAYM4_BLT_ERROR                       (USB_ERROR_BASE+822)  //Blt failed.
#define  USB_ERROR_PLAYM4_UPDATE_ERROR                    (USB_ERROR_BASE+823)  //Update failed.
#define  USB_ERROR_PLAYM4_OPEN_FILE_ERROR_MULTI           (USB_ERROR_BASE+824)  //openfile error, streamtype is multi
#define  USB_ERROR_PLAYM4_OPEN_FILE_ERROR_VIDEO           (USB_ERROR_BASE+825)  //openfile error, streamtype is video
#define  USB_ERROR_PLAYM4_JPEG_COMPRESS_ERROR             (USB_ERROR_BASE+826)  //JPEG compress error
#define  USB_ERROR_PLAYM4_EXTRACT_NOT_SUPPORT             (USB_ERROR_BASE+827)  //Don't support the version of this file.
#define  USB_ERROR_PLAYM4_EXTRACT_DATA_ERROR              (USB_ERROR_BASE+828)  //extract video data failed.
#define  USB_ERROR_PLAYM4_SECRET_KEY_ERROR                (USB_ERROR_BASE+829)  //Secret key is error //add 20071218
#define  USB_ERROR_PLAYM4_DECODE_KEYFRAME_ERROR           (USB_ERROR_BASE+830)  //add by hy 20090318
#define  USB_ERROR_PLAYM4_NEED_MORE_DATA                  (USB_ERROR_BASE+831)  //add by hy 20100617
#define  USB_ERROR_PLAYM4_INVALID_PORT                    (USB_ERROR_BASE+832)  //add by cj 20100913
#define  USB_ERROR_PLAYM4_NOT_FIND                        (USB_ERROR_BASE+833)  //add by cj 20110428
#define  USB_ERROR_PLAYM4_NEED_LARGER_BUFFER              (USB_ERROR_BASE+834)  //add by pzj 20130528

/************************************************************************
* directshow������
************************************************************************/
#define  USB_ERROR_DIRECT_SHOW              (USB_ERROR_BASE+900)

/************************************************************************
* �����������
************************************************************************/
#define USB_HIA_ERROR_MALLOC      (USB_ERROR_BASE + 1001)     ///< �ڴ�����ʧ��
#define USB_HIA_ERROR_THREAD      (USB_ERROR_BASE + 1002)     ///< �����߳�ʧ��
#define USB_HIA_ERROR_RESOURCE    (USB_ERROR_BASE + 1003)     ///< ��Դ����
#define USB_HIA_ERROR_SUPPORT     (USB_ERROR_BASE + 1004)     ///< ��֧�ֲ���
#define USB_HIA_ERROR_PARAM       (USB_ERROR_BASE + 1005)     ///< ��������
#define USB_HIA_ERROR_INIT        (USB_ERROR_BASE + 1006)     ///< δ��ʼ��
#define USB_HIA_ERROR_OPERATE     (USB_ERROR_BASE + 1007)     ///< ����˳�����

#define USB_HIA_ERROR_DECODE      (USB_ERROR_BASE + 1008)     ///< ����ʧ��
#define USB_HIA_ERROR_XML         (USB_ERROR_BASE + 1009)     ///< xml��������
#define USB_HIA_ERROR_NOT_MATCH   (USB_ERROR_BASE + 1010)    ///< �汾��ƥ��
#define USB_HIA_ERROR_OVERFLOW    (USB_ERROR_BASE + 1011)    ///<  ���
#define USB_HIA_ERROR_RESOLUTION  (USB_ERROR_BASE + 1012)    ///< �ֱ��ʲ�֧��
#define USB_HIA_ERROR_FORMAT      (USB_ERROR_BASE + 1013)    ///< �����ʽ��֧��
#define USB_HIA_ERROR_SEND        (USB_ERROR_BASE + 1014)    ///< ��������ʧ��
#define USB_HIA_ERROR_RECV        (USB_ERROR_BASE + 1015)    ///< ��������ʧ��
#define USB_HIA_ERROR_SOCKET      (USB_ERROR_BASE + 1016)    ///< socket���󣬰������������ӵ�
#define USB_HIA_ERROR_OSAPI       (USB_ERROR_BASE + 1017)    ///< ϵͳ��������
#define USB_HIA_ERROR_JSON        (USB_ERROR_BASE + 1018)    ///< json����
#define USB_HIA_ERROR_IMG         (USB_ERROR_BASE + 1019)    ///< ͼƬ����ʧ�ܣ� ������ͼ�� ѹ������ͼ��ͼƬת���ȡ�
#define USB_HIA_ERROR_LACK        (USB_ERROR_BASE + 1020)    //   ���ݲ���
#define USB_HIA_ERROR_ENCRYTE     (USB_ERROR_BASE + 1021)     ///< ����ʧ��
#define USB_HIA_ERROR_CREATE      (USB_ERROR_BASE + 1022)     ///< �㷨�ⴴ��ʧ��
#define USB_HIA_ERROR_PROCESS     (USB_ERROR_BASE + 1023)     ///< �㷨��������
#define USB_HIA_ERROR_LOADMODE    (USB_ERROR_BASE + 1024)     ///< ����ģ�ʹ���
#define USB_HIA_ERROR_SETPARAM    (USB_ERROR_BASE + 1025)     //   ���ò�������
#define USB_HIA_ERROR_GETPARAM    (USB_ERROR_BASE + 1026)     //   ��ȡ��������
#define USB_HIA_ERROR_DESTROY	  (USB_ERROR_BASE + 1027)	  ///<  �㷨������ʧ��
#define USB_HIA_ERROR_FRCNN       (USB_ERROR_BASE + 1028)    //   FRCNNʧ��
#define USB_HIA_ERROR_EXCUTE      (USB_ERROR_BASE + 1029)    ///< ִ��ʧ��
#define USB_HIA_ERROR_TPC         (USB_ERROR_BASE + 1030)    //   TPCʧ��
#define USB_HIA_ERROR_FDRL        (USB_ERROR_BASE + 1031)    //   FDRLʧ��
#define USB_HIA_ERROR_SKIP        (USB_ERROR_BASE + 1032)    //   �����㷨����
#define USB_HIA_ERROR_BLOCK       (USB_ERROR_BASE + 1033)    //<  ����
#define USB_HIA_ERROR_GPUMEMORY    (USB_ERROR_BASE + 1034)   ///< �Դ�����ʧ��
#define USB_HIA_ERROR_CPUMEMORY    (USB_ERROR_BASE + 1035)   ///< �ڴ�����ʧ��
#define USB_HIA_ERROR_AUTHORIZE    (USB_ERROR_BASE + 1036)   ///< ��Ȩʧ��
#define USB_HIA_ERROR_DATACHANGE  (USB_ERROR_BASE + 1047)    //   �ֱ��ʸı�


#define USB_ERROR_NOT_DEFINED          (USB_ERROR_BASE+0x02FE)
#define USB_ERROR_OTHER                (USB_ERROR_BASE+0x02FF)  // Other error
//-----------------------------------------------------------------------------------------

/********************���ô���״̬��*******************/
#define  USB_ERROR_NO_ERROR                                0x00    // No error: The request succeeded
#define  USB_ERROR_DEVICE_REQUEST_NOT_COMPLETE             0x01    // Not Ready: Previous request has not completed
#define  USB_ERROR_DEVICE_WRONG_STATE                      0x02    // Wrong State: In a state that disallows the specific request
#define  USB_ERROR_DEVICE_MODE_ERROR                       0x03    // Power: Current power mode is not sufficient to complete the request
#define  USB_ERROR_SET_PARAM_OVERLIMIT                     0x04    // Out of Range: SET_CUR over limits
#define  USB_ERROR_UNITID_NOT_SUPPORT                      0x05    // Invalid Unit: Unit ID not supported
#define  USB_ERROR_CSID_NOT_SUPPORT                        0x06    // Invalid Control: CS ID not supported
#define  USB_ERROR_REQUEST_TYPE_NOT_SUPPORT                0x07    // Invalid Request: request type not supported
#define  USB_ERROR_SET_PARAM_INVALID                       0x08    // Invalid value with range: SET_CUR invalid value with range
#define  USB_ERROR_SUBFUNCTION_NOT_SUPPORT                 0x09    // Custom: Sub-function not supported
#define  USB_ERROR_DEVICE_EXECUTE_EXCEPTION                0x0a    // Custom: Device inner executing exceptions
#define  USB_ERROR_DEVICE_PROTOCOL_EXCEPTION               0x0b    // Custom: Device inner processing protocol exceptions
#define  USB_ERROR_BULK_DATA_EXCEPTION                     0x0c    // Custom: Bulk data transfer process exceptions
#define  USB_ERROR_UNKNOWN                                 0xff    // Unknown: Unknown
/********************���ô���״̬��*******************/

#define MAX_MANUFACTURE_LEN    32
#define MAX_DEVICE_NAME_LEN    32
#define MAX_SERIAL_NUMBER_LEN     48

#define MAX_USERNAME_LEN       32
#define MAX_PASSWORD_LEN       16
#define MAX_DATA_NUM 8
#define MAX_FILE_PATH_LEN  256
#define USB_INVALID_USERID -1
#define MAX_DATA_NUM 8
#define WORD_LEN               256
#define PIC_LEN                1024
#define FINGER_PRINT_LEN       1024
#define ADDR_LEN               128
#define MAC_LEN                16
#define CARD_NO_LEN            32
#define FINGER_PRINT_MODULE_VERSION_LEN    32    //ָ��ģ�������汾����
#define FINGER_PRINT_MODULE_SERIAL_LEN     64    //ָ��ģ�����кų���
#define SECURITY_MODULE_SERIAL_LEN         16    //��ȫģ�����кų���
#define MAX_FINGER_PRINT       1024*100
#define MAX_PATH_LEN		   260


#define USB_ACS_BASE         1000
#define USB_SET_BEEP_AND_FLICKER        (USB_ACS_BASE)
#define USB_GET_CARD_ISSUE_VERSION      (USB_ACS_BASE + 1)
#define USB_CTRL_RESET_RFC              (USB_ACS_BASE + 2)
#define USB_SET_CARD_PROTO              (USB_ACS_BASE + 3)
#define USB_GET_ACTIVATE_CARD           (USB_ACS_BASE + 4)
#define USB_CTRL_STOP_CARD_OPER         (USB_ACS_BASE + 5)
#define USB_SET_M1_PWD_VERIFY           (USB_ACS_BASE + 6)
#define USB_GET_M1_READ_BLOCK           (USB_ACS_BASE + 7)
#define USB_SET_M1_WRITE_BLOCK          (USB_ACS_BASE + 8)
#define USB_SET_M1_MODIFY_SCB           (USB_ACS_BASE + 9)
#define USB_SET_M1_BLOCK_ADD_VALUE      (USB_ACS_BASE + 10)
#define USB_SET_M1_BLOCK_MINUS_VALUE    (USB_ACS_BASE + 11)
#define USB_CTRL_M1_BLOCK_TO_REG        (USB_ACS_BASE + 12)
#define USB_CTRL_M1_REG_TO_BLOCK        (USB_ACS_BASE + 13)
#define USB_SET_M1_MF_PACK              (USB_ACS_BASE + 14)
    //#define USB_GET_M1_MF_PACK        (USB_ACS_BASE + 15)
#define USB_SET_CARD_PARAM              (USB_ACS_BASE + 16)
#define USB_GET_CPU_CARD_RESET          (USB_ACS_BASE + 17)
#define USB_SET_CPU_CARD_PACK           (USB_ACS_BASE + 18)
    //#define USB_GET_CPU_CARD_PACK         (USB_ACS_BASE + 19)
#define USB_GET_CERTIFICATE_INFO           (USB_ACS_BASE + 20)
#define USB_GET_CERTIFICATE_ADD_ADDR_INFO  (USB_ACS_BASE + 21)
#define USB_GET_CERTIFICATE_MAC            (USB_ACS_BASE + 22)
#define USB_GET_IC_CARD_NO                 (USB_ACS_BASE + 23)
#define USB_DETECT_CARD                 (USB_ACS_BASE + 24)   //��⿨Ƭ
#define USB_SET_IDENTITY_INFO           (USB_ACS_BASE + 25)   //������Ϣ�·�
#define USB_GET_EXTERNAL_DEV_INFO       (USB_ACS_BASE + 26)
#define USB_SET_FINGER_PRINT_OPER_PARAM (USB_ACS_BASE + 27)
#define USB_CAPTURE_FINGER_PRINT         (USB_ACS_BASE + 28)
#define USB_GET_FINGER_PRINT_CONTRAST_RESULT (USB_ACS_BASE + 29)
#define USB_CPU_CARD_ENCRYPT_CFG             (USB_ACS_BASE + 30)  //CPU����������
#define USB_SET_M1_SECTION_ENCRYPT           (USB_ACS_BASE + 31)   //M1��ָ����������

//�ȳ���������
#define USB_THERMAL_BASE                 2000
//#define USB_GET_VIDEO_CAP        (USB_THERMAL_BASE+1)          //��ȡ��Ƶ����
//#define USB_GET_AUDIO_CAP        (USB_THERMAL_BASE+2)          //��ȡ��Ƶ����
//#define USB_GET_VIDEO_FORMAT     (USB_THERMAL_BASE+3)            //��ȡ��Ƶ��ʽ
//#define USB_SET_VIDEO_FORMAT     (USB_THERMAL_BASE+4)             //������Ƶ��ʽ
//#define USB_GET_AUDIO_FORMAT     (USB_THERMAL_BASE+5)           //��ȡ��Ƶ��ʽ
//#define USB_SET_AUDIO_FORMAT     (USB_THERMAL_BASE+6)            //������Ƶ��ʽ
//#define USB_GET_RESOLUTION       (USB_THERMAL_BASE+7)            //��ȡ�ֱ���
//#define USB_SET_RESOLUTION    (USB_THERMAL_BASE+8)            //���÷ֱ���
//#define USB_GET_FRAMERATE     (USB_THERMAL_BASE+9)           //��ȡ֡��
//#define USB_SET_FRAMERATE     (USB_THERMAL_BASE+10)          //����֡��
#define USB_GET_SYSTEM_DEVICE_INFO					(USB_THERMAL_BASE+11)   //��ȡ�豸��Ϣ
#define USB_SET_SYSTEM_REBOOT						(USB_THERMAL_BASE+12)   //�豸����
#define USB_SET_SYSTEM_RESET						(USB_THERMAL_BASE+13)   //�ָ�Ĭ��
#define USB_GET_SYSTEM_HARDWARE_SERVER				(USB_THERMAL_BASE+14)   //��ȡӲ���������
#define USB_SET_SYSTEM_HARDWARE_SERVER				(USB_THERMAL_BASE+15)   //����Ӳ���������
#define USB_GET_SYSTEM_LOCALTIME					(USB_THERMAL_BASE+16)   //��ȡϵͳ����ʱ��
#define USB_SET_SYSTEM_LOCALTIME					(USB_THERMAL_BASE+17)   //����ϵͳ����ʱ��
#define USB_GET_IMAGE_BRIGHTNESS					(USB_THERMAL_BASE+18)   //��ȡͼ�����Ȳ���
#define USB_SET_IMAGE_BRIGHTNESS					(USB_THERMAL_BASE+19)   //����ͼ�����Ȳ���
#define USB_GET_IMAGE_CONTRAST						(USB_THERMAL_BASE+20)   //��ȡͼ��ԱȶȲ���
#define USB_SET_IMAGE_CONTRAST						(USB_THERMAL_BASE+21)   //����ͼ��ԱȶȲ���
#define USB_SET_SYSTEM_UPDATE_FIRMWARE				(USB_THERMAL_BASE+22)   //�豸����
#define USB_SET_IMAGE_BACKGROUND_CORRECT			(USB_THERMAL_BASE+23)   //һ������У��
#define USB_GET_SYSTEM_DIAGNOSED_DATA				(USB_THERMAL_BASE+24)   //�����Ϣ����
#define USB_SET_IMAGE_MANUAL_CORRECT				(USB_THERMAL_BASE+25)   //һ���ֶ�У��
#define USB_GET_IMAGE_ENHANCEMENT					(USB_THERMAL_BASE+26)   //��ȡͼ����ǿ����
#define USB_SET_IMAGE_ENHANCEMENT					(USB_THERMAL_BASE+27)   //����ͼ����ǿ����
#define USB_GET_IMAGE_VIDEO_ADJUST					(USB_THERMAL_BASE+28)   //��ȡ��Ƶ��������
#define USB_SET_IMAGE_VIDEO_ADJUST					(USB_THERMAL_BASE+29)   //������Ƶ��������
#define USB_GET_THERMOMETRY_BASIC_PARAM				(USB_THERMAL_BASE+30)   //��ȡ���»�������
#define USB_SET_THERMOMETRY_BASIC_PARAM				(USB_THERMAL_BASE+31)   //���ò��»�������
#define USB_GET_THERMOMETRY_MODE					(USB_THERMAL_BASE+32)   //��ȡ����ģʽ
#define USB_SET_THERMOMETRY_MODE					(USB_THERMAL_BASE+33)   //���ò���ģʽ
#define USB_GET_THERMOMETRY_REGIONS					(USB_THERMAL_BASE+34)   //��ȡ���¹������
#define USB_SET_THERMOMETRY_REGIONS					(USB_THERMAL_BASE+35)   //���ò��¹������
#define USB_GET_THERMAL_ALG_VERSION					(USB_THERMAL_BASE+36)   //��ȡ�ȳ�������㷨�汾��Ϣ
//#define USB_SET_THERMAL_ALG_VERSION				(USB_THERMAL_BASE+37)   //Ԥ��
#define USB_GET_THERMAL_STREAM_PARAM				(USB_THERMAL_BASE+38)   //��ȡ�ȳ�����������
#define USB_SET_THERMAL_STREAM_PARAM				(USB_THERMAL_BASE+39)   //�����ȳ�����������
#define USB_GET_TEMPERATURE_CORRECT					(USB_THERMAL_BASE+40)   //��ȡ������������
#define USB_SET_TEMPERATURE_CORRECT					(USB_THERMAL_BASE+41)   //���ò�����������
#define USB_GET_BLACK_BODY							(USB_THERMAL_BASE+42)   //��ȡ�������
#define USB_SET_BLACK_BODY							(USB_THERMAL_BASE+43)   //���ú������
#define USB_GET_BODYTEMP_COMPENSATION				(USB_THERMAL_BASE+44)   //��ȡ���²�������
#define USB_SET_BODYTEMP_COMPENSATION				(USB_THERMAL_BASE+45)   //�������²�������
#define USB_GET_JPEGPIC_WITH_APPENDDATA				(USB_THERMAL_BASE+46)   //��ȡ��ͼ
#define USB_GET_ROI_MAX_TEMPERATURE_SEARCH			(USB_THERMAL_BASE+47)   //ROI�������Ϣ��ѯ
#define USB_GET_P2P_PARAM							(USB_THERMAL_BASE+48)   //��ȡȫ�����²���
#define USB_SET_P2P_PARAM							(USB_THERMAL_BASE+49)   //����ȫ�����²���
#define USB_GET_SYSTEM_DIAGNOSED_DATA_EX            (USB_THERMAL_BASE+50)   //���������������Ϣ����
#define USB_POST_DOUBLE_LIGHTS_CORRECT				(USB_THERMAL_BASE+51)   //˫��У׼
#define USB_GET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL	(USB_THERMAL_BASE+52)	//��ȡ˫��У׼������Ʋ���
#define USB_SET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL   (USB_THERMAL_BASE+53)   //����˫��У׼������Ʋ���
#define USB_GET_THERMOMETRY_CALIBRATION_FILE		(USB_THERMAL_BASE+54)   //���±궨�ļ�����
#define USB_SET_THERMOMETRY_CALIBRATION_FILE		(USB_THERMAL_BASE+55)   //���±궨�ļ�����
#define USB_GET_THERMOMETRY_EXPERT_REGIONS			(USB_THERMAL_BASE+56)   //��ȡר�Ҳ��¹���
#define USB_SET_THERMOMETRY_EXPERT_REGIONS			(USB_THERMAL_BASE+57)   //����ר�Ҳ��¹���
#define USB_GET_EXPERT_CORRECTION_PARAM				(USB_THERMAL_BASE+58)   //��ȡר�Ҳ���У������
#define USB_SET_EXPERT_CORRECTION_PARAM				(USB_THERMAL_BASE+59)   //����ר�Ҳ���У������
#define USB_START_EXPERT_CORRECTION					(USB_THERMAL_BASE+60)   //��ʼר�Ҳ���У��
#define USB_GET_THERMOMETRY_RISE_SETTINGS           (USB_THERMAL_BASE+61)    //��ȡ�������ò���
#define USB_SET_THERMOMETRY_RISE_SETTINGS           (USB_THERMAL_BASE+62)    //�����������ò���
#define USB_GET_ENVIROTEMPERATURE_CORRECT           (USB_THERMAL_BASE+63)       //��ȡ�����¶�У������
#define USB_SET_ENVIROTEMPERATURE_CORRECT           (USB_THERMAL_BASE+64)       //���û����¶�У������
#define USB_GET_SYSTEM_CAPABILITIES                 (USB_THERMAL_BASE+65)       //��ȡϵͳ����
#define USB_GET_SYSTEM_ISP_BIN_FILE                 (USB_THERMAL_BASE+66)       //��ȡ�豸ISP bin�ļ�
#define USB_GET_SYSTEM_FUSION_BIN_FILE              (USB_THERMAL_BASE+67)       //��ȡ�豸�ںϲ���bin�ļ�
#define USB_GET_VIDEO_CODE                          (USB_THERMAL_BASE+68)       //��ȡ��Ƶ�������
#define USB_SET_VIDEO_CODE                          (USB_THERMAL_BASE+69)       //������Ƶ�������
#define USB_GET_VIDEO_FUSION                        (USB_THERMAL_BASE+70)       //��ȡ��Ƶͼ���ںϲ���
#define USB_SET_VIDEO_FUSION                        (USB_THERMAL_BASE+71)       //������Ƶͼ���ںϲ���
#define USB_GET_VIDEO_LEN_CALIBRATION               (USB_THERMAL_BASE+72)       //��ȡ��ͷ�궨����
#define USB_SET_VIDEO_LEN_CALIBRATION               (USB_THERMAL_BASE+73)       //���þ�ͷ�궨����
#define USB_GET_IMAGE_CAPABILITIES                  (USB_THERMAL_BASE+74)       //��ȡͼ�����������
#define USB_GET_IMAGE_ENHANCEMENT_CAPABILITIES      (USB_THERMAL_BASE+75)       //��ȡͼ����ǿ����
#define USB_GET_THERMAL_CAPABILITIES                (USB_THERMAL_BASE+76)       //��ȡ�ȳ���������
#define USB_GET_THERMOMETRY_BASIC_PARAM_CAPABILITIES          (USB_THERMAL_BASE+77)       //��ȡ���»�����������
#define USB_GET_VIDEO_COMMON_CAPABILITIES           (USB_THERMAL_BASE+78)       //��ȡ��Ƶͨ��������
#define USB_GET_VIDEO_LEN_CALIBRATION_CAPABILITIES            (USB_THERMAL_BASE+79)       //��ȡ��ͷ�궨����
#define USB_GET_IMAGE_ENHANCEMENT_V20               (USB_THERMAL_BASE+80)    //��ȡͼ����ǿ����V20
#define USB_SET_IMAGE_ENHANCEMENT_V20               (USB_THERMAL_BASE+81)     //����ͼ����ǿ����V20
#define USB_GET_THERMAL_STREAM_PARAM_CAPABILITIES   (USB_THERMAL_BASE+82)     //��ȡ�ȳ�������������������
#define USB_GET_VIDEO_CODE_CAPABILITIES             (USB_THERMAL_BASE+83)     //��ȡ��Ƶ��������
#define USB_GET_SYSTEM_INIT                         (USB_THERMAL_BASE+84)     //��ȡϵͳ��ʼ������
#define USB_SET_SYSTEM_INIT                         (USB_THERMAL_BASE+85)     //����ϵͳ��ʼ������
#define USB_GET_SYSTEM_CTRL_CAPABILITIES            (USB_THERMAL_BASE+86)     //��ȡϵͳ����������
#define USB_GET_SYSTEM_DEVICE_INFO_CAPABILITIES     (USB_THERMAL_BASE+87)     //��ȡ�豸��Ϣ����
#define USB_GET_SYSTEM_HARDWARE_SERVER_CAPABILITIES           (USB_THERMAL_BASE+88)     //��ȡӲ�������������
#define USB_GET_SYSTEM_LOCALTIME_CAPABILITIES       (USB_THERMAL_BASE+89)     //��ȡϵͳʱ���������
#define USB_GET_IMAGE_BRIGHTNESS_CAPABILITIES       (USB_THERMAL_BASE+90)     //��ȡͼ�����ȵ�������
#define USB_GET_IMAGE_CONTRAST_CAPABILITIES         (USB_THERMAL_BASE+91)     //��ȡͼ��Աȶȵ�������
#define USB_GET_IMAGE_VIDEO_ADJUST_CAPABILITIES     (USB_THERMAL_BASE+92)     //��ȡ��Ƶ��������
#define USB_GET_THERMAL_THERMOMETRY_MODE_CAPABILITIES         (USB_THERMAL_BASE+93)       //��ȡ����ģʽ��������
#define USB_GET_THERMAL_THERMOMETRY_REGIONS_CAPABILITIES      (USB_THERMAL_BASE+94)       //��ȡ���¹�����������
#define USB_GET_THERMAL_TEMPERATURE_CORRECT_CAPABILITIES      (USB_THERMAL_BASE+95)       //��ȡ����������������£�����
#define USB_GET_THERMAL_BLACK_BODY_CAPABILITIES               (USB_THERMAL_BASE+96)       //��ȡ���������������
#define USB_GET_THERMAL_BODYTEMP_COMPENSATION_CAPABILITIES    (USB_THERMAL_BASE+97)       //��ȡ���²���������������
#define USB_GET_THERMAL_ROI_MAX_TEMPERATURE_SEARCH_CAPABILITIES         (USB_THERMAL_BASE+98)       //��ȡROI�������Ϣ��ѯ����
#define USB_GET_THERMAL_THERMOMETRY_CALIBRATION_FILE_CAPABILITIES       (USB_THERMAL_BASE+99)       //��ȡ���±궨�ļ����뵼������
#define USB_GET_THERMAL_THERMOMETRY_EXPERT_REGIONS_CAPABILITIES         (USB_THERMAL_BASE+100)       //��ȡר�Ҳ��¹�����������
#define USB_GET_THERMAL_THERMOMETRY_EXPERT_CORRECTION_PARAM_CAPABILITIES    (USB_THERMAL_BASE+101)   //��ȡר�Ҳ���У��������������
#define USB_GET_SYSTEM_DEVICE_DESCRIPTION_INFO                (USB_THERMAL_BASE+102)       //��ȡ�豸������Ϣ
#define USB_GET_SYSTEM_SERIAL_DATA_TRANSMISSION               (USB_THERMAL_BASE+103)       //��ȡ����͸������
#define USB_SET_SYSTEM_SERIAL_DATA_TRANSMISSION               (USB_THERMAL_BASE+104)       //���ô���͸������
#define USB_GET_IMAGE_PALETTE_DATA                            (USB_THERMAL_BASE+105)       //��ȡα��ӳ���
#define USB_GET_THERAML_THERMOMETRY_OFFLINE_DATA_EXPORT       (USB_THERMAL_BASE+106)       //�������߷������ݵ���
#define USB_GET_IMAGE_OUTPUT_CFG                              (USB_THERMAL_BASE+107)       //��ȡͼ��������ò���
#define USB_SET_IMAGE_OUTPUT_CFG                              (USB_THERMAL_BASE+108)       //����ͼ��������ò���
#define USB_GET_SYSTEM_DEVICE_DESCRIPTION_INFO_CAPABILITIES   (USB_THERMAL_BASE+109)       //��ȡ�豸������Ϣ����
#define USB_GET_THERMAL_STREAM_CTRL                           (USB_THERMAL_BASE+110)       //��ȡ������ͣ״̬
#define USB_SET_THERMAL_STREAM_CTRL                           (USB_THERMAL_BASE+111)       //����������ͣ

//ǰ��������
#define USB_CAMERA_BASE                 3000
#define USB_GET_VIDEO_CAP           (USB_CAMERA_BASE+1)               // ��ȡ��Ƶ������
#define USB_GET_AUDIO_CAP           (USB_CAMERA_BASE+2)               // ��ȡ��Ƶ������
#define USB_GET_VIDEO_PARAM         (USB_CAMERA_BASE+3)               // ��ȡ��Ƶ����
#define USB_SET_VIDEO_PARAM         (USB_CAMERA_BASE+4)               // ������Ƶ����
//#define USB_GET_AUDIO_PARAM         (USB_CAMERA_BASE+5)               // ��ȡ��Ƶ����
#define USB_SET_AUDIO_PARAM         (USB_CAMERA_BASE+6)               // ������Ƶ����
#define USB_SET_SRC_STREAM_TYPE     (USB_CAMERA_BASE+7)               // ����ԭʼ��������
#define USB_SET_EVENT_CALLBACK      (USB_CAMERA_BASE+9)               // �����¼��ص�����
#define USB_SET_ROTATE_ANGLE        (USB_CAMERA_BASE+10)              // ����Ԥ��������ת�Ƕ�
#define USB_GET_IRFRAME             (USB_CAMERA_BASE+11)              // ��ȡIR֡
#define USB_INIT_LIVE_DETECT        (USB_CAMERA_BASE+12)              // ���������㷨��Դ
#define USB_GET_LIVEDETECT          (USB_CAMERA_BASE+13)              // ������

//��׼UVCЭ��
#define USB_GET_VIDEO_PROPERTY_CAP			(USB_CAMERA_BASE+14)	// ��ȡ��Ƶ����������
#define USB_GET_VIDEO_BRIGHTNESS			(USB_CAMERA_BASE+15)	// ��ȡ��Ƶ����
#define USB_SET_VIDEO_BRIGHTNESS			(USB_CAMERA_BASE+16)	// ������Ƶ����
#define USB_GET_VIDEO_CONTRAST				(USB_CAMERA_BASE+17)	// ��ȡ��Ƶ�Աȶ�
#define USB_SET_VIDEO_CONTRAST				(USB_CAMERA_BASE+18)	// ������Ƶ�Աȶ�
#define USB_GET_VIDEO_HUE					(USB_CAMERA_BASE+19)	// ��ȡ��Ƶɫ��
#define USB_SET_VIDEO_HUE					(USB_CAMERA_BASE+20)	// ������Ƶɫ��
#define USB_GET_VIDEO_SATURATION			(USB_CAMERA_BASE+21)	// ��ȡ��Ƶ���Ͷ�
#define USB_SET_VIDEO_SATURATION			(USB_CAMERA_BASE+22)	// ������Ƶ���Ͷ�
#define USB_GET_VIDEO_SHARPNESS				(USB_CAMERA_BASE+23)	// ��ȡ��Ƶ������
#define USB_SET_VIDEO_SHARPNESS				(USB_CAMERA_BASE+24)	// ������Ƶ������
#define USB_GET_VIDEO_GAMMA					(USB_CAMERA_BASE+25)	// ��ȡ��Ƶ٤��
#define USB_SET_VIDEO_GAMMA					(USB_CAMERA_BASE+26)	// ������Ƶ٤��
#define USB_GET_VIDEO_COLORENABLE			(USB_CAMERA_BASE+27)	// ��ȡ��Ƶ������ɫ
#define USB_SET_VIDEO_COLORENABLE			(USB_CAMERA_BASE+28)	// ������Ƶ������ɫ
#define USB_GET_VIDEO_WHITEBALANCE			(USB_CAMERA_BASE+29)	// ��ȡ��Ƶ��ƽ��
#define USB_SET_VIDEO_WHITEBALANCE			(USB_CAMERA_BASE+30)	// ������Ƶ��ƽ��
#define USB_GET_VIDEO_BACKLIGHTCOMPENSATION	(USB_CAMERA_BASE+31)	// ��ȡ��Ƶ���Ա�
#define USB_SET_VIDEO_BACKLIGHTCOMPENSATION	(USB_CAMERA_BASE+32)	// ������Ƶ���Ա�
#define USB_GET_VIDEO_GAIN					(USB_CAMERA_BASE+33)	// ��ȡ��Ƶ����
#define USB_SET_VIDEO_GAIN					(USB_CAMERA_BASE+34)	// ������Ƶ����
#define USB_GET_VIDEO_POWERLINEFREQUENCY	(USB_CAMERA_BASE+35)	// ��ȡ��Ƶ������Ƶ��
#define USB_SET_VIDEO_POWERLINEFREQUENCY	(USB_CAMERA_BASE+36)	// ������Ƶ������Ƶ��
#define USB_GET_VIDEO_PAN					(USB_CAMERA_BASE+37)	// ��ȡ��Ƶȫ��
#define USB_SET_VIDEO_PAN					(USB_CAMERA_BASE+38)	// ������Ƶȫ��
#define USB_GET_VIDEO_TILT					(USB_CAMERA_BASE+39)	// ��ȡ��Ƶ��б
#define USB_SET_VIDEO_TILT					(USB_CAMERA_BASE+40)	// ������Ƶ��б
#define USB_GET_VIDEO_ROLL					(USB_CAMERA_BASE+41)	// ��ȡ��Ƶ����
#define USB_SET_VIDEO_ROLL					(USB_CAMERA_BASE+42)	// ������Ƶ����
#define USB_GET_VIDEO_ZOOM					(USB_CAMERA_BASE+43)	// ��ȡ��Ƶ����
#define USB_SET_VIDEO_ZOOM					(USB_CAMERA_BASE+44)	// ������Ƶ����
#define USB_GET_VIDEO_EXPOSURE				(USB_CAMERA_BASE+45)	// ��ȡ��Ƶ�ع�
#define USB_SET_VIDEO_EXPOSURE				(USB_CAMERA_BASE+46)	// ������Ƶ�ع�
#define USB_GET_VIDEO_IRIS					(USB_CAMERA_BASE+47)	// ��ȡ��Ƶ��Ȧ
#define USB_SET_VIDEO_IRIS					(USB_CAMERA_BASE+48)	// ������Ƶ��Ȧ
#define USB_GET_VIDEO_FOCUS					(USB_CAMERA_BASE+49)	// ��ȡ��Ƶ����
#define USB_SET_VIDEO_FOCUS					(USB_CAMERA_BASE+50)	// ������Ƶ����
#define USB_GET_VIDEO_LOWBRIGHTNESSCOMPENSATION	(USB_CAMERA_BASE+51)// ��ȡ��Ƶ�����Ȳ���
#define USB_SET_VIDEO_LOWBRIGHTNESSCOMPENSATION	(USB_CAMERA_BASE+52)// ������Ƶ�����Ȳ���
#define USB_GET_VIDEO_VOLUME				(USB_CAMERA_BASE+53)	// ��ȡ�豸����
#define USB_SET_VIDEO_VOLUME				(USB_CAMERA_BASE+54)	// �����豸����

//˽��UVCЭ��
#define USB_SET_OSD                         (USB_CAMERA_BASE+100)   // ����OSD
//���� #define USB_SET_SYSTEM_RESET          (USB_THERMAL_BASE+13)   // �ָ�Ĭ��
#define USB_GET_PRIVATE_UVC_CABABILITIES    (USB_CAMERA_BASE+102)   // ��ȡ˽��Э��UVC������
#define USB_GET_PRIVATE_UAC_CABABILITIES    (USB_CAMERA_BASE+103)   // ��ȡ˽��Э��UAC������
#define USB_GET_IMAGE_ENHANCEMENT_CAMERA    USB_GET_IMAGE_ENHANCEMENT_V20   // ��ȡͼ����ǿ����
#define USB_SET_IMAGE_ENHANCEMENT_CAMERA    USB_SET_IMAGE_ENHANCEMENT_V20   // ����ͼ����ǿ����
#define USB_GET_IMAGE_VIDEO_ADJUST_CAMERA   USB_GET_IMAGE_VIDEO_ADJUST  // ��ȡ��Ƶ��������
#define USB_SET_IMAGE_VIDEO_ADJUST_CAMERA   USB_SET_IMAGE_VIDEO_ADJUST  // ������Ƶ��������
#define USB_GET_IMAGE_WDR_CAMERA            USB_GET_IMAGE_WDR        // ��ȡͼ��WDR����
#define USB_SET_IMAGE_WDR_CAMERA            USB_SET_IMAGE_WDR        // ����ͼ��WDR����
#define USB_SET_IMAGE_VIDEO_OSD_CFG_CAMERA  USB_SET_IMAGE_VIDEO_OSD_CFG // ����OSD��������
#define USB_GET_IMAGE_MODE                  (USB_CAMERA_BASE+111)   // ��ȡͼ��ģʽ
#define USB_SET_IMAGE_MODE                  (USB_CAMERA_BASE+112)   // ����ͼ��ģʽ
#define USB_GET_IMAGE_WHITE_BALANCE         (USB_CAMERA_BASE+113)   // ��ȡ��ƽ�����
#define USB_SET_IMAGE_WHITE_BALANCE         (USB_CAMERA_BASE+114)   // ���ð�ƽ�����
#define USB_GET_IMAGE_GAMUT                 (USB_CAMERA_BASE+115)   // ��ȡɫ�����
#define USB_SET_IMAGE_GAMUT                 (USB_CAMERA_BASE+116)   // ����ɫ�����
#define USB_GET_IMAGE_SHUTTER               (USB_CAMERA_BASE+117)   // ��ȡ���Ų���
#define USB_SET_IMAGE_SHUTTER               (USB_CAMERA_BASE+118)   // ���ÿ��Ų���
#define USB_GET_VCA_FACE_AE                 (USB_CAMERA_BASE+119)   // ��ȡFace AE����
#define USB_SET_VCA_FACE_AE                 (USB_CAMERA_BASE+120)   // ����Face AE����
#define USB_GET_VCA_FACE_CENTERED           (USB_CAMERA_BASE+121)   // ��ȡ�������в���
#define USB_SET_VCA_FACE_CENTERED           (USB_CAMERA_BASE+122)   // �����������в���
#define USB_GET_VCA_SPOKESMAN_TRACK         (USB_CAMERA_BASE+123)   // ��ȡ�����˸��ٲ���
#define USB_SET_VCA_SPOKESMAN_TRACK         (USB_CAMERA_BASE+124)   // ���÷����˸��ٲ���
#define USB_GET_VCA_BEAUTY                  (USB_CAMERA_BASE+125)   // ��ȡ���ղ���
#define USB_GET_AUDIO_PICK_UP               (USB_CAMERA_BASE+126)   // ��ȡʰ��
#define USB_SET_AUDIO_PICK_UP               (USB_CAMERA_BASE+127)   // ����ʰ��
#define USB_GET_IMAGE_FOCUS                 (USB_CAMERA_BASE+128)   // ��ȡ�۽�������
#define USB_SET_IMAGE_FOCUS                 (USB_CAMERA_BASE+129)   // ���þ۽�������
#define USB_GET_IMAGE_OVERHEAD_SHOT         (USB_CAMERA_BASE+130)   // ��ȡ������ģʽ
#define USB_SET_IMAGE_OVERHEAD_SHOT         (USB_CAMERA_BASE+131)   // ����������ģʽ
#define USB_CTRL_MENU                       (USB_CAMERA_BASE+132)   // ��Ƶ�˵�����
#define USB_CTRL_IMAGE_PARAM_LOCK           (USB_CAMERA_BASE+133)   // ͼ���������
#define USB_GET_IMAGE_DYNAMIC_RANGE         (USB_CAMERA_BASE+134)   // ��ȡͼ��ɫ�ʿռ�
#define USB_CTRL_PTZ_BASIC_CONTORL          (USB_CAMERA_BASE+135)   // ��̨��������
#define USB_CTRL_PTZ_AUTO_FOCUS             (USB_CAMERA_BASE+136)   // һ���Զ��۽�
#define USB_CTRL_PTZ_FOCUS_EXCHANGE         (USB_CAMERA_BASE+137)   // �۽�ģʽ�л�

#define USB_GET_TEST_VCM                     (USB_CAMERA_BASE+200)   // VCMУ׼
#define USB_SET_TEST_VCM                     (USB_CAMERA_BASE+201)   // VCMУ׼
#define USB_GET_TEST_DTOF_CALIBRATION        (USB_CAMERA_BASE+202)   // DTOFУ׼
#define USB_SET_TEST_DTOF_CALIBRATION        (USB_CAMERA_BASE+203)   // DTOFУ׼
#define USB_GET_TEST_DTOF_CHECK              (USB_CAMERA_BASE+204)   // DTOF���
#define USB_SET_TEST_DTOF_CHECK              (USB_CAMERA_BASE+205)   // DTOF���
#define USB_GET_TEST_PWM                     (USB_CAMERA_BASE+206)   // ��ȡPWMռ�ձ�
#define USB_GET_TEST_ITOF_DISTANCE           (USB_CAMERA_BASE+207)   // ITOF������
#define USB_SET_TEST_ITOF_DISTANCE           (USB_CAMERA_BASE+208)   // ITOF������
#define USB_GET_TEST_ITOF_FACTORY            (USB_CAMERA_BASE+209)   // ITOF�������
#define USB_SET_TEST_ITOF_FACTORY            (USB_CAMERA_BASE+210)   // ITOF�������
#define USB_GET_TEST_ITOF_FRAME              (USB_CAMERA_BASE+211)   // ITOF��֡���
#define USB_SET_TEST_ITOF_FRAME              (USB_CAMERA_BASE+212)   // ITOF��֡���
#define USB_GET_TEST_ITOF_FACTORY2           (USB_CAMERA_BASE+213)   // ITOF�������2
#define USB_SET_TEST_ITOF_FACTORY2           (USB_CAMERA_BASE+214)   // ITOF�������2
#define USB_GET_TEST_ITOF_CALIBRATION        (USB_CAMERA_BASE+215)   // ITOF�궨
#define USB_SET_TEST_ITOF_CALIBRATION        (USB_CAMERA_BASE+216)   // ITOF�궨
#define USB_GET_TEST_SCENE_CURVE_CHECK       (USB_CAMERA_BASE+217)   // ��ͷ���߼��
#define USB_SET_TEST_SCENE_CURVE_CHECK       (USB_CAMERA_BASE+218)   // ��ͷ���߼��
#define USB_GET_TEST_SCENE_AGE_CHECK         (USB_CAMERA_BASE+219)   // ��ͷ�ϻ����
#define USB_SET_TEST_SCENE_AGE_CHECK         (USB_CAMERA_BASE+220)   // ��ͷ�ϻ����
#define USB_SET_TEST_LAMP_CHECK             (USB_CAMERA_BASE+221)   // ָʾ�Ƽ��
#define USB_GET_TEST_BATTERY_CHECK           (USB_CAMERA_BASE+222)   // ��ؼ��
#define USB_SET_TEST_BATTERY_CHECK           (USB_CAMERA_BASE+223)   // ��ؼ��
#define USB_GET_TEST_KNOB_CALIBRATION        (USB_CAMERA_BASE+224)   // ��ť�궨
#define USB_SET_TEST_KNOB_CALIBRATION        (USB_CAMERA_BASE+225)   // ��ť�궨
#define USB_SET_TEST_PARAM_RESET             (USB_CAMERA_BASE+226)   // �������ñ��ָ�Ĭ��
#define USB_SET_TEST_HIDE_ENDPOINTS          (USB_CAMERA_BASE+227)   // ���ض˵�
#define USB_GET_TEST_HALL                    (USB_CAMERA_BASE+228)   // ����״̬��ȡ
#define USB_GET_TEST_DEVICE_LOCATION         (USB_CAMERA_BASE+229)   // ��ȡ�豸����λ��
#define USB_GET_TEST_TOUCH_BUTTON            (USB_CAMERA_BASE+230)   // �����������
#define USB_SET_TEST_TOUCH_BUTTON            (USB_CAMERA_BASE+231)   // �����������
#define USB_GET_TEST_FRAME                   (USB_CAMERA_BASE+232)   // ����궨
#define USB_SET_TEST_FRAME                   (USB_CAMERA_BASE+233)   // ����궨


//����������
#define USB_TRANSMISSION_BASE               4000
#define USB_SET_SYSTEM_ENCRYPT_DATA         (USB_TRANSMISSION_BASE+1)   //�豸����
#define USB_GET_SYSTEM_ENCRYPT_STATUS       (USB_TRANSMISSION_BASE+2)   //�豸����״̬��ȡ
#define USB_GET_SYSTEM_INDICATORLIGHT       (USB_TRANSMISSION_BASE+3)   //��ȡָʾ��״̬
#define USB_SET_SYSTEM_INDICATORLIGHT       (USB_TRANSMISSION_BASE+4)   //����ָʾ��״̬
#define USB_GET_SYSTEM_LOG_DATA             (USB_TRANSMISSION_BASE+5)   //��־�ļ�����
#define USB_GET_SYSTEM_DEVICE_STATUS_DATA   (USB_TRANSMISSION_BASE+6)   //�豸״̬�ļ�����
#define USB_SET_IMAGE_WDR                   (USB_TRANSMISSION_BASE+7)   //����ͼ��WDR
#define USB_SET_IMAGE_VIDEO_LOGO_SWITCH     (USB_TRANSMISSION_BASE+8)   //����LOGO����
#define USB_SET_IMAGE_VIDEO_LOGO_CFG        (USB_TRANSMISSION_BASE+9)   //����LOGO����
#define USB_SET_IMAGE_VIDEO_OSD_SWITCH      (USB_TRANSMISSION_BASE+10)   //����OSD����
#define USB_SET_IMAGE_VIDEO_OSD_CFG         (USB_TRANSMISSION_BASE+11)   //����OSD��������
#define USB_SET_IMAGE_VIDEO_MULTIPLE_STREAM (USB_TRANSMISSION_BASE+12)   //���ö�·����ȡ��
#define USB_SET_IMAGE_VIDEO_MULTIPLE_IFRAME (USB_TRANSMISSION_BASE+13)   //���ö�·����ǿ��I֡
#define USB_GET_AUDIO_IN_STATUS             (USB_TRANSMISSION_BASE+14)   //��ȡ��Ƶ����״̬
#define USB_GET_AUDIO_OUT_STATUS            (USB_TRANSMISSION_BASE+15)   //��ȡ��Ƶ���״̬
#define USB_GET_AUDIO_IN_VL                 (USB_TRANSMISSION_BASE+16)   //��ȡ��Ƶ��������
#define USB_GET_AUDIO_OUT_VL                (USB_TRANSMISSION_BASE+17)   //��ȡ��Ƶ�������
#define USB_SET_AUDIO_AMER                  (USB_TRANSMISSION_BASE+18)   //������Ƶ����ѡ��
#define USB_SET_AUDIO_AO_VA                 (USB_TRANSMISSION_BASE+19)   //������Ƶ�������
#define USB_SET_AUDIO_AECSP                 (USB_TRANSMISSION_BASE+20)   //������ƵAEC��ʱ
#define USB_GET_AUDIO_DEVICE_DELAY          (USB_TRANSMISSION_BASE+21)   //��ȡ��Ƶ��ʱ�Զ��Ż�
#define USB_SET_AUDIO_DEVICE_DELAY          (USB_TRANSMISSION_BASE+22)   //������Ƶ��ʱ�Զ��Ż�
#define USB_SET_AUDIO_BT                    (USB_TRANSMISSION_BASE+23)   //��������ɨ��״̬
#define USB_GET_AUDIO_BT_MAC                (USB_TRANSMISSION_BASE+24)   //��ȡ����MAC��ַ
#define USB_GET_AUDIO_BT_STATUS             (USB_TRANSMISSION_BASE+25)   //��ȡ��������״̬
#define USB_GET_AUDIO_DETECT                (USB_TRANSMISSION_BASE+26)   //��ȡ��Ƶ��������Լ�
#define USB_SET_AUDIO_DETECT                (USB_TRANSMISSION_BASE+27)   //������Ƶ��������Լ�
#define USB_GET_AUDIO_EFFICT_DETECT         (USB_TRANSMISSION_BASE+28)   //��ȡ��Ч�Լ�
#define USB_SET_AUDIO_EFFICT_DETECT         (USB_TRANSMISSION_BASE+29)   //������Ч�Լ�
#define USB_GET_AUDIO_FAC_TEST              (USB_TRANSMISSION_BASE+30)   //��ȡ��Ƶ��������
#define USB_SET_AUDIO_FAC_TEST              (USB_TRANSMISSION_BASE+31)   //������Ƶ��������
#define USB_SET_AUDIO_AGC_CONFIG            (USB_TRANSMISSION_BASE+32)   //������ƵAGC����
#define USB_SET_AUDIO_REDUCE_NOISE          (USB_TRANSMISSION_BASE+33)   //������Ƶ����
#define USB_GET_AUDIO_RECOG_RSLT            (USB_TRANSMISSION_BASE+34)   //��ȡ����ʶ�����ϴ�
#define USB_SET_AUDIO_RECOG_RSLT            (USB_TRANSMISSION_BASE+35)   //��������ʶ�����ϴ�
#define USB_GET_AUDIO_DUMP_DATA             (USB_TRANSMISSION_BASE+36)   //��Ƶ���ݵ���
#define USB_SET_PTZ_TRACK_MODE              (USB_TRANSMISSION_BASE+37)   //���ø���ģʽ
#define USB_SET_PTZ_PRESET_CFG              (USB_TRANSMISSION_BASE+38)   //Ԥ�õ����ã����ֶ�ģʽ֧������
#define USB_SET_PTZ_PRESET_CALL             (USB_TRANSMISSION_BASE+39)   //Ԥ�õ���ã����ֶ�ģʽ֧������
#define USB_SET_PTZ_PRESET_DELETE           (USB_TRANSMISSION_BASE+40)  //Ԥ�õ�ɾ�������ֶ�ģʽ֧������
#define USB_SET_PTZ_AUTO_TRACK_SENSITIVITY  (USB_TRANSMISSION_BASE+41)  //�����Զ����������ȣ����Զ�����ģʽ֧��
#define USB_GET_PRIVACY                     (USB_TRANSMISSION_BASE+42)  //��ȡ��˽��
#define USB_SET_PRIVACY                     (USB_TRANSMISSION_BASE+43)  //������˽��
#define USB_SET_AUDIO_ECHO                  (USB_TRANSMISSION_BASE+44)  //ECHO���
//#define USB_SET_SYSTEM_DEVICE_SIGNAL_TRANS  (USB_TRANSMISSION_BASE+45)  //������������
#define USB_SET_AUDIO_SIGNAL_TRANS          (USB_TRANSMISSION_BASE+46)  //��Ƶ������������
#define USB_GET_AUDIO_INPUT_OUTPUT_CHANNELINFO (USB_TRANSMISSION_BASE+47)//��Ƶ�������ͨ����Ϣ��ȡ
#define USB_GET_AUDIO_PROCESS_LINE_CFG      (USB_TRANSMISSION_BASE+48)  //��ȡ��Ƶ���߲�������
#define USB_SET_AUDIO_PROCESS_LINE_CFG      (USB_TRANSMISSION_BASE+49)  //������Ƶ���߲�������
#define USB_GET_AUDIO_POE_LINK_STATUS       (USB_TRANSMISSION_BASE+50)  //��ȡ��ƵPOE�������ڼ��״̬
#define USB_GET_SYSTEM_DEVICE_CAPABILITIES  (USB_TRANSMISSION_BASE+51)  //��ȡ�豸SVC����
#define USB_GET_IMAGE_VIDEO_SVC_MULTIPLE_STREAM (USB_TRANSMISSION_BASE+52) //��ȡSVC��������Ϣ
#define USB_GET_IMAGE_WDR                   (USB_TRANSMISSION_BASE+53)   //��ȡͼ��WDR

#define USB_GET_VCA_SWITCH                  (USB_TRANSMISSION_BASE+101)  //��ȡ���ܹ��ܿ���
#define USB_SET_VCA_SWITCH                  (USB_TRANSMISSION_BASE+102)  //�������ܹ��ܿ���
#define USB_GET_VCA_SNAPSHOT                (USB_TRANSMISSION_BASE+103)  //��ȡ����ץͼ��ͼƬͨ�����ļ����䣩
#define USB_GET_VCA_FACE_THRESHOLD          (USB_TRANSMISSION_BASE+104)  //��ȡ����Ŀ��ʶ������ƶ���ֵ
#define USB_SET_VCA_FACE_THRESHOLD          (USB_TRANSMISSION_BASE+105)  //��������Ŀ��ʶ������ƶ���ֵ
#define USB_GET_VCA_FACE_ATTRIBUTES         (USB_TRANSMISSION_BASE+106)  //��ȡ����Ŀ��ʶ�������
#define USB_SET_VCA_FACE_ATTRIBUTES         (USB_TRANSMISSION_BASE+107)  //��������Ŀ��ʶ�������
#define USB_GET_VCA_FACE_DETECT_RULE        (USB_TRANSMISSION_BASE+108)  //��ȡ�����������Ĺ���
#define USB_SET_VCA_FACE_DETECT_RULE        (USB_TRANSMISSION_BASE+109)  //���������������Ĺ���
#define USB_GET_VCA_FACE_QUALITY            (USB_TRANSMISSION_BASE+110)  //��ȡ�������������������
#define USB_SET_VCA_FACE_QUALITY            (USB_TRANSMISSION_BASE+111)  //�����������������������
#define USB_SET_VCA_PIC_DOWNLOAD            (USB_TRANSMISSION_BASE+112)  //ͼƬ���ؽ�ģ��ͼƬͨ�����ļ����䣩
#define USB_GET_VCA_FACE_BASE_DATA_CFG      (USB_TRANSMISSION_BASE+113)  //��ȡ�����׿�����
#define USB_SET_VCA_FACE_BASE_DATA_CFG      (USB_TRANSMISSION_BASE+114)  //���������׿�����
#define USB_GET_VCA_ELECTRONICSIGNAGE_CFG   (USB_TRANSMISSION_BASE+115)  //��ȡ������������
#define USB_SET_VCA_ELECTRONICSIGNAGE_CFG   (USB_TRANSMISSION_BASE+116)  //���õ�����������
#define USB_GET_VCA_FACE_DETECT             (USB_TRANSMISSION_BASE+117)  //��ȡ�������������Ϣ
#define USB_SET_VCA_FACE_DETECT             (USB_TRANSMISSION_BASE+118)  //�����������������Ϣ
#define USB_GET_VCA_FACE_CONTRAST           (USB_TRANSMISSION_BASE+119)  //��ȡ���������ȶ���Ϣ
#define USB_SET_VCA_FACE_CONTRAST           (USB_TRANSMISSION_BASE+120)  //�������������ȶ���Ϣ

//���Դ������豸������
#define USB_TRANSMISSION_BULK_BASE           4500
#define USB_CTRL_RESET_DEVICE                (USB_TRANSMISSION_BULK_BASE+0)  //�����豸
#define USB_GET_DEVICE_VERSION               (USB_TRANSMISSION_BULK_BASE+1)  //��ȡ�豸�汾��Ϣ

#define USB_TRANS_DEVICE_ENCRYPTION_START    (USB_TRANSMISSION_BULK_BASE+100)  //�豸���ܿ�ʼ
#define USB_TRANS_DEVICE_ENCRYPTION_PROGRESS (USB_TRANSMISSION_BULK_BASE+101)  //��ȡ���ܽ���
#define USB_TRANS_DEVICE_ENCRYPTION_STOP     (USB_TRANSMISSION_BULK_BASE+102)  //�豸���ܽ���
#define USB_TRANS_FILE_UPLOAD_START          (USB_TRANSMISSION_BULK_BASE+103)  //�ļ��ϴ���ʼ
#define USB_TRANS_FILE_UPLOAD_PROGRESS       (USB_TRANSMISSION_BULK_BASE+104)  //��ȡ�ϴ�����
#define USB_TRANS_FILE_UPLOAD_STOP           (USB_TRANSMISSION_BULK_BASE+105)  //�ļ��ϴ�����
#define USB_TRANS_FILE_DOWNLOAD_START        (USB_TRANSMISSION_BULK_BASE+106)  //�ļ����ؿ�ʼ
#define USB_TRANS_FILE_DOWNLOAD_PROGRESS     (USB_TRANSMISSION_BULK_BASE+107)  //��ȡ���ؽ���
#define USB_TRANS_FILE_DOWNLOAD_STOP         (USB_TRANSMISSION_BULK_BASE+108)  //�ļ����ؽ���

/************************************************************************
* ����ȡ������
************************************************************************/
#define USB_STREAM_UNKNOW     0
#define USB_STREAM_PCM        1    // PCM������(DirectShowö�ٳ���PCM����Ϊ1,����һ��)
#define USB_STREAM_MJPEG      101  // MJPEG������
#define USB_STREAM_H264       102  // H264������(�����֧��H264�������)
#define USB_STREAM_YUY2       103  // YUV2������
#define USB_STREAM_NV12       104  // NV12������

/************************************************************************
* ����Ԥ��,�����ص���������
************************************************************************/
#define USB_STREAM_PS_H264    201  // PS��װH264����
#define USB_STREAM_PS_MJPEG   202  // PS��װMJPEG����
#define USB_STREAM_PS_YUY2    203  // PS��װYUV2����
#define USB_STREAM_PS_NV12    204  // PS��װYUV2����

/************************************************************************
* ����¼����������
************************************************************************/
#define USB_RECORDTYPE_PS_MJPEG        301     // ¼��PS��װMJPEG����
#define USB_RECORDTYPE_PS_H264         302     // ¼��PS��װH264����
#define USB_RECORDTYPE_MP4             303     // ¼��MP4
#define USB_RECORDTYPE_AVI             304     // ¼��AVI
#define USB_RECORDTYPE_PS_YUY2         305     // ¼��PS��װYUY2����
#define USB_RECORDTYPE_PS_NV12         306     // ¼��PS��װNV12����

/************************************************************************
* ͨ������: RGB��IR
************************************************************************/
#define USB_CHANNEL_RGB		1    //RGB·
#define USB_CHANNEL_IR      2    //IR·

/************************************************************************
* ͼ���������
************************************************************************/
#define USB_Brightness                0                               // ����
#define USB_Contrast                  USB_Brightness   + 1      // �Աȶ�
#define USB_Hue                       USB_Contrast     + 1        
#define USB_Saturation                USB_Hue          + 1
#define USB_Sharpness                 USB_Saturation   + 1      // ���Ͷ�
#define USB_Gamma                     USB_Sharpness    + 1
#define USB_ColorEnable               USB_Gamma        + 1
#define USB_WhiteBalance              USB_ColorEnable  + 1      // ��ƽ��
#define USB_BacklightCompensation     USB_WhiteBalance + 1      // ���ⲹ��
#define USB_Gain


#define USB_VIDEO_DEVICE       100              // ��Ƶ�豸
#define USB_AUDIO_DEVICE       101              // ��Ƶ�豸

#define USBCAMERA_INVALID_ID -1


/**	@enum
*  @brief �¼��붨��
*
*/
enum
{
    USB_EC_DEVICE_LOST = 31,      // DirectShow�豸����¼�
};

/**	@enum
*  @brief �¼����Ͷ���
*
*/
#define USB_EVENTTYPE_DEV_REMOVED 0
#define USB_EVENTTYPE_DEV_ADDED   1



/**	@enum
*  @brief ����ץ��ģʽ
*
*/
enum
{
    USB_FD_AUTOCAPTURE = 0,
    USB_FD_MANNUALCAPTURE,
    USB_FD_NOCAPTURE,
};


#define MAX_THERMAL_REGIONS     10
#define MAX_ROI_REGIONS   10   //���֧��10������


typedef enum tagLOG_LEVEL_ENUM
{
    ENUM_ERROR_LEVEL = 1,
    ENUM_DEBUG_LEVEL = 2,
    ENUM_INFO_LEVEL = 3
} LOG_LEVEL_ENUM;

    // ��������
    typedef struct tagUSB_COMMON_COND
    {
        DWORD dwSize;
        BYTE  byChannelID;     //ͨ����
        BYTE  bySID;           //����ID
        BYTE  byRes[6];
    }USB_COMMON_COND, *LPUSB_COMMON_COND;

    //�豸ϵͳ��Ϣ
    typedef struct tagUSB_SYSTEM_DEVICE_INFO
    {
        DWORD  dwSize;
        BYTE   byFirmwareVersion[64]; //���س���汾
        BYTE   byEncoderVersion[64];  //����汾
        BYTE   byHardwareVersion[64]; //��о�汾
        BYTE   byDeviceType[64];      //�豸�ͺ�
        BYTE   byProtocolVersion[4];  //Э��汾��Ϣ��"1.0"
        BYTE   bySerialNumber[64];    //���к�
		BYTE   bySecondHardwareVersion[64];	//������汾
        BYTE   byModuleID[32];  //��оID
        BYTE   byDeviceID[64];  //�豸ID
        BYTE   byDeviceAssembleType; //�豸��װ���ͣ�1-�����豸  2-�������豸
        BYTE   byManufacturer; //������Ϣ��1-�����豸  2-�����豸
        BYTE   byLanguageType; //�������ͣ�1-����  2-Ӣ��
        BYTE   byDeviceClass; //�豸���ࣺ1-�۲����豸  2-�²����豸
        BYTE   byRes[24];
    }USB_SYSTEM_DEVICE_INFO, *LPUSB_SYSTEM_DEVICE_INFO;

    //Ӳ�������������
    typedef struct tagUSB_SYSTEM_HARDWARE_SERVER
    {
        DWORD  dwSize;
        BYTE  byUsbMode;  //USBģʽ�л�  1-USB��UVCģʽ, 2-USB��NCMģʽ
        BYTE  byDeviceInitialStatus;  //�豸��ʼ��״̬  1-δ��ʼ��, 2-��ʼ�����
        BYTE  byDeviceWorkingStatus;  //�豸����״̬  1-������factory����, 2-������update����
        BYTE  byRes[29];
    }USB_SYSTEM_HARDWARE_SERVER, *LPUSB_SYSTEM_HARDWARE_SERVER;

    //Уʱ
    typedef struct tagUSB_SYSTEM_LOCALTIME
    {
        DWORD     dwSize;
        WORD      wMillisecond;//����
        BYTE       bySecond;//��
        BYTE       byMinute;//����
        BYTE       byHour;//Сʱ
        BYTE       byDay;//��
        BYTE       byMonth;//��
        BYTE       byRes1[1];
        WORD       wYear;//��
        BYTE       byExternalTimeSourceEnabled;//�ⲿУʱԴʹ��, 0-�رգ�1-����
        BYTE       byRes[5];
    }USB_SYSTEM_LOCALTIME, *LPUSB_SYSTEM_LOCALTIME;

    //ͼ�����ȵ���
    typedef struct tagUSB_IMAGE_BRIGHTNESS
    {
        DWORD  dwSize;
        DWORD  dwBrightness;       //ͼ������0-100
        BYTE   byRes[28];
    }USB_IMAGE_BRIGHTNESS, *LPUSB_IMAGE_BRIGHTNESS;

    //ͼ��Աȶȵ���
    typedef struct tagUSB_IMAGE_CONTRAST
    {
        DWORD     dwSize;
        DWORD dwContrast;      //ͼ��Աȶ�0-100
        BYTE  byRes[28];
    }USB_IMAGE_CONTRAST, *LPUSB_IMAGE_CONTRAST;

    //�����Ϣ����ǰ���������ýṹ���ڲ��з�ר�ã��ⲿ�û�������ļ�ʹ�ã�
    typedef struct tagUSB_SYSTEM_DIAGNOSED_DATA_COND
    {
        DWORD  dwSize;
        BYTE    byDataType;//�����豸����λ��: 1-PSRAM, 2-FLASH
        BYTE    byRes1[3];
        DWORD   dwAddress;//�����豸���ݵ�ַ
        DWORD   dwLength;//�����豸���ݳ���, ���֧��100k, ���������豸��֧��
        BYTE    byRes[112];
    }USB_SYSTEM_DIAGNOSED_DATA_COND, *LPUSB_SYSTEM_DIAGNOSED_DATA_COND;

    //�����Ϣ����
    typedef struct tagUSB_SYSTEM_DIAGNOSED_DATA
    {
        DWORD     dwSize;
        DWORD   dwDataLenth;     //������ݳ���
        BYTE   *pDiagnosedData;     //�������
        BYTE   byRes[56];
    }USB_SYSTEM_DIAGNOSED_DATA, *LPUSB_SYSTEM_DIAGNOSED_DATA;

    //ϵͳ����
    typedef struct tagUSB_SYSTEM_CAPABILITIES
    {
        DWORD	dwSize;
        BYTE  byXuSystemCtrl;  //ϵͳ���� 0-��֧��  1-֧��
        BYTE  byXuImageCtrl;  //��Ƶͼ�����  0-��֧��  1-֧��
        BYTE  byXuThermalCtrl;  //�ȳ������  0-��֧��  1-֧��
        BYTE  byRes[505];
    }USB_SYSTEM_CAPABILITIES, *LPUSB_SYSTEM_CAPABILITIES;

    //�豸ISP bin�ļ�����
    typedef struct tagUSB_SYSTEM_ISP_BIN_FILE
    {
        DWORD	dwSize;
        DWORD dwDataLenth;      //ISP bin�ļ�����
        BYTE   *pData;     //ISP bin�ļ�����
        BYTE  byRes[52];
    }USB_SYSTEM_ISP_BIN_FILE, *LPUSB_SYSTEM_ISP_BIN_FILE;

    //�豸�ںϲ���bin�ļ�����
    typedef struct tagUSB_SYSTEM_FUSION_BIN_FILE
    {
        DWORD	dwSize;
        DWORD dwDataLenth;      //�ںϲ���bin�ļ�����
        BYTE   *pData;     //�ںϲ���bin�ļ�����
        BYTE  byRes[52];
    }USB_SYSTEM_FUSION_BIN_FILE, *LPUSB_SYSTEM_FUSION_BIN_FILE;

    //ϵͳ��ʼ��
    typedef struct tagUSB_SYSTEM_INIT
    {
        DWORD dwSize;
        BYTE byDataStorage; //���ݴ洢 0-�ر�  1-����
        BYTE byRes[251];
    }USB_SYSTEM_INIT, *LPUSB_SYSTEM_INIT;

    //ͼ����ǿ
    typedef struct tagUSB_IMAGE_ENHANCEMENT
    {
        DWORD dwSize;
        BYTE  byNoiseReduceMode;  //���ֽ���ģʽ��0-�ر�; 1-��ͨģʽ;  2 - ר��ģʽ
        BYTE  byBirdWatchingMode;  //����ģʽʹ�ܣ�0-�ر�; 1-����
        BYTE  byHighLightMode;  //����͹��ģʽʹ�ܣ�0-�ر�; 1-����
        BYTE  byHighLightLevel;  //����͹�Եȼ���0-100
        DWORD dwGeneralLevel;  //��ͨģʽ���뼶�� 0-100
        DWORD dwFrameNoiseReduceLevel; //ר��ģʽ�����뼶�� 0-100
        DWORD dwInterFrameNoiseReduceLevel;  //ר��ģʽʱ���뼶�� 0-100
        BYTE  byPaletteMode; //α��ɫ��ɫģʽ��1-����;  2-����;  10-�ں�1; 11-�ʺ�; 12-�ں�2; 13-����1; 14-����2; 15-���ɫ; 16-ɫ��1; 17-ɫ��2; 18-����; 19-��; 20-����; 21-����; 22-����
        BYTE  byLSEDetailEnabled;  //ͼ��ϸ����ǿʹ��: 0-�ر� 1-����
        BYTE  byHookEdgeMode;  //����ģʽʹ��: 0-�ر�  1-����
        BYTE  byHookEdgeLevel;  //���ߵȼ�: 0-100
        DWORD dwLSEDetailLevel;  //ͼ��ϸ����ǿ�ȼ�: 0-100
        BYTE  byWideTemperatureMode;  //�¿�ģʽʹ�ܣ�0-�ر�  1-����
        BYTE  byWideTemperatureWork; //�¿�����ģʽ: 1-�¿�ģʽ�����޾����� 2-�¿�ģʽֻ��������  3-�¿�ģʽֻ��������
        BYTE  byIspAgcMode; //agc����ģʽ: 1-����ģʽ  2-ֱ��ͼģʽ  3-Ѳ��ģʽ  4-�ֶ�ģʽ
        BYTE  byAISuperResolution; //AI����ʹ�ܣ�0-�ر� 1-����
        DWORD  dwWideTemperatureUpThreshold;  //�¿�ģʽ����ֵ��-20.0��~400.0��(��ȷ��С�����һλ)������ʱ(ʵ��ֵ+100)*10�����������
        DWORD  dwWideTemperatureDownThreshold;  //�¿�ģʽ����ֵ��-20.0��~400.0��(��ȷ��С�����һλ)������ʱ(ʵ��ֵ+100)*10�����������
        BYTE  byRes[28];
    }USB_IMAGE_ENHANCEMENT, *LPUSB_IMAGE_ENHANCEMENT;

    //ͼ����ǿEX
    typedef struct tagUSB_IMAGE_ENHANCEMENT_EX
    {
        USB_IMAGE_ENHANCEMENT struImageEnhancement;
        BYTE  bySkyAreaCullLevel; //��������޳��ٷֱȣ�0-100
        BYTE  byAGCMode; //AGCģʽ��1-�ֶ� 2-�Զ�
        BYTE  byGaussianFilterEnabled; //��˹�˲�ʹ�ܣ�0-�ر�  1-����
        BYTE  byEdgePreservingFilterEnabled; //�����˲�ʹ�ܣ�0-�ر�  1-����
        DWORD  dwGaussianFilterCenterPoint; //��˹�˲����ĵ������64-4098
        DWORD  dwBilateralFilterRadius; //˫���˲��뾶��1-8
        DWORD  dwBilateralFilterEdgeThreshold; //˫���˲���Ե�ж����ޣ�1-1023
        BYTE  byBurnPreventionEnabled; //������ģʽʹ�ܣ�0-�ر�  1-����
        BYTE  byBurnPreventionMode; //�����տ���ģʽ��1-�Զ�����ģʽ  2-�ֶ�����ģʽ
        BYTE  byRelativeHumidityThreshold; //���ʪ����ֵ��Χ��0-100����λ��%���ٷֱȣ�������ʱʵ��ֵ + 1
        BYTE bySharpenBoost;  //����ǿʹ�ܣ�1-�ر�  2-����
        DWORD  dwBurnPreventionShutterCloseTime; //�����յ�Ƭ�պ�ʱ��(���Զ�ģʽ����Ч)��0-3600��
        BYTE  byBurnPreventionShutterControl; //�����յ�Ƭ�ֶ�����(���ֶ�ģʽ����Ч)��1-������  2-��Ƭ�պ�  3-��Ƭ̧��
        BYTE  byBurnPreventionRecovery; //�������Իָ�ʹ�ܣ�0-�ر�  1-����
        BYTE  byIsothermEnabled; //�����߿���ʹ�ܣ�0-�ر� 1-����
        BYTE  byRawDataNoiseReduceEnabled; //�����ݽ���ʹ�ܣ�0-�ر�  1-����
        DWORD  dwIsothermalUpperThreshold;  //�������¶�����ֵ��-20��~600�棬����ʱ(ʵ��ֵ+100)*10�����������
        DWORD  dwIsothermalLowerThreshold;  //�������¶�����ֵ��-20��~600�棬����ʱ(ʵ��ֵ+100)*10�����������
        BYTE  byIsothermalType;  //��������ʾ���ͣ�1-���ȵ���; 2-���ȵ���; 3-���ҵ���; 4-�������; 5-��������; 6-ҽ�Ƶ���; 7-��������; 8-�ʺ�1����; 9-�ʺ�2����; 10-������
        BYTE  byColorAlarmType;  //��ɫ�����������ͣ�0 - �ޱ������ر���ɫ����; 1 - ���±��� ����͹��; 2 - ���±��� ����͹��; 3 - ���䱨�� ����͹��; 4 - ���±��� ����͹��;
        //5 - ��������; 9 - ��������ʽα�� ���¾۽�; 10 - ��������ʽα�� ���¾۽�; 11 - ��������ʽα�� ����۽�; 12 - ʪ�ȼ��; 13 - �ȵ���; 14 - �����
        DWORD  dwColorAlarmUpperLimit; //��ɫ����ģʽ������ֵ��-20��~2000�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwColorAlarmLowerLimit; //��ɫ����ģʽ������ֵ��-20��~2000�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwRelativeHumidity; //���ʪ�ȣ�����ʪ�ȼ�⣨����һλС������Χ��0.0-100.0����λ��%���ٷֱȣ�������ʱ(ʵ��ֵ + 1) * 10�����������
        DWORD  dwAtmosphericTemperature;  //�����¶ȣ�����һλС������Χ��0.0-100.0����λ���棨���϶ȣ�������ʱ(ʵ��ֵ + 1) * 10�����������
        BYTE  byAutoShutEnabled; //�Զ���Ƭʹ�ܣ�ʹ�ܹر�ʱ���豸�˲����Զ�������Ƭ 1 �C �ر� 2 �C ����
        BYTE byGeneralLevelDefault;  //��ͨģʽ���뼶��Ĭ��ֵ
        BYTE byGeneralLevelMin;  //��ͨģʽ���뼶����Сֵ
        BYTE byGeneralLevelMax;  //��ͨģʽ���뼶�����ֵ
        BYTE  byRes[386];
    }USB_IMAGE_ENHANCEMENT_EX, *LPUSB_IMAGE_ENHANCEMENT_EX;

    //��Ƶ����
    typedef struct tagUSB_IMAGE_VIDEO_ADJUST
    {
        DWORD  dwSize;
        BYTE  byImageFlipStyle;  //����ģʽ: 0-�ر� 1-���� 2-���� 3-����
        BYTE  byPowerLineFrequencyMode;  //��Ƶ��ʽ��1-PAL(50HZ)
        BYTE  byCorridor;  //��ͷ����ģʽ(��ת): 0-�ر� 1-����
        BYTE  byDigitalZoom;  //���ֱ䱶: 0-X1   1-X2   2-X4   3-X8
        BYTE  byCursor;  //��ʾ���: 0-�ر�   1-����
        BYTE  byBadPointCursor;  //��ʾ����ʮ�ֹ�꣺0-�ر�  1-����
        BYTE  byBadPointCursorShiftMode; //�ƶ�����ʮ�ֹ�귽ʽ��0-�·�����  1-�ƶ�ָ��
        BYTE  byMappingStyle;  //�����ʽ��1-5
        DWORD  dwCursorPointX;  //���X����, ��һ��0-1000, ����Ϊԭ��
        DWORD  dwCursorPointY;  //���Y����, ��һ��0-1000, ����Ϊԭ��
        DWORD  dwBadCursorPointX;  //����ʮ�ֹ��X���꣬��һ��0-1000������Ϊԭ�㣨byBadPointCursorShiftModeΪ0ʱ��Ч��
        DWORD  dwBadCursorPointY;  //����ʮ�ֹ��Y���꣬��һ��0-1000������Ϊԭ�㣨byBadPointCursorShiftModeΪ0ʱ��Ч��
        BYTE  byPointXShiftLeft;  //����ʮ�ֹ��X���������ƶ�����Χ��0-15��byBadPointCursorShiftModeΪ1ʱ��Ч��
        BYTE  byPointXShiftRight;  //����ʮ�ֹ��X���������ƶ�����Χ��0-15��byBadPointCursorShiftModeΪ1ʱ��Ч��
        BYTE  byPointYShiftUp;  //����ʮ�ֹ��Y���������ƶ�����Χ��0-15��byBadPointCursorShiftModeΪ1ʱ��Ч��
        BYTE  byPointYShiftDown;  //����ʮ�ֹ��Y���������ƶ�����Χ��0-15��byBadPointCursorShiftModeΪ1ʱ��Ч��
        BYTE  byDeleteBadPoint;  //ȥ���������0-��Ч����; 1-����ʮ�ֹ�����ĵ����굽�������; 2-�ӻ������ɾ��ʮ�ֹ�����ĵ�����
        BYTE  byCursorColor; //�����ɫ��1-��ɫ  2-��ɫ  3-��ɫ  4-��ɫ
        BYTE  byImageFlipStyleDefaultState;  //����ģʽĬ��״̬: 0-�ر� 1-���� 2-���� 3-����
        BYTE  byPowerLineFrequencyModeDefaultState;  //��Ƶ��ʽĬ��״̬��1-PAL(50HZ) 2-NTSC(60HZ)
    }USB_IMAGE_VIDEO_ADJUST, *LPUSB_IMAGE_VIDEO_ADJUST;

    //����״̬
    typedef struct tagUSB_SYSTEM_ENCRYPT_STATUS
    {
        DWORD	dwSize;
        BYTE	byEncryptStatus;	//����״̬��0-������1-���ܳɹ���2-����ʧ��
        BYTE	byErrMsg;			//����ʧ��ԭ��0-������0xFF-��������
        BYTE	byRes[30];
    } USB_SYSTEM_ENCRYPT_STATUS, *LPUSB_SYSTEM_ENCRYPT_STATUS;

    //ָʾ�ƿ���
    typedef struct tagUSB_SYSTEM_INDICATORLIGHT
    {
        DWORD	dwSize;
        BYTE	byStatus;			//��˸״̬��0-δ��˸��1-��˸
        BYTE	byColour;			//��ɫ��1-red��2-white
        BYTE	byRes[30];
    } USB_SYSTEM_INDICATORLIGHT, *LPUSB_SYSTEM_INDICATORLIGHT;

    //ͼ��WDR
    typedef struct tagUSB_IMAGE_WDR
    {
        DWORD	dwSize;
        BYTE	byEnabled;		//ʹ�ܣ�0-�رգ�1-����
        BYTE	byMode;			//ģʽ��0-100
        BYTE	byLevel;		//�ȼ���0-100
        BYTE    byEnabledDefaultState;      //ʹ��Ĭ��״̬��0-�رգ�1-����
        BYTE	byRes[28];
    }USB_IMAGE_WDR, *LPUSB_IMAGE_WDR;

    //LOGO����
    typedef struct tagUSB_IMAGE_VIDEO_LOGO_SWITCH
    {
        DWORD	dwSize;
        BYTE	byEnabled;		//ʹ�ܣ�0-�رգ�1-����
        BYTE	byChannelID;	//ͨ����
        BYTE	byType;			//OSD����ͼ�����ͣ�1-Դͼ��2-��ʾ�ˣ�3-��ǽ�����ӣ�4-���봦����
        BYTE	byPortID;		//�˿ںţ�0-2
        BYTE	byPictureID;	//ͼƬ����
        BYTE	byLogoID;		//Logo��ţ�0-2
        BYTE	byRes[30];
    }USB_IMAGE_VIDEO_LOGO_SWITCH, *LPUSB_IMAGE_VIDEO_LOGO_SWITCH;

    //LOGO��������
    typedef struct tagUSB_IMAGE_VIDEO_LOGO_CFG
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//ͨ����
        BYTE	byLogoID;			//Logo��ţ�0-2
        BYTE	byLogoType;			//logo���ͣ�1-ͨ�ã�2-������3-���
        BYTE	byLogoPicNums;		//logoͼƬ����
        DWORD	dwRegionX;			//�������϶���X���꣬��һ��ֵ����Χ0-1000
        DWORD	dwRegionY;			//�������϶���Y���꣬��һ��ֵ����Χ0-1000
        DWORD	dwRegionWidth;		//������ȣ���һ��ֵ����Χ0-1000
        DWORD	dwRegionHeight;		//����߶ȣ���һ��ֵ����Χ0-1000
        BYTE	byFlickerControl;	//��˸����
        BYTE	byShieldColorY;		//����ɫY
        BYTE	byShieldColorU;		//����ɫU
        BYTE	byShieldColorV;		//����ɫV
        BYTE	byRes[32];
    }USB_IMAGE_VIDEO_LOGO_CFG, *LPUSB_IMAGE_VIDEO_LOGO_CFG;

    //OSD����
    typedef struct tagUSB_IMAGE_VIDEO_OSD_SWITCH
    {
        DWORD	dwSize;
        BYTE	byEnabled;		//ʹ�ܣ�0-�رգ�1-����
        BYTE	byChannelID;	//ͨ����
        BYTE	byType;			//OSD����ͼ�����ͣ�1-Դͼ��2-��ʾ�ˣ�3-��ǽ�����ӣ�4-���봦����
        BYTE	byPortID;		//�˿ںţ�0-2
        BYTE	byRes[32];
    }USB_IMAGE_VIDEO_OSD_SWITCH, *LPUSB_IMAGE_VIDEO_OSD_SWITCH;

    //OSD����
    typedef struct tagUSB_OSD_PROPERTY
    {
        BYTE    byRowID;                    //��ID����1��ʼ����
        BYTE    byRes1[3];
        DWORD   dwRegionX;                  //�������϶���X���꣬��һ��ֵ����Χ0-1000
        DWORD   dwRegionY;                  //�������϶���Y���꣬��һ��ֵ����Χ0-1000
        DWORD   dwBackgroundColor;          //����ɫ
        DWORD   dwFontColor;                //������ɫ
        BYTE    byVerticalScalingRatio;     //��ֱ���ű�������Χ0-4
        BYTE    byHorizontalScalingRatio;   //ˮƽ���ű�������Χ0-4
        BYTE    byRowCharNums;              //�����ַ�����0-32
        BYTE    byRes2;
        WORD    wCharacterCode[32];         //�ַ��룬0-32
    }USB_OSD_PROPERTY, *LPUSB_OSD_PROPERTY;

    //OSD��������
    typedef struct tagUSB_IMAGE_VIDEO_OSD_CFG
    {
        DWORD	dwSize;
        BYTE	byChannelID;				//ͨ����
        BYTE	byType;						//OSD����ͼ�����ͣ�1-Դͼ��2-��ʾ�ˣ�3-��ǽ�����ӣ�4-���봦����
        BYTE	byPortID;					//�˿ںţ�0-2
        BYTE	byAutoBrightness;			//�Զ��������ȣ�0-�رգ�1-����
        BYTE	byTranslucent;				//�Ƿ��͸����0-�رգ�1-����
        BYTE    byRes1[3];
        DWORD	dwFlickerControl;			//��˸����
        USB_OSD_PROPERTY struOSDProperty[4];//OSD����
        BYTE	byRes[32];
    }USB_IMAGE_VIDEO_OSD_CFG, *LPUSB_IMAGE_VIDEO_OSD_CFG;

    //��·����ȡ��
    typedef struct tagUSB_IMAGE_VIDEO_MULTIPLE_STREAM
    {
        DWORD	dwSize;
        BYTE	byChannelID;			//��·������ͨ���ţ�Ŀǰ���֧��3·�����ϣ���Χ0-2
        BYTE    byRes1[3];
        DWORD	dwEncWidth;				//���������Χ640 - 1920
        DWORD	dwEncHeight;			//����� 360 - 1080
        BYTE	byVideoType;			//�������� 1 - Standard H264
        BYTE    byRes2[3];
        DWORD	dwIFrameInterval;		//I֡��� 0 - 9000
        DWORD	dwBitrate;				//�������ʣ���λbps
        BYTE	byBpsType;				//�������ʿ������ͣ�1-VBR��2-CBR
        BYTE	byProfile;				/*����Э�飺1-H.264�����profile BP
                                        2-H.264�����profile MP
                                        3-H.264�����profile HP
                                        4-H.264�����profile SVC*/
        BYTE	byFps;					//����֡�ʣ���Χ0-30
        BYTE	byRes[29];
    }USB_IMAGE_VIDEO_MULTIPLE_STREAM, *LPUSB_IMAGE_VIDEO_MULTIPLE_STREAM;

    //��·����ȡ��ǿ��I֡
    typedef struct tagUSB_IMAGE_VIDEO_MULTIPLE_IFRAME
    {
        DWORD	dwSize;
        BYTE	byChannelID;			//ͨ����
        BYTE	byIFrameFlag;			//�Ƕ�ǿ��I֡��0-�رգ�1-����
        BYTE	byRes[30];
    }USB_IMAGE_VIDEO_MULTIPLE_IFRAME, *LPUSB_IMAGE_VIDEO_MULTIPLE_IFRAME;

    //��Ƶ״̬
    typedef struct tagUSB_AUDIO_STATUS
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//��Ƶͨ����
        BYTE	byConnectStatus;	//��Ƶ״̬��0-δ���룬1-����
        BYTE	byRes[30];
    }USB_AUDIO_STATUS, *LPUSB_AUDIO_STATUS;

    //��Ƶ����
    typedef struct tagUSB_AUDIO_VOLUME
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//��Ƶͨ����
        BYTE	byVolume;			//����ֵ
        BYTE	byRes[30];
    }USB_AUDIO_VOLUME, *LPUSB_AUDIO_VOLUME;

    //��Ƶ����ѡ��
    typedef struct tagUSB_AUDIO_AMER
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//��Ƶͨ����
        BYTE	byEnabled;			//��Ƶ����ͨ��ʹ�ܣ�0-�رգ�1-����
        BYTE	byRes[30];
    }USB_AUDIO_AMER, *LPUSB_AUDIO_AMER;

    //AEC��ʱ����
    typedef struct tagUSB_AUDIO_AECSP
    {
        DWORD   dwSize;
        BYTE    byInChannelID;      //��Ƶ����ͨ����
        BYTE    byEnabled;          //AECʹ�ܣ�0-�رգ�1-����
        WORD    wAecValue;          //ʱ��ֵ����Χ0-1000
        BYTE    byOutChannelID;     //��Ƶ���ͨ����
        BYTE    byRes[31];
    }USB_AUDIO_AECSP, *LPUSB_AUDIO_AECSP;

    //��ʱ�Զ��Ż�
    typedef struct tagUSB_AUDIO_DEVICE_DELAY
    {
        DWORD	dwSize;
        BYTE	byInChannelID;		//��Ƶ����ͨ����
        BYTE	byOutChannelID;		//��Ƶ���ͨ����
        BYTE	byProcessMode;		//���Թ��̣�1-��ʼ���ԣ�2-��ȡ���
        BYTE    byRes1;
        WORD	wAecValue;			//ʱ��ֵ����Χ0-1000
        BYTE	byRes[30];
    }USB_AUDIO_DEVICE_DELAY, *LPUSB_AUDIO_DEVICE_DELAY;

    //����ɨ��״̬
    typedef struct tagUSB_AUDIO_BT
    {
        DWORD	dwSize;
        BYTE	byEnabled;			//����ɨ��ʹ�ܣ�0-�رգ�1-����
        BYTE	byRes[31];
    }USB_AUDIO_BT, *LPUSB_AUDIO_BT;

    //����MAC��ַ
    typedef struct tagUSB_AUDIO_BT_MAC
    {
        DWORD	dwSize;
        BYTE	byMacAddress[40];	//����MAC��ַ
        BYTE	byRes[32];
    }USB_AUDIO_BT_MAC, *LPUSB_AUDIO_BT_MAC;

    //��������״̬
    typedef struct tagUSB_AUDIO_BT_STATUS
    {
        DWORD	dwSize;
        BYTE	byConnectStatus;	//��������״̬��0-δ���ӣ�1-����
        BYTE	byRes[31];
    }USB_AUDIO_BT_STATUS, *LPUSB_AUDIO_BT_STATUS;

    //��Ƶ�Լ�
    typedef struct tagUSB_AUDIO_DETECT
    {
        DWORD	dwSize;
        BYTE	byInChannelID;		//��Ƶ����ͨ����
        BYTE	byOutChannelID;		//��Ƶ���ͨ����
        BYTE	byProcessMode;		//���Թ��̣�1-��ʼ���ԣ�2-��ȡ���
        BYTE	byTestResult;		//���Խ����1-�Լ���ȷ��2-�Լ����
        BYTE	byRes[32];
    }USB_AUDIO_DETECT, *LPUSB_AUDIO_DETECT;

    //��Ч�Լ�
    typedef struct tagUSB_AUDIO_EFFICT_DETECT
    {
        DWORD	dwSize;
        BYTE	byInChannelID;		//��Ƶ����ͨ����
        BYTE	byOutChannelID;		//��Ƶ���ͨ����
        BYTE	byTestMode;			//����ģʽ��1-�����⣬2-������⣬3-��������
        BYTE	byProcessMode;		//���Թ��̣�1-��ʼ���ԣ�2-��ȡ���
        BYTE	byTestResult;		//���Խ����
        //������ģʽΪ1ʱ��0-����Ч���Ϻã�1-����Ч���ϲ2-�������ʧ��
        //������ģʽΪ2ʱ��0-���������С��1-�������������2-��������ϴ�
        //������ģʽΪ3ʱ��0-��������1-��������
        BYTE	byRes[31];
    }USB_AUDIO_EFFICT_DETECT, *LPUSB_AUDIO_EFFICT_DETECT;

    //��������
    typedef struct tagUSB_AUDIO_FAC_TEST
    {
        DWORD	dwSize;
        BYTE	byTestMode;			//����ģʽ��1-��������USB MIC��2-����ͨ·��3-����������Ƶ
        BYTE	byProcessMode;		//���Թ��̣�1-��ʼ���ԣ�2-��ȡ���
        BYTE	byTestResult;		//���Խ����1-������ȷ��2-���Դ���
        BYTE	byRes[29];
    }USB_AUDIO_FAC_TEST, *LPUSB_AUDIO_FAC_TEST;

    //��ƵAGC
    typedef struct tagUSB_AUDIO_AGC_CONFIG
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//��Ƶͨ����
        BYTE	byEnabled;			//AGCʹ�ܣ�0-�رգ�1-����
        BYTE	byGainLevel;		//����ֵ����Χ0-30
        BYTE	byRes[29];
    }USB_AUDIO_AGC_CONFIG, *LPUSB_AUDIO_AGC_CONFIG;

    //��Ƶ����
    typedef struct tagUSB_AUDIO_REDUCE_NOISE
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//��Ƶͨ����
        BYTE	byEnabled;			//����ʹ�ܣ�0-�رգ�1-����
        BYTE	byLevel;			//����ȼ���0-5
        BYTE	byLevelDefault;     //����ȼ�Ĭ��ֵ
        BYTE	byLevelMin;         //����ȼ���Сֵ
        BYTE	byLevelMax;         //����ȼ����ֵ
        BYTE	byRes[26];
    }USB_AUDIO_REDUCE_NOISE, *LPUSB_AUDIO_REDUCE_NOISE;

    //����ʶ��
    typedef struct tagUSB_AUDIO_RECOG_RSLT
    {
        DWORD	dwSize;
        BYTE	byAudAiCmd;			//�������������Χ��0-100
        BYTE	byMatchAudAi;		//ƥ�䵽������ָ���Χ��0-100
        BYTE    byRes1[2];
        DWORD	dwResSet;			//���ò���ֵ��0 - (2^32 - 1)
        DWORD	dwResRet;			//��ȡ����ֵ��0 - (2^32 - 1)
        BYTE	byRes[32];
    }USB_AUDIO_RECOG_RSLT, *LPUSB_AUDIO_RECOG_RSLT;

    //ECHO ���
    typedef struct tagUSB_AUDIO_ECHO_SET
    {
        BYTE    byInChannelID;      //��ǰ����ͨ��
        BYTE    byOutChannelID;     //��ǰ���ͨ��
        BYTE    byEnabled;          //�Ƿ�ʹ��
        BYTE    byRes[29];
    }USB_AUDIO_ECHO_SET, *LPUSB_AUDIO_ECHO_SET;

    //��Ƶ��������
    typedef struct tagUSB_AUDIO_SIGNAL_TRANS
    {
        BYTE    bySignalTransType;  //�������ͣ�1-��Ƶ���ݵ�����2-log������3-�������ԣ�4-�رս��ԣ�5-��Ƶ�����Զ�ģʽ������6-��Ƶ�����Զ�ģʽ�رգ�7-��Ƶ����Զ�ģʽ������8-��Ƶ����Զ�ģʽ�ر�
        BYTE    byRes[31];
    }USB_AUDIO_SIGNAL_TRANS, *LPUSB_AUDIO_SIGNAL_TRANS;

    //��Ƶ�������ͨ����Ϣ
    typedef struct tagUSB_AUDIO_INPUT_OUTPUT_CHANNELINFO
    {
        BYTE    byInChannelID;      //��ǰ����ͨ��
        BYTE    byOutChannelID;     //��ǰ���ͨ��
        BYTE    byRes[30];
    }USB_AUDIO_INPUT_OUTPUT_CHANNELINFO, *LPUSB_AUDIO_INPUT_OUTPUT_CHANNELINFO;

    //��Ƶ���߲�������
    typedef struct tagUSB_AUDIO_PROCESS_LINE_CFG
    {
        BYTE    byEnabled;          //��Ƶ���߲���ʹ�ܣ�0-�رգ�1-����
        BYTE    byRes[31];
    }USB_AUDIO_PROCESS_LINE_CFG, *LPUSB_AUDIO_PROCESS_LINE_CFG;

    //��ȡ��ƵPOE�������ڼ��״̬
    typedef struct tagUSB_AUDIO_POE_LINK_STATUS
    {
        BYTE    byPOELinkStatus;    //poe�������ڼ�⣺0-�쳣��1-����
        BYTE    byRes[31];
    }USB_AUDIO_POE_LINK_STATUS, *LPUSB_AUDIO_POE_LINK_STATUS;

    //ʰ��
    typedef struct tagUSB_AUDIO_PICK_UP
    {
        BYTE    byMode;           //ģʽ��0-ȫ��1-����
        BYTE    byModeDefault;    //ģʽĬ��ֵ
        BYTE    byRes[30];
    }USB_AUDIO_PICK_UP, *LPUSB_AUDIO_PICK_UP;

    //����ģʽ
    typedef struct tagUSB_PTZ_TRACK_MODE
    {
        DWORD	dwSize;
        BYTE	byTrackingMode;		//����ģʽ��1-�ֶ���2-�Զ���3-AutoFrame
        BYTE	byRes[31];
    }USB_PTZ_TRACK_MODE, *LPUSB_PTZ_TRACK_MODE;

    //Ԥ�õ����
    typedef struct tagUSB_PTZ_PRESET_CFG
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//ͨ����
        BYTE	byPresetID;			//Ԥ�õ�ţ���Χ1-5
        BYTE	byRes[30];
    }USB_PTZ_PRESET_CFG, *LPUSB_PTZ_PRESET_CFG;

    //�Զ�����������
    typedef struct tagUSB_PTZ_AUTO_TRACK_SENSITIVITY
    {
        DWORD	dwSize;
        BYTE	bySensitivity;		//�����ȣ�1-�У�2-��
        BYTE	byRes[31];
    }USB_PTZ_AUTO_TRACK_SENSITIVITY, *LPUSB_PTZ_AUTO_TRACK_SENSITIVITY;

    //���»�����������
    typedef struct tagUSB_THERMOMETRY_BASIC_PARAM
    {
        DWORD  dwSize;
        BYTE       byTemperatureRangeAutoChangedEnabled; //���µ�λ�Զ��л�ģʽʹ�ܣ�0-�ر�  1-����
        BYTE       byEnabled;//�������¹���ʹ��
        BYTE       byDisplayMaxTemperatureEnabled;//��ʾ�����: 0-�ر�; 1-����
        BYTE       byDisplayMinTemperatureEnabled;//��ʾ�����: 0-�ر�; 1-����
        BYTE       byDisplayAverageTemperatureEnabled;//��ʾƽ����: 0-�ر�; 1-����
        BYTE       byTemperatureUnit;//�¶ȵ�λ: 1 - �����¶�;2 - �����¶�;3 - �������¶�(Э�鴫����Լ���������¶���Ϊ��λ����)
        BYTE       byTemperatureRange;//���·�Χ: [1~5]����λ����λ��������Ӧ�¶ȷ�Χ������ο��豸��Ʒ˵��
        BYTE       byCalibrationCoefficientEnabled;//���ñ궨ϵ��:0 - �ر�;1 - ����
        DWORD       dwCalibrationCoefficient;//�궨ϵ��: 0.00~30.00 ,����ʱʵ��ֵ * 100���������
        DWORD       dwExternalOpticsWindowCorrection;//�ⲿ��ѧ�¶�: -40.0~80.0�� ,����ʱ(ʵ��ֵ + 100) * 10�����������   ת����ʽ2������ʱ ʵ��ֵ*2n��С�����ֽضϣ�n�Ĵ�С����shiftLength�ֶΣ����ֶξ�����δ��䣬���ֶ�floatTransMode����������û��floatTransMode�ֶΣ�Ĭ�����ʹ���
        DWORD       dwEmissivity;//������: 0.01~1(��ȷ��С�������λ), ����ʱʵ��ֵ * 100���������   ת����ʽ2������ʱ ʵ��ֵ*2n��С�����ֽضϣ�n�Ĵ�С����shiftLength�ֶΣ����ֶξ�����δ��䣬���ֶ�floatTransMode����������û��floatTransMode�ֶΣ�Ĭ�����ʹ���
        BYTE       byDistanceUnit;//���뵥λ: 1 - ��; 2 - ����; 3 - Ӣ��
        BYTE       byShowAlarmColorEnabled; //������ɫ��ʾʹ��: 0-�ر�  1-����
        BYTE       byAlarmType; //��������: 1-�����, 2-�����, 3-ƽ����, 4-�²�
        BYTE       byAlarmRult;  //������������: 1-����  2-С��
        DWORD       dwDistance;//����: 0.3-2m��Э�鴫����Լ����cm��Ϊ��λ����, ��ȷ��С�����1λ��  ת����ʽ2������ʱ ʵ��ֵ*2n��С�����ֽضϣ�n�Ĵ�С����shiftLength�ֶΣ����ֶξ�����δ��䣬���ֶ�floatTransMode����������û��floatTransMode�ֶΣ�Ĭ�����ʹ���
        BYTE       byReflectiveEnable;//�����¶�ʹ��: 0 - �ر�; 1 - ����
        BYTE       byAutoDrift;  //�Զ���Ư��������: 1-�����㷨������Ư   2-NUC����Ư
        BYTE       bySSECompensation;  //SSE����: 1-֧�ֲ��¾�������Ӧ   2-��֧��
        BYTE       byThermalRawData;  //�ȳ���������ѹ����ʽ: 0-��֧��ѹ��   1-LPLѹ������
        DWORD       dwReflectiveTemperature;//�����¶�: -100.0~1000.0�棨��ȷ��С�����1λ��,����ʱ(ʵ��ֵ + 100) * 10�����������   ת����ʽ2������ʱ ʵ��ֵ*2n��С�����ֽضϣ�n�Ĵ�С����shiftLength�ֶΣ����ֶξ�����δ��䣬���ֶ�floatTransMode����������û��floatTransMode�ֶΣ�Ĭ�����ʹ���
        BYTE       byThermomrtryInfoDisplayPosition;//������Ϣ��ʾλ��: 1-������� 2-��Ļ���Ͻ�
        BYTE       byThermometryStreamOverlay; //���������¶���Ϣ: 1-������  2-����
        BYTE       byDisplayCenTempEnabled;  //��ʾ�����£�0-�ر�   1-����
        BYTE       byBackcolorEnabled;  //��ʾ����ɫ��0-�ر�  1-����
        DWORD       dwAlert;//Ԥ���¶�: -20��~400��, ����ʱ(ʵ��ֵ+100)*10�����������
        DWORD       dwAlarm;//�����¶�: -20��~400��, ����ʱ(ʵ��ֵ+100)*10�����������
        DWORD       dwExternalOpticsTransmit;//�ⲿ��ѧ͸����: 0.01~1(��ȷ��С�������λ), ����ʱʵ��ֵ*100���������   ת����ʽ2������ʱ ʵ��ֵ*2n��С�����ֽضϣ�n�Ĵ�С����shiftLength�ֶΣ����ֶξ�����δ��䣬���ֶ�floatTransMode����������û��floatTransMode�ֶΣ�Ĭ�����ʹ���
        DWORD       dwTemperatureRangeUpperLimit; //���µ�λ�����¶�ֵ��ֻ������-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        //����Ԥ�������¶���Ϣ������ʾ����ʽ�����ڴ��¶ȷ�Χ�� > aboveMaxRangeTemp��ʾ��С�ڴ��¶ȷ�Χ�á���ʾ
        DWORD       dwTemperatureRangeLowerLimit; //���µ�λ�����¶�ֵ��ֻ������-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        //����Ԥ�������¶���Ϣ������ʾ����ʽ��С�ڴ��¶ȷ�Χ�� < aboveMaxRangeTemp��ʾ�����ڴ��¶ȷ�Χ�á���ʾ
        DWORD       dwTemperatureRangeExcursionUpperLimit; //���µ�λƫ�������¶�ֵ��ֻ������-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        //����Ԥ�������¶���Ϣ������ʾ����ʽ�����ڴ��¶ȷ�Χ�á���ʾ��С��������ʾ
        DWORD       dwTemperatureRangeExcursionLowerLimit; //���µ�λƫ�������¶�ֵ��ֻ������-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        //����Ԥ�������¶���Ϣ������ʾ����ʽ��С�ڴ��¶ȷ�Χ�á���ʾ������������ʾ
        DWORD       dwAtmosphericHumidity;  //����ʪ��ֵ������ʹ�ã�����Χ0.0~100.0������ʱʵ��ֵ*10�����������
        BYTE       byFloatTransMode; //���������䷽ʽ  1 - ���ʹ���  2 - ��λ����      ���ʹ��� : �Ƚ�������ת��Ϊ�������ٳ���10�ı�����ת������������Ȼ����    ��λ���� : ֱ�ӽ�����������2n���ض�С����Ȼ����
        BYTE       byShiftLength; //��������λ�������2��N�η�������N�Ĵ�С 1-6; 2-9; 3-13; 4-16; 5-19;
        BYTE       byEnviromentTemperatureEnable; //�����¶�ʹ�ܣ�1 - �ر� 2 - ����
        BYTE       byRes1;
        DWORD      dwEnviromentTemperature;  //�����¶ȣ�-100.0~1000.0�棨��ȷ��С�����2λ������ʱ(ʵ��ֵ + 100) * 100����ɷǸ�����
        BYTE       byRes[176];
    }USB_THERMOMETRY_BASIC_PARAM, *LPUSB_THERMOMETRY_BASIC_PARAM;

    //����ģʽ����
    typedef struct tagUSB_THERMOMETRY_MODE
    {
        DWORD  dwSize;
        BYTE       byThermometryMode;//����ģʽ: 1-��ͨ; 2-ר��
        BYTE       byThermometryROIEnabled;//����ROIʹ��: 0 - �ر�; 1 - ����
        BYTE       byRes[62];
    }USB_THERMOMETRY_MODE, *LPUSB_THERMOMETRY_MODE;

    //���¹�������
    typedef struct tagTHERMAL_REGION
    {
        DWORD  dwSize;
        BYTE  byRegionID;  //����ID����1��ʼ����
        BYTE  byRegionEnabled;  //����ʹ�� 0-�ر� 1-����
        BYTE  byRes1[2];
        DWORD dwRegionX;  //�������϶���X���꣬��һ��ֵ����Χ0-1000
        DWORD dwRegionY;  //�������϶���Y���꣬��һ��ֵ����Χ0-1000
        DWORD dwRegionWidth;  //������ȣ���һ��ֵ����Χ0-1000
        DWORD dwRegionHeight;  //����߶ȣ���һ��ֵ����Χ0-1000
        BYTE  byRes[12];
    }THERMAL_REGION, *LPTHERMAL_REGION;

    //���¹�������
    typedef struct tagUSB_THERMOMETRY_REGIONS
    {
        DWORD  dwSize;
        BYTE         byRegionNum;    //���������ܸ���
        BYTE         byRes1[3];
        THERMAL_REGION    struRegion[MAX_THERMAL_REGIONS];
        BYTE         byRes[188];
    }USB_THERMOMETRY_REGIONS, *LPUSB_THERMOMETRY_REGIONS;

    //�ȳ���������������
    typedef struct tagUSB_THERMAL_STREAM_PARAM
    {
        DWORD  dwSize;
        BYTE       byVideoCodingType;//�������ݱ��������: 1-�ȳ���������; 2-ȫ����������; 3-ʵʱ������; 4-��ͼ����; 5-�ȳ���ʵʱ��; 6-YUVʵʱ��; 7-PS��װMJPEGʵʱ��;
        //8-ȫ����������+YUVʵʱ��; 9-YUV+������; 10-��YUV��������ͷ;  11-����ͷ+YUV+������
        BYTE  byRes[3];
        DWORD dwWidth;
        DWORD dwHeight;
        DWORD dwFrameRate;
    }USB_THERMAL_STREAM_PARAM, *LPUSB_THERMAL_STREAM_PARAM;

    //��������
    typedef struct tagUSB_TEMPERATURE_CORRECT
    {
        DWORD  dwSize;
        BYTE   byRes1;  //����
        BYTE   byEnabled;  //ʹ�� 0-�ر� 1-����
        BYTE   byStreamOverlay;  //�����¶���������ʹ�� 0-�ر� 1-����
        BYTE   byCorrectEnabled; //��������ʹ�� 0-�ر� 1-����
        DWORD  dwEmissivity; //���巢����:0.01-1.00, ����ʱʵ��ֵ*100���������
        DWORD  dwDistance;   //���� 0.3-2m, Э�鴫��ʱ������Ϊ��λ
        DWORD  dwTemperature;  //�����¶� 30.0~50.0��, ����ʱʵ��ֵ*10���������
        DWORD  dwCentrePointX;  //�������ĵ�X���꣬��һ��ֵ����Χ0-1000
        DWORD  dwCentrePointY;  //�������ĵ�Y���꣬��һ��ֵ����Χ0-1000
        DWORD  dwCorrectTemperature;  //�����¶� -99.0-99.0�� ����ʱ(ʵ��ֵ + 100) * 10�����������
        BYTE   byRes[36];
    }USB_TEMPERATURE_CORRECT, *LPUSB_TEMPERATURE_CORRECT;

    //�����������
    typedef struct tagUSB_BLACK_BODY
    {
        DWORD  dwSize;
        BYTE   byEnabled;  //ʹ�� 0-�ر� 1-����
        BYTE   byRes1[3];
        DWORD  dwEmissivity; //���巢����:0.01 - 1.00, ����ʱʵ��ֵ * 100���������
        DWORD  dwDistance;   //���� 0.3-2m, Э�鴫��ʱ������Ϊ��λ
        DWORD  dwTemperature;   //�����¶� 30.0~50.0��, ����ʱʵ��ֵ*10���������
        DWORD  dwCentrePointX;  //�������ĵ�X���꣬��һ��ֵ����Χ0-1000
        DWORD  dwCentrePointY;  //�������ĵ�Y���꣬��һ��ֵ����Χ0-1000
        BYTE   byRes[40];
    }USB_BLACK_BODY, *LPUSB_BLACK_BODY;

    //���²�����������
    typedef struct tagUSB_BODYTEMP_COMPENSATION
    {
        DWORD   dwSize;   //�ṹ���С
        BYTE       byEnabled;  //ʹ�� 0-�ر� 1-����
        BYTE       byType;   //������ʽ:1-�ֶ����� 2-�Զ�����
        BYTE       byRes1[2];
        int        iCompensationValue; //�����¶� [-10.0 10.0]���϶�, ����ʱʵ��ֵ*10���������
        DWORD      dwSmartCorrection; //�ֶ�У׼ -99.0~990.��, ����ʱ(ʵ��ֵ+100)*10�����������
        DWORD      dwEnvironmentalTemperature;    //�����¶� -99.0~99.0��, ����ʱ(ʵ��ֵ+100)*10�����������
        BYTE       byEnvironmentalTemperatureMode;   //�����¶�ģʽ 1-�Զ�ģʽ 2-�ֶ�ģʽ
        BYTE       byTemperatureCurveSensitivityLevel;//�¶����������ȵȼ�: 1-�� 2-�� 3-��  
        BYTE       byEnvironmentCompensationenabled;//��������ʹ��: 1-�ر�  2-����
        BYTE       byRes[45];
    }USB_BODYTEMP_COMPENSATION, *LPUSB_BODYTEMP_COMPENSATION;

    //ȫ�����²�������
    typedef struct tagUSB_P2P_PARAM
    {
        DWORD   dwSize;   //�ṹ���С
        BYTE byJpegPicEnabled;  //�豸�Ƿ񷵻�jpegͼƬ 0-�ر� 1-����
        BYTE byRes[31];
    }USB_P2P_PARAM, *LPUSB_P2P_PARAM;

    //˫��У׼�������
    typedef struct tagUSB_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL
    {
        DWORD   dwSize;   //�ṹ���С
        BYTE byDoubleLightsCorrectPointsEnabled;  //˫��У׼����ʹ�ܿ��� 0-�ر� 1-����
        BYTE byRes[31];
    }USB_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL, *LPUSB_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL;

    //�ȳ�������㷨�汾
    typedef struct tagUSB_THERMAL_ALG_VERSION
    {
        DWORD   dwSize;   //�ṹ���С
        BYTE   byThermometryAlgName[64];  //�����㷨��汾��Ϣ
        BYTE   byThermometryAlgLogicVersion; //�����㷨�߼��汾��
        /*
        0 - V0�汾���ֶγ���ǰ�İ汾����ʶΪV0
        1 - V1�汾������DV 5.5.29�Ĳ��´����߼�
        2 - V2�汾�����ڴ�ʦ�� 5.5.27�Ĳ����߼��������˲����м����
        3 - V3�汾������V2�汾���޸��˶Բ��½���Ĵ�����ʽΪ����2λ����
        4 - V4�汾������V3�汾���㷨��������������λ�ķ�ʽ�ضϣ����ұ���2λС������
        */
        BYTE   byRes[63];
    }USB_THERMAL_ALG_VERSION, *LPUSB_THERMAL_ALG_VERSION;

    //���±궨�ļ����뵼��
    typedef struct tagUSB_THERMOMETRY_CALIBRATION_FILE
    {
        DWORD   dwSize;   //�ṹ���С
        BYTE   byFileName[64];  //�ļ�����
        DWORD   dwFileLenth;      //�궨�ļ�����
        BYTE   *pCalibrationFile;     //�궨�ļ�����
        BYTE   byRes[56];
    }USB_THERMOMETRY_CALIBRATION_FILE, *LPUSB_THERMOMETRY_CALIBRATION_FILE;

    //ץ��ͼ
    typedef struct tagUSB_JPEGPIC_WITH_APPENDDATA
    {
        DWORD   dwSize;   //�ṹ���С
        DWORD       dwJpegPicLen;//JpegͼƬ����
        DWORD       dwJpegPicWidth;//ͼ�����
        DWORD       dwJpegPicHeight;//ͼ��߶�
        DWORD       dwP2pDataLen;//ȫ���������ݳ���
        BYTE       byIsFreezedata;//�Ƿ����ݶ���: 0-��; 1-��
        BYTE       byTemperatureDataLength;//�������ݳ��ȣ�2��4��
        BYTE       byRes2[2];
        DWORD       dwScale;//�Ŵ������������ݳ���Ϊ2ʱ���أ�
        int        iOffset;//ƫ�������������ݳ���Ϊ2ʱ���أ�
        BYTE       *pJpegPic;//�ȳ���ͼƬ����
        BYTE       *pP2pData;//ȫ����������
        BYTE       byRes[28];
    }USB_JPEGPIC_WITH_APPENDDATA, *LPUSB_JPEGPIC_WITH_APPENDDATA;


    //ROI����
    typedef struct tagROI_REGION
    {
        BYTE       byROIRegionID;//ROI����ID����1��ʼ������+1����
        BYTE       byROIRegionEnabled;//ROI����ʹ�ܣ�0 - �رգ�1 - ����
        BYTE       byRes1[2];
        DWORD       dwROIRegionX;//�������϶���X���꣬��һ��ֵ����Χ0-1000
        DWORD       dwROIRegionY;//�������϶���Y���꣬��һ��ֵ����Χ0-1000
        DWORD       dwROIRegionWidth;//������ȣ���һ��ֵ����Χ0-1000
        DWORD       dwROIRegionHeight;//����߶ȣ���һ��ֵ����Χ0-1000
        DWORD       dwDistance;//���룺0.3-2m��Э�鴫����Լ����cm��Ϊ��λ����, ��ȷ��С�����1λ��
        BYTE       byRes[8];
    }ROI_REGION, *LPROI_REGION;

    //ROI�������Ϣ��ѯ
    typedef struct tagUSB_ROI_MAX_TEMPERATURE_SEARCH
    {
        DWORD   dwSize;   //�ṹ���С
        WORD       wMillisecond;//����
        BYTE       byRes2;//����
        BYTE       bySecond;//��
        BYTE       byMinute;//����
        BYTE       byHour;//Сʱ
        BYTE       byDay;//��
        BYTE       byMonth;//��
        WORD       wYear;//��
        BYTE       byJpegPicEnabled;//�豸�Ƿ񷵻�jpegͼƬ
        BYTE       byMaxTemperatureOverlay;//�Ƿ���������
        BYTE       byRegionsOverlay;//�Ƿ���ӹ����
        BYTE       byROIRegionNum;//ROI�����ܸ���
        BYTE       byRes1[2];
        ROI_REGION      struThermalROIRegion[MAX_ROI_REGIONS];
        BYTE       byRes[176];
    }USB_ROI_MAX_TEMPERATURE_SEARCH, *LPUSB_ROI_MAX_TEMPERATURE_SEARCH;

    //ROI������Ϣ
    typedef struct tagROI_REGION_INFO
    {
        BYTE       byROIRegionID;//ROI����ID����1��ʼ������+1����
        BYTE       byRes1[3];
        DWORD       dwMaxROIRegionTemperature;//�����: 30.0~50.0��, ����ʱʵ��ֵ * 10���������
        DWORD       dwVisibleROIRegionMaxTemperaturePointX;//ROI����ɼ��������X���꣬��һ��ֵ����Χ0-1000
        DWORD       dwVisibleROIRegionMaxTemperaturePointY;//ROI����ɼ��������Y���꣬��һ��ֵ����Χ0-1000
        DWORD       dwThermalROIRegionMaxTemperaturePointX;//ROI�����ȳ��������X���꣬��һ��ֵ����Χ0-1000
        DWORD       dwThermalROIRegionMaxTemperaturePointY;//ROI�����ȳ��������Y���꣬��һ��ֵ����Χ0-1000
        BYTE       byRes[8];
    }ROI_REGION_INFO, *LPROI_REGION_INFO;

    //ROI�������Ϣ��ѯ��Ӧ
    typedef struct tagUSB_ROI_MAX_TEMPERATURE_SEARCH_RESULT
    {
        DWORD   dwSize;   //�ṹ���С
        DWORD       dwMaxP2PTemperature;//ȫ�������: 30.0~50.0��, ����ʱʵ��ֵ * 10���������
        DWORD       dwVisibleP2PMaxTemperaturePointX;//ȫ���ɼ��������X���꣬��һ��ֵ����Χ0-1000
        DWORD       dwVisibleP2PMaxTemperaturePointY;//ȫ���ɼ��������Y���꣬��һ��ֵ����Χ0-1000
        DWORD       dwThermalP2PMaxTemperaturePointX;//ȫ���ȳ��������X���꣬��һ��ֵ����Χ0-1000
        DWORD       dwThermalP2PMaxTemperaturePointY;//ȫ���ȳ��������Y���꣬��һ��ֵ����Χ0-1000
        BYTE       byROIRegionNum;//ROI�����ܸ���
        BYTE       byRes2[3];
        DWORD       dwJpegPicLen;//JpegͼƬ����
        ROI_REGION_INFO       struThermalROIRegionInfo[MAX_ROI_REGIONS];
        BYTE       *pJpegPic;//ͼƬ���ݣ�����������Ϣ֮��ĩβֻ����1�Σ�
        BYTE       byRes[160];
    }USB_ROI_MAX_TEMPERATURE_SEARCH_RESULT, *LPUSB_ROI_MAX_TEMPERATURE_SEARCH_RESULT;

    //˫��У׼
    typedef struct tagUSB_DOUBLE_LIGHTS_CORRECT
    {
        DWORD   dwSize;   //�ṹ���С
        BYTE       byVisiblePicHorizontalScale;//��׼�ü��ɼ���ͼ��ˮƽ����ϵ������λ��һ��128��[12,128]
        BYTE       byVisiblePicVerticalScale;//��׼�ü��ɼ���ͼ��ֱ����ϵ������λ��һ��128��[12,128]
        BYTE       byRes1[2];
        WORD       wHorizontalCalibrationOffset;//ˮƽ�궨ƫ�����ֵΪ�궨ʱ�����ã���λ��һ��1000��[0,1000]
        WORD       wVerticalCalibrationOffset;//��ֱ�궨ƫ�����ֵΪ�궨ʱ�����ã���λ��һ��1000��[0,1000]
        DWORD       dwVisibleFocusDistance;//�ɼ��⾵ͷ���࣬��λ����
        DWORD       dwVisiblePixelInterval;//�ɼ���̽������Ԫ�ߴ磬��λ΢��
        DWORD       dwHorizontalCenterDistance;//�ɼ�����ȳ������ĵ�ˮƽ���룬��λ����
        DWORD       dwVerticalCenterDistance;//�ɼ�����ȳ������ĵ㴹ֱ���룬��λ����
        DWORD       dwCalibrationDistance;//�궨����[0.3,2]m,Э�鴫��ʱͳһʹ��cmΪ��λ
        DWORD       dwVisiblePicLen;//�ɼ���ͼƬ����
        BYTE       *pVisiblePic;//�ɼ���ͼƬ����
        BYTE       byRes[92];
    }USB_DOUBLE_LIGHTS_CORRECT, *LPUSB_DOUBLE_LIGHTS_CORRECT;

    //˫��У׼��Ӧ
    typedef struct tagUSB_DOUBLE_LIGHTS_CORRECT_RESULT
    {
        DWORD   dwSize;   //�ṹ���С
        DWORD      dwJpegPicLen;//�ںϵ���ͼƬ����
        BYTE       *pJpegPic;//�ںϵ���ͼƬ
        BYTE       byRes[120];
    }USB_DOUBLE_LIGHTS_CORRECT_RESULT, *LPUSB_DOUBLE_LIGHTS_CORRECT_RESULT;

#define MAX_REGION_POINT_NUM   10 //���֧��10�����򶥵�
#define MAX_EXPERT_REGIONS    21 //���֧��21������

    //���򶥵�����
    typedef struct tagREGION_VERTEX_COORDINATES
    {
        DWORD   dwPointX; //X����, ��һ��0-1000    ����1����һ����0-1000�Ĺ�һ��������, ����2����������ʵ����   ������ʲô�������ֶ�regionCoordinateMode����   Ĭ�Ϲ�һ������
        DWORD   dwPointY; //Y����, ��һ��0-1000    ����1����һ����0-1000�Ĺ�һ��������, ����2����������ʵ����   ������ʲô�������ֶ�regionCoordinateMode����   Ĭ�Ϲ�һ������
        BYTE   byRes[24];
    }REGION_VERTEX_COORDINATES, *LPREGION_VERTEX_COORDINATES;

    //ר�Ҳ��¹�������
    typedef struct tagTHERMAL_EXPERT_REGIONS
    {
        BYTE   byRegionID;  //����ID����1��ʼ����
        BYTE   byEnabled;  //����ʹ�� 0-�ر� 1-����
        BYTE   byRes1[2];
        BYTE   byName[32]; //��������
        DWORD   dwEmissivity; //������: 0.01~1(��ȷ��С�������λ), ����ʱʵ��ֵ * 100���������  ת����ʽ2������ʱ ʵ��ֵ*2n��С�����ֽضϣ�n�Ĵ�С����shiftLength�ֶ�,���ֶξ�����δ��䣬���ֶ�floatTransMode����������û��floatTransMode�ֶΣ�Ĭ�����ʹ���
        DWORD   dwDistance;  //����: 0.3-3m��Э�鴫����Լ����cm��Ϊ��λ�������䣩  ת����ʽ2������ʱ ʵ��ֵ*2n��С�����ֽضϣ�n�Ĵ�С����shiftLength�ֶ�, ���ֶξ�����δ��䣬���ֶ�floatTransMode����������û��floatTransMode�ֶΣ�Ĭ�����ʹ���
        BYTE   byReflectiveEnable; //�����¶�ʹ�ܣ�0-�ر� 1-����
        BYTE   byHighestTempEnable; //�������ʾʹ��: 1-�ر�  2-����
        BYTE   byLowestTempEnable; //�������ʾʹ��: 1-�ر�  2-����
        BYTE   byAverageTempEnable; //ƽ������ʾʹ��: 1-�ر�  2-����
        DWORD   dwReflectiveTemperature; //�����¶�: -73.3~1000.0�棨��ȷ��С�����1λ, ����ʱ(ʵ��ֵ + 100) * 10�����������   ת����ʽ2������ʱ ʵ��ֵ*2n��С�����ֽضϣ�n�Ĵ�С����shiftLength�ֶ�,���ֶξ�����δ��䣬���ֶ�floatTransMode����������û��floatTransMode�ֶΣ�Ĭ�����ʹ���
        BYTE   byType; //����궨����: 1-�� 2-�� 3-��
        BYTE   byShowAlarmColorEnabled; //������ɫ��ʾʹ��: 1-���� 0-�ر�
        BYTE   byRule; //�����¶ȱȽϷ�ʽ: 
        //��typeΪ1-��ʱ��1-ƽ���¶ȴ��� 2-ƽ���¶�С��; 
        //��typeΪ2-��ʱ��1-���´��� 2-����С�� 3-���´��� 4-����С�� 5-ƽ���¶ȴ��� 6-ƽ���¶�С��;
        //��typeΪ3-��ʱ��1-���´��� 2-����С�� 3-���´��� 4-����С�� 5-ƽ���¶ȴ��� 6-ƽ���¶�С�� 7-�²���� 8-�²�С��
        BYTE   byRes3;
        DWORD   dwAlert; //Ԥ���¶ȣ�-20��~400��, ����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD   dwAlarm; //�����¶ȣ�-20��~400��, ����ʱ(ʵ��ֵ + 100) * 10�����������
        BYTE   byPointNum; //���򶥵��ܸ�������typeΪ1-��ʱ����Ϊ1;   ��typeΪ2-��ʱ����Ϊ2 ;   ��typeΪ3-��ʱ����Ϊ3-10
        BYTE   byRes4[3];
        REGION_VERTEX_COORDINATES   struRegionCoordinate[MAX_REGION_POINT_NUM];
        BYTE   byRes[200];
    }THERMAL_EXPERT_REGIONS, *LPTHERMAL_EXPERT_REGIONS;

    //ר�Ҳ��¹�������
    typedef struct tagUSB_THERMOMETRY_EXPERT_REGIONS
    {
        DWORD   dwSize;   //�ṹ���С
        BYTE   byRegionNum; //���������ܸ���
        BYTE   byRegionCoordinateMode; //����������Чģʽ 1 - ��һ������ 2 - ������ʵ������.  ���ֶ������ж��������궥����Ч���ֶ��ǹ�һ�����껹��������ʵ������
        BYTE   byFloatTransMode; //���������䷽ʽ 1 - ���ʹ��� 2 - ��λ����. ���ʹ��� : �Ƚ�������ת��Ϊ�������ٳ���10�ı�����ת������������Ȼ����; ��λ���� : ֱ�ӽ�����������2n���ض�С����Ȼ����
        BYTE   byShiftLength; //��������λ�������2��N�η�������N�Ĵ�С 1-6; 2-9; 3-13; 4-16; 5-19
        THERMAL_EXPERT_REGIONS  struExpertRegions[MAX_EXPERT_REGIONS];
        BYTE   byRes[220];
    }USB_THERMOMETRY_EXPERT_REGIONS, *LPUSB_THERMOMETRY_EXPERT_REGIONS;

#define MAX_TEMPERATURE_NUM  4

    //ר�Ҳ����¶ȵ���Ϣ
    typedef struct tagTHERMAL_EXPERT_TEMPERATURE
    {
        BYTE   byID; //��ţ���1��ʼ����
        BYTE   byRes1[3];
        DWORD   dwPresetTemperature; //Ԥ���¶�: -40.0-650.0��, ����ʱ(ʵ��ֵ+100) * 10���������
        DWORD   dwPointX; //X����, ��һ��0-1000, ���Ͻ�Ϊԭ�㣨����DSP���ƣ�ʵ�ʹ�һ����ΧΪ13-993��
        DWORD   dwPointY; //Y����, ��һ��0-1000, ���Ͻ�Ϊԭ�㣨����DSP���ƣ�ʵ�ʹ�һ����ΧΪ17-991��
        BYTE   byRes[24];
    }THERMAL_EXPERT_TEMPERATURE, *LPTHERMAL_EXPERT_TEMPERATURE;

    //ר�Ҳ���У����������
    typedef struct tagUSB_THERMOMETRY_EXPERT_CORRECTION_PARAM
    {
        DWORD   dwSize;   //�ṹ���С
        DWORD   dwDistance; //����: 0.3-3m, Э�鴫��ʱ������Ϊ��λ
        DWORD   dwEnviroTemperature; //�����¶�: -273.0-1000.0, ����ʱ��ʵ��ֵ + 300�� * 10���������
        DWORD   dwEmissivity; //������: 0.01-1.00, ����ʱʵ��ֵ * 100���������
        BYTE   byPointNum; //�¶ȵ����: 4��
        BYTE   byRes2[3];
        THERMAL_EXPERT_TEMPERATURE  struExpertTemperature[MAX_TEMPERATURE_NUM];
        BYTE   byRes[64];
    }USB_THERMOMETRY_EXPERT_CORRECTION_PARAM, *LPUSB_THERMOMETRY_EXPERT_CORRECTION_PARAM;

    //��������
    typedef struct tagUSB_THERMOMETRY_RISE_SETTINGS
    {
        DWORD  dwSize;  //�ṹ���С
        BYTE  byEnabled; //������������ 0-�ر�  1-����
        BYTE  byType; //����������ȡ��ʽ 0-�Զ���ȡ 1-�ֶ�����
        BYTE  byResult; //������������״̬��ֻ��������������ȡ��ʽΪ�Զ���ȡģʽ��Ч��: 0-�ɹ�(���в���ֵ��Ч)  1-�ȴ�(���в���ֵ��Ч)  2-ʧ��(���в���ֵ��Ч)
        BYTE  byRes1;
        DWORD  dwEnvTemperature; //�����¶�: -99.0~99.0�� (��ȷ��С�������λ), ����ʱ(ʵ��ֵ+100)*10�����������
        int  dwCoefficient;  //����ϵ��: -10~10
        DWORD  dwMaxTemperatureRise;  //�������: 2~20
        DWORD  dwColdStartRate; //�俪����������: 0.01~0.5 (��ȷ��С�������λ), ����ʱʵ��ֵ*100���������
        DWORD  dwColdStartRise; //�俪������: -3.0~3.0 (��ȷ��С�����1λ), ����ʱ(ʵ��ֵ+100)*10�����������
        BYTE  byRes[128];
    }USB_THERMOMETRY_RISE_SETTINGS, *LPUSB_THERMOMETRY_RISE_SETTINGS;

    //�����¶�У��
    typedef struct tagUSB_ENVIROTEMPERATURE_CORRECT
    {
        DWORD dwSize;  //�ṹ���С
        BYTE  byEnabled;  //��ʹ��, ���ڿ���У׼�����Ƿ���Ч  0-�ر�  1-����
        BYTE  byCorrectEnabled;  //�����¶�У׼ʹ��, ��������У׼����  0-�ر�  1-����
        BYTE  byRes1[2];
        DWORD  dwEnviroTemperature;  //�����¶�У׼ֵ, -20.0~50.0��(��ȷ��С�����1λ), ����ʱ(ʵ��ֵ+100)*10�����������
        DWORD  dwCalibrationTemperature;  //(ֻ��)�±�У׼ֵ���, -20.0~50.0��(��ȷ��С�����1λ), ����ʱ(ʵ��ֵ+100)*10�����������
        BYTE  byRes[112];
    }USB_ENVIROTEMPERATURE_CORRECT, *LPUSB_ENVIROTEMPERATURE_CORRECT;

    //��Ƶ�������
    typedef struct tagUSB_VIDEO_CODE
    {
        DWORD	dwSize;
        BYTE  byVideoResolution; //��Ƶ�ֱ��ʣ�1-256*192, 2-384*288, 3-720*576, 4-1024*768, 5-96*96, 6-160*120, 7-640*512, 8-192*144, 9-480*360, 10-640*480
        BYTE  byUnpackedResolution;//��ѹ��֡�ֱ��ʣ�ֻ��������֡��С��5֡ʱ, �豸��ʹ�÷�ѹ��֡�ϴ�����, ���ݴ�ֻ������������Ƶ������Ϣ, �������ѹ��֡�ֱ������������ݱ���ѹ��֡�ֱ������õ�YVCͨ�����˵�
        //1-320*240, 2-640*480, 3-640*512, 4-1024*600, 5-1280*720, 6-640*256
        BYTE  byRes1[2];
        DWORD  dwMaxFrameRate; //��Ƶ֡�ʣ�1-30fps
        BYTE  byRes[244];
    }USB_VIDEO_CODE, *LPUSB_VIDEO_CODE;

    //���л�ģʽ���ο�
    typedef struct tagUSB_PIP_RECT
    {
        DWORD dwPointX; //���л����ο����϶��㣺X���꣬ʵ������λ����Ļ����Ϊԭ��
        DWORD dwPointY; //���л����ο����϶��㣺Y���꣬ʵ������λ����Ļ����Ϊԭ��
        DWORD dwWidth; //���л����ο򣺿���ʵ������λ����Ļ����Ϊԭ��
        DWORD dwHeight; //���л����ο򣺸ߣ�ʵ������λ����Ļ����Ϊԭ��
        BYTE  byRes[16];
    }USB_PIP_RECT, *LPUSB_PIP_RECT;

    //ͼ���ںϲ���
    typedef struct tagUSB_VIDEO_FUSION
    {
        DWORD	dwSize;
        DWORD dwAutoFocusObjectDistance;  //�Զ��۽������������Ϣ, ��Χ:0-100, ��λ:dm
        DWORD dwHistoryFocusObjectDistance;  //��ʷ�Զ��۽������������Ϣ, ��Χ:0-100, ��λ:dm
        DWORD dwCurrentFocusObjectDistance; //��ǰ�Զ��۽������������Ϣ��Ȩ����, ��Χ:0-256
        DWORD dwHorizontalScaleRatio; //ˮƽ��������, ��Χ: 12-19200
        DWORD dwVerticalScaleRatio; //��ֱ��������, ��Χ: 12-19200
        DWORD dwVerticalCroppingOffset; //��ֱ����ƫ����, ��Χ: [-212, 212], ����ʱʵ��ֵ+500
        DWORD dwHorizontalCroppingOffset; //ˮƽ����ƫ����, ��Χ: [-212, 212], ����ʱʵ��ֵ+500
        DWORD dwRotationAngle; //��ת�Ƕ�, ��Χ:[0.0, 360.0], ��λ: ��, ����ʱʵ��ֵ*10
        DWORD dwHighExplosionSuppressionThreshold; //�߱���������, ��Χ:0-255
        DWORD dwHighPassFilterSelectionVariable; //��ͨ�˲�ѡ�����, ��Χ:0,1
        DWORD dwHighPassFilteRadius; //��ͨ�˲��뾶
        DWORD dwHighFrequencyInformationThreshold; //��Ƶ��Ϣ����, ��Χ:0-32767
        DWORD dwSuperpositionGain; //��������, ��Χ:0-127
        DWORD dwLimitingGain; //��������, ��Χ:0-127
        DWORD dwLowFrequencyFusionControlLowerThreshold; //��Ƶ�ںϿ���������, ��Χ:0-255
        DWORD dwLowFrequencyFusionControlUpperThreshold; //��Ƶ�ںϿ���������, ��Χ:0-255
        BYTE byVideoFusionMode; //ͼ���ںϴ���ģʽ: 1-���ȳ���ģʽ, 2-�ɼ���ģʽ, 3-�ں�ģʽ, 4-���л�ģʽ, 5-�궨ģʽ, 6-�ںϲ�ɫģʽ--�ݵ�, 
        //7-�ںϲ�ɫģʽ--��Į, 8-�ںϲ�ɫģʽ--ѩ��, 10-�ںϲ�ɫģʽ--����, 11-���ģʽ--�ɼ���+�ȳ���
        BYTE byRes2[2];
        BYTE byPipEnabled; //���л��ں�ʹ��, 0-�ر� 1-����
        USB_PIP_RECT struPipRect; //���л����ο���Ϣ
        BYTE byMixModeVisibleScale; //���ģʽ�ɼ������, ��Χ0-100 (��videoFusionModeΪ11-���ģʽʱ, �ò�����Ч)
        BYTE byRes[407];
    }USB_VIDEO_FUSION, *LPUSB_VIDEO_FUSION;

    //��ͷ�궨����
    typedef struct tagUSB_VIDEO_LEN_CALIBRATION
    {
        DWORD	dwSize;
        BYTE byVideoResolution; //��������: 1-1X����, 2-0.5X����, 3-2X����, 4-3X����, 5-0.85X΢�ྵͷ, 6-0.34X΢�ྵͷ,
        //7-ר�ų����±���, 8-MAX����, 9-����������, 10-��⵽��������֧��, 11-û�м�⵽����
        BYTE byAdditiveMultiplicationFactor; //�ӳ�����ʹ�ܣ�ֻ����: 0-�ر�  1-����
        BYTE byRes1[2];
        DWORD dwTeleconverterAdditiveFactor1; //������������1
        DWORD dwTeleconverterAdditiveFactor2; //������������2
        DWORD dwTeleconverterAdditiveFactor3; //������������3
        DWORD dwTeleconverterAdditiveFactor4; //������������4
        DWORD dwTeleconverterMultiplicationFactor1; //������������1
        DWORD dwTeleconverterMultiplicationFactor2; //������������2
        DWORD dwTeleconverterMultiplicationFactor3; //������������3
        DWORD dwTeleconverterMultiplicationFactor4; //������������4
        DWORD dwFocus; //�۽�ֵ
        DWORD dwPixelSize; //ԭ���С, 0-1000��m, ��λ: ΢��
        DWORD dwDistance; //���, 0-50000�L, ��λ: ����
        DWORD dwTeleconverterFOV; //�����ӳ���, ��Χ0.0-360.0, ��λ: ��, ����ʱʵ��ֵ*10
        BYTE byRes[200];
    }USB_VIDEO_LEN_CALIBRATION, *LPUSB_VIDEO_LEN_CALIBRATION;

    //ϵͳ����������
    typedef struct tagUSB_SYSTEM_CTRL_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE  byDeviceInfo; //�豸��Ϣ��ȡ��0-��֧��  1-֧��
        BYTE  byReboot; //�豸������0-��֧��  1-֧��
        BYTE  byReset; //�ָ�Ĭ�ϣ�0-��֧��  1-֧��
        BYTE  byHardwareServer; // Ӳ������������ã�0-��֧��  1-֧��
        BYTE  byLocalTime; //Уʱ��0-��֧��  1-֧��
        BYTE  byUpdateFirmware; //�豸������0-��֧��  1-֧��
        BYTE  byDiagnoseData;  //�����Ϣ������0-��֧��  1-֧��
        BYTE  byScreenVirtualMenu;  //��Ļ����˵���0-��֧��  1-֧��
        BYTE  byDeviceMenuArouse;  //�豸�˵����ѣ�0-��֧��  1-֧��
        BYTE  byTouchScreenMessagePoster;  //������Ϣ���ͣ�0-��֧��  1-֧��
        BYTE  byDeviceDescriptionInfo;  //�豸������Ϣ��0-��֧��  1-֧��
        BYTE  byBigDataTransInfo;  //�����ݴ�����Ϣ��0-��֧��  1-֧��
        BYTE  byUVCMenuControl;  //��Ƶ�˵����ƣ�0-��֧��  1-֧��
        BYTE  bySerialDataTransmission;  //��������͸����0-��֧��  1-֧��
        BYTE  byRes[494];
    }USB_SYSTEM_CTRL_CAPABILITIES, *LPUSB_SYSTEM_CTRL_CAPABILITIES;

    //�豸��Ϣ����
    typedef struct tagUSB_SYSTEM_DEVICE_INFO_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byFirmwareVersion; //���س���汾��0-��֧�� 1-֧��
        BYTE byEncoderVersion; //����汾��0-��֧�� 1-֧��
        BYTE byHardwareVersion; //��о�汾��0-��֧�� 1-֧��
        BYTE byDeviceName; //�豸���ƣ�0-��֧�� 1-֧��
        BYTE byProtocolVersion; //Э��汾��Ϣ��0-��֧��  1-֧��
        BYTE bySerialNumber; //�豸���кţ�0-��֧��  1-֧��
        BYTE bySecondhardwareVersion; //������汾��0-��֧��   1-֧��
        BYTE byModuleID; //��оID��0-��֧��  1-֧��
        BYTE byDeviceID; //�豸ID��0-��֧��   1-֧��
        BYTE byDeviceAssembleType; //�豸��װ���ͣ�1-��֧��  2-֧��
        BYTE byManufacturer; //������Ϣ��1-��֧��  2-֧��
        BYTE byLanguageType; //�������ͣ�1-��֧��  2-֧��
        BYTE byDeviceClass; //�豸���ࣺ1-��֧��  2-֧��
        BYTE byRes[495];
    }USB_SYSTEM_DEVICE_INFO_CAPABILITIES, *LPUSB_SYSTEM_DEVICE_INFO_CAPABILITIES;

    //Ӳ����������
    typedef struct tagUSB_SYSTEM_HARDWARE_SERVER_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byUsbMode; //USBģʽ�л�����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0��USB��UVCģʽ
        bit1��USB��NCMģʽ
        */
        BYTE byDeviceinitialstatus; //�豸��ʼ��״̬��0-��֧��  1-֧��
        BYTE byDeviceworkingstatus; //�豸����״̬��0-��֧��   1-֧��
        BYTE byRes[505];
    }USB_SYSTEM_HARDWARE_SERVER_CAPABILITIES, *LPUSB_SYSTEM_HARDWARE_SERVER_CAPABILITIES;

    //ϵͳʱ������
    typedef struct tagUSB_SYSTEM_LOCALTIME_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byMillisecond; //���룺0-��֧��  1-֧��
        BYTE bySecond; //�룺0-��֧��  1-֧��
        BYTE byMinute; //���ӣ�0-��֧��  1-֧��
        BYTE byHour; //Сʱ��0-��֧��   1-֧��
        BYTE byDay; //�գ�0-��֧��  1-֧��
        BYTE byMonth; //�£�0-��֧��  1-֧��
        BYTE  wYear; //�꣺0-��֧��  1-֧��
        BYTE byExternalTimeSourceEnabled; //�ⲿУʱԴʹ�ܣ�0-��֧��  1-֧��
        BYTE byRes[499];
    }USB_SYSTEM_LOCALTIME_CAPABILITIES, *LPUSB_SYSTEM_LOCALTIME_CAPABILITIES;

    //ͼ�����������
    typedef struct tagUSB_IMAGE_CAPABILITIES
    {
        DWORD	dwSize;
        BYTE  byImageBrightness; //ͼ�����ȵ��ڣ�0-��֧��  1-֧��
        BYTE  byImageContrast; //ͼ��Աȶȵ��ڣ�0-��֧��  1-֧��
        BYTE  byImageBackgroundCorrect; //һ������У����0-��֧��  1-֧��
        BYTE  byImageManualCorrect;  //һ���ֶ�У����0-��֧��  1-֧��
        BYTE  byImageEnhancement;  //ͼ����ǿ��0-��֧��  1-֧��
        BYTE  byImageVideoAdjust;  //��Ƶ������0-��֧��  1-֧��
        BYTE byRes[502];
    }USB_IMAGE_CAPABILITIES, *LPUSB_IMAGE_CAPABILITIES;

    //ͼ�����ȵ�������
    typedef struct tagUSB_IMAGE_BRIGHTNESS_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byBrightnessUpperLimit; //ͼ������������ֵ
        BYTE byBrightnessLowerLimit; //ͼ������������ֵ
        BYTE byRes[506];
    }USB_IMAGE_BRIGHTNESS_CAPABILITIES, *LPUSB_IMAGE_BRIGHTNESS_CAPABILITIES;

    //ͼ��Աȶȵ�������
    typedef struct tagUSB_IMAGE_CONTRAST_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byContrastUpperLimit; //ͼ��Աȶ�������ֵ
        BYTE byContrastLowerLimit; //ͼ��Աȶ�������ֵ
        BYTE byRes[506];
    }USB_IMAGE_CONTRAST_CAPABILITIES, *LPUSB_IMAGE_CONTRAST_CAPABILITIES;

    //ͼ����ǿ����
    typedef struct tagUSB_IMAGE_ENHANCEMENT_CAPABILITIES
    {
        DWORD  dwSize;
        DWORD  dwHighLightLevelUpperLimit; //����͹�Եȼ�������ֵ
        DWORD  dwHighLightLevelLowerLimit; //����͹�Եȼ�������ֵ
        DWORD  dwAGCUpperLimit;  //AGC������ֵ
        DWORD  dwAGCLowerLimit;  //AGC������ֵ
        BYTE  byNoiseReduceMode; //���ֽ���ģʽ����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0:�ر�
        bit1:��ͨģʽ
        bit2:ר��ģʽ
        */
        BYTE  byGeneralLevelUpperLimit; //��ͨģʽ���뼶��������ֵ
        BYTE  byGeneralLevelLowerLimit; //��ͨģʽ���뼶��������ֵ
        BYTE  byFrameNoiseReduceLevelUpperLimit; //ר��ģʽ�����뼶��������ֵ
        BYTE  byFrameNoiseReduceLevelLowerLimit; //ר��ģʽ�����뼶��������ֵ
        BYTE  byInterFrameNoiseReduceLevelUpperLimit; //ר��ģʽʱ���뼶��������ֵ
        BYTE  byInterFrameNoiseReduceLevelLowerLimit; //ר��ģʽʱ���뼶��������ֵ
        BYTE  bySharpenBoost; //����ǿ:1 - ��֧�� 2 - ֧��
        DWORD  dwPaletteMode; //α��ɫ��ɫģʽ����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0������
        bit1������
        bit2���ں�1
        bit3���ʺ�
        bit4���ں�2
        bit5������1
        bit6������2
        bit7�����ɫ
        bit8��ɫ��1
        bit9��ɫ��2
        bit10������
        bit11����
        bit12������
        bit13������
        bit14������
        */
        BYTE  byLSEDetailEnabled; //ͼ��ϸ����ǿʹ�ܣ�0-��֧��  1-֧��
        BYTE  byLSEDetailLevelUpperLimit; //ͼ��ϸ����ǿ�ȼ�������ֵ
        BYTE  byLSEDetailLevelLowerLimit; //ͼ��ϸ����ǿ�ȼ�������ֵ
        BYTE  byWideTemperatureRange; //�¿�ģʽʹ�ܣ�0-��֧��  1-֧��
        DWORD  dwWideTemperatureRangeUpThr; //�¿�ģʽ����ֵ��-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwWideTemperatureRangeDownThr; //�¿�ģʽ����ֵ��-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        BYTE  byBirdWatchingMode; //����ģʽʹ�ܣ�0-��֧��  1-֧��
        BYTE  byHighLightMode; //����͹��ģʽʹ�ܣ�0-��֧��  1-֧��
        BYTE  byHookEdgeMode; //����ģʽʹ�ܣ�0-��֧��  1-֧��
        BYTE  byHookEdgeStrUpperLimit; //���ߵȼ�������ֵ
        BYTE  byHookEdgeStrLowerLimit; //���ߵȼ�������ֵ
        BYTE  byWideTemperatureRangemode; //�¿�����ģʽ����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0���¿�ģʽ�����޾�����
        bit1���¿�ģʽֻ��������
        bit2���¿�ģʽֻ��������
        */
        BYTE  byIspAgcmode; //agc����ģʽ����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0������ģʽ
        bit1��ֱ��ͼģʽ
        */
        BYTE  byAISuperResolution; //AI����ʹ�ܣ�0-��֧��  1-֧��
        BYTE  bySkyAreaCullLevel; //��������޳��ٷֱȣ�0-��֧��  1-֧��
        BYTE  byBurnPreventionEnabled; //������ģʽʹ�ܣ�0-��֧��  1-֧��
        BYTE  byBurnPreventionMode; //�����տ���ģʽ����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0���Զ�����ģʽ
        bit1���ֶ�����ģʽ
        */
        BYTE  byAutoShutEnabled; //�Զ���Ƭʹ�� 1 - ��֧�� 2 - ֧��
        DWORD  dwBurnPreventionShutterCloseTimeUpperLimit; //�����յ�Ƭ�պ�ʱ��(���Զ�ģʽ����Ч) ������ֵ0 - 3600��
        BYTE  byBurnPreventionShutterControl; //�����յ�Ƭ�ֶ�����((���ֶ�ģʽ����Ч)) ����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0��������
        bit1����Ƭ�պ�
        bit2����Ƭ̧��
        */
        BYTE  byBurnPreventionRecovery; //�������Իָ�ʹ�ܣ�0-��֧��  1-֧��
        BYTE  byIsothermEnabled; //�����߿�����0-��֧��  1-֧��
        BYTE  byRes3;
        DWORD  dwIsothermalUpperThreshold; //�������¶�����ֵ-20��~600�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwIsothermalLowerThreshold; //�������¶�����ֵ-20��~600�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwIsothermalType; //��������ʾ���ͣ���λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0�����ȵ���
        bit1�����ȵ���
        bit2�����ҵ���
        bit3���������
        bit4����������
        bit5��ҽ�Ƶ���
        bit6����������
        bit7���ʺ�1����
        bit8���ʺ�2����
        bit9��������
        */
        BYTE  byRes[436];
    }USB_IMAGE_ENHANCEMENT_CAPABILITIES, *LPUSB_IMAGE_ENHANCEMENT_CAPABILITIES;

    //��Ƶ��������
    typedef struct tagUSB_IMAGE_VIDEO_ADJUST_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE  byImageFlipStyle; //����ģʽ����λ��ʾö����֧�������0-��֧�֣�1-֧��
        BYTE  byPowerLineFrequencyMode; //��Ƶ��ʽ����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�bit0��PAL(��֧��)
        BYTE  byCorridor; //��ͷ����ģʽ����ת����0-��֧��  1-֧��
        BYTE  byDigitalZoom; //���ֱ䱶����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0��X1
        bit1��X2
        bit2��X4
        bit3��X8
        */
        BYTE  byCursor; //��ʾ�����0-��֧��  1-֧��
        BYTE  byBadPointCursor; //��ʾ����ʮ�ֹ�꣺0-��֧��  1-֧��
        BYTE  byBadPointCursorShiftMode; //�ƶ�����ʮ�ֹ�귽ʽ����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0��ֱ���·�����
        bit1���·��ƶ�ָ��
        */
        BYTE  byBadPointCursorShiftStep; //�ƶ�����ʮ�ֵ�����󲽳�
        BYTE  byRes[500];
    }USB_IMAGE_VIDEO_ADJUST_CAPABILITIES, *LPUSB_IMAGE_VIDEO_ADJUST_CAPABILITIES;

    //�ȳ���������
    typedef struct tagUSB_THERMAL_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE  byIsSupportThermometryBasicParam; //�Ƿ�֧�ֲ��»����������ã�0-��֧��  1-֧��
        BYTE  byThermometryType; //�������ͣ�1-�������  2-��ҵ����
        BYTE  byThermalThermometryRegions; //���¹������ã�0-��֧��  1-֧��
        BYTE  byThermalAlgVersion; //�ȳ�������㷨�汾��0-��֧��  1-֧��
        BYTE  byThermalStreamParam; //�ȳ��������������ã�0-��֧��  1-֧��
        BYTE  byThermalTempeatureCorrect; //����������������£���0-��֧��  1-֧��
        BYTE  byThermalBlackBody; //����������ã�0-��֧��  1-֧��
        BYTE  byThermalBodyTempCompensation; //���²����������ã�0-��֧��  1-֧��
        BYTE  byThermalJpecpic; //ץ��ͼ��0-��֧��  1-֧��
        BYTE  byThermalROIMaxTemperatrueSearch; //ROI�������Ϣ��ѯ��0-��֧��  1-֧��
        BYTE  byThermalP2PParam; //ȫ�����²������ã�0-��֧��  1-֧��
        BYTE  byThermometryCalibrationFile; //���±궨�ļ����뵼����0-��֧��  1-֧��
        BYTE  byThermometryExpertRegions; //ר�Ҳ��¹������ã�0-��֧��  1-֧��
        BYTE  byThermometryExpertCorrection; //ר�Ҳ���У���������ã�0-��֧��  1-֧��
        BYTE  byRes[494];
    }USB_THERMAL_CAPABILITIES, *LPUSB_THERMAL_CAPABILITIES;

#define MAX_TEMP_RANGE_NUM  10

    //���µ�λ��Ϣ
    typedef struct tagUSB_TEMPERATURE_RANGE_INFO
    {
        BYTE byTemperatureRangeID; //���µ�λ
        BYTE byRes[3];
        DWORD  dwTemperatureRangeUpperLimit; //���µ�λ�¶����ޣ���λ��
        DWORD  dwTemperatureRangeLowerLimit;  //���µ�λ�¶����ޣ���λ��
    }USB_TEMPERATURE_RANGE_INFO, *LPUSB_TEMPERATURE_RANGE_INFO;

    //���»�����������
    typedef struct tagUSB_THERMOMETRY_BASIC_PARAM_CAPABILITIES
    {
        DWORD  dwSize;
        DWORD  dwTemperatureRange; //���µ�λ����λ��ʾ��λ֧�������0-��֧�� 1-֧��
        /*
        bit0�� -20~150��
        bit1��0~550��
        bit2��0~650��
        bit3�� -4~302��
        bit4��32~1022��
        bit5��32~1200��
        bit6�� -20~650��
        bit7�� -20~1500��
        bit8��automatic��
        bit9�� -20~120��
        bit10��100~550��
        bit11��28~45��
        bit12��20~350��
        bit13��20~45��
        bit14��0~400��
        bit15��30~45��
        bit16��100~400��
        bit17��100~350��
        bit18�� -40~150��
        bit19��100~650��
        bit20��300~2200��
        bit22�� -20~200��
        bit23��0~800��
        bit24��600~1800��
        bit25��300~2000��
        bit26��300~1500��
        bit27��0~1200��
        */
        DWORD  dwEnviroTemperatureUpperLimit; //�����¶�������ֵ: -99.00~99.00��(��ȷ��С�������λ)������ʱ(ʵ��ֵ+100)*100�����������
        DWORD  dwEnviroTemperatureLowerLimit; //�����¶�������ֵ: -99.00~99.00��(��ȷ��С�������λ)������ʱ(ʵ��ֵ+100)*100�����������
        DWORD  dwReflectiveTemperatureUpperLimit; //�����¶�������ֵ: -100.0~1000.0��(��ȷ��С�����1λ)������ʱ(ʵ��ֵ+100)*10�����������
        DWORD  dwReflectiveTemperatureLowerLimit; //�����¶�������ֵ: -100.0~1000.0��(��ȷ��С�����1λ)������ʱ(ʵ��ֵ+100)*10�����������
        DWORD  dwAtmosphericHumidityUpperLimit; //����ʪ��ֵ������ֵ: 0.0~100.0�棬����ʱʵ��ֵ*10�����������
        DWORD  dwAtmosphericHumidityLowerLimit; //����ʪ��ֵ������ֵ: 0.0~100.0�棬����ʱʵ��ֵ*10�����������
        DWORD  dwEmissivityUpperLimit; //������������ֵ: 0.01~1(��ȷ��С�������λ)������ʱʵ��ֵ*100���������
        DWORD  dwEmissivityLowerLimit; //������������ֵ: 0.01~1(��ȷ��С�������λ)������ʱʵ��ֵ*100���������
        DWORD  dwDistanceUpperLimit; //����������ֵ��Э�鴫����Լ����cm��Ϊ��λ����
        DWORD  dwDistanceLowerLimit; //����������ֵ��Э�鴫����Լ����cm��Ϊ��λ����
        BYTE  byThermometryEnabled; //�������¹��ܣ�0-��֧��  1-֧��
        BYTE  byDisplayMaxTemperatureEnabled; //��ʾ����£�0-��֧��  1-֧��
        BYTE  byDisplayMinTemperatureEnabled; //��ʾ����£�0-��֧��  1-֧��
        BYTE  byDisplayAverageTemperatureEnabled; //��ʾƽ���£�0-��֧��  1-֧��
        BYTE  byTemperatureUnit; //�¶ȵ�λ����λ��ʾö����֧�������0-��֧�֣�1-֧�֡���Э�鴫����Լ���������¶���Ϊ��λ���䣩
        /*
        bit0�������¶�
        bit1�������¶�
        bit2���������¶�
        */
        BYTE  byCalibrationCoefficientEnabled; //���ñ궨ϵ����0-��֧��  1-֧��
        BYTE  byModifyTemperatureRange; //�Ƿ�֧���޸Ĳ��µ�λ��1-��֧�� 2-֧��
        BYTE  byRes1;
        DWORD  dwCalibrationCoefficientUpperLimit; //�궨ϵ��������ֵ��0.00~30.00������ʱʵ��ֵ * 100���������
        DWORD  dwCalibrationCoefficientLowerLimit; //�궨ϵ��������ֵ��0.00~30.00������ʱʵ��ֵ * 100���������
        DWORD  dwExternalOpticsWindowCorrectionUpperLimit; //�ⲿ��ѧ�¶�������ֵ��-40.0~80.0�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwExternalOpticsWindowCorrectionLowerLimit; //�ⲿ��ѧ�¶�������ֵ��-40.0~80.0�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        BYTE  byDistanceUnit; //���뵥λ����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0����
        bit1������
        bit2��Ӣ��
        */
        BYTE  byReflectiveEnable; //�����¶�ʹ�ܣ�0-��֧��  1-֧��
        BYTE  byThermometryInfoDisplayposition; //������Ϣ��ʾλ�ã���λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0���������
        bit1����Ļ���Ͻ�
        */
        BYTE  byThermometryStreamOverlay; //���������¶���Ϣ��0-��֧��  1-֧��
        DWORD  dwAlertUpperLimit; //Ԥ���¶�������ֵ��-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwAlertLowerLimit; //Ԥ���¶�������ֵ��-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwAlarmUpperLimit; //�����¶�������ֵ��-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwAlarmLowerLimit; //�����¶�������ֵ��-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwExternalOpticsTransmit; //�ⲿ��ѧ͸���ʣ�0-��֧��  1-֧��
        BYTE  byDisplayCenTempEnabled; //��ʾ�����£�0-��֧��  1-֧��
        BYTE  byBackcolorEnabled; //��ʾ����ɫ��0-��֧��  1-֧��
        BYTE  byShowAlarmColorEnabled; //������ɫ��ʾʹ�ܣ�0-��֧��  1-֧��
        BYTE  byTemperatureRangeAmount;  //���µ�λ��������ӦstruTempTangeInfo�������ݸ���
        USB_TEMPERATURE_RANGE_INFO  struTempRangeInfo[MAX_TEMP_RANGE_NUM]; //���µ�λ��Ϣ�б�
        BYTE byFloatTransMode; //����������ģʽ����λ��ʾö����֧�����0-��֧�֣�1-֧��   bit0 - ���ʹ���  bit1 - ��λ����
        BYTE byShiftLength; //��������λ�������2��N�η�������N�Ĵ�С����ο��ʾö��֧�������0-��֧�֣�1-֧��  bit0��6  bit1��9 bit2��13 bit3��16 bit4��19
        BYTE byEnviromentTemperatureEnable; //�����¶�ʹ��1 - ��֧�� 2 - ֧��
        BYTE  byRes[289];
    }USB_THERMOMETRY_BASIC_PARAM_CAPABILITIES, *LPUSB_THERMOMETRY_BASIC_PARAM_CAPABILITIES;

    //����ģʽ��������
    typedef struct tagUSB_THERMAL_THERMOMETRY_MODE_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE  byThermometryMode; //����ģʽ����λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0����ͨ
        bit1��ר��
        */
        BYTE  byThermometryROIEnabled;//����ROIʹ�ܣ�0-��֧�֣�1-֧��
        BYTE  byRes[506];
    }USB_THERMAL_THERMOMETRY_MODE_CAPABILITIES, *LPUSB_THERMAL_THERMOMETRY_MODE_CAPABILITIES;

    //���¹�����������
    typedef struct tagUSB_THERMAL_THERMOMETRY_REGIONS_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE byRegionNumUpperLimit;//���������ܸ���������ֵ
        BYTE byRegionEnabled;//����ʹ�ܣ�0-��֧��  1-֧��
        BYTE byRes[506];
    }USB_THERMAL_THERMOMETRY_REGIONS_CAPABILITIES, *LPUSB_THERMAL_THERMOMETRY_REGIONS_CAPABILITIES;

    //�ȳ�������������������
    typedef struct tagUSB_THERMAL_STREAM_PARAM_CAPABILITIES
    {
        DWORD  dwSize;
        DWORD  dwVideoCodingType; //�������ݱ�������ͣ���λ��ʾö����֧�������0-��֧�֣�1-֧�֡�
        /*
        bit0���ȳ���������
        bit1��ȫ����������
        bit2��ʵʱ������
        bit3����ͼ���ݣ����ݸ�ʽ����¼��
        bit4���ȳ���ʵʱ��
        bit5�� YUVʵʱ���ݣ����ݸ�ʽ����¼��
        bit6��PS��װMJPEGʵʱ��
        bit7��ȫ���������� + YUVʵʱ��
        bit8��YUV + ������
        bit9����YUV��������ͷ
        bit10������ͷ + ���߲�����Ϣ + ������ + YUV
        */
        BYTE byRes[504];
    }USB_THERMAL_STREAM_PARAM_CAPABILITIES, *LPUSB_THERMAL_STREAM_PARAM_CAPABILITIES;

    //����������������£�����
    typedef struct tagUSB_THERMAL_TEMPERATURE_CORRECT_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE byEnabled; //ʹ�ܣ�0-��֧��  1-֧��
        BYTE byStreamOverlay; //�����¶���������ʹ�ܣ�0-��֧��  1-֧��
        BYTE byCorrectEnabled; //��������ʹ�ܣ�0-��֧��  1-֧��
        BYTE byRes1;
        DWORD  dwEmissivityUpperLimit; //������������ֵ��0.01~1.00������ʱʵ��ֵ*100���������
        DWORD  dwEmissivityLowerLimit; //������������ֵ��0.01~1.00������ʱʵ��ֵ*100���������
        DWORD  dwDistanceUpperLimit; //����������ֵ��0.3~2m������ʱ������(cm)Ϊ��λ
        DWORD  dwDistanceLowerLimit; //����������ֵ��0.3~2m������ʱ������(cm)Ϊ��λ
        DWORD  dwTemperatureUpperLimit;  //�¶�������ֵ��30.0~50.0�棬����ʱʵ��ֵ*10���������
        DWORD  dwTemperatureLowerLimit;  //�¶�������ֵ��30.0~50.0�棬����ʱʵ��ֵ*10���������
        BYTE  byRes[480];
    }USB_THERMAL_TEMPERATURE_CORRECT_CAPABILITIES, *LPUSB_THERMAL_TEMPERATURE_CORRECT_CAPABILITIES;

    //���������������
    typedef struct tagUSB_THERMAL_BLACK_BODY_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byEnabled;//ʹ�ܣ�0-��֧��  1-֧��
        BYTE byRes1[3];
        DWORD dwEmissivityUpperLimit; //���巢����������ֵ��0.01~1.00������ʱʵ��ֵ * 100���������
        DWORD dwEmissivityLowerLimit; //���巢����������ֵ��0.01~1.00������ʱʵ��ֵ * 100���������
        DWORD dwDistanceUpperLimit; //����������ֵ��0.3~2m��Э�鴫��ʱ������(cm)Ϊ��λ
        DWORD dwDistanceLowerLimit; //����������ֵ��0.3~2m��Э�鴫��ʱ������(cm)Ϊ��λ
        DWORD dwTemperatureUpperLimit; //�����¶�������ֵ��30.0~50.0�棬����ʱʵ��ֵ*10���������
        DWORD dwTemperatureLowerLimit; //�����¶�������ֵ��30.0~50.0�棬����ʱʵ��ֵ*10���������
        BYTE byRes[480];
    }USB_THERMAL_BLACK_BODY_CAPABILITIES, *LPUSB_THERMAL_BLACK_BODY_CAPABILITIES;

    //���²���������������
    typedef struct tagUSB_THERMAL_BODYTEMP_COMPENSATION_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byEnabled;//ʹ�ܣ�0-��֧��  1-֧��
        BYTE byType;//������ʽ����λ��ʾö����֧�������0-��֧��  1-֧��
        /*
        bit0���ֶ�����
        bit1���Զ�����
        */
        BYTE byRes1[2];
        DWORD dwCompensationValueUpperLimit;//�����¶�������ֵ��-10.0~10.0�棬����ʱʵ��ֵ * 10���������
        DWORD dwCompensationValueLowerLimit;//�����¶�������ֵ��-10.0~10.0�棬����ʱʵ��ֵ * 10���������
        DWORD dwSmartCorrectionUpperLimit;//�ֶ�У׼������ֵ��-99.0~99.0�棬����ʱ(ʵ��ֵ+100)*10�����������
        DWORD dwSmartCorrectionLowerLimit;//�ֶ�У׼������ֵ��-99.0~99.0�棬����ʱ(ʵ��ֵ+100)*10�����������
        DWORD dwEnvironmentalTemperatureUpperLimit;//�����¶�������ֵ��-99.0~99.0�棬����ʱ(ʵ��ֵ+100)*10�����������
        DWORD dwEnvironmentalTemperatureLowerLimit; //�����¶�������ֵ��-99.0~99.0�棬����ʱ(ʵ��ֵ+100)*10�����������
        BYTE byEnvironmentalTemperatureMode; //�����¶�ģʽ����λ��ʾö����֧�������0-��֧�֣�1-֧��
        /*
        bit0���Զ�ģʽ
        bit1���ֶ�ģʽ
        */
        BYTE byRes[479];
    }USB_THERMAL_BODYTEMP_COMPENSATION_CAPABILITIES, *LPUSB_THERMAL_BODYTEMP_COMPENSATION_CAPABILITIES;

    //ROI�������Ϣ��ѯ����
    typedef struct tagUSB_THERMAL_ROI_MAX_TEMPERATURE_SEARCH_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byROITimeSynchronizationConfig;//ROIУʱ����������0-��֧��  1-֧��
        BYTE byJpegPicEnabled;//�豸�Ƿ񷵻�JPEGͼƬ��0-��֧��  1-֧��
        BYTE byMaxTemperatureOverlay;//�Ƿ��������£�0-��֧��  1-֧��
        BYTE byRegionOverlay;//�Ƿ���ӹ����0-��֧��  1-֧��
        BYTE byROIRegionNumUpperLimit;//ROI�����ܸ���������ֵ
        BYTE byROIRegionEnabled;//ROI����ʹ�ܣ�0-��֧��  1-֧��
        BYTE byRes1[2];
        DWORD dwDistanceUpperLimit;//����������ֵ��0.3-2m����ȷ��С�����1λ��Э�鴫����Լ����cm��Ϊ��λ����
        DWORD dwDistanceLowerLimit;//����������ֵ��0.3-2m����ȷ��С�����1λ��Э�鴫����Լ����cm��Ϊ��λ����
        BYTE byRes[492];
    }USB_THERMAL_ROI_MAX_TEMPERATURE_SEARCH_CAPABILITIES, *LPUSB_THERMAL_ROI_MAX_TEMPERATURE_SEARCH_CAPABILITIES;

    //���±궨�ļ����뵼������
    typedef struct tagUSB_THERMAL_THERMOMETRY_CALIBRATION_FILE_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byThermometryCalibrationFileImport;//���±궨�ļ����룺0-��֧��  1-֧��
        BYTE byThermometryCalibrationFileExport;//���±궨�ļ�������0-��֧��  1-֧��
        BYTE byRes[506];
    }USB_THERMAL_THERMOMETRY_CALIBRATION_FILE_CAPABILITIES, *LPUSB_THERMAL_THERMOMETRY_CALIBRATION_FILE_CAPABILITIES;

    //ר�Ҳ��¹�����������
    typedef struct tagUSB_THERMAL_THERMOMETRY_EXPERT_REGIONS_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byRegionNumUpperLimit;//���������ܸ���������ֵ
        BYTE byRuleRegionNumUpperLimit;//������������������ֵ
        BYTE byRuleRegionEnabled;//����ʹ�ܣ�0-��֧��  1-֧��
        BYTE byRuleRegionname;//�������ƣ�0-��֧��  1-֧��
        BYTE byRuleRegionPointNumUpperLimit;//��������򶥵��ܸ���������ֵ
        BYTE byRuleRegionPointNumLowerLimit;//��������򶥵��ܸ���������ֵ
        BYTE byRulePointNumUpperLimit;//������������ֵ
        BYTE byRuleLineNumUpperLimit;//�߹����������ֵ
        DWORD  dwEmissivityUpperLimit;//������������ֵ��0.01~1.00(��ȷ��С�������λ)������ʱʵ��ֵ * 100���������
        DWORD  dwEmissivityLowerLimit;//������������ֵ��0.01~1.00(��ȷ��С�������λ)������ʱʵ��ֵ * 100���������
        DWORD  dwDistanceUpperLimit;//����������ֵ��0.3-3m��Э�鴫����Լ����cm��Ϊ��λ��������
        DWORD  dwDistanceLowerLimit;//����������ֵ��0.3-3m��Э�鴫����Լ����cm��Ϊ��λ��������
        BYTE byReflectiveEnable;//�����¶�ʹ�ܣ�0-��֧��  1-֧��
        BYTE byRegionCoordinateMode;//����������Чģʽ����λ��ʾö����֧�������0-��֧�֣�1-֧��  bit0 - ��һ������ bit1 - ������ʵ������
        BYTE byFloatTransMode;//����������ģʽ����λ��ʾö����֧�������0-��֧�֣�1-֧��  bit0 - ���ʹ��� bit1 - ��λ����
        BYTE byShiftLength;//��������λ�������2��N�η�������N�Ĵ�С����ο��ʾö��֧�������0-��֧�֣�1-֧�� bit0��6 bit1��9 bit2��13 bit3��16 bit4��19
        DWORD  dwReflectiveTemperatureUpperLimit;//�����¶�������ֵ��-100.0~1000.0�棨��ȷ��С�����1λ��������ʱ(ʵ��ֵ+100)*10�����������
        DWORD  dwReflectiveTemperatureLowerLimit;//�����¶�������ֵ��-100.0~1000.0�棨��ȷ��С�����1λ��������ʱ(ʵ��ֵ+100)*10�����������
        BYTE byShowAlarmColorEnabled;//������ɫ��ʾʹ�ܣ�0-��֧��  1-֧��
        BYTE byRes2[3];
        DWORD  dwAlertUpperLimit;//Ԥ���¶�������ֵ��-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwAlertLowerLimit;//Ԥ���¶�������ֵ��-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwAlarmUpperLimit;//�����¶�������ֵ��-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwAlarmLowerLimit;//�����¶�������ֵ��-20��~400�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        BYTE  byRes[452];
    }USB_THERMAL_THERMOMETRY_EXPERT_REGIONS_CAPABILITIES, *LPUSB_THERMAL_THERMOMETRY_EXPERT_REGIONS_CAPABILITIES;

    //ר�Ҳ���У��������������
    typedef struct tagUSB_THERMAL_THERMOMETRY_EXPERT_CORRECTION_PARAM_CAPABILITIES
    {
        DWORD dwSize;
        DWORD dwDistanceUpperLimit; //����������ֵ��0.3~3m��Э�鴫����Լ����cm��Ϊ��λ��������
        DWORD dwDistanceLowerLimit; //����������ֵ��0.3~3m��Э�鴫����Լ����cm��Ϊ��λ��������
        DWORD dwEnviroTemperatureUpperLimit; //�����¶�������ֵ��-273.0 - 1000.0(��ȷ��С�����1λ)������ʱ��ʵ��ֵ + 300�� * 10���������
        DWORD dwEnviroTemperatureLowerLimit; //�����¶�������ֵ��-273.0 - 1000.0(��ȷ��С�����1λ)������ʱ��ʵ��ֵ + 300�� * 10���������
        DWORD dwEmissivityUpperLimit; //������������ֵ��0.01 - 1.00������ʱʵ��ֵ * 100���������
        DWORD dwEmissivityLowerLimit; //������������ֵ��0.01 - 1.00������ʱʵ��ֵ * 100���������
        BYTE  byPointNumUpperLimit; //�¶ȵ����������ֵ
        BYTE  byPointNumLowerLimit; //�¶ȵ����������ֵ
        BYTE  byRes1[2];
        DWORD  dwPresetTemperatureUpperLimit; //Ԥ���¶�������ֵ��-40.0 - 650.0�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        DWORD  dwPresetTemperatureLowerLimit; //Ԥ���¶�������ֵ��-40.0 - 650.0�棬����ʱ(ʵ��ֵ + 100) * 10�����������
        BYTE  byRes[472];
    }USB_THERMAL_THERMOMETRY_EXPERT_CORRECTION_PARAM_CAPABILITIES, *LPUSB_THERMAL_THERMOMETRY_EXPERT_CORRECTION_PARAM_CAPABILITIES;

    //�豸������Ϣ
    typedef struct tagUSB_SYSTEM_DEVICE_DESCRIPTION_INFO
    {
        DWORD dwSize;
        BYTE  szDeviceSerialNumber[64]; //�豸���кţ��豸�ͺ�+��������+4byte��Ϣ+���кţ�
        BYTE  szMachineSerialNumber[32]; //�������кţ�ָ�����豸���к��а��������кţ�
        BYTE  szModel[32]; //�豸�ͺ�
        BYTE  szMechanismSerialNumber[32]; //��о���кţ���о�궨������д��Ļ�о���кţ�
        BYTE  szNUCParaVersion[64]; //NUC�����汾��
        BYTE  szISPParaVersion[64]; //ISP�����汾��
        BYTE  byConnectMode; //�豸���ӷ�ʽ��1-USB2.0  2-USB3.0
        BYTE  byRes[1023];
    }USB_SYSTEM_DEVICE_DESCRIPTION_INFO, *LPUSB_SYSTEM_DEVICE_DESCRIPTION_INFO;

    //����͸��
    typedef struct tagUSB_SYSTEM_SERIAL_DATA_TRANSMISSION
    {
        DWORD dwSize;
        BYTE  byMode; //ģʽ��0-������1-����2-д
        BYTE  byRes1;
        WORD  wDeviceCMDFlag; //�����ʶ����[0,255]
        DWORD dwDeviceCMD; //���[0,10000]
        DWORD dwValue; //ֵ��[0,10000]
        BYTE  byRes[512];
    }USB_SYSTEM_SERIAL_DATA_TRANSMISSION, *LPUSB_THERMAL_SERIAL_DATA_TRANSMISSION;

    //��Ƶͨ��������
    typedef struct tagUSB_VIDEO_COMMON_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE byVideoCode; //��Ƶ���룺0-��֧��  1-֧��
        BYTE byVideoFusion; //��Ƶͼ���ںϲ�����0-��֧��  1-֧��
        BYTE byLenCalibration; //��ͷ�궨��0-��֧��  1-֧��
        BYTE byRes[505];
    }USB_VIDEO_COMMON_CAPABILITIES, *LPUSB_VIDEO_COMMON_CAPABILITIES;

    //��ͷ�궨����
    typedef struct tagUSB_VIDEO_LEN_CALIBRATION_CAPABILITIES
    {
        DWORD  dwSize;
        DWORD  dwFocusUpperLimit; //�۽�ֵ������ֵ
        DWORD  dwFocusLowerLimit; //�۽�ֵ������ֵ
        BYTE  byRes[500];
    }USB_VIDEO_LEN_CALIBRATION_CAPABILITIES, *LPUSB_VIDEO_LEN_CALIBRATION_CAPABILITIES;

#define MAX_RESOLUTION_INFO_NUM  10

    //�ֱ�����Ϣ
    typedef struct tagUSB_VIDEO_RESOLUTION_INFO
    {
        BYTE byVideoResolutionID;  //�ֱ���id��1-256*192, 2-384 * 288, 3-720 * 576, 4-1024 * 768, 5-96 * 96, 6-160 * 120, 7-640 * 512, 8-192 * 144, 9-480 * 360, 10-640 * 480
        BYTE byRes1[3];
        DWORD dwVideoResolutionWidth;  //�ֱ��ʿ�
        DWORD dwVideoResolutionHeight;  //�ֱ��ʸ�
        BYTE byRes[4];
    }USB_VIDEO_RESOLUTION_INFO, *LPUSB_VIDEO_RESOLUTION_INFO;

    //��ѹ��֡�ֱ�����Ϣ
    typedef struct tagUSB_UNPACKED_RESOLUTION_INFO
    {
        BYTE byUnpackedResolution;  //��ѹ��֡�ֱ��ʣ�ֻ��������֡��С��5֡ʱ, �豸��ʹ�÷�ѹ��֡�ϴ�����, ���ݴ�ֻ������������Ƶ������Ϣ, �������ѹ��֡�ֱ������������ݱ���ѹ��֡�ֱ������õ�YVCͨ�����˵�
        //1-320*240, 2-640*480, 3-640*512, 4-1024*600, 5-1280*720
        BYTE byRes1[3];
        DWORD dwUnpackedResolutionWidth;  //��ѹ��֡�ֱ��ʿ�
        DWORD dwUnpackedResolutionHeight;  //��ѹ��֡�ֱ��ʸ�
        BYTE byRes[4];
    }USB_UNPACKED_RESOLUTION_INFO, *LPUSB_UNPACKED_RESOLUTION_INFO;

    //��Ƶ��������
    typedef struct tagUSB_VIDEO_CODE_CAPABILITIES
    {
        DWORD  dwSize;
        DWORD dwMaxFrameRateUpperLimit; //֡��������ֵ��1-30fps
        DWORD dwMaxFrameRateLowerLimit; //֡��������ֵ��1-30fps
        DWORD dwVideoResolutionListNum; //�ֱ����б������ܸ���������ֵΪ10
        DWORD dwUnpackedResolutionListNum; //��ѹ��֡�ֱ����б������ܸ���������ֵΪ10
        USB_VIDEO_RESOLUTION_INFO struVideoResolution[MAX_RESOLUTION_INFO_NUM];
        USB_UNPACKED_RESOLUTION_INFO struUnpackedResolution[MAX_RESOLUTION_INFO_NUM];
        DWORD dwMaxFrameRate3UpperLimit; //USB3.0֡��������ֵ��1-30fps
        DWORD dwMaxFrameRate3LowerLimit; //USB3.0֡��������ֵ��1-30fps
        BYTE  byRes[164];
    }USB_VIDEO_CODE_CAPABILITIES, *LPUSB_VIDEO_CODE_CAPABILITIES;

    //α��ӳ���
    typedef struct tagUSB_IMAGE_PALETTE_DATA{
        DWORD dwSize; //�ṹ���С
        BYTE byPaletteMode; //α��ɫ��ɫģʽ: 1-���� 2-���� 10-�ں�1 11-�ʺ� 12-�ں�2 13-����1 14-����2 15-���ɫ 16-ɫ��1 17-ɫ��2 18-���� 19-�� 20-���� 21-���� 22-����
        BYTE byRes1[3];
        DWORD dwDataLen;//α��ӳ�������
        BYTE byRes2[4];
        BYTE  *pData; //α��ӳ���
        BYTE byRes[1024];
    } USB_IMAGE_PALETTE_DATA, *LPUSB_IMAGE_PALETTE_DATA;

    //�������߷�������
    typedef struct tagUSB_THERAML_THERMOMETRY_OFFLINE_DATA{
        DWORD dwSize; //�ṹ���С
        DWORD dwDataLen;//[in]pData��������С,[out]�������߷������ݳ���
        BYTE byRes2[4];
        BYTE  *pData; //�������߷�������
        BYTE byRes[1024];
    } USB_THERAML_THERMOMETRY_OFFLINE_DATA, *LPUSB_THERAML_THERMOMETRY_OFFLINE_DATA;

    //ͼ���������
    typedef struct tagUSB_IMAGE_OUTPUT_CFG
    {
        DWORD dwSize; //�ṹ���С
        BYTE byEnable; //���ʹ��: 1-�ر� 2-����
        BYTE byType; //ͼ������: 1-��ͼ 2-���߲���ͼ
        BYTE byRes[506];
    }USB_IMAGE_OUTPUT_CFG, *LPUSB_IMAGE_OUTPUT_CFG;

    //�豸������Ϣ����
    typedef struct tagUSB_SYSTEM_DEVICE_DESCRIPTION_INFO_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE  byDeviceSerialNumber; //�豸���кţ��豸�ͺ�+��������+4byte��Ϣ+���кţ�: 1-��֧�� 2-֧��
        BYTE  byMachineSerialNumber; //�������кţ�ָ�����豸���к��а��������кţ�: 1-��֧�� 2-֧��
        BYTE  byModel; //�豸�ͺ�: 1-��֧�� 2-֧��
        BYTE  byMechanismSerialNumber; //��о���кţ���о�궨������д��Ļ�о���кţ�: 1-��֧�� 2-֧��
        BYTE  byNUCParaVersion; //NUC�����汾��: 1-��֧�� 2-֧��
        BYTE  byISPParaVersion; //ISP�����汾��: 1-��֧�� 2-֧��
        BYTE  byConnectMode; //�豸���ӷ�ʽ����λ��ʾö����֧�������0-��֧�֣�1-֧��
        /*
        bit0 - USB 2.0
        bit1 - USB 3.0
        */
        BYTE byRes[245];
    }USB_SYSTEM_DEVICE_DESCRIPTION_INFO_CAPABILITIES, *LPUSB_SYSTEM_DEVICE_DESCRIPTION_INFO_CAPABILITIES;

    //����������ͣ�����ԣ�
    typedef struct tagUSB_CTRL_THERMAL_STREAM_PARAM
    {
        DWORD dwSize;
        BYTE byEnable;//ʹ�ܣ�0-�ر�ȡ��  1-����ȡ��
        BYTE byRes[27];
    }USB_CTRL_THERMAL_STREAM_PARAM, *LPUSB_CTRL_THERMAL_STREAM_PARAM;


    //////////////////////////////////////////////////////////�ȳ������������ṹ�嶨�忪ʼ//////////////////////////////////////////////////////////////////////
#define INT_MINI    (-2147483647 - 1)  /* minimum (signed) int value */
#define INT_MAXI    2147483647  /* maximum (signed) int value */
    //��������
    typedef enum tagUSB_STREAM_TYPE_E
    {
        ENUM_STREAM_H264_TYPE,
        ENUM_STREAM_H265_TYPE,
        ENUM_STREAM_JPEG_TYPE,
        ENUM_STREAM_AUD_TYPE,
        ENUM_STREAM_META_TYPE,
        ENUM_STREAM_UPDATE_TYPE,  //����ˢ�°�����֪APP��ǰ֡��֮ǰ�Ĳ������ڲ�ͬ���������²��� 
        ENUM_STREAM_RTDATA_TYPE,  //ʵʱ�ϴ����� 
        ENUM_STREAM_TYPE_INT_MIN = INT_MINI,
        ENUM_STREAM_TYPE_INT_MAX = INT_MAXI
    }USB_STREAM_TYPE_E;

    //ʱ���
    typedef struct tagUSB_DATE_TIME
    {
        WORD  wYear; //��
        WORD  wMonth;//��
        WORD  wDayOfWeek;//0-������, 1-����һ, 2-���ڶ�, 3-������, 4-������, 5-������, 6-������
        WORD  wDay;//��
        WORD  wHour;//Сʱ, 0~23
        WORD  wMinute;//����, 0~59
        WORD  wSecond;//��, 0~59
        WORD  wMillisecond;//����, 0~999
    }USB_DATE_TIME, *LPUSB_DATE_TIME;

    //ʵʱ�¶���������ṹ��
    typedef struct tagUSB_STREAM_RT_DATA_INFO_S
    {
        DWORD  dwRTDataType; // 1-14bit������; 2-ȫ�����½������; 3-YUV����
        DWORD  dwFrmNum; //֡���кţ�ʵʱ�ϴ���֡���к�������������ż��1000��1002��1004��1006
        DWORD  dwStdStamp; //DSP���ʱ���
        USB_DATE_TIME struTime;//������ʱ�䣬��ʱ�����ڼ�¼��ǰ֡���ݵĲɼ�ʱ�䣬��sensor�ɼ���ɺ��ʱ�䣬��ʱ�������û�ƥ��������Ӧ֡ʱʹ��
        DWORD  dwWidth;//�����ݿ�
        DWORD  dwHeight;//�����ݸ�
        DWORD  dwLen;//ʵʱ���¾���ĳ��ȣ����ֽ�Ϊ��λ���ټ���4���ֽڣ� ��4�ֽڵ�float���¾���120*160*4+4 
        DWORD  dwFps;//ʵʱ�ϴ���֡�ʣ���ǰ�̶�����Ϊ�û����õ�֡��
        DWORD  dwChan;//ͨ���ţ���ʱ�̶�Ϊ0
    }USB_STREAM_RT_DATA_INFO_S, *LPUSB_STREAM_RT_DATA_INFO_S;

    //ʵʱ�¶����ݸ�����Ϣ�ṹ��
    typedef struct tagUSB_STREAM_FS_SUPPLE_INFO_TEMP
    {
        DWORD  dwTmDataMode;  //0Ϊ4�ֽڣ�1Ϊ2�ֽ� 
        DWORD  dwTmScale;   //�������ű��� 
        DWORD  dwTmOffset;  //����ƫ��������ǰ�̶�Ϊ0 
        DWORD  dwIsFreezedata;  //�Ƿ��Ƕ������ݣ�1-���ᣬ0-�Ƕ��� 
    }USB_STREAM_FS_SUPPLE_INFO_TEMP, *LPUSB_STREAM_FS_SUPPLE_INFO_TEMP;

    //ʵʱJPEG������ṹ��
    typedef struct tagUSB_RT_JPEG_DATA_INFO_S
    {
        DWORD  dwFrmNum;  //֡���кţ�ʵʱ�ϴ���֡���к�������������ż�� 1000��1002��1004��1006 
        DWORD  dwWidth;  //JPEG���ݿ� 
        DWORD  dwHeight;  //JPEG���ݸ� 
        DWORD  dwJpegLen;  //JPEG���ݳ���(DATA2)
        DWORD  dwStdStamp;  //DSP���ʱ��� 
        USB_DATE_TIME struTime;  //��ǰʱ�� 
    }USB_RT_JPEG_DATA_INFO_S, *LPUSB_RT_JPEG_DATA_INFO_S;

    //�¶ȵ�λ
    typedef enum tagUSB_IFR_TEMP_UNIT
    {
        IFR_TEMP_CENTIGRADE = 0,  //���϶� 
        IFR_TEMP_FAHRENHEIT = 1,  //���϶� 
        IFR_TEMP_KELVIN = 2,  //������

        IFR_TEMP_UNIT_MIN = INT_MINI,
        IFR_TEMP_UNIT_MAX = INT_MAXI
    }USB_IFR_TEMP_UNIT;

    //����
    typedef struct tagUSB_IFR_POINT
    {
        int  x;
        int  y;
    }USB_IFR_POINT, *LPUSB_IFR_POINT;

    //����������½��	  
    typedef struct tagUSB_IFR_SQUARE_ROI_OUTCOME_INFO
    {
        BYTE byEnable;  //�Ƿ����ã�0-��1-��
        BYTE byRegionId;  //����ID
        BYTE byRes[34];  //�����ֶ�
        char szName[32];  //��������
        float fEmissionRate;  //������: [0.00, 1.00]
        float fDistance;  //Ԥ��Ĳ��¾���
        float fMinTmp;  //����¶�: [-40.0, 1000.0]����λ���϶�
        float fMaxTmp;  //����¶�: [-40.0, 1000.0]����λ���϶�
        float fAvgTmp;  //ƽ���¶�: [-40.0, 1000.0]����λ���϶�
        USB_IFR_POINT struPoints[2];  //������Խ���е�����º���������꣬��һ����0-1000�������±�: 0-����£�1-�����
    }USB_IFR_SQUARE_ROI_OUTCOME_INFO, *LPUSB_IFR_SQUARE_ROI_OUTCOME_INFO;

#define IFR_MAX_SQUARE_REGION_NUM  10
    //ROI�����������������ⲿ����Ϣ�б�
    typedef struct tagUSB_IFR_SQUARE_ROI_OUTCOME_LIST
    {
        DWORD dwRoiRegionNum;  //��Ч������������ 
        USB_IFR_SQUARE_ROI_OUTCOME_INFO struIfrRoiOutcome[IFR_MAX_SQUARE_REGION_NUM];  // ���½��
    }USB_IFR_SQUARE_ROI_OUTCOME_LIST, *LPUSB_IFR_SQUARE_ROI_OUTCOME_LIST;

    //ʵʱ������Ϣ������ṹ��
    typedef struct tagUSB_IFR_REALTIME_TM_UPLOAD_INFO
    {
        USB_IFR_TEMP_UNIT  enumTempUnit;  // �¶ȵ�λ��Ĭ�����϶ȣ���Ҫ�����ϴ� 
        BYTE  byRefTempkey;  //�����¶ȿ���
        BYTE  byRes1[3];  //���� 
        float  fDistance;  //��������
        float  fRefTemp;  //�����¶ȣ����ݷ����¶ȿ���
        float  fEmissionRate;  //�����ʣ�[0.00, 1.0] 
        float  fEnvTemp;  //�����¶�, ���¸�ʱ�Ӳ����㷨���л�ȡ
        float  fMinTmp;  //ȫ������¶�
        float  fMaxTmp;  // ȫ������¶�
        float  fAvrTmp;  //ȫ��ƽ���¶�
        USB_IFR_POINT  struPoints[3];  //������Խ���е�����º���������꣬��һ����0-1000�������±�: 0-����£�1-����� ��2-ƽ����
        BYTE  byRes[24];
        USB_IFR_SQUARE_ROI_OUTCOME_LIST struRoiOutList; //ROI�����������Ϣ
    }USB_IFR_REALTIME_TM_UPLOAD_INFO, *LPUSB_IFR_REALTIME_TM_UPLOAD_INFO;


    //�ȳ���ȫ������ʵʱ�����ݽṹ��ÿ֡������Ϊ��USB_THERMAL_STREAM_TEMP_S(ͷ����) + DATA(ȫ����������)
    typedef struct tagUSB_THERMAL_STREAM_TEMP_S
    {
        DWORD  dwMagicNo;  //ħ����, �涨Ϊ0x70827773, ��"FRMI"��ASCII��
        DWORD  dwHeadLen; //Head����
        DWORD  dwStreamType; //��������RTData, �μ�STREAM_TYPE_E
        DWORD  dwStreamLen; //ȫ���������ݳ���(DATA)
        USB_STREAM_RT_DATA_INFO_S  struRTDataInfo;//ʵʱ�¶�������Ϣ
        USB_STREAM_FS_SUPPLE_INFO_TEMP  struFsSuppleInfo;//ʵʱ�¶����ݸ�����Ϣ
        BYTE  byRes[48];
        DWORD  dwCrcVal;//�ṹ��У���룬�Խṹ����ǰ�����ݽ���У��
    }USB_THERMAL_STREAM_TEMP_S, *LPUSB_THERMAL_STREAM_TEMP_S;

    //�ȳ�����ͼʵʱ�����ݽṹ��ÿ֡������Ϊ��USB_THERMAL_STREAM_TEMP_HOT(ͷ����) + DATA1(ȫ����������) + DATA2(JPEG����)
    typedef struct tagUSB_THERMAL_STREAM_TEMP_HOT
    {
        DWORD  dwMagicNo;  //ħ����, �涨Ϊ 0x70827773
        DWORD  dwHeadLen; //Head����, ���ֽ�Ϊ��λ
        DWORD  dwStreamType; //��������, �μ�STREAM_TYPE_E
        DWORD  dwStreamLen; //ȫ���������ݳ���(DATA1)
        DWORD  dwIRFJpg;//�Ƿ�Я��JPEGͼƬ
        USB_STREAM_RT_DATA_INFO_S  struRTDataInfo;//ʵʱ�¶�������Ϣ
        USB_STREAM_FS_SUPPLE_INFO_TEMP  struFsSuppleInfo;//ʵʱ�¶����ݸ�����Ϣ
        USB_RT_JPEG_DATA_INFO_S  struRTJpegDataInfo;//ʵʱJPEG������Ϣ
        USB_IFR_REALTIME_TM_UPLOAD_INFO  struRTDataUpload;//ʵʱ������Ϣ
        BYTE  byRes[48];
        DWORD  dwCrcVal;//�ṹ��У���룬�Խṹ����ǰ�����ݽ���У��
    }USB_THERMAL_STREAM_TEMP_HOT, *LPUSB_THERMAL_STREAM_TEMP_HOT;

    //////////////////////////////////////////////////////////�ȳ������������ṹ�嶨�����//////////////////////////////////////////////////////////////////////

    typedef struct tagUSB_DEVICE_INFO
    {
        DWORD   dwSize;   //�ṹ���С
        DWORD   dwIndex; // �豸���� 
        DWORD   dwVID;   //�豸VID
        DWORD   dwPID;   //�豸PID
        char    szManufacturer[MAX_MANUFACTURE_LEN/*32*/];//�����̣�������������
        char    szDeviceName[MAX_DEVICE_NAME_LEN/*32*/];//�豸���ƣ�������������
        char    szSerialNumber[MAX_SERIAL_NUMBER_LEN/*48*/];//�豸���кţ�������������
        BYTE    byHaveAudio;    // �Ƿ������Ƶ
        BYTE    iColorType;     // 1.RGB·�� 2.IR·
        BYTE    szDevicePath[MAX_PATH_LEN];
        BYTE    byDeviceType;   //�豸���ͣ�0-HID���������豸 1-UVC(��Ƶ)�豸 2-UVC(��Ƶ)�豸 4-UAC(��Ƶ)�豸��5-UVC(��Ƶ)�豸
        DWORD   dwBCD;          //�豸�����汾��
        BYTE    byRes[249];
    } USB_DEVICE_INFO, *LPUSB_DEVICE_INFO;

    typedef struct tagUSB_USER_LOGIN_INFO
    {
        DWORD   dwSize; //�ṹ���С
        DWORD   dwTimeout; //��¼��ʱʱ�䣨��λ�����룩,ȡֵ��Χ��0-Ĭ��ֵ5000���룬[1000,5000]-���峬ʱʱ��
        DWORD   dwDevIndex; //�豸�±�
        DWORD   dwVID;  //�豸VID��ö���豸ʱ�õ�
        DWORD   dwPID;  //�豸PID��ö���豸ʱ�õ�
        char    szUserName[MAX_USERNAME_LEN/*32*/]; //�û�������ȡ����״̬ʱ������
        char    szPassword[MAX_PASSWORD_LEN/*16*/]; //���룬��ȡ����״̬ʱ������
        char    szSerialNumber[MAX_SERIAL_NUMBER_LEN/*48*/]; //�豸���кţ�ö���豸ʱ�õ�
        BYTE    byLoginMode; //0-��֤��½ 1-Ĭ���˺ŵ�½���������û������룩��Ȩ�޲�ͬ�����ֹ�������֤��½��֧�֣�
        // �����Բ���ָ����ʽ��½��
        BYTE    byRes2[3];
        DWORD   dwFd; //�豸������fd (android��û��rootȨ�޵�¼ʱʹ��)
        BYTE    byRes[248];
    } USB_USER_LOGIN_INFO, *LPUSB_USER_LOGIN_INFO;

    typedef struct tagUSB_DEVICE_REG_RES
    {
        DWORD   dwSize;   //�ṹ���С
        char    szDeviceName[MAX_DEVICE_NAME_LEN /*32*/]; //�豸����
        char    szSerialNumber[MAX_SERIAL_NUMBER_LEN /*48*/]; //�豸���к�
        DWORD   dwSoftwareVersion; //�����汾��,��16λ�����汾,��16λ�Ǵΰ汾
        WORD    wYear;
        BYTE    byMonth;
        BYTE    byDay;
        BYTE    byRetryLoginTimes; //ʣ��ɳ��Ե�½�Ĵ���
        BYTE    byRes1[3];             //����
        DWORD   dwSurplusLockTime; //ʣ��ʱ�䣬��λ�� �û�����ʱ���˲�����Ч
        BYTE    byRes[256];
    } USB_DEVICE_REG_RES, *LPUSB_DEVICE_REG_RES;


    typedef struct tagUSB_CONFIG_INPUT_INFO
    {
        void * lpCondBuffer;        //ָ������������
        DWORD  dwCondBufferSize;//������������С
        void * lpInBuffer;          //ָ�����������
        DWORD  dwInBufferSize;   //���뻺������С
        BYTE   byRes[48];
    } USB_CONFIG_INPUT_INFO, *LPUSB_CONFIG_INPUT_INFO; //64�ֽ�

    typedef struct tagUSB_CONFIG_OUTPUT_INFO
    {
        void * lpOutBuffer;      //ָ�����������
        DWORD  dwOutBufferSize;  //�����������С
        BYTE   byRes[56];
    } USB_CONFIG_OUTPUT_INFO, *LPUSB_CONFIG_OUTPUT_INFO; //64�ֽ�

    typedef struct tagUSB_UPGRADE_STATE_INFO
    {
        DWORD  dwSize;
        BYTE   byState;
        BYTE   byProgress;
        BYTE   byRes[6];
    } USB_UPGRADE_STATE_INFO, *LPUSB_UPGRADE_STATE_INFO; //12�ֽ�

    typedef struct tagUSB_UPGRADE_COND
    {
        DWORD dwSize;
        BYTE  byTimeout;
        BYTE  byFileCrc; //�Ƿ�У����������0-Ĭ�ϣ���У�� 1-У��
        BYTE  byRes[2];
        DWORD dwModuleID;
        BYTE  byRes1[4];
    } USB_UPGRADE_COND, *LPUSB_UPGRADE_COND;//16�ֽ�

    typedef struct tagUSB_MIME_UNIT
    {
        //HTTP��ʽ����
        //Content-Disposition: form-data; name="upload"; filename="C:\Users\test\Desktop\11.txt"
        //Content-Type: text/plain
        char szContentType[32];               //��ӦContent-Type
        char szName[MAX_FILE_PATH_LEN];       //��Ӧname�ֶ�
        char szFilename[MAX_FILE_PATH_LEN];   //��Ӧfilename�ֶ�
        DWORD dwContentLen;              //Content�ĳ���
        char* pContent;                       //����ָ��
        BYTE byRes[16];
    }USB_MIME_UNIT, *LPUSB_MIME_UNIT;

    typedef struct tagUSB_DATA_BUFFER
    {
        char szName[MAX_FILE_PATH_LEN];  //[OUT]��Ӧname�ֶ�
        void * pDataBuffer;         //[IN/OUT]���ݻ�����
        DWORD   dwDataSize;              //[IN/OUT]���ݻ�������С/ʵ�ʴ��豸���յ������ݵĳ���
        BYTE    byRes[12];               //����
    }USB_DATA_BUFFER, *PUSB_DATA_BUFFER;

    typedef struct tagUSB_PT_PARAM
    {
        DWORD   dwSize;             //�ṹ���С
        void *  pRequestUrl;        //[IN]����URL
        DWORD   dwRequestUrlLen;    //[IN]����URL����
        void *  pInBuffer;          //[IN]��������
        DWORD   dwInSize;           //[IN]�������ݳ���
        void *  pOutBuffer;         //[IN/OUT]���������
        DWORD   dwOutSize;          //[IN/OUT]�����������С/ʵ�ʴ��豸���յ������ݵĳ���
        DWORD   dwSendTimeOut;      //[IN]Ĭ��5000ms
        DWORD   dwRecvTimeOut;      //[IN]Ĭ��5000ms
        USB_DATA_BUFFER struData[MAX_DATA_NUM];
        BYTE    byNumOfMultiPart;   //[IN]0-��Ч������ֵ��ʾ���ķֶθ���������ʱpInBuffer�������USB_SDK_MIME_UNIT�ṹ�������ָ�룬��ֵ�������ṹ�����
        BYTE    byNumOfData;        //[OUT]ʵ���豸���ص�DATA������������ɼ�����������
        BYTE    byRes[62];          //����
    }USB_PT_PARAM, *LPUSB_PT_PARAM;

    typedef struct tagUSB_CONTROL_INPUT_INFO
    {
        void * lpCondBuffer;     //�������������
        DWORD  dwCondBufferSize; //���������������С
        void * lpInBuffer;        //���뻺����
        DWORD  dwInBufferSize;    //���뻺������С
        BYTE   byRes[48];
    }USB_CONTROL_INPUT_INFO, *LPUSB_CONTROL_INPUT_INFO; //64�ֽ�

    typedef struct tagUSB_PREVIEW_PARAM
    {
        DWORD  dwSize;
        DWORD  dwStreamType;				//��������
        DWORD  dwChannel;
        HWND   hWindow;				       //���ھ��
        BYTE   bUseAudio;				   //�Ƿ�Ԥ����Ƶ
        BYTE   bYUVCallback;			   //�Ƿ���YUV�ص�
        BYTE   byRes[126];
    } USB_PREVIEW_PARAM, *LPUSB_PREVIEW_PARAM;

    typedef struct tagUSB_RECORD_PARAM
    {
        DWORD  dwSize;
        DWORD  dwRecordType;                // ¼������
        BYTE   bRecordAudio;   // �Ƿ�¼����Ƶ
        BYTE   byRes1[3];
        char   szFilePath[MAX_FILE_PATH_LEN];        // ¼���ļ��洢·��
        BYTE   byRes[128];
    } USB_RECORD_PARAM, *LPUSB_RECORD_PARAM;

    ////Frame Info
    //typedef struct{
    //    LONG nWidth;
    //    LONG nHeight;
    //    LONG nStamp;
    //    LONG nType;
    //    LONG nFrameRate;
    //    DWORD dwFrameNum;
    //}FRAME_INFO;

    typedef struct __RECT
    {
        DWORD nX;
        DWORD nY;
        DWORD nWidth;
        DWORD nHeight;
    }ORECT;

    typedef struct tagTARGET_INFO
    {
        ORECT    struRect;             // Ŀ��λ��
        DWORD  dwImgHeight;          // ����ͼƬ��
        DWORD  dwImgWidth;           // ����ͼƬ��
        LONG   nBufferLen;           // ����ͼƬ��������С
        BYTE *  pBuffer;             // ����ͼƬ������
        BYTE    byRes[128];
    } TARGET_INFO;

    typedef struct tagUSB_FACE_DRAW_PARAM
    {
        TARGET_INFO struTargetInfoList[50];
        DWORD    dwFaceTotalNum;             // �����ܵĸ���                    
        BYTE    byEnlarge;                  // �Ƿ����������Ŵ�ģʽ 0-������ 1-����
        BYTE    byShowFont;                 // �Ƿ���ʾ��ʾ���� 0:��ʾ 1:����ʾ
        BYTE    byDisappear;                // �����Ƿ���ʧ
        BYTE    byRes[125];
    }USB_FACE_DRAW_PARAM, *LPUSB_FACE_DRAW_PARAM;


    typedef struct tagUSB_IR_FRAME
    {
        DWORD                  nLen;               // ���ݳ���
        BYTE*       pBuffer;            // ���ݻ���
        DWORD                  byRes[32];
    }USB_IR_FRAME, *LPUSB_IR_FRAME;


    /**	@struct �����������ṹ��
    *  @brief
    *
    */
    typedef struct tagUSB_LIVE_COND_INFO
    {
        UINT dwWidth;
        UINT dwHeight;
        BYTE* pRGBBuf;
        UINT pRGBBufLen;
        BYTE* pIRBuf;
        UINT pIRBufLen;
    }USB_LIVE_COND_INFO, *LPUSB_LIVE_COND_INFO;


#define MAX_LIVE_TARGET_NUM  64
    typedef struct tagUSB_FR_LIVE_INFO
    {
        DWORD					nLiveStatus;
        float				fLiveConfidence;     //���������Ŷ�
        char				reserved[16];         //Ԥ��16���ֽ�                           
    }USB_FR_LIVE_INFO, *LPUSB_FR_LIVE_INFO;

    typedef struct tagFACE_ATTR_CLS
    {
        DWORD                       nValue;                           //���
        float                      fConf;                            //���Ŷ�,��Χ0~1
    }USB_FACE_ATTR_CLS, *LPUSB_FACE_ATTR_CLS;

    typedef struct tagFACE_ATTR_OUT
    {
        USB_FACE_ATTR_CLS   stAge;                        // ���䣬0 ~ 99
        USB_FACE_ATTR_CLS   stGender;                     // �Ա�0-Ů, 1-��
        USB_FACE_ATTR_CLS   stGlass;                      // �Ƿ���۾���0-���۾�,1-��ͨ�۾�,2-ī��
        USB_FACE_ATTR_CLS   stExpress;                    // ���飬0-���ԣ�1-���ˣ�2-���ȣ�3-���£�4-���5-�ѹ���6-��ŭ
        USB_FACE_ATTR_CLS   stMask;                       // ���֣�0-�������֣�1-������
        USB_FACE_ATTR_CLS   szReserved1;                  // �����ֽ�
        USB_FACE_ATTR_CLS   stHat;                        // ñ�ӣ�0-����ñ�ӣ�1-��ñ��
        BYTE                szReserved[64];               // �����ֽ�
    }USB_FACE_ATTR_OUT, *LPUSB_FACE_ATTR_OUT;

    typedef struct tagUSB_TARGET_LIVE_INFO
    {
        USB_FR_LIVE_INFO       strLiveInfo;
        USB_FACE_ATTR_OUT      strFaceAttr;
    }USB_TARGET_LIVE_INFO, *LPUSB_TARGET_LIVE_INFO;

    typedef struct tagUSB_FR_LIVE_PARAM
    {
        DWORD                   LiveNum;                                // ʵ�ʵ�Ŀ�����,����0��ʾ�л���
        USB_TARGET_LIVE_INFO          stTargetLiveOut[MAX_LIVE_TARGET_NUM];      // �������
    }USB_FR_LIVE_PARAM, *LPUSB_FR_LIVE_PARAM;


    typedef struct tagUSB_FRAME_INFO
    {
        LONG       nStamp;       // ʱ����Ϣ
        DWORD      dwStreamType; // ��������
        DWORD      dwWidth;      // �����,�������Ƶ������Ϊ��Ƶ������
        DWORD      dwHeight;     // �����,�������Ƶ������Ϊ����λ��
        DWORD      dwFrameRate;  // ֡��,����ʱ������ͼ��֡�ʣ��������Ƶ������Ϊ������
        DWORD      dwFrameType;  // ��Ƶ֡����,  ��Ӧת��װ�����������,�������Ƶ������ΪnAvgBytesPerSec
        DWORD      dwDataType;   // ��������,��Ӧת��װ���������������  1-ϵͳͷ���� 2-��Ƶ������ 3-��Ƶ������
        LONG       nFrameNum;    // ֡��, 
        BYTE       *pBuf;        // ����ָ��
        DWORD      dwBufSize;    // ���ݳ���
        BYTE       byRes[128];
    } USB_FRAME_INFO, *LPUSB_FRAME_INFO;


    typedef struct tagUSB_FACE_QUALITY
    {
        float               fEyeDistance;                   // ���ۼ��,��ʵ����ֵ
        float               fGrayMean;                      // �ҽ׾�ֵ����Χ0~255
        float               fGrayVariance;                  // �ҽ׾������Χ0~128
        float               fClearityScore;                 // ���������֣���Χ0~1
        float               fPosePitch;                     // ƽ�������¸����ǣ���������Ϊ������Χ-90~90
        float               fPoseYaw;                       // ƽ��������ƫת�ǣ���������Ϊ������Χ-90~90
        float               fPoseRoll;                      // ƽ������ת�ǣ�����˳ʱ����תΪ������Χ-90~90
        float               fPoseConfidence;                // ��̬(pose_pitch��pose_yaw��pose_roll)���Ŷȣ���Χ0~1
        float               fFrontalScore;                  // ����̶����֣���Χ0~1
        float               fVisibleScore;                  // �ɼ������֣������ڵ�������Χ0~1��0��ʾ��ȫ�ڵ���1��ʾ��ȫ���ڵ�
        float               fFaceScore;                     // �������֣���Χ0~1
        BYTE           byRes[128];                     // �����ֽڣ�������չ������
    }USB_FACE_QUALITY, *LPUSB_FACE_QUALITY;

    typedef struct tagUSB_SUBFACE_PIC
    {
        DWORD       dwWidth;             // Сͼ����
        DWORD       dwHeight;            // Сͼ�߶�
        BYTE*       pSubFacePic;         // ����Сͼ
        DWORD       dwSubFacePicLen;     // ����Сͼ��С
#if (defined(OS_WINDOWS64) || defined(OS_POSIX64))
        BYTE*       pSubFaceJpgPic;      // ����JpgСͼ
#else
        BYTE*       pSubFaceJpgPic;      // ����JpgСͼ
        BYTE        byRes1[4];           // �����ֽ�
#endif
        DWORD       dwSubFaceJpgPicLen;  // ����JpgСͼ��С
        BYTE        byRes[4];            // �����ֽ�
    }USB_SUBFACE_PIC, *LPUSB_SUBFACE_PIC;

    typedef struct tagUSB_FACE_PARAM
    {
        USB_FACE_QUALITY   struFaceQualityList;
        USB_SUBFACE_PIC    struSubFacePic;
        BYTE          byRes[16];         // �����ֽ�
    }USB_FACE_PARAM, *LPUSB_FACE_PARAM;

    /**	@struct USB_CAMERA_MEDIA_DATA
    *  @brief   ����ý������ṹ��*
    */
    typedef struct tagUSB_MEDIA_DATA
    {
        DWORD   dwWidth;             // ����
        DWORD   dwHeight;            // �߶�
        DWORD   dwFrameRate;         // ֡��
        DWORD   dwTimeStamp;         // ʱ���
        DWORD   dwFrameNum;          // ֡��
        DWORD   dwLen;               // ����ͼ���ݳ���
        BYTE*   pBuffer;             // ����ͼ����
        INT64   dwSysTime;           // ϵͳʱ���
#if (defined(OS_WINDOWS64) || defined(OS_POSIX64))
        BYTE*   pJpgBuffer;          // ����Jpgͼ����
#else
        BYTE*   pJpgBuffer;          // ����Jpgͼ����
        BYTE    byRes1[4];           // �����ֽ�
#endif
        DWORD   dwJpgLen;            // ����Jpgͼ���ݳ���
        BYTE    byRes[116];          // �����ֽ�
    }USB_MEDIA_DATA, *LPUSB_MEDIA_DATA;

    typedef struct tagUSB_FD_RESULT_PARAM
    {
        DWORD        dwFaceTotalNum;             // �����ܵĸ��� 
        USB_MEDIA_DATA    struMediaData;
        USB_FACE_PARAM    struFaceParam[64]; //������������
        BYTE         byRes[32];
    }USB_FD_RESULT_PARAM, *LPUSB_FD_RESULT_PARAM;

    //�ⲿ�¼��ص�
    typedef void(__stdcall *fnEventCallBack)(LONG lPort, LONG lEvent, LONG nParam1, LONG nParam2, void *pUser);
    //�ڲ����ſ�YUV���ݻص�
    //typedef void(__stdcall *YUVDataCallBack)(LONG nPort, char *pBuf, LONG nSize, FRAME_INFO *pFrameInfo, void * nReserved1, void * nReserved2);
    //typedef void(__stdcall *DecCallBack)(LONG lPort, BYTE *pBuf, LONG nSize, FRAME_INFO *pFrameInfo, void* pUser);
    //�ⲿ�����ص�
    typedef void(__stdcall *fnStreamCallBack)(LONG handle, USB_FRAME_INFO *pFrameInfo, void* pUser);
    //�ⲿ����������ص�
    //typedef void(__stdcall *FDResultCallBack)(LONG lPort, LPUSB_FACE_DRAW_PARAM struRes);
    //�ⲿ����������ص�
    typedef void(__stdcall *FDExtenResultCallBack)(long lPort, LPUSB_FD_RESULT_PARAM struFDResultInfo, void* pUser);

    typedef struct tagUSB_STREAM_CALLBACK_PARAM
    {
        DWORD  dwSize;
        DWORD  dwStreamType; //MJPEG/H264/YUV/PCM
        fnStreamCallBack funcStreamCallBack;
        void * pUser;
        BYTE   bUseAudio;  //�Ƿ�ص���Ƶ
        BYTE  byRes[127];
    } USB_STREAM_CALLBACK_PARAM, *LPUSB_STREAM_CALLBACK_PARAM;

    //typedef struct tagUSB_FACE_DETECT_PARAM
    //{
    //    BYTE  byEnable;                 // �Ƿ�ʹ���������   0-��ʹ��   1-ʹ��
    //    BYTE  byEnlarge;                // �Ƿ����������Ŵ�ģʽ 0-������ 1-����
    //    BYTE  byModel;                  // �������ģʽ 0:������� 1:����������� 2:�������λ������ 3:��������
    //    BYTE  bySnapMode;               // ץͼģʽ  0:�Զ�ץͼ 1:�ֶ�ץͼ
    //    BYTE  szFacePicPath[MAX_FILE_PATH_LEN];  // ����ͼƬ·��
    //    FDResultCallBack fnFaceDetectCB;    // ����������ݻص�
    //    BYTE  byShowFont;               // �Ƿ���ʾ��ʾ���� 0:��ʾ 1:����ʾ����֧�֡�
    //    BYTE  byRes[127];
    //}USB_FACE_DETECT_PARAM, *LPUSB_FACE_DETECT_PARAM;

    typedef struct tagUSB_FACE_DETECT_PARAM
    {
        FDExtenResultCallBack fnFDExtenResultCallBack;  // �������Լ�������ݻص�
        void*           pUser;
        BYTE  bySnapMode;               // ץͼģʽ  0:�Զ�ץͼ 1:�ֶ�ץͼ     ��Ԥ������֧�֡�
        BYTE             byRes[503];
    }USB_FACE_DETECT_PARAM, *LPUSB_FACE_DETECT_PARAM;


    typedef struct tagUSB_CAPTURE_PARAM
    {
        DWORD  dwSize;        // sizeof(USB_CAMERA_CAPTURE_PARAM)
        DWORD  dwType;        // ץͼ��ʽ��0-�ڲ�д�ļ���1-����ͼƬ����
        BYTE   *pBuf;         // ���ݻ�����
        DWORD  dwBufSize;     // ���ݻ�������С
        DWORD  dwDataLen;     // ���ݻ���������Ч���ݳ���(��ͼƬ��С)
        char   szFilePath[256]; //ͼƬ�洢·��
        BYTE   byRes[32];
    } USB_CAPTURE_PARAM, *LPUSB_CAPTURE_PARAM;

    typedef struct tagUSB_BEEP_AND_FLICKER
    {
        DWORD     dwSize;   //�ṹ���С
        BYTE      byBeepType;// �������� 0��Ч��1������2������3������4ֹͣ
        BYTE      byBeepCount;// ���д���, ��ֻ��������������Ч���Ҳ���Ϊ0��
        BYTE      byFlickerType;// ��˸���� 0��Ч��1������2����3��ȷ��4ֹͣ
        BYTE      byFlickerCount;// ��˸������ֻ�Դ�����ȷ��Ч���Ҳ���Ϊ0��
        BYTE      byRes[24];
    } USB_BEEP_AND_FLICKER, *LPUSB_BEEP_AND_FLICKER; //32�ֽ�

    typedef struct tagUSB_CARD_ISSUE_VERSION
    {
        DWORD     dwSize;   //�ṹ���С
        char      szDeviceName[MAX_DEVICE_NAME_LEN /*32*/]; //�豸����
        char      szSerialNumber[MAX_SERIAL_NUMBER_LEN /*48*/]; //�豸���к�
        DWORD     dwSoftwareVersion; //�����汾��,//�����汾�ţ���ʽΪ��24-32λΪ���汾�ţ�16-24λΪ�ΰ汾�ţ�0-16λΪ��С�汾�ţ�
        WORD      wYear;
        BYTE      byMonth;
        BYTE      byDay;
        BYTE      byLanguage; //0-���ģ�1-Ӣ��
        BYTE      byRes[35];
    } USB_CARD_ISSUE_VERSION, *LPUSB_CARD_ISSUE_VERSION; //128�ֽ�

    typedef struct tagUSB_CARD_PROTO
    {
        DWORD   dwSize;   //�ṹ���С
        BYTE    byProto; //��Э�����ͣ�0-TypeA,1-TypeB,2-typeAB,3-125Khz,255���У�
        BYTE    byRes[27];
    } USB_CARD_PROTO, *LPUSB_CARD_PROTO; //32�ֽ�

    typedef struct tagUSB_WAIT_SECOND
    {
        DWORD   dwSize;   //�ṹ���С
        BYTE    byWait; // 1Byte�����ȴ�ʱ�䣨0-һֱִ��ֱ���п���Ӧ��������Ӧ1S��λ��
        BYTE    byRes[27];
    } USB_WAIT_SECOND, *LPUSB_WAIT_SECOND; //32�ֽ�

    typedef struct tagUSB_ACTIVATE_CARD_RES
    {
        DWORD  dwSize;
        BYTE   byCardType;// �����ͣ�0-TypeA m1����1-TypeA cpu��,2-TypeB,3-125kHz Id��,4-Felica Card 5-Desfire Card��
        BYTE   bySerialLen; //���������к��ֽڳ���
        BYTE   bySerial[10];//���������к�
        BYTE   bySelectVerifyLen; //ѡ��ȷ�ϳ���
        BYTE   bySelectVerify[3]; //ѡ��ȷ��(3�ֽ�)
        BYTE   byRes[12];
    } USB_ACTIVATE_CARD_RES, *LPUSB_ACTIVATE_CARD_RES; //32�ֽ�

    typedef struct tagUSB_M1_PWD_VERIFY_INFO
    {
        DWORD    dwSize;   //�ṹ���С
        BYTE     byPasswordType; // �������0-KeyA, 1-KeyB��
        BYTE     bySectionNum; // Ҫ��֤�����������
        BYTE     byRes1[2];  //�����ֽ�
        BYTE     byPassword[6]; // 6Byte����
        BYTE     byRes[18]; //�����ֽ�
    } USB_M1_PWD_VERIFY_INFO, *LPUSB_M1_PWD_VERIFY_INFO; //32�ֽ�

    typedef struct tagUSB_M1_BLOCK_ADDR
    {
        DWORD    dwSize;
        WORD     wAddr; // 2Byte���ַ
        BYTE     byRes[26];
    } USB_M1_BLOCK_ADDR, *LPUSB_USB_M1_BLOCK_ADDR; //32�ֽ�

    typedef struct tagUSB_M1_BLOCK_DATA
    {
        DWORD   dwSize;   //�ṹ���С
        BYTE    byData[16];// 16Byte������
        BYTE    byRes[12];
    } USB_M1_BLOCK_DATA, *LPUSB_M1_BLOCK_DATA; //32�ֽ�

    typedef struct tagUSB_M1_BLOCK_WRITE_DATA
    {
        DWORD    dwSize;   //�ṹ���С
        WORD    wAddr;    // 2Byte���ַ
        BYTE     byDataLen; // ���ݳ���(0-16)
        BYTE     byRes1;    //�����ֽ�
        BYTE     byData[16]; //16Byte BUFF(Ҫд�Ŀ�����)
        BYTE     byRes[8];  //�����ֽ�
    } USB_M1_BLOCK_WRITE_DATA, *LPUSB_M1_BLOCK_WRITE_DATA; //32�ֽ�

    typedef struct tagUSB_M1_MODIFY_SCB
    {
        DWORD    dwSize;   //�ṹ���С
        BYTE     bySectionNum;  //1Byte������
        BYTE     byPasswordA[6];// 6Byte ����A
        BYTE     byRes1;    //�����ֽ�
        BYTE     byCtrlBits[4];   // 4Byte����λ
        BYTE     byPasswordB[6];// 6Byte ����B
        BYTE     byRes[10]; //�����ֽ�
    } USB_M1_MODIFY_SCB, *LPUSB_M1_MODIFY_SCB; //32�ֽ�

    typedef struct tagUSB_M1_BLOCK_OPER
    {
        DWORD    dwSize;   //�ṹ���С
        WORD     wAddr;    // 2Byte���ַ
        WORD     wValue;    // 2ByteҪ���ӵ�ֵ
        BYTE     byRes[24];
    } USB_M1_BLOCK_OPER, *LPUSB_M1_BLOCK_OPER; //32�ֽ�

    typedef struct tagUSB_M1_BLOCK_OPER_RES
    {
        DWORD    dwSize;
        WORD     wSuccessNum;// 2Byte ʵ�ʳɹ�����
        BYTE     byRes[26];
    } USB_M1_BLOCK_OPER_RES, *LPUSB_M1_BLOCK_OPER_RES; //32�ֽ�

    typedef struct tagUSB_M1_MF_PACK
    {
        DWORD    dwSize;
        BYTE     byBufLen; //���ݳ��ȣ�0-255��
        BYTE     byRes1[3]; //�����ֽ�
        BYTE     byBuf[255];//����
        BYTE     byRes2; //�����ֽ�
        BYTE     byDelay; //�ӳ�ʱ�䣨��λ10ms��,0ΪĬ��ֵ��2000ms��(����SDKĬ�ϳ�ʱʱ��5�룬���ʱ��Ӧ������5��)
        BYTE     byRes[55];
    } USB_M1_MF_PACK, *LPUSB_M1_MF_PACK; //320�ֽ�

    typedef struct tagUSB_SDK_M1_SECTION_ENCRYPT
    {
        DWORD   dwSize;              //�ṹ���С
        BYTE    bySectionID;         //����ID
        BYTE    byKeyType;           //��֤��Կ���ͣ�0-������Կ��1-����������Կ
        BYTE    byKeyAContent[6];    //��֤��Կ�����������֤��Կ����Ϊ1ʱ��Ч
        BYTE    byNewKeyType;        //����Կ���ͣ�0-������Կ��1-����������Կ
        BYTE    byRes1;              //�����ֽ�
        BYTE    byNewKeyAContent[6]; //����ԿA�������������Կ����Ϊ1ʱ��Ч
        BYTE    byCtrlBits[4];       //����λ������Կ����Ϊ1ʱ��Ч
        BYTE    byNewKeyBContent[6]; //����ԿB�������������Կ����Ϊ1ʱ��Ч
        BYTE    byRes[34];
    } USB_SDK_M1_SECTION_ENCRYPT, *LPUSB_SDK_M1_SECTION_ENCRYPT; //64�ֽ�

    typedef struct tagUSB_SDK_M1_SECTION_ENCRYPT_RES
    {
        DWORD   dwSize;      //�ṹ���С
        BYTE    byStatus;    //�ɹ�����0��ʧ��ʱ����1-������֤��Կʧ�ܣ�2-��������Կʧ��
        BYTE    byRes[27];
    } USB_SDK_M1_SECTION_ENCRYPT_RES, *LPUSB_SDK_M1_SECTION_ENCRYPT_RES; //32�ֽ�

    typedef struct tagUSB_PSAM_SEAT_INFO
    {
        DWORD   dwSize;
        BYTE    bySeat;// 1Byte PSAM������ţ�0- ����1��1-����2��
        BYTE    byRes[27];
    } USB_PSAM_SEAT_INFO, *LPUSB_PSAM_SEAT_INFO; //32�ֽ�

    typedef struct tagUSB_CARD_PARAM
    {
        DWORD   dwSize;
        BYTE    byCardType; // 1Byte������(0-13.56��ƵCPU����1-PSAM����1,2-PSAM����2)
        BYTE    byCardProto; // 1Byte��Э�����ͣ�0ΪT=0��1ΪT=1��
        BYTE    byRes[26];
    } USB_CARD_PARAM, *LPUSB_CARD_PARAM; //32�ֽ�

    typedef struct tagUSB_CPU_CARD_RESET_RES
    {
        DWORD    dwSize;
        BYTE     byBufLen;//byBuf����Ч���ݳ��ȣ�0-60��
        BYTE     byRes1[3]; //�����ֽ�
        BYTE     byBuf[60];//��һ���ǳ�����Ϣ��
        BYTE     byRes[28]; //�����ֽ�
    } USB_CPU_CARD_RESET_RES, *LPUSB_CPU_CARD_RESET_RES; //96�ֽ�

    typedef struct tagUSB_CPU_CARD_PACK
    {
        DWORD    dwSize;
        BYTE     byBufLen; //0-255
        BYTE     byRes1[3]; //�����ֽ�
        BYTE     byBuf[255];
        BYTE     byDelay; //�ӳ�ʱ�䣨��λ10ms����0ΪĬ�ϣ�200ms��
        BYTE     byRes[56]; //�����ֽ�
    } USB_CPU_CARD_PACK, *LPUSB_CPU_CARD_PACK; //320�ֽ�

    typedef struct tagUSB_CERTIFICATE_INFO
    {
        DWORD  dwSize; //�ṹ���С
        WORD   wWordInfoSize; //������Ϣ����
        WORD   wPicInfoSize; //��Ƭ��Ϣ����
        WORD   wFingerPrintInfoSize; //ָ����Ϣ����
        BYTE   byCertificateType; //֤�����ͣ�0-����֤��1-�й��̿���2-�۰�̨��������֤��3-�й��̿����£�
        BYTE   byRes2;
        BYTE   byWordInfo[WORD_LEN/*256*/]; //������Ϣ
        BYTE   byPicInfo[PIC_LEN/*1024*/]; //��Ƭ��Ϣ
        BYTE   byFingerPrintInfo[FINGER_PRINT_LEN/*1024*/]; //ָ����Ϣ
        BYTE   byRes[40];
    } USB_CERTIFICATE_INFO, *LPUSB_CERTIFICATE_INFO;

    typedef struct tagUSB_IDENTITY_INFO_CFG
    {
        DWORD  dwSize; //�ṹ���С
        WORD   wPicInfoSize; //��Ƭ��Ϣ����
        WORD   wFingerPrintInfoSize; //ָ����Ϣ����
        BYTE    byPicInfo[PIC_LEN/*1024*/]; //����֤ͼƬ��Ϣ
        BYTE    byFingerPrintInfo[FINGER_PRINT_LEN/*1024*/]; //ָ����Ϣ
        BYTE    byRes[256];
    } USB_IDENTITY_INFO_CFG, *LPUSB_IDENTITY_INFO_CFG;

    typedef struct tagUSB_CERTIFICATE_ADD_ADDR_INFO
    {
        DWORD  dwSize; //�ṹ���С
        WORD   wAddrInfoSize; //׷��סַ��Ϣ����
        BYTE   byAddAddrInfo[ADDR_LEN/*128*/]; //׷��סַ��Ϣ
        BYTE   byRes[40];
    } USB_CERTIFICATE_ADD_ADDR_INFO, *LPUSB_CERTIFICATE_ADD_ADDR_INFO;

    typedef struct tagUSB_EXTERNAL_DEV_INFO
    {
        DWORD  dwSize;   //�ṹ���С
        char      szFPModuleSoftVersion[FINGER_PRINT_MODULE_VERSION_LEN/*32*/]; //ָ��ģ�������汾����
        char      szFPModuleSerialNumber[FINGER_PRINT_MODULE_SERIAL_LEN/*64*/]; //ָ��ģ�����кų���
        char      szSecurityModuleSerialNumber[SECURITY_MODULE_SERIAL_LEN/*16*/]; //��ȫģ�����кų���
        BYTE     byRes[140];
    } USB_EXTERNAL_DEV_INFO, *LPUSB_EXTERNAL_DEV_INFO; //256�ֽ�

    typedef struct tagUSB_FINGER_PRINT_OPER_PARAM
    {
        DWORD  dwSize;   //�ṹ���С
        BYTE    byFPCompareType; //ָ�Ʊȶ�ģʽ��0-���ȶԣ�Ĭ�ϣ���1-�豸�ڲ��ȶԣ�Ĭ�ϣ���2-ƽ̨���ͻ��ˣ��ȶ�
        BYTE    byFPCaptureType; //ָ�Ʋɼ����ͣ�1-ģ�壨Ĭ�ϣ���2-ͼƬ��byFPCompareTypeΪ2ʱ��Ч��
        BYTE    byFPCompareTimeout; //�豸�ڲ�ָ�ƱȶԳ�ʱʱ�䣺1-255s��Ĭ��5s����byFPCompareTypeΪ1ʱ��Ч��
        BYTE    byFPCompareMatchLevel; //�豸�ڲ�ָ�Ʊȶ�ƥ��ȼ���1-5��Ĭ��3����byFPCompareTypeΪ1ʱ��Ч��
        BYTE    byRes[24];
    } USB_FINGER_PRINT_OPER_PARAM, *LPUSB_FINGER_PRINT_OPER_PARAM; //32�ֽ�

    typedef struct tagUSB_FINGER_PRINT_COND
    {
        DWORD  dwSize;   //�ṹ���С
        BYTE    byWait; //�����ȴ�ʱ�䣨��Χ10s-60s��������ʱĬ��Ϊ60s��
        BYTE    byFPType; //ָ�����ͣ�1-ģ�壬2-ͼƬ
        BYTE    byRes[26];
    } USB_FINGER_PRINT_COND, *LPUSB_FINGER_PRINT_COND; //32�ֽ�

    typedef struct tagUSB_FINGER_PRINT
    {
        DWORD  dwSize; //�ṹ���С
        DWORD  dwFPBufferSize; //ָ�ƻ����С
        char*  pFPBuffer; //ָ�ƻ���
        DWORD  dwFPSize; //ָ�ƴ�С
        BYTE    byFPType; //ָ�����ͣ�1-ģ�壬2-ͼƬ��90k���ң�
        BYTE    byResult; //�ɼ������1-�ɼ��ɹ���2-�ɼ�ʧ�ܣ�3-�ɼ���ʱ��4-ָ��ͼ��������
        BYTE    byFPTemplateQuality; //ָ��ģ��������0-100��byFPTypeΪ1-ģ��ʱ��Ч��
        BYTE    byRes[13];
    } USB_FINGER_PRINT, *LPUSB_FINGER_PRINT; //32�ֽ�

    typedef struct tagUSB_FINGER_PRINT_CONTRAST_RESULT
    {
        DWORD  dwSize;   //�ṹ���С
        BYTE    byResult; //�ȶԽ����1-�ȶԳɹ���2-�ȶ�ʧ�ܣ�3-�ȶԳ�ʱ��4-ָ��ͼ�������5-����ָ������֮���1:1�ȶ�ʧ�ܣ�6-���ָ������������ʧ�ܣ�7-����ָ������ʧ��
        BYTE    byFPTemplateQuality; //ָ��ģ��������0-100
        BYTE    byRes[26];
    } USB_FINGER_PRINT_CONTRAST_RESULT, *LPUSB_FINGER_PRINT_CONTRAST_RESULT; //32�ֽ�

    typedef struct tagUSB_CERTIFICATE_MAC
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byMac[MAC_LEN/*16*/]; //�������к�
        BYTE   byRes[40];
    } USB_CERTIFICATE_MAC, *LPUSB_CERTIFICATE_MAC;

    typedef struct tagUSB_IC_CARD_NO
    {
        DWORD  dwSize; //�ṹ���С
        BYTE    byCardNo[CARD_NO_LEN/*32*/]; //IC������
        BYTE    byRes[40];
    } USB_IC_CARD_NO, *LPUSB_IC_CARD_NO;

    typedef struct tagUSB_DETECT_CARD_COND
    {
        DWORD  dwSize;   //�ṹ���С
        BYTE    byWait; // 1BYTE�����ȴ�ʱ�䣨0-һֱִ��ֱ���п���Ӧ��������Ӧ1S��λ��
        BYTE    byRes[27];
    } USB_DETECT_CARD_COND, *LPUSB_DETECT_CARD_COND; //32�ֽ�

    typedef struct tagUSB_DETECT_CARD_CFG
    {
        DWORD  dwSize; //�ṹ���С
        BYTE    byCardStatus; //��Ƭ״̬��0-δ��⵽��1-��⵽
        BYTE    byRes[27];
    } USB_DETECT_CARD_CFG, *LPUSB_DETECT_CARD_CFG; //32�ֽ�

    typedef struct tagUSB_CPU_CARD_ENCRYPT
    {
        DWORD  dwSize;    //�ṹ���С
        BYTE    byCardType;    //�����ͣ�0-��Ч��1-�׿�����ԿΪ8�ֽ�0xFF����2-����CPU����3-�����Ѽ��ܿ�Ƭ
        BYTE    byKeyLength;    //MF�ⲿ��֤����Կ���ȣ�byCardTypeΪ3-�����Ѽ��ܿ�Ƭʱ�����ֶ���Ч��
        BYTE    byRes2[2];
        BYTE    byKeyContent[16];    //MF�ⲿ��֤����Կ���ݣ�byCardTypeΪ3-�����Ѽ��ܿ�Ƭʱ�����ֶ���Ч��
        BYTE    byRes[40];
    } USB_CPU_CARD_ENCRYPT, *LPUSB_CPU_CARD_ENCRYPT; //64�ֽ�

    typedef struct tagUSB_CPU_CARD_ENCRYPT_RES
    {
        DWORD  dwSize;    //�ṹ���С
        BYTE    byTryTimes;    //ʣ��ɳ��Դ�����255������Ч�������óɹ�ʱ������255������ʧ��ʱ�����ؾ����ʣ��ɳ��Դ���
        BYTE    byRes[27];
    } USB_CPU_CARD_ENCRYPT_RES, *LPUSB_CPU_CARD_ENCRYPT_RES; //32�ֽ�

    typedef struct tagUSB_M1_SECTION_ENCRYPT
    {
        DWORD   dwSize;              //�ṹ���С
        BYTE    bySectionID;         //����ID
        BYTE    byKeyType;           //��֤��Կ���ͣ�0-������Կ��1-����������Կ
        BYTE    byKeyAContent[6];    //��֤��Կ�����������֤��Կ����Ϊ1ʱ��Ч
        BYTE    byNewKeyType;        //����Կ���ͣ�0-������Կ��1-����������Կ
        BYTE    byRes1;              //�����ֽ�
        BYTE    byNewKeyAContent[6]; //����ԿA�������������Կ����Ϊ1ʱ��Ч
        BYTE    byCtrlBits[4];       //����λ������Կ����Ϊ1ʱ��Ч
        BYTE    byNewKeyBContent[6]; //����ԿB�������������Կ����Ϊ1ʱ��Ч
        BYTE    byRes[34];
    } USB_M1_SECTION_ENCRYPT, *LPUSB_M1_SECTION_ENCRYPT; //64�ֽ�

    typedef struct tagUSB_M1_SECTION_ENCRYPT_RES
    {
        LONG    dwSize;      //�ṹ���С
        BYTE    byStatus;    //�ɹ�����0��ʧ��ʱ����1-������֤��Կʧ�ܣ�2-��������Կʧ��
        BYTE    byRes[27];
    } USB_M1_SECTION_ENCRYPT_RES, *LPUSB_M1_SECTION_ENCRYPT_RES; //32�ֽ�

    typedef struct tagUSB_ACTIVE_STATUS
    {
        DWORD  dwSize;
        BYTE   byState; //0-�Ѽ��� 1-δ����
        BYTE   byRes[7];
    } USB_ACTIVE_STATUS, *LPUSB_ACTIVE_STATUS; //12�ֽ�


    /**@struct USB_CONFIG
    *  @brief  �����Ƶ���������ṹ��
    *
    *
    */
    typedef struct tagUSB_VIDEO_CAPACITY
    {
        char         nIndex;
        char         nType;					 // �������ͣ�USBCamera_H264��USBCamera_MJPEG��USBCamera_RGB24�ȣ�
        int          dwWidth;				 // ͼ�����
        int          dwHeight;				 // ͼ��߶�
        long         lListSize;				 // ֧�ֵ�֡�ʵĸ���
        INT64        lFrameRates[50];		 // ֧�ֵ�֡��(50�㹻��)
    } USB_VIDEO_CAPACITY, *LPUSB_VIDEO_CAPACITY;

    typedef struct tagUSB_AUDIO_PARAM
    {
        WORD        wFormatTag;         /* format type */
        WORD        nChannels;          /* number of channels (i.e. mono, stereo...) */
        DWORD       nSamplesPerSec;     /* sample rate */
        DWORD       nAvgBytesPerSec;    /* for buffer estimation */
        WORD        nBlockAlign;        /* block size of data */
        WORD        wBitsPerSample;     /* number of bits per sample of mono data */
        WORD        cbSize;             /* the count in bytes of the size of */
        /* extra information (after cbSize) */
    } USB_AUDIO_PARAM, *LPUSB_AUDIO_PARAM;

    typedef struct tagUSB_VIDEO_PARAM
    {
        DWORD dwVideoFormat; //��Ƶ������ʽ
        DWORD dwWidth;//�ֱ��ʿ�
        DWORD dwHeight;//�ֱ��ʸ�
        DWORD dwFramerate;//֡��
        DWORD dwBitrate;//������
        DWORD dwParamType; //ͼ���������
        DWORD dwValue; //ͼ�����ֵ
        BYTE byRes[128];//�����ֽ�
    } USB_VIDEO_PARAM, *LPUSB_VIDEO_PARAM;

	typedef struct tagUSB_PROPERTY
	{
        long dwMin;						//��Сֵ
        long dwMax;						//���ֵ
        long dwStep;					//����
        long dwDef;						//Ĭ��ֵ
		BYTE byEnabled;					//�Ƿ�֧�֣�0-��֧�֣�1-֧�֣�2-�ֶ���3-�Զ�
        BYTE byRes[7];
	} USB_PROPERTY, *LPUSB_PROPERTY;

	typedef struct tagUSB_VIDEO_PROPERTY_CAP
	{
		USB_PROPERTY struBrightness;			//����
		USB_PROPERTY struContrast;				//�Աȶ�
		USB_PROPERTY struHue;					//ɫ��
		USB_PROPERTY struSaturation;			//���Ͷ�
		USB_PROPERTY struSharpness;				//������
		USB_PROPERTY struGamma;					//٤��
		USB_PROPERTY struColorEnable;			//������ɫ
		USB_PROPERTY struWhiteBalance;			//��ƽ��
		USB_PROPERTY struBacklightCompensation;	//���Ա�
		USB_PROPERTY struGain;					//����
		USB_PROPERTY struPowerlineFrequency;	//������Ƶ��
		USB_PROPERTY struPan;					//ȫ��
		USB_PROPERTY struTilt;					//��б
		USB_PROPERTY struRoll;					//����
		USB_PROPERTY struZoom;					//����
		USB_PROPERTY struExposure;				//�ع�
		USB_PROPERTY struIris;					//��Ȧ
		USB_PROPERTY struFocus;					//����
		USB_PROPERTY struLowBrightnessCompensation;//�����Ȳ���
		BYTE		 byRes[128];				//�����ֽ�
	} USB_VIDEO_PROPERTY_CAP, *LPUSB_VIDEO_PROPERTY_CAP;

    typedef struct tagUSB_VIDEO_PROPERTY
    {
        long dwValue;
        BYTE byFlag;        //SET����ʾ����ģʽ��1-�Զ���2-�ֶ�
                            //GET�������豸������1-֧���Զ����ֶ���2-ֻ֧���ֶ�
        BYTE byRes[31];
    } USB_VIDEO_PROPERTY, *LPUSB_VIDEO_PROPERTY;

    typedef struct tagUSB_SRC_STREAM_CFG
    {
        DWORD  dwStreamType;	// ԭʼ��������(MJPEG/H264/YUV)
        BYTE   bUseAudio;      // �Ƿ�ʹ����Ƶ 0-��ʹ�ã�1-ʹ��
        BYTE   byRes[4];
    }USB_SRC_STREAM_CFG, *LPUSB_SRC_STREAM_CFG;

    /**	@struct USB_EVENT_CALLBACK_PARAM
    *  @brief   �¼��ص������ṹ��
    *
    */
    typedef struct tagUSB_EVENT_CALLBACK_PARAM
    {
        fnEventCallBack funcEventCallBack;
        void*           pUser;
        unsigned char   byRes[20];
    } USB_EVENT_CALLBACK_PARAM, *LPUSB_EVENT_CALLBACK_PARAM;


    typedef struct tagUSB_ROTATE_ANGLE_INFO
    {
        LONG   dwType;  // -1(����ת)  0(������ת90��)  1(������ת90��)  2(��ת180��)
        BYTE   byRes[124];
    }USB_ROTATE_ANGLE_INFO, *LPUSB_ROTATE_ANGLE_INFO;

    typedef struct tagUSB_COMMAND_STATE
    {
        DWORD  dwSize;
        BYTE   byState; // �μ����ô���״̬��
        //#define  USB_ERROR_NO_ERROR                                0x00    // No error: The request succeeded
        //#define  USB_ERROR_DEVICE_REQUEST_NOT_COMPLETE             0x01    // Not Ready: Previous request has not completed
        //#define  USB_ERROR_DEVICE_WRONG_STATE                      0x02    // Wrong State: In a state that disallows the specific request
        //#define  USB_ERROR_DEVICE_MODE_ERROR                       0x03    // Power: Current power mode is not sufficient to complete the request
        //#define  USB_ERROR_SET_PARAM_OVERLIMIT                     0x04    // Out of Range: SET_CUR over limits
        //#define  USB_ERROR_UNITID_NOT_SUPPORT                      0x05    // Invalid Unit: Unit ID not supported
        //#define  USB_ERROR_CSID_NOT_SUPPORT                        0x06    // Invalid Control: CS ID not supported
        //#define  USB_ERROR_REQUEST_TYPE_NOT_SUPPORT                0x07    // Invalid Request: request type not supported
        //#define  USB_ERROR_SET_PARAM_INVALID                       0x08    // Invalid value with range: SET_CUR invalid value with range
        //#define  USB_ERROR_SUBFUNCTION_NOT_SUPPORT                 0x09    // Custom: Sub-function not supported
        //#define  USB_ERROR_DEVICE_EXECUTE_EXCEPTION                0x0a    // Custom: Device inner executing exceptions
        //#define  USB_ERROR_DEVICE_PROTOCOL_EXCEPTION               0x0b    // Custom: Device inner processing protocol exceptions
        //#define  USB_ERROR_BULK_DATA_EXCEPTION                     0x0c    // Custom: Bulk data transfer process exceptions
        //#define  USB_ERROR_UNKNOWN                                 0xff    // Unknown: Unknown
        BYTE   byRes[3];
    } USB_COMMAND_STATE, *LPUSB_COMMAND_STATE; //8�ֽ�

	typedef struct tagUSB_GET_DEVICE_COUNT_INFO
	{
		BYTE   bySeparate;		// 0-�����룬1-����Ƶ����
		BYTE   byIncludeAll;	// 0-ö��HIK��1-ö�ٰ���������
	}USB_GET_DEVICE_COUNT_INFO, *LPUSB_GET_DEVICE_COUNT_INFO;

    //�豸SVC����
    typedef struct tagUSB_SYSTEM_DEVICE_CAPABILITIES
    {
        BYTE    byIsSupportSVC;     //�Ƿ�֧��SVC��0-��֧�֣�1-֧��
        BYTE    byRes[31];
    }USB_SYSTEM_DEVICE_CAPABILITIES, *LPUSB_SYSTEM_DEVICE_CAPABILITIES;

    //SVC��������Ϣ
    typedef struct tagUSB_IMAGE_VIDEO_SVC_MULTIPLE_STREAM
    {
        BYTE    byMultipleStreamNum;//SVC������֧��·��
        BYTE    byRes[31];
    }USB_IMAGE_VIDEO_SVC_MULTIPLE_STREAM, *LPUSB_IMAGE_VIDEO_SVC_MULTIPLE_STREAM;

    //���ܹ��ܿ���
    typedef struct tagUSB_VCA_SWITCH
    {
        BYTE    byChannelID;        //��Ƶͨ����
        BYTE    byDetectEnabled;    //�Ƿ���Ŀ���⣬0-�رգ�1-����
        BYTE    byIdentifyEnabled;  //�Ƿ���Ŀ��ʶ��0-�رգ�1-����
        BYTE    byRes[29];
    } USB_VCA_SWITCH, *LPUSB_VCA_SWITCH;

    //����ץͼ
    typedef struct tagUSB_VCA_SNAPSHOT
    {
        BYTE    byChannelID;        //��Ƶͨ����
        BYTE    bySnapshotMode;     //ץͼģʽ��1-����ץͼ��2-ʶ���ץͼ��3-��ģץͼ��4-ץȥԭʼͼƬ
        BYTE    byCaptureInterval;  //ץͼʱ����
        BYTE    byRes[32];
    } USB_VCA_SNAPSHOT, *LPUSB_VCA_SNAPSHOT;

    //����Ŀ��ʶ�����ƶ���ֵ
    typedef struct tagUSB_VCA_FACE_THRESHOLD
    {
        BYTE    byChannelID;        //��Ƶͨ����
        BYTE    byThresholdValue;   //���ƶ���ֵ
        BYTE    byRes[30];
    } USB_VCA_FACE_THRESHOLD, *LPUSB_VCA_FACE_THRESHOLD;

    //����ʶ����������
    typedef struct tagUSB_VCA_FACE_ATTRIBUTES
    {
        BYTE    byChannelID;        //��Ƶͨ����
        BYTE    byEnabled;          //���Կ��أ�0-�رգ�1-����
        BYTE    byFaceExpression;   //���飬1-��ŭ��2-���3-���ˣ�4-���£�5-���ȣ�6-�ѹ���7-δ֪
        BYTE    byAge;              //����
        BYTE    byGender;           //�Ա�1-�У�2-Ů��3-δ֪
        BYTE    byGlass;            //�۾���0-δ���۾���1-���۾�
        BYTE    byRes[30];
    } USB_VCA_FACE_ATTRIBUTES, *LPUSB_VCA_FACE_ATTRIBUTES;

    //��������������
    typedef struct tagUSB_VCA_FACE_DETECT_RULE
    {
        BYTE    byChannelID;        //��Ƶͨ��
        BYTE    bySensitivity;      //���������
        BYTE    byObjGenerateRate;  //Ŀ�������ٶ�
        BYTE    byRes1;
        DWORD   dwRegionX;          //�������϶���X���꣬��һ��ֵ����Χ0 - 1000
        DWORD   dwRegionY;          //�������϶���Y���꣬��һ��ֵ����Χ0 - 1000
        DWORD   dwRegionWidth;      //������ȣ���һ��ֵ����Χ0 - 1000
        DWORD   dwRegionHeight;     //����߶ȣ���һ��ֵ����Χ0 - 1000
        BYTE    byRes[32];
    } USB_VCA_FACE_DETECT_RULE, *LPUSB_VCA_FACE_DETECT_RULE;

    //�������������������
    typedef struct tagUSB_VCA_FACE_QUALITY
    {
        BYTE    byChannelID;        //��Ƶͨ��
        BYTE    byLeftAngle;        //�������ұ�ת�ĽǶ�[0, 90]
        BYTE    byRightAngle;       //���������ת�ĽǶ�[0, 90]
        BYTE    byUpAngle;          //�������ϵĽǶ�[0, 90]
        BYTE    byDownAngle;        //�������µĽǶ�[0, 90]
        BYTE    byPupilDistance;    //ͫ��
        BYTE    byScore;            //������ֵ[20, 100]
        BYTE    byShelterType;      //�ڵ����ͣ�1-���ڵ���2-˲ʱ��ȣ�3-�̶���ȣ�4-����
        BYTE    byRes[32];
    } USB_VCA_FACE_QUALITY, *LPUSB_VCA_FACE_QUALITY;

    //ͼƬ���ؽ�ģ
    typedef struct tagUSB_VCA_PIC_DOWNLOAD
    {
        BYTE    byId;               //ͼƬ���
        BYTE    byType;             //ͼƬ���ͣ�1-JPEG��2-PNG��3-BMP
        BYTE    byPicWidth;         //ͼƬ������ֵ0��ʾ����Ӧ
        BYTE    byPicHeight;        //ͼƬ�ߣ���ֵ0��ʾ����Ӧ
        BYTE    byPicSize;          //ͼƬ��С
        BYTE    byName[16];         //ͼƬ��Ӧ����
        BYTE    byPost[16];         //ͼƬ��Ӧ��Աְλ
        BYTE    byRes[32];
    } USB_VCA_PIC_DOWNLOAD, *LPUSB_VCA_PIC_DOWNLOAD;

    //�����׿���������
    typedef struct tagUSB_VCA_FACE_BASE_DATA_CFG
    {
        BYTE    byId;               //ͼƬ���
        BYTE    byOperateType;      //�������ͣ�1-��ȡ��2-ɾ����3-�޸�
        BYTE    byRes1[2];
        BYTE    byName[16];         //ͼƬ��Ӧ����
        BYTE    byPost[16];         //ͼƬ��Ӧ��Աְλ
        BYTE    byRes[32];
    } USB_VCA_FACE_BASE_DATA_CFG, *LPUSB_VCA_FACE_BASE_DATA_CFG;

    //������������
    typedef struct tagUSB_VCA_ELECTRONICSIGNAGE_CFG
    {
        BYTE    byChannelID;        //��Ƶͨ��
        BYTE    byEnabled;          //���������Ƿ�����0-�رգ�1-����
        BYTE    byFontColor;        //��ɫ
        BYTE    byFontType;         //���壺1-���壬2-����
        BYTE    byRes[32];
    } USB_VCA_ELECTRONICSIGNAGE_CFG, *LPUSB_VCA_ELECTRONICSIGNAGE_CFG;

    //������Ϣ
    typedef struct tagUSB_VCA_FACE_INFO
    {
        DWORD   dwRegionX;          //�������϶���X���꣬��һ��ֵ����Χ0 - 1000
        DWORD   dwRegionY;          //�������϶���Y���꣬��һ��ֵ����Χ0 - 1000
        DWORD   dwRegionWidth;      //������ȣ���һ��ֵ����Χ0 - 1000
        DWORD   dwRegionHeight;     //����߶ȣ���һ��ֵ����Χ0 - 1000
    } USB_VCA_FACE_INFO, *LPUSB_VCA_FACE_INFO;

    //�������������Ϣ
    typedef struct tagUSB_VCA_FACE_DETECT
    {
        BYTE    byChannelID;        //��Ƶͨ��
        BYTE    byDetFaceNum;       //��ǰͼ���м�⵽��������Ŀ
        BYTE    byRes1[2];
        USB_VCA_FACE_INFO struFaceInfo[16];
        BYTE    byRes[32];
    } USB_VCA_FACE_DETECT, *LPUSB_VCA_FACE_DETECT;

    //�����ȶ���Ϣ
    typedef struct tagUSB_VCA_FACE_CONTRAST
    {
        BYTE    byChannelID;        //��Ƶͨ��
        BYTE    byId;               //��ǰ������
        BYTE    byFPID;             //��ǰ�����ڵ׿��е����
        BYTE    byRes1;
        BYTE    byName[16];         //ʶ�������������
        BYTE    byPost[16];         //ʶ���������ְλ
        BYTE    byRes[32];
    } USB_VCA_FACE_CONTRAST, *LPUSB_VCA_FACE_CONTRAST;

	typedef struct  tagUSB_OSD_INFO
	{
		WORD    wLineNums;
        UINT    uiWinWidth; // Window width of OSD
        UINT    uiWinHeight; //Window height of OSD
        BYTE    byRes[128];
	}USB_OSD_INFO, *LPUSB_OSD_INFO;

	typedef struct tagUSB_OSD_LINE
	{
        UINT    uiOffsetx;//For the x coordinate of the OSD
        UINT    uiOffsety;//For the y coordinate of the OSD
        BYTE    szOsdString[44];//
        BYTE    byRes[48];
	}USB_OSD_LINE, *LPUSB_OSD_LINE;

	typedef struct tagUSB_OSD
	{
		BYTE         byEnabled; //OSD�Ƿ�����0-�رգ�1-����
		USB_OSD_INFO struOsdInfo;
		USB_OSD_LINE struOsdLineList[32];
        BYTE         byRes[1024];
	}USB_OSD, *LPUSB_OSD;

	typedef enum tagUSB_LOCAL_CFG_TYPE
	{
        ENUM_LOCAL_CFG_TYPE_LOAD_PATH = 0, //(USB_Initǰ����)���ض�̬��·�����ã���Ӧ�ṹ��USB_LOCAL_LOAD_PATH
        ENUM_LOCAL_CFG_TYPE_GUID, //(USB_Init�����)����GUID���ã���Ӧ�ṹ��USB_LOCAL_GUID  �ṹ����������չID�������ж���
        ENUM_LOCAL_CFG_TYPE_FONT_PATH,   //���������ļ�·����ֻ֧��Linux
        ENUM_LOCAL_CFG_TYPE_FACE_DETECT //(USB_Initǰ����)�������������Դ��Linux��ʹ��,win��android��֧�֣�
	}USB_LOCAL_CFG_TYPE;

	//���ö�̬��·����Ҫ���ļ��� 
	typedef enum tagUSB_DLL_TYPE
	{
        ENUM_DLL_SSL_PATH = 1, //����OpenSSL��ssleay32.dll/libssl.so/libssl.dylib����·��
        ENUM_DLL_CRYPTO_PATH = 2, //����OpenSSL��libeay32.dll/libcrypto.so/libcrypto.dylib����·��
        ENUM_DLL_SYSTEMTRANSFORM_PATH = 3, //����ת��װ��·��
        ENUM_DLL_LIBUSB_PATH = 4, //����LIBUSB��·��
        ENUM_DLL_PLAYCTRL_PATH = 5, //���ò��ſ�·��
        ENUM_DLL_FORMATCONVERSION_PATH = 6, //����ת���·��
        ENUM_DLL_LIBUVC_PATH = 8
	} USB_DLL_TYPE;

	typedef struct tagUSB_LOCAL_LOAD_PATH
	{
        USB_DLL_TYPE emType; //���ؿ������
        BYTE         byLoadPath[MAX_FILE_PATH_LEN];
		BYTE         byRes[128]; //�����ֽ�
	}USB_LOCAL_LOAD_PATH, *LPUSB_LOCAL_LOAD_PATH;

    typedef struct _USB_GUID {
        ULONG    ulData1;
        WORD     wData2;
        WORD     wData3;
        BYTE     byData4[8];
    }USB_GUID, *LPUSB_GUID;

	typedef struct tagUSB_LOCAL_GUID
	{
        ULONG    ulVID; //��Ӧ��ID
        ULONG    ulPID;//��Ʒʶ����
        USB_GUID struGuid; //GUID
		BYTE     byRes[128];                //�����ֽ�
	}USB_LOCAL_GUID, *LPUSB_LOCAL_GUID;

    typedef struct tagUSB_LOCAL_FONT_PATH
    {
        BYTE    byLoadPath[MAX_FILE_PATH_LEN];
        BYTE    byRes[128]; //�����ֽ�
    }USB_LOCAL_FONT_PATH, *LPUSB_LOCAL_FONT_PATH;

    typedef struct tagUSB_DEVICE_VERSION
    {
        DWORD   dwSize;   //�ṹ���С
        BYTE    byDeviceName[MAX_DEVICE_NAME_LEN/*32*/]; //�豸����
        BYTE    bySerialNumber[MAX_SERIAL_NUMBER_LEN/*48*/]; //�豸���к�
        BYTE    bySoftwareVersion[MAX_DEVICE_NAME_LEN]; //�豸�汾
        BYTE    byRes[44];
    } USB_DEVICE_VERSION, *LPUSB_DEVICE_VERSION;  //160�ֽ�

    typedef struct tagUSB_FILE_TRANSFER_INFO
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byLocalFileName[MAX_FILE_PATH_LEN]; //�ļ�·�� + �ļ�����    Ҫ�ϴ��ı����ļ�
        BYTE   byRemoteFileName[MAX_FILE_PATH_LEN]; //�ļ�·�� + �ļ�����   �ϴ����豸�ĸ�·����
        BYTE   byRes[1024];
    } USB_FILE_TRANSFER_INFO, *LPUSB_FILE_TRANSFER_INFO;

    typedef struct tagUSB_FILE_TRANSFER_PROGRESS_INFO
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byState; //״ֵ̬��ö��USB_FILE_TRANSFER_STATE
        BYTE   byProgress;
        BYTE   byRes[1024];
    } USB_FILE_TRANSFER_PROGRESS_INFO, *LPUSB_FILE_TRANSFER_PROGRESS_INFO;

    typedef enum tagUSB_FILE_TRANSFER_STATE
    {
        USB_FILE_TRANSFERING = 0,  //-�ļ�������
        USB_FILE_TRANSFER_FAIL,    //-�ļ�����ʧ��
        USB_FILE_TRANSFER_SUCC,    //-�ļ�����ɹ�
    }USB_FILE_TRANSFER_STATE;

    //��׼�����������ݽṹ��
    typedef struct tagUSB_CONTROL_TRANSFER_DATA{
        BYTE byRequestType;
        BYTE byRequest;
        BYTE byRes[2];
        WORD wValue;
        WORD wIndex;
        char* pData;
        DWORD dwDataLen;
        DWORD dwTimeout;
        BYTE byRes2[1024];
    } USB_CONTROL_TRANSFER_DATA, *LPUSB_CONTROL_TRANSFER_DATA;

    typedef struct tagUSB_PRIVATE_UVC_CABABILITIES
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   bySupportSoftwareVersion; //�Ƿ�֧�� �����汾�ţ�0-��֧�֣�1-֧��
        BYTE   bySupportPNSwitch;        //�Ƿ�֧�� PN���л���0-��֧�֣�1-֧��
        BYTE   bySupportImageMode;       //�Ƿ�֧�� ͼ��ģʽ��0-��֧�֣�1-֧��
        BYTE   bySupportImageFlip;       //�Ƿ�֧�� ����0-��֧�֣�1-֧��
        BYTE   bySupportWDR;             //�Ƿ�֧�� ����̬��0-��֧�֣�1-֧��
        BYTE   bySupportNoiseReduce;     //�Ƿ�֧�� ���룺0-��֧�֣�1-֧��
        BYTE   bySupportWhiteBalance;    //�Ƿ�֧�� ��ƽ�⣺0-��֧�֣�1-֧��
        BYTE   bySupportGamut;           //�Ƿ�֧�� ɫ��0-��֧�֣�1-֧��
        BYTE   bySupportShutter;         //�Ƿ�֧�� ���ţ�0-��֧�֣�1-֧��
        BYTE   bySupportBeauty;          //�Ƿ�֧�� ���գ�0-��֧�֣�1-֧��
        BYTE   bySupportFaceAE;          //�Ƿ�֧�� FaceAE��0-��֧�֣�1-֧��
        BYTE   bySupportFocusSensitivity;//�Ƿ�֧�� �۽������ȣ�0-��֧�֣�1-֧��
        BYTE   bySupportFaceCentered;    //�Ƿ�֧�� �������У�0-��֧�֣�1-֧��
        BYTE   bySupportSpokesmanTrack;  //�Ƿ�֧�� �����˸��٣�0-��֧�֣�1-֧��
        BYTE   byRes1[2];
        BYTE   byRes[128];
    } USB_PRIVATE_UVC_CABABILITIES, *LPUSB_PRIVATE_UVC_CABABILITIES;

    typedef struct tagUSB_PRIVATE_UAC_CABABILITIES
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   bySupportSoftwareVersion; //�Ƿ�֧�� �����汾�ţ�0-��֧�֣�1-֧��
        BYTE   bySupportAEC;             //�Ƿ�֧�� ����������0-��֧�֣�1-֧��
        BYTE   bySupportNoiseReduce;     //�Ƿ�֧�� ���룺0-��֧�֣�1-֧��
        BYTE   bySupportPickUp;          //�Ƿ�֧�� ��Ƶʰ����0-��֧�֣�1-֧��
        BYTE   byRes[128];
    } USB_PRIVATE_UAC_CABABILITIES, *LPUSB_PRIVATE_UAC_CABABILITIES;

    typedef struct tagUSB_IAMGE_MODE_PARAM
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byMode; //ͼ��ģʽ��0-��׼��1-���ޣ�2-��ͣ�3-����
        BYTE   byDefault; //ͼ��ģʽĬ��ֵ
        BYTE   byRes1[2];
        BYTE   byRes[128];
    } USB_IAMGE_MODE_PARAM, *LPUSB_IAMGE_MODE_PARAM;

    typedef struct tagUSB_WHITE_BALANCE_PARAM
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byEnable; //��ƽ�⣺0-�رգ�1-������2-У׼
        BYTE   byDefault; //��ƽ��Ĭ��ֵ
        BYTE   byRes1[2];
        BYTE   byRes[128];
    } USB_WHITE_BALANCE_PARAM, *LPUSB_WHITE_BALANCE_PARAM;

    typedef struct tagUSB_GAMUT_PARAM
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byLevel; //ɫ��ֵ
        BYTE   byDefault; //ɫ��Ĭ��ֵ
        BYTE   byMin; //ɫ����Сֵ
        BYTE   byMax; //ɫ�����ֵ
        BYTE   byRes[128];
    } USB_GAMUT_PARAM, *LPUSB_GAMUT_PARAM;

    typedef struct tagUSB_SHUTTER_PARAM
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byLevel; //����ʱ��ȼ�
        BYTE   byDefault; //����ʱ��ȼ�Ĭ��ֵ
        BYTE   byMin; //����ʱ��ȼ���Сֵ
        BYTE   byMax; //����ʱ��ȼ����ֵ
        BYTE   byRes[128];
    } USB_SHUTTER_PARAM, *LPUSB_SHUTTER_PARAM;

    typedef struct tagUSB_FOCUS_PARAM
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byLevel; //�۽������ȵȼ�
        BYTE   byDefault; //�۽������ȵȼ�Ĭ��ֵ
        BYTE   byMin; //�۽������ȵȼ���Сֵ
        BYTE   byMax; //�۽������ȵȼ����ֵ
        BYTE   byRes[128];
    } USB_FOCUS_PARAM, *LPUSB_FOCUS_PARAM;

    typedef struct tagUSB_OVERHEAD_SHOT_PARAM
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byMode; //������ģʽ: 0-����  1-����
        BYTE   byDefault; //�۽������ȵȼ�Ĭ��ֵ
        BYTE   byRes[128];
    } USB_OVERHEAD_SHOT_PARAM, *LPUSB_OVERHEAD_SHOT_PARAM;

    typedef struct tagUSB_VCA_FACE_AE_PARAM
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byEnable; //�����ֲ��ع�ʹ�� 0-�ر� 1-����
        BYTE   byLevel; //�����ֲ��ع�ȼ�
        BYTE   byDefault; //�����ֲ��ع�ȼ�Ĭ��ֵ
        BYTE   byMin; //�����ֲ��ع�ȼ���Сֵ
        BYTE   byMax; //�����ֲ��ع�ȼ����ֵ
        BYTE   byRes1[3];
        BYTE   byRes[128];
    } USB_VCA_FACE_AE_PARAM, *LPUSB_VCA_FACE_AE_PARAM;

    typedef struct tagUSB_VCA_FACE_CENTERED_PARAM
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byEnable; //��������ʹ�� 0-�ر� 1-����
        BYTE   byLevel; //�������������ȵȼ�
        BYTE   byDefault; //�������������ȵȼ�Ĭ��ֵ
        BYTE   byMin; //�������������ȵȼ���Сֵ
        BYTE   byMax; //�������������ȵȼ����ֵ
        BYTE   byRes1[3];
        BYTE   byRes[128];
    } USB_VCA_FACE_CENTERED_PARAM, *LPUSB_VCA_FACE_CENTERED_PARAM;

    typedef struct tagUSB_VCA_SPOKESMAN_TRACK_PARAM
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   byEnable; //�����˸���ʹ�� 0-�ر� 1-����
        BYTE   byLevel; //�����˸��������ȵȼ�
        BYTE   byDefault; //�����˸��������ȵȼ�Ĭ��ֵ
        BYTE   byMin; //�����˸��������ȵȼ���Сֵ
        BYTE   byMax; //�����˸��������ȵȼ����ֵ
        BYTE   byRes1[3];
        BYTE   byRes[128];
    } USB_VCA_SPOKESMAN_TRACK_PARAM, *LPUSB_VCA_SPOKESMAN_TRACK_PARAM;

    typedef struct tagUSB_VCA_BEAUTY_PARAM
    {
        DWORD  dwSize; //�ṹ���С
        BYTE   bySmoothing; //ĥƤ 0-��֧�� 1-֧��
        BYTE   byWhitening; //���� 0-��֧�� 1-֧��
        BYTE   byBlush; //���� 0-��֧�� 1-֧��
        BYTE   bySharpness; //�� 0-��֧�� 1-֧��
        BYTE   byEyeRetouch; //���� 0-��֧�� 1-֧��
        BYTE   byTeethBeautification; //���� 0-��֧�� 1-֧��
        BYTE   byDarkCircles; //�����Ȧ 0-��֧�� 1-֧��
        BYTE   byNasolabialFolds; //����� 0-��֧�� 1-֧��
        BYTE   bySlimFace; //���� 0-��֧�� 1-֧��
        BYTE   byVshapedFace; //V�� 0-��֧�� 1-֧��
        BYTE   byFaceWidth; //խ�� 0-��֧�� 1-֧��
        BYTE   byCheekbones; //��ȧ�� 0-��֧�� 1-֧��
        BYTE   byLowerJaw; //������ 0-��֧�� 1-֧��
        BYTE   byEyeSize; //���� 0-��֧�� 1-֧��
        BYTE   byEyeShape; //Բ�� 0-��֧�� 1-֧��
        BYTE   byNoseWidth; //�ݱ� 0-��֧�� 1-֧��
        BYTE   byNoseLength; //���� 0-��֧�� 1-֧��
        BYTE   byMouthType; //���� 0-��֧�� 1-֧��
        BYTE   bySmilingMouth; //΢Ц��� 0-��֧�� 1-֧��
        BYTE   byRemoveMakeup; //жױ 0-��֧�� 1-֧��
        BYTE   byPeachBlossom; //�һ� 0-��֧�� 1-֧��
        BYTE   byFreckle; //ȸ�� 0-��֧�� 1-֧��
        BYTE   byPunk; //��� 0-��֧�� 1-֧��
        BYTE   byMapleLeaf; //��Ҷ 0-��֧�� 1-֧��
        BYTE   byRetro; //���� 0-��֧�� 1-֧��
        BYTE   byKoi; //���� 0-��֧�� 1-֧��
        BYTE   byPlum; //÷�� 0-��֧�� 1-֧��
        BYTE   bySweet; //���� 0-��֧�� 1-֧��
        BYTE   byRedTea; //��� 0-��֧�� 1-֧��
        BYTE   byWinter; //���� 0-��֧�� 1-֧��
        BYTE   byStylish; //���� 0-��֧�� 1-֧��
        BYTE   byCream; //���� 0-��֧�� 1-֧��
        BYTE   byClear; //��͸ 0-��֧�� 1-֧��
        BYTE   byGrapefruit; //���� 0-��֧�� 1-֧��
        BYTE   byNeighbour; //�ڼ� 0-��֧�� 1-֧��
        BYTE   byDegree; //�̶� 0-��֧�� 1-֧��
        BYTE   byOriginal; //ԭͼ 0-��֧�� 1-֧��
        BYTE   byBrightWhite; //���� 0-��֧�� 1-֧��
        BYTE   byRosy; //���� 0-��֧�� 1-֧��
        BYTE   byFair; //��� 0-��֧�� 1-֧��
        BYTE   byCoolColors; //��ɫ�� 0-��֧�� 1-֧��
        BYTE   byPeach; //���� 0-��֧�� 1-֧��
        BYTE   byWarmColors; //ůɫ�� 0-��֧�� 1-֧��
        BYTE   byFresh; //С���� 0-��֧�� 1-֧��
        BYTE   byElegantGray; //�ʸл� 0-��֧�� 1-֧��
        BYTE   byNatural; //��Ȼ 0-��֧�� 1-֧��
        BYTE   bySunshine; //���� 0-��֧�� 1-֧��
        BYTE   byRes1[1];
        BYTE   byRes[128];
    } USB_VCA_BEAUTY_PARAM, *LPUSB_VCA_BEAUTY_PARAM;

    //VCMУ׼
    typedef struct tagUSB_TEST_VCM
    {
        DWORD  dwSize;   //�ṹ���С
        BYTE   byResult; //VCM�궨��� 0-ʧ�� 1-�ɹ� 2-�궨��  ������ʱ��Ч��
        BYTE   byRes1[3];
        WORD   wValue; //VCM�궨����  ������ʱ��Ч��
        BYTE   byRes[22];
    } USB_TEST_VCM, *LPUSB_TEST_VCM;

    //DTOFУ׼
    typedef struct tagUSB_TEST_DTOF_CALIBRATION
    {
        DWORD  dwSize;    //�ṹ���С
        BYTE   byEnable;  //ʹ�� 0-�ر� 1-���� ����ȡʱ��Ч��
        BYTE   byResult;  //DTOFУ׼��� 0-ʧ�� 1-�ɹ� 2-У׼��  ������ʱ��Ч��
        BYTE   byRes[26];
    } USB_TEST_DTOF_CALIBRATION, *LPUSB_TEST_DTOF_CALIBRATION;

    //DTOFģ��
    typedef struct tagUSB_TEST_DTOF_INFO
    {
        DWORD  dwSize;    //�ṹ���С
        BYTE   byId;    //TOF ID
        BYTE   byStatus;    //״̬��0-������1-7�쳣
        BYTE   byDistance;    //����(mm)��0-255
        BYTE   byRes[25];
    } USB_TEST_DTOF_INFO, *LPUSB_TEST_DTOF_INFO;

    //DTOF���
    typedef struct tagUSB_TEST_DTOF_CHECK
    {
        DWORD  dwSize;    //�ṹ���С
        BYTE   byEnable;    //ʹ�� 0-Ĭ�� 1-����  ����ȡʱ��Ч��
        BYTE   byTofNum;    //TOF����   ������ʱ��Ч��
        BYTE   byRes1[2];
        USB_TEST_DTOF_INFO struDtofInfo[10];//Dtof ģ����Ϣ  ������ʱ��Ч��
        BYTE   byRes[32];
    } USB_TEST_DTOF_CHECK, *LPUSB_TEST_DTOF_CHECK;

    //PWMռ�ձ�
    typedef struct tagUSB_TEST_PWM
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byValue;     //ռ�ձȣ�0-100��
        BYTE   byRes[27];
    } USB_TEST_PWM, *LPUSB_TEST_PWM;

    //ITOF������
    typedef struct tagUSB_TEST_ITOF_DISTANCE
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byResult;       //ITOF�������� 0-ʧ�� 1-�ɹ� ������ʱ��Ч��
        BYTE   byRes1;
        WORD   wValue;   //������� ������ʱ��Ч��
        BYTE   byRes[24];
    } USB_TEST_ITOF_DISTANCE, *LPUSB_TEST_ITOF_DISTANCE;

    //ITOF�������
    typedef struct tagUSB_TEST_ITOF_FACTORY
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byEnable;    //ʹ�� 0-�ر� 1-����  ����ȡʱ��Ч��
        BYTE   byResult;    //ITOF�������� 2-�ɹ� ����ֵ-ʧ�� ������ʱ��Ч��
        BYTE   byRes[26];
    } USB_TEST_ITOF_FACTORY, *LPUSB_TEST_ITOF_FACTORY;

    //ITOF��֡���
    typedef struct tagUSB_TEST_ITOF_FRAME
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byEnable;    //ʹ�� 0-�ر� 1-����  ����ȡʱ��Ч��
        BYTE   byResult;    //ITOF��֡����� 2-�ɹ� ����ֵ-ʧ�� ������ʱ��Ч��
        BYTE   byRes[26];
    } USB_TEST_ITOF_FRAME, *LPUSB_TEST_ITOF_FRAME;

    //ITOF�������2
    typedef struct tagUSB_TEST_ITOF_FACTORY2
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byEnable;    //ʹ�� 0-�ر� 1-����  ����ȡʱ��Ч��
        BYTE   byResult;    //ITOF������2��� 2-�ɹ� ����ֵ-ʧ�� ������ʱ��Ч��
        WORD   wPrecision;   //���ȣ�����ʱ��Ч��
        WORD   wAccuracy;   //׼�ȣ�����ʱ��Ч��
        WORD   wIr;         //IRƽ��ֵ������ʱ��Ч��
        BYTE   byRes[26];
    } USB_TEST_ITOF_FACTORY2, *LPUSB_TEST_ITOF_FACTORY2;

    //ITOF�궨
    typedef struct tagUSB_TEST_ITOF_CALIBRATION
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byEnable;    //ʹ�� 0-�ر� 1-����  ����ȡʱ��Ч��
        BYTE   byResult;    //ITOF������2��� 0-����׼���� 1-�ɹ� 2-ʧ�� ������ʱ��Ч��
        BYTE   byRes1[2];
        DWORD  dwRatioInt;
        DWORD  dwRatioDecimal;
        DWORD  dwHRatioInt;
        DWORD  dwHRatioDecima;
        DWORD  dwOffsetLX;
        DWORD  dwOffsetX;
        DWORD  dwOffsetLY;
        DWORD  dwOffsetY;
        BYTE   byRes[16];
    } USB_TEST_ITOF_CALIBRATION, *LPUSB_TEST_ITOF_CALIBRATION;

    //��ͷ�ϻ������
    typedef struct tagUSB_TEST_SCENE_CURVE_CHECK
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byEnable;    //ʹ�� 0-��ʼ�� 1-��ʼУ�� 2-������  ����ȡʱ��Ч��
        BYTE   byResult;    //��� 0-ʧ�� 1-�ɹ� ������ʱ��Ч��
        BYTE   byRes[20];
    } USB_TEST_SCENE_CURVE_CHECK, *LPUSB_TEST_SCENE_CURVE_CHECK;

    //��ͷ�ϻ������
    typedef struct tagUSB_TEST_SCENE_AGE_CHECK
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byEnable;    //ʹ�� 0-�ر� 1-����  ����ȡʱ��Ч��
        BYTE   byRes1[3];
        DWORD  dwPan;       //Pan�ϻ���   ������ʱ��Ч��
        DWORD  dwTitl;      //Titl�ϻ���    ������ʱ��Ч��
        BYTE   byRes[16];
    } USB_TEST_SCENE_AGE_CHECK, *LPUSB_TEST_SCENE_AGE_CHECK;

    //ָʾ�Ƽ��
    typedef struct tagUSB_TEST_LAMP_CHECK
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byEnable;    //ʹ�ܣ�0-�ر� 1-����
        BYTE   byRes[27];
    } USB_TEST_LAMP_CHECK, *LPUSB_TEST_LAMP_CHECK;

    //��ؼ��
    typedef struct tagUSB_TEST_BATTERY_CHECK
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byEnable;    //ʹ�� 0-Ĭ�� 1-����   ����ȡʱ��Ч��
        BYTE   byShutdown;    //Shutdownģʽ���� 0-�ر� 1-����   ��enableΪ0ʱ��Ч������ȡʱ��Ч��
        BYTE   byResult;    //Shutdownģʽ��� 0-ʧ�� 1-�ɹ� ������ʱ��Ч��
        char   byPower;     //������-1���쳣   0-100����ֵ
        WORD   wVoltageDiff;      //�ṹ���С
        WORD   wCirculate;      //�ṹ���С
        WORD   wTemperature;      //�ṹ���С
        WORD   wVoltage;      //�ṹ���С
        WORD   wCurrent;      //�ṹ���С
        WORD   wVersion;      //�ṹ���С
        BYTE   byRes[27];
    } USB_TEST_BATTERY_CHECK, *LPUSB_TEST_BATTERY_CHECK;

    //��ť
    typedef struct tagUSB_TEST_KNOB_PARAM
    {
        DWORD  dwSize;       //�ṹ���С
        BYTE   byID;  //��ťid
        BYTE   byRes1[3];
        WORD   wMin;    //��Сֵ
        WORD   wMax;    //���ֵ
        BYTE   byRes[4];
    } USB_TEST_KNOB_PARAM, *LPUSB_TEST_KNOB_PARAM;

    //��ť�궨
    typedef struct tagUSB_TEST_KNOB_CALIBRATION
    {
        DWORD  dwSize;       //�ṹ���С
        BYTE   byOperation;  //��ⲽ��: 0-Ĭ�� 1-��Сֵ�궨 2-���ֵ�궨  ����ȡʱ��Ч��
        BYTE   byResult;    //������·� 0-Ĭ�� 1-����Ҫ�� 2-������Ҫ�� ��operationΪ0ʱ��Ч������ȡʱ��Ч��
        BYTE   byGetResult;    //������豸��ȡ��ť��ѹֵ�Ƿ������ 0-����� 1-������������ʱ��Ч��
        BYTE   bySaveResult;    //������豸������ť�궨����� 0-ʧ�� 1-�ɹ�������ʱ��Ч��
        BYTE   byKnobNum;    //��ť����
        BYTE   byRes1[3];
        USB_TEST_KNOB_PARAM struKnob[10];
        BYTE   byRes[16];
    } USB_TEST_KNOB_CALIBRATION, *LPUSB_TEST_KNOB_CALIBRATION;

    //�������ñ��ָ�Ĭ��
    typedef struct tagUSB_TEST_PARAM_RESET
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byEnable;    //��ⲽ�� 0-Ĭ�� 1-��ʼ�ָ�   ����ȡʱ��Ч��
        BYTE   byResult;    //��� 0-ʧ�� 1-�ɹ� ������ʱ��Ч��
        BYTE   byRes[26];
    } USB_TEST_PARAM_RESET, *LPUSB_TEST_PARAM_RESET;

    //�˵�
    typedef struct tagUSB_TEST_ENDPOINTS
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byID;    //�˵�ID
        BYTE   byEnable;    //���⴮��ʹ�� 0-�ر� 1-����
        BYTE   byRes[26];
    } USB_TEST_ENDPOINTS, *LPUSB_TEST_ENDPOINTS;

    //���ض˵�
    typedef struct tagUSB_TEST_HIDE_ENDPOINTS
    {
        DWORD  dwSize;      //�ṹ���С
        USB_TEST_ENDPOINTS struEndpoints[10];
        BYTE   byRes[32];
    } USB_TEST_HIDE_ENDPOINTS, *LPUSB_TEST_HIDE_ENDPOINTS;

    //����״̬��ȡ
    typedef struct tagUSB_TEST_HALL
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byStatus;    //����״̬ 0-�ر� 1-����
        BYTE   byRes[27];
    } USB_TEST_HALL, *LPUSB_TEST_HALL;

    //�豸λ��
    typedef struct tagUSB_TEST_DEVICE_LOCATION
    {
        DWORD  dwSize;        //�ṹ���С
        BYTE   byLocationID;  //�豸����λ��ID(��Χ��1-255)
        BYTE   byRes[27];
    } USB_TEST_DEVICE_LOCATION, *LPUSB_TEST_DEVICE_LOCATION;

    //������
    typedef struct tagUSB_TEST_TOUCH_POINT
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byID;    //������ID
        BYTE   byStatus;    //״̬ 0-�ر� 1-����
        BYTE   byRes[26];
    } USB_TEST_TOUCH_POINT, *LPUSB_TEST_TOUCH_POINT;

    //�����������
    typedef struct tagUSB_TEST_TOUCH_BUTTON
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byEnable;    //ʹ�� 0-�ر� 1-���� ����ȡʱ��Ч��
        BYTE   byNum;    //��������� 0-�ر� 1-����  ������ʱ��Ч��
        BYTE   byRes1[2];
        USB_TEST_TOUCH_POINT struTouchPoint[10]; //�����㣨����ʱ��Ч��
        BYTE   byRes[32];
    } USB_TEST_TOUCH_BUTTON, *LPUSB_TEST_TOUCH_BUTTON;

    //����궨
    typedef struct tagUSB_TEST_FRAME
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byEnable;    //��ⲽ�� 0-Ĭ�� 1-��ʼ   ����ȡʱ��Ч��
        BYTE   byResult;    //��� 0-ʧ�� 1-�ɹ� 2-�궨�У�����ʱ��Ч��
        BYTE   byRes[26];
    } USB_TEST_FRAME, *LPUSB_TEST_FRAME;

    //��Ƶ�˵�����
    typedef struct tagUSB_CTRL_MENU_PARAM
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byControlUnit; //�˵����� 1-�����˵� 2-�����ƶ��˵���ѡ�� 3-�����ƶ��˵���ѡ�� 4-�����ƶ��˵���ѡ�� 5-�����ƶ��˵���ѡ�� 6-ȷ�� 7-����
        BYTE   byRes[27];
    } USB_CTRL_MENU_PARAM, *LPUSB_CTRL_MENU_PARAM;

    //ͼ��ɫ�ʿռ�
    typedef struct tagUSB_IMAGE_DYNAMIC_RANGE_PARAM
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byDynamicRangeType; //ɫ�ʿռ����ͣ�ITU������׼����1-BT.601 2-BT.709 3-BT.2020
        BYTE   byRes[27];
    } USB_IMAGE_DYNAMIC_RANGE_PARAM, *LPUSB_IMAGE_DYNAMIC_RANGE_PARAM;

    //��̨��������
    typedef struct tagUSB_PTZ_BASIC_CTRL_PARAM
    {
        DWORD  dwSize;      //�ṹ���С
        BYTE   byPtzDirection; //����1-�� 2-�� 3-�� 4-�� 5-zoom+ 6-zoom- 7-focus+ 8-focus-
        BYTE   byPtzStatus; //״̬��0-ֹͣ 1-��ʼ
        BYTE   byRes[26];
    } USB_PTZ_BASIC_CTRL_PARAM, *LPUSB_PTZ_BASIC_CTRL_PARAM;

    //USB_SDK�ĳ�ʼ��
    USB_SDK_API BOOL  CALLBACK USB_Init();
    //USB_SDK�ķ���ʼ��
    USB_SDK_API BOOL  CALLBACK USB_Cleanup();
    USB_SDK_API DWORD CALLBACK USB_GetSDKVersion(void);

    USB_SDK_API LONG  CALLBACK USB_GetDeviceCount();
    //�������豸ö�ٽӿڣ��Ƿ�����Ƶ�豸���룬�Ƿ�����������豸��
    USB_SDK_API LONG  CALLBACK USB_GetDeviceCountEx(LPUSB_GET_DEVICE_COUNT_INFO pGetDeivceCountInfo);
    USB_SDK_API BOOL  CALLBACK USB_EnumDevices(DWORD dwCount, LPUSB_DEVICE_INFO pDevInfoList);
    //��ȡ������
    USB_SDK_API DWORD CALLBACK USB_GetLastError();
    //��ȡ�������Ӧ����Ϣ
    USB_SDK_API char* CALLBACK USB_GetErrorMsg(DWORD dwErrorCode);

    // ��ȡ��ǰ����״̬���ȳ����豸��
    // ��������ȷ��ǰ�����豸�Ƿ���Чʱ��ͨ���ýӿ��ж���һ��ָ���Ƿ���Ч��һֱ��ȡֱ��״̬������0x01����ѯ�������10ms��
    USB_SDK_API BOOL  CALLBACK USB_GetCommandState(LONG lUserID, LPUSB_COMMAND_STATE pCommandState);

    USB_SDK_API BOOL  CALLBACK USB_SetLogToFile(DWORD dwLogLevel, const char* strLogDir, BOOL bAutoDel);
    USB_SDK_API LONG  CALLBACK USB_Login(LPUSB_USER_LOGIN_INFO pUsbLoginInfo, LPUSB_DEVICE_REG_RES pDevRegRes);
    USB_SDK_API BOOL  CALLBACK USB_Logout(LONG lUserID);
    USB_SDK_API BOOL  CALLBACK USB_Active(LPUSB_USER_LOGIN_INFO pActiveInfo);
    USB_SDK_API BOOL  CALLBACK USB_GetActiveStatus(LPUSB_USER_LOGIN_INFO pActiveInfo, LPUSB_ACTIVE_STATUS pActiveStatus);
    USB_SDK_API LONG  CALLBACK USB_Upgrade(LONG lUserID, DWORD dwUpgradeType, char *sFileName, void *pInbuffer, DWORD dwBufferLen);
    USB_SDK_API BOOL  CALLBACK USB_GetUpgradeState(LONG lUpgradeHandle, LPUSB_UPGRADE_STATE_INFO pUpgradeState);
    USB_SDK_API BOOL  CALLBACK USB_CloseUpgradeHandle(LONG lUpgradeHandle);
    USB_SDK_API BOOL  CALLBACK USB_GetDeviceConfig(LONG lUserID, DWORD dwCommand, LPUSB_CONFIG_INPUT_INFO pConfigInputInfo, LPUSB_CONFIG_OUTPUT_INFO pConfigOutputInfo);
    USB_SDK_API BOOL  CALLBACK USB_SetDeviceConfig(LONG lUserID, DWORD dwCommand, LPUSB_CONFIG_INPUT_INFO pConfigInputInfo, LPUSB_CONFIG_OUTPUT_INFO pConfigOutputInfo);
    USB_SDK_API BOOL  CALLBACK USB_Control(LONG lUserID, DWORD dwCommand, LPUSB_CONTROL_INPUT_INFO pInputInfo);
    USB_SDK_API BOOL  CALLBACK USB_TransConfig(LONG lUserID, LPUSB_PT_PARAM lpParam);
   
    USB_SDK_API LONG  CALLBACK USB_StartPreview(LONG lUserID, LPUSB_PREVIEW_PARAM pPreviewParam);
    USB_SDK_API LONG  CALLBACK USB_StartRecord(LONG lUserID, LPUSB_RECORD_PARAM pRecordParam);
    USB_SDK_API LONG  CALLBACK USB_StartStreamCallback(LONG lUserID, LPUSB_STREAM_CALLBACK_PARAM pStreamCBParam);
    USB_SDK_API LONG  CALLBACK USB_StartFaceDetect(LONG lUserID, USB_FACE_DETECT_PARAM* pFaceDetectParam);
    USB_SDK_API BOOL  CALLBACK USB_Capture(LONG lUserID, LPUSB_CAPTURE_PARAM pChapterInfo);
    USB_SDK_API LONG  CALLBACK USB_FileTransfer(LONG lUserID, DWORD dwCommand, char *sFileName);
    USB_SDK_API BOOL  CALLBACK USB_FileTransfer_V20(LONG lUserID, DWORD dwCommand, LPUSB_FILE_TRANSFER_INFO pFileTransferInfo, LPUSB_FILE_TRANSFER_PROGRESS_INFO pProgressInfo);
    /**
    * ���ܣ�ֹͣԤ����¼�������ص���Ŀ��ʶ��
    * @param in lUserID���豸�������USB_Login�ķ���ֵ��
    * @param in lHandle��Ԥ����¼�������ص������������
    * @param out HPR_TRUE - �ɹ���HPR_FALSE - ʧ��
    */
    USB_SDK_API BOOL  CALLBACK USB_StopChannel(LONG lUserID, DWORD lHandle);
    USB_SDK_API BOOL  CALLBACK USB_SetSDKLocalCfg(USB_LOCAL_CFG_TYPE enumType, const void *lpInBuff);
    // ��ȡ���ſ�˿�
    USB_SDK_API LONG  CALLBACK USB_GetPlayerPort(LONG lUserID, DWORD lHandle);
#endif 

