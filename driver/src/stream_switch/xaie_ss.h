/******************************************************************************
*
* Copyright (C) 2019 Xilinx, Inc.  All rights reserved.
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
* THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMANGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*
******************************************************************************/

/*****************************************************************************/
/**
* @file xaie_ss.h
* @{
*
* Header file for stream switch implementations.
*
* <pre>
* MODIFICATION HISTORY:
*
* Ver   Who     Date     Changes
* ----- ------  -------- -----------------------------------------------------
* 1.0   Tejus   09/24/2019  Initial creation
* 1.1   Tejus   03/20/2020  Remove range apis
* 1.2   Tejus   03/21/2020  Add stream switch packet switch mode apis
* </pre>
*
******************************************************************************/
#ifndef XAIESS_H
#define XAIESS_H

/***************************** Include Files *********************************/
#include "xaiegbl.h"
#include "xaiegbl_defs.h"
#include "xaielib.h"
#include "xaie_helper.h"

/**************************** Type Definitions *******************************/
/* Typedef to capture Packet drop header */
typedef enum {
	XAIE_SS_PKT_DONOT_DROP_HEADER,
	XAIE_SS_PKT_DROP_HEADER
} XAie_StrmSwPktHeader;

/************************** Function Prototypes  *****************************/
AieRC XAie_StrmConnCctEnable(XAie_DevInst *DevInst, XAie_LocType Loc,
		StrmSwPortType Slave, u8 SlvPortNum, StrmSwPortType Master,
		u8 MstrPortNum);

AieRC XAie_StrmConnCctDisable(XAie_DevInst *DevInst, XAie_LocType Loc,
		StrmSwPortType Slave, u8 SlvPortNum, StrmSwPortType Master,
		u8 MstrPortNum);

AieRC XAie_StrmPktSwMstrPortEnable(XAie_DevInst *DevInst, XAie_LocType Loc,
		StrmSwPortType Master, u8 MstrPortNum,
		XAie_StrmSwPktHeader DropHeader, u8 Arbitor, u8 MSelEn);

AieRC XAie_StrmPktSwMstrPortDisable(XAie_DevInst *DevInst, XAie_LocType Loc,
		StrmSwPortType Master, u8 MstrPortNum);

AieRC XAie_StrmPktSwSlavePortEnable(XAie_DevInst *DevInst, XAie_LocType Loc,
		StrmSwPortType Slave, u8 SlvPortNum);

AieRC XAie_StrmPktSwSlavePortDisable(XAie_DevInst *DevInst, XAie_LocType Loc,
		StrmSwPortType Slave, u8 SlvPortNum);

AieRC XAie_StrmPktSwSlaveSlotEnable(XAie_DevInst *DevInst, XAie_LocType Loc,
		StrmSwPortType Slave, u8 SlvPortNum, u8 SlotNum,
		XAie_Packet Pkt, u8 Mask, u8 MSel, u8 Arbitor);

AieRC XAie_StrmPktSwSlaveSlotDisable(XAie_DevInst *DevInst, XAie_LocType Loc,
		StrmSwPortType Slave, u8 SlvPortNum, u8 SlotNum);

#endif		/* end of protection macro */
