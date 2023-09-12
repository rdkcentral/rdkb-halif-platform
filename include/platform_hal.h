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
/**
 * @file platform_hal.h
 * @brief The platform_hal provides an interface to get/set platform control features.
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
#define DHCPV6_OPT_82  82  //!< OPTION_SOL_MAX_RT: Solicite Maximum Retry Time
#define DHCPV6_OPT_23  23  //!< OPTION_SOL_MAX_RT: Solicite Maximum Retry Time
#define DHCPV6_OPT_95  95  //!< OPTION_SOL_MAX_RT: Solicite Maximum Retry Time
#define DHCPV6_OPT_24  24  //!< OPTION_DOMAIN_LIST
#define DHCPV6_OPT_83  83  //!< OPTION_INF_MAX_RT
#define DHCPV6_OPT_17  17  //!< OPTION_VENDOR_OPTS
#define DHCPV6_OPT_31  31  //!< OPTION_SNTP_SERVERS
#define DHCPV6_OPT_15  15  //!< User Class Option
#define DHCPV6_OPT_16  16  //!< Vendor Class Option
#define DHCPV6_OPT_20  20  //!< Reconfigure Accept Option


//DHCPv4 Options
#define DHCPV4_OPT_42  42  //!< NTP Server Addresses
#define DHCPV4_OPT_43  43  //!< Vendor Specific Information
#define DHCPV4_OPT_58  58  //!< DHCP Renewal (T1) Time
#define DHCPV4_OPT_59  59  //!< DHCP Rebinding (T2) Time
#define DHCPV4_OPT_60  60  //!< Class Identifier
#define DHCPV4_OPT_61  61  //!< Client Identifier
#define DHCPV4_OPT_100 100 //!< IEEE 1003.1 TZ String
#define DHCPV4_OPT_122 122 //!< CableLabs Client Configuration
#define DHCPV4_OPT_125 125 //!< Vendor-Identifying Vendor-Specific Information
#define DHCPV4_OPT_242 242 //!< Private Use
#define DHCPV4_OPT_243 243 //!< Private Use
#define DHCPV4_OPT_END 255 //!< DHCP Option End - used to check if option is valid

#define FW_NAME_MAX_LEN 64 //!< Firmware Name String Length
#define FW_STATE_MAX_LEN 64 //!<Firmware State
/**********************************************************************
                ENUMERATION DEFINITIONS
**********************************************************************/

typedef  enum {
   HOST_CPU=0,
   PEER_CPU=1,
   NOT_SUPPORTED_CPU=3,
} RDK_CPUS; //!< RDK_CPUS

#ifndef PLAT_PROC_MEM_MAX_LEN
#define PLAT_PROC_MEM_MAX_LEN   40 /**< Maximum length for memory path strings */
#endif

