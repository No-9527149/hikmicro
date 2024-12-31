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

    //SDK内部错误码
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
#define USB_ERROR_INVALID_PORT          (USB_ERROR_BASE+30)   // 无效Port
#define USB_ERROR_INVALID_PATH          (USB_ERROR_BASE+31)   // 无效路径
#define USB_ERROR_INVALID_CMD           (USB_ERROR_BASE+32)   // 无效命令码
#define USB_ERROR_INVALID_POINTER       (USB_ERROR_BASE+33)   // 无效指针

#define USB_ERROR_INVALID_HANDLE       (USB_ERROR_BASE+38)    // 无效句柄
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
#define USB_ERROR_LOAD_LIBRARY         (USB_ERROR_BASE+76)  //加载库失败
#define USB_ERROR_ALLOC_RESOURCE       (USB_ERROR_BASE+77)  //资源分配出错：线程，锁等

#define USB_ERROR_FILE_OPEN            (USB_ERROR_BASE+80)  // 文件打开失败
#define USB_ERROR_FILE_WRITE           (USB_ERROR_BASE+81)  // 文件写失败
#define USB_ERROR_CALL_DISORDER        (USB_ERROR_BASE+82)  // 调用顺序不对
#define USB_ERROR_INITOBSERVER         (USB_ERROR_BASE+83)  // 初始化观察者失败
#define USB_ERROR_NOT_SUPPORTED_FORMAT (USB_ERROR_BASE+84)  // 不支持的音视频格式
#define USB_ERROR_NOT_SUPPORTED_AUDIO  (USB_ERROR_BASE+85)  // 该设备不支持音频
#define USB_ERROR_INIT_LIBUSB          (USB_ERROR_BASE+86)  // 初始化libusb失败
#define USB_ERROR_INIT_LIBUVC          (USB_ERROR_BASE+87)  // 初始化libuvc失败
#define USB_ERROR_INIT_DIRECTSHOW      (USB_ERROR_BASE+88)  // 初始化directshow失败
#define USB_ERROR_NO_MATCH_IR_FRAME    (USB_ERROR_BASE+89)  // 未匹配到IR帧

//设备相关错误码
#define USB_ERROR_DEV_OPER_FAILED      (USB_ERROR_BASE+257)  // 操作失败
#define USB_ERROR_DEV_OPER_NOT_SUPPORT (USB_ERROR_BASE+258)  // 设备不支持该操作
#define USB_ERROR_DEV_CHECK_SUM        (USB_ERROR_BASE+259)  // 校验和错误
#define USB_ERROR_DEV_USER_ID          (USB_ERROR_BASE+260)  // 非法的UserID
#define USB_ERROR_DEV_SESSION_ID       (USB_ERROR_BASE+261)  // 非法的SessionID
#define USB_ERROR_DEV_OPER_TIMEOUT     (USB_ERROR_BASE+262)  // 设备操作超时
#define USB_ERROR_DEV_PASSWORD_ERROR   (USB_ERROR_BASE+266)  // Username or Password Error
#define USB_ERROR_DEV_USER_LOCKED      (USB_ERROR_BASE+267)  // Device locked
#define USB_ERROR_DEV_UNKNOW_OPER_RES  (USB_ERROR_BASE+512)  // 未知的设备操作返回码


/************************************************************************
* 转封装库错误码
************************************************************************/
#define USB_ERROR_SYSTRANS_HANDLE       (USB_ERROR_BASE+600)  //转换句柄错误
#define USB_ERROR_SYSTRANS_SUPPORT      (USB_ERROR_BASE+601)  //类型不支挿
#define USB_ERROR_SYSTRANS_RESOURCE     (USB_ERROR_BASE+602)  //资源申请或释放错诿
#define USB_ERROR_SYSTRANS_PARA         (USB_ERROR_BASE+603)  //参数错误
#define USB_ERROR_SYSTRANS_PRECONDITION (USB_ERROR_BASE+604)  //前置条件未满足，调用顺序
#define USB_ERROR_SYSTRANS_OVERFLOW     (USB_ERROR_BASE+605)  //缓存溢出
#define USB_ERROR_SYSTRANS_STOP         (USB_ERROR_BASE+606)  //停止状怿
#define USB_ERROR_SYSTRANS_FILE         (USB_ERROR_BASE+607)  //文件错误
#define USB_ERROR_SYSTRANS_MAX_HANDLE   (USB_ERROR_BASE+608)  //最大路数限刿
#define USB_ERROR_SYSTRANS_MUXER        (USB_ERROR_BASE+609)  //底层mp4打包库打包错诿
#define USB_ERROR_SYSTRANS_FAIL         (USB_ERROR_BASE+610)  //探测失败
#define USB_ERROR_SYSTRANS_ENCAP        (USB_ERROR_BASE+611)  //流式模式不支持（如ASF、AVI和MP4＿

/************************************************************************
* 转码库错误码
************************************************************************/
#define USB_ERROR_FC_HANDLE         (USB_ERROR_BASE+700)  ///< 错误或无效的句柄
#define USB_ERROR_FC_SUPPORT        (USB_ERROR_BASE+701)  ///< 不支持的功能
#define USB_ERROR_FC_BUFOVER        (USB_ERROR_BASE+702)  ///< 缓存已满
#define USB_ERROR_FC_CALLORDER      (USB_ERROR_BASE+703)  ///< 函数调用顺序错误
#define USB_ERROR_FC_PARAMETER      (USB_ERROR_BASE+704)  ///< 错误的参数
#define USB_ERROR_FC_NEEDMOREDATA   (USB_ERROR_BASE+705)  ///< 需要更多的数据
#define USB_ERROR_FC_RESOURCE       (USB_ERROR_BASE+706)  ///< 资源申请失败
#define USB_ERROR_FC_STREAM         (USB_ERROR_BASE+707)  ///< 码流出错
#define USB_ERROR_FC_DEMUXER        (USB_ERROR_BASE+708)  ///< 解析异常
#define USB_ERROR_FC_MUXER          (USB_ERROR_BASE+709)  ///< 打包异常
#define USB_ERROR_FC_DECODER        (USB_ERROR_BASE+710)  ///< 解码异常
#define USB_ERROR_FC_ENCODER        (USB_ERROR_BASE+711)  ///< 编码异常
#define USB_ERROR_FC_POSTPROC       (USB_ERROR_BASE+712)  ///< 后处理异常
#define USB_ERROR_FC_FILE           (USB_ERROR_BASE+713)  ///< 文件操作异常

/************************************************************************
* 播放库错误码
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
* directshow错误码
************************************************************************/
#define  USB_ERROR_DIRECT_SHOW              (USB_ERROR_BASE+900)

/************************************************************************
* 人脸库错误码
************************************************************************/
#define USB_HIA_ERROR_MALLOC      (USB_ERROR_BASE + 1001)     ///< 内存申请失败
#define USB_HIA_ERROR_THREAD      (USB_ERROR_BASE + 1002)     ///< 创建线程失败
#define USB_HIA_ERROR_RESOURCE    (USB_ERROR_BASE + 1003)     ///< 资源不足
#define USB_HIA_ERROR_SUPPORT     (USB_ERROR_BASE + 1004)     ///< 不支持操作
#define USB_HIA_ERROR_PARAM       (USB_ERROR_BASE + 1005)     ///< 参数错误
#define USB_HIA_ERROR_INIT        (USB_ERROR_BASE + 1006)     ///< 未初始化
#define USB_HIA_ERROR_OPERATE     (USB_ERROR_BASE + 1007)     ///< 操作顺序错误

#define USB_HIA_ERROR_DECODE      (USB_ERROR_BASE + 1008)     ///< 解码失败
#define USB_HIA_ERROR_XML         (USB_ERROR_BASE + 1009)     ///< xml解析出错
#define USB_HIA_ERROR_NOT_MATCH   (USB_ERROR_BASE + 1010)    ///< 版本不匹配
#define USB_HIA_ERROR_OVERFLOW    (USB_ERROR_BASE + 1011)    ///<  溢出
#define USB_HIA_ERROR_RESOLUTION  (USB_ERROR_BASE + 1012)    ///< 分辨率不支持
#define USB_HIA_ERROR_FORMAT      (USB_ERROR_BASE + 1013)    ///< 解码格式不支持
#define USB_HIA_ERROR_SEND        (USB_ERROR_BASE + 1014)    ///< 发送数据失败
#define USB_HIA_ERROR_RECV        (USB_ERROR_BASE + 1015)    ///< 接受数据失败
#define USB_HIA_ERROR_SOCKET      (USB_ERROR_BASE + 1016)    ///< socket错误，包括创建，链接等
#define USB_HIA_ERROR_OSAPI       (USB_ERROR_BASE + 1017)    ///< 系统函数错误
#define USB_HIA_ERROR_JSON        (USB_ERROR_BASE + 1018)    ///< json错误
#define USB_HIA_ERROR_IMG         (USB_ERROR_BASE + 1019)    ///< 图片处理失败， 包括抠图， 压缩，绘图，图片转换等。
#define USB_HIA_ERROR_LACK        (USB_ERROR_BASE + 1020)    //   数据不足
#define USB_HIA_ERROR_ENCRYTE     (USB_ERROR_BASE + 1021)     ///< 加密失败
#define USB_HIA_ERROR_CREATE      (USB_ERROR_BASE + 1022)     ///< 算法库创建失败
#define USB_HIA_ERROR_PROCESS     (USB_ERROR_BASE + 1023)     ///< 算法处理报错
#define USB_HIA_ERROR_LOADMODE    (USB_ERROR_BASE + 1024)     ///< 加载模型错误
#define USB_HIA_ERROR_SETPARAM    (USB_ERROR_BASE + 1025)     //   设置参数错误
#define USB_HIA_ERROR_GETPARAM    (USB_ERROR_BASE + 1026)     //   获取参数错误
#define USB_HIA_ERROR_DESTROY	  (USB_ERROR_BASE + 1027)	  ///<  算法库销毁失败
#define USB_HIA_ERROR_FRCNN       (USB_ERROR_BASE + 1028)    //   FRCNN失败
#define USB_HIA_ERROR_EXCUTE      (USB_ERROR_BASE + 1029)    ///< 执行失败
#define USB_HIA_ERROR_TPC         (USB_ERROR_BASE + 1030)    //   TPC失败
#define USB_HIA_ERROR_FDRL        (USB_ERROR_BASE + 1031)    //   FDRL失败
#define USB_HIA_ERROR_SKIP        (USB_ERROR_BASE + 1032)    //   跳过算法分析
#define USB_HIA_ERROR_BLOCK       (USB_ERROR_BASE + 1033)    //<  阻塞
#define USB_HIA_ERROR_GPUMEMORY    (USB_ERROR_BASE + 1034)   ///< 显存申请失败
#define USB_HIA_ERROR_CPUMEMORY    (USB_ERROR_BASE + 1035)   ///< 内存申请失败
#define USB_HIA_ERROR_AUTHORIZE    (USB_ERROR_BASE + 1036)   ///< 授权失败
#define USB_HIA_ERROR_DATACHANGE  (USB_ERROR_BASE + 1047)    //   分辨率改变


#define USB_ERROR_NOT_DEFINED          (USB_ERROR_BASE+0x02FE)
#define USB_ERROR_OTHER                (USB_ERROR_BASE+0x02FF)  // Other error
//-----------------------------------------------------------------------------------------

/********************配置错误状态码*******************/
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
/********************配置错误状态码*******************/

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
#define FINGER_PRINT_MODULE_VERSION_LEN    32    //指纹模组软件版本长度
#define FINGER_PRINT_MODULE_SERIAL_LEN     64    //指纹模组序列号长度
#define SECURITY_MODULE_SERIAL_LEN         16    //安全模块序列号长度
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
#define USB_DETECT_CARD                 (USB_ACS_BASE + 24)   //检测卡片
#define USB_SET_IDENTITY_INFO           (USB_ACS_BASE + 25)   //身份信息下发
#define USB_GET_EXTERNAL_DEV_INFO       (USB_ACS_BASE + 26)
#define USB_SET_FINGER_PRINT_OPER_PARAM (USB_ACS_BASE + 27)
#define USB_CAPTURE_FINGER_PRINT         (USB_ACS_BASE + 28)
#define USB_GET_FINGER_PRINT_CONTRAST_RESULT (USB_ACS_BASE + 29)
#define USB_CPU_CARD_ENCRYPT_CFG             (USB_ACS_BASE + 30)  //CPU卡加密配置
#define USB_SET_M1_SECTION_ENCRYPT           (USB_ACS_BASE + 31)   //M1卡指定扇区加密

//热成像命令码
#define USB_THERMAL_BASE                 2000
//#define USB_GET_VIDEO_CAP        (USB_THERMAL_BASE+1)          //获取视频能力
//#define USB_GET_AUDIO_CAP        (USB_THERMAL_BASE+2)          //获取音频能力
//#define USB_GET_VIDEO_FORMAT     (USB_THERMAL_BASE+3)            //获取视频格式
//#define USB_SET_VIDEO_FORMAT     (USB_THERMAL_BASE+4)             //设置视频格式
//#define USB_GET_AUDIO_FORMAT     (USB_THERMAL_BASE+5)           //获取音频格式
//#define USB_SET_AUDIO_FORMAT     (USB_THERMAL_BASE+6)            //设置音频格式
//#define USB_GET_RESOLUTION       (USB_THERMAL_BASE+7)            //获取分辨率
//#define USB_SET_RESOLUTION    (USB_THERMAL_BASE+8)            //设置分辨率
//#define USB_GET_FRAMERATE     (USB_THERMAL_BASE+9)           //获取帧率
//#define USB_SET_FRAMERATE     (USB_THERMAL_BASE+10)          //设置帧率
#define USB_GET_SYSTEM_DEVICE_INFO					(USB_THERMAL_BASE+11)   //获取设备信息
#define USB_SET_SYSTEM_REBOOT						(USB_THERMAL_BASE+12)   //设备重启
#define USB_SET_SYSTEM_RESET						(USB_THERMAL_BASE+13)   //恢复默认
#define USB_GET_SYSTEM_HARDWARE_SERVER				(USB_THERMAL_BASE+14)   //获取硬件服务参数
#define USB_SET_SYSTEM_HARDWARE_SERVER				(USB_THERMAL_BASE+15)   //设置硬件服务参数
#define USB_GET_SYSTEM_LOCALTIME					(USB_THERMAL_BASE+16)   //获取系统本地时间
#define USB_SET_SYSTEM_LOCALTIME					(USB_THERMAL_BASE+17)   //设置系统本地时间
#define USB_GET_IMAGE_BRIGHTNESS					(USB_THERMAL_BASE+18)   //获取图像亮度参数
#define USB_SET_IMAGE_BRIGHTNESS					(USB_THERMAL_BASE+19)   //设置图像亮度参数
#define USB_GET_IMAGE_CONTRAST						(USB_THERMAL_BASE+20)   //获取图像对比度参数
#define USB_SET_IMAGE_CONTRAST						(USB_THERMAL_BASE+21)   //设置图像对比度参数
#define USB_SET_SYSTEM_UPDATE_FIRMWARE				(USB_THERMAL_BASE+22)   //设备升级
#define USB_SET_IMAGE_BACKGROUND_CORRECT			(USB_THERMAL_BASE+23)   //一键背景校正
#define USB_GET_SYSTEM_DIAGNOSED_DATA				(USB_THERMAL_BASE+24)   //诊断信息导出
#define USB_SET_IMAGE_MANUAL_CORRECT				(USB_THERMAL_BASE+25)   //一键手动校正
#define USB_GET_IMAGE_ENHANCEMENT					(USB_THERMAL_BASE+26)   //获取图像增强参数
#define USB_SET_IMAGE_ENHANCEMENT					(USB_THERMAL_BASE+27)   //设置图像增强参数
#define USB_GET_IMAGE_VIDEO_ADJUST					(USB_THERMAL_BASE+28)   //获取视频调整参数
#define USB_SET_IMAGE_VIDEO_ADJUST					(USB_THERMAL_BASE+29)   //设置视频调整参数
#define USB_GET_THERMOMETRY_BASIC_PARAM				(USB_THERMAL_BASE+30)   //获取测温基本参数
#define USB_SET_THERMOMETRY_BASIC_PARAM				(USB_THERMAL_BASE+31)   //设置测温基本参数
#define USB_GET_THERMOMETRY_MODE					(USB_THERMAL_BASE+32)   //获取测温模式
#define USB_SET_THERMOMETRY_MODE					(USB_THERMAL_BASE+33)   //设置测温模式
#define USB_GET_THERMOMETRY_REGIONS					(USB_THERMAL_BASE+34)   //获取测温规则参数
#define USB_SET_THERMOMETRY_REGIONS					(USB_THERMAL_BASE+35)   //设置测温规则参数
#define USB_GET_THERMAL_ALG_VERSION					(USB_THERMAL_BASE+36)   //获取热成像相关算法版本信息
//#define USB_SET_THERMAL_ALG_VERSION				(USB_THERMAL_BASE+37)   //预留
#define USB_GET_THERMAL_STREAM_PARAM				(USB_THERMAL_BASE+38)   //获取热成像码流参数
#define USB_SET_THERMAL_STREAM_PARAM				(USB_THERMAL_BASE+39)   //设置热成像码流参数
#define USB_GET_TEMPERATURE_CORRECT					(USB_THERMAL_BASE+40)   //获取测温修正参数
#define USB_SET_TEMPERATURE_CORRECT					(USB_THERMAL_BASE+41)   //设置测温修正参数
#define USB_GET_BLACK_BODY							(USB_THERMAL_BASE+42)   //获取黑体参数
#define USB_SET_BLACK_BODY							(USB_THERMAL_BASE+43)   //设置黑体参数
#define USB_GET_BODYTEMP_COMPENSATION				(USB_THERMAL_BASE+44)   //获取体温补偿参数
#define USB_SET_BODYTEMP_COMPENSATION				(USB_THERMAL_BASE+45)   //设置体温补偿参数
#define USB_GET_JPEGPIC_WITH_APPENDDATA				(USB_THERMAL_BASE+46)   //获取热图
#define USB_GET_ROI_MAX_TEMPERATURE_SEARCH			(USB_THERMAL_BASE+47)   //ROI最高温信息查询
#define USB_GET_P2P_PARAM							(USB_THERMAL_BASE+48)   //获取全屏测温参数
#define USB_SET_P2P_PARAM							(USB_THERMAL_BASE+49)   //设置全屏测温参数
#define USB_GET_SYSTEM_DIAGNOSED_DATA_EX            (USB_THERMAL_BASE+50)   //带参数条件诊断信息导出
#define USB_POST_DOUBLE_LIGHTS_CORRECT				(USB_THERMAL_BASE+51)   //双光校准
#define USB_GET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL	(USB_THERMAL_BASE+52)	//获取双光校准坐标控制参数
#define USB_SET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL   (USB_THERMAL_BASE+53)   //设置双光校准坐标控制参数
#define USB_GET_THERMOMETRY_CALIBRATION_FILE		(USB_THERMAL_BASE+54)   //测温标定文件导出
#define USB_SET_THERMOMETRY_CALIBRATION_FILE		(USB_THERMAL_BASE+55)   //测温标定文件导入
#define USB_GET_THERMOMETRY_EXPERT_REGIONS			(USB_THERMAL_BASE+56)   //获取专家测温规则
#define USB_SET_THERMOMETRY_EXPERT_REGIONS			(USB_THERMAL_BASE+57)   //设置专家测温规则
#define USB_GET_EXPERT_CORRECTION_PARAM				(USB_THERMAL_BASE+58)   //获取专家测温校正参数
#define USB_SET_EXPERT_CORRECTION_PARAM				(USB_THERMAL_BASE+59)   //设置专家测温校正参数
#define USB_START_EXPERT_CORRECTION					(USB_THERMAL_BASE+60)   //开始专家测温校正
#define USB_GET_THERMOMETRY_RISE_SETTINGS           (USB_THERMAL_BASE+61)    //获取温升配置参数
#define USB_SET_THERMOMETRY_RISE_SETTINGS           (USB_THERMAL_BASE+62)    //设置温升配置参数
#define USB_GET_ENVIROTEMPERATURE_CORRECT           (USB_THERMAL_BASE+63)       //获取环境温度校正参数
#define USB_SET_ENVIROTEMPERATURE_CORRECT           (USB_THERMAL_BASE+64)       //设置环境温度校正参数
#define USB_GET_SYSTEM_CAPABILITIES                 (USB_THERMAL_BASE+65)       //获取系统能力
#define USB_GET_SYSTEM_ISP_BIN_FILE                 (USB_THERMAL_BASE+66)       //获取设备ISP bin文件
#define USB_GET_SYSTEM_FUSION_BIN_FILE              (USB_THERMAL_BASE+67)       //获取设备融合参数bin文件
#define USB_GET_VIDEO_CODE                          (USB_THERMAL_BASE+68)       //获取视频编码参数
#define USB_SET_VIDEO_CODE                          (USB_THERMAL_BASE+69)       //设置视频编码参数
#define USB_GET_VIDEO_FUSION                        (USB_THERMAL_BASE+70)       //获取视频图像融合参数
#define USB_SET_VIDEO_FUSION                        (USB_THERMAL_BASE+71)       //设置视频图像融合参数
#define USB_GET_VIDEO_LEN_CALIBRATION               (USB_THERMAL_BASE+72)       //获取镜头标定参数
#define USB_SET_VIDEO_LEN_CALIBRATION               (USB_THERMAL_BASE+73)       //设置镜头标定参数
#define USB_GET_IMAGE_CAPABILITIES                  (USB_THERMAL_BASE+74)       //获取图像管理总能力
#define USB_GET_IMAGE_ENHANCEMENT_CAPABILITIES      (USB_THERMAL_BASE+75)       //获取图像增强能力
#define USB_GET_THERMAL_CAPABILITIES                (USB_THERMAL_BASE+76)       //获取热成像总能力
#define USB_GET_THERMOMETRY_BASIC_PARAM_CAPABILITIES          (USB_THERMAL_BASE+77)       //获取测温基本参数能力
#define USB_GET_VIDEO_COMMON_CAPABILITIES           (USB_THERMAL_BASE+78)       //获取视频通用总能力
#define USB_GET_VIDEO_LEN_CALIBRATION_CAPABILITIES            (USB_THERMAL_BASE+79)       //获取镜头标定能力
#define USB_GET_IMAGE_ENHANCEMENT_V20               (USB_THERMAL_BASE+80)    //获取图像增强参数V20
#define USB_SET_IMAGE_ENHANCEMENT_V20               (USB_THERMAL_BASE+81)     //设置图像增强参数V20
#define USB_GET_THERMAL_STREAM_PARAM_CAPABILITIES   (USB_THERMAL_BASE+82)     //获取热成像码流参数配置能力
#define USB_GET_VIDEO_CODE_CAPABILITIES             (USB_THERMAL_BASE+83)     //获取视频编码能力
#define USB_GET_SYSTEM_INIT                         (USB_THERMAL_BASE+84)     //获取系统初始化参数
#define USB_SET_SYSTEM_INIT                         (USB_THERMAL_BASE+85)     //设置系统初始化参数
#define USB_GET_SYSTEM_CTRL_CAPABILITIES            (USB_THERMAL_BASE+86)     //获取系统管理总能力
#define USB_GET_SYSTEM_DEVICE_INFO_CAPABILITIES     (USB_THERMAL_BASE+87)     //获取设备信息能力
#define USB_GET_SYSTEM_HARDWARE_SERVER_CAPABILITIES           (USB_THERMAL_BASE+88)     //获取硬件服务参数能力
#define USB_GET_SYSTEM_LOCALTIME_CAPABILITIES       (USB_THERMAL_BASE+89)     //获取系统时间参数能力
#define USB_GET_IMAGE_BRIGHTNESS_CAPABILITIES       (USB_THERMAL_BASE+90)     //获取图像亮度调节能力
#define USB_GET_IMAGE_CONTRAST_CAPABILITIES         (USB_THERMAL_BASE+91)     //获取图像对比度调节能力
#define USB_GET_IMAGE_VIDEO_ADJUST_CAPABILITIES     (USB_THERMAL_BASE+92)     //获取视频调整能力
#define USB_GET_THERMAL_THERMOMETRY_MODE_CAPABILITIES         (USB_THERMAL_BASE+93)       //获取测温模式配置能力
#define USB_GET_THERMAL_THERMOMETRY_REGIONS_CAPABILITIES      (USB_THERMAL_BASE+94)       //获取测温规则配置能力
#define USB_GET_THERMAL_TEMPERATURE_CORRECT_CAPABILITIES      (USB_THERMAL_BASE+95)       //获取测温修正（人体测温）能力
#define USB_GET_THERMAL_BLACK_BODY_CAPABILITIES               (USB_THERMAL_BASE+96)       //获取黑体参数配置能力
#define USB_GET_THERMAL_BODYTEMP_COMPENSATION_CAPABILITIES    (USB_THERMAL_BASE+97)       //获取体温补偿参数配置能力
#define USB_GET_THERMAL_ROI_MAX_TEMPERATURE_SEARCH_CAPABILITIES         (USB_THERMAL_BASE+98)       //获取ROI最高温信息查询能力
#define USB_GET_THERMAL_THERMOMETRY_CALIBRATION_FILE_CAPABILITIES       (USB_THERMAL_BASE+99)       //获取测温标定文件导入导出能力
#define USB_GET_THERMAL_THERMOMETRY_EXPERT_REGIONS_CAPABILITIES         (USB_THERMAL_BASE+100)       //获取专家测温规则配置能力
#define USB_GET_THERMAL_THERMOMETRY_EXPERT_CORRECTION_PARAM_CAPABILITIES    (USB_THERMAL_BASE+101)   //获取专家测温校正参数配置能力
#define USB_GET_SYSTEM_DEVICE_DESCRIPTION_INFO                (USB_THERMAL_BASE+102)       //获取设备描述信息
#define USB_GET_SYSTEM_SERIAL_DATA_TRANSMISSION               (USB_THERMAL_BASE+103)       //获取串口透传数据
#define USB_SET_SYSTEM_SERIAL_DATA_TRANSMISSION               (USB_THERMAL_BASE+104)       //设置串口透传数据
#define USB_GET_IMAGE_PALETTE_DATA                            (USB_THERMAL_BASE+105)       //获取伪彩映射表
#define USB_GET_THERAML_THERMOMETRY_OFFLINE_DATA_EXPORT       (USB_THERMAL_BASE+106)       //测温离线分析数据导出
#define USB_GET_IMAGE_OUTPUT_CFG                              (USB_THERMAL_BASE+107)       //获取图像输出配置参数
#define USB_SET_IMAGE_OUTPUT_CFG                              (USB_THERMAL_BASE+108)       //设置图像输出配置参数
#define USB_GET_SYSTEM_DEVICE_DESCRIPTION_INFO_CAPABILITIES   (USB_THERMAL_BASE+109)       //获取设备描述信息能力
#define USB_GET_THERMAL_STREAM_CTRL                           (USB_THERMAL_BASE+110)       //获取码流启停状态
#define USB_SET_THERMAL_STREAM_CTRL                           (USB_THERMAL_BASE+111)       //设置码流启停

//前端命令码
#define USB_CAMERA_BASE                 3000
#define USB_GET_VIDEO_CAP           (USB_CAMERA_BASE+1)               // 获取视频能力集
#define USB_GET_AUDIO_CAP           (USB_CAMERA_BASE+2)               // 获取音频能力集
#define USB_GET_VIDEO_PARAM         (USB_CAMERA_BASE+3)               // 获取视频参数
#define USB_SET_VIDEO_PARAM         (USB_CAMERA_BASE+4)               // 设置视频参数
//#define USB_GET_AUDIO_PARAM         (USB_CAMERA_BASE+5)               // 获取音频参数
#define USB_SET_AUDIO_PARAM         (USB_CAMERA_BASE+6)               // 设置音频参数
#define USB_SET_SRC_STREAM_TYPE     (USB_CAMERA_BASE+7)               // 设置原始码流类型
#define USB_SET_EVENT_CALLBACK      (USB_CAMERA_BASE+9)               // 设置事件回调参数
#define USB_SET_ROTATE_ANGLE        (USB_CAMERA_BASE+10)              // 设置预览画面旋转角度
#define USB_GET_IRFRAME             (USB_CAMERA_BASE+11)              // 获取IR帧
#define USB_INIT_LIVE_DETECT        (USB_CAMERA_BASE+12)              // 创建活体算法资源
#define USB_GET_LIVEDETECT          (USB_CAMERA_BASE+13)              // 活体检测

//标准UVC协议
#define USB_GET_VIDEO_PROPERTY_CAP			(USB_CAMERA_BASE+14)	// 获取视频属性能力集
#define USB_GET_VIDEO_BRIGHTNESS			(USB_CAMERA_BASE+15)	// 获取视频亮度
#define USB_SET_VIDEO_BRIGHTNESS			(USB_CAMERA_BASE+16)	// 设置视频亮度
#define USB_GET_VIDEO_CONTRAST				(USB_CAMERA_BASE+17)	// 获取视频对比度
#define USB_SET_VIDEO_CONTRAST				(USB_CAMERA_BASE+18)	// 设置视频对比度
#define USB_GET_VIDEO_HUE					(USB_CAMERA_BASE+19)	// 获取视频色调
#define USB_SET_VIDEO_HUE					(USB_CAMERA_BASE+20)	// 设置视频色调
#define USB_GET_VIDEO_SATURATION			(USB_CAMERA_BASE+21)	// 获取视频饱和度
#define USB_SET_VIDEO_SATURATION			(USB_CAMERA_BASE+22)	// 设置视频饱和度
#define USB_GET_VIDEO_SHARPNESS				(USB_CAMERA_BASE+23)	// 获取视频清晰度
#define USB_SET_VIDEO_SHARPNESS				(USB_CAMERA_BASE+24)	// 设置视频清晰度
#define USB_GET_VIDEO_GAMMA					(USB_CAMERA_BASE+25)	// 获取视频伽玛
#define USB_SET_VIDEO_GAMMA					(USB_CAMERA_BASE+26)	// 设置视频伽玛
#define USB_GET_VIDEO_COLORENABLE			(USB_CAMERA_BASE+27)	// 获取视频启用颜色
#define USB_SET_VIDEO_COLORENABLE			(USB_CAMERA_BASE+28)	// 设置视频启用颜色
#define USB_GET_VIDEO_WHITEBALANCE			(USB_CAMERA_BASE+29)	// 获取视频白平衡
#define USB_SET_VIDEO_WHITEBALANCE			(USB_CAMERA_BASE+30)	// 设置视频白平衡
#define USB_GET_VIDEO_BACKLIGHTCOMPENSATION	(USB_CAMERA_BASE+31)	// 获取视频逆光对比
#define USB_SET_VIDEO_BACKLIGHTCOMPENSATION	(USB_CAMERA_BASE+32)	// 设置视频逆光对比
#define USB_GET_VIDEO_GAIN					(USB_CAMERA_BASE+33)	// 获取视频增益
#define USB_SET_VIDEO_GAIN					(USB_CAMERA_BASE+34)	// 设置视频增益
#define USB_GET_VIDEO_POWERLINEFREQUENCY	(USB_CAMERA_BASE+35)	// 获取视频电力线频率
#define USB_SET_VIDEO_POWERLINEFREQUENCY	(USB_CAMERA_BASE+36)	// 设置视频电力线频率
#define USB_GET_VIDEO_PAN					(USB_CAMERA_BASE+37)	// 获取视频全景
#define USB_SET_VIDEO_PAN					(USB_CAMERA_BASE+38)	// 设置视频全景
#define USB_GET_VIDEO_TILT					(USB_CAMERA_BASE+39)	// 获取视频倾斜
#define USB_SET_VIDEO_TILT					(USB_CAMERA_BASE+40)	// 设置视频倾斜
#define USB_GET_VIDEO_ROLL					(USB_CAMERA_BASE+41)	// 获取视频滚动
#define USB_SET_VIDEO_ROLL					(USB_CAMERA_BASE+42)	// 设置视频滚动
#define USB_GET_VIDEO_ZOOM					(USB_CAMERA_BASE+43)	// 获取视频缩放
#define USB_SET_VIDEO_ZOOM					(USB_CAMERA_BASE+44)	// 设置视频缩放
#define USB_GET_VIDEO_EXPOSURE				(USB_CAMERA_BASE+45)	// 获取视频曝光
#define USB_SET_VIDEO_EXPOSURE				(USB_CAMERA_BASE+46)	// 设置视频曝光
#define USB_GET_VIDEO_IRIS					(USB_CAMERA_BASE+47)	// 获取视频光圈
#define USB_SET_VIDEO_IRIS					(USB_CAMERA_BASE+48)	// 设置视频光圈
#define USB_GET_VIDEO_FOCUS					(USB_CAMERA_BASE+49)	// 获取视频焦点
#define USB_SET_VIDEO_FOCUS					(USB_CAMERA_BASE+50)	// 设置视频焦点
#define USB_GET_VIDEO_LOWBRIGHTNESSCOMPENSATION	(USB_CAMERA_BASE+51)// 获取视频低亮度补偿
#define USB_SET_VIDEO_LOWBRIGHTNESSCOMPENSATION	(USB_CAMERA_BASE+52)// 设置视频低亮度补偿
#define USB_GET_VIDEO_VOLUME				(USB_CAMERA_BASE+53)	// 获取设备音量
#define USB_SET_VIDEO_VOLUME				(USB_CAMERA_BASE+54)	// 设置设备音量

