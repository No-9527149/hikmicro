#include "Thermal.h"

#include <stdio.h>
#include <string.h>
#include <unistd.h>

#include <iostream>

using namespace std;

Thermal::Thermal() : fd(NULL) {
  m_pGetStream = new CGetStream(THERMAL_DEVICE);
  m_bResource = (m_pGetStream != NULL);
}

void Thermal::GetImage() {
  printf("\n****通用接口调用****\r\n");
  printf("\n----SDK版本----\r\n");
  FuncGetSdkVersion();
  printf("\n----USB初始化----\r\n");
  FuncSdkInit();
  printf("\n----设置Log----\r\n");
  SetLogFile();
  printf("\n----设备数量----\r\n");
  FuncGetDeviceCount();
  printf("\n----枚举设备----\r\n");
  FuncEnumDevices();
  printf("\n----登陆设备----\r\n");
  FuncLoginDevices(0);
  m_pGetStream->SetUserID(m_lUserID);
  printf("\n****设备初始化****\r\n");
  printf("\n----设备信息----\r\n");
  GetSystemDeviceInfo();
  printf("\n----获取硬件服务----\r\n");
  GetSystemHardwareServer();
  printf("\n----设置硬件服务----\r\n");
  SetSystemHardwareServer();
  printf("\n----获取系统时间----\r\n");
  GetSystemLocalTime();
  printf("\n----设置系统时间----\r\n");
  SetSystemLocalTime();
  printf("\n****图像参数****\r\n");
  printf("\n----亮度----\r\n");
  GetImageBrightness();
  printf("\n----对比度----\r\n");
  GetImageContrast();
  printf("\n----图像增强----\r\n");
  GetImageEnhancement();
  printf("\n----视频调整----\r\n");
  GetImageVideoAdjust();
  printf("\n----测温基本参数----\r\n");
  GetThermometryBasicParam();
  SetThermometryBasicParam();
  GetThermometryBasicParam();
  printf("\n----测温模式----\r\n");
  GetThermometryMode();
  printf("\n----测温规则----\r\n");
  GetThermometryRegions();
  printf("\n----测温修正----\r\n");
  GetTemperatureCorrect();
  printf("\n----黑体参数----\r\n");
  GetBlackBody();
  printf("\n----体温补偿----\r\n");
  GetBodytempCompensation();
  printf("\n----ROI最高温----\r\n");
  GetRoiMaxTemperatureSearch();
  printf("\n----全屏测温----\r\n");
  GetP2PParam();
  printf("\n----双光校准坐标控制参数----\r\n");
  GetDoubleLightsCorrectPointsCtrl();

  printf("\n****数据传输****\r\n");
  printf("\n----获取流参数----\r\n");
  GetThermalStreamParam();
  printf("\n----设置流参数----\r\n");
  SetThermalStreamParam();
  printf("\n----截图测温----\r\n");
  GetJpegpicWithAppenddata();
  printf("\n----诊断数据----\r\n");
  GetSystemDiagnoseData();
}

void Thermal::Usage(void) {
  printf("Select Thermal Capacity:\r\n");
  PRINTF(CUSTOM_PRINT_MENU);
  PRINTF(CUSTOM_GET_SDK_VERSION);
  PRINTF(CUSTOM_USB_INIT);
  PRINTF(CUSTOM_SET_LOGTOFILE);
  PRINTF(CUSTOM_GET_DEVICE_COUNT);
  PRINTF(CUSTOM_ENUM_DEVICE);
  PRINTF(CUSTOM_LOGIN_DEVICE);
  PRINTF(CUSTOM_DEVICE_LOGOUT);
  PRINTF(CUSTOM_CLEANUP);
  PRINTF(THERMAL_GET_SYSTEM_DEVICE_INFO);
  PRINTF(THERMAL_SET_SYSTEM_REBOOT);
  PRINTF(THERMAL_SET_SYSTEM_RESET);
  PRINTF(THERMAL_GET_SYSTEM_HARDWARE_SERVER);
  PRINTF(THERMAL_SET_SYSTEM_HARDWARE_SERVER);
  PRINTF(THERMAL_GET_SYSTEM_LOCALTIME);
  PRINTF(THERMAL_SET_SYSTEM_LOCALTIME);
  PRINTF(THERMAL_GET_IMAGE_BRIGHTNESS);
  PRINTF(THERMAL_SET_IMAGE_BRIGHTNESS);
  PRINTF(THERMAL_GET_IMAGE_CONTRAST);
  PRINTF(THERMAL_SET_IMAGE_CONTRAST);
  PRINTF(THERMAL_SET_SYSTEM_UPDATE_FIRMWARE);
  PRINTF(THERMAL_SET_IMAGE_BACKGROUND_CORRECT);
  PRINTF(THERMAL_GET_SYSTEM_DIAGNOSED_DATA);
  PRINTF(THERMAL_SET_IMAGE_MANUAL_CORRECT);
  PRINTF(THERMAL_GET_IMAGE_ENHANCEMENT);
  PRINTF(THERMAL_SET_IMAGE_ENHANCEMENT);
  PRINTF(THERMAL_GET_IMAGE_VIDEO_ADJUST);
  PRINTF(THERMAL_SET_IMAGE_VIDEO_ADJUST);
  PRINTF(THERMAL_GET_THERMOMETRY_BASIC_PARAM);
  PRINTF(THERMAL_SET_THERMOMETRY_BASIC_PARAM);
  PRINTF(THERMAL_GET_THERMOMETRY_MODE);
  PRINTF(THERMAL_SET_THERMOMETRY_MODE);
  PRINTF(THERMAL_GET_THERMOMETRY_REGIONS);
  PRINTF(THERMAL_SET_THERMOMETRY_REGIONS);
  PRINTF(THERMAL_GET_THERMAL_ALG_VERSION);
  PRINTF(THERMAL_GET_THERMAL_STREAM_PARAM);
  PRINTF(THERMAL_SET_THERMAL_STREAM_PARAM);
  PRINTF(THERMAL_GET_TEMPERATURE_CORRECT);
  PRINTF(THERMAL_SET_TEMPERATURE_CORRECT);
  PRINTF(THERMAL_GET_BLACK_BODY);
  PRINTF(THERMAL_SET_BLACK_BODY);
  PRINTF(THERMAL_GET_BODYTEMP_COMPENSATION);
  PRINTF(THERMAL_SET_BODYTEMP_COMPENSATION);
  PRINTF(THERMAL_GET_JPEGPIC_WITH_APPENDDATA);
  PRINTF(THERMAL_GET_ROI_MAX_TEMPERATURE_SEARCH);
  PRINTF(THERMAL_GET_P2P_PARAM);
  PRINTF(THERMAL_SET_P2P_PARAM);
  PRINTF(THERMAL_POST_DOUBLE_LIGHTS_CORRECT);
  PRINTF(THERMAL_GET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL);
  PRINTF(THERMAL_SET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL);
  PRINTF(THERMAL_GET_THERMOMETRY_CALIBRATION_FILE);
  PRINTF(THERMAL_SET_THERMOMETRY_CALIBRATION_FILE);
  PRINTF(THERMAL_GET_DEVICE_UPGRADE_STATE);
  PRINTF(THERMAL_CLOSE_UPGRADE);
  PRINTF(THERMAL_GET_COMMAND_STATE);
  PRINTF(CUSTOM_STREAM_CALLBACK);
  PRINTF(CUSTOM_STREAM_RECORD);
  PRINTF(CUSTOM_STREAM_PREVIEW);
  printf("\t Press q to quit...\r\n");
}

void Thermal::UsbImplement() {
  while (!m_bExit) {
    int iIn = CheckBoardInput();
    DoBusiness(iIn);
  }
  delete m_pGetStream;
  m_pGetStream = NULL;
}