/**********************************************************************
                STRUCTURE DEFINITIONS
**********************************************************************/
typedef  struct
_PLAT_PROC_MEM_INFO
{
    CHAR                            dramPath[PLAT_PROC_MEM_MAX_LEN];  /**< Path to DRAM memory */
    CHAR                            emmcPath1[PLAT_PROC_MEM_MAX_LEN]; /**< Path to the first eMMC memory */
    CHAR                            emmcPath2[PLAT_PROC_MEM_MAX_LEN]; /**< Path to the second eMMC memory */
    CHAR                            emmcPath3[PLAT_PROC_MEM_MAX_LEN]; /**< Path to the third eMMC memory */
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
/**
* @brief Get the device configuration status.
*
* @param[out] pValue  - Device Configuration status, to be returned.
*		            \n Possible string values are 'WaitForImplement', 'In Progress', 'Complete'.
*                   \n The buffer size for pValue should be at least 128 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetDeviceConfigStatus(CHAR *pValue);

/**
* @brief Get telnet enable status.
*
* @param[out] pFlag - Pointer to a BOOLEAN variable where the Telnet enable status will be stored.
*                     \n Set to TRUE if Telnet is enabled.
*                     \n Set to FALSE if Telnet is disabled.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetTelnetEnable(BOOLEAN *pFlag);

/**
* @brief Enable/Disable telnet.
*
* @param[in] Flag - Pointer to a BOOLEAN variable where the Telnet enable status will be stored.
*                   \n Set to TRUE if Telnet is enabled.
*                   \n Set to FALSE if Telnet is disabled.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_SetTelnetEnable(BOOLEAN Flag);

/**
* @brief Get SSH enable status.
*
* @param[out] pFlag - Pointer to a BOOLEAN variable where the SSH enable status will be stored.
*                     \n Set to TRUE if SSH is enabled.
*                     \n Set to FALSE if SSH is disabled.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetSSHEnable(BOOLEAN *pFlag);

/**
* @brief Enable/disable SSH.
*
* @param[in] Flag - Pointer to a BOOLEAN variable where the SSH enable status will be stored.
*                     \n Set to TRUE if SSH is enabled.
*                     \n Set to FALSE if SSH is disabled.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_SetSSHEnable(BOOLEAN Flag);

/**
* @brief Get SNMP Enable value from the device.
*
* @param[out] pValue - Pointer to a buffer where the SNMP enable value will be stored.
*                     \n The buffer size should be at least 32 bytes long.
*                     \n Possible values are:
*                     \n 'rgWan': SNMP enabled for WAN interface.
*                     \n 'rgDualIp': SNMP enabled for dual IP configuration.
*                     \n 'rgLanIp': SNMP enabled for LAN IP configuration.
*
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetSNMPEnable(CHAR* pValue);

/**
* @brief Set SNMP Enable value.
*
* @param[in] pValue - Pointer to a buffer where the SNMP enable value will be stored.
*                     \n The buffer size should be at least 32 bytes long.
*                     \n Possible values are:
*                     \n 'rgWan': SNMP enabled for WAN interface.
*                     \n 'rgDualIp': SNMP enabled for dual IP configuration.
*                     \n 'rgLanIp': SNMP enabled for LAN IP configuration.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_SetSNMPEnable(CHAR* pValue);

/**
* @brief Get WebUI timeout value.
*
* @param[out] pValue - WebUI timeout value, to be returned.
*                   \n Valid range of values is from 30 to 86400.
*                   \n Default value is 840.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetWebUITimeout(ULONG *pValue);

/**
* @brief Set WebUI timeout value.
*
* @param[in] value - WebUI timeout value.
*                 \n Valid range of values are 30 to 86400 and can also be set to 0.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_SetWebUITimeout(ULONG value);

/**
* @brief Get Web Access Level.
*
* @param[in] userIndex - User index specifying the user for which the Web Access Level is requested.
*                    \n The valid range of values is -2^31 to (2^31)-1.
* @param[in] ifIndex - Interface index specifying the interface for which the Web Access Level is requested.
*                    \n The valid range of values is -2^31 to (2^31)-1.
* @param[out] pValue - Pointer to a ULONG variable where the Web Access Level will be stored and to be returned.
*                    \n The valid range of values is 0 to (2^31)-1.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @note Soon to be deprecated
*/
INT platform_hal_GetWebAccessLevel(INT userIndex, INT ifIndex, ULONG *pValue);

/**
* @brief Set Web Access Level.
*
* @param[in] userIndex - User index specifying the user for which the Web Access Level is requested.
*                    \n The valid range of values is -2^31 to (2^31)-1.
* @param[in] ifIndex - Interface index specifying the interface for which the Web Access Level is requested.
*                    \n The valid range of values is -2^31 to (2^31)-1.
* @param[out] value - Pointer to a ULONG variable where the Web Access Level will be stored and to be returned.
*                    \n The valid range of values is 0 to (2^31)-1.
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
* @note Soon to be deprecated
*/
INT platform_hal_SetWebAccessLevel(INT userIndex, INT ifIndex, ULONG value);

/**
* @brief Initialize PandM Database.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_PandMDBInit(void);

/**
* @brief Initialize Platform HAL docsis parameters Database.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_DocsisParamsDBInit(void);

/**
* @brief Get device model name.
*
* @param[out] pValue - Device Model Name, to be returned.
*                   \n It is a vendor specific value.
*                   \n Buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetModelName(CHAR* pValue);

/**
* @brief Get router region.
*
* @param[out] pValue - Router region name, to be returned .
*                   \n Possible values of pValue are `REGION_UK`, `REGION_IT`, `REGION_ROI` and `REGION_UNKNOWN`.
*                   \n The buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetRouterRegion(CHAR* pValue);

/**
* @brief Get device serial number.
*
* @param[out] pValue - Device Serial Number, to be returned.
*                   \n It is a vendor specific value.
*                   \n The buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetSerialNumber(CHAR* pValue);

/**
* @brief Get hardware version of the device.
*
* @param[out] pValue - Hardware version, to be returned.
*                   \n It is a vendor specific value.
*                   \n The buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetHardwareVersion(CHAR* pValue);

/**
* @brief Get software version flashed in the device.
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
*/
INT platform_hal_GetSoftwareVersion(CHAR* pValue, ULONG maxSize);

/**
* @brief Get the bootloader version flashed in the device.
*
* @param[out] pValue - Bootloader version.
*                      \n It is a vendor specific value.
* @param[in]  maxSize - Size of the buffer allocated for pValue.
*                      \n The value of maxSize should be greater than or equal to 256 bytes.
*
* @return The status of the operation.
* @retval RETURN_OK  if successful.
* @retval RETURN_ERR If any error is detected .
*
*/
INT platform_hal_GetBootloaderVersion(CHAR* pValue, ULONG maxSize);

/**
* @brief Get firmware image name flashed in the device.
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
*/
INT platform_hal_GetFirmwareName(CHAR* pValue, ULONG maxSize);

/**
* @brief Get base MAC Address of the device.
*
* @param[out] pValue - Base MAC Address, to be returned.
*                   \n The MAC Address should be in the format AA:BB:CC:DD:EE:FF (colon-separated).
*                   \n The buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetBaseMacAddress(CHAR *pValue);

/**
* @brief Get total flash size of the hardware.
*
* @param[out] pValue - Total flash size, to be returned.
*                   \n The pValue output returned should be in the range [1, 4096], both inclusive.
*                   \n The buffer size should be at least 256 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetHardware(CHAR *pValue);

/**
* @brief Get total used memory of the flash.
*
* @param[out] pValue - Total used memory, to be returned.
*                   \n The pValue output will be in the range [1, n] inclusive, where n is dependent on the total amount of physical RAM available in the device.
*                   \n The buffer size should be at least 1024 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetHardware_MemUsed(CHAR *pValue);

/**
* @brief Get total available memory of the flash.
*
* @param[out] pValue - Total available memory, to be returned.
*                   \n The pValue output will be in the range [1, n] inclusive, where n is dependent on total amount of physical RAM available in the device.
*                   \n The buffer size should be at least 1024 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetHardware_MemFree(CHAR *pValue);

/**
* @brief Get total memory size of the DRAM (Dynamic Random Access Memory).
*
* @param[out] pulSize - Total memory size of DRAM, to be returned.
*                    \n The pulSize output will be in the range [1, n] inclusive, where "n" is dependent on the total amount of physical RAM available in the device.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetTotalMemorySize(ULONG *pulSize);

/**
* @brief Get the total used memory of the DRAM (Dynamic Random Access Memory)
*
* @param[out] pulSize - Total used memory of the DRAM, to be returned.
*                    \n The value will be in the range [1, n] inclusive, where "n" is dependent on the total amount of physical RAM available in the device.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetUsedMemorySize(ULONG *pulSize);

/**
* @brief Get the total available memory of the DRAM (Dynamic Random Access Memory).
*
* @param[out] pulSize - Total available memory of the DRAM, to be returned.
*                    \n The value will be in the range [1, n] inclusive, where n is dependent on the total amount of physical RAM.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetFreeMemorySize(ULONG *pulSize);

/**
* @brief Get the total number of times factory reset has been done on the device.
* \n Device.DeviceInfo.FactoryResetCount.
*
* @param[out] pulSize - Factory reset count, to be returned.
*                    \n Possible values for pulSize is 0 to n.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetFactoryResetCount(ULONG *pulSize);

/**
* @brief Reset the factory reset count on the device.
*\n Device.DeviceInfo.ClearResetCount.
*
* @param[in] bFlag - Reset Factory reset count, if TRUE .
*                 \n Factory Reset count will be unchanged,if set to FALSE.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_ClearResetCount(BOOLEAN bFlag);

/**
* @brief Get the time offset from the device.
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
*/
INT platform_hal_getTimeOffSet(CHAR *timeOffSet);

/**
* @brief Set HW watchdog timeout value.
*
* @param[in] seconds - Hardware watchdog timeout value in seconds.
*                   \n The default value is 60 minutes.
*                   \n The possible range for seconds is 0 to 60 mins[inclusively].
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_SetDeviceCodeImageTimeout(INT seconds);


/**
* @brief Set Valid flag for firmware image flashed in the device.
*
* @param[in] flag - Image valid flag.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_SetDeviceCodeImageValid(BOOLEAN flag);

/**
* @brief Get FactoryPartnerID from the the device.
*
* @param[out] pValue - FactoryPartnerID.
*                   \n Possible values for pValue are "unknown", "eUnprogrammed", "eComcast", "eCharter", "eCox", "eRogers", "eVodafone", "eShaw", "eVideotron".
*                   \n The buffer size size should be at least 512 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_getFactoryPartnerId(CHAR *pValue);


/**
* @brief Get FactoryCmVariant from the the device.
*
* @param[out] pValue - FactoryCmVariant.
*                   \n Possible values for pValue are "unknown", "pc20", "pc20genband", "pc15sip", "pc15mgcp".
*                   \n The buffer size should be at least 512 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_getFactoryCmVariant(CHAR *pValue);


/**
* @brief Set FactoryCmVariant from the the device.
*
* @param[in] pValue - FactoryCmVariant.
*                  \n Possible values are  "unknown", "pc20", "pc20genband", "pc15sip" and "pc15mgcp" .
*                  \n The string size shouldn't exceed 512 bytes.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_setFactoryCmVariant(CHAR *pValue);


/**
 * @addtogroup PLATFORM_HAL_TYPES
 * @{
 */

#define LED_BUFFER_SIZE 3

typedef  enum {
   LED_WHITE=0,
   LED_YELLOW=1, //!<This is also classified as Amber from RDKB perspective.
   LED_GREEN=2,
   LED_RED=3,
   LED_BLUE=4,
   LED_RED_AND_GREEN=5,
   LED_YELLOW_AND_GREEN= 6,
   NOT_SUPPORTED=7
} LED_COLOR; //!< LED_COLOR


typedef struct _LEDMGMT_PARAMS
{
#ifdef FEATURE_RDKB_LED_MANAGER
    char * led_name;  //!< Name of the LED.
    char * led_param; //!< Additional parameters for the LED
#endif
    LED_COLOR  LedColor;  //!< LED color defined by the LED_COLOR enum.
    INT  State;	//!< LED state. Use 0 for Solid and 1 for Blink.
    INT  Interval; //!< Blink interval in case the LED state is set to blink (in seconds).
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
/**
* @brief Initialises HAL layer and return file pointer to config file.
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

/**
* @brief Set Led behavior of the device.
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
*/
INT platform_hal_setLed(PLEDMGMT_PARAMS pValue);


/**
* @brief Get Led behavior of the device at time of call.
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
*/
INT platform_hal_getLed(PLEDMGMT_PARAMS pValue);

/**
* @brief Get PWM (pulse width modulation) setting of the fan.
*
* @param[in] fanIndex - The index of the fan for which the speed is requested.
*                       \n The valid range of fanIndex is from 0 to 1 (fanIndex value should be less than 2).
*
* @return FanSpeed in unsigned int.
* @retval Range of FanSpeed is from 0 to n and “n” is OEM dependent.
*/
UINT platform_hal_getFanSpeed(UINT fanIndex);

/**
* @brief Get RPM(rotations per minute) of the fan.
*
* @param[in] fanIndex - The index of the fan for which the RPM is requested
*                       \n The valid range of fanIndex is from 0 to 1 (fanIndex value should be less than 2).
*
* @return FanRPM in unsigned int.
* @retval Range of FanRPM is from 0 to n and “n” is OEM dependent.
*/
UINT platform_hal_getRPM(UINT fanIndex);

/**
* @brief Get the status of rotor lock.
*
* @param[in] fanIndex - The index of the fan for which the rotor lock status is requested.
*                       \n The valid range of fanIndex is from 0 to 1 (fanIndex value should be less than 2).
*
* @return The status of the rotor lock.
* @retval  1 if locked.
* @retval  0 if not locked.
* @retval -1 if value not applicable.
*/
INT platform_hal_getRotorLock(UINT fanIndex);


/**
* @brief Get the fan status.
*
* @param[in] fanIndex - The index of the fan for which the status is requested.
*                       \n The valid range of fanIndex is from 0 to 1 (fanIndex value should be less than 2).
*
* @return The fan status.
* @retval 1 if fan is enabled.
* @retval 0 if fan disabled.
*/
BOOLEAN platform_hal_getFanStatus(UINT fanIndex);

/**
* @brief Set the fan to maximum speed.
*
* @param[in] bOverrideFlag - Boolean value to enable/disable fan to run at highspeed.
* @param[in] fanIndex - The index of the fan for which the maximum speed override is to be configured.
*                       \n The valid range of fanIndex is from 0 to 1 (fanIndex value should be less than 2).
*
* @return The status of the operation.
* @retval RETURN_OK on success setting/unsetting the fan to run at high speed mode.
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
} FAN_SPEED; //!< Fan speed



typedef struct _FAN_PLATFORM_CONFIG
{
   UINT FanCount; /*!< The total number of fans in the system */
   UINT SlowSpeedThresh; /*!< The threshold for considering a fan speed as "slow" */
   UINT MediumSpeedThresh; /*!< The threshold for considering a fan speed as "medium" */
   UINT FastSpeedThresh; /*!< The threshold for considering a fan speed as "fast" */
   UINT FanMinRunTime; /*!< The minimum runtime for a fan before it can be turned off */
   UINT MonitoringDelay; /*!< The delay in monitoring fan speed and conditions */
   UINT PowerMonitoring; /*!< The power monitoring for the fans*/
   UINT LogInterval; /*!< The Interval at which fan-related data is logged*/
} THERMAL_PLATFORM_CONFIG;



/**
* @brief Initialise Thermal Hal.
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

/**
* @brief Loads default Thermal Hal thresholds.
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
} FAN_ERR; //!< Fan errors

/**
* @brief Set the fan speed.
*
* @param[in] fanIndex - The index of the fan for which the speed is to be set.
*                       \n The valid range of fanIndex is from 0 to 1 (fanIndex value should be less than 2).
* @param[in] fanSpeed - Off, Slow, medium or fast.
*                       \n fanSpeed can hold any values from enum FAN_SPEED.
* @param[out] pErrReason - Pointer where to provide error status.
*                          \n pErrReason can hold any values from enum FAN_ERR.
*
* @return The status of the operation.
* @retval RETURN_OK on success setting fan speed.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_setFanSpeed(UINT fanIndex, FAN_SPEED fanSpeed, FAN_ERR* pErrReason);

/**
* @brief Get current device temperature reading.
*
* @param[out] pTemp - Pointer where to provide temperature reading and it is OEM dependent.
*                     \n The valid range of pTemp is from 0 to 100 degrees celsius.
*
* @return The status of the operation.
* @retval RETURN_OK on success reading temperature.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getFanTemperature(int* pTemp);


/* platform_hal_getInputCurrent() function */
/**
* @brief To get input current.
*
* @param[out] pValue - Input current in milli Amperes.
*                      \n pValue is OEM dependent.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getInputCurrent(INT *pValue);

/**
* @brief To get input power.
*
* @param[out] pValue - Input power in milli Watts.
*                      \n It is Vendor specific value.
*                      \n For example, the least possible value for a signed 32-bit integer is normally -2,147,483,648, and the greatest possible value is 2,147,483,647. The valid range varies accordingly for 64-bit architecture.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getInputPower(INT *pValue);

/**
* @brief To get Radio Temperature.
*
* @param[in] radioIndex - Index of Wi-Fi radio channel.
*                         \n Possible values are 0, 1, and 2. It depends on the number of radios supported by the platform.
* @param[out] pValue - Radio temperature and it is OEM dependent.
*                      \n Range of pValue is 0 to 100 degree Celsius.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getRadioTemperature(INT radioIndex, INT* pValue);

#endif

/**
* @brief Set SNMP Onboard Reboot Enable value  to allow or ignore SNMP reboot.
*
* @param[in] pValue - SNMP Onboard Reboot Enable value.
*                  \n Possible values are "disable" and "enable" (case-insensitive).
*                  \n The string size shouldn't exceed 8 bytes.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_SetSNMPOnboardRebootEnable(CHAR* pValue);


/**
* @brief Get MACsec enable status.
*
* @param[in] ethPort - Ethernet port(zero-based).
*                   \n Here ethPort means combination of all interfaces such as moca,ethernet and wifi.
*                   \n The valid range of ethPort is from 0 to MaxEthPort-1, where MaxEthPort is platform specific.
* @param[out] pFlag - MACsec enable value, to be returned. Use "TRUE" to represent MACsec is enabled and "FALSE" to represent MACsec is disabled.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_GetMACsecEnable(INT ethPort, BOOLEAN *pFlag);

/**
* @brief Enable/Disable MACsec.
*
* @param[in] ethPort - Ethernet port (zero-based).
*                   \n Here ethPort means combination of all interfaces such as moca,ethernet and wifi.
*                   \n The valid range of ethPort is from 0 to MaxEthPort-1, where MaxEthPort is platform specific.
* @param[in] Flag - MACsec enable value. Use "TRUE" to represent MACsec is enabled and "FALSE" to represent MACsec is disabled.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_SetMACsecEnable(INT ethPort, BOOLEAN Flag);

/**
* @brief Checks whether MACSEC is configured at interface / driver level.
*
* @param[in] ethPort - Ethernet port (zero-based).
*                   \n Here ethPort means combination of all interfaces such as moca,ethernet and wifi.
*                   \n The valid range of ethPort is from 0 to MaxEthPort-1, where MaxEthPort is platform specific.
* @param[out] pFlag - MACsec operation status value, to be returned. Use "TRUE" to represent MACsec is enabled and "FALSE" to represent MACsec is disabled.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_GetMACsecOperationalStatus(INT ethPort, BOOLEAN *pFlag);

/**
* @brief Start MACsec - Call should be Blocking.
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

/**
* @brief Stop MACsec - Call should be Blocking.
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

/**
* @brief Get the device specific processors DRAM and eMMC paths.
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
    int dhcp_opt; /*!< The DHCP option code or identifier */
    char * dhcp_opt_val; /*!< Pointer to the value associated with the DHCP option */
    struct dhcp_opt_list * next; /*!< Pointer to the next DHCP option in the list */
} dhcp_opt_list;

