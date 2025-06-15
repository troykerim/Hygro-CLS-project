#include <stdio.h>
#include "PmodCLS.h"
#include "PmodHYGRO.h"
#include "sleep.h"
#include "string.h"
#include "xil_cache.h"
#include "xil_printf.h"
#include "xparameters.h"

#define TIMER_FREQ_HZ 50000000

PmodHYGRO hygroDevice;
PmodCLS clsDevice;

void DemoInitialize();
void DemoRun();
void DemoCleanup();

int main(void) {
   DemoInitialize();
   DemoRun();
   DemoCleanup();
   return 0;
}

// Initialize both Pmods
void DemoInitialize() {
   CLS_begin(&clsDevice, XPAR_PMODCLS_0_AXI_LITE_SPI_BASEADDR);
   HYGRO_begin(
      &hygroDevice,
      XPAR_PMODHYGRO_0_AXI_LITE_IIC_BASEADDR,
      0x40,
      XPAR_PMODHYGRO_0_AXI_LITE_TMR_BASEADDR,
      XPAR_PMODHYGRO_0_DEVICE_ID,
      TIMER_FREQ_HZ
   );
}

void DemoRun() {
	   float temp_degc, hum_perrh, temp_degf;
	   char szLine1[32];
	   char szLine2[32];

	   CLS_DisplayClear(&clsDevice);

	   while (1) {
	      // Read values for Hygro
	      temp_degc = HYGRO_getTemperature(&hygroDevice);
	      temp_degf = HYGRO_tempC2F(temp_degc);
	      hum_perrh = HYGRO_getHumidity(&hygroDevice);

	      // Format strings for CLS
	      snprintf(szLine1, sizeof(szLine1), "Temp: %2d.%02d F",
	               (int)temp_degf, ((int)(temp_degf * 100)) % 100);
	      snprintf(szLine2, sizeof(szLine2), "Humid: %2d.%02d RH",
	               (int)hum_perrh, ((int)(hum_perrh * 100)) % 100);

	      // Display on PmodCLS
	      CLS_DisplayClear(&clsDevice);
	      CLS_WriteStringAtPos(&clsDevice, 0, 0, szLine1);
	      CLS_WriteStringAtPos(&clsDevice, 1, 0, szLine2);

	      // Print to Vitis Serial Terminal for debugging
	      xil_printf("%s | %s\n\r", szLine1, szLine2);

	      // Wait 1 second
	      sleep(1);
	   }
	}

void DemoCleanup() {
   CLS_end(&clsDevice);
}