//私有UVC协议
#define USB_SET_OSD                         (USB_CAMERA_BASE+100)   // 设置OSD
//复用 #define USB_SET_SYSTEM_RESET          (USB_THERMAL_BASE+13)   // 恢复默认
#define USB_GET_PRIVATE_UVC_CABABILITIES    (USB_CAMERA_BASE+102)   // 获取私有协议UVC能力集
#define USB_GET_PRIVATE_UAC_CABABILITIES    (USB_CAMERA_BASE+103)   // 获取私有协议UAC能力集
#define USB_GET_IMAGE_ENHANCEMENT_CAMERA    USB_GET_IMAGE_ENHANCEMENT_V20   // 获取图像增强参数
#define USB_SET_IMAGE_ENHANCEMENT_CAMERA    USB_SET_IMAGE_ENHANCEMENT_V20   // 设置图像增强参数
#define USB_GET_IMAGE_VIDEO_ADJUST_CAMERA   USB_GET_IMAGE_VIDEO_ADJUST  // 获取视频调整参数
#define USB_SET_IMAGE_VIDEO_ADJUST_CAMERA   USB_SET_IMAGE_VIDEO_ADJUST  // 设置视频调整参数
#define USB_GET_IMAGE_WDR_CAMERA            USB_GET_IMAGE_WDR        // 获取图像WDR参数
#define USB_SET_IMAGE_WDR_CAMERA            USB_SET_IMAGE_WDR        // 设置图像WDR参数
#define USB_SET_IMAGE_VIDEO_OSD_CFG_CAMERA  USB_SET_IMAGE_VIDEO_OSD_CFG // 设置OSD参数设置
#define USB_GET_IMAGE_MODE                  (USB_CAMERA_BASE+111)   // 获取图像模式
#define USB_SET_IMAGE_MODE                  (USB_CAMERA_BASE+112)   // 设置图像模式
#define USB_GET_IMAGE_WHITE_BALANCE         (USB_CAMERA_BASE+113)   // 获取白平衡参数
#define USB_SET_IMAGE_WHITE_BALANCE         (USB_CAMERA_BASE+114)   // 设置白平衡参数
#define USB_GET_IMAGE_GAMUT                 (USB_CAMERA_BASE+115)   // 获取色域参数
#define USB_SET_IMAGE_GAMUT                 (USB_CAMERA_BASE+116)   // 设置色域参数
#define USB_GET_IMAGE_SHUTTER               (USB_CAMERA_BASE+117)   // 获取快门参数
#define USB_SET_IMAGE_SHUTTER               (USB_CAMERA_BASE+118)   // 设置快门参数
#define USB_GET_VCA_FACE_AE                 (USB_CAMERA_BASE+119)   // 获取Face AE参数
#define USB_SET_VCA_FACE_AE                 (USB_CAMERA_BASE+120)   // 设置Face AE参数
#define USB_GET_VCA_FACE_CENTERED           (USB_CAMERA_BASE+121)   // 获取人脸居中参数
#define USB_SET_VCA_FACE_CENTERED           (USB_CAMERA_BASE+122)   // 设置人脸居中参数
#define USB_GET_VCA_SPOKESMAN_TRACK         (USB_CAMERA_BASE+123)   // 获取发言人跟踪参数
#define USB_SET_VCA_SPOKESMAN_TRACK         (USB_CAMERA_BASE+124)   // 设置发言人跟踪参数
#define USB_GET_VCA_BEAUTY                  (USB_CAMERA_BASE+125)   // 获取美颜参数
#define USB_GET_AUDIO_PICK_UP               (USB_CAMERA_BASE+126)   // 获取拾音
#define USB_SET_AUDIO_PICK_UP               (USB_CAMERA_BASE+127)   // 设置拾音
#define USB_GET_IMAGE_FOCUS                 (USB_CAMERA_BASE+128)   // 获取聚焦灵敏度
#define USB_SET_IMAGE_FOCUS                 (USB_CAMERA_BASE+129)   // 设置聚焦灵敏度
#define USB_GET_IMAGE_OVERHEAD_SHOT         (USB_CAMERA_BASE+130)   // 获取正俯拍模式
#define USB_SET_IMAGE_OVERHEAD_SHOT         (USB_CAMERA_BASE+131)   // 设置正俯拍模式
#define USB_CTRL_MENU                       (USB_CAMERA_BASE+132)   // 视频菜单控制
#define USB_CTRL_IMAGE_PARAM_LOCK           (USB_CAMERA_BASE+133)   // 图像参数锁定
#define USB_GET_IMAGE_DYNAMIC_RANGE         (USB_CAMERA_BASE+134)   // 获取图像色彩空间
#define USB_CTRL_PTZ_BASIC_CONTORL          (USB_CAMERA_BASE+135)   // 云台基础控制
#define USB_CTRL_PTZ_AUTO_FOCUS             (USB_CAMERA_BASE+136)   // 一键自动聚焦
#define USB_CTRL_PTZ_FOCUS_EXCHANGE         (USB_CAMERA_BASE+137)   // 聚焦模式切换

#define USB_GET_TEST_VCM                     (USB_CAMERA_BASE+200)   // VCM校准
#define USB_SET_TEST_VCM                     (USB_CAMERA_BASE+201)   // VCM校准
#define USB_GET_TEST_DTOF_CALIBRATION        (USB_CAMERA_BASE+202)   // DTOF校准
#define USB_SET_TEST_DTOF_CALIBRATION        (USB_CAMERA_BASE+203)   // DTOF校准
#define USB_GET_TEST_DTOF_CHECK              (USB_CAMERA_BASE+204)   // DTOF检测
#define USB_SET_TEST_DTOF_CHECK              (USB_CAMERA_BASE+205)   // DTOF检测
#define USB_GET_TEST_PWM                     (USB_CAMERA_BASE+206)   // 获取PWM占空比
#define USB_GET_TEST_ITOF_DISTANCE           (USB_CAMERA_BASE+207)   // ITOF距离检测
#define USB_SET_TEST_ITOF_DISTANCE           (USB_CAMERA_BASE+208)   // ITOF距离检测
#define USB_GET_TEST_ITOF_FACTORY            (USB_CAMERA_BASE+209)   // ITOF出厂检测
#define USB_SET_TEST_ITOF_FACTORY            (USB_CAMERA_BASE+210)   // ITOF出厂检测
#define USB_GET_TEST_ITOF_FRAME              (USB_CAMERA_BASE+211)   // ITOF单帧检测
#define USB_SET_TEST_ITOF_FRAME              (USB_CAMERA_BASE+212)   // ITOF单帧检测
#define USB_GET_TEST_ITOF_FACTORY2           (USB_CAMERA_BASE+213)   // ITOF出厂检测2
#define USB_SET_TEST_ITOF_FACTORY2           (USB_CAMERA_BASE+214)   // ITOF出厂检测2
#define USB_GET_TEST_ITOF_CALIBRATION        (USB_CAMERA_BASE+215)   // ITOF标定
#define USB_SET_TEST_ITOF_CALIBRATION        (USB_CAMERA_BASE+216)   // ITOF标定
#define USB_GET_TEST_SCENE_CURVE_CHECK       (USB_CAMERA_BASE+217)   // 镜头曲线检测
#define USB_SET_TEST_SCENE_CURVE_CHECK       (USB_CAMERA_BASE+218)   // 镜头曲线检测
#define USB_GET_TEST_SCENE_AGE_CHECK         (USB_CAMERA_BASE+219)   // 镜头老化检测
#define USB_SET_TEST_SCENE_AGE_CHECK         (USB_CAMERA_BASE+220)   // 镜头老化检测
#define USB_SET_TEST_LAMP_CHECK             (USB_CAMERA_BASE+221)   // 指示灯检测
#define USB_GET_TEST_BATTERY_CHECK           (USB_CAMERA_BASE+222)   // 电池检测
#define USB_SET_TEST_BATTERY_CHECK           (USB_CAMERA_BASE+223)   // 电池检测
#define USB_GET_TEST_KNOB_CALIBRATION        (USB_CAMERA_BASE+224)   // 旋钮标定
#define USB_SET_TEST_KNOB_CALIBRATION        (USB_CAMERA_BASE+225)   // 旋钮标定
#define USB_SET_TEST_PARAM_RESET             (USB_CAMERA_BASE+226)   // 参数配置表恢复默认
#define USB_SET_TEST_HIDE_ENDPOINTS          (USB_CAMERA_BASE+227)   // 隐藏端点
#define USB_GET_TEST_HALL                    (USB_CAMERA_BASE+228)   // 霍尔状态获取
#define USB_GET_TEST_DEVICE_LOCATION         (USB_CAMERA_BASE+229)   // 获取设备物理位置
#define USB_GET_TEST_TOUCH_BUTTON            (USB_CAMERA_BASE+230)   // 触摸按键检测
#define USB_SET_TEST_TOUCH_BUTTON            (USB_CAMERA_BASE+231)   // 触摸按键检测
#define USB_GET_TEST_FRAME                   (USB_CAMERA_BASE+232)   // 幅面标定
#define USB_SET_TEST_FRAME                   (USB_CAMERA_BASE+233)   // 幅面标定


//传显命令码
#define USB_TRANSMISSION_BASE               4000
#define USB_SET_SYSTEM_ENCRYPT_DATA         (USB_TRANSMISSION_BASE+1)   //设备加密
#define USB_GET_SYSTEM_ENCRYPT_STATUS       (USB_TRANSMISSION_BASE+2)   //设备加密状态获取
#define USB_GET_SYSTEM_INDICATORLIGHT       (USB_TRANSMISSION_BASE+3)   //获取指示灯状态
#define USB_SET_SYSTEM_INDICATORLIGHT       (USB_TRANSMISSION_BASE+4)   //设置指示灯状态
#define USB_GET_SYSTEM_LOG_DATA             (USB_TRANSMISSION_BASE+5)   //日志文件导出
#define USB_GET_SYSTEM_DEVICE_STATUS_DATA   (USB_TRANSMISSION_BASE+6)   //设备状态文件导出
#define USB_SET_IMAGE_WDR                   (USB_TRANSMISSION_BASE+7)   //设置图像WDR
#define USB_SET_IMAGE_VIDEO_LOGO_SWITCH     (USB_TRANSMISSION_BASE+8)   //设置LOGO开关
#define USB_SET_IMAGE_VIDEO_LOGO_CFG        (USB_TRANSMISSION_BASE+9)   //设置LOGO参数
#define USB_SET_IMAGE_VIDEO_OSD_SWITCH      (USB_TRANSMISSION_BASE+10)   //设置OSD开关
#define USB_SET_IMAGE_VIDEO_OSD_CFG         (USB_TRANSMISSION_BASE+11)   //设置OSD参数设置
#define USB_SET_IMAGE_VIDEO_MULTIPLE_STREAM (USB_TRANSMISSION_BASE+12)   //设置多路复合取流
#define USB_SET_IMAGE_VIDEO_MULTIPLE_IFRAME (USB_TRANSMISSION_BASE+13)   //设置多路复合强制I帧
#define USB_GET_AUDIO_IN_STATUS             (USB_TRANSMISSION_BASE+14)   //获取音频输入状态
#define USB_GET_AUDIO_OUT_STATUS            (USB_TRANSMISSION_BASE+15)   //获取音频输出状态
#define USB_GET_AUDIO_IN_VL                 (USB_TRANSMISSION_BASE+16)   //获取音频输入音量
#define USB_GET_AUDIO_OUT_VL                (USB_TRANSMISSION_BASE+17)   //获取音频输出音量
#define USB_SET_AUDIO_AMER                  (USB_TRANSMISSION_BASE+18)   //设置音频输入选择
#define USB_SET_AUDIO_AO_VA                 (USB_TRANSMISSION_BASE+19)   //设置音频输出音量
#define USB_SET_AUDIO_AECSP                 (USB_TRANSMISSION_BASE+20)   //设置音频AEC延时
#define USB_GET_AUDIO_DEVICE_DELAY          (USB_TRANSMISSION_BASE+21)   //获取音频延时自动优化
#define USB_SET_AUDIO_DEVICE_DELAY          (USB_TRANSMISSION_BASE+22)   //设置音频延时自动优化
#define USB_SET_AUDIO_BT                    (USB_TRANSMISSION_BASE+23)   //设置蓝牙扫描状态
#define USB_GET_AUDIO_BT_MAC                (USB_TRANSMISSION_BASE+24)   //获取蓝牙MAC地址
#define USB_GET_AUDIO_BT_STATUS             (USB_TRANSMISSION_BASE+25)   //获取蓝牙连接状态
#define USB_GET_AUDIO_DETECT                (USB_TRANSMISSION_BASE+26)   //获取音频输入输出自检
#define USB_SET_AUDIO_DETECT                (USB_TRANSMISSION_BASE+27)   //设置音频输入输出自检
#define USB_GET_AUDIO_EFFICT_DETECT         (USB_TRANSMISSION_BASE+28)   //获取音效自检
#define USB_SET_AUDIO_EFFICT_DETECT         (USB_TRANSMISSION_BASE+29)   //设置音效自检
#define USB_GET_AUDIO_FAC_TEST              (USB_TRANSMISSION_BASE+30)   //获取音频生产测试
#define USB_SET_AUDIO_FAC_TEST              (USB_TRANSMISSION_BASE+31)   //设置音频生产测试
#define USB_SET_AUDIO_AGC_CONFIG            (USB_TRANSMISSION_BASE+32)   //设置音频AGC配置
#define USB_SET_AUDIO_REDUCE_NOISE          (USB_TRANSMISSION_BASE+33)   //设置音频降噪
#define USB_GET_AUDIO_RECOG_RSLT            (USB_TRANSMISSION_BASE+34)   //获取语音识别结果上传
#define USB_SET_AUDIO_RECOG_RSLT            (USB_TRANSMISSION_BASE+35)   //设置语音识别结果上传
#define USB_GET_AUDIO_DUMP_DATA             (USB_TRANSMISSION_BASE+36)   //音频数据导出
#define USB_SET_PTZ_TRACK_MODE              (USB_TRANSMISSION_BASE+37)   //设置跟随模式
#define USB_SET_PTZ_PRESET_CFG              (USB_TRANSMISSION_BASE+38)   //预置点设置，仅手动模式支持配置
#define USB_SET_PTZ_PRESET_CALL             (USB_TRANSMISSION_BASE+39)   //预置点调用，仅手动模式支持配置
#define USB_SET_PTZ_PRESET_DELETE           (USB_TRANSMISSION_BASE+40)  //预置点删除，仅手动模式支持配置
#define USB_SET_PTZ_AUTO_TRACK_SENSITIVITY  (USB_TRANSMISSION_BASE+41)  //设置自动跟随灵敏度，仅自动跟随模式支持
#define USB_GET_PRIVACY                     (USB_TRANSMISSION_BASE+42)  //获取隐私罩
#define USB_SET_PRIVACY                     (USB_TRANSMISSION_BASE+43)  //设置隐私罩
#define USB_SET_AUDIO_ECHO                  (USB_TRANSMISSION_BASE+44)  //ECHO诊断
//#define USB_SET_SYSTEM_DEVICE_SIGNAL_TRANS  (USB_TRANSMISSION_BASE+45)  //主控信令设置
#define USB_SET_AUDIO_SIGNAL_TRANS          (USB_TRANSMISSION_BASE+46)  //音频控制信令设置
#define USB_GET_AUDIO_INPUT_OUTPUT_CHANNELINFO (USB_TRANSMISSION_BASE+47)//音频输入输出通道信息获取
#define USB_GET_AUDIO_PROCESS_LINE_CFG      (USB_TRANSMISSION_BASE+48)  //获取音频产线测试配置
#define USB_SET_AUDIO_PROCESS_LINE_CFG      (USB_TRANSMISSION_BASE+49)  //设置音频产线测试配置
#define USB_GET_AUDIO_POE_LINK_STATUS       (USB_TRANSMISSION_BASE+50)  //获取音频POE供电网口检测状态
#define USB_GET_SYSTEM_DEVICE_CAPABILITIES  (USB_TRANSMISSION_BASE+51)  //获取设备SVC能力
#define USB_GET_IMAGE_VIDEO_SVC_MULTIPLE_STREAM (USB_TRANSMISSION_BASE+52) //获取SVC多码流信息
#define USB_GET_IMAGE_WDR                   (USB_TRANSMISSION_BASE+53)   //获取图像WDR

#define USB_GET_VCA_SWITCH                  (USB_TRANSMISSION_BASE+101)  //获取智能功能开关
#define USB_SET_VCA_SWITCH                  (USB_TRANSMISSION_BASE+102)  //设置智能功能开关
#define USB_GET_VCA_SNAPSHOT                (USB_TRANSMISSION_BASE+103)  //获取智能抓图（图片通过大文件传输）
#define USB_GET_VCA_FACE_THRESHOLD          (USB_TRANSMISSION_BASE+104)  //获取智能目标识别的相似度阈值
#define USB_SET_VCA_FACE_THRESHOLD          (USB_TRANSMISSION_BASE+105)  //设置智能目标识别的相似度阈值
#define USB_GET_VCA_FACE_ATTRIBUTES         (USB_TRANSMISSION_BASE+106)  //获取智能目标识别的属性
#define USB_SET_VCA_FACE_ATTRIBUTES         (USB_TRANSMISSION_BASE+107)  //设置智能目标识别的属性
#define USB_GET_VCA_FACE_DETECT_RULE        (USB_TRANSMISSION_BASE+108)  //获取智能人脸检测的规则
#define USB_SET_VCA_FACE_DETECT_RULE        (USB_TRANSMISSION_BASE+109)  //设置智能人脸检测的规则
#define USB_GET_VCA_FACE_QUALITY            (USB_TRANSMISSION_BASE+110)  //获取智能人脸检测质量评估
#define USB_SET_VCA_FACE_QUALITY            (USB_TRANSMISSION_BASE+111)  //设置智能人脸检测质量评估
#define USB_SET_VCA_PIC_DOWNLOAD            (USB_TRANSMISSION_BASE+112)  //图片下载建模（图片通过大文件传输）
#define USB_GET_VCA_FACE_BASE_DATA_CFG      (USB_TRANSMISSION_BASE+113)  //获取人脸底库配置
#define USB_SET_VCA_FACE_BASE_DATA_CFG      (USB_TRANSMISSION_BASE+114)  //设置人脸底库配置
#define USB_GET_VCA_ELECTRONICSIGNAGE_CFG   (USB_TRANSMISSION_BASE+115)  //获取电子铭牌配置
#define USB_SET_VCA_ELECTRONICSIGNAGE_CFG   (USB_TRANSMISSION_BASE+116)  //设置电子铭牌配置
#define USB_GET_VCA_FACE_DETECT             (USB_TRANSMISSION_BASE+117)  //获取智能人脸检测信息
#define USB_SET_VCA_FACE_DETECT             (USB_TRANSMISSION_BASE+118)  //设置智能人脸检测信息
#define USB_GET_VCA_FACE_CONTRAST           (USB_TRANSMISSION_BASE+119)  //获取智能人脸比对信息
#define USB_SET_VCA_FACE_CONTRAST           (USB_TRANSMISSION_BASE+120)  //设置智能人脸比对信息

//传显大容量设备命令码
#define USB_TRANSMISSION_BULK_BASE           4500
#define USB_CTRL_RESET_DEVICE                (USB_TRANSMISSION_BULK_BASE+0)  //重置设备
#define USB_GET_DEVICE_VERSION               (USB_TRANSMISSION_BULK_BASE+1)  //获取设备版本信息

#define USB_TRANS_DEVICE_ENCRYPTION_START    (USB_TRANSMISSION_BULK_BASE+100)  //设备加密开始
#define USB_TRANS_DEVICE_ENCRYPTION_PROGRESS (USB_TRANSMISSION_BULK_BASE+101)  //获取加密进度
#define USB_TRANS_DEVICE_ENCRYPTION_STOP     (USB_TRANSMISSION_BULK_BASE+102)  //设备加密结束
#define USB_TRANS_FILE_UPLOAD_START          (USB_TRANSMISSION_BULK_BASE+103)  //文件上传开始
#define USB_TRANS_FILE_UPLOAD_PROGRESS       (USB_TRANSMISSION_BULK_BASE+104)  //获取上传进度
#define USB_TRANS_FILE_UPLOAD_STOP           (USB_TRANSMISSION_BULK_BASE+105)  //文件上传结束
#define USB_TRANS_FILE_DOWNLOAD_START        (USB_TRANSMISSION_BULK_BASE+106)  //文件下载开始
#define USB_TRANS_FILE_DOWNLOAD_PROGRESS     (USB_TRANSMISSION_BULK_BASE+107)  //获取下载进度
#define USB_TRANS_FILE_DOWNLOAD_STOP         (USB_TRANSMISSION_BULK_BASE+108)  //文件下载结束

/************************************************************************
* 定义取流类型
************************************************************************/
#define USB_STREAM_UNKNOW     0
#define USB_STREAM_PCM        1    // PCM裸码流(DirectShow枚举出的PCM类型为1,保持一致)
#define USB_STREAM_MJPEG      101  // MJPEG裸码流
#define USB_STREAM_H264       102  // H264裸码流(需相机支持H264裸流输出)
#define USB_STREAM_YUY2       103  // YUV2裸码流
#define USB_STREAM_NV12       104  // NV12裸码流

/************************************************************************
* 定义预览,码流回调码流类型
************************************************************************/
#define USB_STREAM_PS_H264    201  // PS封装H264码流
#define USB_STREAM_PS_MJPEG   202  // PS封装MJPEG码流
#define USB_STREAM_PS_YUY2    203  // PS封装YUV2码流
#define USB_STREAM_PS_NV12    204  // PS封装YUV2码流

/************************************************************************
* 定义录像码流类型
************************************************************************/
#define USB_RECORDTYPE_PS_MJPEG        301     // 录制PS封装MJPEG码流
#define USB_RECORDTYPE_PS_H264         302     // 录制PS封装H264码流
#define USB_RECORDTYPE_MP4             303     // 录制MP4
#define USB_RECORDTYPE_AVI             304     // 录制AVI
#define USB_RECORDTYPE_PS_YUY2         305     // 录制PS封装YUY2码流
#define USB_RECORDTYPE_PS_NV12         306     // 录制PS封装NV12码流

/************************************************************************
* 通道类型: RGB或IR
************************************************************************/
#define USB_CHANNEL_RGB		1    //RGB路
#define USB_CHANNEL_IR      2    //IR路

/************************************************************************
* 图像参数类型
************************************************************************/
#define USB_Brightness                0                               // 亮度
#define USB_Contrast                  USB_Brightness   + 1      // 对比度
#define USB_Hue                       USB_Contrast     + 1        
#define USB_Saturation                USB_Hue          + 1
#define USB_Sharpness                 USB_Saturation   + 1      // 饱和度
#define USB_Gamma                     USB_Sharpness    + 1
#define USB_ColorEnable               USB_Gamma        + 1
#define USB_WhiteBalance              USB_ColorEnable  + 1      // 白平衡
#define USB_BacklightCompensation     USB_WhiteBalance + 1      // 背光补偿
#define USB_Gain


#define USB_VIDEO_DEVICE       100              // 视频设备
#define USB_AUDIO_DEVICE       101              // 音频设备

#define USBCAMERA_INVALID_ID -1


/**	@enum
*  @brief 事件码定义
*
*/
enum
{
    USB_EC_DEVICE_LOST = 31,      // DirectShow设备插拔事件
};

/**	@enum
*  @brief 事件类型定义
*
*/
#define USB_EVENTTYPE_DEV_REMOVED 0
#define USB_EVENTTYPE_DEV_ADDED   1



/**	@enum
*  @brief 人脸抓拍模式
*
*/
enum
{
    USB_FD_AUTOCAPTURE = 0,
    USB_FD_MANNUALCAPTURE,
    USB_FD_NOCAPTURE,
};


#define MAX_THERMAL_REGIONS     10
#define MAX_ROI_REGIONS   10   //最大支持10个区域