void Thermal::DoBusiness(int iType, int iDevIndex) {
  switch (iType) {
    case KEYBOARD_INPUT_FAILED: {
      printf("Thermal Device Exit...\r\n");
      m_bExit = TRUE;
      break;
    }
    case THERMAL_CLOSE_UPGRADE:  //关闭升级
    {
      CloseUpgradeHandle();
      break;
    }
    case CUSTOM_CLEANUP:  //反初始化
    {
      FuncSdkCleanup();
      break;
    }
    case CUSTOM_PRINT_MENU: {
      Usage();
      break;
    }
    case CUSTOM_GET_SDK_VERSION:  //打印SDK版本号
    {
      FuncGetSdkVersion();
      break;
    }
    case CUSTOM_USB_INIT:  // SDK初始化
    {
      FuncSdkInit();
      break;
    }
    case CUSTOM_SET_LOGTOFILE:  //开启SDK日志
    {
      SetLogFile();
      break;
    }
    case CUSTOM_GET_DEVICE_COUNT:  //获取设备数量
    {
      FuncGetDeviceCount();
      break;
    }
    case CUSTOM_ENUM_DEVICE:  //枚举设备信息
    {
      FuncEnumDevices();
      break;
    }
    case CUSTOM_LOGIN_DEVICE:  //登陆设备
    {
      FuncLoginDevices(iDevIndex);
      m_pGetStream->SetUserID(m_lUserID);
      printf("iDevIndex: %d\n", iDevIndex);
      printf("m_lUserID: %d\n", m_lUserID);
      break;
    }
    case THERMAL_GET_SYSTEM_DEVICE_INFO:  //获取设备信息
    {
      GetSystemDeviceInfo();
      break;
    }
    case THERMAL_SET_SYSTEM_REBOOT:  //设备重启
    {
      SetSystemReboot();
      break;
    }
    case THERMAL_SET_SYSTEM_RESET:  //恢复默认
    {
      SetSystemReset();
      break;
    }
    case THERMAL_GET_SYSTEM_HARDWARE_SERVER:  // 获取硬件服务参数
    {
      GetSystemHardwareServer();
      break;
    }
    case THERMAL_SET_SYSTEM_HARDWARE_SERVER:  // 设置硬件服务参数
    {
      SetSystemHardwareServer();
      break;
    }
    case THERMAL_GET_SYSTEM_LOCALTIME:  //获取系统本地时间
    {
      GetSystemLocalTime();
      break;
    }
    case THERMAL_SET_SYSTEM_LOCALTIME:  //设置系统本地时间
    {
      SetSystemLocalTime();
      break;
    }
    case THERMAL_GET_IMAGE_BRIGHTNESS:  //获取图像亮度参数
    {
      GetImageBrightness();
      break;
    }
    case THERMAL_SET_IMAGE_BRIGHTNESS:  //设置图像亮度参数
    {
      SetImageBrightness();
      break;
    }
    case THERMAL_GET_IMAGE_CONTRAST:  //获取图像对比度参数
    {
      GetImageContrast();
      break;
    }
    case THERMAL_SET_IMAGE_CONTRAST:  //设置图像对比度参数
    {
      SetImageContrast();
      break;
    }
    case THERMAL_SET_SYSTEM_UPDATE_FIRMWARE:  // 设备升级
    {
      SetSystemUpdateFirmware();
      GetDeviceUpgradeState();
      break;
    }
    case THERMAL_SET_IMAGE_BACKGROUND_CORRECT:  //一键背景校正
    {
      SetImageBackgroundCorrect();
      break;
    }
    case THERMAL_GET_SYSTEM_DIAGNOSED_DATA:  //诊断信息导出
    {
      GetSystemDiagnoseData();
      break;
    }
    case THERMAL_SET_IMAGE_MANUAL_CORRECT:  //一键手动校正
    {
      SetImageManualCorrect();
      break;
    }
    case THERMAL_GET_IMAGE_ENHANCEMENT:  // 获取图像增强参数
    {
      GetImageEnhancement();
      break;
    }
    case THERMAL_SET_IMAGE_ENHANCEMENT:  //设置图像增强参数
    {
      SetImageEnhancement();
      break;
    }
    case THERMAL_GET_IMAGE_VIDEO_ADJUST:  //获取视频调整参数
    {
      GetImageVideoAdjust();
      break;
    }
    case THERMAL_SET_IMAGE_VIDEO_ADJUST:  //设置视频调整参数
    {
      SetImageVideoAdjust();
      break;
    }
    case THERMAL_GET_THERMOMETRY_BASIC_PARAM:  // 获取测温基本参数
    {
      GetThermometryBasicParam();
      break;
    }
    case THERMAL_SET_THERMOMETRY_BASIC_PARAM:  // 设置测温基本参数
    {
      SetThermometryBasicParam();
      break;
    }
    case THERMAL_GET_THERMOMETRY_MODE:  //获取测温模式
    {
      GetThermometryMode();
      break;
    }
    case THERMAL_SET_THERMOMETRY_MODE:  //设置测温模式
    {
      SetThermometryMode();
      break;
    }
    case THERMAL_GET_THERMOMETRY_REGIONS:  // 获取测温规则参数
    {
      GetThermometryRegions();
      break;
    }
    case THERMAL_SET_THERMOMETRY_REGIONS:  //设置测温规则参数
    {
      SetThermometryRegions();
      break;
    }
    case THERMAL_GET_THERMAL_ALG_VERSION:  //获取热成像相关算法版本信息
    {
      GetThermalAlgVersion();
      break;
    }
    case THERMAL_GET_THERMAL_STREAM_PARAM:  // 获取热成像码流参数
    {
      GetThermalStreamParam();
      break;
    }
    case THERMAL_SET_THERMAL_STREAM_PARAM:  // 设置热成像码流参数
    {
      SetThermalStreamParam();
      break;
    }
    case THERMAL_GET_TEMPERATURE_CORRECT:  //获取测温修正参数
    {
      GetTemperatureCorrect();
      break;
    }
    case THERMAL_SET_TEMPERATURE_CORRECT:  //设置测温修正参数
    {
      SetTemperatureCorrect();
      break;
    }
    case THERMAL_GET_BLACK_BODY:  //获取黑体参数
    {
      GetBlackBody();
      break;
    }
    case THERMAL_SET_BLACK_BODY:  //设置黑体参数
    {
      SetBlackBody();
      break;
    }
    case THERMAL_GET_BODYTEMP_COMPENSATION:  // 获取体温补偿参数
    {
      GetBodytempCompensation();
      break;
    }
    case THERMAL_SET_BODYTEMP_COMPENSATION:  //设置体温补偿参数
    {
      SetBodytempCompensation();
      break;
    }
    case THERMAL_GET_JPEGPIC_WITH_APPENDDATA:  // 获取热图
    {
      GetJpegpicWithAppenddata();
      break;
    }
    case THERMAL_GET_ROI_MAX_TEMPERATURE_SEARCH:  // roi最高温信息查询
    {
      GetRoiMaxTemperatureSearch();
      break;
    }
    case THERMAL_GET_P2P_PARAM:  //获取全屏测温参数
    {
      GetP2PParam();
      break;
    }
    case THERMAL_SET_P2P_PARAM:  //设置全屏测温参数
    {
      SetP2PParam();
      break;
    }
    case THERMAL_POST_DOUBLE_LIGHTS_CORRECT:  //双光校准
    {
      PostDoubleLightsCorrect();
      break;
    }
    case THERMAL_GET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL:  //获取双光校准坐标控制参数
    {
      GetDoubleLightsCorrectPointsCtrl();
      break;
    }
    case THERMAL_SET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL:  //设置双光校准坐标控制参数
    {
      SetDoubleLightsCorrectPointCtrl();
      break;
    }
    case THERMAL_GET_THERMOMETRY_CALIBRATION_FILE:  //测温标定文件导出
    {
      GetThermometryCalibrationFile();
      break;
    }
    case THERMAL_SET_THERMOMETRY_CALIBRATION_FILE:  //测温标定文件导入
    {
      SetThermometryCalibrationFile();
      break;
    }
    case THERMAL_GET_DEVICE_UPGRADE_STATE:  // 获取设备升级状态
    {
      GetDeviceUpgradeState();
      break;
    }
    case CUSTOM_STREAM_CALLBACK:  //码流回调
    {
      m_pGetStream->StartStreamCallback();
      break;
    }
    case CUSTOM_DEVICE_LOGOUT:  //登出
    {
      DeviceLogout();
      break;
    }
    case CUSTOM_STREAM_RECORD:  //录像
    {
      m_pGetStream->StartStreamRecord();
      break;
    }
    case CUSTOM_STREAM_PREVIEW:  //预览
    {
      m_pGetStream->StartStreamPreview();
      break;
    }
    case THERMAL_GET_COMMAND_STATE:  //获取命令状态
    {
      GetCommandState();
      break;
    }
    default: {
      printf("FAILED Unsupported\r\n");
      break;
    }
  }
}

/*设备初始化*/
void Thermal::GetSystemDeviceInfo() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_SYSTEM_DEVICE_INFO struSysDevInfo = {0};

  struSysDevInfo.dwSize = sizeof(struSysDevInfo);
  struConfigOutputInfo.lpOutBuffer = &struSysDevInfo;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struSysDevInfo);
  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_SYSTEM_DEVICE_INFO,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_SYSTEM_DEVICE_INFO ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS USB_GET_SYSTEM_DEVICE_INFO byDeviceType[%s] "
        "byEncoderVersion[%s]  byFirmwareVersion[%s] byHardwareVersion[%s] "
        "byProtocolVersion[%s]\r\n",
        struSysDevInfo.byDeviceType, struSysDevInfo.byEncoderVersion,
        struSysDevInfo.byFirmwareVersion, struSysDevInfo.byHardwareVersion,
        struSysDevInfo.byProtocolVersion);
  }
}