/**
* @brief  This function fills in 2 list, 1 for request option and 1 for send option.
*
* @param[out] req_opt_list - List to be filled for request dhcp options .
* @param[out] send_opt_list - List to be filled for send dhcp options.
*                          \n List of client structure to be filled by hal.
* <pre>
*                dhcp_opt_list is a structure with following members :
*
*                dhcp_opt                    - DHCPv4 Options. Possible values are :
*                                              DHCPV4_OPT_42 42 // NTP Server Addresses.
*                                              DHCPV4_OPT_43 43 // Vendor Specific Information.
*                                              DHCPV4_OPT_58 58 // DHCP Renewal (T1) Time.
*                                              DHCPV4_OPT_59 59 // DHCP Rebinding (T2) Time.
*                                              DHCPV4_OPT_60 60 // Class Identifier.
*                                              DHCPV4_OPT_61 61 // Client Identifier.
*                                              DHCPV4_OPT_100 100 // IEEE 1003.1 TZ String.
*                                              DHCPV4_OPT_122 122 // CableLabs Client Configuration.
*                                              DHCPV4_OPT_125 125 // Vendor-Identifying Vendor-Specific Information.
*                                              DHCPV4_OPT_242 242 // Private Use.
*                                              DHCPV4_OPT_243 243 // Private Use.
*                                              DHCPV4_OPT_END 255 // DHCP Option End - used to check if option is valid.
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

/**
* @brief This function fills in 2 list, 1 for request option and 1 for send option.
*
* @param[out] req_opt_list - List to be filled for request dhcp options.
* @param[out] send_opt_list - List to be filled for send dhcp options.
*                          \n List of client structure to be filled by hal.
* <pre>
*                dhcp_opt_list is a structure with following members :
*
*                dhcp_opt                    - DHCPv6 Options Possible values are :
*                                              DHCPV6_OPT_82 82 // OPTION_SOL_MAX_RT: Solicite Maximum Retry Time.
*                                              DHCPV6_OPT_23 23 // OPTION_SOL_MAX_RT: Solicite Maximum Retry Time.
*                                              DHCPV6_OPT_95 95 // OPTION_SOL_MAX_RT: Solicite Maximum Retry Time.
*                                              DHCPV6_OPT_24 24 // OPTION_DOMAIN_LIST.
*                                              DHCPV6_OPT_83 83 // OPTION_INF_MAX_RT.
*                                              DHCPV6_OPT_17 17 // OPTION_VENDOR_OPTS.
*                                              DHCPV6_OPT_31 31 // OPTION_SNTP_SERVERS.
*                                              DHCPV6_OPT_15 15 // User Class Option.
*                                              DHCPV6_OPT_16 16 // Vendor Class Option.
*                                              DHCPV6_OPT_20 20 // Reconfigure Accept Option.
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
   PSM_UNKNOWN=0, /*!< Unknown or unspecified PSM state. */
   PSM_AC, /*!< PSM state when the device is powered by an AC source. */
   PSM_BATT, /*!< PSM state when the device is powered by a battery source. */
   PSM_HOT, /*!< Hot PSM state, possibly indicating a high-temperature condition. */
   PSM_COOLED, /*!< Cooled PSM state, possibly indicating a temperature-regulated condition */
   PSM_NOT_SUPPORTED, /*!< State indicating that the specific PSM is not supported */
} PSM_STATE, *PPSM_STATE; //!< Power Saving Mode State

