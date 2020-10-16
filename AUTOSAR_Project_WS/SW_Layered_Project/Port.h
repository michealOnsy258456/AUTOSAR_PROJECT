/*
 * Port_PBcfg.h
 *
 *  Created on: Mar 3, 2020
 *      Author: micheal_onsy
 */
#ifndef PORT_H
#define PORT_H

/* Id for the company in the AUTOSAR
 * for example Mohamed Tarek's ID = 1000 :) */
#define PORT_VENDOR_ID    (1000U)

/* Port Module Id */
#define PORT_MODULE_ID    (120U)

/* Port Instance Id */
#define PORT_INSTANCE_ID  (0U)

/*
 * Module Version 1.0.0
 */
#define PORT_SW_MAJOR_VERSION           (1U)
#define PORT_SW_MINOR_VERSION           (0U)
#define PORT_SW_PATCH_VERSION           (0U)

/*
 * AUTOSAR Version 4.0.3
 */
#define PORT_AR_RELEASE_MAJOR_VERSION   (4U)
#define PORT_AR_RELEASE_MINOR_VERSION   (0U)
#define PORT_AR_RELEASE_PATCH_VERSION   (3U)

/*
 * Macros for Port Status
 */
#define PORT_INITIALIZED                (1U)
#define PORT_NOT_INITIALIZED            (0U)

/* PORT DEFINES */
#define PORTA					(0U)
#define PORTB					(1U)
#define PORTC					(2U)
#define PORTD					(3U)
#define PORT_PIN0 							(Port_PinType)0
#define PORT_PIN1 							(Port_PinType)1
#define PORT_PIN2 							(Port_PinType)2
#define PORT_PIN3 							(Port_PinType)3
#define PORT_PIN4 							(Port_PinType)4
#define PORT_PIN5 							(Port_PinType)5
#define PORT_PIN6 							(Port_PinType)6
#define PORT_PIN7 							(Port_PinType)7

#define MAX_PIN_IN_PORT (8U)
/* PIN DEFINES */
#define PORT_A_PIN_0   (0U)
#define PORT_A_PIN_1   (1U)
#define PORT_A_PIN_2   (2U)
#define PORT_A_PIN_3   (3U)
#define PORT_A_PIN_4   (4U)
#define PORT_A_PIN_5   (5U)
#define PORT_A_PIN_6   (6U)
#define PORT_A_PIN_7   (7U)
#define PORT_B_PIN_0   (8U)
#define PORT_B_PIN_1   (9U)
#define PORT_B_PIN_2   (10U)
#define PORT_B_PIN_3   (11U)
#define PORT_B_PIN_4   (12U)
#define PORT_B_PIN_5   (13U)
#define PORT_B_PIN_6   (14U)
#define PORT_B_PIN_7   (15U)
#define PORT_C_PIN_0   (16U)
#define PORT_C_PIN_1   (17U)
#define PORT_C_PIN_2   (18U)
#define PORT_C_PIN_3   (19U)
#define PORT_C_PIN_4   (20U)
#define PORT_C_PIN_5   (21U)
#define PORT_C_PIN_6   (22U)
#define PORT_C_PIN_7   (23U)
#define PORT_D_PIN_0   (24U)
#define PORT_D_PIN_1   (25U)
#define PORT_D_PIN_2   (26U)
#define PORT_D_PIN_3   (27U)
#define PORT_D_PIN_4   (28U)
#define PORT_D_PIN_5   (29U)
#define PORT_D_PIN_6   (30U)
#define PORT_D_PIN_7   (31U)

/* Standard AUTOSAR types */
#include "Std_Types.h"

/* AUTOSAR checking between Std Types and Port Modules */
#if ((STD_TYPES_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (STD_TYPES_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Std_Types.h does not match the expected version"
#endif

/* Port Pre-Compile Configuration Header file */
#include "Port_Cfg.h"

/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_CFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_CFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_CFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_CFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif


/****************************************************************************************************************/
/**/
/* Non AUTOSAR files */
#include "Common_Macros.h"

/******************************************************************************
 *                      API Service Id Macros                                 *
 ******************************************************************************/
/* Service ID for PORT Initialization  */
#define PORT_INIT_SID           				     (uint8)0x00

/* Service ID for PORT set pin direction */
#define PORT_SET_PIN_DIRECTION_SID          		 (uint8)0x01