void Thermal::GetSystemHardwareServer() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_SYSTEM_HARDWARE_SERVER struHardware = {0};

  struHardware.dwSize = sizeof(struHardware);
  struConfigOutputInfo.lpOutBuffer = &struHardware;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struHardware);
  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_SYSTEM_HARDWARE_SERVER,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_SYSTEM_HARDWARE_SERVER ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_GET_SYSTEM_HARDWARE_SERVER byUsbMode[%d]\r\n",
           struHardware.byUsbMode);
  }
}

void Thermal::SetSystemHardwareServer() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_SYSTEM_HARDWARE_SERVER struHardware = {0};

  struHardware.dwSize = sizeof(struHardware);
  struHardware.byUsbMode = 1;  //设置为uvc模式
  struConfigInputInfo.lpInBuffer = &struHardware;
  struConfigInputInfo.dwInBufferSize = sizeof(struHardware);
  if (!USB_SetDeviceConfig(m_lUserID, USB_SET_SYSTEM_HARDWARE_SERVER,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_SYSTEM_HARDWARE_SERVER ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_SET_SYSTEM_HARDWARE_SERVER byUsbMode[%d]\r\n",
           struHardware.byUsbMode);
  }
}

void Thermal::GetSystemLocalTime() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_SYSTEM_LOCALTIME struSysTime = {0};

  struSysTime.dwSize = sizeof(struSysTime);
  struConfigOutputInfo.lpOutBuffer = &struSysTime;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struSysTime);
  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_SYSTEM_LOCALTIME,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_SYSTEM_LOCALTIME ErrorCode = [%d], ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_GET_SYSTEM_LOCALTIME time[%d-%d-%d %d:%d:%d.%d]\r\n",
           struSysTime.wYear, struSysTime.byMonth, struSysTime.byDay,
           struSysTime.byHour, struSysTime.byMinute, struSysTime.bySecond,
           struSysTime.wMillisecond);
  }
}

void Thermal::SetSystemLocalTime() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_SYSTEM_LOCALTIME struSysTime = {0};

  time_t tNow = time(NULL);
  struct tm *pLocalTime = NULL;
  pLocalTime = localtime(&tNow);
  struSysTime.wYear = pLocalTime->tm_year + 1900;
  struSysTime.byMonth = pLocalTime->tm_mon + 1;
  struSysTime.byDay = pLocalTime->tm_wday;
  struSysTime.byHour = pLocalTime->tm_hour;
  struSysTime.byMinute = pLocalTime->tm_min;
  struSysTime.bySecond = pLocalTime->tm_sec;
  struSysTime.wMillisecond = 0;
  struSysTime.byExternalTimeSourceEnabled = 0;  //关闭外部校时
  struSysTime.dwSize = sizeof(struSysTime);
  struConfigInputInfo.lpInBuffer = &struSysTime;
  struConfigInputInfo.dwInBufferSize = sizeof(struSysTime);
  if (!USB_SetDeviceConfig(m_lUserID, USB_SET_SYSTEM_LOCALTIME,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_SYSTEM_LOCALTIME ErrorCode = [%d], ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_SET_SYSTEM_LOCALTIME time[%d-%d-%d %d:%d:%d.%d]\r\n",
           struSysTime.wYear, struSysTime.byMonth, struSysTime.byDay,
           struSysTime.byHour, struSysTime.byMinute, struSysTime.bySecond,
           struSysTime.wMillisecond);
  }
}

/*图像参数*/
void Thermal::GetImageBrightness() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_IMAGE_BRIGHTNESS struImageBrightness = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
  struConfigOutputInfo.lpOutBuffer = &struImageBrightness;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struImageBrightness);
  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_IMAGE_BRIGHTNESS,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_IMAGE_BRIGHTNESS ErrorCode = [%d], ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_GET_IMAGE_BRIGHTNESS dwBrightness[%d]\r\n",
           struImageBrightness.dwBrightness);
  }
}

void Thermal::SetImageBrightness() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_IMAGE_BRIGHTNESS struImageBrightness = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struImageBrightness.dwBrightness = 50;  //亮度50
  struConfigInputInfo.lpInBuffer = &struImageBrightness;
  struConfigInputInfo.dwInBufferSize = sizeof(struImageBrightness);
  if (!USB_GetDeviceConfig(m_lUserID, USB_SET_IMAGE_BRIGHTNESS,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_IMAGE_BRIGHTNESS ErrorCode = [%d], ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_SET_IMAGE_BRIGHTNESS dwBrightness[%d]\r\n",
           struImageBrightness.dwBrightness);
  }
}

void Thermal::GetImageContrast() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_IMAGE_CONTRAST struImageContrast = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
  struConfigOutputInfo.lpOutBuffer = &struImageContrast;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struImageContrast);
  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_IMAGE_CONTRAST,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_IMAGE_CONTRAST ErrorCode = [%d], ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_GET_IMAGE_CONTRAST dwContrast[%d]\r\n",
           struImageContrast.dwContrast);
  }
}

void Thermal::SetImageContrast() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_IMAGE_CONTRAST struImageContrast = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struImageContrast.dwContrast = 50;  //对比度50
  struConfigInputInfo.lpInBuffer = &struImageContrast;
  struConfigInputInfo.dwInBufferSize = sizeof(struImageContrast);
  if (!USB_GetDeviceConfig(m_lUserID, USB_SET_IMAGE_CONTRAST,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_IMAGE_CONTRAST ErrorCode = [%d], ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_SET_IMAGE_CONTRAST dwContrast[%d]\r\n",
           struImageContrast.dwContrast);
  }
}

void Thermal::GetImageEnhancement() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_IMAGE_ENHANCEMENT struImageEnhancement = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struImageEnhancement;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struImageEnhancement);
  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_IMAGE_ENHANCEMENT,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_IMAGE_ENHANCEMENT ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_GET_IMAGE_ENHANCEMENT byNoiseReduceMode[%d] "
        "dwGeneralLevel[%d] dwFrameNoiseReduceLevel[%d] "
        "dwInterFrameNoiseReduceLevel[%d] byPaletteMode[%d] "
        "byLSEDetailEnabled[%d] dwLSEDetailLevel[%d]\r\n",
        struImageEnhancement.byNoiseReduceMode,
        struImageEnhancement.dwGeneralLevel,
        struImageEnhancement.dwFrameNoiseReduceLevel,
        struImageEnhancement.dwInterFrameNoiseReduceLevel,
        struImageEnhancement.byPaletteMode,
        struImageEnhancement.byLSEDetailEnabled,
        struImageEnhancement.dwLSEDetailLevel);
  }
}

void Thermal::SetImageEnhancement() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_IMAGE_ENHANCEMENT struImageEnhancement = {0};
  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struImageEnhancement.byNoiseReduceMode = 2;  // 专家模式
  struImageEnhancement.dwGeneralLevel = 50;
  struImageEnhancement.dwFrameNoiseReduceLevel = 50;
  struImageEnhancement.dwInterFrameNoiseReduceLevel = 50;
  struImageEnhancement.byPaletteMode = 1;
  struImageEnhancement.byLSEDetailEnabled = 1;
  struImageEnhancement.dwLSEDetailLevel = 50;
  struConfigInputInfo.lpInBuffer = &struImageEnhancement;
  struConfigInputInfo.dwInBufferSize = sizeof(struImageEnhancement);
  if (!USB_SetDeviceConfig(m_lUserID, USB_SET_IMAGE_ENHANCEMENT,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_IMAGE_ENHANCEMENT ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_SET_IMAGE_ENHANCEMENT byNoiseReduceMode[%d] "
        "dwGeneralLevel[%d] dwFrameNoiseReduceLevel[%d] "
        "dwInterFrameNoiseReduceLevel[%d] byPaletteMode[%d] "
        "byLSEDetailEnabled[%d] dwLSEDetailLevel[%d]\r\n",
        struImageEnhancement.byNoiseReduceMode,
        struImageEnhancement.dwGeneralLevel,
        struImageEnhancement.dwFrameNoiseReduceLevel,
        struImageEnhancement.dwInterFrameNoiseReduceLevel,
        struImageEnhancement.byPaletteMode,
        struImageEnhancement.byLSEDetailEnabled,
        struImageEnhancement.dwLSEDetailLevel);
  }
}