/**
* @brief Set Low Power Mode State value. Hysteresis currently not accounted for before call.
*
* @param[in] pState - Low Power Mode State.
*                  \n pState can hold any values from enum PPSM_STATE.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_SetLowPowerModeState(PPSM_STATE pState);

/**
* @brief Get CMTS MAC Address.
*
* @param[out] pValue - MAC address string in format AA:BB:CC:DD:EE:FF.
*                   \n The buffer size should be atleast 100 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_getCMTSMac(CHAR *pValue);


typedef  enum {
   DOCSIS=1, /*!< DOCSIS mode will be provisioned*/
   EWAN=2,  /*!< EthWAN mode will be provisioned*/
} WAN_INTERFACE;

typedef  enum {
   TRAFFIC_CNT_START=1, /*!< Traffic count start */
   TRAFFIC_CNT_STOP=2, /*!< Traffic count stop */
} TRAFFIC_CNT_COMMAND;

typedef struct Traffic_client {
    char mac[18]; /*!< The client mac e.g. 00:AA:BB:CC:DD:EE */
    ULONG rxBytes; /*!< The total number of bytes received by the client */
    ULONG txBytes; /*!< The total number of bytes transmitted by the client */
} Traffic_client_t, *pTraffic_client_t;

typedef struct DSCP_Element {
    UINT dscp_value; /*!< DSCP value. */
    UINT numClients; /*!< Number of clients associated with the DSCP value. */
    Traffic_client_t Client[256]; /*!< Array of traffic clients for the specified DSCP value. */
} DSCP_Element_t, *pDSCP_Element_t;