/* Service ID for PORT refresh direction */
#define PORT_REFRESH_PORT_DIRECTION_SID              (uint8)0x02

/* Service ID for PORT get info */
#define PORT_GET_INFO_SID              			 	 (uint8)0x03

/* Service ID for PORT set pin mode */
#define PORT_SET_PIN_MODE_SID						 (uint8)0x04

/*******************************************************************************
 *                      DET Error Codes                                        *
 *******************************************************************************/
/* Invalid Port Pin ID requested */
#define PORT_E_PARAM_PIN 			   (uint8)0x0A

/* Port Pin not configured as changeable */
#define PORT_E_DIRECTION_UNCHANGEABLE  (uint8)0x0B

/* API Port_Init service called with wrong parameter */
#define PORT_E_PARAM_CONFIG 		   (uint8)0x0C

/* API Port_SetPinMode service called with invalid mode */
#define PORT_E_PARAM_INVALID_MODE 	   (uint8)0x0D

/* API Port_SetPinMode service called when mode is unchangeable */
#define PORT_E_MODE_UNCHANGEABLE 	   (uint8)0x0E

/* API service called without module initialization */
#define PORT_E_UNINIT 				   (uint8)0x0F

/* APIs called with a Null Pointer */
#define PORT_E_PARAM_POINTER 		   (uint8)0x10

/*******************************************************************************
 *                              Module Data Types                              *
 *******************************************************************************/

/* Type definition for Port pin mode from mode list for use with Port_Init() function */


#define PORT_PIN_NUM (32U)

/*Data type for the symbolic name of a port pin*/
typedef uint16 Port_PinType;
/*Different port pin modes*/
typedef uint8 Port_PinModeType;
/*Possible directions of a port pin*/

typedef enum {
	PORT_PIN_IN,
	PORT_PIN_OUT
} Port_PinDirectionType;

typedef enum {
	Disable_Pullup,
	Enable_Pullup
} Port_Input_Mode;

typedef enum {
	initial_Low,
	initial_High
} Port_Initial_Value;

typedef struct {
	uint8 port;
	Port_PinType pin_num;
	Port_PinDirectionType direction;
	Port_Initial_Value initial_Value;
	Port_Input_Mode pin_in_mode;
} Port_ConfigChannel;

/*Type of the external data structure containing the initialization data for this module. */
typedef struct {
	Port_ConfigChannel Ports[PORT_CONFIGURED_CHANNLES];
} Port_ConfigType;

/*******************************************************************************
 *                      Function Prototypes                                    *
 *******************************************************************************/

/* Initializes the Port Driver module */
void Port_Init(const Port_ConfigType *ConfigPtr);

/* Sets the port pin direction */
#if (PORT_SET_PIN_DIRECTION_API == STD_ON)
void Port_SetPinDirection(Port_PinType Pin, Port_PinDirectionType Direction);
#endif

/* Refreshes port direction */
void Port_RefreshPortDirection(void);

/* Returns the version information of this module */
void Port_GetVersionInfo(Std_VersionInfoType *versioninfo);

/*Sets the port pin mode*/
void Port_SetPinMode(Port_PinType Pin, Port_PinModeType Mode);

/* Port Post-Compile Configuration Header file */
#include "Port_PBcfg.h"
/* AUTOSAR Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_PBCFG_AR_RELEASE_MAJOR_VERSION != PORT_AR_RELEASE_MAJOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_MINOR_VERSION != PORT_AR_RELEASE_MINOR_VERSION)\
 ||  (PORT_PBCFG_AR_RELEASE_PATCH_VERSION != PORT_AR_RELEASE_PATCH_VERSION))
  #error "The AR version of Dio_Cfg.h does not match the expected version"
#endif

/* Software Version checking between Port_Cfg.h and Port.h files */
#if ((PORT_PBCFG_SW_MAJOR_VERSION != PORT_SW_MAJOR_VERSION)\
 ||  (PORT_PBCFG_SW_MINOR_VERSION != PORT_SW_MINOR_VERSION)\
 ||  (PORT_PBCFG_SW_PATCH_VERSION != PORT_SW_PATCH_VERSION))
  #error "The SW version of Dio_Cfg.h does not match the expected version"
#endif


#endif /* PORT_H */
