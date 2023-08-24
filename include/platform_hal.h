/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2016 RDK Management
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
*/

/**********************************************************************
   Copyright [2014] [Cisco Systems, Inc.]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
**********************************************************************/

/**********************************************************************

    module: platform_hal.h

        For CCSP Component:  CcspCMAgent

    ---------------------------------------------------------------

    description:

        This header file gives the function call prototypes and
        structure definitions used for the RDK-Broadband
        hardware abstraction layer for platform

    ---------------------------------------------------------------

    environment:

        This HAL layer is intended to support platform drivers
        through an open API.
        Changes may be needed to support different hardware enviornments.

    ---------------------------------------------------------------

    author:

        Cisco

**********************************************************************/
/**
* @file platform_hal.h
* @author Cisco
* @brief For CCSP Component:  CcspPandM
*
* @description This header file gives the function call prototypes and structure definitions used for the RDK-Broadband hardware abstraction layer for platform.
*/


#ifndef __PLATFORM_HAL_H__
#define __PLATFORM_HAL_H__

/**
* @defgroup platform_hal Platform HAL
*
* @defgroup PLATFORM_HAL_TYPES  Platform HAL Data Types
* @ingroup  platform_hal
*
* @defgroup PLATFORM_HAL_APIS   Platform HAL  APIs
* @ingroup  platform_hal
*
**/


/**
 * @addtogroup PLATFORM_HAL_TYPES
 * @{
 */