typedef struct DSCP_list {
    UINT numElements; /*!< Number of DSCP elements in the list. */
    DSCP_Element_t DSCP_Element[64]; /*!< Array of DSCP elements in the list. */
} DSCP_list_t, *pDSCP_list_t;

/**
* @brief Control/Set traffic counting based on Dscp value.
*
* @param[in] interfaceType - The WAN interface type (e.g., DOCSIS or EthWAN) for which DSCP values will be configured.
*                            \n interfaceType variable can hold any values from the enum WAN_INTERFACE.
* @param[in] cmd - START/STOP.
*                 \n cmd can hold any values from enum TRAFFIC_CNT_COMMAND.
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

/**
* @brief To reset Dscp Counter values.
*
* @param[in] interfaceType - The WAN interface type (e.g., DOCSIS or EthWAN) for which DSCP values will be configured.
*                            \n interfaceType variable can hold any values from the enum WAN_INTERFACE.
*
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_resetDscpCounts(WAN_INTERFACE interfaceType);


/**
* @brief To get counter data.
*
* @param[in] interfaceType - The WAN interface type (e.g., DOCSIS or EthWAN) for which DSCP values will be configured.
*                            \n interfaceType variable can hold any values from the enum WAN_INTERFACE.
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


/**
* @brief Get cpu speed.
*
* @param[out] cpuSpeed - It is the processor speed in bogomips.
*                     \n It is a vendor specific.
*                     \n The range of acceptable values is 0 to (2^64)-1 (inclusive).
*                     \n The buffer size should be at least 64 bytes long.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetCPUSpeed(char *cpuSpeed);

typedef  enum {
   ACTIVE_BANK, /*!< Active firmware bank state */
   INACTIVE_BANK, /*!< Inactive firmware bank state */
} FW_BANK;