void Thermal::GetImageVideoAdjust() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_IMAGE_VIDEO_ADJUST struImageVideoAdjust = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struImageVideoAdjust;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struImageVideoAdjust);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_IMAGE_VIDEO_ADJUST,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_IMAGE_VIDEO_ADJUST ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_GET_IMAGE_VIDEO_ADJUST byImageFlipStyle[%d] "
        "byPowerLineFrequencyMode[%d] byCorridor[%d]\r\n",
        struImageVideoAdjust.byImageFlipStyle,
        struImageVideoAdjust.byPowerLineFrequencyMode,
        struImageVideoAdjust.byCorridor);
  }
}

void Thermal::SetImageVideoAdjust() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_IMAGE_VIDEO_ADJUST struImageVideoAdjust = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struImageVideoAdjust.byImageFlipStyle = 1;
  struImageVideoAdjust.byPowerLineFrequencyMode = 1;
  struImageVideoAdjust.byCorridor = 1;
  struConfigInputInfo.lpInBuffer = &struImageVideoAdjust;
  struConfigInputInfo.dwInBufferSize = sizeof(struImageVideoAdjust);
  if (!USB_SetDeviceConfig(m_lUserID, USB_SET_IMAGE_VIDEO_ADJUST,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_IMAGE_VIDEO_ADJUST ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_SET_IMAGE_VIDEO_ADJUST byImageFlipStyle[%d] "
        "byPowerLineFrequencyMode[%d] byCorridor[%d]\r\n",
        struImageVideoAdjust.byImageFlipStyle,
        struImageVideoAdjust.byPowerLineFrequencyMode,
        struImageVideoAdjust.byCorridor);
  }
}

void Thermal::GetThermometryBasicParam() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_THERMOMETRY_BASIC_PARAM struThermometryBasicParam = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struThermometryBasicParam;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryBasicParam);
  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_BASIC_PARAM,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_THERMOMETRY_BASIC_PARAM ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_GET_THERMOMETRY_BASIC_PARAM byImageFlipStyle[%d] "
        "byDisplayMaxTemperatureEnabled[%d] "
        "byDisplayMinTemperatureEnabled[%d]\r\n",
        struThermometryBasicParam.byEnabled,
        struThermometryBasicParam.byDisplayMaxTemperatureEnabled,
        struThermometryBasicParam.byDisplayMinTemperatureEnabled);
  }
  std::cout << "USB_THERMOMETRY_BASIC_PARAM Contents:" << std::endl;
  std::cout << "  dwSize: " << struThermometryBasicParam.dwSize << std::endl;
  std::cout << "  byTemperatureRangeAutoChangedEnabled: "
            << static_cast<int>(struThermometryBasicParam
                                    .byTemperatureRangeAutoChangedEnabled)
            << std::endl;
  std::cout << "  byEnabled: "
            << static_cast<int>(struThermometryBasicParam.byEnabled)
            << std::endl;
  std::cout << "  byDisplayMaxTemperatureEnabled: "
            << static_cast<int>(
                   struThermometryBasicParam.byDisplayMaxTemperatureEnabled)
            << std::endl;
  std::cout << "  byDisplayMinTemperatureEnabled: "
            << static_cast<int>(
                   struThermometryBasicParam.byDisplayMinTemperatureEnabled)
            << std::endl;
  std::cout << "  byDisplayAverageTemperatureEnabled: "
            << static_cast<int>(
                   struThermometryBasicParam.byDisplayAverageTemperatureEnabled)
            << std::endl;
  std::cout << "  byTemperatureUnit: "
            << static_cast<int>(struThermometryBasicParam.byTemperatureUnit)
            << std::endl;
  std::cout << "  byTemperatureRange: "
            << static_cast<int>(struThermometryBasicParam.byTemperatureRange)
            << std::endl;
  std::cout << "  byCalibrationCoefficientEnabled: "
            << static_cast<int>(
                   struThermometryBasicParam.byCalibrationCoefficientEnabled)
            << std::endl;
  std::cout << "  dwCalibrationCoefficient: "
            << struThermometryBasicParam.dwCalibrationCoefficient << std::endl;
  std::cout << "  dwExternalOpticsWindowCorrection: "
            << struThermometryBasicParam.dwExternalOpticsWindowCorrection
            << std::endl;
  std::cout << "  dwEmissivity: " << struThermometryBasicParam.dwEmissivity
            << std::endl;
  std::cout << "  byDistanceUnit: "
            << static_cast<int>(struThermometryBasicParam.byDistanceUnit)
            << std::endl;
  std::cout << "  byShowAlarmColorEnabled: "
            << static_cast<int>(
                   struThermometryBasicParam.byShowAlarmColorEnabled)
            << std::endl;
  std::cout << "  byAlarmType: "
            << static_cast<int>(struThermometryBasicParam.byAlarmType)
            << std::endl;
  std::cout << "  byAlarmResult: "
            << static_cast<int>(struThermometryBasicParam.byAlarmRult)
            << std::endl;
  std::cout << "  dwDistance: " << struThermometryBasicParam.dwDistance
            << std::endl;
  std::cout << "  byReflectiveEnable: "
            << static_cast<int>(struThermometryBasicParam.byReflectiveEnable)
            << std::endl;
  std::cout << "  byAutoDrift: "
            << static_cast<int>(struThermometryBasicParam.byAutoDrift)
            << std::endl;
  std::cout << "  bySSECompensation: "
            << static_cast<int>(struThermometryBasicParam.bySSECompensation)
            << std::endl;
  std::cout << "  byThermalRawData: "
            << static_cast<int>(struThermometryBasicParam.byThermalRawData)
            << std::endl;
  std::cout << "  dwReflectiveTemperature: "
            << struThermometryBasicParam.dwReflectiveTemperature << std::endl;
  std::cout << "  byThermomrtryInfoDisplayPosition: "
            << static_cast<int>(
                   struThermometryBasicParam.byThermomrtryInfoDisplayPosition)
            << std::endl;
  std::cout << "  byThermometryStreamOverlay: "
            << static_cast<int>(
                   struThermometryBasicParam.byThermometryStreamOverlay)
            << std::endl;
  std::cout << "  byDisplayCenTempEnabled: "
            << static_cast<int>(
                   struThermometryBasicParam.byDisplayCenTempEnabled)
            << std::endl;
  std::cout << "  byBackcolorEnabled: "
            << static_cast<int>(struThermometryBasicParam.byBackcolorEnabled)
            << std::endl;
  std::cout << "  dwAlert: " << struThermometryBasicParam.dwAlert << std::endl;
  std::cout << "  dwAlarm: " << struThermometryBasicParam.dwAlarm << std::endl;
  std::cout << "  dwExternalOpticsTransmit: "
            << struThermometryBasicParam.dwExternalOpticsTransmit << std::endl;
  std::cout << "  dwTemperatureRangeUpperLimit: "
            << struThermometryBasicParam.dwTemperatureRangeUpperLimit
            << std::endl;
  std::cout << "  dwTemperatureRangeLowerLimit: "
            << struThermometryBasicParam.dwTemperatureRangeLowerLimit
            << std::endl;
  std::cout << "  dwTemperatureRangeExcursionUpperLimit: "
            << struThermometryBasicParam.dwTemperatureRangeExcursionUpperLimit
            << std::endl;
  std::cout << "  dwTemperatureRangeExcursionLowerLimit: "
            << struThermometryBasicParam.dwTemperatureRangeExcursionLowerLimit
            << std::endl;
  std::cout << "  dwAtmosphericHumidity: "
            << struThermometryBasicParam.dwAtmosphericHumidity << std::endl;
  std::cout << "  byFloatTransMode: "
            << static_cast<int>(struThermometryBasicParam.byFloatTransMode)
            << std::endl;
  std::cout << "  byShiftLength: "
            << static_cast<int>(struThermometryBasicParam.byShiftLength)
            << std::endl;
  std::cout << "  byEnvironmentTemperatureEnable: "
            << static_cast<int>(
                   struThermometryBasicParam.byEnviromentTemperatureEnable)
            << std::endl;
  std::cout << "  dwEnvironmentTemperature: "
            << struThermometryBasicParam.dwEnviromentTemperature << std::endl;
}