typedef enum tagLOG_LEVEL_ENUM
{
    ENUM_ERROR_LEVEL = 1,
    ENUM_DEBUG_LEVEL = 2,
    ENUM_INFO_LEVEL = 3
} LOG_LEVEL_ENUM;

    // 条件参数
    typedef struct tagUSB_COMMON_COND
    {
        DWORD dwSize;
        BYTE  byChannelID;     //通道号
        BYTE  bySID;           //场景ID
        BYTE  byRes[6];
    }USB_COMMON_COND, *LPUSB_COMMON_COND;

    //设备系统信息
    typedef struct tagUSB_SYSTEM_DEVICE_INFO
    {
        DWORD  dwSize;
        BYTE   byFirmwareVersion[64]; //主控程序版本
        BYTE   byEncoderVersion[64];  //编码版本
        BYTE   byHardwareVersion[64]; //机芯版本
        BYTE   byDeviceType[64];      //设备型号
        BYTE   byProtocolVersion[4];  //协议版本信息："1.0"
        BYTE   bySerialNumber[64];    //序列号
		BYTE   bySecondHardwareVersion[64];	//副程序版本
        BYTE   byModuleID[32];  //机芯ID
        BYTE   byDeviceID[64];  //设备ID
        BYTE   byDeviceAssembleType; //设备组装类型：1-整机设备  2-集成类设备
        BYTE   byManufacturer; //厂商信息：1-标配设备  2-中性设备
        BYTE   byLanguageType; //语言类型：1-中文  2-英文
        BYTE   byDeviceClass; //设备种类：1-观测类设备  2-温测类设备
        BYTE   byRes[24];
    }USB_SYSTEM_DEVICE_INFO, *LPUSB_SYSTEM_DEVICE_INFO;

    //硬件服务参数配置
    typedef struct tagUSB_SYSTEM_HARDWARE_SERVER
    {
        DWORD  dwSize;
        BYTE  byUsbMode;  //USB模式切换  1-USB的UVC模式, 2-USB的NCM模式
        BYTE  byDeviceInitialStatus;  //设备初始化状态  1-未初始化, 2-初始化完成
        BYTE  byDeviceWorkingStatus;  //设备工作状态  1-运行在factory程序, 2-运行在update程序
        BYTE  byRes[29];
    }USB_SYSTEM_HARDWARE_SERVER, *LPUSB_SYSTEM_HARDWARE_SERVER;

    //校时
    typedef struct tagUSB_SYSTEM_LOCALTIME
    {
        DWORD     dwSize;
        WORD      wMillisecond;//毫秒
        BYTE       bySecond;//秒
        BYTE       byMinute;//分钟
        BYTE       byHour;//小时
        BYTE       byDay;//日
        BYTE       byMonth;//月
        BYTE       byRes1[1];
        WORD       wYear;//年
        BYTE       byExternalTimeSourceEnabled;//外部校时源使能, 0-关闭，1-开启
        BYTE       byRes[5];
    }USB_SYSTEM_LOCALTIME, *LPUSB_SYSTEM_LOCALTIME;

    //图像亮度调节
    typedef struct tagUSB_IMAGE_BRIGHTNESS
    {
        DWORD  dwSize;
        DWORD  dwBrightness;       //图像亮度0-100
        BYTE   byRes[28];
    }USB_IMAGE_BRIGHTNESS, *LPUSB_IMAGE_BRIGHTNESS;

    //图像对比度调节
    typedef struct tagUSB_IMAGE_CONTRAST
    {
        DWORD     dwSize;
        DWORD dwContrast;      //图像对比度0-100
        BYTE  byRes[28];
    }USB_IMAGE_CONTRAST, *LPUSB_IMAGE_CONTRAST;

    //诊断信息导出前置条件（该结构体内部研发专用，外部用户无需关心及使用）
    typedef struct tagUSB_SYSTEM_DIAGNOSED_DATA_COND
    {
        DWORD  dwSize;
        BYTE    byDataType;//导出设备数据位置: 1-PSRAM, 2-FLASH
        BYTE    byRes1[3];
        DWORD   dwAddress;//导出设备数据地址
        DWORD   dwLength;//导出设备数据长度, 最大支持100k, 超出返回设备不支持
        BYTE    byRes[112];
    }USB_SYSTEM_DIAGNOSED_DATA_COND, *LPUSB_SYSTEM_DIAGNOSED_DATA_COND;

    //诊断信息导出
    typedef struct tagUSB_SYSTEM_DIAGNOSED_DATA
    {
        DWORD     dwSize;
        DWORD   dwDataLenth;     //诊断数据长度
        BYTE   *pDiagnosedData;     //诊断数据
        BYTE   byRes[56];
    }USB_SYSTEM_DIAGNOSED_DATA, *LPUSB_SYSTEM_DIAGNOSED_DATA;

    //系统能力
    typedef struct tagUSB_SYSTEM_CAPABILITIES
    {
        DWORD	dwSize;
        BYTE  byXuSystemCtrl;  //系统管理 0-不支持  1-支持
        BYTE  byXuImageCtrl;  //视频图像管理  0-不支持  1-支持
        BYTE  byXuThermalCtrl;  //热成像管理  0-不支持  1-支持
        BYTE  byRes[505];
    }USB_SYSTEM_CAPABILITIES, *LPUSB_SYSTEM_CAPABILITIES;

    //设备ISP bin文件导出
    typedef struct tagUSB_SYSTEM_ISP_BIN_FILE
    {
        DWORD	dwSize;
        DWORD dwDataLenth;      //ISP bin文件长度
        BYTE   *pData;     //ISP bin文件数据
        BYTE  byRes[52];
    }USB_SYSTEM_ISP_BIN_FILE, *LPUSB_SYSTEM_ISP_BIN_FILE;

    //设备融合参数bin文件导出
    typedef struct tagUSB_SYSTEM_FUSION_BIN_FILE
    {
        DWORD	dwSize;
        DWORD dwDataLenth;      //融合参数bin文件长度
        BYTE   *pData;     //融合参数bin文件数据
        BYTE  byRes[52];
    }USB_SYSTEM_FUSION_BIN_FILE, *LPUSB_SYSTEM_FUSION_BIN_FILE;

    //系统初始化
    typedef struct tagUSB_SYSTEM_INIT
    {
        DWORD dwSize;
        BYTE byDataStorage; //数据存储 0-关闭  1-开启
        BYTE byRes[251];
    }USB_SYSTEM_INIT, *LPUSB_SYSTEM_INIT;

    //图像增强
    typedef struct tagUSB_IMAGE_ENHANCEMENT
    {
        DWORD dwSize;
        BYTE  byNoiseReduceMode;  //数字降噪模式：0-关闭; 1-普通模式;  2 - 专家模式
        BYTE  byBirdWatchingMode;  //观鸟模式使能：0-关闭; 1-开启
        BYTE  byHighLightMode;  //红热凸显模式使能：0-关闭; 1-开启
        BYTE  byHighLightLevel;  //红热凸显等级：0-100
        DWORD dwGeneralLevel;  //普通模式降噪级别 0-100
        DWORD dwFrameNoiseReduceLevel; //专家模式空域降噪级别 0-100
        DWORD dwInterFrameNoiseReduceLevel;  //专家模式时域降噪级别 0-100
        BYTE  byPaletteMode; //伪彩色颜色模式：1-白热;  2-黑热;  10-融合1; 11-彩虹; 12-融合2; 13-铁红1; 14-铁红2; 15-深褐色; 16-色彩1; 17-色彩2; 18-冰火; 19-雨; 20-红热; 21-绿热; 22-深蓝
        BYTE  byLSEDetailEnabled;  //图像细节增强使能: 0-关闭 1-开启
        BYTE  byHookEdgeMode;  //勾边模式使能: 0-关闭  1-开启
        BYTE  byHookEdgeLevel;  //勾边等级: 0-100
        DWORD dwLSEDetailLevel;  //图像细节增强等级: 0-100
        BYTE  byWideTemperatureMode;  //温宽模式使能：0-关闭  1-开启
        BYTE  byWideTemperatureWork; //温宽工作模式: 1-温宽模式上下限均配置 2-温宽模式只配置上限  3-温宽模式只配置下限
        BYTE  byIspAgcMode; //agc工作模式: 1-线性模式  2-直方图模式  3-巡检模式  4-手动模式
        BYTE  byAISuperResolution; //AI超分使能：0-关闭 1-开启
        DWORD  dwWideTemperatureUpThreshold;  //温宽模式上阈值，-20.0℃~400.0℃(精确到小数点后一位)，传输时(实际值+100)*10换算成正整数
        DWORD  dwWideTemperatureDownThreshold;  //温宽模式下阈值，-20.0℃~400.0℃(精确到小数点后一位)，传输时(实际值+100)*10换算成正整数
        BYTE  byRes[28];
    }USB_IMAGE_ENHANCEMENT, *LPUSB_IMAGE_ENHANCEMENT;

    //图像增强EX
    typedef struct tagUSB_IMAGE_ENHANCEMENT_EX
    {
        USB_IMAGE_ENHANCEMENT struImageEnhancement;
        BYTE  bySkyAreaCullLevel; //天空区域剔除百分比：0-100
        BYTE  byAGCMode; //AGC模式：1-手动 2-自动
        BYTE  byGaussianFilterEnabled; //高斯滤波使能：0-关闭  1-开启
        BYTE  byEdgePreservingFilterEnabled; //保边滤波使能：0-关闭  1-开启
        DWORD  dwGaussianFilterCenterPoint; //高斯滤波中心点参数：64-4098
        DWORD  dwBilateralFilterRadius; //双边滤波半径：1-8
        DWORD  dwBilateralFilterEdgeThreshold; //双边滤波边缘判断门限：1-1023
        BYTE  byBurnPreventionEnabled; //防灼烧模式使能：0-关闭  1-开启
        BYTE  byBurnPreventionMode; //防灼烧控制模式：1-自动控制模式  2-手动控制模式
        BYTE  byRelativeHumidityThreshold; //相对湿度阈值范围：0-100，单位：%（百分比），传输时实际值 + 1
        BYTE bySharpenBoost;  //锐化增强使能：1-关闭  2-开启
        DWORD  dwBurnPreventionShutterCloseTime; //防灼烧挡片闭合时间(仅自动模式下生效)：0-3600秒
        BYTE  byBurnPreventionShutterControl; //防灼烧挡片手动控制(仅手动模式下生效)：1-不控制  2-挡片闭合  3-挡片抬起
        BYTE  byBurnPreventionRecovery; //防灼烧自恢复使能：0-关闭  1-开启
        BYTE  byIsothermEnabled; //等温线开启使能：0-关闭 1-开启
        BYTE  byRawDataNoiseReduceEnabled; //裸数据降噪使能：0-关闭  1-开启
        DWORD  dwIsothermalUpperThreshold;  //等温线温度上阈值：-20℃~600℃，传输时(实际值+100)*10换算成正整数
        DWORD  dwIsothermalLowerThreshold;  //等温线温度下阈值：-20℃~600℃，传输时(实际值+100)*10换算成正整数
        BYTE  byIsothermalType;  //等温线显示类型：1-白热等温; 2-黑热等温; 3-熔岩等温; 4-铁红等温; 5-热铁等温; 6-医疗等温; 7-北极等温; 8-彩虹1等温; 9-彩虹2等温; 10-描红等温
        BYTE  byColorAlarmType;  //颜色报警类型类型：0 - 无报警，关闭颜色报警; 1 - 高温报警 高温凸显; 2 - 低温报警 低温凸显; 3 - 区间报警 区间凸显; 4 - 保温报警 保温凸显;
        //5 - 冷凝报警; 9 - 高温两段式伪彩 高温聚焦; 10 - 低温两段式伪彩 低温聚焦; 11 - 区间两段式伪彩 区间聚焦; 12 - 湿度检测; 13 - 热点检测; 14 - 冷点检测
        DWORD  dwColorAlarmUpperLimit; //颜色报警模式上限阈值：-20℃~2000℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwColorAlarmLowerLimit; //颜色报警模式下限阈值：-20℃~2000℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwRelativeHumidity; //相对湿度，用于湿度检测（保留一位小数）范围：0.0-100.0，单位：%（百分比），传输时(实际值 + 1) * 10换算成正整数
        DWORD  dwAtmosphericTemperature;  //大气温度（保留一位小数）范围：0.0-100.0，单位：℃（摄氏度），传输时(实际值 + 1) * 10换算成正整数
        BYTE  byAutoShutEnabled; //自动挡片使能，使能关闭时，设备端不再自动触发挡片 1 – 关闭 2 – 开启
        BYTE byGeneralLevelDefault;  //普通模式降噪级别默认值
        BYTE byGeneralLevelMin;  //普通模式降噪级别最小值
        BYTE byGeneralLevelMax;  //普通模式降噪级别最大值
        BYTE  byRes[386];
    }USB_IMAGE_ENHANCEMENT_EX, *LPUSB_IMAGE_ENHANCEMENT_EX;

    //视频调整
    typedef struct tagUSB_IMAGE_VIDEO_ADJUST
    {
        DWORD  dwSize;
        BYTE  byImageFlipStyle;  //镜像模式: 0-关闭 1-中心 2-左右 3-上下
        BYTE  byPowerLineFrequencyMode;  //视频制式：1-PAL(50HZ)
        BYTE  byCorridor;  //镜头走廊模式(旋转): 0-关闭 1-开启
        BYTE  byDigitalZoom;  //数字变倍: 0-X1   1-X2   2-X4   3-X8
        BYTE  byCursor;  //显示射表: 0-关闭   1-开启
        BYTE  byBadPointCursor;  //显示坏点十字光标：0-关闭  1-开启
        BYTE  byBadPointCursorShiftMode; //移动坏点十字光标方式：0-下发坐标  1-移动指令
        BYTE  byMappingStyle;  //射表样式：1-5
        DWORD  dwCursorPointX;  //射表X坐标, 归一化0-1000, 左上为原点
        DWORD  dwCursorPointY;  //射表Y坐标, 归一化0-1000, 左上为原点
        DWORD  dwBadCursorPointX;  //坏点十字光标X坐标，归一化0-1000，左上为原点（byBadPointCursorShiftMode为0时有效）
        DWORD  dwBadCursorPointY;  //坏点十字光标Y坐标，归一化0-1000，左上为原点（byBadPointCursorShiftMode为0时有效）
        BYTE  byPointXShiftLeft;  //坏点十字光标X坐标向左移动，范围：0-15（byBadPointCursorShiftMode为1时有效）
        BYTE  byPointXShiftRight;  //坏点十字光标X坐标向右移动，范围：0-15（byBadPointCursorShiftMode为1时有效）
        BYTE  byPointYShiftUp;  //坏点十字光标Y坐标向上移动，范围：0-15（byBadPointCursorShiftMode为1时有效）
        BYTE  byPointYShiftDown;  //坏点十字光标Y坐标向下移动，范围：0-15（byBadPointCursorShiftMode为1时有效）
        BYTE  byDeleteBadPoint;  //去坏点操作：0-无效操作; 1-增加十字光标中心点坐标到坏点表中; 2-从坏点表中删除十字光标中心点坐标
        BYTE  byCursorColor; //射表颜色：1-白色  2-黑色  3-绿色  4-红色
        BYTE  byImageFlipStyleDefaultState;  //镜像模式默认状态: 0-关闭 1-中心 2-左右 3-上下
        BYTE  byPowerLineFrequencyModeDefaultState;  //视频制式默认状态：1-PAL(50HZ) 2-NTSC(60HZ)
    }USB_IMAGE_VIDEO_ADJUST, *LPUSB_IMAGE_VIDEO_ADJUST;

    //加密状态
    typedef struct tagUSB_SYSTEM_ENCRYPT_STATUS
    {
        DWORD	dwSize;
        BYTE	byEncryptStatus;	//加密状态：0-保留，1-加密成功，2-加密失败
        BYTE	byErrMsg;			//加密失败原因：0-保留，0xFF-其他错误
        BYTE	byRes[30];
    } USB_SYSTEM_ENCRYPT_STATUS, *LPUSB_SYSTEM_ENCRYPT_STATUS;

    //指示灯控制
    typedef struct tagUSB_SYSTEM_INDICATORLIGHT
    {
        DWORD	dwSize;
        BYTE	byStatus;			//闪烁状态：0-未闪烁，1-闪烁
        BYTE	byColour;			//颜色：1-red，2-white
        BYTE	byRes[30];
    } USB_SYSTEM_INDICATORLIGHT, *LPUSB_SYSTEM_INDICATORLIGHT;

    //图像WDR
    typedef struct tagUSB_IMAGE_WDR
    {
        DWORD	dwSize;
        BYTE	byEnabled;		//使能：0-关闭，1-开启
        BYTE	byMode;			//模式：0-100
        BYTE	byLevel;		//等级：0-100
        BYTE    byEnabledDefaultState;      //使能默认状态：0-关闭，1-开启
        BYTE	byRes[28];
    }USB_IMAGE_WDR, *LPUSB_IMAGE_WDR;

    //LOGO开关
    typedef struct tagUSB_IMAGE_VIDEO_LOGO_SWITCH
    {
        DWORD	dwSize;
        BYTE	byEnabled;		//使能：0-关闭，1-开启
        BYTE	byChannelID;	//通道号
        BYTE	byType;			//OSD叠加图像类型：1-源图像，2-显示端，3-上墙处叠加，4-编码处叠加
        BYTE	byPortID;		//端口号：0-2
        BYTE	byPictureID;	//图片索引
        BYTE	byLogoID;		//Logo编号：0-2
        BYTE	byRes[30];
    }USB_IMAGE_VIDEO_LOGO_SWITCH, *LPUSB_IMAGE_VIDEO_LOGO_SWITCH;

    //LOGO参数设置
    typedef struct tagUSB_IMAGE_VIDEO_LOGO_CFG
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//通道号
        BYTE	byLogoID;			//Logo编号：0-2
        BYTE	byLogoType;			//logo类型：1-通用，2-音量，3-鼠标
        BYTE	byLogoPicNums;		//logo图片数量
        DWORD	dwRegionX;			//区域左上顶点X坐标，归一化值，范围0-1000
        DWORD	dwRegionY;			//区域左上顶点Y坐标，归一化值，范围0-1000
        DWORD	dwRegionWidth;		//区域宽度，归一化值，范围0-1000
        DWORD	dwRegionHeight;		//区域高度，归一化值，范围0-1000
        BYTE	byFlickerControl;	//闪烁控制
        BYTE	byShieldColorY;		//屏蔽色Y
        BYTE	byShieldColorU;		//屏蔽色U
        BYTE	byShieldColorV;		//屏蔽色V
        BYTE	byRes[32];
    }USB_IMAGE_VIDEO_LOGO_CFG, *LPUSB_IMAGE_VIDEO_LOGO_CFG;

    //OSD开关
    typedef struct tagUSB_IMAGE_VIDEO_OSD_SWITCH
    {
        DWORD	dwSize;
        BYTE	byEnabled;		//使能：0-关闭，1-开启
        BYTE	byChannelID;	//通道号
        BYTE	byType;			//OSD叠加图像类型：1-源图像，2-显示端，3-上墙处叠加，4-编码处叠加
        BYTE	byPortID;		//端口号：0-2
        BYTE	byRes[32];
    }USB_IMAGE_VIDEO_OSD_SWITCH, *LPUSB_IMAGE_VIDEO_OSD_SWITCH;

    //OSD属性
    typedef struct tagUSB_OSD_PROPERTY
    {
        BYTE    byRowID;                    //行ID，从1开始递增
        BYTE    byRes1[3];
        DWORD   dwRegionX;                  //区域左上顶点X坐标，归一化值，范围0-1000
        DWORD   dwRegionY;                  //区域左上顶点Y坐标，归一化值，范围0-1000
        DWORD   dwBackgroundColor;          //背景色
        DWORD   dwFontColor;                //字体颜色
        BYTE    byVerticalScalingRatio;     //垂直缩放比例，范围0-4
        BYTE    byHorizontalScalingRatio;   //水平缩放比例，范围0-4
        BYTE    byRowCharNums;              //该行字符数，0-32
        BYTE    byRes2;
        WORD    wCharacterCode[32];         //字符码，0-32
    }USB_OSD_PROPERTY, *LPUSB_OSD_PROPERTY;

    //OSD参数设置
    typedef struct tagUSB_IMAGE_VIDEO_OSD_CFG
    {
        DWORD	dwSize;
        BYTE	byChannelID;				//通道号
        BYTE	byType;						//OSD叠加图像类型：1-源图像，2-显示端，3-上墙处叠加，4-编码处叠加
        BYTE	byPortID;					//端口号：0-2
        BYTE	byAutoBrightness;			//自动调整亮度：0-关闭，1-开启
        BYTE	byTranslucent;				//是否半透明：0-关闭，1-开启
        BYTE    byRes1[3];
        DWORD	dwFlickerControl;			//闪烁控制
        USB_OSD_PROPERTY struOSDProperty[4];//OSD参数
        BYTE	byRes[32];
    }USB_IMAGE_VIDEO_OSD_CFG, *LPUSB_IMAGE_VIDEO_OSD_CFG;

    //多路复合取流
    typedef struct tagUSB_IMAGE_VIDEO_MULTIPLE_STREAM
    {
        DWORD	dwSize;
        BYTE	byChannelID;			//多路复合流通道号，目前最多支持3路流复合，范围0-2
        BYTE    byRes1[3];
        DWORD	dwEncWidth;				//编码宽，范围640 - 1920
        DWORD	dwEncHeight;			//编码高 360 - 1080
        BYTE	byVideoType;			//编码类型 1 - Standard H264
        BYTE    byRes2[3];
        DWORD	dwIFrameInterval;		//I帧间隔 0 - 9000
        DWORD	dwBitrate;				//编码码率，单位bps
        BYTE	byBpsType;				//编码码率控制类型：1-VBR，2-CBR
        BYTE	byProfile;				/*编码协议：1-H.264编码的profile BP
                                        2-H.264编码的profile MP
                                        3-H.264编码的profile HP
                                        4-H.264编码的profile SVC*/
        BYTE	byFps;					//编码帧率，范围0-30
        BYTE	byRes[29];
    }USB_IMAGE_VIDEO_MULTIPLE_STREAM, *LPUSB_IMAGE_VIDEO_MULTIPLE_STREAM;

    //多路复合取流强制I帧
    typedef struct tagUSB_IMAGE_VIDEO_MULTIPLE_IFRAME
    {
        DWORD	dwSize;
        BYTE	byChannelID;			//通道号
        BYTE	byIFrameFlag;			//是都强制I帧：0-关闭，1-开启
        BYTE	byRes[30];
    }USB_IMAGE_VIDEO_MULTIPLE_IFRAME, *LPUSB_IMAGE_VIDEO_MULTIPLE_IFRAME;

    //音频状态
    typedef struct tagUSB_AUDIO_STATUS
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//音频通道号
        BYTE	byConnectStatus;	//音频状态：0-未接入，1-接入
        BYTE	byRes[30];
    }USB_AUDIO_STATUS, *LPUSB_AUDIO_STATUS;

    //音频音量
    typedef struct tagUSB_AUDIO_VOLUME
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//音频通道号
        BYTE	byVolume;			//音量值
        BYTE	byRes[30];
    }USB_AUDIO_VOLUME, *LPUSB_AUDIO_VOLUME;

    //音频输入选择
    typedef struct tagUSB_AUDIO_AMER
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//音频通道号
        BYTE	byEnabled;			//音频输入通道使能：0-关闭，1-开启
        BYTE	byRes[30];
    }USB_AUDIO_AMER, *LPUSB_AUDIO_AMER;

    //AEC延时配置
    typedef struct tagUSB_AUDIO_AECSP
    {
        DWORD   dwSize;
        BYTE    byInChannelID;      //音频输入通道号
        BYTE    byEnabled;          //AEC使能：0-关闭，1-开启
        WORD    wAecValue;          //时延值，范围0-1000
        BYTE    byOutChannelID;     //音频输出通道号
        BYTE    byRes[31];
    }USB_AUDIO_AECSP, *LPUSB_AUDIO_AECSP;

    //延时自动优化
    typedef struct tagUSB_AUDIO_DEVICE_DELAY
    {
        DWORD	dwSize;
        BYTE	byInChannelID;		//音频输入通道号
        BYTE	byOutChannelID;		//音频输出通道号
        BYTE	byProcessMode;		//测试过程：1-开始测试，2-获取结果
        BYTE    byRes1;
        WORD	wAecValue;			//时延值，范围0-1000
        BYTE	byRes[30];
    }USB_AUDIO_DEVICE_DELAY, *LPUSB_AUDIO_DEVICE_DELAY;

    //蓝牙扫描状态
    typedef struct tagUSB_AUDIO_BT
    {
        DWORD	dwSize;
        BYTE	byEnabled;			//蓝牙扫描使能：0-关闭，1-开启
        BYTE	byRes[31];
    }USB_AUDIO_BT, *LPUSB_AUDIO_BT;

    //蓝牙MAC地址
    typedef struct tagUSB_AUDIO_BT_MAC
    {
        DWORD	dwSize;
        BYTE	byMacAddress[40];	//蓝牙MAC地址
        BYTE	byRes[32];
    }USB_AUDIO_BT_MAC, *LPUSB_AUDIO_BT_MAC;

    //蓝牙连接状态
    typedef struct tagUSB_AUDIO_BT_STATUS
    {
        DWORD	dwSize;
        BYTE	byConnectStatus;	//蓝牙连接状态：0-未连接，1-连接
        BYTE	byRes[31];
    }USB_AUDIO_BT_STATUS, *LPUSB_AUDIO_BT_STATUS;

    //音频自检
    typedef struct tagUSB_AUDIO_DETECT
    {
        DWORD	dwSize;
        BYTE	byInChannelID;		//音频输入通道号
        BYTE	byOutChannelID;		//音频输出通道号
        BYTE	byProcessMode;		//测试过程：1-开始测试，2-获取结果
        BYTE	byTestResult;		//测试结果：1-自检正确，2-自检错误
        BYTE	byRes[32];
    }USB_AUDIO_DETECT, *LPUSB_AUDIO_DETECT;

    //音效自检
    typedef struct tagUSB_AUDIO_EFFICT_DETECT
    {
        DWORD	dwSize;
        BYTE	byInChannelID;		//音频输入通道号
        BYTE	byOutChannelID;		//音频输出通道号
        BYTE	byTestMode;			//测试模式：1-混响检测，2-音量检测，3-噪声测试
        BYTE	byProcessMode;		//测试过程：1-开始测试，2-获取结果
        BYTE	byTestResult;		//测试结果：
        //当测试模式为1时：0-混响效果较好，1-混响效果较差，2-混响测试失败
        //当测试模式为2时：0-输出音量较小，1-输出音量正常，2-输出音量较大
        //当测试模式为3时：0-噪声过大，1-噪声正常
        BYTE	byRes[31];
    }USB_AUDIO_EFFICT_DETECT, *LPUSB_AUDIO_EFFICT_DETECT;

    //生产测试
    typedef struct tagUSB_AUDIO_FAC_TEST
    {
        DWORD	dwSize;
        BYTE	byTestMode;			//测试模式：1-测试自研USB MIC，2-测试通路，3-测试蓝牙音频
        BYTE	byProcessMode;		//测试过程：1-开始测试，2-获取结果
        BYTE	byTestResult;		//测试结果：1-测试正确，2-测试错误
        BYTE	byRes[29];
    }USB_AUDIO_FAC_TEST, *LPUSB_AUDIO_FAC_TEST;

    //音频AGC
    typedef struct tagUSB_AUDIO_AGC_CONFIG
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//音频通道号
        BYTE	byEnabled;			//AGC使能：0-关闭，1-开启
        BYTE	byGainLevel;		//增益值，范围0-30
        BYTE	byRes[29];
    }USB_AUDIO_AGC_CONFIG, *LPUSB_AUDIO_AGC_CONFIG;

    //音频降噪
    typedef struct tagUSB_AUDIO_REDUCE_NOISE
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//音频通道号
        BYTE	byEnabled;			//降噪使能：0-关闭，1-开启
        BYTE	byLevel;			//降噪等级：0-5
        BYTE	byLevelDefault;     //降噪等级默认值
        BYTE	byLevelMin;         //降噪等级最小值
        BYTE	byLevelMax;         //降噪等级最大值
        BYTE	byRes[26];
    }USB_AUDIO_REDUCE_NOISE, *LPUSB_AUDIO_REDUCE_NOISE;

    //语音识别
    typedef struct tagUSB_AUDIO_RECOG_RSLT
    {
        DWORD	dwSize;
        BYTE	byAudAiCmd;			//语音智能命令，范围：0-100
        BYTE	byMatchAudAi;		//匹配到的语音指令，范围：0-100
        BYTE    byRes1[2];
        DWORD	dwResSet;			//设置参数值：0 - (2^32 - 1)
        DWORD	dwResRet;			//获取参数值：0 - (2^32 - 1)
        BYTE	byRes[32];
    }USB_AUDIO_RECOG_RSLT, *LPUSB_AUDIO_RECOG_RSLT;

    //ECHO 诊断
    typedef struct tagUSB_AUDIO_ECHO_SET
    {
        BYTE    byInChannelID;      //当前输入通道
        BYTE    byOutChannelID;     //当前输出通道
        BYTE    byEnabled;          //是否使能
        BYTE    byRes[29];
    }USB_AUDIO_ECHO_SET, *LPUSB_AUDIO_ECHO_SET;

    //音频控制信令
    typedef struct tagUSB_AUDIO_SIGNAL_TRANS
    {
        BYTE    bySignalTransType;  //信令类型：1-音频数据导出，2-log导出，3-开启禁言，4-关闭禁言，5-音频输入自动模式开启，6-音频输入自动模式关闭，7-音频输出自动模式开启，8-音频输出自动模式关闭
        BYTE    byRes[31];
    }USB_AUDIO_SIGNAL_TRANS, *LPUSB_AUDIO_SIGNAL_TRANS;

    //音频输入输出通道信息
    typedef struct tagUSB_AUDIO_INPUT_OUTPUT_CHANNELINFO
    {
        BYTE    byInChannelID;      //当前输入通道
        BYTE    byOutChannelID;     //当前输出通道
        BYTE    byRes[30];
    }USB_AUDIO_INPUT_OUTPUT_CHANNELINFO, *LPUSB_AUDIO_INPUT_OUTPUT_CHANNELINFO;

    //音频产线测试配置
    typedef struct tagUSB_AUDIO_PROCESS_LINE_CFG
    {
        BYTE    byEnabled;          //音频产线测试使能：0-关闭，1-开启
        BYTE    byRes[31];
    }USB_AUDIO_PROCESS_LINE_CFG, *LPUSB_AUDIO_PROCESS_LINE_CFG;

    //获取音频POE供电网口检测状态
    typedef struct tagUSB_AUDIO_POE_LINK_STATUS
    {
        BYTE    byPOELinkStatus;    //poe供电网口检测：0-异常，1-正常
        BYTE    byRes[31];
    }USB_AUDIO_POE_LINK_STATUS, *LPUSB_AUDIO_POE_LINK_STATUS;

    //拾音
    typedef struct tagUSB_AUDIO_PICK_UP
    {
        BYTE    byMode;           //模式：0-全向，1-定向
        BYTE    byModeDefault;    //模式默认值
        BYTE    byRes[30];
    }USB_AUDIO_PICK_UP, *LPUSB_AUDIO_PICK_UP;

    //跟随模式
    typedef struct tagUSB_PTZ_TRACK_MODE
    {
        DWORD	dwSize;
        BYTE	byTrackingMode;		//跟随模式：1-手动，2-自动，3-AutoFrame
        BYTE	byRes[31];
    }USB_PTZ_TRACK_MODE, *LPUSB_PTZ_TRACK_MODE;

    //预置点参数
    typedef struct tagUSB_PTZ_PRESET_CFG
    {
        DWORD	dwSize;
        BYTE	byChannelID;		//通道号
        BYTE	byPresetID;			//预置点号，范围1-5
        BYTE	byRes[30];
    }USB_PTZ_PRESET_CFG, *LPUSB_PTZ_PRESET_CFG;

    //自动跟随灵敏度
    typedef struct tagUSB_PTZ_AUTO_TRACK_SENSITIVITY
    {
        DWORD	dwSize;
        BYTE	bySensitivity;		//灵敏度：1-中，2-高
        BYTE	byRes[31];
    }USB_PTZ_AUTO_TRACK_SENSITIVITY, *LPUSB_PTZ_AUTO_TRACK_SENSITIVITY;

    //测温基本参数配置
    typedef struct tagUSB_THERMOMETRY_BASIC_PARAM
    {
        DWORD  dwSize;
        BYTE       byTemperatureRangeAutoChangedEnabled; //测温档位自动切换模式使能：0-关闭  1-开启
        BYTE       byEnabled;//开启测温功能使能
        BYTE       byDisplayMaxTemperatureEnabled;//显示最高温: 0-关闭; 1-开启
        BYTE       byDisplayMinTemperatureEnabled;//显示最低温: 0-关闭; 1-开启
        BYTE       byDisplayAverageTemperatureEnabled;//显示平均温: 0-关闭; 1-开启
        BYTE       byTemperatureUnit;//温度单位: 1 - 摄氏温度;2 - 华氏温度;3 - 开尔文温度(协议传输中约定以摄氏温度作为单位传输)
        BYTE       byTemperatureRange;//测温范围: [1~5]个档位，档位能力及对应温度范围，具体参考设备产品说明
        BYTE       byCalibrationCoefficientEnabled;//启用标定系数:0 - 关闭;1 - 开启
        DWORD       dwCalibrationCoefficient;//标定系数: 0.00~30.00 ,传输时实际值 * 100换算成整数
        DWORD       dwExternalOpticsWindowCorrection;//外部光学温度: -40.0~80.0℃ ,传输时(实际值 + 100) * 10换算成正整数   转换方式2：传输时 实际值*2n，小数部分截断，n的大小来自shiftLength字段，该字段具体如何传输，由字段floatTransMode决定，若是没有floatTransMode字段，默认整型传输
        DWORD       dwEmissivity;//发射率: 0.01~1(精确到小数点后两位), 传输时实际值 * 100换算成整数   转换方式2：传输时 实际值*2n，小数部分截断，n的大小来自shiftLength字段，该字段具体如何传输，由字段floatTransMode决定，若是没有floatTransMode字段，默认整型传输
        BYTE       byDistanceUnit;//距离单位: 1 - 米; 2 - 厘米; 3 - 英尺
        BYTE       byShowAlarmColorEnabled; //报警颜色显示使能: 0-关闭  1-开启
        BYTE       byAlarmType; //报警类型: 1-最高温, 2-最低温, 3-平均温, 4-温差
        BYTE       byAlarmRult;  //报警规则类型: 1-大于  2-小于
        DWORD       dwDistance;//距离: 0.3-2m（协议传输中约定以cm作为单位传输, 精确到小数点后1位）  转换方式2：传输时 实际值*2n，小数部分截断，n的大小来自shiftLength字段，该字段具体如何传输，由字段floatTransMode决定，若是没有floatTransMode字段，默认整型传输
        BYTE       byReflectiveEnable;//反射温度使能: 0 - 关闭; 1 - 开启
        BYTE       byAutoDrift;  //自动温漂抑制类型: 1-测温算法库做温漂   2-NUC做温漂
        BYTE       bySSECompensation;  //SSE补偿: 1-支持测温距离自适应   2-不支持
        BYTE       byThermalRawData;  //热成像裸数据压缩方式: 0-不支持压缩   1-LPL压缩方法
        DWORD       dwReflectiveTemperature;//反射温度: -100.0~1000.0℃（精确到小数点后1位）,传输时(实际值 + 100) * 10换算成正整数   转换方式2：传输时 实际值*2n，小数部分截断，n的大小来自shiftLength字段，该字段具体如何传输，由字段floatTransMode决定，若是没有floatTransMode字段，默认整型传输
        BYTE       byThermomrtryInfoDisplayPosition;//测温信息显示位置: 1-跟随规则 2-屏幕左上角
        BYTE       byThermometryStreamOverlay; //码流叠加温度信息: 1-不叠加  2-叠加
        BYTE       byDisplayCenTempEnabled;  //显示中心温：0-关闭   1-开启
        BYTE       byBackcolorEnabled;  //显示背景色：0-关闭  1-开启
        DWORD       dwAlert;//预警温度: -20℃~400℃, 传输时(实际值+100)*10换算成正整数
        DWORD       dwAlarm;//报警温度: -20℃~400℃, 传输时(实际值+100)*10换算成正整数
        DWORD       dwExternalOpticsTransmit;//外部光学透过率: 0.01~1(精确到小数点后两位), 传输时实际值*100换算成整数   转换方式2：传输时 实际值*2n，小数部分截断，n的大小来自shiftLength字段，该字段具体如何传输，由字段floatTransMode决定，若是没有floatTransMode字段，默认整型传输
        DWORD       dwTemperatureRangeUpperLimit; //测温档位上限温度值（只读）：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        //用于预览画面温度信息叠加显示的样式：大于此温度范围用 > aboveMaxRangeTemp显示，小于此温度范围用≈显示
        DWORD       dwTemperatureRangeLowerLimit; //测温档位下限温度值（只读）：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        //用于预览画面温度信息叠加显示的样式：小于此温度范围用 < aboveMaxRangeTemp显示，大于此温度范围用≈显示
        DWORD       dwTemperatureRangeExcursionUpperLimit; //测温档位偏移上限温度值（只读）：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        //用于预览画面温度信息叠加显示的样式：大于此温度范围用≈显示，小于正常显示
        DWORD       dwTemperatureRangeExcursionLowerLimit; //测温档位偏移下限温度值（只读）：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        //用于预览画面温度信息叠加显示的样式：小于此温度范围用≈显示，大于正常显示
        DWORD       dwAtmosphericHumidity;  //大气湿度值（测温使用）：范围0.0~100.0，传输时实际值*10换算成正整数
        BYTE       byFloatTransMode; //浮点数传输方式  1 - 整型传输  2 - 移位传输      整型传输 : 先将浮点数转换为正数，再乘以10的倍数，转换成正整数，然后传输    移位传输 : 直接将浮点数乘以2n，截断小数，然后传输
        BYTE       byShiftLength; //浮点数移位传输乘以2的N次方，其中N的大小 1-6; 2-9; 3-13; 4-16; 5-19;
        BYTE       byEnviromentTemperatureEnable; //环境温度使能：1 - 关闭 2 - 开启
        BYTE       byRes1;
        DWORD      dwEnviromentTemperature;  //环境温度：-100.0~1000.0℃（精确到小数点后2位）传输时(实际值 + 100) * 100换算成非负整数
        BYTE       byRes[176];
    }USB_THERMOMETRY_BASIC_PARAM, *LPUSB_THERMOMETRY_BASIC_PARAM;

    //测温模式配置
    typedef struct tagUSB_THERMOMETRY_MODE
    {
        DWORD  dwSize;
        BYTE       byThermometryMode;//测温模式: 1-普通; 2-专家
        BYTE       byThermometryROIEnabled;//测温ROI使能: 0 - 关闭; 1 - 开启
        BYTE       byRes[62];
    }USB_THERMOMETRY_MODE, *LPUSB_THERMOMETRY_MODE;

    //测温规则区域
    typedef struct tagTHERMAL_REGION
    {
        DWORD  dwSize;
        BYTE  byRegionID;  //区域ID，从1开始递增
        BYTE  byRegionEnabled;  //区域使能 0-关闭 1-开启
        BYTE  byRes1[2];
        DWORD dwRegionX;  //区域左上顶点X坐标，归一化值，范围0-1000
        DWORD dwRegionY;  //区域左上顶点Y坐标，归一化值，范围0-1000
        DWORD dwRegionWidth;  //区域宽度，归一化值，范围0-1000
        DWORD dwRegionHeight;  //区域高度，归一化值，范围0-1000
        BYTE  byRes[12];
    }THERMAL_REGION, *LPTHERMAL_REGION;

    //测温规则配置
    typedef struct tagUSB_THERMOMETRY_REGIONS
    {
        DWORD  dwSize;
        BYTE         byRegionNum;    //规则区域总个数
        BYTE         byRes1[3];
        THERMAL_REGION    struRegion[MAX_THERMAL_REGIONS];
        BYTE         byRes[188];
    }USB_THERMOMETRY_REGIONS, *LPUSB_THERMOMETRY_REGIONS;

    //热成像码流参数配置
    typedef struct tagUSB_THERMAL_STREAM_PARAM
    {
        DWORD  dwSize;
        BYTE       byVideoCodingType;//码流数据编解码类型: 1-热成像裸数据; 2-全屏测温数据; 3-实时裸数据; 4-热图数据; 5-热成像实时流; 6-YUV实时数; 7-PS封装MJPEG实时流;
        //8-全屏测温数据+YUV实时流; 9-YUV+裸数据; 10-仅YUV不含测温头;  11-测温头+YUV+裸数据
        BYTE  byRes[3];
        DWORD dwWidth;
        DWORD dwHeight;
        DWORD dwFrameRate;
    }USB_THERMAL_STREAM_PARAM, *LPUSB_THERMAL_STREAM_PARAM;

    //测温修正
    typedef struct tagUSB_TEMPERATURE_CORRECT
    {
        DWORD  dwSize;
        BYTE   byRes1;  //保留
        BYTE   byEnabled;  //使能 0-关闭 1-开启
        BYTE   byStreamOverlay;  //修正温度码流叠加使能 0-关闭 1-开启
        BYTE   byCorrectEnabled; //测温修正使能 0-关闭 1-开启
        DWORD  dwEmissivity; //黑体发射率:0.01-1.00, 传输时实际值*100换算成整数
        DWORD  dwDistance;   //距离 0.3-2m, 协议传输时以厘米为单位
        DWORD  dwTemperature;  //黑体温度 30.0~50.0℃, 传输时实际值*10换算成整数
        DWORD  dwCentrePointX;  //黑体中心点X坐标，归一化值，范围0-1000
        DWORD  dwCentrePointY;  //黑体中心点Y坐标，归一化值，范围0-1000
        DWORD  dwCorrectTemperature;  //修正温度 -99.0-99.0℃ 传输时(实际值 + 100) * 10换算成正整数
        BYTE   byRes[36];
    }USB_TEMPERATURE_CORRECT, *LPUSB_TEMPERATURE_CORRECT;

    //黑体参数配置
    typedef struct tagUSB_BLACK_BODY
    {
        DWORD  dwSize;
        BYTE   byEnabled;  //使能 0-关闭 1-开启
        BYTE   byRes1[3];
        DWORD  dwEmissivity; //黑体发射率:0.01 - 1.00, 传输时实际值 * 100换算成整数
        DWORD  dwDistance;   //距离 0.3-2m, 协议传输时以厘米为单位
        DWORD  dwTemperature;   //黑体温度 30.0~50.0℃, 传输时实际值*10换算成整数
        DWORD  dwCentrePointX;  //黑体中心点X坐标，归一化值，范围0-1000
        DWORD  dwCentrePointY;  //黑体中心点Y坐标，归一化值，范围0-1000
        BYTE   byRes[40];
    }USB_BLACK_BODY, *LPUSB_BLACK_BODY;

    //体温补偿参数配置
    typedef struct tagUSB_BODYTEMP_COMPENSATION
    {
        DWORD   dwSize;   //结构体大小
        BYTE       byEnabled;  //使能 0-关闭 1-开启
        BYTE       byType;   //补偿方式:1-手动补偿 2-自动补偿
        BYTE       byRes1[2];
        int        iCompensationValue; //补偿温度 [-10.0 10.0]摄氏度, 传输时实际值*10换算成整数
        DWORD      dwSmartCorrection; //手动校准 -99.0~990.℃, 传输时(实际值+100)*10换算成正整数
        DWORD      dwEnvironmentalTemperature;    //环境温度 -99.0~99.0℃, 传输时(实际值+100)*10换算成正整数
        BYTE       byEnvironmentalTemperatureMode;   //环境温度模式 1-自动模式 2-手动模式
        BYTE       byTemperatureCurveSensitivityLevel;//温度曲线灵敏度等级: 1-低 2-中 3-高  
        BYTE       byEnvironmentCompensationenabled;//环境补偿使能: 1-关闭  2-开启
        BYTE       byRes[45];
    }USB_BODYTEMP_COMPENSATION, *LPUSB_BODYTEMP_COMPENSATION;

    //全屏测温参数配置
    typedef struct tagUSB_P2P_PARAM
    {
        DWORD   dwSize;   //结构体大小
        BYTE byJpegPicEnabled;  //设备是否返回jpeg图片 0-关闭 1-开启
        BYTE byRes[31];
    }USB_P2P_PARAM, *LPUSB_P2P_PARAM;

    //双光校准坐标控制
    typedef struct tagUSB_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL
    {
        DWORD   dwSize;   //结构体大小
        BYTE byDoubleLightsCorrectPointsEnabled;  //双光校准坐标使能开关 0-关闭 1-开启
        BYTE byRes[31];
    }USB_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL, *LPUSB_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL;

    //热成像测温算法版本
    typedef struct tagUSB_THERMAL_ALG_VERSION
    {
        DWORD   dwSize;   //结构体大小
        BYTE   byThermometryAlgName[64];  //测温算法库版本信息
        BYTE   byThermometryAlgLogicVersion; //测温算法逻辑版本：
        /*
        0 - V0版本，字段出现前的版本被标识为V0
        1 - V1版本，基于DV 5.5.29的测温处理逻辑
        2 - V2版本，基于大师型 5.5.27的测温逻辑，引入了测温中间参数
        3 - V3版本，基于V2版本，修改了对测温结果的处理方式为保留2位精度
        4 - V4版本，基于V3版本，算法库输出结果采用移位的方式截断，并且保留2位小数精度
        */
        BYTE   byRes[63];
    }USB_THERMAL_ALG_VERSION, *LPUSB_THERMAL_ALG_VERSION;

    //测温标定文件导入导出
    typedef struct tagUSB_THERMOMETRY_CALIBRATION_FILE
    {
        DWORD   dwSize;   //结构体大小
        BYTE   byFileName[64];  //文件名称
        DWORD   dwFileLenth;      //标定文件长度
        BYTE   *pCalibrationFile;     //标定文件数据
        BYTE   byRes[56];
    }USB_THERMOMETRY_CALIBRATION_FILE, *LPUSB_THERMOMETRY_CALIBRATION_FILE;

    //抓热图
    typedef struct tagUSB_JPEGPIC_WITH_APPENDDATA
    {
        DWORD   dwSize;   //结构体大小
        DWORD       dwJpegPicLen;//Jpeg图片长度
        DWORD       dwJpegPicWidth;//图像宽度
        DWORD       dwJpegPicHeight;//图像高度
        DWORD       dwP2pDataLen;//全屏测温数据长度
        BYTE       byIsFreezedata;//是否数据冻结: 0-否; 1-是
        BYTE       byTemperatureDataLength;//测温数据长度（2、4）
        BYTE       byRes2[2];
        DWORD       dwScale;//放大倍数（测温数据长度为2时返回）
        int        iOffset;//偏移量（测温数据长度为2时返回）
        BYTE       *pJpegPic;//热成像图片数据
        BYTE       *pP2pData;//全屏测温数据
        BYTE       byRes[28];
    }USB_JPEGPIC_WITH_APPENDDATA, *LPUSB_JPEGPIC_WITH_APPENDDATA;


    //ROI区域
    typedef struct tagROI_REGION
    {
        BYTE       byROIRegionID;//ROI区域ID，从1开始递增，+1递增
        BYTE       byROIRegionEnabled;//ROI区域使能：0 - 关闭，1 - 开启
        BYTE       byRes1[2];
        DWORD       dwROIRegionX;//区域左上顶点X坐标，归一化值，范围0-1000
        DWORD       dwROIRegionY;//区域左上顶点Y坐标，归一化值，范围0-1000
        DWORD       dwROIRegionWidth;//区域宽度，归一化值，范围0-1000
        DWORD       dwROIRegionHeight;//区域高度，归一化值，范围0-1000
        DWORD       dwDistance;//距离：0.3-2m（协议传输中约定以cm作为单位传输, 精确到小数点后1位）
        BYTE       byRes[8];
    }ROI_REGION, *LPROI_REGION;

    //ROI最高温信息查询
    typedef struct tagUSB_ROI_MAX_TEMPERATURE_SEARCH
    {
        DWORD   dwSize;   //结构体大小
        WORD       wMillisecond;//毫秒
        BYTE       byRes2;//保留
        BYTE       bySecond;//秒
        BYTE       byMinute;//分钟
        BYTE       byHour;//小时
        BYTE       byDay;//日
        BYTE       byMonth;//月
        WORD       wYear;//年
        BYTE       byJpegPicEnabled;//设备是否返回jpeg图片
        BYTE       byMaxTemperatureOverlay;//是否叠加最高温
        BYTE       byRegionsOverlay;//是否叠加规则框
        BYTE       byROIRegionNum;//ROI区域总个数
        BYTE       byRes1[2];
        ROI_REGION      struThermalROIRegion[MAX_ROI_REGIONS];
        BYTE       byRes[176];
    }USB_ROI_MAX_TEMPERATURE_SEARCH, *LPUSB_ROI_MAX_TEMPERATURE_SEARCH;

    //ROI区域信息
    typedef struct tagROI_REGION_INFO
    {
        BYTE       byROIRegionID;//ROI区域ID，从1开始递增，+1递增
        BYTE       byRes1[3];
        DWORD       dwMaxROIRegionTemperature;//最高温: 30.0~50.0℃, 传输时实际值 * 10换算成整数
        DWORD       dwVisibleROIRegionMaxTemperaturePointX;//ROI区域可见光最高温X坐标，归一化值，范围0-1000
        DWORD       dwVisibleROIRegionMaxTemperaturePointY;//ROI区域可见光最高温Y坐标，归一化值，范围0-1000
        DWORD       dwThermalROIRegionMaxTemperaturePointX;//ROI区域热成像最高温X坐标，归一化值，范围0-1000
        DWORD       dwThermalROIRegionMaxTemperaturePointY;//ROI区域热成像最高温Y坐标，归一化值，范围0-1000
        BYTE       byRes[8];
    }ROI_REGION_INFO, *LPROI_REGION_INFO;

    //ROI最高温信息查询响应
    typedef struct tagUSB_ROI_MAX_TEMPERATURE_SEARCH_RESULT
    {
        DWORD   dwSize;   //结构体大小
        DWORD       dwMaxP2PTemperature;//全屏最高温: 30.0~50.0℃, 传输时实际值 * 10换算成整数
        DWORD       dwVisibleP2PMaxTemperaturePointX;//全屏可见光最高温X坐标，归一化值，范围0-1000
        DWORD       dwVisibleP2PMaxTemperaturePointY;//全屏可见光最高温Y坐标，归一化值，范围0-1000
        DWORD       dwThermalP2PMaxTemperaturePointX;//全屏热成像最高温X坐标，归一化值，范围0-1000
        DWORD       dwThermalP2PMaxTemperaturePointY;//全屏热成像最高温Y坐标，归一化值，范围0-1000
        BYTE       byROIRegionNum;//ROI区域总个数
        BYTE       byRes2[3];
        DWORD       dwJpegPicLen;//Jpeg图片长度
        ROI_REGION_INFO       struThermalROIRegionInfo[MAX_ROI_REGIONS];
        BYTE       *pJpegPic;//图片数据（所有区域信息之后，末尾只出现1次）
        BYTE       byRes[160];
    }USB_ROI_MAX_TEMPERATURE_SEARCH_RESULT, *LPUSB_ROI_MAX_TEMPERATURE_SEARCH_RESULT;

    //双光校准
    typedef struct tagUSB_DOUBLE_LIGHTS_CORRECT
    {
        DWORD   dwSize;   //结构体大小
        BYTE       byVisiblePicHorizontalScale;//配准裁剪可见光图像水平缩放系数，单位归一化128，[12,128]
        BYTE       byVisiblePicVerticalScale;//配准裁剪可见光图像垂直缩放系数，单位归一化128，[12,128]
        BYTE       byRes1[2];
        WORD       wHorizontalCalibrationOffset;//水平标定偏差，该数值为标定时计算获得，单位归一化1000，[0,1000]
        WORD       wVerticalCalibrationOffset;//垂直标定偏差，该数值为标定时计算获得，单位归一化1000，[0,1000]
        DWORD       dwVisibleFocusDistance;//可见光镜头焦距，单位毫米
        DWORD       dwVisiblePixelInterval;//可见光探测器像元尺寸，单位微米
        DWORD       dwHorizontalCenterDistance;//可见光和热成像中心点水平距离，单位毫米
        DWORD       dwVerticalCenterDistance;//可见光和热成像中心点垂直距离，单位毫米
        DWORD       dwCalibrationDistance;//标定距离[0.3,2]m,协议传输时统一使用cm为单位
        DWORD       dwVisiblePicLen;//可见光图片长度
        BYTE       *pVisiblePic;//可见光图片数据
        BYTE       byRes[92];
    }USB_DOUBLE_LIGHTS_CORRECT, *LPUSB_DOUBLE_LIGHTS_CORRECT;

    //双光校准响应
    typedef struct tagUSB_DOUBLE_LIGHTS_CORRECT_RESULT
    {
        DWORD   dwSize;   //结构体大小
        DWORD      dwJpegPicLen;//融合叠加图片长度
        BYTE       *pJpegPic;//融合叠加图片
        BYTE       byRes[120];
    }USB_DOUBLE_LIGHTS_CORRECT_RESULT, *LPUSB_DOUBLE_LIGHTS_CORRECT_RESULT;