typedef  struct _FW_BANK_INFO
{
      CHAR  fw_name[FW_NAME_MAX_LEN]; /* Firmware name associated with the bank */
      CHAR  fw_state[FW_STATE_MAX_LEN]; /* Firmware state information */
}
FW_BANK_INFO, *PFW_BANK_INFO;

/**
* @brief Get firmware image name flashed in the given Bank.
*
* @param[in] bankIndex - The parameter can hold any value from the enum FW_BANK.
* @param[out] pFW_Bankinfo - Structure variable containing Firmware image name and Firmware state.
* <pre>
*                _FW_BANK_INFO is a structure with the following parameters :
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

/**
* @brief Get Interface Stats for the given interface, considering only LAN to WAN/WAN to LAN traffic.
*
* @param[in] ifname - Interface name for which stats need to be fetched. 
*                     \n To acquire a list of available network interfaces that are platform specific, use the 'ifconfig -a' command to know the list all interfaces on each platform.
* @param[out] pIntfStats - Interface Stats structure, to be returned.
* <pre>
*                pIntfStats is a structure with the following parameters :
*                rx_packet                   - Packets received. The range of acceptable values is 0 to 2^64 - 1.
*                tx_packet                   - Packets sent. The range of acceptable values is 0 to 2^64 - 1.
*                rx_bytes                    - Bytes received. The range of acceptable values is 0 to 2^64 - 1.
*                tx_bytes                    - Bytes sent. The range of acceptable values is 0 to 2^64 - 1.
*
* </pre>
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetInterfaceStats(const char *ifname,PINTF_STATS pIntfStats);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @}
 */