void Thermal::SetThermometryBasicParam() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_THERMOMETRY_BASIC_PARAM struThermometryBasicParam = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struThermometryBasicParam.byEnabled = 1;  //开启测温功能使能
  struThermometryBasicParam.byDisplayMaxTemperatureEnabled =
      1;  //显示最高温: 0-关闭; 1-开启
  struThermometryBasicParam.byDisplayMinTemperatureEnabled =
      0;  //显示最低温: 0-关闭; 1-开启
  struThermometryBasicParam.byDisplayAverageTemperatureEnabled =
      0;  //显示平均温: 0-关闭; 1-开启
  struThermometryBasicParam.byTemperatureUnit =
      1;  //温度单位: 1 - 摄氏温度;2 - 华氏温度;3 -
          //开尔文温度(协议传输中约定以摄氏温度作为单位传输)
  struThermometryBasicParam.byTemperatureRange =
      2;  //测温范围: 1- 30~45  2- -20~150     3- 0~400
  struThermometryBasicParam.byCalibrationCoefficientEnabled =
      0;  //启用标定系数:0 - 关闭;1 - 开启
  struThermometryBasicParam.dwCalibrationCoefficient =
      2;  //标定系数: 0.00~30.00 ,传输时实际值 * 100换算成整数
  struThermometryBasicParam.dwExternalOpticsWindowCorrection =
      1100;  //外部光学温度: -40.0~80.0℃ ,传输时(实际值 + 100) * 10换算成正整数
  struThermometryBasicParam.dwEmissivity =
      98;  //发射率: 0.01~1(精确到小数点后两位), 传输时实际值 * 100换算成整数
  struThermometryBasicParam.byDistanceUnit =
      2;  //距离单位: 1 - 米; 2 - 厘米; 3 - 英尺
  struThermometryBasicParam.dwDistance =
      100;  //距离: 0.3-2m（协议传输中约定以cm作为单位传输, 精确到小数点后1位）
  struThermometryBasicParam.byReflectiveEnable =
      0;  //反射温度使能: 0 - 关闭; 1 - 开启
  struThermometryBasicParam.dwReflectiveTemperature =
      1100;  //反射温度: -100.0~1000.0℃（精确到小数点后1位）,传输时(实际值 +
             //100) * 10换算成正整数
  struThermometryBasicParam.byThermomrtryInfoDisplayPosition =
      1;  //测温信息显示位置: 1-跟随规则 2-屏幕左上角
  struThermometryBasicParam.byThermometryStreamOverlay =
      2;  //码流叠加温度信息: 1-不叠加  2-叠加
  struThermometryBasicParam.dwAlert =
      1000;  //预警温度: -20℃~400℃, 传输时(实际值+100)*10换算成正整数
  struThermometryBasicParam.dwAlarm =
      2000;  //报警温度: -20℃~400℃, 传输时(实际值+100)*10换算成正整数
  struThermometryBasicParam.dwExternalOpticsTransmit =
      50;  //外部光学透过率: 0.01~1(精确到小数点后两位),
           //传输时实际值*100换算成整数
  struThermometryBasicParam.byDisplayCenTempEnabled =
      1;  //显示中心温：0-关闭   1-开启
  struThermometryBasicParam.byBackcolorEnabled = 1;  //显示背景色：0-关闭 1-开启
  struThermometryBasicParam.byShowAlarmColorEnabled =
      1;  //报警颜色显示使能: 0-关闭  1-开启

  struConfigOutputInfo.lpOutBuffer = &struThermometryBasicParam;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryBasicParam);
  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_BASIC_PARAM,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_THERMOMETRY_BASIC_PARAM ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    struConfigInputInfo.lpInBuffer = &struThermometryBasicParam;
    struConfigInputInfo.dwInBufferSize = sizeof(struThermometryBasicParam);
    if (!USB_GetDeviceConfig(m_lUserID, USB_SET_THERMOMETRY_BASIC_PARAM,
                             &struConfigInputInfo, &struConfigOutputInfo)) {
      DWORD dwError = USB_GetLastError();
      printf(
          "FAILED USB_SET_THERMOMETRY_BASIC_PARAM ErrorCode = [%d], ErrorMsg = "
          "[%s]\r\n",
          dwError, USB_GetErrorMsg(dwError));
    } else {
      printf(
          "SUCCESS  USB_SET_THERMOMETRY_BASIC_PARAM byImageFlipStyle[%d] "
          "byDisplayMaxTemperatureEnabled[%d] "
          "byDisplayMinTemperatureEnabled[%d]\r\n",
          struThermometryBasicParam.byEnabled,
          struThermometryBasicParam.byDisplayMaxTemperatureEnabled,
          struThermometryBasicParam.byDisplayMinTemperatureEnabled);
    }
  }
}

void Thermal::GetThermometryMode() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_THERMOMETRY_MODE struThermometryMode = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struThermometryMode;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryMode);
  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_MODE,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_THERMOMETRY_MODE ErrorCode = [%d], ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_GET_THERMOMETRY_MODE byThermometryMode[%d] "
        "byThermometryROIEnabled[%d]\r\n",
        struThermometryMode.byThermometryMode,
        struThermometryMode.byThermometryROIEnabled);
  }
}

void Thermal::SetThermometryMode() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_THERMOMETRY_MODE struThermometryMode = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struThermometryMode.byThermometryMode = 1;  //专家
  struThermometryMode.byThermometryROIEnabled = 2;
  struConfigInputInfo.lpInBuffer = &struThermometryMode;
  struConfigInputInfo.dwInBufferSize = sizeof(struThermometryMode);
  if (!USB_SetDeviceConfig(m_lUserID, USB_SET_THERMOMETRY_MODE,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_THERMOMETRY_MODE ErrorCode = [%d], ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_SET_THERMOMETRY_MODE byThermometryMode[%d] "
        "byThermometryROIEnabled[%d]\r\n",
        struThermometryMode.byThermometryMode,
        struThermometryMode.byThermometryROIEnabled);
  }
}

void Thermal::GetThermometryRegions() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_THERMOMETRY_REGIONS struThermometryRegions = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struThermometryRegions;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryRegions);
  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_REGIONS,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_THERMOMETRY_REGIONS ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS  USB_GET_THERMOMETRY_REGIONS byRegionNum[%d]\r\n",
           struThermometryRegions.byRegionNum);
  }
}

void Thermal::SetThermometryRegions() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_THERMOMETRY_REGIONS struThermometryRegions = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struThermometryRegions;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryRegions);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_REGIONS,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_THERMOMETRY_REGIONS ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    struConfigInputInfo.lpInBuffer = &struThermometryRegions;
    struConfigInputInfo.dwInBufferSize = sizeof(struThermometryRegions);

    if (!USB_SetDeviceConfig(m_lUserID, USB_SET_THERMOMETRY_REGIONS,
                             &struConfigInputInfo, &struConfigOutputInfo)) {
      DWORD dwError = USB_GetLastError();
      printf(
          "FAILED USB_SET_THERMOMETRY_REGIONS ErrorCode = [%d], ErrorMsg = "
          "[%s]\r\n",
          dwError, USB_GetErrorMsg(dwError));
    } else {
      printf("SUCCESS  USB_SET_THERMOMETRY_REGIONS byRegionNum[%d]\r\n",
             struThermometryRegions.byRegionNum);
    }
  }
}

void Thermal::GetTemperatureCorrect() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_TEMPERATURE_CORRECT struTemperatureCorrect = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struTemperatureCorrect;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struTemperatureCorrect);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_TEMPERATURE_CORRECT,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_TEMPERATURE_CORRECT ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS  USB_GET_TEMPERATURE_CORRECT dwSize[%d] byEnabled[%d]\r\n",
           struTemperatureCorrect.dwSize, struTemperatureCorrect.byEnabled);
  }
}

void Thermal::SetTemperatureCorrect() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_TEMPERATURE_CORRECT struTemperatureCorrect = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struTemperatureCorrect;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struTemperatureCorrect);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_TEMPERATURE_CORRECT,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_TEMPERATURE_CORRECT ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    struConfigInputInfo.lpInBuffer = &struTemperatureCorrect;
    struConfigInputInfo.dwInBufferSize = sizeof(struTemperatureCorrect);

    if (!USB_SetDeviceConfig(m_lUserID, USB_SET_TEMPERATURE_CORRECT,
                             &struConfigInputInfo, &struConfigOutputInfo)) {
      DWORD dwError = USB_GetLastError();
      printf(
          "FAILED USB_SET_TEMPERATURE_CORRECT ErrorCode = [%d], ErrorMsg = "
          "[%s]\r\n",
          dwError, USB_GetErrorMsg(dwError));
    } else {
      printf(
          "SUCCESS  USB_SET_TEMPERATURE_CORRECT dwSize[%d] byEnabled[%d]\r\n",
          struTemperatureCorrect.dwSize, struTemperatureCorrect.byEnabled);
    }
  }
}

void Thermal::GetBlackBody() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_BLACK_BODY struBlackBody = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struBlackBody;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struBlackBody);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_BLACK_BODY, &struConfigInputInfo,
                           &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf("FAILED USB_GET_BLACK_BODY ErrorCode = [%d], ErrorMsg = [%s]\r\n",
           dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS  USB_GET_BLACK_BODY dwSize[%d] byEnabled[%d]\r\n",
           struBlackBody.dwSize, struBlackBody.byEnabled);
  }
}