#define MAX_REGION_POINT_NUM   10 //最大支持10个区域顶点
#define MAX_EXPERT_REGIONS    21 //最大支持21个区域

    //区域顶点坐标
    typedef struct tagREGION_VERTEX_COORDINATES
    {
        DWORD   dwPointX; //X坐标, 归一化0-1000    含义1：归一化到0-1000的归一化后坐标, 含义2：裸数据真实坐标   具体是什么含义由字段regionCoordinateMode决定   默认归一化坐标
        DWORD   dwPointY; //Y坐标, 归一化0-1000    含义1：归一化到0-1000的归一化后坐标, 含义2：裸数据真实坐标   具体是什么含义由字段regionCoordinateMode决定   默认归一化坐标
        BYTE   byRes[24];
    }REGION_VERTEX_COORDINATES, *LPREGION_VERTEX_COORDINATES;

    //专家测温规则区域
    typedef struct tagTHERMAL_EXPERT_REGIONS
    {
        BYTE   byRegionID;  //区域ID，从1开始递增
        BYTE   byEnabled;  //区域使能 0-关闭 1-开启
        BYTE   byRes1[2];
        BYTE   byName[32]; //规则名称
        DWORD   dwEmissivity; //发射率: 0.01~1(精确到小数点后两位), 传输时实际值 * 100换算成整数  转换方式2：传输时 实际值*2n，小数部分截断，n的大小来自shiftLength字段,该字段具体如何传输，由字段floatTransMode决定，若是没有floatTransMode字段，默认整型传输
        DWORD   dwDistance;  //距离: 0.3-3m（协议传输中约定以cm作为单位整数传输）  转换方式2：传输时 实际值*2n，小数部分截断，n的大小来自shiftLength字段, 该字段具体如何传输，由字段floatTransMode决定，若是没有floatTransMode字段，默认整型传输
        BYTE   byReflectiveEnable; //反射温度使能：0-关闭 1-开启
        BYTE   byHighestTempEnable; //最高温显示使能: 1-关闭  2-开启
        BYTE   byLowestTempEnable; //最低温显示使能: 1-关闭  2-开启
        BYTE   byAverageTempEnable; //平均温显示使能: 1-关闭  2-开启
        DWORD   dwReflectiveTemperature; //反射温度: -73.3~1000.0℃（精确到小数点后1位, 传输时(实际值 + 100) * 10换算成正整数   转换方式2：传输时 实际值*2n，小数部分截断，n的大小来自shiftLength字段,该字段具体如何传输，由字段floatTransMode决定，若是没有floatTransMode字段，默认整型传输
        BYTE   byType; //规则标定类型: 1-点 2-线 3-框
        BYTE   byShowAlarmColorEnabled; //报警颜色显示使能: 1-开启 0-关闭
        BYTE   byRule; //报警温度比较方式: 
        //当type为1-点时：1-平均温度大于 2-平均温度小于; 
        //当type为2-线时：1-高温大于 2-高温小于 3-低温大于 4-低温小于 5-平均温度大于 6-平均温度小于;
        //当type为3-框时：1-高温大于 2-高温小于 3-低温大于 4-低温小于 5-平均温度大于 6-平均温度小于 7-温差大于 8-温差小于
        BYTE   byRes3;
        DWORD   dwAlert; //预警温度：-20℃~400℃, 传输时(实际值 + 100) * 10换算成正整数
        DWORD   dwAlarm; //报警温度：-20℃~400℃, 传输时(实际值 + 100) * 10换算成正整数
        BYTE   byPointNum; //区域顶点总个数：当type为1-点时个数为1;   当type为2-线时个数为2 ;   当type为3-框时个数为3-10
        BYTE   byRes4[3];
        REGION_VERTEX_COORDINATES   struRegionCoordinate[MAX_REGION_POINT_NUM];
        BYTE   byRes[200];
    }THERMAL_EXPERT_REGIONS, *LPTHERMAL_EXPERT_REGIONS;

    //专家测温规则配置
    typedef struct tagUSB_THERMOMETRY_EXPERT_REGIONS
    {
        DWORD   dwSize;   //结构体大小
        BYTE   byRegionNum; //规则区域总个数
        BYTE   byRegionCoordinateMode; //区域坐标生效模式 1 - 归一化坐标 2 - 裸数据实际坐标.  该字段用来判断区域坐标顶点生效的字段是归一化坐标还是裸数据实际坐标
        BYTE   byFloatTransMode; //浮点数传输方式 1 - 整型传输 2 - 移位传输. 整型传输 : 先将浮点数转换为正数，再乘以10的倍数，转换成正整数，然后传输; 移位传输 : 直接将浮点数乘以2n，截断小数，然后传输
        BYTE   byShiftLength; //浮点数移位传输乘以2的N次方，其中N的大小 1-6; 2-9; 3-13; 4-16; 5-19
        THERMAL_EXPERT_REGIONS  struExpertRegions[MAX_EXPERT_REGIONS];
        BYTE   byRes[220];
    }USB_THERMOMETRY_EXPERT_REGIONS, *LPUSB_THERMOMETRY_EXPERT_REGIONS;

#define MAX_TEMPERATURE_NUM  4

    //专家测温温度点信息
    typedef struct tagTHERMAL_EXPERT_TEMPERATURE
    {
        BYTE   byID; //序号，从1开始递增
        BYTE   byRes1[3];
        DWORD   dwPresetTemperature; //预设温度: -40.0-650.0℃, 传输时(实际值+100) * 10换算成整数
        DWORD   dwPointX; //X坐标, 归一化0-1000, 左上角为原点（由于DSP限制，实际归一化后范围为13-993）
        DWORD   dwPointY; //Y坐标, 归一化0-1000, 左上角为原点（由于DSP限制，实际归一化后范围为17-991）
        BYTE   byRes[24];
    }THERMAL_EXPERT_TEMPERATURE, *LPTHERMAL_EXPERT_TEMPERATURE;

    //专家测温校正参数配置
    typedef struct tagUSB_THERMOMETRY_EXPERT_CORRECTION_PARAM
    {
        DWORD   dwSize;   //结构体大小
        DWORD   dwDistance; //距离: 0.3-3m, 协议传输时以厘米为单位
        DWORD   dwEnviroTemperature; //环境温度: -273.0-1000.0, 传输时（实际值 + 300） * 10换算成整数
        DWORD   dwEmissivity; //发射率: 0.01-1.00, 传输时实际值 * 100换算成整数
        BYTE   byPointNum; //温度点个数: 4个
        BYTE   byRes2[3];
        THERMAL_EXPERT_TEMPERATURE  struExpertTemperature[MAX_TEMPERATURE_NUM];
        BYTE   byRes[64];
    }USB_THERMOMETRY_EXPERT_CORRECTION_PARAM, *LPUSB_THERMOMETRY_EXPERT_CORRECTION_PARAM;

    //温升配置
    typedef struct tagUSB_THERMOMETRY_RISE_SETTINGS
    {
        DWORD  dwSize;  //结构体大小
        BYTE  byEnabled; //启用温升设置 0-关闭  1-开启
        BYTE  byType; //温升参数获取方式 0-自动获取 1-手动输入
        BYTE  byResult; //温升参数计算状态（只读，温升参数获取方式为自动获取模式有效）: 0-成功(下列参数值有效)  1-等待(下列参数值无效)  2-失败(下列参数值无效)
        BYTE  byRes1;
        DWORD  dwEnvTemperature; //环境温度: -99.0~99.0℃ (精确到小数点后两位), 传输时(实际值+100)*10换算成正整数
        int  dwCoefficient;  //温升系数: -10~10
        DWORD  dwMaxTemperatureRise;  //最大温升: 2~20
        DWORD  dwColdStartRate; //冷开机温升速率: 0.01~0.5 (精确到小数点后两位), 传输时实际值*100换算成整数
        DWORD  dwColdStartRise; //冷开机温升: -3.0~3.0 (精确到小数点后1位), 传输时(实际值+100)*10换算成正整数
        BYTE  byRes[128];
    }USB_THERMOMETRY_RISE_SETTINGS, *LPUSB_THERMOMETRY_RISE_SETTINGS;

    //环境温度校正
    typedef struct tagUSB_ENVIROTEMPERATURE_CORRECT
    {
        DWORD dwSize;  //结构体大小
        BYTE  byEnabled;  //总使能, 用于开关校准参数是否生效  0-关闭  1-开启
        BYTE  byCorrectEnabled;  //环境温度校准使能, 用于生成校准参数  0-关闭  1-开启
        BYTE  byRes1[2];
        DWORD  dwEnviroTemperature;  //环境温度校准值, -20.0~50.0℃(精确到小数点后1位), 传输时(实际值+100)*10换算成正整数
        DWORD  dwCalibrationTemperature;  //(只读)温变校准值结果, -20.0~50.0℃(精确到小数点后1位), 传输时(实际值+100)*10换算成正整数
        BYTE  byRes[112];
    }USB_ENVIROTEMPERATURE_CORRECT, *LPUSB_ENVIROTEMPERATURE_CORRECT;

    //视频编码参数
    typedef struct tagUSB_VIDEO_CODE
    {
        DWORD	dwSize;
        BYTE  byVideoResolution; //视频分辨率：1-256*192, 2-384*288, 3-720*576, 4-1024*768, 5-96*96, 6-160*120, 7-640*512, 8-192*144, 9-480*360, 10-640*480
        BYTE  byUnpackedResolution;//非压缩帧分辨率（只读）：当帧率小于5帧时, 设备会使用非压缩帧上传数据, 根据此只读参数配置视频属性信息, 避免因非压缩帧分辨率扩大导致数据被按压缩帧分辨率配置的YVC通道过滤掉
        //1-320*240, 2-640*480, 3-640*512, 4-1024*600, 5-1280*720, 6-640*256
        BYTE  byRes1[2];
        DWORD  dwMaxFrameRate; //视频帧率：1-30fps
        BYTE  byRes[244];
    }USB_VIDEO_CODE, *LPUSB_VIDEO_CODE;

    //画中画模式矩形框
    typedef struct tagUSB_PIP_RECT
    {
        DWORD dwPointX; //画中画矩形框左上顶点：X坐标，实际像素位，屏幕左上为原点
        DWORD dwPointY; //画中画矩形框左上顶点：Y坐标，实际像素位，屏幕左上为原点
        DWORD dwWidth; //画中画矩形框：宽，实际像素位，屏幕左上为原点
        DWORD dwHeight; //画中画矩形框：高，实际像素位，屏幕左上为原点
        BYTE  byRes[16];
    }USB_PIP_RECT, *LPUSB_PIP_RECT;

    //图像融合参数
    typedef struct tagUSB_VIDEO_FUSION
    {
        DWORD	dwSize;
        DWORD dwAutoFocusObjectDistance;  //自动聚焦反馈的物距信息, 范围:0-100, 单位:dm
        DWORD dwHistoryFocusObjectDistance;  //历史自动聚焦反馈的物距信息, 范围:0-100, 单位:dm
        DWORD dwCurrentFocusObjectDistance; //当前自动聚焦反馈的物距信息加权比例, 范围:0-256
        DWORD dwHorizontalScaleRatio; //水平缩放因子, 范围: 12-19200
        DWORD dwVerticalScaleRatio; //垂直缩放因子, 范围: 12-19200
        DWORD dwVerticalCroppingOffset; //垂直剪裁偏移量, 范围: [-212, 212], 传输时实际值+500
        DWORD dwHorizontalCroppingOffset; //水平剪裁偏移量, 范围: [-212, 212], 传输时实际值+500
        DWORD dwRotationAngle; //旋转角度, 范围:[0.0, 360.0], 单位: 度, 传输时实际值*10
        DWORD dwHighExplosionSuppressionThreshold; //高爆抑制门限, 范围:0-255
        DWORD dwHighPassFilterSelectionVariable; //高通滤波选择变量, 范围:0,1
        DWORD dwHighPassFilteRadius; //高通滤波半径
        DWORD dwHighFrequencyInformationThreshold; //高频信息门限, 范围:0-32767
        DWORD dwSuperpositionGain; //叠加增益, 范围:0-127
        DWORD dwLimitingGain; //限制增益, 范围:0-127
        DWORD dwLowFrequencyFusionControlLowerThreshold; //低频融合控制下门限, 范围:0-255
        DWORD dwLowFrequencyFusionControlUpperThreshold; //低频融合控制上门限, 范围:0-255
        BYTE byVideoFusionMode; //图像融合处理模式: 1-单热成像模式, 2-可见光模式, 3-融合模式, 4-画中画模式, 5-标定模式, 6-融合彩色模式--草地, 
        //7-融合彩色模式--荒漠, 8-融合彩色模式--雪地, 10-融合彩色模式--城市, 11-混合模式--可见光+热成像
        BYTE byRes2[2];
        BYTE byPipEnabled; //画中画融合使能, 0-关闭 1-开启
        USB_PIP_RECT struPipRect; //画中画矩形框信息
        BYTE byMixModeVisibleScale; //混合模式可见光比例, 范围0-100 (当videoFusionMode为11-混合模式时, 该参数生效)
        BYTE byRes[407];
    }USB_VIDEO_FUSION, *LPUSB_VIDEO_FUSION;

    //镜头标定参数
    typedef struct tagUSB_VIDEO_LEN_CALIBRATION
    {
        DWORD	dwSize;
        BYTE byVideoResolution; //倍镜类型: 1-1X倍镜, 2-0.5X倍镜, 3-2X倍镜, 4-3X倍镜, 5-0.85X微距镜头, 6-0.34X微距镜头,
        //7-专门超高温倍镜, 8-MAX倍镜, 9-开机启动中, 10-检测到倍镜但不支持, 11-没有检测到倍镜
        BYTE byAdditiveMultiplicationFactor; //加乘因子使能（只读）: 0-关闭  1-开启
        BYTE byRes1[2];
        DWORD dwTeleconverterAdditiveFactor1; //倍镜加性因子1
        DWORD dwTeleconverterAdditiveFactor2; //倍镜加性因子2
        DWORD dwTeleconverterAdditiveFactor3; //倍镜加性因子3
        DWORD dwTeleconverterAdditiveFactor4; //倍镜加性因子4
        DWORD dwTeleconverterMultiplicationFactor1; //倍镜乘性因子1
        DWORD dwTeleconverterMultiplicationFactor2; //倍镜乘性因子2
        DWORD dwTeleconverterMultiplicationFactor3; //倍镜乘性因子3
        DWORD dwTeleconverterMultiplicationFactor4; //倍镜乘性因子4
        DWORD dwFocus; //聚焦值
        DWORD dwPixelSize; //原相大小, 0-1000μm, 单位: 微米
        DWORD dwDistance; //物距, 0-50000㎜, 单位: 毫米
        DWORD dwTeleconverterFOV; //倍镜视场角, 范围0.0-360.0, 单位: 度, 传输时实际值*10
        BYTE byRes[200];
    }USB_VIDEO_LEN_CALIBRATION, *LPUSB_VIDEO_LEN_CALIBRATION;

    //系统管理总能力
    typedef struct tagUSB_SYSTEM_CTRL_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE  byDeviceInfo; //设备信息获取：0-不支持  1-支持
        BYTE  byReboot; //设备重启：0-不支持  1-支持
        BYTE  byReset; //恢复默认：0-不支持  1-支持
        BYTE  byHardwareServer; // 硬件服务参数配置：0-不支持  1-支持
        BYTE  byLocalTime; //校时：0-不支持  1-支持
        BYTE  byUpdateFirmware; //设备升级：0-不支持  1-支持
        BYTE  byDiagnoseData;  //诊断信息导出：0-不支持  1-支持
        BYTE  byScreenVirtualMenu;  //屏幕虚拟菜单：0-不支持  1-支持
        BYTE  byDeviceMenuArouse;  //设备菜单唤醒：0-不支持  1-支持
        BYTE  byTouchScreenMessagePoster;  //触屏消息发送：0-不支持  1-支持
        BYTE  byDeviceDescriptionInfo;  //设备描述信息：0-不支持  1-支持
        BYTE  byBigDataTransInfo;  //大数据传输信息：0-不支持  1-支持
        BYTE  byUVCMenuControl;  //视频菜单控制：0-不支持  1-支持
        BYTE  bySerialDataTransmission;  //串口数据透传：0-不支持  1-支持
        BYTE  byRes[494];
    }USB_SYSTEM_CTRL_CAPABILITIES, *LPUSB_SYSTEM_CTRL_CAPABILITIES;

    //设备信息能力
    typedef struct tagUSB_SYSTEM_DEVICE_INFO_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byFirmwareVersion; //主控程序版本：0-不支持 1-支持
        BYTE byEncoderVersion; //编码版本：0-不支持 1-支持
        BYTE byHardwareVersion; //机芯版本：0-不支持 1-支持
        BYTE byDeviceName; //设备名称：0-不支持 1-支持
        BYTE byProtocolVersion; //协议版本信息：0-不支持  1-支持
        BYTE bySerialNumber; //设备序列号：0-不支持  1-支持
        BYTE bySecondhardwareVersion; //副程序版本：0-不支持   1-支持
        BYTE byModuleID; //机芯ID：0-不支持  1-支持
        BYTE byDeviceID; //设备ID：0-不支持   1-支持
        BYTE byDeviceAssembleType; //设备组装类型：1-不支持  2-支持
        BYTE byManufacturer; //厂商信息：1-不支持  2-支持
        BYTE byLanguageType; //语言类型：1-不支持  2-支持
        BYTE byDeviceClass; //设备种类：1-不支持  2-支持
        BYTE byRes[495];
    }USB_SYSTEM_DEVICE_INFO_CAPABILITIES, *LPUSB_SYSTEM_DEVICE_INFO_CAPABILITIES;

    //硬件服务能力
    typedef struct tagUSB_SYSTEM_HARDWARE_SERVER_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byUsbMode; //USB模式切换，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：USB的UVC模式
        bit1：USB的NCM模式
        */
        BYTE byDeviceinitialstatus; //设备初始化状态：0-不支持  1-支持
        BYTE byDeviceworkingstatus; //设备工作状态：0-不支持   1-支持
        BYTE byRes[505];
    }USB_SYSTEM_HARDWARE_SERVER_CAPABILITIES, *LPUSB_SYSTEM_HARDWARE_SERVER_CAPABILITIES;

    //系统时间能力
    typedef struct tagUSB_SYSTEM_LOCALTIME_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byMillisecond; //毫秒：0-不支持  1-支持
        BYTE bySecond; //秒：0-不支持  1-支持
        BYTE byMinute; //分钟：0-不支持  1-支持
        BYTE byHour; //小时：0-不支持   1-支持
        BYTE byDay; //日：0-不支持  1-支持
        BYTE byMonth; //月：0-不支持  1-支持
        BYTE  wYear; //年：0-不支持  1-支持
        BYTE byExternalTimeSourceEnabled; //外部校时源使能：0-不支持  1-支持
        BYTE byRes[499];
    }USB_SYSTEM_LOCALTIME_CAPABILITIES, *LPUSB_SYSTEM_LOCALTIME_CAPABILITIES;

    //图像管理总能力
    typedef struct tagUSB_IMAGE_CAPABILITIES
    {
        DWORD	dwSize;
        BYTE  byImageBrightness; //图像亮度调节：0-不支持  1-支持
        BYTE  byImageContrast; //图像对比度调节：0-不支持  1-支持
        BYTE  byImageBackgroundCorrect; //一键背景校正：0-不支持  1-支持
        BYTE  byImageManualCorrect;  //一键手动校正：0-不支持  1-支持
        BYTE  byImageEnhancement;  //图像增强：0-不支持  1-支持
        BYTE  byImageVideoAdjust;  //视频调整：0-不支持  1-支持
        BYTE byRes[502];
    }USB_IMAGE_CAPABILITIES, *LPUSB_IMAGE_CAPABILITIES;

    //图像亮度调节能力
    typedef struct tagUSB_IMAGE_BRIGHTNESS_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byBrightnessUpperLimit; //图像亮度上线阈值
        BYTE byBrightnessLowerLimit; //图像亮度下线阈值
        BYTE byRes[506];
    }USB_IMAGE_BRIGHTNESS_CAPABILITIES, *LPUSB_IMAGE_BRIGHTNESS_CAPABILITIES;

    //图像对比度调节能力
    typedef struct tagUSB_IMAGE_CONTRAST_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byContrastUpperLimit; //图像对比度上限阈值
        BYTE byContrastLowerLimit; //图像对比度下限阈值
        BYTE byRes[506];
    }USB_IMAGE_CONTRAST_CAPABILITIES, *LPUSB_IMAGE_CONTRAST_CAPABILITIES;

    //图像增强能力
    typedef struct tagUSB_IMAGE_ENHANCEMENT_CAPABILITIES
    {
        DWORD  dwSize;
        DWORD  dwHighLightLevelUpperLimit; //红热凸显等级上限阈值
        DWORD  dwHighLightLevelLowerLimit; //红热凸显等级下线阈值
        DWORD  dwAGCUpperLimit;  //AGC上限阈值
        DWORD  dwAGCLowerLimit;  //AGC下限阈值
        BYTE  byNoiseReduceMode; //数字降噪模式，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0:关闭
        bit1:普通模式
        bit2:专家模式
        */
        BYTE  byGeneralLevelUpperLimit; //普通模式降噪级别上限阈值
        BYTE  byGeneralLevelLowerLimit; //普通模式降噪级别下限阈值
        BYTE  byFrameNoiseReduceLevelUpperLimit; //专家模式空域降噪级别上限阈值
        BYTE  byFrameNoiseReduceLevelLowerLimit; //专家模式空域降噪级别下限阈值
        BYTE  byInterFrameNoiseReduceLevelUpperLimit; //专家模式时域降噪级别上限阈值
        BYTE  byInterFrameNoiseReduceLevelLowerLimit; //专家模式时域降噪级别下限阈值
        BYTE  bySharpenBoost; //锐化增强:1 - 不支持 2 - 支持
        DWORD  dwPaletteMode; //伪彩色颜色模式，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：白热
        bit1：黑热
        bit2：融合1
        bit3：彩虹
        bit4：融合2
        bit5：铁红1
        bit6：铁红2
        bit7：深褐色
        bit8：色彩1
        bit9：色彩2
        bit10：冰火
        bit11：雨
        bit12：红热
        bit13：绿热
        bit14：深蓝
        */
        BYTE  byLSEDetailEnabled; //图像细节增强使能：0-不支持  1-支持
        BYTE  byLSEDetailLevelUpperLimit; //图像细节增强等级上限阈值
        BYTE  byLSEDetailLevelLowerLimit; //图像细节增强等级下限阈值
        BYTE  byWideTemperatureRange; //温宽模式使能：0-不支持  1-支持
        DWORD  dwWideTemperatureRangeUpThr; //温宽模式上阈值：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwWideTemperatureRangeDownThr; //温宽模式下阈值：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        BYTE  byBirdWatchingMode; //观鸟模式使能：0-不支持  1-支持
        BYTE  byHighLightMode; //红热凸显模式使能：0-不支持  1-支持
        BYTE  byHookEdgeMode; //勾边模式使能：0-不支持  1-支持
        BYTE  byHookEdgeStrUpperLimit; //勾边等级上限阈值
        BYTE  byHookEdgeStrLowerLimit; //勾边等级下限阈值
        BYTE  byWideTemperatureRangemode; //温宽工作模式，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：温宽模式上下限均配置
        bit1：温宽模式只配置上限
        bit2：温宽模式只配置下限
        */
        BYTE  byIspAgcmode; //agc工作模式，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：线性模式
        bit1：直方图模式
        */
        BYTE  byAISuperResolution; //AI超分使能：0-不支持  1-支持
        BYTE  bySkyAreaCullLevel; //天空区域剔除百分比：0-不支持  1-支持
        BYTE  byBurnPreventionEnabled; //防灼烧模式使能：0-不支持  1-支持
        BYTE  byBurnPreventionMode; //防灼烧控制模式，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：自动控制模式
        bit1：手动控制模式
        */
        BYTE  byAutoShutEnabled; //自动挡片使能 1 - 不支持 2 - 支持
        DWORD  dwBurnPreventionShutterCloseTimeUpperLimit; //防灼烧挡片闭合时间(仅自动模式下生效) 上限阈值0 - 3600秒
        BYTE  byBurnPreventionShutterControl; //防灼烧挡片手动控制((仅手动模式下生效)) ，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：不控制
        bit1：挡片闭合
        bit2：挡片抬起
        */
        BYTE  byBurnPreventionRecovery; //防灼烧自恢复使能：0-不支持  1-支持
        BYTE  byIsothermEnabled; //等温线开启：0-不支持  1-支持
        BYTE  byRes3;
        DWORD  dwIsothermalUpperThreshold; //等温线温度上阈值-20℃~600℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwIsothermalLowerThreshold; //等温线温度下阈值-20℃~600℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwIsothermalType; //等温线显示类型，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：白热等温
        bit1：黑热等温
        bit2：熔岩等温
        bit3：铁红等温
        bit4：热铁等温
        bit5：医疗等温
        bit6：北极等温
        bit7：彩虹1等温
        bit8：彩虹2等温
        bit9：描红等温
        */
        BYTE  byRes[436];
    }USB_IMAGE_ENHANCEMENT_CAPABILITIES, *LPUSB_IMAGE_ENHANCEMENT_CAPABILITIES;

    //视频调整能力
    typedef struct tagUSB_IMAGE_VIDEO_ADJUST_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE  byImageFlipStyle; //镜像模式，按位表示枚举项支持情况：0-不支持，1-支持
        BYTE  byPowerLineFrequencyMode; //视频制式，按位表示枚举项支持情况：0-不支持，1-支持。bit0：PAL(不支持)
        BYTE  byCorridor; //镜头走廊模式（旋转）：0-不支持  1-支持
        BYTE  byDigitalZoom; //数字变倍，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：X1
        bit1：X2
        bit2：X4
        bit3：X8
        */
        BYTE  byCursor; //显示射表：0-不支持  1-支持
        BYTE  byBadPointCursor; //显示坏点十字光标：0-不支持  1-支持
        BYTE  byBadPointCursorShiftMode; //移动坏点十字光标方式，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：直接下发坐标
        bit1：下发移动指令
        */
        BYTE  byBadPointCursorShiftStep; //移动坏点十字调节最大步长
        BYTE  byRes[500];
    }USB_IMAGE_VIDEO_ADJUST_CAPABILITIES, *LPUSB_IMAGE_VIDEO_ADJUST_CAPABILITIES;

    //热成像总能力
    typedef struct tagUSB_THERMAL_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE  byIsSupportThermometryBasicParam; //是否支持测温基本参数配置：0-不支持  1-支持
        BYTE  byThermometryType; //测温类型：1-人体测温  2-工业测温
        BYTE  byThermalThermometryRegions; //测温规则配置：0-不支持  1-支持
        BYTE  byThermalAlgVersion; //热成像相关算法版本：0-不支持  1-支持
        BYTE  byThermalStreamParam; //热成像码流参数配置：0-不支持  1-支持
        BYTE  byThermalTempeatureCorrect; //测温修正（人体测温）：0-不支持  1-支持
        BYTE  byThermalBlackBody; //黑体参数设置：0-不支持  1-支持
        BYTE  byThermalBodyTempCompensation; //体温补偿参数配置：0-不支持  1-支持
        BYTE  byThermalJpecpic; //抓热图：0-不支持  1-支持
        BYTE  byThermalROIMaxTemperatrueSearch; //ROI最高温信息查询：0-不支持  1-支持
        BYTE  byThermalP2PParam; //全屏测温参数配置：0-不支持  1-支持
        BYTE  byThermometryCalibrationFile; //测温标定文件导入导出：0-不支持  1-支持
        BYTE  byThermometryExpertRegions; //专家测温规则配置：0-不支持  1-支持
        BYTE  byThermometryExpertCorrection; //专家测温校正参数配置：0-不支持  1-支持
        BYTE  byRes[494];
    }USB_THERMAL_CAPABILITIES, *LPUSB_THERMAL_CAPABILITIES;

