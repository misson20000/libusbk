/*
             LUFA Library
     Copyright (C) Dean Camera, 2010.

  dean [at] fourwalledcubicle [dot] com
           www.lufa-lib.org
*/

/*
  Copyright 2011  Pete Batard (pbatard [at] gmail [dot] com)
  Copyright 2010-2011 Travis Robinson (libusb.win32.support [at] gmail [dot] com)
  Copyright 2010  Dean Camera (dean [at] fourwalledcubicle [dot] com)

  Permission to use, copy, modify, distribute, and sell this
  software and its documentation for any purpose is hereby granted
  without fee, provided that the above copyright notice appear in
  all copies and that both that the copyright notice and this
  permission notice and warranty disclaimer appear in supporting
  documentation, and that the name of the author not be used in
  advertising or publicity pertaining to distribution of the
  software without specific, written prior permission.

  The author disclaim all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall the author be liable for any
  special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortuous action,
  arising out of or in connection with the use or performance of
  this software.
*/

/** \file
 *
 *  Header file for Benchmark.c.
 */

#ifndef _BENCHMARK_H_
#define _BENCHMARK_H_

	/* Includes: */
		#include <avr/io.h>
		#include <avr/wdt.h>
		#include <avr/power.h>
		#include <avr/interrupt.h>

		#include "Descriptors.h"

		#include <LUFA/Version.h>
		#include <LUFA/Drivers/Board/LEDs.h>
		#include <LUFA/Drivers/USB/USB.h>

	/* Macros: */
		#define RELAY1      (1 << 7)
		#define RELAY2      (1 << 6)
		#define RELAY3      (1 << 5)
		#define RELAY4      (1 << 4)
		#define ALL_RELAYS  (RELAY1 | RELAY2 | RELAY3 | RELAY4)


	/* Vendor specific commands */
		enum TestType
		{
			TEST_NONE,
			TEST_PCREAD,
			TEST_PCWRITE,
			TEST_LOOP
		};

		enum FW_COMMANDS
		{
			FW_SET_TEST		= 0x0E,
			FW_GET_TEST		= 0x0F,
			FW_SET_VENDOR_BUFFER= 0x10,
			FW_GET_VENDOR_BUFFER= 0x11,
		};

	/* Macros: */
		/** LED mask for the library LED driver, to indicate that the USB interface is not ready. */
		#define LEDMASK_USB_NOTREADY      LEDS_LED2

		/** LED mask for the library LED driver, to indicate that the USB interface is enumerating. */
		#define LEDMASK_USB_ENUMERATING  (LEDS_LED1 | LEDS_LED2)

		/** LED mask for the library LED driver, to indicate that the USB interface is ready. */
		#define LEDMASK_USB_READY         LEDS_LED1

		/** LED mask for the library LED driver, to indicate that an error has occurred in the USB interface. */
		#define LEDMASK_USB_ERROR         LEDS_LED2

		/** LED mask for the library LED driver, to indicate that the USB interface is busy. */
		#define LEDMASK_BUSY             (LEDS_LED1 | LEDS_LED2)

		/** LED mask for the library LED driver, to indicate that the target is being powered by VBUS. */
		#define LEDMASK_VBUSPOWER         LEDS_LED3

	/* Function Prototypes: */
		void SetupHardware(void);
		void Benchmark_ProcessIO(void);

		void EVENT_USB_Device_Connect(void);
		void EVENT_USB_Device_Disconnect(void);
//		void EVENT_USB_Device_ConfigurationChanged(void);
		void EVENT_USB_Device_ControlRequest(void);

#endif