void Thermal::SetBlackBody() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_BLACK_BODY struBlackBody = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struBlackBody;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struBlackBody);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_BLACK_BODY, &struConfigInputInfo,
                           &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf("FAILED USB_GET_BLACK_BODY ErrorCode = [%d], ErrorMsg = [%s]\r\n",
           dwError, USB_GetErrorMsg(dwError));
  } else {
    struConfigInputInfo.lpInBuffer = &struBlackBody;
    struConfigInputInfo.dwInBufferSize = sizeof(struBlackBody);

    if (!USB_SetDeviceConfig(m_lUserID, USB_SET_BLACK_BODY,
                             &struConfigInputInfo, &struConfigOutputInfo)) {
      DWORD dwError = USB_GetLastError();
      printf("FAILED USB_SET_BLACK_BODY ErrorCode = [%d], ErrorMsg = [%s]\r\n",
             dwError, USB_GetErrorMsg(dwError));
    } else {
      printf("SUCCESS  USB_SET_BLACK_BODY dwSize[%d] byEnabled[%d]\r\n",
             struBlackBody.dwSize, struBlackBody.byEnabled);
    }
  }
}

void Thermal::GetBodytempCompensation() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_BODYTEMP_COMPENSATION struBodytempCompensation = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struBodytempCompensation;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struBodytempCompensation);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_BODYTEMP_COMPENSATION,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_BODYTEMP_COMPENSATION ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_GET_BODYTEMP_COMPENSATION dwSize[%d] byEnabled[%d]\r\n",
        struBodytempCompensation.dwSize, struBodytempCompensation.byEnabled);
  }
}

void Thermal::SetBodytempCompensation() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_BODYTEMP_COMPENSATION struBodytempCompensation = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struBodytempCompensation;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struBodytempCompensation);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_BODYTEMP_COMPENSATION,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_BODYTEMP_COMPENSATION ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    struConfigInputInfo.lpInBuffer = &struBodytempCompensation;
    struConfigInputInfo.dwInBufferSize = sizeof(struBodytempCompensation);

    if (!USB_SetDeviceConfig(m_lUserID, USB_SET_BODYTEMP_COMPENSATION,
                             &struConfigInputInfo, &struConfigOutputInfo)) {
      DWORD dwError = USB_GetLastError();
      printf(
          "FAILED USB_SET_BODYTEMP_COMPENSATION ErrorCode = [%d], ErrorMsg = "
          "[%s]\r\n",
          dwError, USB_GetErrorMsg(dwError));
    } else {
      printf(
          "SUCCESS  USB_SET_BODYTEMP_COMPENSATION dwSize[%d] byEnabled[%d]\r\n",
          struBodytempCompensation.dwSize, struBodytempCompensation.byEnabled);
    }
  }
}

void Thermal::GetRoiMaxTemperatureSearch() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_ROI_MAX_TEMPERATURE_SEARCH struRoiMaxTemperatureSearch = {0};
  USB_ROI_MAX_TEMPERATURE_SEARCH_RESULT struRoiMaxTemperatureSearchResult = {0};

  char *pData = new char[BUFFER_LEN];
  if (NULL == pData) {
    return;
  }
  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struRoiMaxTemperatureSearch.byJpegPicEnabled = 1;
  struRoiMaxTemperatureSearch.byMaxTemperatureOverlay = 1;
  struRoiMaxTemperatureSearch.byRegionsOverlay = 1;
  struRoiMaxTemperatureSearch.byROIRegionNum = 2;
  struRoiMaxTemperatureSearch.struThermalROIRegion[0].byROIRegionID = 1;
  struRoiMaxTemperatureSearch.struThermalROIRegion[0].byROIRegionEnabled = 1;
  struRoiMaxTemperatureSearch.struThermalROIRegion[0].dwROIRegionX = 0;
  struRoiMaxTemperatureSearch.struThermalROIRegion[0].dwROIRegionY = 0;
  struRoiMaxTemperatureSearch.struThermalROIRegion[0].dwROIRegionHeight = 50;
  struRoiMaxTemperatureSearch.struThermalROIRegion[0].dwROIRegionWidth = 150;
  struRoiMaxTemperatureSearch.struThermalROIRegion[0].dwDistance = 50;

  struRoiMaxTemperatureSearch.struThermalROIRegion[1].byROIRegionID = 2;
  struRoiMaxTemperatureSearch.struThermalROIRegion[1].byROIRegionEnabled = 1;
  struRoiMaxTemperatureSearch.struThermalROIRegion[1].dwROIRegionX = 70;
  struRoiMaxTemperatureSearch.struThermalROIRegion[1].dwROIRegionY = 110;
  struRoiMaxTemperatureSearch.struThermalROIRegion[1].dwROIRegionHeight = 10;
  struRoiMaxTemperatureSearch.struThermalROIRegion[1].dwROIRegionWidth = 10;
  struRoiMaxTemperatureSearch.struThermalROIRegion[1].dwDistance = 100;

  //查询参数
  struConfigInputInfo.lpInBuffer = &struRoiMaxTemperatureSearch;
  struConfigInputInfo.dwInBufferSize = sizeof(struRoiMaxTemperatureSearch);

  struRoiMaxTemperatureSearchResult.pJpegPic = (BYTE *)pData;
  struRoiMaxTemperatureSearchResult.dwJpegPicLen = BUFFER_LEN;
  //查询结果
  struConfigOutputInfo.lpOutBuffer = &struRoiMaxTemperatureSearchResult;
  struConfigOutputInfo.dwOutBufferSize =
      sizeof(struRoiMaxTemperatureSearchResult);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_ROI_MAX_TEMPERATURE_SEARCH,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_ROI_MAX_TEMPERATURE_SEARCH ErrorCode = [%d], ErrorMsg "
        "= [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    if (struRoiMaxTemperatureSearchResult.dwJpegPicLen > 0) {
      FILE *fd = NULL;
      fd = fopen("../Log/ROI_Max.jpg", "wb");
      fwrite((void *)struRoiMaxTemperatureSearchResult.pJpegPic, 1,
             struRoiMaxTemperatureSearchResult.dwJpegPicLen, fd);
      fclose(fd);
      fd = NULL;
    }
    printf(
        "SUCCESS  USB_GET_ROI_MAX_TEMPERATURE_SEARCH dwSize[%d] "
        "dwJpegPicLen[%d]\r\n",
        struRoiMaxTemperatureSearchResult.dwSize,
        struRoiMaxTemperatureSearchResult.dwJpegPicLen);
  }
  delete[] pData;
  pData = NULL;
}

void Thermal::GetP2PParam() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_P2P_PARAM struP2pParam = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
  struConfigOutputInfo.lpOutBuffer = &struP2pParam;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struP2pParam);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_P2P_PARAM, &struConfigInputInfo,
                           &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf("FAILED USB_GET_P2P_PARAM ErrorCode = [%d], ErrorMsg = [%s]\r\n",
           dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS  USB_GET_P2P_PARAM dwSize[%d] byJpegPicEnabled[%d]\r\n",
           struP2pParam.dwSize, struP2pParam.byJpegPicEnabled);
  }
}

void Thermal::SetP2PParam() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_P2P_PARAM struP2pParam = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struP2pParam.byJpegPicEnabled = 1;
  struConfigInputInfo.lpInBuffer = &struP2pParam;
  struConfigInputInfo.dwInBufferSize = sizeof(struP2pParam);
  if (!USB_SetDeviceConfig(m_lUserID, USB_SET_P2P_PARAM, &struConfigInputInfo,
                           &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf("FAILED USB_SET_P2P_PARAM ErrorCode = [%d], ErrorMsg = [%s]\r\n",
           dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS  USB_SET_P2P_PARAM dwSize[%d] byJpegPicEnabled[%d]\r\n",
           struP2pParam.dwSize, struP2pParam.byJpegPicEnabled);
  }
}

void Thermal::GetCommandState() {
  USB_COMMAND_STATE struCommandState = {0};
  struCommandState.dwSize = sizeof(struCommandState);

  if (!USB_GetCommandState(m_lUserID, &struCommandState)) {
    DWORD dwError = USB_GetLastError();
    printf("FAILED USB_GetCommandState ErrorCode = [%d], ErrorMsg = [%s]\r\n",
           dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_GetCommandState byState[%d]\r\n",
           struCommandState.byState);
  }
}