#define MAX_TEMP_RANGE_NUM  10

    //测温档位信息
    typedef struct tagUSB_TEMPERATURE_RANGE_INFO
    {
        BYTE byTemperatureRangeID; //测温档位
        BYTE byRes[3];
        DWORD  dwTemperatureRangeUpperLimit; //测温档位温度上限，单位℃
        DWORD  dwTemperatureRangeLowerLimit;  //测温档位温度下限，单位℃
    }USB_TEMPERATURE_RANGE_INFO, *LPUSB_TEMPERATURE_RANGE_INFO;

    //测温基本参数能力
    typedef struct tagUSB_THERMOMETRY_BASIC_PARAM_CAPABILITIES
    {
        DWORD  dwSize;
        DWORD  dwTemperatureRange; //测温档位，按位表示档位支持情况：0-不支持 1-支持
        /*
        bit0： -20~150℃
        bit1：0~550℃
        bit2：0~650℃
        bit3： -4~302℃
        bit4：32~1022℃
        bit5：32~1200℃
        bit6： -20~650℃
        bit7： -20~1500℃
        bit8：automatic℃
        bit9： -20~120℃
        bit10：100~550℃
        bit11：28~45℃
        bit12：20~350℃
        bit13：20~45℃
        bit14：0~400℃
        bit15：30~45℃
        bit16：100~400℃
        bit17：100~350℃
        bit18： -40~150℃
        bit19：100~650℃
        bit20：300~2200℃
        bit22： -20~200℃
        bit23：0~800℃
        bit24：600~1800℃
        bit25：300~2000℃
        bit26：300~1500℃
        bit27：0~1200℃
        */
        DWORD  dwEnviroTemperatureUpperLimit; //环境温度上限阈值: -99.00~99.00℃(精确到小数点后两位)，传输时(实际值+100)*100换算成正整数
        DWORD  dwEnviroTemperatureLowerLimit; //环境温度下限阈值: -99.00~99.00℃(精确到小数点后两位)，传输时(实际值+100)*100换算成正整数
        DWORD  dwReflectiveTemperatureUpperLimit; //反射温度上限阈值: -100.0~1000.0℃(精确到小数点后1位)，传输时(实际值+100)*10换算成正整数
        DWORD  dwReflectiveTemperatureLowerLimit; //反射温度下限阈值: -100.0~1000.0℃(精确到小数点后1位)，传输时(实际值+100)*10换算成正整数
        DWORD  dwAtmosphericHumidityUpperLimit; //大气湿度值上限阈值: 0.0~100.0℃，传输时实际值*10换算成正整数
        DWORD  dwAtmosphericHumidityLowerLimit; //大气湿度值下限阈值: 0.0~100.0℃，传输时实际值*10换算成正整数
        DWORD  dwEmissivityUpperLimit; //发射率上限阈值: 0.01~1(精确到小数点后两位)，传输时实际值*100换算成整数
        DWORD  dwEmissivityLowerLimit; //发射率下限阈值: 0.01~1(精确到小数点后两位)，传输时实际值*100换算成整数
        DWORD  dwDistanceUpperLimit; //距离上限阈值，协议传输中约定以cm作为单位传输
        DWORD  dwDistanceLowerLimit; //距离下限阈值，协议传输中约定以cm作为单位传输
        BYTE  byThermometryEnabled; //开启测温功能：0-不支持  1-支持
        BYTE  byDisplayMaxTemperatureEnabled; //显示最高温：0-不支持  1-支持
        BYTE  byDisplayMinTemperatureEnabled; //显示最低温：0-不支持  1-支持
        BYTE  byDisplayAverageTemperatureEnabled; //显示平均温：0-不支持  1-支持
        BYTE  byTemperatureUnit; //温度单位，按位表示枚举项支持情况：0-不支持，1-支持。（协议传输中约定以摄氏温度作为单位传输）
        /*
        bit0：摄氏温度
        bit1：华氏温度
        bit2：开尔文温度
        */
        BYTE  byCalibrationCoefficientEnabled; //启用标定系数：0-不支持  1-支持
        BYTE  byModifyTemperatureRange; //是否支持修改测温档位：1-不支持 2-支持
        BYTE  byRes1;
        DWORD  dwCalibrationCoefficientUpperLimit; //标定系数上限阈值：0.00~30.00，传输时实际值 * 100换算成整数
        DWORD  dwCalibrationCoefficientLowerLimit; //标定系数下限阈值：0.00~30.00，传输时实际值 * 100换算成整数
        DWORD  dwExternalOpticsWindowCorrectionUpperLimit; //外部光学温度上限阈值：-40.0~80.0℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwExternalOpticsWindowCorrectionLowerLimit; //外部光学温度下限阈值：-40.0~80.0℃，传输时(实际值 + 100) * 10换算成正整数
        BYTE  byDistanceUnit; //距离单位，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：米
        bit1：厘米
        bit2：英尺
        */
        BYTE  byReflectiveEnable; //反射温度使能：0-不支持  1-支持
        BYTE  byThermometryInfoDisplayposition; //测温信息显示位置，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：跟随规则
        bit1：屏幕左上角
        */
        BYTE  byThermometryStreamOverlay; //码流叠加温度信息：0-不支持  1-支持
        DWORD  dwAlertUpperLimit; //预警温度上限阈值：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwAlertLowerLimit; //预警温度下限阈值：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwAlarmUpperLimit; //报警温度上限阈值：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwAlarmLowerLimit; //报警温度下限阈值：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwExternalOpticsTransmit; //外部光学透过率：0-不支持  1-支持
        BYTE  byDisplayCenTempEnabled; //显示中心温：0-不支持  1-支持
        BYTE  byBackcolorEnabled; //显示背景色：0-不支持  1-支持
        BYTE  byShowAlarmColorEnabled; //报警颜色显示使能：0-不支持  1-支持
        BYTE  byTemperatureRangeAmount;  //测温档位总数，对应struTempTangeInfo具体内容个数
        USB_TEMPERATURE_RANGE_INFO  struTempRangeInfo[MAX_TEMP_RANGE_NUM]; //测温档位信息列表
        BYTE byFloatTransMode; //浮点数传输模式，按位表示枚举项支持情况0-不支持，1-支持   bit0 - 整型传输  bit1 - 移位传输
        BYTE byShiftLength; //浮点数移位传输乘以2的N次方，其中N的大小，安慰表示枚举支持情况：0-不支持，1-支持  bit0：6  bit1：9 bit2：13 bit3：16 bit4：19
        BYTE byEnviromentTemperatureEnable; //环境温度使能1 - 不支持 2 - 支持
        BYTE  byRes[289];
    }USB_THERMOMETRY_BASIC_PARAM_CAPABILITIES, *LPUSB_THERMOMETRY_BASIC_PARAM_CAPABILITIES;

    //测温模式配置能力
    typedef struct tagUSB_THERMAL_THERMOMETRY_MODE_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE  byThermometryMode; //测温模式，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：普通
        bit1：专家
        */
        BYTE  byThermometryROIEnabled;//测温ROI使能：0-不支持，1-支持
        BYTE  byRes[506];
    }USB_THERMAL_THERMOMETRY_MODE_CAPABILITIES, *LPUSB_THERMAL_THERMOMETRY_MODE_CAPABILITIES;

    //测温规则配置能力
    typedef struct tagUSB_THERMAL_THERMOMETRY_REGIONS_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE byRegionNumUpperLimit;//规则区域总个数上线阈值
        BYTE byRegionEnabled;//区域使能：0-不支持  1-支持
        BYTE byRes[506];
    }USB_THERMAL_THERMOMETRY_REGIONS_CAPABILITIES, *LPUSB_THERMAL_THERMOMETRY_REGIONS_CAPABILITIES;

    //热成像码流参数配置能力
    typedef struct tagUSB_THERMAL_STREAM_PARAM_CAPABILITIES
    {
        DWORD  dwSize;
        DWORD  dwVideoCodingType; //码流数据编解码类型，按位表示枚举项支持情况：0-不支持，1-支持。
        /*
        bit0：热成像裸数据
        bit1：全屏测温数据
        bit2：实时裸数据
        bit3：热图数据（数据格式见附录）
        bit4：热成像实时流
        bit5： YUV实时数据（数据格式见附录）
        bit6：PS封装MJPEG实时流
        bit7：全屏测温数据 + YUV实时流
        bit8：YUV + 裸数据
        bit9：仅YUV不含测温头
        bit10：测温头 + 离线测温信息 + 裸数据 + YUV
        */
        BYTE byRes[504];
    }USB_THERMAL_STREAM_PARAM_CAPABILITIES, *LPUSB_THERMAL_STREAM_PARAM_CAPABILITIES;

    //测温修正（人体测温）能力
    typedef struct tagUSB_THERMAL_TEMPERATURE_CORRECT_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE byEnabled; //使能：0-不支持  1-支持
        BYTE byStreamOverlay; //修正温度码流叠加使能：0-不支持  1-支持
        BYTE byCorrectEnabled; //测温修正使能：0-不支持  1-支持
        BYTE byRes1;
        DWORD  dwEmissivityUpperLimit; //发射率上限阈值：0.01~1.00，传输时实际值*100换算成整数
        DWORD  dwEmissivityLowerLimit; //发射率下限阈值：0.01~1.00，传输时实际值*100换算成整数
        DWORD  dwDistanceUpperLimit; //距离上限阈值：0.3~2m，传输时以厘米(cm)为单位
        DWORD  dwDistanceLowerLimit; //距离下限阈值：0.3~2m，传输时以厘米(cm)为单位
        DWORD  dwTemperatureUpperLimit;  //温度上限阈值：30.0~50.0℃，传输时实际值*10换算成整数
        DWORD  dwTemperatureLowerLimit;  //温度下限阈值：30.0~50.0℃，传输时实际值*10换算成整数
        BYTE  byRes[480];
    }USB_THERMAL_TEMPERATURE_CORRECT_CAPABILITIES, *LPUSB_THERMAL_TEMPERATURE_CORRECT_CAPABILITIES;

    //黑体参数配置能力
    typedef struct tagUSB_THERMAL_BLACK_BODY_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byEnabled;//使能：0-不支持  1-支持
        BYTE byRes1[3];
        DWORD dwEmissivityUpperLimit; //黑体发射率上限阈值：0.01~1.00，传输时实际值 * 100换算成整数
        DWORD dwEmissivityLowerLimit; //黑体发射率下限阈值：0.01~1.00，传输时实际值 * 100换算成整数
        DWORD dwDistanceUpperLimit; //距离上限阈值：0.3~2m，协议传输时以厘米(cm)为单位
        DWORD dwDistanceLowerLimit; //距离下限阈值：0.3~2m，协议传输时以厘米(cm)为单位
        DWORD dwTemperatureUpperLimit; //黑体温度上限阈值：30.0~50.0℃，传输时实际值*10换算成整数
        DWORD dwTemperatureLowerLimit; //黑体温度下限阈值：30.0~50.0℃，传输时实际值*10换算成整数
        BYTE byRes[480];
    }USB_THERMAL_BLACK_BODY_CAPABILITIES, *LPUSB_THERMAL_BLACK_BODY_CAPABILITIES;

    //体温补偿参数配置能力
    typedef struct tagUSB_THERMAL_BODYTEMP_COMPENSATION_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byEnabled;//使能：0-不支持  1-支持
        BYTE byType;//补偿方式，按位表示枚举项支持情况：0-不支持  1-支持
        /*
        bit0：手动补偿
        bit1：自动补偿
        */
        BYTE byRes1[2];
        DWORD dwCompensationValueUpperLimit;//补偿温度上限阈值：-10.0~10.0℃，传输时实际值 * 10换算成整数
        DWORD dwCompensationValueLowerLimit;//补偿温度下限阈值：-10.0~10.0℃，传输时实际值 * 10换算成整数
        DWORD dwSmartCorrectionUpperLimit;//手动校准上限阈值：-99.0~99.0℃，传输时(实际值+100)*10换算成正整数
        DWORD dwSmartCorrectionLowerLimit;//手动校准下限阈值：-99.0~99.0℃，传输时(实际值+100)*10换算成正整数
        DWORD dwEnvironmentalTemperatureUpperLimit;//环境温度上限阈值：-99.0~99.0℃，传输时(实际值+100)*10换算成正整数
        DWORD dwEnvironmentalTemperatureLowerLimit; //环境温度下限阈值：-99.0~99.0℃，传输时(实际值+100)*10换算成正整数
        BYTE byEnvironmentalTemperatureMode; //环境温度模式，按位表示枚举项支持情况：0-不支持，1-支持
        /*
        bit0：自动模式
        bit1：手动模式
        */
        BYTE byRes[479];
    }USB_THERMAL_BODYTEMP_COMPENSATION_CAPABILITIES, *LPUSB_THERMAL_BODYTEMP_COMPENSATION_CAPABILITIES;

    //ROI最高温信息查询能力
    typedef struct tagUSB_THERMAL_ROI_MAX_TEMPERATURE_SEARCH_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byROITimeSynchronizationConfig;//ROI校时配置能力：0-不支持  1-支持
        BYTE byJpegPicEnabled;//设备是否返回JPEG图片：0-不支持  1-支持
        BYTE byMaxTemperatureOverlay;//是否叠加最高温：0-不支持  1-支持
        BYTE byRegionOverlay;//是否叠加规则框：0-不支持  1-支持
        BYTE byROIRegionNumUpperLimit;//ROI区域总个数上限阈值
        BYTE byROIRegionEnabled;//ROI区域使能：0-不支持  1-支持
        BYTE byRes1[2];
        DWORD dwDistanceUpperLimit;//距离上限阈值：0.3-2m，精确到小数点后1位，协议传输中约定以cm作为单位传输
        DWORD dwDistanceLowerLimit;//距离下限阈值：0.3-2m，精确到小数点后1位，协议传输中约定以cm作为单位传输
        BYTE byRes[492];
    }USB_THERMAL_ROI_MAX_TEMPERATURE_SEARCH_CAPABILITIES, *LPUSB_THERMAL_ROI_MAX_TEMPERATURE_SEARCH_CAPABILITIES;

    //测温标定文件导入导出能力
    typedef struct tagUSB_THERMAL_THERMOMETRY_CALIBRATION_FILE_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byThermometryCalibrationFileImport;//测温标定文件导入：0-不支持  1-支持
        BYTE byThermometryCalibrationFileExport;//测温标定文件导出：0-不支持  1-支持
        BYTE byRes[506];
    }USB_THERMAL_THERMOMETRY_CALIBRATION_FILE_CAPABILITIES, *LPUSB_THERMAL_THERMOMETRY_CALIBRATION_FILE_CAPABILITIES;

    //专家测温规则配置能力
    typedef struct tagUSB_THERMAL_THERMOMETRY_EXPERT_REGIONS_CAPABILITIES
    {
        DWORD dwSize;
        BYTE byRegionNumUpperLimit;//规则区域总个数上限阈值
        BYTE byRuleRegionNumUpperLimit;//多边形区域个数上限阈值
        BYTE byRuleRegionEnabled;//区域使能：0-不支持  1-支持
        BYTE byRuleRegionname;//规则名称：0-不支持  1-支持
        BYTE byRuleRegionPointNumUpperLimit;//多边形区域顶点总个数上限阈值
        BYTE byRuleRegionPointNumLowerLimit;//多边形区域顶点总个数上限阈值
        BYTE byRulePointNumUpperLimit;//点规则个数上阈值
        BYTE byRuleLineNumUpperLimit;//线规则个数上阈值
        DWORD  dwEmissivityUpperLimit;//发射率上限阈值：0.01~1.00(精确到小数点后两位)，传输时实际值 * 100换算成整数
        DWORD  dwEmissivityLowerLimit;//发射率下限阈值：0.01~1.00(精确到小数点后两位)，传输时实际值 * 100换算成整数
        DWORD  dwDistanceUpperLimit;//距离上限阈值：0.3-3m，协议传输中约定以cm作为单位整数传输
        DWORD  dwDistanceLowerLimit;//距离下限阈值：0.3-3m，协议传输中约定以cm作为单位整数传输
        BYTE byReflectiveEnable;//反射温度使能：0-不支持  1-支持
        BYTE byRegionCoordinateMode;//区域坐标生效模式，按位表示枚举项支持情况，0-不支持，1-支持  bit0 - 归一化坐标 bit1 - 裸数据实际坐标
        BYTE byFloatTransMode;//浮点数传输模式，按位表示枚举项支持情况，0-不支持，1-支持  bit0 - 整型传输 bit1 - 移位传输
        BYTE byShiftLength;//浮点数移位传输乘以2的N次方，其中N的大小，安慰表示枚举支持情况：0-不支持，1-支持 bit0：6 bit1：9 bit2：13 bit3：16 bit4：19
        DWORD  dwReflectiveTemperatureUpperLimit;//反射温度上限阈值：-100.0~1000.0℃（精确到小数点后1位），传输时(实际值+100)*10换算成正整数
        DWORD  dwReflectiveTemperatureLowerLimit;//反射温度下限阈值：-100.0~1000.0℃（精确到小数点后1位），传输时(实际值+100)*10换算成正整数
        BYTE byShowAlarmColorEnabled;//报警颜色显示使能：0-不支持  1-支持
        BYTE byRes2[3];
        DWORD  dwAlertUpperLimit;//预警温度上限阈值：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwAlertLowerLimit;//预警温度下限阈值：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwAlarmUpperLimit;//报警温度上限阈值：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwAlarmLowerLimit;//报警温度下限阈值：-20℃~400℃，传输时(实际值 + 100) * 10换算成正整数
        BYTE  byRes[452];
    }USB_THERMAL_THERMOMETRY_EXPERT_REGIONS_CAPABILITIES, *LPUSB_THERMAL_THERMOMETRY_EXPERT_REGIONS_CAPABILITIES;

    //专家测温校正参数配置能力
    typedef struct tagUSB_THERMAL_THERMOMETRY_EXPERT_CORRECTION_PARAM_CAPABILITIES
    {
        DWORD dwSize;
        DWORD dwDistanceUpperLimit; //距离上限阈值：0.3~3m，协议传输中约定以cm作为单位整数传输
        DWORD dwDistanceLowerLimit; //距离下限阈值：0.3~3m，协议传输中约定以cm作为单位整数传输
        DWORD dwEnviroTemperatureUpperLimit; //环境温度上限阈值：-273.0 - 1000.0(精确到小数点后1位)，传输时（实际值 + 300） * 10换算成整数
        DWORD dwEnviroTemperatureLowerLimit; //环境温度下限阈值：-273.0 - 1000.0(精确到小数点后1位)，传输时（实际值 + 300） * 10换算成整数
        DWORD dwEmissivityUpperLimit; //发射率上限阈值：0.01 - 1.00，传输时实际值 * 100换算成整数
        DWORD dwEmissivityLowerLimit; //发射率下限阈值：0.01 - 1.00，传输时实际值 * 100换算成整数
        BYTE  byPointNumUpperLimit; //温度点个数上限阈值
        BYTE  byPointNumLowerLimit; //温度点个数下限阈值
        BYTE  byRes1[2];
        DWORD  dwPresetTemperatureUpperLimit; //预设温度上限阈值：-40.0 - 650.0℃，传输时(实际值 + 100) * 10换算成正整数
        DWORD  dwPresetTemperatureLowerLimit; //预设温度下限阈值：-40.0 - 650.0℃，传输时(实际值 + 100) * 10换算成正整数
        BYTE  byRes[472];
    }USB_THERMAL_THERMOMETRY_EXPERT_CORRECTION_PARAM_CAPABILITIES, *LPUSB_THERMAL_THERMOMETRY_EXPERT_CORRECTION_PARAM_CAPABILITIES;

    //设备描述信息
    typedef struct tagUSB_SYSTEM_DEVICE_DESCRIPTION_INFO
    {
        DWORD dwSize;
        BYTE  szDeviceSerialNumber[64]; //设备序列号（设备型号+生成日期+4byte信息+序列号）
        BYTE  szMachineSerialNumber[32]; //整机序列号（指的是设备序列号中包含的序列号）
        BYTE  szModel[32]; //设备型号
        BYTE  szMechanismSerialNumber[32]; //机芯序列号（机芯标定工序中写入的机芯序列号）
        BYTE  szNUCParaVersion[64]; //NUC参数版本号
        BYTE  szISPParaVersion[64]; //ISP参数版本号
        BYTE  byConnectMode; //设备连接方式：1-USB2.0  2-USB3.0
        BYTE  byRes[1023];
    }USB_SYSTEM_DEVICE_DESCRIPTION_INFO, *LPUSB_SYSTEM_DEVICE_DESCRIPTION_INFO;

    //串口透传
    typedef struct tagUSB_SYSTEM_SERIAL_DATA_TRANSMISSION
    {
        DWORD dwSize;
        BYTE  byMode; //模式：0-保留，1-读，2-写
        BYTE  byRes1;
        WORD  wDeviceCMDFlag; //命令标识符：[0,255]
        DWORD dwDeviceCMD; //命令：[0,10000]
        DWORD dwValue; //值：[0,10000]
        BYTE  byRes[512];
    }USB_SYSTEM_SERIAL_DATA_TRANSMISSION, *LPUSB_THERMAL_SERIAL_DATA_TRANSMISSION;

    //视频通用总能力
    typedef struct tagUSB_VIDEO_COMMON_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE byVideoCode; //视频编码：0-不支持  1-支持
        BYTE byVideoFusion; //视频图像融合参数：0-不支持  1-支持
        BYTE byLenCalibration; //镜头标定：0-不支持  1-支持
        BYTE byRes[505];
    }USB_VIDEO_COMMON_CAPABILITIES, *LPUSB_VIDEO_COMMON_CAPABILITIES;

    //镜头标定能力
    typedef struct tagUSB_VIDEO_LEN_CALIBRATION_CAPABILITIES
    {
        DWORD  dwSize;
        DWORD  dwFocusUpperLimit; //聚焦值上限阈值
        DWORD  dwFocusLowerLimit; //聚焦值下限阈值
        BYTE  byRes[500];
    }USB_VIDEO_LEN_CALIBRATION_CAPABILITIES, *LPUSB_VIDEO_LEN_CALIBRATION_CAPABILITIES;

