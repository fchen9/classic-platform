/* 
* Configuration of module Os (Os_Cfg.c)
* 
* Created by: 
* Configured for (MCU): Undefined MCU
* 
* Module editor vendor:  ArcCore
* Module editor version: 2.0.7
* 
* 
* Generated by Arctic Studio (http://arccore.com)
*           on Tue Jun 08 08:23:43 CEST 2010
*/

	

#include <stdlib.h>
#include <stdint.h>
#include "Platform_Types.h"
#include "Os.h"				// includes Os_Cfg.h
#include "os_config_macros.h"
#include "kernel.h"
#include "kernel_offset.h"
#include "alist_i.h"
#include "Mcu.h"

extern void dec_exception( void );

// Set the os tick frequency
OsTickType OsTickFreq = 1000;


// ###############################    DEBUG OUTPUT     #############################
uint32 os_dbg_mask = D_RESOURCE |D_SCHTBL |D_EVENT |D_TASK |D_ALARM;
 


// #################################    COUNTERS     ###############################
GEN_COUNTER_HEAD {
	GEN_COUNTER(	COUNTER_ID_Counter1,
					"Counter1",
					COUNTER_TYPE_HARD,
					COUNTER_UNIT_NANO,
					0xffff,
					1,
					1,
					0),
	GEN_COUNTER(	COUNTER_ID_Counter2,
					"Counter2",
					COUNTER_TYPE_SOFT,
					COUNTER_UNIT_NANO,
					65535,
					1,
					1,
					0),
};

CounterType Os_Arc_OsTickCounter = COUNTER_ID_Counter1;

// ##################################    ALARMS     ################################
GEN_ALARM_AUTOSTART(ALARM_ID_Alarm1, ALARM_AUTOSTART_ABSOLUTE, 1, 0, OSDEFAULTAPPMODE );
	
GEN_ALARM_AUTOSTART(ALARM_ID_Alarm2, ALARM_AUTOSTART_ABSOLUTE, 1, 0, OSDEFAULTAPPMODE );
	

GEN_ALARM_HEAD {
	GEN_ALARM(	ALARM_ID_Alarm1,
				"Alarm1",
				COUNTER_ID_Counter2,
				GEN_ALARM_AUTOSTART_NAME(ALARM_ID_Alarm1),
				ALARM_ACTION_SETEVENT,
				TASK_ID_etask_master,
				EVENT_MASK_Alarm_1,
				NULL ),
	GEN_ALARM(	ALARM_ID_Alarm2,
				"Alarm2",
				COUNTER_ID_Counter2,
				GEN_ALARM_AUTOSTART_NAME(ALARM_ID_Alarm2),
				ALARM_ACTION_SETEVENT,
				TASK_ID_etask_master,
				EVENT_MASK_Alarm_2,
				NULL ),
};

// ################################    RESOURCES     ###############################
GEN_RESOURCE_HEAD {
};

// ##############################    STACKS (TASKS)     ############################
DECLARE_STACK(OsIdle,OS_OSIDLE_STACK_SIZE);
DECLARE_STACK(btask_2,2048);
DECLARE_STACK(btask_4,2048);
DECLARE_STACK(etask_3,2048);
DECLARE_STACK(etask_5,2048);
DECLARE_STACK(etask_master,2048);

// ##################################    TASKS     #################################
GEN_TASK_HEAD {
	GEN_ETASK(	OsIdle,
				0,
				FULL,
				TRUE,
				NULL,
				0 
	),
	GEN_ETASK(
		btask_2,
		2,
		FULL,
		TRUE,
		NULL,
		0
	),
		
				
	GEN_BTASK(
		btask_4,
		4,
		FULL,
		TRUE,
		NULL,
		0,
		1
	),
				
	GEN_ETASK(
		etask_3,
		3,
		FULL,
		TRUE,
		NULL,
		0
	),
		
				
	GEN_ETASK(
		etask_5,
		5,
		FULL,
		TRUE,
		NULL,
		0
	),
		
				
	GEN_ETASK(
		etask_master,
		10,
		FULL,
		TRUE,
		NULL,
		0
	),
		
				
};

// ##################################    HOOKS     #################################
GEN_HOOKS( 
	StartupHook, 
	NULL, 
	ShutdownHook, 
	ErrorHook,
	PreTaskHook, 
	PostTaskHook 
);

// ##################################    ISRS     ##################################


// ############################    SCHEDULE TABLES     #############################

// Table data ScheduleTable_1


GEN_SCHTBL_EVENT_LIST_HEAD( 0, 0 ) {
	
	{ 
		EVENT_MASK_SchTbl_1, 
		TASK_ID_etask_master 
	},
	
};


GEN_SCHTBL_EXPIRY_POINT_HEAD( 0 ) {
	GEN_SCHTBL_EXPIRY_POINT_W_EVENT(0, 0),
	
};

GEN_SCHTBL_AUTOSTART(
	0,
	SCHTBL_AUTOSTART_ABSOLUTE,
	1, 
	OSDEFAULTAPPMODE
);

// Table data ScheduleTable_2


GEN_SCHTBL_EVENT_LIST_HEAD( 1, 0 ) {
	
	{ 
		EVENT_MASK_SchTbl_2, 
		TASK_ID_etask_master 
	},
	
};


GEN_SCHTBL_EXPIRY_POINT_HEAD( 1 ) {
	GEN_SCHTBL_EXPIRY_POINT_W_EVENT(1, 0),
	
};

GEN_SCHTBL_AUTOSTART(
	1,
	SCHTBL_AUTOSTART_ABSOLUTE,
	1, 
	OSDEFAULTAPPMODE
);

// Table heads
GEN_SCHTBL_HEAD {
	GEN_SCHEDULETABLE(
		0,
		"ScheduleTable_1",
	    COUNTER_ID_Counter2,
	    SINGLE_SHOT,
		10,
		GEN_SCHTBL_AUTOSTART_NAME(0)
	),
	GEN_SCHEDULETABLE(
		1,
		"ScheduleTable_2",
	    COUNTER_ID_Counter2,
	    SINGLE_SHOT,
		10,
		GEN_SCHTBL_AUTOSTART_NAME(1)
	),
};

GEN_PCB_LIST()

uint8_t os_interrupt_stack[OS_INTERRUPT_STACK_SIZE] __attribute__ ((aligned (0x10)));

GEN_IRQ_VECTOR_TABLE_HEAD {};
GEN_IRQ_ISR_TYPE_TABLE_HEAD {};
GEN_IRQ_PRIORITY_TABLE_HEAD {};

#include "os_config_funcs.h"