void Thermal::GetThermalAlgVersion() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_THERMAL_ALG_VERSION struThermalAlgVersion = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struThermalAlgVersion;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struThermalAlgVersion);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMAL_ALG_VERSION,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_THERMAL_ALG_VERSION ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_GET_THERMOMETRY_REGIONS dwSize[%d] "
        "byThermometryAlgName[%s]\r\n",
        struThermalAlgVersion.dwSize,
        struThermalAlgVersion.byThermometryAlgName);
  }
}

void Thermal::SetImageBackgroundCorrect() {
  USB_COMMON_COND struCond = {0};
  USB_CONTROL_INPUT_INFO struControlInputInfo = {0};

  struCond.byChannelID = 1;
  struControlInputInfo.lpCondBuffer = &struCond;
  struControlInputInfo.dwCondBufferSize = sizeof(struCond);
  if (!USB_Control(m_lUserID, USB_SET_IMAGE_BACKGROUND_CORRECT,
                   &struControlInputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_IMAGE_BACKGROUND_CORRECT ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_SET_IMAGE_BACKGROUND_CORRECT\r\n");
  }
}

void Thermal::SetImageManualCorrect() {
  USB_COMMON_COND struCond = {0};
  USB_CONTROL_INPUT_INFO struControlInputInfo = {0};

  struCond.byChannelID = 1;
  struControlInputInfo.lpCondBuffer = &struCond;
  struControlInputInfo.dwCondBufferSize = sizeof(struCond);
  if (!USB_Control(m_lUserID, USB_SET_IMAGE_MANUAL_CORRECT,
                   &struControlInputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_IMAGE_MANUAL_CORRECT ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_SET_IMAGE_MANUAL_CORRECT\r\n");
  }
}

/*用不到*/
void Thermal::GetDoubleLightsCorrectPointsCtrl() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL struDoubleLightsCorrectPointsCtrl = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);
  struConfigOutputInfo.lpOutBuffer = &struDoubleLightsCorrectPointsCtrl;
  struConfigOutputInfo.dwOutBufferSize =
      sizeof(struDoubleLightsCorrectPointsCtrl);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL ErrorCode = [%d], "
        "ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_GET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL dwSize[%d] "
        "byDoubleLightsCorrectPointsEnabled[%d]\r\n",
        struDoubleLightsCorrectPointsCtrl.dwSize,
        struDoubleLightsCorrectPointsCtrl.byDoubleLightsCorrectPointsEnabled);
  }
}

void Thermal::SetDoubleLightsCorrectPointCtrl() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL struDoubleLightsCorrectPointsCtrl = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struDoubleLightsCorrectPointsCtrl.byDoubleLightsCorrectPointsEnabled = 1;
  struConfigInputInfo.lpInBuffer = &struDoubleLightsCorrectPointsCtrl;
  struConfigInputInfo.dwInBufferSize =
      sizeof(struDoubleLightsCorrectPointsCtrl);

  if (!USB_SetDeviceConfig(m_lUserID, USB_SET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL ErrorCode = [%d], "
        "ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_SET_DOUBLE_LIGHTS_CORRECT_POINTS_CTRL dwSize[%d] "
        "byDoubleLightsCorrectPointsEnabled[%d]\r\n",
        struDoubleLightsCorrectPointsCtrl.dwSize,
        struDoubleLightsCorrectPointsCtrl.byDoubleLightsCorrectPointsEnabled);
  }
}

/*用不到*/
void Thermal::GetThermometryCalibrationFile() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_THERMOMETRY_CALIBRATION_FILE struThermometryCalibrationFile = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  // struConfigInputInfo.lpInBuffer = &struThermometryCalibrationFile;
  // struConfigInputInfo.dwInBufferSize =
  // sizeof(struThermometryCalibrationFile);

  struConfigOutputInfo.lpOutBuffer = &struThermometryCalibrationFile;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struThermometryCalibrationFile);
  BYTE *pData = new BYTE[BUFFER_LEN];
  if (NULL == pData) {
    return;
  }
  struThermometryCalibrationFile.pCalibrationFile = pData;
  struThermometryCalibrationFile.dwFileLenth = BUFFER_LEN;

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMOMETRY_CALIBRATION_FILE,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_THERMOMETRY_CALIBRATION_FILE ErrorCode = [%d], "
        "ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    if (struThermometryCalibrationFile.dwFileLenth > 0) {
      FILE *fd = NULL;
      fd = fopen("../Log/Calibration.dat", "wb");
      fwrite((void *)struThermometryCalibrationFile.pCalibrationFile, 1,
             struThermometryCalibrationFile.dwFileLenth, fd);
      fclose(fd);
      fd = NULL;
    }
    printf(
        "SUCCESS  USB_GET_THERMOMETRY_CALIBRATION_FILE dwSize[%d] "
        "dwFileLenth[%d]\r\n",
        struThermometryCalibrationFile.dwSize,
        struThermometryCalibrationFile.dwFileLenth);
  }
  delete[] pData;
  pData = NULL;
}

void Thermal::SetThermometryCalibrationFile() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_THERMOMETRY_CALIBRATION_FILE struThermometryCalibrationFile = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  //可见光图片   ?????
  FILE *fd = NULL;
  int iReadSize = 0;
  char *pData = new char[BUFFER_LEN];
  if (NULL == pData) {
    return;
  }
  fd = fopen("../Log/Calibration.dat", "rb");
  fseek(fd, 0, SEEK_END);
  iReadSize = ftell(fd);
  fseek(fd, 0, SEEK_SET);
  fread(pData, 1, iReadSize, fd);
  fclose(fd);
  fd = NULL;
  struThermometryCalibrationFile.pCalibrationFile = (BYTE *)pData;
  struThermometryCalibrationFile.dwFileLenth = iReadSize;
  sprintf((char *)struThermometryCalibrationFile.byFileName, "Calibration.dat");
  struConfigInputInfo.lpInBuffer = &struThermometryCalibrationFile;
  struConfigInputInfo.dwInBufferSize = sizeof(struThermometryCalibrationFile);

  // struConfigOutputInfo.lpOutBuffer = &struThermometryCalibrationFile;
  // struConfigOutputInfo.dwOutBufferSize =
  // sizeof(struThermometryCalibrationFile);

  if (!USB_GetDeviceConfig(m_lUserID, USB_SET_THERMOMETRY_CALIBRATION_FILE,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_THERMOMETRY_CALIBRATION_FILE ErrorCode = [%d], "
        "ErrorMsg = [%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_SET_THERMOMETRY_CALIBRATION_FILE dwSize[%d] "
        "dwFileLenth[%d]\r\n",
        struThermometryCalibrationFile.dwSize,
        struThermometryCalibrationFile.dwFileLenth);
  }
  delete[] pData;
  pData = NULL;
}

void Thermal::PostDoubleLightsCorrect() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_DOUBLE_LIGHTS_CORRECT struDoubleLightsCorrect = {0};
  USB_DOUBLE_LIGHTS_CORRECT_RESULT struDoubleLightsCorrectResult = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  //可见光图片
  FILE *fd = NULL;
  int iReadSize = 0;
  BYTE *pData = new BYTE[BUFFER_LEN];
  if (NULL == pData) {
    return;
  }
  fd = fopen("../Log/1080p.jpg", "rb");
  fseek(fd, 0, SEEK_END);
  iReadSize = ftell(fd);
  fseek(fd, 0, SEEK_SET);
  fread(pData, 1, iReadSize, fd);

  struDoubleLightsCorrect.pVisiblePic = pData;
  struDoubleLightsCorrect.dwVisiblePicLen = iReadSize;

  fclose(fd);
  fd = NULL;
  struDoubleLightsCorrect.byVisiblePicHorizontalScale = 20;
  struDoubleLightsCorrect.byVisiblePicVerticalScale = 118;
  struDoubleLightsCorrect.wHorizontalCalibrationOffset = 1;
  struDoubleLightsCorrect.wVerticalCalibrationOffset = 1;
  struDoubleLightsCorrect.dwVisibleFocusDistance = 4;
  struDoubleLightsCorrect.dwVisiblePixelInterval = 2;
  struDoubleLightsCorrect.dwHorizontalCenterDistance = 50;
  struDoubleLightsCorrect.dwVerticalCenterDistance = 15;
  struDoubleLightsCorrect.dwCalibrationDistance = 100;

  struConfigInputInfo.lpInBuffer = &struDoubleLightsCorrect;
  struConfigInputInfo.dwInBufferSize = sizeof(struDoubleLightsCorrect);

  struConfigOutputInfo.lpOutBuffer = &struDoubleLightsCorrectResult;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struDoubleLightsCorrectResult);
  struDoubleLightsCorrectResult.pJpegPic = pData;
  struDoubleLightsCorrectResult.dwJpegPicLen = BUFFER_LEN;

  if (!USB_GetDeviceConfig(m_lUserID, USB_POST_DOUBLE_LIGHTS_CORRECT,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_POST_DOUBLE_LIGHTS_CORRECT ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    if (struDoubleLightsCorrectResult.dwJpegPicLen > 0) {
      FILE *fd = NULL;
      fd = fopen("../Log/double.jpg", "wb");
      fwrite((void *)struDoubleLightsCorrectResult.pJpegPic, 1,
             struDoubleLightsCorrectResult.dwJpegPicLen, fd);
      fclose(fd);
      fd = NULL;
    }
    printf(
        "SUCCESS  USB_POST_DOUBLE_LIGHTS_CORRECT dwSize[%d] "
        "dwJpegPicLen[%d]\r\n",
        struDoubleLightsCorrectResult.dwSize,
        struDoubleLightsCorrectResult.dwJpegPicLen);
  }
  delete[] pData;
  pData = NULL;
}