#define MAX_RESOLUTION_INFO_NUM  10

    //分辨率信息
    typedef struct tagUSB_VIDEO_RESOLUTION_INFO
    {
        BYTE byVideoResolutionID;  //分辨率id：1-256*192, 2-384 * 288, 3-720 * 576, 4-1024 * 768, 5-96 * 96, 6-160 * 120, 7-640 * 512, 8-192 * 144, 9-480 * 360, 10-640 * 480
        BYTE byRes1[3];
        DWORD dwVideoResolutionWidth;  //分辨率宽
        DWORD dwVideoResolutionHeight;  //分辨率高
        BYTE byRes[4];
    }USB_VIDEO_RESOLUTION_INFO, *LPUSB_VIDEO_RESOLUTION_INFO;

    //非压缩帧分辨率信息
    typedef struct tagUSB_UNPACKED_RESOLUTION_INFO
    {
        BYTE byUnpackedResolution;  //非压缩帧分辨率（只读）：当帧率小于5帧时, 设备会使用非压缩帧上传数据, 根据此只读参数配置视频属性信息, 避免因非压缩帧分辨率扩大导致数据被按压缩帧分辨率配置的YVC通道过滤掉
        //1-320*240, 2-640*480, 3-640*512, 4-1024*600, 5-1280*720
        BYTE byRes1[3];
        DWORD dwUnpackedResolutionWidth;  //非压缩帧分辨率宽
        DWORD dwUnpackedResolutionHeight;  //非压缩帧分辨率高
        BYTE byRes[4];
    }USB_UNPACKED_RESOLUTION_INFO, *LPUSB_UNPACKED_RESOLUTION_INFO;

    //视频编码能力
    typedef struct tagUSB_VIDEO_CODE_CAPABILITIES
    {
        DWORD  dwSize;
        DWORD dwMaxFrameRateUpperLimit; //帧率上限阈值：1-30fps
        DWORD dwMaxFrameRateLowerLimit; //帧率下限阈值：1-30fps
        DWORD dwVideoResolutionListNum; //分辨率列表子项总个数，上限值为10
        DWORD dwUnpackedResolutionListNum; //非压缩帧分辨率列表子项总个数，上限值为10
        USB_VIDEO_RESOLUTION_INFO struVideoResolution[MAX_RESOLUTION_INFO_NUM];
        USB_UNPACKED_RESOLUTION_INFO struUnpackedResolution[MAX_RESOLUTION_INFO_NUM];
        DWORD dwMaxFrameRate3UpperLimit; //USB3.0帧率上限阈值：1-30fps
        DWORD dwMaxFrameRate3LowerLimit; //USB3.0帧率下限阈值：1-30fps
        BYTE  byRes[164];
    }USB_VIDEO_CODE_CAPABILITIES, *LPUSB_VIDEO_CODE_CAPABILITIES;

    //伪彩映射表
    typedef struct tagUSB_IMAGE_PALETTE_DATA{
        DWORD dwSize; //结构体大小
        BYTE byPaletteMode; //伪彩色颜色模式: 1-白热 2-黑热 10-融合1 11-彩虹 12-融合2 13-铁红1 14-铁红2 15-深褐色 16-色彩1 17-色彩2 18-冰火 19-雨 20-红热 21-绿热 22-深蓝
        BYTE byRes1[3];
        DWORD dwDataLen;//伪彩映射表长度
        BYTE byRes2[4];
        BYTE  *pData; //伪彩映射表
        BYTE byRes[1024];
    } USB_IMAGE_PALETTE_DATA, *LPUSB_IMAGE_PALETTE_DATA;

    //测温离线分析数据
    typedef struct tagUSB_THERAML_THERMOMETRY_OFFLINE_DATA{
        DWORD dwSize; //结构体大小
        DWORD dwDataLen;//[in]pData缓冲区大小,[out]测温离线分析数据长度
        BYTE byRes2[4];
        BYTE  *pData; //测温离线分析数据
        BYTE byRes[1024];
    } USB_THERAML_THERMOMETRY_OFFLINE_DATA, *LPUSB_THERAML_THERMOMETRY_OFFLINE_DATA;

    //图像输出配置
    typedef struct tagUSB_IMAGE_OUTPUT_CFG
    {
        DWORD dwSize; //结构体大小
        BYTE byEnable; //输出使能: 1-关闭 2-开启
        BYTE byType; //图像类型: 1-假图 2-离线测温图
        BYTE byRes[506];
    }USB_IMAGE_OUTPUT_CFG, *LPUSB_IMAGE_OUTPUT_CFG;

    //设备描述信息能力
    typedef struct tagUSB_SYSTEM_DEVICE_DESCRIPTION_INFO_CAPABILITIES
    {
        DWORD  dwSize;
        BYTE  byDeviceSerialNumber; //设备序列号（设备型号+生成日期+4byte信息+序列号）: 1-不支持 2-支持
        BYTE  byMachineSerialNumber; //整机序列号（指的是设备序列号中包含的序列号）: 1-不支持 2-支持
        BYTE  byModel; //设备型号: 1-不支持 2-支持
        BYTE  byMechanismSerialNumber; //机芯序列号（机芯标定工序中写入的机芯序列号）: 1-不支持 2-支持
        BYTE  byNUCParaVersion; //NUC参数版本号: 1-不支持 2-支持
        BYTE  byISPParaVersion; //ISP参数版本号: 1-不支持 2-支持
        BYTE  byConnectMode; //设备连接方式，按位表示枚举项支持情况：0-不支持，1-支持
        /*
        bit0 - USB 2.0
        bit1 - USB 3.0
        */
        BYTE byRes[245];
    }USB_SYSTEM_DEVICE_DESCRIPTION_INFO_CAPABILITIES, *LPUSB_SYSTEM_DEVICE_DESCRIPTION_INFO_CAPABILITIES;

    //控制码流启停（调试）
    typedef struct tagUSB_CTRL_THERMAL_STREAM_PARAM
    {
        DWORD dwSize;
        BYTE byEnable;//使能：0-关闭取流  1-开启取流
        BYTE byRes[27];
    }USB_CTRL_THERMAL_STREAM_PARAM, *LPUSB_CTRL_THERMAL_STREAM_PARAM;


    //////////////////////////////////////////////////////////热成像码流解析结构体定义开始//////////////////////////////////////////////////////////////////////
#define INT_MINI    (-2147483647 - 1)  /* minimum (signed) int value */
#define INT_MAXI    2147483647  /* maximum (signed) int value */
    //码流类型
    typedef enum tagUSB_STREAM_TYPE_E
    {
        ENUM_STREAM_H264_TYPE,
        ENUM_STREAM_H265_TYPE,
        ENUM_STREAM_JPEG_TYPE,
        ENUM_STREAM_AUD_TYPE,
        ENUM_STREAM_META_TYPE,
        ENUM_STREAM_UPDATE_TYPE,  //重新刷新包，告知APP当前帧与之前的参数存在不同，或者最新参数 
        ENUM_STREAM_RTDATA_TYPE,  //实时上传数据 
        ENUM_STREAM_TYPE_INT_MIN = INT_MINI,
        ENUM_STREAM_TYPE_INT_MAX = INT_MAXI
    }USB_STREAM_TYPE_E;

    //时间戳
    typedef struct tagUSB_DATE_TIME
    {
        WORD  wYear; //年
        WORD  wMonth;//月
        WORD  wDayOfWeek;//0-星期日, 1-星期一, 2-星期二, 3-星期三, 4-星期四, 5-星期五, 6-星期六
        WORD  wDay;//日
        WORD  wHour;//小时, 0~23
        WORD  wMinute;//分钟, 0~59
        WORD  wSecond;//秒, 0~59
        WORD  wMillisecond;//毫秒, 0~999
    }USB_DATE_TIME, *LPUSB_DATE_TIME;

    //实时温度数据输出结构体
    typedef struct tagUSB_STREAM_RT_DATA_INFO_S
    {
        DWORD  dwRTDataType; // 1-14bit裸数据; 2-全屏测温结果数据; 3-YUV数据
        DWORD  dwFrmNum; //帧序列号，实时上传的帧序列号是连续递增的偶数1000、1002、1004、1006
        DWORD  dwStdStamp; //DSP相对时间戳
        USB_DATE_TIME struTime;//年月日时间，该时间用于记录当前帧数据的采集时间，是sensor采集完成后的时间，该时间用于用户匹配搜索对应帧时使用
        DWORD  dwWidth;//裸数据宽
        DWORD  dwHeight;//裸数据高
        DWORD  dwLen;//实时测温矩阵的长度，以字节为单位，再加上4个字节， 如4字节的float测温矩阵：120*160*4+4 
        DWORD  dwFps;//实时上传的帧率，当前固定配置为用户配置的帧率
        DWORD  dwChan;//通道号，暂时固定为0
    }USB_STREAM_RT_DATA_INFO_S, *LPUSB_STREAM_RT_DATA_INFO_S;

    //实时温度数据附加信息结构体
    typedef struct tagUSB_STREAM_FS_SUPPLE_INFO_TEMP
    {
        DWORD  dwTmDataMode;  //0为4字节，1为2字节 
        DWORD  dwTmScale;   //测温缩放比例 
        DWORD  dwTmOffset;  //测温偏移量，当前固定为0 
        DWORD  dwIsFreezedata;  //是否是冻结数据，1-冻结，0-非冻结 
    }USB_STREAM_FS_SUPPLE_INFO_TEMP, *LPUSB_STREAM_FS_SUPPLE_INFO_TEMP;

    //实时JPEG的输出结构体
    typedef struct tagUSB_RT_JPEG_DATA_INFO_S
    {
        DWORD  dwFrmNum;  //帧序列号，实时上传的帧序列号是连续递增的偶数 1000、1002、1004、1006 
        DWORD  dwWidth;  //JPEG数据宽 
        DWORD  dwHeight;  //JPEG数据高 
        DWORD  dwJpegLen;  //JPEG数据长度(DATA2)
        DWORD  dwStdStamp;  //DSP相对时间戳 
        USB_DATE_TIME struTime;  //当前时间 
    }USB_RT_JPEG_DATA_INFO_S, *LPUSB_RT_JPEG_DATA_INFO_S;

    //温度单位
    typedef enum tagUSB_IFR_TEMP_UNIT
    {
        IFR_TEMP_CENTIGRADE = 0,  //摄氏度 
        IFR_TEMP_FAHRENHEIT = 1,  //华氏度 
        IFR_TEMP_KELVIN = 2,  //开尔文

        IFR_TEMP_UNIT_MIN = INT_MINI,
        IFR_TEMP_UNIT_MAX = INT_MAXI
    }USB_IFR_TEMP_UNIT;

    //坐标
    typedef struct tagUSB_IFR_POINT
    {
        int  x;
        int  y;
    }USB_IFR_POINT, *LPUSB_IFR_POINT;

    //单个区域测温结果	  
    typedef struct tagUSB_IFR_SQUARE_ROI_OUTCOME_INFO
    {
        BYTE byEnable;  //是否启用：0-否，1-是
        BYTE byRegionId;  //区域ID
        BYTE byRes[34];  //保留字段
        char szName[32];  //区域名称
        float fEmissionRate;  //发射率: [0.00, 1.00]
        float fDistance;  //预设的测温距离
        float fMinTmp;  //最低温度: [-40.0, 1000.0]，单位摄氏度
        float fMaxTmp;  //最高温度: [-40.0, 1000.0]，单位摄氏度
        float fAvgTmp;  //平均温度: [-40.0, 1000.0]，单位摄氏度
        USB_IFR_POINT struPoints[2];  //保存测试结果中的最高温和最低温坐标，归一化到0-1000，数组下标: 0-最高温，1-最低温
    }USB_IFR_SQUARE_ROI_OUTCOME_INFO, *LPUSB_IFR_SQUARE_ROI_OUTCOME_INFO;

