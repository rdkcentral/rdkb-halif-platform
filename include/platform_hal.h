/*
 * If not stated otherwise in this file or this component's LICENSE file the
 * following copyright and licenses apply:
 *
 * Copyright 2023 RDK Management
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
 * 
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
#define DHCPV6_OPT_3    3  // Identity Association for Non-temporary Addresses Option
#define DHCPV6_OPT_5    5  // IA Address Option
#define DHCPV6_OPT_15  15  // User Class Option
#define DHCPV6_OPT_16  16  // Vendor Class Option
#define DHCPV6_OPT_17  17  // OPTION_VENDOR_OPTS
#define DHCPV6_OPT_20  20  // Reconfigure Accept Option
#define DHCPV6_OPT_22  22  // OPTION_SIP_SERVER_A
#define DHCPV6_OPT_23  23  // DNS Recursive Name Server option
#define DHCPV6_OPT_24  24  // OPTION_DOMAIN_LIST
#define DHCPV6_OPT_25  25  // Identity Association for Prefix Delegation Option
#define DHCPV6_OPT_31  31  // OPTION_SNTP_SERVERS
#define DHCPV6_OPT_64  64  // OPTION_AFTR_NAME 
#define DHCPV6_OPT_82  82  // OPTION_SOL_MAX_RT: Solicite Maximum Retry Time
#define DHCPV6_OPT_83  83  // OPTION_INF_MAX_RT
#define DHCPV6_OPT_95  95  // OPTION_SOL_MAX_RT: Solicite Maximum Retry Time

//DHCPv4 Options
#define DHCPV4_OPT_2   2   // Time Offset
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
/**
 * @brief Represents the types of CPUs in an RDK system.
 *
 * This enumeration is used to distinguish between different CPU types 
 * within an RDK (Reference Design Kit) environment. It provides a mechanism 
 * to differentiate between the main host processor, any secondary or peer 
 * processors, and processors that are not supported or recognized within the 
 * RDK framework.
 */
typedef enum {
   HOST_CPU=0,          /**< Represents the main host CPU, which typically handles 
                             primary tasks and operations in the RDK environment. */

   PEER_CPU=1,          /**< Represents a secondary or peer CPU. These CPUs might be 
                             used for offloading specific tasks, handling parallel 
                             processes, or managing other dedicated operations 
                             alongside the main host CPU. */

   NOT_SUPPORTED_CPU=3  /**< Denotes an unsupported or unrecognized CPU type. This value 
                             can be used to identify and handle scenarios where a CPU type 
                             is encountered that doesn't match known configurations in 
                             the RDK environment. */
} 
RDK_CPUS; //!< Enum type indicating the CPU classifications within the RDK framework.

#ifndef PLAT_PROC_MEM_MAX_LEN
#define PLAT_PROC_MEM_MAX_LEN   40 /**< Maximum length for memory path strings */
#endif

/**********************************************************************
                STRUCTURE DEFINITIONS
**********************************************************************/
/**
 * @brief Represents memory paths in a platform.
 *
 * Holds information about the memory paths used by a specific platform.
 * Provides paths for DRAM and multiple eMMC memories. These paths are generally
 * used for accessing or mounting memory storage locations in the system.
 *
 * @note Ensure that any path specified does not exceed the buffer size
 * limit defined by the `PLAT_PROC_MEM_MAX_LEN` macro.
 */