/*数据传输*/
void Thermal::GetThermalStreamParam() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_THERMAL_STREAM_PARAM struThermalStreamParam = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struThermalStreamParam;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struThermalStreamParam);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_THERMAL_STREAM_PARAM,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_THERMAL_STREAM_PARAM ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_GET_THERMAL_STREAM_PARAM dwSize[%d] "
        "byVideoCodingType[%d]\r\n",
        struThermalStreamParam.dwSize,
        struThermalStreamParam.byVideoCodingType);
  }
}

void Thermal::SetThermalStreamParam() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_THERMAL_STREAM_PARAM struThermalStreamParam = {0};

  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struThermalStreamParam.byVideoCodingType = 3;
  struThermalStreamParam.dwFrameRate = 25;
  struThermalStreamParam.dwWidth = 256;
  struThermalStreamParam.dwHeight = 192;
  struConfigInputInfo.lpInBuffer = &struThermalStreamParam;
  struConfigInputInfo.dwInBufferSize = sizeof(struThermalStreamParam);
  struThermalStreamParam.dwSize = sizeof(struThermalStreamParam);

  if (!USB_SetDeviceConfig(m_lUserID, USB_SET_THERMAL_STREAM_PARAM,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_SET_THERMAL_STREAM_PARAM ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    printf(
        "SUCCESS  USB_SET_THERMAL_STREAM_PARAM dwSize[%d] "
        "byVideoCodingType[%d]\r\n",
        struThermalStreamParam.dwSize,
        struThermalStreamParam.byVideoCodingType);
  }
}

void Thermal::GetJpegpicWithAppenddata() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_JPEGPIC_WITH_APPENDDATA struJpegpicWithAppendData = {0};
  char *pData = new char[BUFFER_LEN];
  if (NULL == pData) {
    return;
  }
  char *pData2 = new char[BUFFER_LEN];
  if (NULL == pData2) {
    return;
  }
  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struJpegpicWithAppendData.dwJpegPicWidth = 256;
  struJpegpicWithAppendData.dwJpegPicHeight = 192;
  struJpegpicWithAppendData.pP2pData = (BYTE *)pData;
  struJpegpicWithAppendData.dwP2pDataLen = BUFFER_LEN;
  struJpegpicWithAppendData.pJpegPic = (BYTE *)pData2;
  struJpegpicWithAppendData.dwJpegPicLen = BUFFER_LEN;
  struConfigOutputInfo.lpOutBuffer = &struJpegpicWithAppendData;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struJpegpicWithAppendData);

  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_JPEGPIC_WITH_APPENDDATA,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_JPEGPIC_WITH_APPENDDATA ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    if (struJpegpicWithAppendData.dwJpegPicLen > 0) {
      FILE *fd = NULL;
      fd = fopen("../Log/append.jpg", "wb");
      fwrite((void *)struJpegpicWithAppendData.pJpegPic, 1,
             struJpegpicWithAppendData.dwJpegPicLen, fd);
      fclose(fd);
      fd = NULL;
    }
    printf(
        "SUCCESS  USB_GET_JPEGPIC_WITH_APPENDDATA dwSize[%d] "
        "dwJpegPicLen[%d]\r\n",
        struJpegpicWithAppendData.dwSize,
        struJpegpicWithAppendData.dwJpegPicLen);
    if (struJpegpicWithAppendData.dwP2pDataLen > 0) {
      FILE *fd = NULL;
      fd = fopen("../Log/p2p.bin", "wb");
      fwrite((void *)struJpegpicWithAppendData.pP2pData, 1,
             struJpegpicWithAppendData.dwP2pDataLen, fd);
      fclose(fd);
      fd = NULL;
    }
  }
  std::cout << "Structure Content:" << std::endl;
  std::cout << "  dwSize: " << struJpegpicWithAppendData.dwSize << std::endl;
  std::cout << "  dwJpegPicLen: " << struJpegpicWithAppendData.dwJpegPicLen
            << std::endl;
  std::cout << "  dwJpegPicWidth: " << struJpegpicWithAppendData.dwJpegPicWidth
            << std::endl;
  std::cout << "  dwJpegPicHeight: "
            << struJpegpicWithAppendData.dwJpegPicHeight << std::endl;
  std::cout << "  dwP2pDataLen: " << struJpegpicWithAppendData.dwP2pDataLen
            << std::endl;
  std::cout << "  byIsFreezedata: "
            << static_cast<int>(struJpegpicWithAppendData.byIsFreezedata)
            << std::endl;
  std::cout << "  byTemperatureDataLength: "
            << static_cast<int>(
                   struJpegpicWithAppendData.byTemperatureDataLength)
            << std::endl;
  delete[] pData;
  pData = NULL;
  delete[] pData2;
  pData2 = NULL;
}

void Thermal::GetSystemDiagnoseData() {
  USB_CONFIG_INPUT_INFO struConfigInputInfo = {0};
  USB_CONFIG_OUTPUT_INFO struConfigOutputInfo = {0};
  USB_COMMON_COND struCond = {0};
  USB_SYSTEM_DIAGNOSED_DATA struSysDiagnosedData = {0};
  BYTE *pData = new BYTE[BUFFER_LEN];
  if (NULL == pData) {
    return;
  }
  struCond.byChannelID = 1;
  struConfigInputInfo.lpCondBuffer = &struCond;
  struConfigInputInfo.dwCondBufferSize = sizeof(struCond);

  struConfigOutputInfo.lpOutBuffer = &struSysDiagnosedData;
  struConfigOutputInfo.dwOutBufferSize = sizeof(struSysDiagnosedData);

  struSysDiagnosedData.pDiagnosedData = pData;
  struSysDiagnosedData.dwDataLenth = BUFFER_LEN;
  if (!USB_GetDeviceConfig(m_lUserID, USB_GET_SYSTEM_DIAGNOSED_DATA,
                           &struConfigInputInfo, &struConfigOutputInfo)) {
    DWORD dwError = USB_GetLastError();
    printf(
        "FAILED USB_GET_SYSTEM_DIAGNOSED_DATA ErrorCode = [%d], ErrorMsg = "
        "[%s]\r\n",
        dwError, USB_GetErrorMsg(dwError));
  } else {
    if (struSysDiagnosedData.dwDataLenth > 0) {
      FILE *fd = NULL;
      fd = fopen("../Log/DiagnoseInformation.txt", "w");
      fwrite((void *)struSysDiagnosedData.pDiagnosedData, 1,
             struSysDiagnosedData.dwDataLenth, fd);
      fclose(fd);
      fd = NULL;
    }
    printf("SUCCESS  USB_GET_SYSTEM_DIAGNOSED_DATA dwDataLenth[%d]\r\n",
           struSysDiagnosedData.dwDataLenth);
  }
  delete[] pData;
  pData = NULL;
}

/*基本功能*/
void Thermal::SetSystemReboot() {
  if (!USB_Control(m_lUserID, USB_SET_SYSTEM_REBOOT, NULL)) {
    DWORD dwError = USB_GetLastError();
    printf("FAILED USB_SET_SYSTEM_REBOOT ErrorCode = [%d], ErrorMsg = [%s]\r\n",
           dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_SET_SYSTEM_REBOOT\r\n");
  }
}

void Thermal::SetSystemReset() {
  if (!USB_Control(m_lUserID, USB_SET_SYSTEM_RESET, NULL)) {
    DWORD dwError = USB_GetLastError();
    printf("FAILED USB_SET_SYSTEM_RESET ErrorCode = [%d], ErrorMsg = [%s]\r\n",
           dwError, USB_GetErrorMsg(dwError));
  } else {
    printf("SUCCESS USB_SET_SYSTEM_RESET\r\n");
  }
}