#define IFR_MAX_SQUARE_REGION_NUM  10
    //ROI矩形区域测温输出给外部的信息列表
    typedef struct tagUSB_IFR_SQUARE_ROI_OUTCOME_LIST
    {
        DWORD dwRoiRegionNum;  //有效测温区域数量 
        USB_IFR_SQUARE_ROI_OUTCOME_INFO struIfrRoiOutcome[IFR_MAX_SQUARE_REGION_NUM];  // 测温结果
    }USB_IFR_SQUARE_ROI_OUTCOME_LIST, *LPUSB_IFR_SQUARE_ROI_OUTCOME_LIST;

    //实时测温信息的输出结构体
    typedef struct tagUSB_IFR_REALTIME_TM_UPLOAD_INFO
    {
        USB_IFR_TEMP_UNIT  enumTempUnit;  // 温度单位，默认摄氏度，主要用于上传 
        BYTE  byRefTempkey;  //反射温度开关
        BYTE  byRes1[3];  //保留 
        float  fDistance;  //测量距离
        float  fRefTemp;  //反射温度，根据反射温度开关
        float  fEmissionRate;  //发射率，[0.00, 1.0] 
        float  fEnvTemp;  //环境温度, 无温感时从测温算法库中获取
        float  fMinTmp;  //全屏最低温度
        float  fMaxTmp;  // 全屏最高温度
        float  fAvrTmp;  //全屏平均温度
        USB_IFR_POINT  struPoints[3];  //保存测试结果中的最高温和最低温坐标，归一化到0-1000，数组下标: 0-最高温，1-最低温 ，2-平均温
        BYTE  byRes[24];
        USB_IFR_SQUARE_ROI_OUTCOME_LIST struRoiOutList; //ROI测温输出的信息
    }USB_IFR_REALTIME_TM_UPLOAD_INFO, *LPUSB_IFR_REALTIME_TM_UPLOAD_INFO;


    //热成像全屏测温实时流数据结构，每帧流数据为：USB_THERMAL_STREAM_TEMP_S(头数据) + DATA(全屏测温数据)
    typedef struct tagUSB_THERMAL_STREAM_TEMP_S
    {
        DWORD  dwMagicNo;  //魔术字, 规定为0x70827773, 即"FRMI"的ASCII码
        DWORD  dwHeadLen; //Head长度
        DWORD  dwStreamType; //数据类型RTData, 参见STREAM_TYPE_E
        DWORD  dwStreamLen; //全屏测温数据长度(DATA)
        USB_STREAM_RT_DATA_INFO_S  struRTDataInfo;//实时温度数据信息
        USB_STREAM_FS_SUPPLE_INFO_TEMP  struFsSuppleInfo;//实时温度数据附加信息
        BYTE  byRes[48];
        DWORD  dwCrcVal;//结构体校验码，对结构体中前面数据进行校验
    }USB_THERMAL_STREAM_TEMP_S, *LPUSB_THERMAL_STREAM_TEMP_S;

    //热成像热图实时流数据结构，每帧流数据为：USB_THERMAL_STREAM_TEMP_HOT(头数据) + DATA1(全屏测温数据) + DATA2(JPEG数据)
    typedef struct tagUSB_THERMAL_STREAM_TEMP_HOT
    {
        DWORD  dwMagicNo;  //魔术字, 规定为 0x70827773
        DWORD  dwHeadLen; //Head长度, 以字节为单位
        DWORD  dwStreamType; //数据类型, 参见STREAM_TYPE_E
        DWORD  dwStreamLen; //全屏测温数据长度(DATA1)
        DWORD  dwIRFJpg;//是否携带JPEG图片
        USB_STREAM_RT_DATA_INFO_S  struRTDataInfo;//实时温度数据信息
        USB_STREAM_FS_SUPPLE_INFO_TEMP  struFsSuppleInfo;//实时温度数据附加信息
        USB_RT_JPEG_DATA_INFO_S  struRTJpegDataInfo;//实时JPEG数据信息
        USB_IFR_REALTIME_TM_UPLOAD_INFO  struRTDataUpload;//实时测温信息
        BYTE  byRes[48];
        DWORD  dwCrcVal;//结构体校验码，对结构体中前面数据进行校验
    }USB_THERMAL_STREAM_TEMP_HOT, *LPUSB_THERMAL_STREAM_TEMP_HOT;

    //////////////////////////////////////////////////////////热成像码流解析结构体定义结束//////////////////////////////////////////////////////////////////////

    typedef struct tagUSB_DEVICE_INFO
    {
        DWORD   dwSize;   //结构体大小
        DWORD   dwIndex; // 设备索引 
        DWORD   dwVID;   //设备VID
        DWORD   dwPID;   //设备PID
        char    szManufacturer[MAX_MANUFACTURE_LEN/*32*/];//制造商（来自描述符）
        char    szDeviceName[MAX_DEVICE_NAME_LEN/*32*/];//设备名称（来自描述符）
        char    szSerialNumber[MAX_SERIAL_NUMBER_LEN/*48*/];//设备序列号（来自描述符）
        BYTE    byHaveAudio;    // 是否具有音频
        BYTE    iColorType;     // 1.RGB路， 2.IR路
        BYTE    szDevicePath[MAX_PATH_LEN];
        BYTE    byDeviceType;   //设备类型，0-HID，大容量设备 1-UVC(视频)设备 2-UVC(视频)设备 4-UAC(音频)设备，5-UVC(视频)设备
        DWORD   dwBCD;          //设备软件版本号
        BYTE    byRes[249];
    } USB_DEVICE_INFO, *LPUSB_DEVICE_INFO;

    typedef struct tagUSB_USER_LOGIN_INFO
    {
        DWORD   dwSize; //结构体大小
        DWORD   dwTimeout; //登录超时时间（单位：毫秒）,取值范围：0-默认值5000毫秒，[1000,5000]-具体超时时间
        DWORD   dwDevIndex; //设备下标
        DWORD   dwVID;  //设备VID，枚举设备时得到
        DWORD   dwPID;  //设备PID，枚举设备时得到
        char    szUserName[MAX_USERNAME_LEN/*32*/]; //用户名，获取激活状态时无需填
        char    szPassword[MAX_PASSWORD_LEN/*16*/]; //密码，获取激活状态时无需填
        char    szSerialNumber[MAX_SERIAL_NUMBER_LEN/*48*/]; //设备序列号，枚举设备时得到
        BYTE    byLoginMode; //0-认证登陆 1-默认账号登陆（不关心用户名密码）（权限不同，部分功能需认证登陆才支持）
        // （尝试采用指定方式登陆）
        BYTE    byRes2[3];
        DWORD   dwFd; //设备描述符fd (android下没有root权限登录时使用)
        BYTE    byRes[248];
    } USB_USER_LOGIN_INFO, *LPUSB_USER_LOGIN_INFO;

    typedef struct tagUSB_DEVICE_REG_RES
    {
        DWORD   dwSize;   //结构体大小
        char    szDeviceName[MAX_DEVICE_NAME_LEN /*32*/]; //设备名称
        char    szSerialNumber[MAX_SERIAL_NUMBER_LEN /*48*/]; //设备序列号
        DWORD   dwSoftwareVersion; //软件版本号,高16位是主版本,低16位是次版本
        WORD    wYear;
        BYTE    byMonth;
        BYTE    byDay;
        BYTE    byRetryLoginTimes; //剩余可尝试登陆的次数
        BYTE    byRes1[3];             //保留
        DWORD   dwSurplusLockTime; //剩余时间，单位秒 用户锁定时，此参数有效
        BYTE    byRes[256];
    } USB_DEVICE_REG_RES, *LPUSB_DEVICE_REG_RES;


    typedef struct tagUSB_CONFIG_INPUT_INFO
    {
        void * lpCondBuffer;        //指向条件缓冲区
        DWORD  dwCondBufferSize;//条件缓冲区大小
        void * lpInBuffer;          //指向输出缓冲区
        DWORD  dwInBufferSize;   //输入缓冲区大小
        BYTE   byRes[48];
    } USB_CONFIG_INPUT_INFO, *LPUSB_CONFIG_INPUT_INFO; //64字节

    typedef struct tagUSB_CONFIG_OUTPUT_INFO
    {
        void * lpOutBuffer;      //指向输出缓冲区
        DWORD  dwOutBufferSize;  //输出缓冲区大小
        BYTE   byRes[56];
    } USB_CONFIG_OUTPUT_INFO, *LPUSB_CONFIG_OUTPUT_INFO; //64字节

    typedef struct tagUSB_UPGRADE_STATE_INFO
    {
        DWORD  dwSize;
        BYTE   byState;
        BYTE   byProgress;
        BYTE   byRes[6];
    } USB_UPGRADE_STATE_INFO, *LPUSB_UPGRADE_STATE_INFO; //12字节

    typedef struct tagUSB_UPGRADE_COND
    {
        DWORD dwSize;
        BYTE  byTimeout;
        BYTE  byFileCrc; //是否校验升级包：0-默认，不校验 1-校验
        BYTE  byRes[2];
        DWORD dwModuleID;
        BYTE  byRes1[4];
    } USB_UPGRADE_COND, *LPUSB_UPGRADE_COND;//16字节

    typedef struct tagUSB_MIME_UNIT
    {
        //HTTP格式如下
        //Content-Disposition: form-data; name="upload"; filename="C:\Users\test\Desktop\11.txt"
        //Content-Type: text/plain
        char szContentType[32];               //对应Content-Type
        char szName[MAX_FILE_PATH_LEN];       //对应name字段
        char szFilename[MAX_FILE_PATH_LEN];   //对应filename字段
        DWORD dwContentLen;              //Content的长度
        char* pContent;                       //数据指针
        BYTE byRes[16];
    }USB_MIME_UNIT, *LPUSB_MIME_UNIT;

    typedef struct tagUSB_DATA_BUFFER
    {
        char szName[MAX_FILE_PATH_LEN];  //[OUT]对应name字段
        void * pDataBuffer;         //[IN/OUT]数据缓冲区
        DWORD   dwDataSize;              //[IN/OUT]数据缓冲区大小/实际从设备接收到的数据的长度
        BYTE    byRes[12];               //保留
    }USB_DATA_BUFFER, *PUSB_DATA_BUFFER;

    typedef struct tagUSB_PT_PARAM
    {
        DWORD   dwSize;             //结构体大小
        void *  pRequestUrl;        //[IN]请求URL
        DWORD   dwRequestUrlLen;    //[IN]请求URL长度
        void *  pInBuffer;          //[IN]输入数据
        DWORD   dwInSize;           //[IN]输入数据长度
        void *  pOutBuffer;         //[IN/OUT]输出缓冲区
        DWORD   dwOutSize;          //[IN/OUT]输出缓冲区大小/实际从设备接收到的数据的长度
        DWORD   dwSendTimeOut;      //[IN]默认5000ms
        DWORD   dwRecvTimeOut;      //[IN]默认5000ms
        USB_DATA_BUFFER struData[MAX_DATA_NUM];
        BYTE    byNumOfMultiPart;   //[IN]0-无效，其他值表示报文分段个数，非零时pInBuffer传入的是USB_SDK_MIME_UNIT结构体数组的指针，该值即代表结构体个数
        BYTE    byNumOfData;        //[OUT]实际设备返回的DATA数据数量（如采集人脸数量）
        BYTE    byRes[62];          //保留
    }USB_PT_PARAM, *LPUSB_PT_PARAM;

    typedef struct tagUSB_CONTROL_INPUT_INFO
    {
        void * lpCondBuffer;     //输入参数缓冲区
        DWORD  dwCondBufferSize; //输入参数缓冲区大小
        void * lpInBuffer;        //输入缓冲区
        DWORD  dwInBufferSize;    //输入缓冲区大小
        BYTE   byRes[48];
    }USB_CONTROL_INPUT_INFO, *LPUSB_CONTROL_INPUT_INFO; //64字节

    typedef struct tagUSB_PREVIEW_PARAM
    {
        DWORD  dwSize;
        DWORD  dwStreamType;				//码流类型
        DWORD  dwChannel;
        HWND   hWindow;				       //窗口句柄
        BYTE   bUseAudio;				   //是否预览音频
        BYTE   bYUVCallback;			   //是否开启YUV回调
        BYTE   byRes[126];
    } USB_PREVIEW_PARAM, *LPUSB_PREVIEW_PARAM;

    typedef struct tagUSB_RECORD_PARAM
    {
        DWORD  dwSize;
        DWORD  dwRecordType;                // 录像类型
        BYTE   bRecordAudio;   // 是否录制音频
        BYTE   byRes1[3];
        char   szFilePath[MAX_FILE_PATH_LEN];        // 录像文件存储路径
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
        ORECT    struRect;             // 目标位置
        DWORD  dwImgHeight;          // 人脸图片高
        DWORD  dwImgWidth;           // 人脸图片宽
        LONG   nBufferLen;           // 人脸图片缓冲区大小
        BYTE *  pBuffer;             // 人脸图片缓冲区
        BYTE    byRes[128];
    } TARGET_INFO;

    typedef struct tagUSB_FACE_DRAW_PARAM
    {
        TARGET_INFO struTargetInfoList[50];
        DWORD    dwFaceTotalNum;             // 人脸总的个数                    
        BYTE    byEnlarge;                  // 是否启用人脸放大模式 0-不启用 1-启用
        BYTE    byShowFont;                 // 是否显示提示文字 0:显示 1:不显示
        BYTE    byDisappear;                // 人脸是否消失
        BYTE    byRes[125];
    }USB_FACE_DRAW_PARAM, *LPUSB_FACE_DRAW_PARAM;


    typedef struct tagUSB_IR_FRAME
    {
        DWORD                  nLen;               // 数据长度
        BYTE*       pBuffer;            // 数据缓存
        DWORD                  byRes[32];
    }USB_IR_FRAME, *LPUSB_IR_FRAME;


    /**	@struct 活体检测条件结构体
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
        float				fLiveConfidence;     //活体检测置信度
        char				reserved[16];         //预留16个字节                           
    }USB_FR_LIVE_INFO, *LPUSB_FR_LIVE_INFO;

    typedef struct tagFACE_ATTR_CLS
    {
        DWORD                       nValue;                           //类别
        float                      fConf;                            //置信度,范围0~1
    }USB_FACE_ATTR_CLS, *LPUSB_FACE_ATTR_CLS;

    typedef struct tagFACE_ATTR_OUT
    {
        USB_FACE_ATTR_CLS   stAge;                        // 年龄，0 ~ 99
        USB_FACE_ATTR_CLS   stGender;                     // 性别，0-女, 1-男
        USB_FACE_ATTR_CLS   stGlass;                      // 是否戴眼镜，0-无眼镜,1-普通眼镜,2-墨镜
        USB_FACE_ATTR_CLS   stExpress;                    // 表情，0-中性，1-高兴，2-惊讶，3-害怕，4-厌恶，5-难过，6-愤怒
        USB_FACE_ATTR_CLS   stMask;                       // 口罩，0-不戴口罩，1-戴口罩
        USB_FACE_ATTR_CLS   szReserved1;                  // 保留字节
        USB_FACE_ATTR_CLS   stHat;                        // 帽子，0-不戴帽子，1-戴帽子
        BYTE                szReserved[64];               // 保留字节
    }USB_FACE_ATTR_OUT, *LPUSB_FACE_ATTR_OUT;

    typedef struct tagUSB_TARGET_LIVE_INFO
    {
        USB_FR_LIVE_INFO       strLiveInfo;
        USB_FACE_ATTR_OUT      strFaceAttr;
    }USB_TARGET_LIVE_INFO, *LPUSB_TARGET_LIVE_INFO;

    typedef struct tagUSB_FR_LIVE_PARAM
    {
        DWORD                   LiveNum;                                // 实际的目标个数,大于0表示有活体
        USB_TARGET_LIVE_INFO          stTargetLiveOut[MAX_LIVE_TARGET_NUM];      // 活体输出
    }USB_FR_LIVE_PARAM, *LPUSB_FR_LIVE_PARAM;


    typedef struct tagUSB_FRAME_INFO
    {
        LONG       nStamp;       // 时标信息
        DWORD      dwStreamType; // 数据类型
        DWORD      dwWidth;      // 画面宽,如果是音频数据则为音频声道数
        DWORD      dwHeight;     // 画面高,如果是音频数据则为采样位数
        DWORD      dwFrameRate;  // 帧率,编码时产生的图像帧率，如果是音频数据则为采样率
        DWORD      dwFrameType;  // 视频帧类型,  对应转封装库输出的类型,如果是音频数据则为nAvgBytesPerSec
        DWORD      dwDataType;   // 数据类型,对应转封装库输出的数据类型  1-系统头数据 2-视频流数据 3-音频流数据
        LONG       nFrameNum;    // 帧号, 
        BYTE       *pBuf;        // 数据指针
        DWORD      dwBufSize;    // 数据长度
        BYTE       byRes[128];
    } USB_FRAME_INFO, *LPUSB_FRAME_INFO;


    typedef struct tagUSB_FACE_QUALITY
    {
        float               fEyeDistance;                   // 两眼间距,真实像素值
        float               fGrayMean;                      // 灰阶均值，范围0~255
        float               fGrayVariance;                  // 灰阶均方差，范围0~128
        float               fClearityScore;                 // 清晰度评分，范围0~1
        float               fPosePitch;                     // 平面外上下俯仰角，人脸朝上为正，范围-90~90
        float               fPoseYaw;                       // 平面外左右偏转角，人脸朝左为正，范围-90~90
        float               fPoseRoll;                      // 平面内旋转角，人脸顺时针旋转为正，范围-90~90
        float               fPoseConfidence;                // 姿态(pose_pitch、pose_yaw、pose_roll)置信度，范围0~1
        float               fFrontalScore;                  // 正面程度评分，范围0~1
        float               fVisibleScore;                  // 可见性评分（即不遮挡），范围0~1，0表示完全遮挡，1表示完全不遮挡
        float               fFaceScore;                     // 人脸评分，范围0~1
        BYTE           byRes[128];                     // 保留字节，后续扩展评分项
    }USB_FACE_QUALITY, *LPUSB_FACE_QUALITY;

    typedef struct tagUSB_SUBFACE_PIC
    {
        DWORD       dwWidth;             // 小图宽度
        DWORD       dwHeight;            // 小图高度
        BYTE*       pSubFacePic;         // 人脸小图
        DWORD       dwSubFacePicLen;     // 人脸小图大小
#if (defined(OS_WINDOWS64) || defined(OS_POSIX64))
        BYTE*       pSubFaceJpgPic;      // 人脸Jpg小图
#else
        BYTE*       pSubFaceJpgPic;      // 人脸Jpg小图
        BYTE        byRes1[4];           // 保留字节
#endif
        DWORD       dwSubFaceJpgPicLen;  // 人脸Jpg小图大小
        BYTE        byRes[4];            // 保留字节
    }USB_SUBFACE_PIC, *LPUSB_SUBFACE_PIC;

    typedef struct tagUSB_FACE_PARAM
    {
        USB_FACE_QUALITY   struFaceQualityList;
        USB_SUBFACE_PIC    struSubFacePic;
        BYTE          byRes[16];         // 保留字节
    }USB_FACE_PARAM, *LPUSB_FACE_PARAM;

    /**	@struct USB_CAMERA_MEDIA_DATA
    *  @brief   人脸媒体参数结构体*
    */
    typedef struct tagUSB_MEDIA_DATA
    {
        DWORD   dwWidth;             // 宽度
        DWORD   dwHeight;            // 高度
        DWORD   dwFrameRate;         // 帧率
        DWORD   dwTimeStamp;         // 时间戳
        DWORD   dwFrameNum;          // 帧号
        DWORD   dwLen;               // 背景图数据长度
        BYTE*   pBuffer;             // 背景图缓存
        INT64   dwSysTime;           // 系统时间戳
#if (defined(OS_WINDOWS64) || defined(OS_POSIX64))
        BYTE*   pJpgBuffer;          // 背景Jpg图缓存
#else
        BYTE*   pJpgBuffer;          // 背景Jpg图缓存
        BYTE    byRes1[4];           // 保留字节
#endif
        DWORD   dwJpgLen;            // 背景Jpg图数据长度
        BYTE    byRes[116];          // 保留字节
    }USB_MEDIA_DATA, *LPUSB_MEDIA_DATA;

    typedef struct tagUSB_FD_RESULT_PARAM
    {
        DWORD        dwFaceTotalNum;             // 人脸总的个数 
        USB_MEDIA_DATA    struMediaData;
        USB_FACE_PARAM    struFaceParam[64]; //单个人脸参数
        BYTE         byRes[32];
    }USB_FD_RESULT_PARAM, *LPUSB_FD_RESULT_PARAM;

    //外部事件回调
    typedef void(__stdcall *fnEventCallBack)(LONG lPort, LONG lEvent, LONG nParam1, LONG nParam2, void *pUser);
    //内部播放库YUV数据回调
    //typedef void(__stdcall *YUVDataCallBack)(LONG nPort, char *pBuf, LONG nSize, FRAME_INFO *pFrameInfo, void * nReserved1, void * nReserved2);
    //typedef void(__stdcall *DecCallBack)(LONG lPort, BYTE *pBuf, LONG nSize, FRAME_INFO *pFrameInfo, void* pUser);
    //外部码流回调
    typedef void(__stdcall *fnStreamCallBack)(LONG handle, USB_FRAME_INFO *pFrameInfo, void* pUser);
    //外部人脸检测结果回调
    //typedef void(__stdcall *FDResultCallBack)(LONG lPort, LPUSB_FACE_DRAW_PARAM struRes);
    //外部人脸检测结果回调
    typedef void(__stdcall *FDExtenResultCallBack)(long lPort, LPUSB_FD_RESULT_PARAM struFDResultInfo, void* pUser);

    typedef struct tagUSB_STREAM_CALLBACK_PARAM
    {
        DWORD  dwSize;
        DWORD  dwStreamType; //MJPEG/H264/YUV/PCM
        fnStreamCallBack funcStreamCallBack;
        void * pUser;
        BYTE   bUseAudio;  //是否回调音频
        BYTE  byRes[127];
    } USB_STREAM_CALLBACK_PARAM, *LPUSB_STREAM_CALLBACK_PARAM;

    //typedef struct tagUSB_FACE_DETECT_PARAM
    //{
    //    BYTE  byEnable;                 // 是否使能人脸检测   0-不使能   1-使能
    //    BYTE  byEnlarge;                // 是否启用人脸放大模式 0-不启用 1-启用
    //    BYTE  byModel;                  // 人脸检测模式 0:最大人脸 1:评分最高人脸 2:最靠近中心位置人脸 3:所有人脸
    //    BYTE  bySnapMode;               // 抓图模式  0:自动抓图 1:手动抓图
    //    BYTE  szFacePicPath[MAX_FILE_PATH_LEN];  // 人脸图片路径
    //    FDResultCallBack fnFaceDetectCB;    // 人脸检测数据回调
    //    BYTE  byShowFont;               // 是否显示提示文字 0:显示 1:不显示【不支持】
    //    BYTE  byRes[127];
    //}USB_FACE_DETECT_PARAM, *LPUSB_FACE_DETECT_PARAM;

    typedef struct tagUSB_FACE_DETECT_PARAM
    {
        FDExtenResultCallBack fnFDExtenResultCallBack;  // 人脸属性检测结果数据回调
        void*           pUser;
        BYTE  bySnapMode;               // 抓图模式  0:自动抓图 1:手动抓图     【预留，不支持】
        BYTE             byRes[503];
    }USB_FACE_DETECT_PARAM, *LPUSB_FACE_DETECT_PARAM;


    typedef struct tagUSB_CAPTURE_PARAM
    {
        DWORD  dwSize;        // sizeof(USB_CAMERA_CAPTURE_PARAM)
        DWORD  dwType;        // 抓图方式：0-内部写文件，1-返回图片数据
        BYTE   *pBuf;         // 数据缓冲区
        DWORD  dwBufSize;     // 数据缓冲区大小
        DWORD  dwDataLen;     // 数据缓冲区中有效数据长度(即图片大小)
        char   szFilePath[256]; //图片存储路径
        BYTE   byRes[32];
    } USB_CAPTURE_PARAM, *LPUSB_CAPTURE_PARAM;

    typedef struct tagUSB_BEEP_AND_FLICKER
    {
        DWORD     dwSize;   //结构体大小
        BYTE      byBeepType;// 蜂鸣类型 0无效，1连续，2慢鸣，3快鸣，4停止
        BYTE      byBeepCount;// 鸣叫次数, （只对慢鸣、快鸣有效，且不能为0）
        BYTE      byFlickerType;// 闪烁类型 0无效，1连续，2错误，3正确，4停止
        BYTE      byFlickerCount;// 闪烁次数（只对错误、正确有效，且不能为0）
        BYTE      byRes[24];
    } USB_BEEP_AND_FLICKER, *LPUSB_BEEP_AND_FLICKER; //32字节

    typedef struct tagUSB_CARD_ISSUE_VERSION
    {
        DWORD     dwSize;   //结构体大小
        char      szDeviceName[MAX_DEVICE_NAME_LEN /*32*/]; //设备名称
        char      szSerialNumber[MAX_SERIAL_NUMBER_LEN /*48*/]; //设备序列号
        DWORD     dwSoftwareVersion; //软件版本号,//软件版本号，格式为：24-32位为主版本号，16-24位为次版本号；0-16位为最小版本号；
        WORD      wYear;
        BYTE      byMonth;
        BYTE      byDay;
        BYTE      byLanguage; //0-中文，1-英文
        BYTE      byRes[35];
    } USB_CARD_ISSUE_VERSION, *LPUSB_CARD_ISSUE_VERSION; //128字节

    typedef struct tagUSB_CARD_PROTO
    {
        DWORD   dwSize;   //结构体大小
        BYTE    byProto; //卡协议类型（0-TypeA,1-TypeB,2-typeAB,3-125Khz,255所有）
        BYTE    byRes[27];
    } USB_CARD_PROTO, *LPUSB_CARD_PROTO; //32字节

    typedef struct tagUSB_WAIT_SECOND
    {
        DWORD   dwSize;   //结构体大小
        BYTE    byWait; // 1Byte操作等待时间（0-一直执行直到有卡响应，其他对应1S单位）
        BYTE    byRes[27];
    } USB_WAIT_SECOND, *LPUSB_WAIT_SECOND; //32字节

    typedef struct tagUSB_ACTIVATE_CARD_RES
    {
        DWORD  dwSize;
        BYTE   byCardType;// 卡类型（0-TypeA m1卡，1-TypeA cpu卡,2-TypeB,3-125kHz Id卡,4-Felica Card 5-Desfire Card）
        BYTE   bySerialLen; //卡物理序列号字节长度
        BYTE   bySerial[10];//卡物理序列号
        BYTE   bySelectVerifyLen; //选择确认长度
        BYTE   bySelectVerify[3]; //选择确认(3字节)
        BYTE   byRes[12];
    } USB_ACTIVATE_CARD_RES, *LPUSB_ACTIVATE_CARD_RES; //32字节

    typedef struct tagUSB_M1_PWD_VERIFY_INFO
    {
        DWORD    dwSize;   //结构体大小
        BYTE     byPasswordType; // 密码类别（0-KeyA, 1-KeyB）
        BYTE     bySectionNum; // 要验证密码的扇区号
        BYTE     byRes1[2];  //保留字节
        BYTE     byPassword[6]; // 6Byte密码
        BYTE     byRes[18]; //保留字节
    } USB_M1_PWD_VERIFY_INFO, *LPUSB_M1_PWD_VERIFY_INFO; //32字节

    typedef struct tagUSB_M1_BLOCK_ADDR
    {
        DWORD    dwSize;
        WORD     wAddr; // 2Byte块地址
        BYTE     byRes[26];
    } USB_M1_BLOCK_ADDR, *LPUSB_USB_M1_BLOCK_ADDR; //32字节

    typedef struct tagUSB_M1_BLOCK_DATA
    {
        DWORD   dwSize;   //结构体大小
        BYTE    byData[16];// 16Byte块数据
        BYTE    byRes[12];
    } USB_M1_BLOCK_DATA, *LPUSB_M1_BLOCK_DATA; //32字节

    typedef struct tagUSB_M1_BLOCK_WRITE_DATA
    {
        DWORD    dwSize;   //结构体大小
        WORD    wAddr;    // 2Byte块地址
        BYTE     byDataLen; // 数据长度(0-16)
        BYTE     byRes1;    //保留字节
        BYTE     byData[16]; //16Byte BUFF(要写的块数据)
        BYTE     byRes[8];  //保留字节
    } USB_M1_BLOCK_WRITE_DATA, *LPUSB_M1_BLOCK_WRITE_DATA; //32字节

    typedef struct tagUSB_M1_MODIFY_SCB
    {
        DWORD    dwSize;   //结构体大小
        BYTE     bySectionNum;  //1Byte扇区号
        BYTE     byPasswordA[6];// 6Byte 密码A
        BYTE     byRes1;    //保留字节
        BYTE     byCtrlBits[4];   // 4Byte控制位
        BYTE     byPasswordB[6];// 6Byte 密码B
        BYTE     byRes[10]; //保留字节
    } USB_M1_MODIFY_SCB, *LPUSB_M1_MODIFY_SCB; //32字节

    typedef struct tagUSB_M1_BLOCK_OPER
    {
        DWORD    dwSize;   //结构体大小
        WORD     wAddr;    // 2Byte块地址
        WORD     wValue;    // 2Byte要增加的值
        BYTE     byRes[24];
    } USB_M1_BLOCK_OPER, *LPUSB_M1_BLOCK_OPER; //32字节

    typedef struct tagUSB_M1_BLOCK_OPER_RES
    {
        DWORD    dwSize;
        WORD     wSuccessNum;// 2Byte 实际成功次数
        BYTE     byRes[26];
    } USB_M1_BLOCK_OPER_RES, *LPUSB_M1_BLOCK_OPER_RES; //32字节

    typedef struct tagUSB_M1_MF_PACK
    {
        DWORD    dwSize;
        BYTE     byBufLen; //数据长度（0-255）
        BYTE     byRes1[3]; //保留字节
        BYTE     byBuf[255];//数据
        BYTE     byRes2; //保留字节
        BYTE     byDelay; //延迟时间（单位10ms）,0为默认值（2000ms）(由于SDK默认超时时间5秒，这个时间应不超过5秒)
        BYTE     byRes[55];
    } USB_M1_MF_PACK, *LPUSB_M1_MF_PACK; //320字节

    typedef struct tagUSB_SDK_M1_SECTION_ENCRYPT
    {
        DWORD   dwSize;              //结构体大小
        BYTE    bySectionID;         //扇区ID
        BYTE    byKeyType;           //验证密钥类型，0-海康密钥，1-其它正常密钥
        BYTE    byKeyAContent[6];    //验证密钥具体参数，验证密钥类型为1时有效
        BYTE    byNewKeyType;        //新密钥类型，0-海康密钥，1-其它正常密钥
        BYTE    byRes1;              //保留字节
        BYTE    byNewKeyAContent[6]; //新密钥A具体参数，新密钥类型为1时有效
        BYTE    byCtrlBits[4];       //控制位，新密钥类型为1时有效
        BYTE    byNewKeyBContent[6]; //新密钥B具体参数，新密钥类型为1时有效
        BYTE    byRes[34];
    } USB_SDK_M1_SECTION_ENCRYPT, *LPUSB_SDK_M1_SECTION_ENCRYPT; //64字节

    typedef struct tagUSB_SDK_M1_SECTION_ENCRYPT_RES
    {
        DWORD   dwSize;      //结构体大小
        BYTE    byStatus;    //成功返回0，失败时返回1-代表验证密钥失败，2-设置新密钥失败
        BYTE    byRes[27];
    } USB_SDK_M1_SECTION_ENCRYPT_RES, *LPUSB_SDK_M1_SECTION_ENCRYPT_RES; //32字节

    typedef struct tagUSB_PSAM_SEAT_INFO
    {
        DWORD   dwSize;
        BYTE    bySeat;// 1Byte PSAM卡座序号（0- 卡座1，1-卡座2）
        BYTE    byRes[27];
    } USB_PSAM_SEAT_INFO, *LPUSB_PSAM_SEAT_INFO; //32字节

    typedef struct tagUSB_CARD_PARAM
    {
        DWORD   dwSize;
        BYTE    byCardType; // 1Byte卡类型(0-13.56射频CPU卡，1-PSAM卡座1,2-PSAM卡座2)
        BYTE    byCardProto; // 1Byte卡协议类型（0为T=0，1为T=1）
        BYTE    byRes[26];
    } USB_CARD_PARAM, *LPUSB_CARD_PARAM; //32字节

    typedef struct tagUSB_CPU_CARD_RESET_RES
    {
        DWORD    dwSize;
        BYTE     byBufLen;//byBuf中有效数据长度（0-60）
        BYTE     byRes1[3]; //保留字节
        BYTE     byBuf[60];//（一般是厂商信息）
        BYTE     byRes[28]; //保留字节
    } USB_CPU_CARD_RESET_RES, *LPUSB_CPU_CARD_RESET_RES; //96字节

    typedef struct tagUSB_CPU_CARD_PACK
    {
        DWORD    dwSize;
        BYTE     byBufLen; //0-255
        BYTE     byRes1[3]; //保留字节
        BYTE     byBuf[255];
        BYTE     byDelay; //延迟时间（单位10ms），0为默认（200ms）
        BYTE     byRes[56]; //保留字节
    } USB_CPU_CARD_PACK, *LPUSB_CPU_CARD_PACK; //320字节

    typedef struct tagUSB_CERTIFICATE_INFO
    {
        DWORD  dwSize; //结构体大小
        WORD   wWordInfoSize; //文字信息长度
        WORD   wPicInfoSize; //相片信息长度
        WORD   wFingerPrintInfoSize; //指纹信息长度
        BYTE   byCertificateType; //证件类型：0-身份证，1-中国绿卡，2-港澳台居民身份证，3-中国绿卡（新）
        BYTE   byRes2;
        BYTE   byWordInfo[WORD_LEN/*256*/]; //文字信息
        BYTE   byPicInfo[PIC_LEN/*1024*/]; //相片信息
        BYTE   byFingerPrintInfo[FINGER_PRINT_LEN/*1024*/]; //指纹信息
        BYTE   byRes[40];
    } USB_CERTIFICATE_INFO, *LPUSB_CERTIFICATE_INFO;

    typedef struct tagUSB_IDENTITY_INFO_CFG
    {
        DWORD  dwSize; //结构体大小
        WORD   wPicInfoSize; //相片信息长度
        WORD   wFingerPrintInfoSize; //指纹信息长度
        BYTE    byPicInfo[PIC_LEN/*1024*/]; //身份证图片信息
        BYTE    byFingerPrintInfo[FINGER_PRINT_LEN/*1024*/]; //指纹信息
        BYTE    byRes[256];
    } USB_IDENTITY_INFO_CFG, *LPUSB_IDENTITY_INFO_CFG;

    typedef struct tagUSB_CERTIFICATE_ADD_ADDR_INFO
    {
        DWORD  dwSize; //结构体大小
        WORD   wAddrInfoSize; //追加住址信息长度
        BYTE   byAddAddrInfo[ADDR_LEN/*128*/]; //追加住址信息
        BYTE   byRes[40];
    } USB_CERTIFICATE_ADD_ADDR_INFO, *LPUSB_CERTIFICATE_ADD_ADDR_INFO;

    typedef struct tagUSB_EXTERNAL_DEV_INFO
    {
        DWORD  dwSize;   //结构体大小
        char      szFPModuleSoftVersion[FINGER_PRINT_MODULE_VERSION_LEN/*32*/]; //指纹模组软件版本长度
        char      szFPModuleSerialNumber[FINGER_PRINT_MODULE_SERIAL_LEN/*64*/]; //指纹模组序列号长度
        char      szSecurityModuleSerialNumber[SECURITY_MODULE_SERIAL_LEN/*16*/]; //安全模块序列号长度
        BYTE     byRes[140];
    } USB_EXTERNAL_DEV_INFO, *LPUSB_EXTERNAL_DEV_INFO; //256字节

    typedef struct tagUSB_FINGER_PRINT_OPER_PARAM
    {
        DWORD  dwSize;   //结构体大小
        BYTE    byFPCompareType; //指纹比对模式：0-不比对（默认），1-设备内部比对（默认），2-平台（客户端）比对
        BYTE    byFPCaptureType; //指纹采集类型：1-模板（默认），2-图片（byFPCompareType为2时有效）
        BYTE    byFPCompareTimeout; //设备内部指纹比对超时时间：1-255s（默认5s）（byFPCompareType为1时有效）
        BYTE    byFPCompareMatchLevel; //设备内部指纹比对匹配等级：1-5（默认3）（byFPCompareType为1时有效）
        BYTE    byRes[24];
    } USB_FINGER_PRINT_OPER_PARAM, *LPUSB_FINGER_PRINT_OPER_PARAM; //32字节

    typedef struct tagUSB_FINGER_PRINT_COND
    {
        DWORD  dwSize;   //结构体大小
        BYTE    byWait; //操作等待时间（范围10s-60s，不设置时默认为60s）
        BYTE    byFPType; //指纹类型：1-模板，2-图片
        BYTE    byRes[26];
    } USB_FINGER_PRINT_COND, *LPUSB_FINGER_PRINT_COND; //32字节

    typedef struct tagUSB_FINGER_PRINT
    {
        DWORD  dwSize; //结构体大小
        DWORD  dwFPBufferSize; //指纹缓存大小
        char*  pFPBuffer; //指纹缓存
        DWORD  dwFPSize; //指纹大小
        BYTE    byFPType; //指纹类型：1-模板，2-图片（90k左右）
        BYTE    byResult; //采集结果：1-采集成功，2-采集失败，3-采集超时，4-指纹图像质量差
        BYTE    byFPTemplateQuality; //指纹模板质量：0-100（byFPType为1-模板时有效）
        BYTE    byRes[13];
    } USB_FINGER_PRINT, *LPUSB_FINGER_PRINT; //32字节

    typedef struct tagUSB_FINGER_PRINT_CONTRAST_RESULT
    {
        DWORD  dwSize;   //结构体大小
        BYTE    byResult; //比对结果：1-比对成功，2-比对失败，3-比对超时，4-指纹图像质量差，5-两个指纹特征之间的1:1比对失败，6-清空指纹特征缓冲区失败，7-生成指纹特征失败
        BYTE    byFPTemplateQuality; //指纹模板质量：0-100
        BYTE    byRes[26];
    } USB_FINGER_PRINT_CONTRAST_RESULT, *LPUSB_FINGER_PRINT_CONTRAST_RESULT; //32字节

    typedef struct tagUSB_CERTIFICATE_MAC
    {
        DWORD  dwSize; //结构体大小
        BYTE   byMac[MAC_LEN/*16*/]; //物理序列号
        BYTE   byRes[40];
    } USB_CERTIFICATE_MAC, *LPUSB_CERTIFICATE_MAC;

    typedef struct tagUSB_IC_CARD_NO
    {
        DWORD  dwSize; //结构体大小
        BYTE    byCardNo[CARD_NO_LEN/*32*/]; //IC卡卡号
        BYTE    byRes[40];
    } USB_IC_CARD_NO, *LPUSB_IC_CARD_NO;

    typedef struct tagUSB_DETECT_CARD_COND
    {
        DWORD  dwSize;   //结构体大小
        BYTE    byWait; // 1BYTE操作等待时间（0-一直执行直到有卡响应，其他对应1S单位）
        BYTE    byRes[27];
    } USB_DETECT_CARD_COND, *LPUSB_DETECT_CARD_COND; //32字节

    typedef struct tagUSB_DETECT_CARD_CFG
    {
        DWORD  dwSize; //结构体大小
        BYTE    byCardStatus; //卡片状态：0-未检测到，1-检测到
        BYTE    byRes[27];
    } USB_DETECT_CARD_CFG, *LPUSB_DETECT_CARD_CFG; //32字节

    typedef struct tagUSB_CPU_CARD_ENCRYPT
    {
        DWORD  dwSize;    //结构体大小
        BYTE    byCardType;    //卡类型：0-无效，1-白卡（密钥为8字节0xFF），2-海康CPU卡，3-其它已加密卡片
        BYTE    byKeyLength;    //MF外部认证用秘钥长度（byCardType为3-其它已加密卡片时，该字段有效）
        BYTE    byRes2[2];
        BYTE    byKeyContent[16];    //MF外部认证用秘钥内容（byCardType为3-其它已加密卡片时，该字段有效）
        BYTE    byRes[40];
    } USB_CPU_CARD_ENCRYPT, *LPUSB_CPU_CARD_ENCRYPT; //64字节

    typedef struct tagUSB_CPU_CARD_ENCRYPT_RES
    {
        DWORD  dwSize;    //结构体大小
        BYTE    byTryTimes;    //剩余可尝试次数（255代表无效）：配置成功时，返回255；配置失败时，返回具体的剩余可尝试次数
        BYTE    byRes[27];
    } USB_CPU_CARD_ENCRYPT_RES, *LPUSB_CPU_CARD_ENCRYPT_RES; //32字节

    typedef struct tagUSB_M1_SECTION_ENCRYPT
    {
        DWORD   dwSize;              //结构体大小
        BYTE    bySectionID;         //扇区ID
        BYTE    byKeyType;           //验证密钥类型，0-海康密钥，1-其它正常密钥
        BYTE    byKeyAContent[6];    //验证密钥具体参数，验证密钥类型为1时有效
        BYTE    byNewKeyType;        //新密钥类型，0-海康密钥，1-其它正常密钥
        BYTE    byRes1;              //保留字节
        BYTE    byNewKeyAContent[6]; //新密钥A具体参数，新密钥类型为1时有效
        BYTE    byCtrlBits[4];       //控制位，新密钥类型为1时有效
        BYTE    byNewKeyBContent[6]; //新密钥B具体参数，新密钥类型为1时有效
        BYTE    byRes[34];
    } USB_M1_SECTION_ENCRYPT, *LPUSB_M1_SECTION_ENCRYPT; //64字节

    typedef struct tagUSB_M1_SECTION_ENCRYPT_RES
    {
        LONG    dwSize;      //结构体大小
        BYTE    byStatus;    //成功返回0，失败时返回1-代表验证密钥失败，2-设置新密钥失败
        BYTE    byRes[27];
    } USB_M1_SECTION_ENCRYPT_RES, *LPUSB_M1_SECTION_ENCRYPT_RES; //32字节

    typedef struct tagUSB_ACTIVE_STATUS
    {
        DWORD  dwSize;
        BYTE   byState; //0-已激活 1-未激活
        BYTE   byRes[7];
    } USB_ACTIVE_STATUS, *LPUSB_ACTIVE_STATUS; //12字节


    /**@struct USB_CONFIG
    *  @brief  相机视频能力参数结构体
    *
    *
    */
    typedef struct tagUSB_VIDEO_CAPACITY
    {
        char         nIndex;
        char         nType;					 // 码流类型（USBCamera_H264、USBCamera_MJPEG、USBCamera_RGB24等）
        int          dwWidth;				 // 图像宽度
        int          dwHeight;				 // 图像高度
        long         lListSize;				 // 支持的帧率的个数
        INT64        lFrameRates[50];		 // 支持的帧率(50足够大)
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
        DWORD dwVideoFormat; //视频码流格式
        DWORD dwWidth;//分辨率宽
        DWORD dwHeight;//分辨率高
        DWORD dwFramerate;//帧率
        DWORD dwBitrate;//比特率
        DWORD dwParamType; //图像参数类型
        DWORD dwValue; //图像参数值
        BYTE byRes[128];//保留字节
    } USB_VIDEO_PARAM, *LPUSB_VIDEO_PARAM;

	typedef struct tagUSB_PROPERTY
	{
        long dwMin;						//最小值
        long dwMax;						//最大值
        long dwStep;					//步长
        long dwDef;						//默认值
		BYTE byEnabled;					//是否支持，0-不支持，1-支持，2-手动，3-自动
        BYTE byRes[7];
	} USB_PROPERTY, *LPUSB_PROPERTY;

	typedef struct tagUSB_VIDEO_PROPERTY_CAP
	{
		USB_PROPERTY struBrightness;			//亮度
		USB_PROPERTY struContrast;				//对比度
		USB_PROPERTY struHue;					//色调
		USB_PROPERTY struSaturation;			//饱和度
		USB_PROPERTY struSharpness;				//清晰度
		USB_PROPERTY struGamma;					//伽玛
		USB_PROPERTY struColorEnable;			//启用颜色
		USB_PROPERTY struWhiteBalance;			//白平衡
		USB_PROPERTY struBacklightCompensation;	//逆光对比
		USB_PROPERTY struGain;					//增益
		USB_PROPERTY struPowerlineFrequency;	//电力线频率
		USB_PROPERTY struPan;					//全景
		USB_PROPERTY struTilt;					//倾斜
		USB_PROPERTY struRoll;					//滚动
		USB_PROPERTY struZoom;					//缩放
		USB_PROPERTY struExposure;				//曝光
		USB_PROPERTY struIris;					//光圈
		USB_PROPERTY struFocus;					//焦点
		USB_PROPERTY struLowBrightnessCompensation;//低亮度补偿
		BYTE		 byRes[128];				//保留字节
	} USB_VIDEO_PROPERTY_CAP, *LPUSB_VIDEO_PROPERTY_CAP;

    typedef struct tagUSB_VIDEO_PROPERTY
    {
        long dwValue;
        BYTE byFlag;        //SET：表示设置模式，1-自动，2-手动
                            //GET：返回设备能力，1-支持自动和手动，2-只支持手动
        BYTE byRes[31];
    } USB_VIDEO_PROPERTY, *LPUSB_VIDEO_PROPERTY;

    typedef struct tagUSB_SRC_STREAM_CFG
    {
        DWORD  dwStreamType;	// 原始码流类型(MJPEG/H264/YUV)
        BYTE   bUseAudio;      // 是否使用音频 0-不使用，1-使用
        BYTE   byRes[4];
    }USB_SRC_STREAM_CFG, *LPUSB_SRC_STREAM_CFG;

    /**	@struct USB_EVENT_CALLBACK_PARAM
    *  @brief   事件回调参数结构体
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
        LONG   dwType;  // -1(不旋转)  0(向左旋转90度)  1(向右旋转90度)  2(旋转180度)
        BYTE   byRes[124];
    }USB_ROTATE_ANGLE_INFO, *LPUSB_ROTATE_ANGLE_INFO;

    typedef struct tagUSB_COMMAND_STATE
    {
        DWORD  dwSize;
        BYTE   byState; // 参见配置错误状态码
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
    } USB_COMMAND_STATE, *LPUSB_COMMAND_STATE; //8字节

	typedef struct tagUSB_GET_DEVICE_COUNT_INFO
	{
		BYTE   bySeparate;		// 0-不分离，1-音视频分离
		BYTE   byIncludeAll;	// 0-枚举HIK，1-枚举包括第三方
	}USB_GET_DEVICE_COUNT_INFO, *LPUSB_GET_DEVICE_COUNT_INFO;

    //设备SVC能力
    typedef struct tagUSB_SYSTEM_DEVICE_CAPABILITIES
    {
        BYTE    byIsSupportSVC;     //是否支持SVC：0-不支持，1-支持
        BYTE    byRes[31];
    }USB_SYSTEM_DEVICE_CAPABILITIES, *LPUSB_SYSTEM_DEVICE_CAPABILITIES;

    //SVC多码流信息
    typedef struct tagUSB_IMAGE_VIDEO_SVC_MULTIPLE_STREAM
    {
        BYTE    byMultipleStreamNum;//SVC多码流支持路数
        BYTE    byRes[31];
    }USB_IMAGE_VIDEO_SVC_MULTIPLE_STREAM, *LPUSB_IMAGE_VIDEO_SVC_MULTIPLE_STREAM;

    //智能功能开关
    typedef struct tagUSB_VCA_SWITCH
    {
        BYTE    byChannelID;        //视频通道号
        BYTE    byDetectEnabled;    //是否开启目标检测，0-关闭，1-开启
        BYTE    byIdentifyEnabled;  //是否开启目标识别，0-关闭，1-开启
        BYTE    byRes[29];
    } USB_VCA_SWITCH, *LPUSB_VCA_SWITCH;

    //智能抓图
    typedef struct tagUSB_VCA_SNAPSHOT
    {
        BYTE    byChannelID;        //视频通道号
        BYTE    bySnapshotMode;     //抓图模式，1-检测后抓图，2-识别后抓图，3-建模抓图，4-抓去原始图片
        BYTE    byCaptureInterval;  //抓图时间间隔
        BYTE    byRes[32];
    } USB_VCA_SNAPSHOT, *LPUSB_VCA_SNAPSHOT;

    //智能目标识别相似度阈值
    typedef struct tagUSB_VCA_FACE_THRESHOLD
    {
        BYTE    byChannelID;        //视频通道号
        BYTE    byThresholdValue;   //相似度阈值
        BYTE    byRes[30];
    } USB_VCA_FACE_THRESHOLD, *LPUSB_VCA_FACE_THRESHOLD;

    //智能识别人脸属性
    typedef struct tagUSB_VCA_FACE_ATTRIBUTES
    {
        BYTE    byChannelID;        //视频通道号
        BYTE    byEnabled;          //属性开关，0-关闭，1-开启
        BYTE    byFaceExpression;   //表情，1-愤怒，2-轻蔑，3-高兴，4-害怕，5-惊讶，6-难过，7-未知
        BYTE    byAge;              //年龄
        BYTE    byGender;           //性别，1-男，2-女，3-未知
        BYTE    byGlass;            //眼镜，0-未戴眼镜，1-戴眼镜
        BYTE    byRes[30];
    } USB_VCA_FACE_ATTRIBUTES, *LPUSB_VCA_FACE_ATTRIBUTES;

    //智能人脸检测规则
    typedef struct tagUSB_VCA_FACE_DETECT_RULE
    {
        BYTE    byChannelID;        //视频通道
        BYTE    bySensitivity;      //检测灵敏度
        BYTE    byObjGenerateRate;  //目标生产速度
        BYTE    byRes1;
        DWORD   dwRegionX;          //区域左上顶点X坐标，归一化值，范围0 - 1000
        DWORD   dwRegionY;          //区域左上顶点Y坐标，归一化值，范围0 - 1000
        DWORD   dwRegionWidth;      //区域宽度，归一化值，范围0 - 1000
        DWORD   dwRegionHeight;     //区域高度，归一化值，范围0 - 1000
        BYTE    byRes[32];
    } USB_VCA_FACE_DETECT_RULE, *LPUSB_VCA_FACE_DETECT_RULE;

    //智能人脸检测质量评估
    typedef struct tagUSB_VCA_FACE_QUALITY
    {
        BYTE    byChannelID;        //视频通道
        BYTE    byLeftAngle;        //人脸向右边转的角度[0, 90]
        BYTE    byRightAngle;       //人脸向左边转的角度[0, 90]
        BYTE    byUpAngle;          //人脸向上的角度[0, 90]
        BYTE    byDownAngle;        //人脸向下的角度[0, 90]
        BYTE    byPupilDistance;    //瞳距
        BYTE    byScore;            //评分数值[20, 100]
        BYTE    byShelterType;      //遮挡类型：1-无遮挡，2-瞬时轻度，3-固定轻度，4-严重
        BYTE    byRes[32];
    } USB_VCA_FACE_QUALITY, *LPUSB_VCA_FACE_QUALITY;

    //图片下载建模
    typedef struct tagUSB_VCA_PIC_DOWNLOAD
    {
        BYTE    byId;               //图片序号
        BYTE    byType;             //图片类型：1-JPEG，2-PNG，3-BMP
        BYTE    byPicWidth;         //图片宽，赋值0表示自适应
        BYTE    byPicHeight;        //图片高，赋值0表示自适应
        BYTE    byPicSize;          //图片大小
        BYTE    byName[16];         //图片对应人名
        BYTE    byPost[16];         //图片对应人员职位
        BYTE    byRes[32];
    } USB_VCA_PIC_DOWNLOAD, *LPUSB_VCA_PIC_DOWNLOAD;

    //人脸底库数据配置
    typedef struct tagUSB_VCA_FACE_BASE_DATA_CFG
    {
        BYTE    byId;               //图片序号
        BYTE    byOperateType;      //操作类型：1-获取，2-删除，3-修改
        BYTE    byRes1[2];
        BYTE    byName[16];         //图片对应人名
        BYTE    byPost[16];         //图片对应人员职位
        BYTE    byRes[32];
    } USB_VCA_FACE_BASE_DATA_CFG, *LPUSB_VCA_FACE_BASE_DATA_CFG;

    //电子铭牌配置
    typedef struct tagUSB_VCA_ELECTRONICSIGNAGE_CFG
    {
        BYTE    byChannelID;        //视频通道
        BYTE    byEnabled;          //电子铭牌是否开启：0-关闭，1-开启
        BYTE    byFontColor;        //颜色
        BYTE    byFontType;         //字体：1-宋体，2-黑体
        BYTE    byRes[32];
    } USB_VCA_ELECTRONICSIGNAGE_CFG, *LPUSB_VCA_ELECTRONICSIGNAGE_CFG;

    //人脸信息
    typedef struct tagUSB_VCA_FACE_INFO
    {
        DWORD   dwRegionX;          //区域左上顶点X坐标，归一化值，范围0 - 1000
        DWORD   dwRegionY;          //区域左上顶点Y坐标，归一化值，范围0 - 1000
        DWORD   dwRegionWidth;      //区域宽度，归一化值，范围0 - 1000
        DWORD   dwRegionHeight;     //区域高度，归一化值，范围0 - 1000
    } USB_VCA_FACE_INFO, *LPUSB_VCA_FACE_INFO;

    //智能人脸检测信息
    typedef struct tagUSB_VCA_FACE_DETECT
    {
        BYTE    byChannelID;        //视频通道
        BYTE    byDetFaceNum;       //当前图像中检测到的人脸数目
        BYTE    byRes1[2];
        USB_VCA_FACE_INFO struFaceInfo[16];
        BYTE    byRes[32];
    } USB_VCA_FACE_DETECT, *LPUSB_VCA_FACE_DETECT;

    //人脸比对信息
    typedef struct tagUSB_VCA_FACE_CONTRAST
    {
        BYTE    byChannelID;        //视频通道
        BYTE    byId;               //当前结果序号
        BYTE    byFPID;             //当前人脸在底库中的序号
        BYTE    byRes1;
        BYTE    byName[16];         //识别出人脸的人名
        BYTE    byPost[16];         //识别出人脸的职位
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
		BYTE         byEnabled; //OSD是否开启：0-关闭，1-开启
		USB_OSD_INFO struOsdInfo;
		USB_OSD_LINE struOsdLineList[32];
        BYTE         byRes[1024];
	}USB_OSD, *LPUSB_OSD;

	typedef enum tagUSB_LOCAL_CFG_TYPE
	{
        ENUM_LOCAL_CFG_TYPE_LOAD_PATH = 0, //(USB_Init前调用)加载动态库路径配置，对应结构体USB_LOCAL_LOAD_PATH
        ENUM_LOCAL_CFG_TYPE_GUID, //(USB_Init后调用)设置GUID配置，对应结构体USB_LOCAL_GUID  结构体在设置扩展ID的需求中定义
        ENUM_LOCAL_CFG_TYPE_FONT_PATH,   //设置字体文件路径，只支持Linux
        ENUM_LOCAL_CFG_TYPE_FACE_DETECT //(USB_Init前调用)创建人脸检测资源（Linux下使用,win和android不支持）
	}USB_LOCAL_CFG_TYPE;

	//设置动态库路径需要加文件名 
	typedef enum tagUSB_DLL_TYPE
	{
        ENUM_DLL_SSL_PATH = 1, //设置OpenSSL的ssleay32.dll/libssl.so/libssl.dylib所在路径
        ENUM_DLL_CRYPTO_PATH = 2, //设置OpenSSL的libeay32.dll/libcrypto.so/libcrypto.dylib所在路径
        ENUM_DLL_SYSTEMTRANSFORM_PATH = 3, //设置转封装库路径
        ENUM_DLL_LIBUSB_PATH = 4, //设置LIBUSB库路径
        ENUM_DLL_PLAYCTRL_PATH = 5, //设置播放库路径
        ENUM_DLL_FORMATCONVERSION_PATH = 6, //设置转码库路径
        ENUM_DLL_LIBUVC_PATH = 8
	} USB_DLL_TYPE;

	typedef struct tagUSB_LOCAL_LOAD_PATH
	{
        USB_DLL_TYPE emType; //加载库的类型
        BYTE         byLoadPath[MAX_FILE_PATH_LEN];
		BYTE         byRes[128]; //保留字节
	}USB_LOCAL_LOAD_PATH, *LPUSB_LOCAL_LOAD_PATH;

    typedef struct _USB_GUID {
        ULONG    ulData1;
        WORD     wData2;
        WORD     wData3;
        BYTE     byData4[8];
    }USB_GUID, *LPUSB_GUID;

	typedef struct tagUSB_LOCAL_GUID
	{
        ULONG    ulVID; //供应商ID
        ULONG    ulPID;//产品识别码
        USB_GUID struGuid; //GUID
		BYTE     byRes[128];                //保留字节
	}USB_LOCAL_GUID, *LPUSB_LOCAL_GUID;

    typedef struct tagUSB_LOCAL_FONT_PATH
    {
        BYTE    byLoadPath[MAX_FILE_PATH_LEN];
        BYTE    byRes[128]; //保留字节
    }USB_LOCAL_FONT_PATH, *LPUSB_LOCAL_FONT_PATH;

    typedef struct tagUSB_DEVICE_VERSION
    {
        DWORD   dwSize;   //结构体大小
        BYTE    byDeviceName[MAX_DEVICE_NAME_LEN/*32*/]; //设备名称
        BYTE    bySerialNumber[MAX_SERIAL_NUMBER_LEN/*48*/]; //设备序列号
        BYTE    bySoftwareVersion[MAX_DEVICE_NAME_LEN]; //设备版本
        BYTE    byRes[44];
    } USB_DEVICE_VERSION, *LPUSB_DEVICE_VERSION;  //160字节

    typedef struct tagUSB_FILE_TRANSFER_INFO
    {
        DWORD  dwSize; //结构体大小
        BYTE   byLocalFileName[MAX_FILE_PATH_LEN]; //文件路径 + 文件名称    要上传的本地文件
        BYTE   byRemoteFileName[MAX_FILE_PATH_LEN]; //文件路径 + 文件名称   上传到设备哪个路径下
        BYTE   byRes[1024];
    } USB_FILE_TRANSFER_INFO, *LPUSB_FILE_TRANSFER_INFO;

    typedef struct tagUSB_FILE_TRANSFER_PROGRESS_INFO
    {
        DWORD  dwSize; //结构体大小
        BYTE   byState; //状态值见枚举USB_FILE_TRANSFER_STATE
        BYTE   byProgress;
        BYTE   byRes[1024];
    } USB_FILE_TRANSFER_PROGRESS_INFO, *LPUSB_FILE_TRANSFER_PROGRESS_INFO;

    typedef enum tagUSB_FILE_TRANSFER_STATE
    {
        USB_FILE_TRANSFERING = 0,  //-文件传输中
        USB_FILE_TRANSFER_FAIL,    //-文件传输失败
        USB_FILE_TRANSFER_SUCC,    //-文件传输成功
    }USB_FILE_TRANSFER_STATE;

    //标准控制命令数据结构体
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
        DWORD  dwSize; //结构体大小
        BYTE   bySupportSoftwareVersion; //是否支持 软件版本号：0-不支持，1-支持
        BYTE   bySupportPNSwitch;        //是否支持 PN制切换：0-不支持，1-支持
        BYTE   bySupportImageMode;       //是否支持 图像模式：0-不支持，1-支持
        BYTE   bySupportImageFlip;       //是否支持 镜像：0-不支持，1-支持
        BYTE   bySupportWDR;             //是否支持 宽动态：0-不支持，1-支持
        BYTE   bySupportNoiseReduce;     //是否支持 降噪：0-不支持，1-支持
        BYTE   bySupportWhiteBalance;    //是否支持 白平衡：0-不支持，1-支持
        BYTE   bySupportGamut;           //是否支持 色域：0-不支持，1-支持
        BYTE   bySupportShutter;         //是否支持 快门：0-不支持，1-支持
        BYTE   bySupportBeauty;          //是否支持 美颜：0-不支持，1-支持
        BYTE   bySupportFaceAE;          //是否支持 FaceAE：0-不支持，1-支持
        BYTE   bySupportFocusSensitivity;//是否支持 聚焦灵敏度：0-不支持，1-支持
        BYTE   bySupportFaceCentered;    //是否支持 人脸居中：0-不支持，1-支持
        BYTE   bySupportSpokesmanTrack;  //是否支持 发言人跟踪：0-不支持，1-支持
        BYTE   byRes1[2];
        BYTE   byRes[128];
    } USB_PRIVATE_UVC_CABABILITIES, *LPUSB_PRIVATE_UVC_CABABILITIES;

    typedef struct tagUSB_PRIVATE_UAC_CABABILITIES
    {
        DWORD  dwSize; //结构体大小
        BYTE   bySupportSoftwareVersion; //是否支持 软件版本号：0-不支持，1-支持
        BYTE   bySupportAEC;             //是否支持 回声消除：0-不支持，1-支持
        BYTE   bySupportNoiseReduce;     //是否支持 降噪：0-不支持，1-支持
        BYTE   bySupportPickUp;          //是否支持 音频拾音：0-不支持，1-支持
        BYTE   byRes[128];
    } USB_PRIVATE_UAC_CABABILITIES, *LPUSB_PRIVATE_UAC_CABABILITIES;

    typedef struct tagUSB_IAMGE_MODE_PARAM
    {
        DWORD  dwSize; //结构体大小
        BYTE   byMode; //图像模式：0-标准，1-鲜艳，2-柔和，3-背光
        BYTE   byDefault; //图像模式默认值
        BYTE   byRes1[2];
        BYTE   byRes[128];
    } USB_IAMGE_MODE_PARAM, *LPUSB_IAMGE_MODE_PARAM;

    typedef struct tagUSB_WHITE_BALANCE_PARAM
    {
        DWORD  dwSize; //结构体大小
        BYTE   byEnable; //白平衡：0-关闭，1-开启，2-校准
        BYTE   byDefault; //白平衡默认值
        BYTE   byRes1[2];
        BYTE   byRes[128];
    } USB_WHITE_BALANCE_PARAM, *LPUSB_WHITE_BALANCE_PARAM;

    typedef struct tagUSB_GAMUT_PARAM
    {
        DWORD  dwSize; //结构体大小
        BYTE   byLevel; //色域值
        BYTE   byDefault; //色域默认值
        BYTE   byMin; //色域最小值
        BYTE   byMax; //色域最大值
        BYTE   byRes[128];
    } USB_GAMUT_PARAM, *LPUSB_GAMUT_PARAM;

    typedef struct tagUSB_SHUTTER_PARAM
    {
        DWORD  dwSize; //结构体大小
        BYTE   byLevel; //快门时间等级
        BYTE   byDefault; //快门时间等级默认值
        BYTE   byMin; //快门时间等级最小值
        BYTE   byMax; //快门时间等级最大值
        BYTE   byRes[128];
    } USB_SHUTTER_PARAM, *LPUSB_SHUTTER_PARAM;

    typedef struct tagUSB_FOCUS_PARAM
    {
        DWORD  dwSize; //结构体大小
        BYTE   byLevel; //聚焦灵敏度等级
        BYTE   byDefault; //聚焦灵敏度等级默认值
        BYTE   byMin; //聚焦灵敏度等级最小值
        BYTE   byMax; //聚焦灵敏度等级最大值
        BYTE   byRes[128];
    } USB_FOCUS_PARAM, *LPUSB_FOCUS_PARAM;

    typedef struct tagUSB_OVERHEAD_SHOT_PARAM
    {
        DWORD  dwSize; //结构体大小
        BYTE   byMode; //正俯拍模式: 0-正拍  1-俯拍
        BYTE   byDefault; //聚焦灵敏度等级默认值
        BYTE   byRes[128];
    } USB_OVERHEAD_SHOT_PARAM, *LPUSB_OVERHEAD_SHOT_PARAM;

    typedef struct tagUSB_VCA_FACE_AE_PARAM
    {
        DWORD  dwSize; //结构体大小
        BYTE   byEnable; //人脸局部曝光使能 0-关闭 1-开启
        BYTE   byLevel; //人脸局部曝光等级
        BYTE   byDefault; //人脸局部曝光等级默认值
        BYTE   byMin; //人脸局部曝光等级最小值
        BYTE   byMax; //人脸局部曝光等级最大值
        BYTE   byRes1[3];
        BYTE   byRes[128];
    } USB_VCA_FACE_AE_PARAM, *LPUSB_VCA_FACE_AE_PARAM;

    typedef struct tagUSB_VCA_FACE_CENTERED_PARAM
    {
        DWORD  dwSize; //结构体大小
        BYTE   byEnable; //人脸居中使能 0-关闭 1-开启
        BYTE   byLevel; //人脸居中灵敏度等级
        BYTE   byDefault; //人脸居中灵敏度等级默认值
        BYTE   byMin; //人脸居中灵敏度等级最小值
        BYTE   byMax; //人脸居中灵敏度等级最大值
        BYTE   byRes1[3];
        BYTE   byRes[128];
    } USB_VCA_FACE_CENTERED_PARAM, *LPUSB_VCA_FACE_CENTERED_PARAM;

    typedef struct tagUSB_VCA_SPOKESMAN_TRACK_PARAM
    {
        DWORD  dwSize; //结构体大小
        BYTE   byEnable; //发言人跟踪使能 0-关闭 1-开启
        BYTE   byLevel; //发言人跟踪灵敏度等级
        BYTE   byDefault; //发言人跟踪灵敏度等级默认值
        BYTE   byMin; //发言人跟踪灵敏度等级最小值
        BYTE   byMax; //发言人跟踪灵敏度等级最大值
        BYTE   byRes1[3];
        BYTE   byRes[128];
    } USB_VCA_SPOKESMAN_TRACK_PARAM, *LPUSB_VCA_SPOKESMAN_TRACK_PARAM;

    typedef struct tagUSB_VCA_BEAUTY_PARAM
    {
        DWORD  dwSize; //结构体大小
        BYTE   bySmoothing; //磨皮 0-不支持 1-支持
        BYTE   byWhitening; //美白 0-不支持 1-支持
        BYTE   byBlush; //红润 0-不支持 1-支持
        BYTE   bySharpness; //锐化 0-不支持 1-支持
        BYTE   byEyeRetouch; //亮眼 0-不支持 1-支持
        BYTE   byTeethBeautification; //美牙 0-不支持 1-支持
        BYTE   byDarkCircles; //祛黑眼圈 0-不支持 1-支持
        BYTE   byNasolabialFolds; //祛法令纹 0-不支持 1-支持
        BYTE   bySlimFace; //瘦脸 0-不支持 1-支持
        BYTE   byVshapedFace; //V脸 0-不支持 1-支持
        BYTE   byFaceWidth; //窄脸 0-不支持 1-支持
        BYTE   byCheekbones; //瘦颧骨 0-不支持 1-支持
        BYTE   byLowerJaw; //瘦下颚骨 0-不支持 1-支持
        BYTE   byEyeSize; //大眼 0-不支持 1-支持
        BYTE   byEyeShape; //圆眼 0-不支持 1-支持
        BYTE   byNoseWidth; //瘦鼻 0-不支持 1-支持
        BYTE   byNoseLength; //长鼻 0-不支持 1-支持
        BYTE   byMouthType; //嘴型 0-不支持 1-支持
        BYTE   bySmilingMouth; //微笑嘴角 0-不支持 1-支持
        BYTE   byRemoveMakeup; //卸妆 0-不支持 1-支持
        BYTE   byPeachBlossom; //桃花 0-不支持 1-支持
        BYTE   byFreckle; //雀斑 0-不支持 1-支持
        BYTE   byPunk; //朋克 0-不支持 1-支持
        BYTE   byMapleLeaf; //枫叶 0-不支持 1-支持
        BYTE   byRetro; //复古 0-不支持 1-支持
        BYTE   byKoi; //锦鲤 0-不支持 1-支持
        BYTE   byPlum; //梅子 0-不支持 1-支持
        BYTE   bySweet; //甜美 0-不支持 1-支持
        BYTE   byRedTea; //赤茶 0-不支持 1-支持
        BYTE   byWinter; //冬日 0-不支持 1-支持
        BYTE   byStylish; //个性 0-不支持 1-支持
        BYTE   byCream; //奶油 0-不支持 1-支持
        BYTE   byClear; //清透 0-不支持 1-支持
        BYTE   byGrapefruit; //西柚 0-不支持 1-支持
        BYTE   byNeighbour; //邻家 0-不支持 1-支持
        BYTE   byDegree; //程度 0-不支持 1-支持
        BYTE   byOriginal; //原图 0-不支持 1-支持
        BYTE   byBrightWhite; //亮白 0-不支持 1-支持
        BYTE   byRosy; //粉嫩 0-不支持 1-支持
        BYTE   byFair; //白皙 0-不支持 1-支持
        BYTE   byCoolColors; //冷色调 0-不支持 1-支持
        BYTE   byPeach; //蜜桃 0-不支持 1-支持
        BYTE   byWarmColors; //暖色调 0-不支持 1-支持
        BYTE   byFresh; //小清新 0-不支持 1-支持
        BYTE   byElegantGray; //质感灰 0-不支持 1-支持
        BYTE   byNatural; //自然 0-不支持 1-支持
        BYTE   bySunshine; //阳光 0-不支持 1-支持
        BYTE   byRes1[1];
        BYTE   byRes[128];
    } USB_VCA_BEAUTY_PARAM, *LPUSB_VCA_BEAUTY_PARAM;

    //VCM校准
    typedef struct tagUSB_TEST_VCM
    {
        DWORD  dwSize;   //结构体大小
        BYTE   byResult; //VCM标定结果 0-失败 1-成功 2-标定中  （设置时无效）
        BYTE   byRes1[3];
        WORD   wValue; //VCM标定数据  （设置时无效）
        BYTE   byRes[22];
    } USB_TEST_VCM, *LPUSB_TEST_VCM;

    //DTOF校准
    typedef struct tagUSB_TEST_DTOF_CALIBRATION
    {
        DWORD  dwSize;    //结构体大小
        BYTE   byEnable;  //使能 0-关闭 1-开启 （获取时无效）
        BYTE   byResult;  //DTOF校准结果 0-失败 1-成功 2-校准中  （设置时无效）
        BYTE   byRes[26];
    } USB_TEST_DTOF_CALIBRATION, *LPUSB_TEST_DTOF_CALIBRATION;

    //DTOF模块
    typedef struct tagUSB_TEST_DTOF_INFO
    {
        DWORD  dwSize;    //结构体大小
        BYTE   byId;    //TOF ID
        BYTE   byStatus;    //状态：0-正常，1-7异常
        BYTE   byDistance;    //距离(mm)：0-255
        BYTE   byRes[25];
    } USB_TEST_DTOF_INFO, *LPUSB_TEST_DTOF_INFO;

    //DTOF检测
    typedef struct tagUSB_TEST_DTOF_CHECK
    {
        DWORD  dwSize;    //结构体大小
        BYTE   byEnable;    //使能 0-默认 1-开启  （获取时无效）
        BYTE   byTofNum;    //TOF个数   （设置时无效）
        BYTE   byRes1[2];
        USB_TEST_DTOF_INFO struDtofInfo[10];//Dtof 模块信息  （设置时无效）
        BYTE   byRes[32];
    } USB_TEST_DTOF_CHECK, *LPUSB_TEST_DTOF_CHECK;

    //PWM占空比
    typedef struct tagUSB_TEST_PWM
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byValue;     //占空比（0-100）
        BYTE   byRes[27];
    } USB_TEST_PWM, *LPUSB_TEST_PWM;

    //ITOF距离检测
    typedef struct tagUSB_TEST_ITOF_DISTANCE
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byResult;       //ITOF距离检测结果 0-失败 1-成功 （设置时无效）
        BYTE   byRes1;
        WORD   wValue;   //深度数据 （设置时无效）
        BYTE   byRes[24];
    } USB_TEST_ITOF_DISTANCE, *LPUSB_TEST_ITOF_DISTANCE;

    //ITOF出厂检测
    typedef struct tagUSB_TEST_ITOF_FACTORY
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byEnable;    //使能 0-关闭 1-开启  （获取时无效）
        BYTE   byResult;    //ITOF距离检测结果 2-成功 其他值-失败 （设置时无效）
        BYTE   byRes[26];
    } USB_TEST_ITOF_FACTORY, *LPUSB_TEST_ITOF_FACTORY;

    //ITOF单帧检测
    typedef struct tagUSB_TEST_ITOF_FRAME
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byEnable;    //使能 0-关闭 1-开启  （获取时无效）
        BYTE   byResult;    //ITOF单帧检测结果 2-成功 其他值-失败 （设置时无效）
        BYTE   byRes[26];
    } USB_TEST_ITOF_FRAME, *LPUSB_TEST_ITOF_FRAME;

    //ITOF出厂检测2
    typedef struct tagUSB_TEST_ITOF_FACTORY2
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byEnable;    //使能 0-关闭 1-开启  （获取时无效）
        BYTE   byResult;    //ITOF距离检测2结果 2-成功 其他值-失败 （设置时无效）
        WORD   wPrecision;   //精度（设置时无效）
        WORD   wAccuracy;   //准度（设置时无效）
        WORD   wIr;         //IR平均值（设置时无效）
        BYTE   byRes[26];
    } USB_TEST_ITOF_FACTORY2, *LPUSB_TEST_ITOF_FACTORY2;

    //ITOF标定
    typedef struct tagUSB_TEST_ITOF_CALIBRATION
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byEnable;    //使能 0-关闭 1-开启  （获取时无效）
        BYTE   byResult;    //ITOF距离检测2结果 0-数据准备中 1-成功 2-失败 （设置时无效）
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

    //镜头老化检测结果
    typedef struct tagUSB_TEST_SCENE_CURVE_CHECK
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byEnable;    //使能 0-初始化 1-开始校验 2-保存结果  （获取时无效）
        BYTE   byResult;    //结果 0-失败 1-成功 （设置时无效）
        BYTE   byRes[20];
    } USB_TEST_SCENE_CURVE_CHECK, *LPUSB_TEST_SCENE_CURVE_CHECK;

    //镜头老化检测结果
    typedef struct tagUSB_TEST_SCENE_AGE_CHECK
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byEnable;    //使能 0-关闭 1-开启  （获取时无效）
        BYTE   byRes1[3];
        DWORD  dwPan;       //Pan老化率   （设置时无效）
        DWORD  dwTitl;      //Titl老化率    （设置时无效）
        BYTE   byRes[16];
    } USB_TEST_SCENE_AGE_CHECK, *LPUSB_TEST_SCENE_AGE_CHECK;

    //指示灯检测
    typedef struct tagUSB_TEST_LAMP_CHECK
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byEnable;    //使能：0-关闭 1-开启
        BYTE   byRes[27];
    } USB_TEST_LAMP_CHECK, *LPUSB_TEST_LAMP_CHECK;

    //电池检测
    typedef struct tagUSB_TEST_BATTERY_CHECK
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byEnable;    //使能 0-默认 1-开启   （获取时无效）
        BYTE   byShutdown;    //Shutdown模式配置 0-关闭 1-开启   （enable为0时有效）（获取时无效）
        BYTE   byResult;    //Shutdown模式结果 0-失败 1-成功 （设置时无效）
        char   byPower;     //电量：-1：异常   0-100电量值
        WORD   wVoltageDiff;      //结构体大小
        WORD   wCirculate;      //结构体大小
        WORD   wTemperature;      //结构体大小
        WORD   wVoltage;      //结构体大小
        WORD   wCurrent;      //结构体大小
        WORD   wVersion;      //结构体大小
        BYTE   byRes[27];
    } USB_TEST_BATTERY_CHECK, *LPUSB_TEST_BATTERY_CHECK;

    //旋钮
    typedef struct tagUSB_TEST_KNOB_PARAM
    {
        DWORD  dwSize;       //结构体大小
        BYTE   byID;  //旋钮id
        BYTE   byRes1[3];
        WORD   wMin;    //最小值
        WORD   wMax;    //最大值
        BYTE   byRes[4];
    } USB_TEST_KNOB_PARAM, *LPUSB_TEST_KNOB_PARAM;

    //旋钮标定
    typedef struct tagUSB_TEST_KNOB_CALIBRATION
    {
        DWORD  dwSize;       //结构体大小
        BYTE   byOperation;  //检测步骤: 0-默认 1-最小值标定 2-最大值标定  （获取时无效）
        BYTE   byResult;    //检测结果下发 0-默认 1-复合要求 2-不符合要求 （operation为0时有效）（获取时无效）
        BYTE   byGetResult;    //结果（设备获取旋钮电压值是否结束） 0-检测中 1-检测结束（设置时无效）
        BYTE   bySaveResult;    //结果（设备保存旋钮标定结果） 0-失败 1-成功（设置时无效）
        BYTE   byKnobNum;    //旋钮个数
        BYTE   byRes1[3];
        USB_TEST_KNOB_PARAM struKnob[10];
        BYTE   byRes[16];
    } USB_TEST_KNOB_CALIBRATION, *LPUSB_TEST_KNOB_CALIBRATION;

    //参数配置表恢复默认
    typedef struct tagUSB_TEST_PARAM_RESET
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byEnable;    //检测步骤 0-默认 1-开始恢复   （获取时无效）
        BYTE   byResult;    //结果 0-失败 1-成功 （设置时无效）
        BYTE   byRes[26];
    } USB_TEST_PARAM_RESET, *LPUSB_TEST_PARAM_RESET;

    //端点
    typedef struct tagUSB_TEST_ENDPOINTS
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byID;    //端点ID
        BYTE   byEnable;    //虚拟串口使能 0-关闭 1-开启
        BYTE   byRes[26];
    } USB_TEST_ENDPOINTS, *LPUSB_TEST_ENDPOINTS;

    //隐藏端点
    typedef struct tagUSB_TEST_HIDE_ENDPOINTS
    {
        DWORD  dwSize;      //结构体大小
        USB_TEST_ENDPOINTS struEndpoints[10];
        BYTE   byRes[32];
    } USB_TEST_HIDE_ENDPOINTS, *LPUSB_TEST_HIDE_ENDPOINTS;

    //霍尔状态获取
    typedef struct tagUSB_TEST_HALL
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byStatus;    //霍尔状态 0-关闭 1-开启
        BYTE   byRes[27];
    } USB_TEST_HALL, *LPUSB_TEST_HALL;

    //设备位置
    typedef struct tagUSB_TEST_DEVICE_LOCATION
    {
        DWORD  dwSize;        //结构体大小
        BYTE   byLocationID;  //设备物理位置ID(范围：1-255)
        BYTE   byRes[27];
    } USB_TEST_DEVICE_LOCATION, *LPUSB_TEST_DEVICE_LOCATION;

    //触摸点
    typedef struct tagUSB_TEST_TOUCH_POINT
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byID;    //触摸点ID
        BYTE   byStatus;    //状态 0-关闭 1-开启
        BYTE   byRes[26];
    } USB_TEST_TOUCH_POINT, *LPUSB_TEST_TOUCH_POINT;

    //触摸按键检测
    typedef struct tagUSB_TEST_TOUCH_BUTTON
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byEnable;    //使能 0-关闭 1-开启 （获取时无效）
        BYTE   byNum;    //触摸点个数 0-关闭 1-开启  （设置时无效）
        BYTE   byRes1[2];
        USB_TEST_TOUCH_POINT struTouchPoint[10]; //触摸点（设置时无效）
        BYTE   byRes[32];
    } USB_TEST_TOUCH_BUTTON, *LPUSB_TEST_TOUCH_BUTTON;

    //幅面标定
    typedef struct tagUSB_TEST_FRAME
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byEnable;    //检测步骤 0-默认 1-开始   （获取时无效）
        BYTE   byResult;    //结果 0-失败 1-成功 2-标定中（设置时无效）
        BYTE   byRes[26];
    } USB_TEST_FRAME, *LPUSB_TEST_FRAME;

    //视频菜单控制
    typedef struct tagUSB_CTRL_MENU_PARAM
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byControlUnit; //菜单控制 1-调出菜单 2-向上移动菜单栏选项 3-向下移动菜单栏选项 4-向左移动菜单栏选项 5-向右移动菜单栏选项 6-确认 7-返回
        BYTE   byRes[27];
    } USB_CTRL_MENU_PARAM, *LPUSB_CTRL_MENU_PARAM;

    //图像色彩空间
    typedef struct tagUSB_IMAGE_DYNAMIC_RANGE_PARAM
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byDynamicRangeType; //色彩空间类型（ITU发布标准）：1-BT.601 2-BT.709 3-BT.2020
        BYTE   byRes[27];
    } USB_IMAGE_DYNAMIC_RANGE_PARAM, *LPUSB_IMAGE_DYNAMIC_RANGE_PARAM;

    //云台基础控制
    typedef struct tagUSB_PTZ_BASIC_CTRL_PARAM
    {
        DWORD  dwSize;      //结构体大小
        BYTE   byPtzDirection; //方向：1-上 2-下 3-左 4-右 5-zoom+ 6-zoom- 7-focus+ 8-focus-
        BYTE   byPtzStatus; //状态：0-停止 1-开始
        BYTE   byRes[26];
    } USB_PTZ_BASIC_CTRL_PARAM, *LPUSB_PTZ_BASIC_CTRL_PARAM;

    //USB_SDK的初始化
    USB_SDK_API BOOL  CALLBACK USB_Init();
    //USB_SDK的反初始化
    USB_SDK_API BOOL  CALLBACK USB_Cleanup();
    USB_SDK_API DWORD CALLBACK USB_GetSDKVersion(void);

    USB_SDK_API LONG  CALLBACK USB_GetDeviceCount();
    //可配置设备枚举接口（是否音视频设备分离，是否包括第三方设备）
    USB_SDK_API LONG  CALLBACK USB_GetDeviceCountEx(LPUSB_GET_DEVICE_COUNT_INFO pGetDeivceCountInfo);
    USB_SDK_API BOOL  CALLBACK USB_EnumDevices(DWORD dwCount, LPUSB_DEVICE_INFO pDevInfoList);
    //获取错误码
    USB_SDK_API DWORD CALLBACK USB_GetLastError();
    //获取错误码对应的信息
    USB_SDK_API char* CALLBACK USB_GetErrorMsg(DWORD dwErrorCode);

    // 获取当前命令状态（热成像设备）
    // 场景：明确当前操作设备是否生效时，通过该接口判断上一次指令是否生效（一直获取直到状态不等于0x01，轮询间隔大于10ms）
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
    * 功能：停止预览，录像，码流回调，目标识别
    * @param in lUserID：设备句柄（即USB_Login的返回值）
    * @param in lHandle：预览，录像，码流回调，人脸检测句柄
    * @param out HPR_TRUE - 成功，HPR_FALSE - 失败
    */
    USB_SDK_API BOOL  CALLBACK USB_StopChannel(LONG lUserID, DWORD lHandle);
    USB_SDK_API BOOL  CALLBACK USB_SetSDKLocalCfg(USB_LOCAL_CFG_TYPE enumType, const void *lpInBuff);
    // 获取播放库端口
    USB_SDK_API LONG  CALLBACK USB_GetPlayerPort(LONG lUserID, DWORD lHandle);
#endif 