typedef struct _PLAT_PROC_MEM_INFO
{
    CHAR dramPath[PLAT_PROC_MEM_MAX_LEN];   /**< @brief Path to DRAM memory.
                                                Typically set to "/tmp".
                                                Ensure the path doesn't exceed
                                                a 40-byte buffer size. */

    CHAR emmcPath1[PLAT_PROC_MEM_MAX_LEN];  /**< @brief Path to the first eMMC memory.
                                                Possible values include "/nvram".
                                                Path should not exceed 40 bytes. */

    CHAR emmcPath2[PLAT_PROC_MEM_MAX_LEN];  /**< @brief Path to the second eMMC memory.
                                                "/nvram2" is a common value.
                                                Ensure path is under 40 bytes. */

    CHAR emmcPath3[PLAT_PROC_MEM_MAX_LEN];  /**< @brief Path to the third eMMC memory.
                                                This field is currently unused.
                                                Despite this, its value should
                                                not exceed 40 bytes. */
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
* @param[out] pValue  - Pointer to a buffer where the Device Configuration status will be returned.
*                    \n Possible string values are 'WaitForImplement', 'In Progress', 'Complete'.
*                    \n The buffer pointed by pValue should be allocated with a size of at least 128 bytes, 
*                    which is the recommended maximum length for the returned status string.
*
* @return The status of the operation.
* @retval RETURN_OK if the operation is successful.
* @retval RETURN_ERR if any error is detected during the operation.
*
*/
INT platform_hal_GetDeviceConfigStatus(CHAR *pValue);

/**
* @brief Get telnet enable status.
*
* @param[out] pFlag - Pointer to a BOOLEAN variable where the Telnet enable status will be stored.
*                  \n Set to TRUE if Telnet is enabled.
*                  \n Set to FALSE if Telnet is disabled.
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
*                     \n The buffer pointed by pValue should be allocated with a size of at least 32 bytes,
*                     which is the recommended maximum length for the returned status string.
*                     \n Possible values stored in the buffer are:
*                     \n 'rgWan': SNMP enabled for WAN interface.
*                     \n 'rgDualIp': SNMP enabled for dual IP configuration.
*                     \n 'rgLanIp': SNMP enabled for LAN IP configuration.
*
* @return The status of the operation.
* @retval RETURN_OK if the operation is successful.
* @retval RETURN_ERR if any error is detected during the operation.
*
*/
INT platform_hal_GetSNMPEnable(CHAR *pValue);

/**
* @brief Set SNMP Enable value for the device.
*
* @param[in] pValue - Pointer to a buffer containing the SNMP enable value to be set.
*                     \n The buffer pointed by pValue should have a size of at least 32 bytes,
*                     which is the recommended maximum length for the input value.
*                     \n Possible values that can be set are:
*                     \n 'rgWan': Set SNMP to be enabled for WAN interface.
*                     \n 'rgDualIp': Set SNMP to be enabled for dual IP configuration.
*                     \n 'rgLanIp': Set SNMP to be enabled for LAN IP configuration.
*
* @return The status of the operation.
* @retval RETURN_OK if the operation is successful.
* @retval RETURN_ERR if any error is detected during the operation.
*
*/
INT platform_hal_SetSNMPEnable(CHAR *pValue);

/**
* @brief Get WebUI timeout value.
*
* @param[out] pValue - Pointer to store the WebUI timeout value, expressed in seconds.
*                   \n Valid range of values is from 30 to 86400 seconds.
*                   \n Default value is 840 seconds.
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
* @param[in] value - WebUI timeout value to be set, expressed in seconds.
*                 \n Valid range of values are 0 and from 30 to 86400 seconds.
*                 \n A value of 0 may represent a specific mode or behavior (e.g., no timeout).
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
* @brief Initialize the PandM (Platform and Management) Database.
*
* Initializes the PandM Database for storing and managing platform-specific configurations. 
* Ensures the database is set up and ready for operations. If already initialized, behavior may vary 
* based on the implementation.
*
* @return The status of the operation.
* @retval RETURN_OK if the initialization is successful.
* @retval RETURN_ERR if any error occurs during initialization.
*
*/
INT platform_hal_PandMDBInit(void);

/**
* @brief Initialize the Platform HAL DOCSIS Parameters Database.
*
* Sets up the database for DOCSIS (Data Over Cable Service Interface Specification) parameters within the Platform HAL.
* This database is crucial for handling cable modem configurations and data. Depending on the implementation,
* if the database is already initialized, this function's behavior might vary.
*
* @return The status of the operation.
* @retval RETURN_OK if the initialization is successful.
* @retval RETURN_ERR if any error occurs during initialization.
*
*/
INT platform_hal_DocsisParamsDBInit(void);

/**
* @brief Get device model name.
*
* @param[out] pValue - Pointer to store the Device Model Name.
*                   \n It represents a vendor-specific value.
*                   \n The buffer size should be at least 256 bytes long and is considered as the maximum limit for the model name length.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetModelName(CHAR *pValue);

/**
* @brief Get router region.
*
* @param[out] pValue - Pointer to store the Router region name.
*                   \n Possible values of pValue are `REGION_UK`, `REGION_IT`, `REGION_ROI`, and `REGION_UNKNOWN`.
*                   \n The buffer size should be at least 256 bytes long, which is considered the maximum limit for the region name.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetRouterRegion(CHAR *pValue);

/**
* @brief Get device serial number.
*
* @param[out] pValue - Pointer to store the Device Serial Number.
*                   \n It represents a vendor-specific value.
*                   \n The buffer size should be at least 256 bytes long, which is considered as the maximum limit for the serial number length.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetSerialNumber(CHAR *pValue);

/**
* @brief Get hardware version of the device.
*
* @param[out] pValue - Pointer to store the Hardware version.
*                   \n It represents a vendor-specific value.
*                   \n The buffer size should be at least 256 bytes long, which stands as the maximum allowable limit for the hardware version string.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetHardwareVersion(CHAR *pValue);

/**
* @brief Get software version flashed in the device.
*
* @param[out] pValue  - Pointer to store the Software version.
*                   \n It represents a vendor-specific value.
* @param[in] maxSize  - Indicates the size of the buffer allocated for pValue.
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
*
* @return The status of the operation.
* @retval RETURN_OK  if successful.
* @retval RETURN_ERR If any error is detected.
*
*/
INT platform_hal_GetBootloaderVersion(CHAR *pValue, ULONG maxSize);

/**
* @brief Get firmware image name flashed in the device.
*
* @param[out] pValue - Firmware image name, to be returned.
*                   \n It is a vendor specific value.
* @param[in] maxSize - Size of the buffer allocated for pValue.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetFirmwareName(CHAR *pValue, ULONG maxSize);

/**
* @brief Get base MAC Address of the device.
*
* @param[out] pValue - Pointer to store the Base MAC Address.
*                   \n The MAC Address should be in the format AA:BB:CC:DD:EE:FF (colon-separated) and zero-terminated (zt).
*                   \n The buffer size should be at least 256 bytes long, which is considered as the maximum limit for the MAC address storage, including any null terminators or additional information.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetBaseMacAddress(CHAR *pValue);

/**
* @brief Get the Hardware for the total flash size of the device in megabytes (MB).
*
* This function retrieves the total flash memory size of the hardware device, expressed in MB.
*
* @param[out] pValue - Pointer to store the total flash size.
*                   \n The returned value represents the flash size in MB.
*                   \n The pValue output returned should be in the range [1, 4096], representing the minimum and maximum supported flash sizes in MB.
*                   \n The buffer size allocated for pValue should be at least 256 bytes. A buffer of this size ensures space for the returned value and any null terminators or additional information.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetHardware(CHAR *pValue);

/**
* @brief Get the total used memory of the flash in megabytes (MB).
*
* This function retrieves the total used flash memory size of the device, expressed in MB.
*
* @param[out] pValue - Pointer to store the total used flash size.
*                   \n The returned value represents the used flash size in MB.
*                   \n The pValue output will be in the range [1, n] inclusive, where n is the total flash size in MB available in the device.
*                   \n The buffer size allocated for pValue should be at least 1024 bytes and not exceed 2048 bytes. This range ensures space for the returned value, any null terminators, and additional information.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetHardware_MemUsed(CHAR *pValue);

/**
* @brief Get the total available memory of the flash in megabytes (MB).
*
* This function retrieves the total available flash memory size of the device, expressed in MB.
*
* @param[out] pValue - Pointer to store the total available flash size.
*                   \n The returned value represents the available flash size in MB.
*                   \n The pValue output will be in the range [1, n] inclusive, where n is the total flash size in MB minus used space on the device.
*                   \n The returned string will be Zero Terminated (ZT).
*                   \n The buffer size allocated for pValue should be at least 1024 bytes long to ensure space for the returned value, the zero terminator, and additional information.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetHardware_MemFree(CHAR *pValue);

/**
* @brief Get total memory size of the DRAM (Dynamic Random Access Memory) in megabytes (MB).
*
* This function retrieves the total memory size of the DRAM available on the device, expressed in MB.
*
* @param[out] pulSize - Pointer to store the total memory size of DRAM.
*                    \n The returned value represents the DRAM size in MB.
*                    \n The pulSize output will be in the range [1, n] inclusive, where "n" is the maximum DRAM size available in MB on the device.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetTotalMemorySize(ULONG *pulSize);

/**
* @brief Get the total used memory of the DRAM (Dynamic Random Access Memory) in megabytes (MB).
*
* This function retrieves the amount of DRAM memory currently in use by the system, expressed in MB.
*
* @param[out] pulSize - Pointer to store the total used memory size of DRAM.
*                    \n The returned value represents the used DRAM size in MB.
*                    \n The value will be in the range [1, n] inclusive, where "n" is the total DRAM size available in MB on the device.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetUsedMemorySize(ULONG *pulSize);

/**
* @brief Get the total available memory of the DRAM (Dynamic Random Access Memory) in megabytes (MB).
*
* This function retrieves the amount of DRAM memory that is currently free or available in the system, expressed in MB.
*
* @param[out] pulSize - Pointer to store the total available memory size of DRAM.
*                    \n The returned value represents the available DRAM size in MB.
*                    \n The value will be in the range [1, n] inclusive, where "n" is the total DRAM size available in MB on the device.
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
* @brief Reset the factory reset count on the device command "Device.DeviceInfo.ClearResetCount".
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
* This function retrieves the time offset in seconds from UTC (Coordinated Universal Time).
*
* @param[out] timeOffSet - Pointer to store the time offset in seconds.
*                       \n The valid values for timeOffSet are as follows :
*                       \n '-25200': Eastern Standard Time (EST) = UTC-5.
*                       \n '-18000': Mountain Standard Time (MST) = UTC-7 (default).
*                       \n '+25200': Indonesia Western Time = UTC+7.
*                       \n The returned value is expressed in seconds relative to UTC.
*                       \n The buffer size allocated for timeOffSet should be at least 256 bytes to accommodate the offset value and any null terminators or additional information.
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
 * @}
 */

/**
 * @addtogroup PLATFORM_HAL_TYPES
 * @{
 */

#define LED_BUFFER_SIZE 3

/**
* @enum LED_COLOR
* @brief Defines the available LED color options for the device.
*/
typedef enum {
    LED_WHITE=0,                //!< Default LED color.
    LED_YELLOW=1,               //!< This is also classified as Amber from RDKB perspective.
    LED_GREEN=2,                //!< Green LED color.
    LED_RED=3,                  //!< Red LED color.
    LED_BLUE=4,                 //!< Blue LED color.
    LED_RED_AND_GREEN=5,        //!< Combination of Red and Green LED colors.
    LED_YELLOW_AND_GREEN=6,     //!< Combination of Yellow and Green LED colors.
    NOT_SUPPORTED=7             //!< Indicates the LED color is not supported.
} LED_COLOR;

/**
* @struct LEDMGMT_PARAMS
* @brief Parameters for managing the LED behavior on the device.
*/
typedef struct _LEDMGMT_PARAMS
{
#ifdef FEATURE_RDKB_LED_MANAGER
    char * led_name;            //!< Name of the LED.
    char * led_param;           //!< Additional parameters for the LED.
#endif
    LED_COLOR  LedColor;        //!< LED color choice from @ref LED_COLOR enum.
    INT  State;                 //!< LED state (0 for Solid, 1 for Blink).
    INT  Interval;              //!< Blink interval duration (in seconds) when LED state is set to Blink.
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
int platform_hal_initLed(char *config_file_name);
#endif

/**
* @brief Sets the LED behavior on the device as per the provided configuration.
*
* This function allows the configuration of the LED's color, state (Solid/Blink), and blink interval.
*
* @param[in] pValue A pointer to the LEDMGMT_PARAMS structure containing the desired LED configuration.
*
* @return The status of the operation.
* @retval RETURN_OK if the LED behavior was successfully set.
* @retval RETURN_ERR if any error occurred during the operation.
*/
INT platform_hal_setLed(PLEDMGMT_PARAMS pValue);

/**
* @brief Get the LED behavior of the device at the time of call.
*
* @param[out] pValue Pointer to the LEDMGMT_PARAMS structure where the current LED configuration will be stored.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getLed(PLEDMGMT_PARAMS pValue);

/**
* @brief Retrieve the PWM (pulse width modulation) setting for the specified fan.
*
* This function is used to get the current fan speed based on its PWM setting. The speed result reflects the actual RPM or percentage of maximum RPM, not just the PWM value.
*
* @param[in] fanIndex Index of the fan for which the speed is to be retrieved.
*                     \n Valid range for fanIndex is [0, 1], meaning only two fans (indexed 0 and 1) are supported.
*
* @return FanSpeed in unsigned int.
* @retval The range for FanSpeed is [0, n]. Here, "n" is dependent on the OEM's fan speed specification, where "n" could represent the maximum RPM or 100% speed.
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
* @brief Override the fan's speed setting, setting it to either run at maximum speed or restoring its default behavior.
*
* This function allows the user to override the fan's default behavior and set it to run at its maximum speed or, if already set to max speed, to revert back to its normal speed.
*
* @param[in] bOverrideFlag Boolean value to enable (if set to TRUE) or disable (if set to FALSE) the fan's maximum speed override.
* @param[in] fanIndex Index of the fan for which the maximum speed override setting is to be applied.
*                     \n Valid range for fanIndex is [0, 1], meaning only two fans (indexed 0 and 1) are supported.
*
* @return The status of the operation.
* @retval RETURN_OK if successfully set/unset the fan to/from high-speed mode.
* @retval RETURN_ERR if an error occurs.
*/
INT platform_hal_setFanMaxOverride(BOOLEAN bOverrideFlag, UINT fanIndex);

#ifdef FEATURE_RDKB_THERMAL_MANAGER

/**
 * @enum FAN_SPEED
 * @brief Enumerates the various speed settings for a fan.
 */
typedef enum {
   FAN_SPEED_OFF=0,      /**< Represents the fan being turned off. */
   FAN_SPEED_SLOW=1,     /**< Represents a slow fan speed. */
   FAN_SPEED_MEDIUM=2,   /**< Represents a medium fan speed. */
   FAN_SPEED_FAST=3,     /**< Represents a fast fan speed. */
   FAN_SPEED_MAX=4       /**< Represents the maximum speed setting for the fan. */
} FAN_SPEED;

/**
 * @struct _FAN_PLATFORM_CONFIG
 * @brief Contains configuration settings related to fan operation in a platform.
 *
 * This structure holds various thresholds and timings that dictate how fans operate and
 * how their speed changes in response to different conditions.
 */
typedef struct _FAN_PLATFORM_CONFIG
{
   UINT FanCount;          /**< Total number of fans in the system. Can be either 1 or 2. */
   UINT SlowSpeedThresh;   /**< Temperature threshold (in °C) for classifying a fan speed as "slow". Typically set to 30°C. */
   UINT MediumSpeedThresh; /**< Temperature threshold (in °C) for classifying a fan speed as "medium". Typically set to 35°C. */
   UINT FastSpeedThresh;   /**< Temperature threshold (in °C) for classifying a fan speed as "fast". Typically set to 40°C. */
   UINT FanMinRunTime;     /**< The minimum runtime (in seconds) a fan has to run before it can be turned off. Usually set to 30 seconds. */
   UINT MonitoringDelay;   /**< Delay (in seconds) between monitoring checks for fan speed and conditions. */
   UINT PowerMonitoring;   /**< Power monitoring configuration for the fans. */
   UINT LogInterval;       /**< Interval (in seconds) at which fan-related data should be logged. */
} THERMAL_PLATFORM_CONFIG;

/**
* @brief Initialise Thermal Hal.
*
* @param[out] pThermalPlatformConfig Pointer to the platform's thermal configuration described by the THERMAL_PLATFORM_CONFIG structure.
*
* @return The status of the operation.
* @retval RETURN_OK on successful initialisation.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_initThermal(THERMAL_PLATFORM_CONFIG *pThermalPlatformConfig);

/**
* @brief Loads default Thermal Hal thresholds.
*
* @param[out] pThermalPlatformConfig Pointer to the platform's thermal configuration.
* Refer to the THERMAL_PLATFORM_CONFIG structure for details on the configuration parameters.
*
* @return The status of the operation.
* @retval RETURN_OK on successful loading of the thermal configuration.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_LoadThermalConfig(THERMAL_PLATFORM_CONFIG *pThermalPlatformConfig);

/**
 * @enum FAN_ERR
 * @brief Enumerates the possible error states for fan operations.
 */
typedef enum {
   FAN_ERR_NONE = 0,          /**< No error, the operation was successful. */
   FAN_ERR_HW = 1,            /**< Hardware error related to the fan. */
   FAN_ERR_MAX_OVERRIDE_SET = 2 /**< Error indicating that maximum override is already set. */
} FAN_ERR;

/**
* @brief Set the fan speed.
*
* @param[in] fanIndex Index of the fan for which the speed is to be set. 
*                     Valid range is from 0 to 1 (fanIndex value should be less than 2).
* @param[in] fanSpeed Desired fan speed setting. 
*                     Values can be taken from the FAN_SPEED enumeration.
* @param[out] pErrReason Pointer to store any error that may occur during the operation. 
*                        Values returned can be from the FAN_ERR enumeration.
*
* @return The status of the operation.
* @retval RETURN_OK if successful in setting the fan speed.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_setFanSpeed(UINT fanIndex, FAN_SPEED fanSpeed, FAN_ERR *pErrReason);

/**
* @brief Get current device temperature reading.
*
* @param[out] pTemp Pointer to store the temperature reading.
*                   The valid range for the temperature reading is from 0 to 100 degrees Celsius
*                   as defined by the platform's requirements.
*
* @return The status of the operation.
* @retval RETURN_OK on successfully retrieving the temperature reading.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getFanTemperature(INT *pTemp);

/* platform_hal_getInputCurrent() function */
/**
* @brief To get input current.
*
* @param[out] pValue - Pointer to an integer variable to store the input current in milli-Amperes.
*                     \n Valid values for pValue are in the range of 0 to 20000 milli-Amperes (mA).
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_getInputCurrent(INT *pValue);

/**
 * @brief Get the input power in milli-Watts.
 *
 * This function retrieves the power consumed by the platform and stores it in the provided pointer.
 *
 * @param[out] pValue - Pointer to an integer variable to store the input power in milli-Watts.
 *                     Valid values for pValue are in the range of 0 to 20000 milli-Watts (mW).
 *
 * @return The status of the operation.
 * @retval RETURN_OK if the input power is successfully retrieved.
 * @retval RETURN_ERR if an error is encountered during the operation.
 *
 */
INT platform_hal_getInputPower(INT *pValue);

/**
 * @brief Get the temperature of a specific radio module.
 *
 * This function retrieves the temperature of a radio module identified by `radioIndex`
 * and stores it in the provided pointer `pValue`.
 *
 * @param[in] radioIndex - Index of the radio module to query.
 *                         \n Possible values are 0, 1 and 2.
 *                         \n value 0 means 2.4GHz WiFi radio, value 1 means 5GHz WiFi (Low Band) radio and value 2 means 5GHz WiFi (High Band) radio.
 * @param[out] pValue - Pointer to an integer variable to store the radio temperature in degrees Celsius.
 *                      \n Valid values for `pValue` are in the range of 0 to 100 degrees Celsius.
 *
 * @return The status of the operation.
 * @retval RETURN_OK if the radio temperature is successfully retrieved.
 * @retval RETURN_ERR if an error is encountered during the operation.
 *
 */
INT platform_hal_getRadioTemperature(INT radioIndex, INT *pValue);


/**
 * @brief Get the ECO mode status for a specific radio module.
 *
 * This function retrieves the ECO mode status of radio module identified by `radioIndex`
 *
 * @param[in] radioIndex - Index of the radio module to query.
 *                         \n Possible values are 0, 1.
 *                         \n value 0 means 2.4GHz WiFi radio, value 1 means 5GHz WiFi radio.
 * @param[out] pValue - Pointer to an integer variable to store the ECO mode status .
 *                         \n Possible values are 0, 1.
 *                         \n value 0 means ECO mode is disabled, value 1 means ECO mode is enabled.
 *
 * @return The status of the operation.
 * @retval RETURN_OK if the ECO mode is successfully retrieved.
 * @retval RETURN_ERR if an error is encountered during the operation.
 *
 */
INT platform_hal_getEcoModeStatus(INT radioIndex, INT *pValue);

#endif

/**
* @brief Set SNMP Onboard Reboot Enable value to allow or ignore SNMP reboot.
*
* @param[in] pValue - SNMP Onboard Reboot Enable value.
*                  \n Possible values are "disable" and "enable" (case-insensitive).
*                  \n The string size shouldn't exceed 8 bytes. It is a zero-terminated string.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*/
INT platform_hal_SetSNMPOnboardRebootEnable(CHAR *pValue);


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
*                    \n Host is the primary RDK CPU .
*                    \n index can hold any values from enum RDK_CPUS.
* @param[out] ppinfo - Pointer to get the return array.
*                      \n List of client structure to be filled by hal.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
* @execution Synchronous.
*
* @note HAL function need to allocate the array of PLAT_PROC_MEM_INFO and return with ppinfo.
*
*/
INT platform_hal_GetMemoryPaths(RDK_CPUS index, PPLAT_PROC_MEM_INFO *ppinfo);

/**
 * @brief Struct to represent a list of DHCPv4 or DHCPv6 options.
 *
 * The structure represents a linked list, where each node contains 
 * an option and its corresponding value.
 */
typedef struct dhcp_opt_list {
    int dhcp_opt; /*!< The DHCP option code or identifier. The DHCP option code value can be DHCPv4 or DHCPv6 Possible values. DHCPv6 Options Possible values are "DHCPV6_OPT_82", "DHCPV6_OPT_23", "DHCPV6_OPT_95", "DHCPV6_OPT_24", "DHCPV6_OPT_83", "DHCPV6_OPT_17", "DHCPV6_OPT_31", "DHCPV6_OPT_15", "DHCPV6_OPT_16", "DHCPV6_OPT_20" . DHCPv4 Options Possible values are "DHCPV4_OPT_42", "DHCPV4_OPT_43", "DHCPV4_OPT_58", "DHCPV4_OPT_59", "DHCPV4_OPT_60", "DHCPV4_OPT_61", "DHCPV4_OPT_100", "DHCPV4_OPT_122", "DHCPV4_OPT_125", "DHCPV4_OPT_242", "DHCPV4_OPT_243", "DHCPV4_OPT_END" */
    char * dhcp_opt_val; /*!< Pointer to the value associated with the DHCP option code*/
    struct dhcp_opt_list * next; /*!< Pointer to the next DHCP option in the list */
} dhcp_opt_list;

/**
* @brief  This function fills in 2 list, 1 for request option and 1 for send option.
*
* @param[out] req_opt_list - Pointer to the list of requested DHCPv4 options.
* @param[out] send_opt_list - Pointer to the list of DHCPv4 options to be sent.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetDhcpv4_Options(dhcp_opt_list **req_opt_list, dhcp_opt_list **send_opt_list);

/**
* @brief This function fills in 2 list, 1 for request option and 1 for send option.
*
* @param[out] req_opt_list -  Pointer to the list of requested DHCPv6 options. 
* @param[out] send_opt_list - Pointer to the list of DHCPv6 options to be sent.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetDhcpv6_Options ( dhcp_opt_list **req_opt_list, dhcp_opt_list **send_opt_list);

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
*                     \n pState can hold any values from enum PPSM_STATE.
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
* This function is used to obtain the CMTS (Cable Modem Termination System) MAC address.
* The MAC address is populated in the provided buffer.
*
* @param[out] pValue   Pointer to the buffer where the CMTS MAC address will be written.
*                      \n The buffer size should be at least 100 bytes in size.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_getCMTSMac(CHAR *pValue);


typedef enum {
   DOCSIS=1, /*!< DOCSIS mode will be provisioned*/
   EWAN=2,  /*!< EthWAN mode will be provisioned*/
} WAN_INTERFACE;

typedef enum {
   TRAFFIC_CNT_START=1, /*!< Traffic count start */
   TRAFFIC_CNT_STOP=2,  /*!< Traffic count stop */
} TRAFFIC_CNT_COMMAND;

typedef struct Traffic_client {
    char mac[18];    /*!< The client mac e.g. 00:AA:BB:CC:DD:EE */
    ULONG rxBytes;   /*!< The total number of bytes received by the client, Possible values from 0 to 2^64-1.*/
    ULONG txBytes;   /*!< The total number of bytes transmitted by the client,  Possible values from 0 to 2^64-1. */
} Traffic_client_t, *pTraffic_client_t;

typedef struct DSCP_Element {
    UINT dscp_value;                /*!< DSCP value. Maximum value for dcspvalue is 65,535 range [ 0- 65,534]*/
    UINT numClients;                /*!< Number of clients associated with the DSCP value. Maximum value for numClients is 255 range [ 0-255]*/
    Traffic_client_t Client[256];   /*!< Traffic_client_t structure is used to hold up to 256 traffic clients for the specified DSCP value in an array. */
} DSCP_Element_t, *pDSCP_Element_t;

typedef struct DSCP_list {
    UINT numElements;                  /*!< Number of DSCP elements in the list. Maximum value for numElements is 64 range [ 0-63] */
    DSCP_Element_t DSCP_Element[64];   /*!< The DSCP_Element_t structure is used to hold up to 64 DSCP elements in an array. */
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
INT platform_hal_setDscp(WAN_INTERFACE interfaceType , TRAFFIC_CNT_COMMAND cmd , char *pDscpVals);

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
      CHAR  fw_name[FW_NAME_MAX_LEN]; /*!< Firmware name. Vendor specific. The buffer size should be at least FW_NAME_MAX_LEN bytes long */
      CHAR  fw_state[FW_STATE_MAX_LEN]; /*!< Firmware state information, Expected values are confirmed, from `TrialBoot#0` to `TrialBoot#n`. TrialBoot value can vary from 0 to n, where "n" is vendor specific. The buffer size should be at least FW_STATE_MAX_LEN bytes long. */
}
FW_BANK_INFO, *PFW_BANK_INFO;

/**
* @brief Get firmware image name flashed in the given Bank.
*
* @param[in] bankIndex - The parameter can hold any value from the enum FW_BANK.
* @param[out] pFW_Bankinfo - Structure variable containing Firmware image name and Firmware state.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetFirmwareBankInfo(FW_BANK bankIndex,PFW_BANK_INFO pFW_Bankinfo);

typedef  struct _INTF_STATS
{
   UINT64_t rx_packet; /*!< Packets received. The range of acceptable values is 0 to 2^64 - 1. */
   UINT64_t tx_packet; /*!< Packets sent. The range of acceptable values is 0 to 2^64 - 1. */
   UINT64_t rx_bytes;  /*!< Bytes received. The range of acceptable values is 0 to 2^64 - 1 */
   UINT64_t tx_bytes;  /*!< Bytes sent. The range of acceptable values is 0 to 2^64 - 1. */
}
INTF_STATS, *PINTF_STATS;

/**
* @brief Get Interface Stats for the given interface, considering only LAN to WAN/WAN to LAN traffic.
*
* @param[in] ifname - Interface name for which stats need to be fetched. 
*                     \n To acquire a list of available network interfaces that are platform specific, use the 'ifconfig -a' command to know the list all interfaces on each platform.
* @param[out] pIntfStats - Interface Stats structure, to be returned.
*
* @return The status of the operation.
* @retval RETURN_OK if successful.
* @retval RETURN_ERR if any error is detected.
*
*/
INT platform_hal_GetInterfaceStats(const char *ifname,PINTF_STATS pIntfStats);

INT platform_hal_GetPppUserName(CHAR* pUserName, ULONG maxSize);
INT platform_hal_GetPppPassword(CHAR* pPassword, ULONG maxSize);

#ifdef __cplusplus
}
#endif

#endif

/**
 * @}
 */