/**********************************************************************
               CONSTANT DEFINITIONS
**********************************************************************/
#ifdef __cplusplus
extern "C"{
#endif

#ifndef CHAR
#define CHAR  char
#endif

#ifndef UCHAR
#define UCHAR unsigned char
#endif

#ifndef BOOLEAN
#define BOOLEAN  unsigned char
#endif

#ifndef INT
#define INT   int
#endif

#ifndef UINT
#define UINT  unsigned int
#endif

#ifndef ULONG
#define ULONG unsigned long
#endif



#ifndef UINT64_t
#define UINT64_t unsigned long long
#endif

#ifndef TRUE
#define TRUE     1
#endif

#ifndef FALSE
#define FALSE    0
#endif

#ifndef ENABLE
#define ENABLE   1
#endif

#ifndef RETURN_OK
#define RETURN_OK   0
#endif

#ifndef RETURN_ERR
#define RETURN_ERR   -1
#endif

/**
 * @}
 */

//DHCPv6 Options
#define DHCPV6_OPT_82  82  // OPTION_SOL_MAX_RT: Solicite Maximum Retry Time
#define DHCPV6_OPT_23  23  // OPTION_SOL_MAX_RT: Solicite Maximum Retry Time
#define DHCPV6_OPT_95  95  // OPTION_SOL_MAX_RT: Solicite Maximum Retry Time
#define DHCPV6_OPT_24  24  // OPTION_DOMAIN_LIST
#define DHCPV6_OPT_83  83  // OPTION_INF_MAX_RT
#define DHCPV6_OPT_17  17  // OPTION_VENDOR_OPTS
#define DHCPV6_OPT_31  31  // OPTION_SNTP_SERVERS
#define DHCPV6_OPT_15  15  // User Class Option
#define DHCPV6_OPT_16  16  // Vendor Class Option
#define DHCPV6_OPT_20  20  // Reconfigure Accept Option


//DHCPv4 Options
#define DHCPV4_OPT_42  42  // NTP Server Addresses
#define DHCPV4_OPT_43  43  // Vendor Specific Information
#define DHCPV4_OPT_58  58  // DHCP Renewal (T1) Time
#define DHCPV4_OPT_59  59  // DHCP Rebinding (T2) Time
#define DHCPV4_OPT_60  60  // Class Identifier
#define DHCPV4_OPT_61  61  // Client Identifier
#define DHCPV4_OPT_100 100 // IEEE 1003.1 TZ String
#define DHCPV4_OPT_122 122 // CableLabs Client Configuration
#define DHCPV4_OPT_125 125 // Vendor-Identifying Vendor-Specific Information
#define DHCPV4_OPT_242 242 // Private Use
#define DHCPV4_OPT_243 243 // Private Use
#define DHCPV4_OPT_END 255 // DHCP Option End - used to check if option is valid

#define FW_NAME_MAX_LEN 64 // Firmware Name String Length
#define FW_STATE_MAX_LEN 64 //Firmware State
/**********************************************************************
                ENUMERATION DEFINITIONS
**********************************************************************/

typedef  enum {
   HOST_CPU=0,
   PEER_CPU=1,
   NOT_SUPPORTED_CPU=3,
} RDK_CPUS; // RDK_CPUS

#ifndef PLAT_PROC_MEM_MAX_LEN
#define PLAT_PROC_MEM_MAX_LEN   40
#endif

/**********************************************************************
                STRUCTURE DEFINITIONS
**********************************************************************/
typedef  struct
_PLAT_PROC_MEM_INFO
{
    CHAR                            dramPath[PLAT_PROC_MEM_MAX_LEN];
    CHAR                            emmcPath1[PLAT_PROC_MEM_MAX_LEN];
    CHAR                            emmcPath2[PLAT_PROC_MEM_MAX_LEN];
    CHAR                            emmcPath3[PLAT_PROC_MEM_MAX_LEN];
}
PLAT_PROC_MEM_INFO, *PPLAT_PROC_MEM_INFO;

/**
 * @addtogroup PLATFORM_HAL_APIS
 * @{
 */

/**********************************************************************************
 *
 *  Subsystem level function prototypes
 *
**********************************************************************************/
/* platform_hal_GetDeviceConfigStatus() function */
/**
* @description Get the device configuration status.
*
* @param[out] pValue  - Device Configuration status, to be returned.
*		     \n Possible values are WaitForImplement, In Progress, Complete.
*                    \n The buffer size for pValue should be at least 128 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetDeviceConfigStatus(CHAR *pValue);

/* platform_hal_GetTelnetEnable() function */
/**
* @description Get telnet enable status.
*
* @param[out] pFlag - Telnet enable value, to be returned.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetTelnetEnable(BOOLEAN *pFlag);

/* platform_hal_SetTelnetEnable() function */
/**
* @description Enable/Disable telnet.
*
* @param[in] Flag - Telnet enable value.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_SetTelnetEnable(BOOLEAN Flag);

/* platform_hal_GetSSHEnable() function */
/**
* @description Get SSH enable status.
*
* @param[out] pFlag - SSH enable value, to be returned.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetSSHEnable(BOOLEAN *pFlag);

/* platform_hal_SetSSHEnable() function */
/**
* @description Enable/disable SSH.
*
* @param[in] Flag - SSH enable value.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_SetSSHEnable(BOOLEAN Flag);

/* platform_hal_GetSNMPEnable() function */
/**
* @description Get SNMP Enable value from the device.
*
* @param[out] pValue - SNMP enable value, to be returned.
*                   \n Possible values are rgWan, rgDualIp, and rgLanIp.
*                   \n The buffer size should be at least 32 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetSNMPEnable(CHAR* pValue);

/* platform_hal_SetSNMPEnable() function */
/**
* @description Set SNMP Enable value.
*
* @param[in] pValue - SNMP enable value.
*                  \n Possible values are rgWan, rgDualIp, rgLanIp.
*                  \n The string's size shouldn’t exceed 32 bytes .
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_SetSNMPEnable(CHAR* pValue);

/* platform_hal_GetWebUITimeout() function */
/**
* @description Get WebUI timeout value.
*
* @param[out] pValue - WebUI timeout value, to be returned.
*                   \n Valid range of values is from 30 to 86400.
*                   \n Default value is 840.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetWebUITimeout(ULONG *pValue);

/* platform_hal_SetWebUITimeout() function */
/**
* @description Set WebUI timeout value.
*
* @param[in] value - WebUI timeout value.
*                 \n Valid range of values are 30 to 86400 and can also be set to 0.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_SetWebUITimeout(ULONG value);

/** Soon to be deprecated **/
/* platform_hal_GetWebAccessLevel() function */
/**
* @description Get Web Access Level.
*
* @param userIndex - User Index.
* @param ifIndex   - Interface Index.
* @param pValue    - Web Access Level, to be returned.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetWebAccessLevel(INT userIndex, INT ifIndex, ULONG *pValue);

/** Soon to be deprecated **/
/* platform_hal_SetWebAccessLevel() function */
/**
* @description Set Web Access Level.
*
* @param userIndex - User Index.
* @param ifIndex   - Interface Index.
* @param value     - Web Access Level.
*
* <table>
* <caption id="multi_row">Lan Level Vs Index table</caption>
* <tr><th>Lan Level	<th>User Index	<th>Interface Index
* <tr><td>HomeUser_Lan_Level <td>1 <td>1
* <tr><td>HomeUser_RfCM_Level <td>1 <td>2
* <tr><td>HomeUser_Mta_Level <td>1 <td>16
* <tr><td>HomeUser_WanRG_Level <td>1 <td>40
* <tr><td>CusAdmin_Lan_Level <td>5 <td>1
* <tr><td>CusAdmin_RfCM_Level <td>5 <td>2
* <tr><td>CusAdmin_Mta_Level <td>5 <td>16
* <tr><td>CusAdmin_WanRG_Level <td>5 <td>40
* <tr><td>AdvUser_Lan_Level <td>10 <td>1
* <tr><td>AdvUser_RfCM_Level <td>10 <td>2
* <tr><td>AdvUser_Mta_Level <td>10 <td>16
* <tr><td>AdvUser_WanRG_Level <td>10 <td>40
* </table>
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_SetWebAccessLevel(INT userIndex, INT ifIndex, ULONG value);

/* platform_hal_PandMDBInit() function */
/**
* @description Initialize PandM DB (Database).
*
* @param None.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_PandMDBInit(void);

/* platform_hal_DocsisParamsDBInit() function */
/**
* @description Initialize Platform HAL docsis parameters DB.
*
* @param None.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_DocsisParamsDBInit(void);

/* platform_hal_GetModelName() function */
/**
* @description Get device model name.
*
* @param[out] pValue - Device Model Name, to be returned.
*                   \n It is a vendor specific value.
*                   \n Buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetModelName(CHAR* pValue);

/* platform_hal_GetRouterRegion() function */
/**
* @description Get router region.
*
* @param[out] pValue - Router region name, to be returned .
*                   \n Possible values of pValue are REGION_UK, REGION_IT, REGION_ROI and REGION_UNKNOWN.
*                   \n The buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetRouterRegion(CHAR* pValue);

/* platform_hal_GetSerialNumber() function */
/**
* @description Get device serial number.
*
* @param[out] pValue - Device Serial Number, to be returned.
*                   \n It is a vendor specific value.
*                   \n The buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetSerialNumber(CHAR* pValue);

/* platform_hal_GetHardwareVersion() function */
/**
* @description Get hardware version of the device.
*
* @param[out] pValue - Hardware version, to be returned.
*                   \n It is a vendor specific value.
*                   \n The buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetHardwareVersion(CHAR* pValue);

/* platform_hal_GetSoftwareVersion() function */
/**
* @description Get software version flashed in the device.
*
* @param[out] pValue - Software version, to be returned.
*                   \n It is vendor specific value.
* @param[in] maxSize - Size of the buffer allocated for pValue.
*                   \n The value of maxSize should be greater than or equal to 256 bytes.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None
*/
INT platform_hal_GetSoftwareVersion(CHAR* pValue, ULONG maxSize);

/* platform_hal_GetBootloaderVersion() function */
/**
* @description Get the bootloader version flashed in the device.
*
* @param[out] pValue - Bootloader version.
*                   \n It is a vendor specific value.
* @param[in]  maxSize - Size of the buffer allocated for pValue.
*                   \n The value of maxSize should be greater than or equal to 256 bytes.
*
* @return The status of the operation.
* @retval RETURN_OK  if successful.
* @retval RETURN_ERR If any error is detected .
*
* @sideeffect None.
*/
INT platform_hal_GetBootloaderVersion(CHAR* pValue, ULONG maxSize);

/* platform_hal_GetFirmwareName() function */
/**
* @description Get firmware image name flashed in the device.
*
* @param[out] pValue - Firmware image name, to be returned.
*                   \n It is a vendor specific value.
* @param[in] maxSize - Size of the buffer allocated for pValue.
*                   \n The value of maxSize should be greater than or equal to 256 bytes.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetFirmwareName(CHAR* pValue, ULONG maxSize);

/* platform_hal_GetBaseMacAddress() function */
/**
* @description Get base MAC Address of the device.
*
* @param[out] pValue - Base MAC Address, to be returned.
*                   \n The MAC Address should be in the format AA:BB:CC:DD:EE:FF (colon-separated).
*                   \n The buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetBaseMacAddress(CHAR *pValue);

/*platform_hal_GetHardware() function*/
/**
* @description Get total flash size of the hardware.
*
* @param[out] pValue - Total flash size, to be returned.
*                   \n The pValue output returned should be in the range [1, 4096], both inclusive.
*                   \n The buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetHardware(CHAR *pValue);

/* platform_hal_GetHardware_MemUsed() function */
/**
* @description Get total used memory of the flash.
*
* @param[out] pValue - Total used memory, to be returned.
*                   \n The pValue output will be in the range [1, n] inclusive, where n is dependent on the total amount of physical RAM available in the device.
*                   \n The buffer size should be at least 1024 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetHardware_MemUsed(CHAR *pValue);

/* platform_hal_GetHardware_MemFree() function */
/**
* @description Get total available memory of the flash.
*
* @param[out] pValue - Total available memory, to be returned.
*                   \n The pValue output will be in the range [1, n] inclusive, where n is dependent on total amount of physical RAM available in the device.
*                   \n The buffer size should be at least 1024 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetHardware_MemFree(CHAR *pValue);

/* platform_hal_GetTotalMemorySize() function */
/**
* @description Get total memory size of the DRAM (Dynamic Random Access Memory).
*
* @param[out] pulSize - Total memory size of DRAM, to be returned.
*                    \n The pulSize output will be in the range [1, n] inclusive, where "n" is dependent on the total amount of physical RAM available in the device.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetTotalMemorySize(ULONG *pulSize);

/* platform_hal_GetUsedMemorySize() function */
/**
* @description Get the total used memory of the DRAM (Dynamic Random Access Memory)
*
* @param[out] pulSize - Total used memory of the DRAM, to be returned.
*                    \n The value will be in the range [1, n] inclusive, where "n" is dependent on the total amount of physical RAM available in the device.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetUsedMemorySize(ULONG *pulSize);

/* platform_hal_GetFreeMemorySize() function */
/**
* @description Get the total available memory of the DRAM (Dynamic Random Access Memory).
*
* @param[out] pulSize - Total available memory of the DRAM, to be returned.
*                    \n The value will be in the range [1, n] inclusive, where n is dependent on the total amount of physical RAM.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetFreeMemorySize(ULONG *pulSize);

/* platform_hal_GetFactoryResetCount() function */
/**
* @description Get the total number of times factory reset has been done on the device.
* \n Device.DeviceInfo.FactoryResetCount.
*
* @param[out] pulSize - Factory reset count, to be returned.
*                    \n Possible values for pulSize is 0 to n.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetFactoryResetCount(ULONG *pulSize);

/* platform_hal_ClearResetCount() function */
/**
* @description Reset the factory reset count on the device.
*\n Device.DeviceInfo.ClearResetCount.
*
* @param[in] bFlag - Reset Factory reset count, if TRUE .
*                 \n Factory Reset count will be unchanged,if set to FALSE.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_ClearResetCount(BOOLEAN bFlag);

/* platform_hal_getTimeOffSet() function */
/**
* @description Get the time offset from the device.
* \n Device.DeviceInfo.TimeOffset.
*
* @param[out] timeOffSet - Time offset to be returned.
*                       \n The valid values for timeOffSet are as follows :
*                       \n '-25200': Eastern Standard Time (EST) = UTC-5.
*                       \n '-18000': Mountain Standard Time (MST) = UTC-7 (default).
*                       \n '+25200': Indonesia Western Time = UTC+7.
*                       \n The buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_getTimeOffSet(CHAR *timeOffSet);

/* platform_hal_SetDeviceCodeImageTimeout() function */
/**
* @description Set HW watchdog timeout value.
*
* @param[in] seconds - Hardware watchdog timeout value in seconds.
*                   \n The default value is 60 minutes.
*                   \n The possible range for seconds is 0 to 60 mins[inclusively].
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_SetDeviceCodeImageTimeout(INT seconds);


/* platform_hal_SetDeviceCodeImageValid() function */
/**
* @description Set Valid flag for firmware image flashed in the device.
*
* @param[in] flag - Image valid flag.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_SetDeviceCodeImageValid(BOOLEAN flag);

/* platform_hal_getFactoryPartnerId() function */
/**
* @description Get FactoryPartnerID from the the device.
*
* @param[out] pValue - FactoryPartnerID.
*                   \n Possible values for pValue are "unknown", "eUnprogrammed", "eComcast", "eCharter", "eCox", "eRogers", "eVodafone", "eShaw", "eVideotron".
*                   \n The buffer size size should be at least 512 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_getFactoryPartnerId(CHAR *pValue);


/* platform_hal_getFactoryCmVariant() function */
/**
* @description Get FactoryCmVariant from the the device.
*
* @param[out] pValue - FactoryCmVariant.
*                   \n Possible values for pValue are "unknown", "pc20", "pc20genband", "pc15sip", "pc15mgcp".
*                   \n The buffer size should be at least 512 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_getFactoryCmVariant(CHAR *pValue);


/* platform_hal_setFactoryCmVariant() function */
/**
* @description Set FactoryCmVariant from the the device.
*
* @param[in] pValue - FactoryCmVariant.
*                  \n Possible values are  "unknown", "pc20", "pc20genband", "pc15sip" and "pc15mgcp" .
*                  \n The string size shouldn't exceed 512 bytes.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_setFactoryCmVariant(CHAR *pValue);


/**
 * @addtogroup PLATFORM_HAL_TYPES
 * @{
 */

#define LED_BUFFER_SIZE 3

typedef  enum {
   LED_WHITE=0,
   LED_YELLOW=1, //This is also classified as Amber from RDKB perspective.
   LED_GREEN=2,
   LED_RED=3,
   LED_BLUE=4,
   LED_RED_AND_GREEN=5,
   LED_YELLOW_AND_GREEN= 6,
   NOT_SUPPORTED=7
} LED_COLOR; // LED_COLOR


typedef struct _LEDMGMT_PARAMS
{
#ifdef FEATURE_RDKB_LED_MANAGER
    char * led_name;
    char * led_param;
#endif
    LED_COLOR  LedColor;  //!< LED_COLOR.
    INT  State;	//!< 0 for Solid, 1 for Blink.
    INT  Interval;	//!< In case fs State is blink then interval per second.
}
LEDMGMT_PARAMS, *PLEDMGMT_PARAMS;

/**
 * @}
 */

/**
 * @addtogroup PLATFORM_HAL_APIS
 * @{
 */

#ifdef FEATURE_RDKB_LED_MANAGER
/* platfom_hal_initLed() function */
/**
* @description Initialises HAL layer and return file pointer to config file.
*
* @param[out] config_file_name - Vendor specific value.
*                             \n Buffer to hold the config file name including the full path. eg: /usr/rdk/rdkledmanager/led_config_gb.json.
*                             \n The buffer size should be at least 128 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
int platform_hal_initLed(char * config_file_name);
#endif

/* platform_hal_setLed() function */
/**
* @description Set Led behavior of the device.
*
* @param[in] pValue - The Current Led Buffer to be populated.
* <pre>
*                _LEDMGMT_PARAMS is a structure with following members :
*
*                LedColor                    - LedColor is platform dependent.
*                                              LedColor can hold  any values from enum LED_COLOR.
*
*                State                       - 0 for Solid, 1 for Blink.
*
*                Interval                    - In seconds. Range is from 0 to n.
* </pre>
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_setLed(PLEDMGMT_PARAMS pValue);


/* platform_hal_getLed() function */
/**
* @description Get Led behavior of the device at time of call.
*
* @param[out] pValue - The Current Led Buffer to be populated.
* <pre>
*                _LEDMGMT_PARAMS is a structure with following members :
*
*                LedColor                    - LedColor is platform dependent.
*                                              LedColor can hold  any values from enum LED_COLOR.
*
*                State                       - 0 for Solid, 1 for Blink.
*
*                Interval                    - In seconds. Range is from 0 to n.
* </pre>
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None
*/
INT platform_hal_getLed(PLEDMGMT_PARAMS pValue);

/* platform_hal_getFanSpeed() function */
/**
* @description Get PWM (pulse width modulation) setting of the fan.
*
* @param[in] fanIndex - fanIndex is a OEM dependent value.
*                    \n The range of fanIndex is from 0 to 1.
*
* @return FanSpeed in unsigned int.
* @retval Range of FanSpeed is from 0 to n and “n” is OEM dependent.
*/
UINT platform_hal_getFanSpeed(UINT fanIndex);

/* platform_hal_getRPM() function */
/**
* @description Get RPM(rotations per minute) of the fan.
*
* @param[in] fanIndex - fanIndex is a OEM dependent value.
*                    \n The range of fanIndex is from 0 to 1.
*
* @return FanRPM in unsigned int.
* @retval Range of FanRPM is from 0 to n and “n” is OEM dependent.
*/
UINT platform_hal_getRPM(UINT fanIndex);

/* platform_hal_getRotorLock() function */
/**
* @description Get the status of rotor lock.
*
* @param[in] fanIndex - fanIndex is a OEM dependent value.
*                    \n The range of fanIndex is from 0 to 1.
*
* @return The status of the rotor lock.
* @retval  1 if locked.
* @retval  0 if not locked.
* @retval -1 if value not applicable.
*/
INT platform_hal_getRotorLock(UINT fanIndex);


/* platform_hal_getFanStatus() function */
/**
* @description Get the fan status.
*
* @param[in] fanIndex - fanIndex is a OEM dependent value.
*                    \n The range of fanIndex is from 0 to 1.
*
* @return The fan status.
* @retval 1 if fan is enabled.
* @retval 0 if fan disabled.
*/
BOOLEAN platform_hal_getFanStatus(UINT fanIndex);

/* platform_hal_setFanMaxOverride() function */
/**
* @description Set the fan to maximum speed.
*
* @param[in] bOverrideFlag - Boolean value to enable/disable fan to run in highspeed.
* @param[in] fanIndex - fanIndex is a OEM dependent value.
*                    \n The range of fanindex is from 0 to 1.
*
* @return The status of the operation.
* @retval RETURN_OK on success setting/unsetting the fan to run in high speed mode.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_setFanMaxOverride(BOOLEAN bOverrideFlag, UINT fanIndex);

#ifdef FEATURE_RDKB_THERMAL_MANAGER
typedef enum {
   FAN_SPEED_OFF=0,
   FAN_SPEED_SLOW=1,
   FAN_SPEED_MEDIUM=2,
   FAN_SPEED_FAST=3,
   FAN_SPEED_MAX=4
} FAN_SPEED; // Fan speed



typedef struct _FAN_PLATFORM_CONFIG
{
   UINT FanCount;
   UINT SlowSpeedThresh;
   UINT MediumSpeedThresh;
   UINT FastSpeedThresh;
   UINT FanMinRunTime;
   UINT MonitoringDelay;
   UINT PowerMonitoring;
   UINT LogInterval;
} THERMAL_PLATFORM_CONFIG;



/* platform_hal_initThermal() function */
/**
* @description Initialise Thermal Hal.
*
* @param[out] pThermalPlatformConfig - Pointer to platforms thermal configuration.
* <pre>
*                _FAN_PLATFORM_CONFIG is a structure with following members :
*
*                FanCount                    - Number of fans present. Possible values are 1 or 2.
*
*                SlowSpeedThresh             - Slow fan speed temperature threshold in degree celsius. Possible value is 30 C.
*
*                MediumSpeedThresh           - Medium fan speed temperature threshold in degree celsius. Possible value is 35 C.
*
*                FastSpeedThresh             - Fast fan speed temperature threshold in degree celsius. Possible value is 40 C.
*
*                FanMinRunTime               - Minimum Fan runtime in seconds. Possible value is 60 seconds.
*
*                MonitoringDelay             - Monitoring Delay time in seconds. Possible value is 30 seconds.
*
*                PowerMonitoring             - Enable or Disable power monitoring. Possible values are 0 or 1.
*
*                LogInterval                 - Thermal log interval in seconds. Possible value is 10 minutes.
* </pre>
*
* @return The status of the operation.
* @retval RETURN_OK on successful initialisation.
* @retval RETURN_ERR if any error is detected
*/
INT platform_hal_initThermal(THERMAL_PLATFORM_CONFIG* pThermalPlatformConfig);

/* platform_hal_LoadThermalConfig() function */
/**
* @description Loads default Thermal Hal thresholds.
*
* @param[out] pThermalPlatformConfig - Pointer to platforms thermal configuration.
* <pre>
*                _FAN_PLATFORM_CONFIG is a structure with following members :
*
*                FanCount                    - Number of fans present. Possible values are 1 or 2.
*
*                SlowSpeedThresh             - Slow fan speed temperature threshold in degree celsius. Possible value is 30 C.
*
*                MediumSpeedThresh           - Medium fan speed temperature threshold in degree celsius. Possible value is 35 C.
*
*                FastSpeedThresh             - Fast fan speed temperature threshold in degree celsius. Possible value is 40 C.
*
*                FanMinRunTime               - Minimum Fan runtime in seconds. Possible value is 60 seconds.
*
*                MonitoringDelay             - Monitoring Delay time in seconds. Possible value is 30 seconds.
*
*                PowerMonitoring             - Enable or Disable power monitoring. Possible values are 0 or 1.
*
*                LogInterval                 - Thermal log interval in seconds. Possible value is 10 minutes.
* </pre>
*
* @return The status of the operation.
* @retval RETURN_OK on successful initialisation.
* @retval RETURN_ERR if any error is detected
*/
INT platform_hal_LoadThermalConfig (THERMAL_PLATFORM_CONFIG* pThermalPlatformConfig);

typedef enum {
   FAN_ERR_NONE = 0,
   FAN_ERR_HW = 1,
   FAN_ERR_MAX_OVERRIDE_SET = 2
} FAN_ERR; // Fan errors

/* platform_hal_setFanSpeed() function */
/**
* @description Set the fan speed.
*
* @param[in] fanIndex - fanIndex is OEM dependent.
*                    \n The valid range of fanIndex are 0 to 1.
* @param[in] fanSpeed - Off, Slow, medium or fast.
*                    \n fanSpeed can hold any values from enum FAN_SPEED.
* @param[out] pErrReason - Pointer where to provide error status.
*                       \n pErrReason can hold any values from enum FAN_ERR.
*
* @return The status of the operation.
* @retval RETURN_OK on success setting fan speed.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_setFanSpeed(UINT fanIndex, FAN_SPEED fanSpeed, FAN_ERR* pErrReason);

/* platform_hal_getFanTemperature() function */
/**
* @description Get current device temperature reading.
*
* @param[out] pTemp - Pointer where to provide temperature reading and it is OEM dependent.
*                  \n The valid range of pTemp is from 0 to 100 degree celsius.
*
* @return The status of the operation.
* @retval RETURN_OK on success reading temperature.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getFanTemperature(int* pTemp);


/* platform_hal_getInputCurrent() function */
/**
* @description To get input current.
*
* @param[out] pValue - Input current in milli Amperes.
*                   \n pValue is OEM dependent.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getInputCurrent(INT *pValue);

/* platform_hal_getInputPower() function */
/**
* @description To get input power.
*
* @param[out] pValue - Input power in milli Watts.
*                   \n pValue is OEM dependent.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getInputPower(INT *pValue);

/* platform_hal_getRadioTemperature() function */
/**
* @description To get Radio Temperature.
*
* @param[in] radioIndex - Index of Wi-Fi radio channel.
*                      \n Possible values are 0,1 and 2, depending on the number of radios supported by the platform.
* @param[out] pValue - Radio temperature and it is OEM dependent.
*                   \n Range of pValue is 0 to 100 degree Celsius.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getRadioTemperature(INT radioIndex, INT* pValue);

#endif

/* platform_hal_SetSNMPOnboardRebootEnable() function */
/**
* @description Set SNMP Onboard Reboot Enable value  to allow or ignore SNMP reboot.
*
* @param[in] pValue - SNMP Onboard Reboot Enable value.
*                  \n Possible values are "disable" and "enable".
*                  \n The string size shouldn't exceed 8 bytes.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_SetSNMPOnboardRebootEnable(CHAR* pValue);


/* platform_hal_GetMACsecEnable() function */
/**
* @description Get MACsec enable status.
*
* @param[in] ethPort - Ethernet port(zero-based).
*                   \n Here ethPort means combination of all interfaces such as moca,ethernet and wifi.
*                   \n The valid range of ethPort is from 0 to MaxEthPort-1, where MaxEthPort is platform specific.
* @param[out] pFlag - MACsec enable value, to be returned.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_GetMACsecEnable(INT ethPort, BOOLEAN *pFlag);


/* platform_hal_SetMACsecEnable() function */
/**
* @description Enable/Disable MACsec.
*
* @param[in] ethPort - Ethernet port (zero-based).
*                   \n Here ethPort means combination of all interfaces such as moca,ethernet and wifi.
*                   \n The valid range of ethPort is from 0 to MaxEthPort-1, where MaxEthPort is platform specific.
* @param[in] Flag - MACsec enable value.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_SetMACsecEnable(INT ethPort, BOOLEAN Flag);


/* platform_hal_GetMACsecOperationalStatus() function */
/**
* @description Checks whether MACSEC is configured at interface / driver level.
*
* @param[in] ethPort - Ethernet port (zero-based).
*                   \n Here ethPort means combination of all interfaces such as moca,ethernet and wifi.
*                   \n The valid range of ethPort is from 0 to MaxEthPort-1, where MaxEthPort is platform specific.
* @param[out] pFlag - MACsec operation status value, to be returned.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_GetMACsecOperationalStatus(INT ethPort, BOOLEAN *pFlag);

/* platform_hal_StartMACsec() function */
/**
* @description Start MACsec - Call should be Blocking.
*
* @param[in] ethPort - Ethernet port (zero-based).
*                   \n Here ethPort means combination of all interfaces such as moca,ethernet and wifi.
*                   \n The valid range of ethPort is from 0 to MaxEthPort-1, where MaxEthPort is platform specific.
* @param[in] timeoutSec - MACsec Start Timeout (0 means retry forever).
*                      \n timeoutSec is unused and possible value is 0.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_StartMACsec(INT ethPort, INT timeoutSec);

/* platform_hal_StopMACsec() function */
/**
* @description Stop MACsec - Call should be Blocking.
*
* @param[in] ethPort - Ethernet port (zero-based).
*                   \n Here ethPort means combination of all interfaces such as moca,ethernet and wifi.
*                   \n The valid range of ethPort is from 0 to MaxEthPort-1, where MaxEthPort is platform specific.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_StopMACsec(INT ethPort);


/*  platform_hal_GetMemoryPaths() function */
/**
* @description Get the device specific processors DRAM and eMMC paths.
*
* @param[in] index - Index to which processor/CPU to request.
*                 \n Host is the primary RDK CPU .
*                 \n index can hold any values from enum RDK_CPUS.
* @param[out] ppinfo - Pointer to get the return array.
*                   \n List of client structure to be filled by hal.
* <pre>
*                _PLAT_PROC_MEM_INFO is a structure with following members :
*
*                dramPath                    - Possible value is "/tmp".
*                                              The buffer size should be at least 40 bytes long.
*
*                emmcpath1                   - Possible value is "/nvram".
*                                              The buffer size should be at least 40 bytes long.
*
*                emmcPath2                   - Possible value is "/nvram2".
*                                              The buffer size should be at least 40 bytes long.
*
*                emmcPath3                   - Unused variable.
*                                              The buffer size should be at least 40 bytes long.
* </pre>
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @execution Synchronous.
* \n @sideeffect None.
*
* @note HAL function need to allocate the array of PPLAT_PROC_MEM_INFO and return with ppinfo.
*
*/
INT platform_hal_GetMemoryPaths(RDK_CPUS index, PPLAT_PROC_MEM_INFO *ppinfo);

/*
 * dhcpv4_req_opt_to_hal - is used to fill options to request values.
 * from platform
 */

typedef struct dhcp_opt_list {
    int dhcp_opt;
    char * dhcp_opt_val;
    struct dhcp_opt_list * next;
} dhcp_opt_list;

/* platform_hal_GetDhcpv4Options() function*/
/**
* @description  This function fills in 2 list, 1 for request option and 1 for send option.
*
* @param[out] req_opt_list - List to be filled for request dhcp options .
* @param[out] send_opt_list - List to be filled for send dhcp options.
*                          \n List of client structure to be filled by hal.
* <pre>
*                dhcp_opt_list is a structure with following members :
*
*                dhcp_opt                    - DHCPv4 Options. Possible values are :
*                                              #define DHCPV4_OPT_42 42 // NTP Server Addresses.
*                                              #define DHCPV4_OPT_43 43 // Vendor Specific Information.
*                                              #define DHCPV4_OPT_58 58 // DHCP Renewal (T1) Time.
*                                              #define DHCPV4_OPT_59 59 // DHCP Rebinding (T2) Time.
*                                              #define DHCPV4_OPT_60 60 // Class Identifier.
*                                              #define DHCPV4_OPT_61 61 // Client Identifier.
*                                              #define DHCPV4_OPT_100 100 // IEEE 1003.1 TZ String.
*                                              #define DHCPV4_OPT_122 122 // CableLabs Client Configuration.
*                                              #define DHCPV4_OPT_125 125 // Vendor-Identifying Vendor-Specific Information.
*                                              #define DHCPV4_OPT_242 242 // Private Use.
*                                              #define DHCPV4_OPT_243 243 // Private Use.
*                                              #define DHCPV4_OPT_END 255 // DHCP Option End - used to check if option is valid.
*
*                dhcp_opt_val                - It can be any string and the parameter is optional.
*
*                next                        - Pointer variable of dhcp_opt_list.
* </pre>
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetDhcpv4_Options(dhcp_opt_list ** req_opt_list, dhcp_opt_list ** send_opt_list);

/* platform_hal_GetDhcpv6Options() function*/
/**
* @description This function fills in 2 list, 1 for request option and 1 for send option.
*
* @param[out] req_opt_list - List to be filled for request dhcp options.
* @param[out] send_opt_list - List to be filled for send dhcp options.
*                          \n List of client structure to be filled by hal.
* <pre>
*                dhcp_opt_list is a structure with following members :
*
*                dhcp_opt                    - DHCPv6 Options Possible values are :
*                                              #define DHCPV6_OPT_82 82 // OPTION_SOL_MAX_RT: Solicite Maximum Retry Time.
*                                              #define DHCPV6_OPT_23 23 // OPTION_SOL_MAX_RT: Solicite Maximum Retry Time.
*                                              #define DHCPV6_OPT_95 95 // OPTION_SOL_MAX_RT: Solicite Maximum Retry Time.
*                                              #define DHCPV6_OPT_24 24 // OPTION_DOMAIN_LIST.
*                                              #define DHCPV6_OPT_83 83 // OPTION_INF_MAX_RT.
*                                              #define DHCPV6_OPT_17 17 // OPTION_VENDOR_OPTS.
*                                              #define DHCPV6_OPT_31 31 // OPTION_SNTP_SERVERS.
*                                              #define DHCPV6_OPT_15 15 // User Class Option.
*                                              #define DHCPV6_OPT_16 16 // Vendor Class Option.
*                                              #define DHCPV6_OPT_20 20 // Reconfigure Accept Option.
*
*                dhcp_opt_val                - it can be any string and the parameter is optional.
*                next                        - Pointer variable of dhcp_opt_list.
* </pre>
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetDhcpv6_Options ( dhcp_opt_list ** req_opt_list, dhcp_opt_list ** send_opt_list);

typedef  enum {
   PSM_UNKNOWN=0,
   PSM_AC,
   PSM_BATT,
   PSM_HOT,
   PSM_COOLED,
   PSM_NOT_SUPPORTED,
} PSM_STATE, *PPSM_STATE; // Power Saving Mode State

/* platform_hal_SetLowPowerModeState() function */
/**
* @description Set Low Power Mode State value. Hysteresis currently not accounted for before call.
*
* @param[in] pState - Low Power Mode State.
*                  \n pState can hold any values from enum PPSM_STATE.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_SetLowPowerModeState(PPSM_STATE pState);

/* platform_hal_getCMTSMac() function */
/**
* @description Get CMTS MAC Address.
*
* @param[out] pValue - MAC address string in format AA:BB:CC:DD:EE:FF.
*                   \n The buffer size should be atleast 100 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_getCMTSMac(CHAR *pValue);


typedef  enum {
   DOCSIS=1,
   EWAN=2,
} WAN_INTERFACE;

typedef  enum {
   TRAFFIC_CNT_START=1,
   TRAFFIC_CNT_STOP=2,
} TRAFFIC_CNT_COMMAND;

typedef struct Traffic_client {
    char mac[18]; // e.g. 00:AA:BB:CC:DD:EE
    ULONG rxBytes;
    ULONG txBytes;
} Traffic_client_t, *pTraffic_client_t;

typedef struct DSCP_Element {
    UINT dscp_value;
    UINT numClients;
    Traffic_client_t Client[256];
} DSCP_Element_t, *pDSCP_Element_t;

typedef struct DSCP_list {
    UINT numElements;
    DSCP_Element_t DSCP_Element[64];
} DSCP_list_t, *pDSCP_list_t;

/* platform_hal_setDscp() function */
/**
* @description Control/Set traffic counting based on Dscp value.
*
* @param[in] interfaceType - 1 for DOCSIS , 2 for EWAN.
*                         \n interfaceType can hold any values from enum WAN_INTERFACE.
* @param[in] cmd - START/STOP.
*               \n cmd can hold any values from enum TRAFFIC_CNT_COMMAND.
* @param[in] pDscpVals - Comma separated string of base 10 values.
*                     \n Range of DSCP values is [0-65,534].
*                     \n The string’s size shouldn’t exceed 195 bytes.
*                     \n e.g. "10,0" , NULL. NULL is for all DSCP values.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_setDscp(WAN_INTERFACE interfaceType , TRAFFIC_CNT_COMMAND cmd , char* pDscpVals);

/* platform_hal_resetDscpCounts() function */
/**
* @description To reset Dscp Counter values.
*
* @param[in] interfaceType - 1 for DOCSIS , 2 for EWAN.
*                         \n interfaceType can hold any values from enum WAN_INTERFACE.
*
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_resetDscpCounts(WAN_INTERFACE interfaceType);


/* platform_hal_getDscpClientList() function */
/**
* @description To get counter data.
*
* @param[in] interfaceType - 1 for DOCSIS , 2 for EWAN.
*                         \n interfaceType can hold any values from enum WAN_INTERFACE.
* @param[out] pDSCP_List - List of client structure to be filled by hal.
* <pre>
*                DSCP_list is a structure with following members :
*
*                numElements                 - Maximum value for numElements is 64 range [ 0-63].
*
*                DSCP_Element is a Structure with following members :
*
*                dscp_value                  - Maximum dcspvalue is 65,535 range [ 0- 65,534].
*                                              numClients - Range is 0-255.
*
*                Traffic_client is a Structure with following members :
*
*                mac                         - mac address. e.g. 00:AA:BB:CC:DD:EE.
*
*                rxBytes                     - Possible values from 0 to 2^64-1.
*
*                txBytes                     - Possible values from 0 to 2^64-1.
* </pre>
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getDscpClientList(WAN_INTERFACE interfaceType , pDSCP_list_t pDSCP_List);


/* platform_hal_GetCPUSpeed() function */
/**
* @description Get cpu speed.
*
* @param[out] cpuSpeed - It is the processor speed in bogomips.
*                     \n Expected values for cpuSpeed is 1 to n, where n is device specific.
*                     \n The buffer size should be at least 16 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetCPUSpeed(char *cpuSpeed);

typedef  enum {
   ACTIVE_BANK,
   INACTIVE_BANK,
} FW_BANK;

typedef  struct _FW_BANK_INFO
{
      CHAR  fw_name[FW_NAME_MAX_LEN];
      CHAR  fw_state[FW_STATE_MAX_LEN];
}
FW_BANK_INFO, *PFW_BANK_INFO;

/* platform_hal_GetFirmwareBankInfo() function */
/**
* @description Get firmware image name flashed in the given Bank.
*
* @param[in] bankIndex - The parameter can hold any value from the enum FW_BANK.
* @param[out] pFW_Bankinfo - Structure variable containing Firmware image name and Firmware state.
* <pre>
*                _FW_BANK_INFO is a structure with following parameters :
*
*                fw_name                     - Firmware name. Vendor specific.
*                                              The buffer size should be at least 64 bytes long.
*
*                fw_state                    - Firmware state.
*                                              Expected values are confirmed, from "TrialBoot#0" to "TrialBoot#n".
*                                              TrialBoot value can vary from 0 to n, where "n" is vendor specific.
*                                              The buffer size should be at least 64 bytes long.
* </pre>
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetFirmwareBankInfo(FW_BANK bankIndex,PFW_BANK_INFO pFW_Bankinfo);

typedef  struct _INTF_STATS
{
   UINT64_t rx_packet; /* Packets received */
   UINT64_t tx_packet; /* Packets sent */
   UINT64_t rx_bytes; /* Bytes received */
   UINT64_t tx_bytes; /* Bytes sent */
}
INTF_STATS, *PINTF_STATS;
/* platform_hal_GetInterfaceStats() function */
/**
* @description Get Interface Stats for the given interface,considering only LAN to WAN/WAN to LAN traffic.
*
* @param ifname - Interface name for which stats needs to be fetched.
* @param pIntfStats - Interface Stats structure, to be returned.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @sideeffect None.
*/
INT platform_hal_GetInterfaceStats(const char *ifname,PINTF_STATS pIntfStats);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @}
 */


