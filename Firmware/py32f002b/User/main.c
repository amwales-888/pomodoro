/**
  ******************************************************************************
  * @file    main.c
  * @author  MCU Application Team
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) Puya Semiconductor Co.
  * All rights reserved.</center></h2>
  *
  * <h2><center>&copy; Copyright (c) 2016 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private define ------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

static volatile uint32_t systickCnt;
static int sleep;

static uint8_t buttonIntegrator;
static uint16_t buttonCount;
static int buttonDstate;

static enum buttonState_e {
    
    BUTTONIDLE=0,
    BUTTONPRESSED,
    BUTTONHELD,
    BUTTONRELEASED,   
            
} buttonState;

static uint32_t workTimeTicks;
static uint32_t relaxTimeTicks;

static enum ledState_e {
    
    STATEWORK=0,
    STATEWORKWAITINGON,
    STATEWORKWAITINGOFF,
    STATERELAX,
    STATERELAXWAITINGON,        
    STATERELAXWAITINGOFF,        
            
} ledState;


/* Private user code ---------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/

#define ARRAYSIZE(arr) (sizeof(arr) / sizeof(arr[0]))
	
#define MSPERTICK      10
#define MSTOTICKS(x)   ((x)/MSPERTICK)
#define TICKSTOSECS(x) ((x)/(1000/MSPERTICK))

#define DEBOUNCE_TIME               0.05    /* Seconds */
#define DEBOUNCE_SAMPLE_FREQUENCY	100     /* Hertz */

#define DEBOUNCE_MAXIMUM			(DEBOUNCE_TIME * DEBOUNCE_SAMPLE_FREQUENCY)
#define DEBOUNCE_INTEGRATOR_DELAYMS ((1.0/DEBOUNCE_SAMPLE_FREQUENCY)*1000)
#define DEBOUNCE_DELAYMS            (DEBOUNCE_TIME * 1000)

/* Private function prototypes -----------------------------------------------*/

static void APP_SystemClockConfig(void);
static void APP_GpioConfig(void);

static void processButton(void);
static void nullFunc(void);
static void processDisplay(void);
static void processWorkExpired(void);
static void processRelaxExpired(void);
static void processIntegrator(void);
static void buttonReleased(void);
static void buttonHeld(void);
static void buttonPressed(void);
static void buzzStart(void);
static void buzzStop(void);
static void playMelody(void);
static void startMelody(void);
static void stopMelody(void);
static void setupTimer(void);
static void resetAllLeds(void);
static void setAllLeds(void);
static void resetLed(int id);
static void toggleLed(int id);
static void setLed(int id);
static int isWorkTimerSet(void);
static int isRelaxTimerSet(void);
static void getTimers(int *work, int *relax);
static void enableRedLeds(void);
static void disableRedLeds(void);
static void enableGreenLeds(void);
static void disableGreenLeds(void);
static uint32_t getSysTickCnt(void);
static void waitMs(uint32_t msDelay);
static int getButtonValue(void);


static void PWMConfigure(void);
static void TIMConfigure(void);
static void	PWMSetFreq(uint16_t frequency);
static void	PWMPause(void);
static void	PWMUnpause(void);
static void TIMStop(void);
static void PWMStop(void);

static void APP_EnterDeepStop(void);






static struct process_s {
    
    uint32_t periodTick;
    uint32_t lastTick;
    
    void (*func)(void);

} processList[] = {

#ifdef BLINKTEST    
    { (uint32_t)MSTOTICKS(1000),                          0, testFunc          },
#else    
    { (uint32_t)0,                                        0, nullFunc          },
    { (uint32_t)MSTOTICKS(DEBOUNCE_DELAYMS),              0, processButton     },
    { (uint32_t)MSTOTICKS(1000),                          0, processDisplay    },
    { (uint32_t)MSTOTICKS(DEBOUNCE_INTEGRATOR_DELAYMS),   0, processIntegrator },    
    { (uint32_t)MSTOTICKS(50),                            0, playMelody        },
#endif

};


static void setupTimer(void) {
	
		int work, relax;

		getTimers(&work, &relax);
	
		switch (work) {
			case 1:
				workTimeTicks = MSTOTICKS((uint32_t)15*60*1000);  /* 15 mins */
				break;
			case 2:
				workTimeTicks = MSTOTICKS((uint32_t)30*60*1000);  /* 30 mins */
				break;
			case 3:
				workTimeTicks = MSTOTICKS((uint32_t)45*60*1000);  /* 45 mins */
				break;
			case 4:
				workTimeTicks = MSTOTICKS((uint32_t)60*60*1000);  /* 60 mins */
				break;
			default:
				workTimeTicks  = MSTOTICKS((uint32_t)30*60*1000);  /* 30 mins */
				break;
		}
		
		switch (relax) {
			case 1:
				relaxTimeTicks = MSTOTICKS((uint32_t)0*60*1000);  /*  0 mins */
				break;
			case 2:
				relaxTimeTicks = MSTOTICKS((uint32_t)5*60*1000);  /*  5 mins */
				break;
			case 3:
				relaxTimeTicks = MSTOTICKS((uint32_t)10*60*1000); /* 10 mins */
				break;
			case 4:
				relaxTimeTicks = MSTOTICKS((uint32_t)15*60*1000); /* 15 mins */
				break;
			default:
				relaxTimeTicks = MSTOTICKS((uint32_t)0*60*1000);   /*  0 mins */
				break;
		}
}

static void resetAllLeds(void) {

	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_1);
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_0);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_0);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_1);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_2);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_3);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4);
	LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
}

static void setAllLeds(void) {

	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_1);
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_0);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_0);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_1);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_2);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_3);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_4);
	LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
}





static void toggleLed(int id) {
	
	switch (id) {
		case 1:
			LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_1);
			break;
		case 2:
			LL_GPIO_TogglePin(GPIOA, LL_GPIO_PIN_0);
			break;
		case 3:
			LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_0);
			break;
		case 4:
			LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_1);
			break;
		case 5:
			LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_2);
			break;
		case 6:
			LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_3);
			break;
		case 7:
			LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_4);
			break;
		case 8:
			LL_GPIO_TogglePin(GPIOB, LL_GPIO_PIN_5);
			break;
	}
}


static void resetLed(int id) {
	
	switch (id) {
		case 1:
			LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_1);
			break;
		case 2:
			LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_0);
			break;
		case 3:
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_0);
			break;
		case 4:
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_1);
			break;
		case 5:
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_2);
			break;
		case 6:
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_3);
			break;
		case 7:
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_4);
			break;
		case 8:
			LL_GPIO_ResetOutputPin(GPIOB, LL_GPIO_PIN_5);
			break;
	}
}

static void setLed(int id) {

	switch (id) {
		case 1:
			LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_1);
			break;
		case 2:
			LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_0);
			break;
		case 3:
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_0);
			break;
		case 4:
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_1);
			break;
		case 5:
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_2);
			break;
		case 6:
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_3);
			break;
		case 7:
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_4);
			break;
		case 8:
			LL_GPIO_SetOutputPin(GPIOB, LL_GPIO_PIN_5);
			break;
	}
}

static int isWorkTimerSet(void) {
	
	return LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_7);
}

static int isRelaxTimerSet(void) {
	
	return LL_GPIO_IsInputPinSet(GPIOC, LL_GPIO_PIN_1);
}


static void getTimers(int *work, int *relax) {
	
	*work = 0;
	*relax = 0;
	
	resetAllLeds();

	/* WORK Timer Inputs */
	LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_7, LL_GPIO_PULL_DOWN);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_7, LL_GPIO_MODE_INPUT);
	
	/* RELAX Timer Inputs */
	LL_GPIO_SetPinPull(GPIOC, LL_GPIO_PIN_1, LL_GPIO_PULL_DOWN);
	LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_1, LL_GPIO_MODE_INPUT);

	
	for (int i=1; i<9; i++) {
		
		setLed(i);
		if (isRelaxTimerSet()) {
			*relax = i;
		}
		if (isWorkTimerSet()) {
			*work = i;
		}
		resetLed(i);
	}	


	/* WORK Timer Ouput */
	LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_7, LL_GPIO_PULL_NO);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_7, LL_GPIO_MODE_ANALOG);
	/* RELAX Timer Ouput */
	LL_GPIO_SetPinPull(GPIOC, LL_GPIO_PIN_1, LL_GPIO_PULL_NO);
	LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_1, LL_GPIO_MODE_ANALOG);




}

static void enableRedLeds(void) {
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_3);
}

static void disableRedLeds(void) {
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_3);
}

static void enableGreenLeds(void) {
	LL_GPIO_SetOutputPin(GPIOA, LL_GPIO_PIN_4);
}

static void disableGreenLeds(void) {
	LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_4);
}

static volatile uint32_t systickCnt = 0;

void SysTick_Handler(void) {
  systickCnt++;
}

static uint32_t getSysTickCnt(void) {
	return systickCnt;
}

static void waitMs(uint32_t msDelay) {

	if (msDelay == 0) return;
		
	uint32_t delayCount = ((msDelay-1) / 10) + 1;
	uint32_t start = getSysTickCnt();
	
	while (1) {		
		if (getSysTickCnt() - start > delayCount) {
			break;
		}
	}	
}





static void nullFunc(void){
    
}

static void buzzStart(void) {
	//TODO

    return;
    
}

static void buzzStop(void) {
	//TODO
    
    return;
}





static void processIntegrator(void) {

    /* This function MUST be called every 1/DEBOUNCE_SAMPLE_FREQUENCY seconds
     */
    if (getButtonValue() != 0) {                
        if (buttonIntegrator > 0) {                
            buttonIntegrator--;
        }                               
    } else if (buttonIntegrator < DEBOUNCE_MAXIMUM) {
        buttonIntegrator++;
    }
}

static void buttonReleased(void) {

    if (sleep) {

        APP_EnterDeepStop();

        /* An interrupt has woken us up from sleep */
        
        __NOP();
        __NOP();
        __NOP();

        /* restart */
        
        NVIC_SystemReset();
    }
}


static void buttonHeld(void) {
    
    /* Test to see if the button has been held down for 3 seconds.
     * If it has then we shutdown 
     */    
        
    if (buttonCount > ((3 * 1000) / DEBOUNCE_DELAYMS)) {

        resetAllLeds();

				disableRedLeds();
				disableGreenLeds();
			
        PWMStop();
        TIMStop();

        /* Signal that we want to enter sleep */
        
        sleep = 1;			
    }    
}

static void buttonPressed(void) {

    /* The button was pressed, this is only relevant when the 
     * we are blinking in the work/relax state, if we are then
     * we can reset the time and switch state.
     */    
    switch (ledState) {
        case STATEWORK:
            break;
        case STATEWORKWAITINGON:
        case STATEWORKWAITINGOFF:

            buzzStop();
            stopMelody();
                        
            processList[0].periodTick = relaxTimeTicks;
            processList[0].lastTick   = systickCnt;
            processList[0].func       = processRelaxExpired;

						resetAllLeds();
						disableRedLeds();
						enableGreenLeds();
				
            ledState = STATERELAX;
            break;

        case STATERELAX:
            break;
        case STATERELAXWAITINGON:
        case STATERELAXWAITINGOFF:

            buzzStop();
            stopMelody();

            processList[0].periodTick = workTimeTicks;
            processList[0].lastTick   = systickCnt;
            processList[0].func       = processWorkExpired;

						resetAllLeds();
						disableGreenLeds();
						enableRedLeds();
				
            ledState = STATEWORK;
            break;
    }
}


static void processButton(void) {

    int report = 0;
    
    /* This function MUST be called every DEBOUNCE_TIME seconds
     */                        
    if  (buttonIntegrator == DEBOUNCE_MAXIMUM) {
        if (buttonDstate == 0) {

            buttonState = BUTTONPRESSED;  
            report = 1;

        } else {

            buttonState = BUTTONHELD;  
            report = 1;
        }

        buttonCount++;
        buttonDstate = 1;

    } else if (buttonIntegrator == 0) {

        if (buttonDstate) {

            /* Released */
            buttonState = BUTTONRELEASED;  
            report = 1;

        } else {

            buttonState = BUTTONIDLE;                      
        }

        buttonCount  = 0;
        buttonDstate = 0;
    } 
    
    if (report) {        
        switch (buttonState) {
            case BUTTONIDLE:
                break;
            case BUTTONRELEASED:
                buttonReleased();
                break;
            case BUTTONHELD:
                buttonHeld();
                break;
            case BUTTONPRESSED:
                buttonPressed();
                break;
        }
    }
}

static void processDisplay(void) {
     
    if (sleep) return;
    
    /* Depending on our current work/relax state reflect the values
     * on the 7 LEDs     
     */    
    switch (ledState) {
        case STATEWORK: {
            
            int percentage = (int)((systickCnt - processList[0].lastTick) * 100 / processList[0].periodTick);
            int count = (percentage - 1) / (100/7);
            int i;
                        
            for (i=0; i<count; i++) {                
								resetLed(i+1);
            }            
						
						toggleLed(count+1);
            
            for (i=count+1; i<7; i++) {							
								setLed(i+1);
            }
            
            break;
        }
            
        case STATEWORKWAITINGON:
            
            buzzStart();

						setAllLeds();
				            
            ledState = STATEWORKWAITINGOFF;
            break;
            
        case STATEWORKWAITINGOFF:
            
            buzzStop();

						resetAllLeds();
				
            ledState = STATEWORKWAITINGON;
            break;

        case STATERELAX: {
 
            int percentage = (int)((systickCnt - processList[0].lastTick) * 100 / processList[0].periodTick);
            int count = (percentage - 1) / (100/7);
            int i;

            for (i=0; i<count; i++) {  
								resetLed(i+1);              
            }            

						toggleLed(count+1);
            
            for (i=count+1; i<7; i++) {
								setLed(i+1);              
            }

            break;
        }

        case STATERELAXWAITINGON:
            
            buzzStart();

						setAllLeds();
            
            ledState = STATERELAXWAITINGOFF;
            break;

        case STATERELAXWAITINGOFF:

            buzzStop();
            
						resetAllLeds();
				
            ledState = STATERELAXWAITINGON;
            break;
    }          
}


static void processWorkExpired(void) {
     
    if (sleep) return;

    if (ledState == STATEWORK) {  
                
        /* Our work time has expired move to work, start melody and
         * enter blink state
         */    
        startMelody();      

				resetAllLeds();
				disableGreenLeds();
				enableRedLeds();
			
        ledState = STATEWORKWAITINGON;
    }
}

static void processRelaxExpired(void) {

     if (sleep) return;

     /* Our relax time has expired move to relax, start melody and
      * enter blink state
     */    
    if (ledState == STATERELAX) {

        startMelody();
			
				resetAllLeds();
				disableRedLeds();
				enableGreenLeds();
			
        ledState = STATERELAXWAITINGON;
    }
}



/* Q. Where are all the other octaves
 * A. We require another timebase and I got tired of typing,
 *    these notes seem sufficient for this use case.
 */
#define NOTE_C6  (uint16_t)(1047) /* 1047 Hz */
#define NOTE_CS6 (uint16_t)(1108) /* 1108 Hz */
#define NOTE_D6  (uint16_t)(1174) /* 1174 Hz */
#define NOTE_DS6 (uint16_t)(1244) /* 1244 Hz */
#define NOTE_E6  (uint16_t)(1318) /* 1318 Hz */
#define NOTE_F6  (uint16_t)(1396) /* 1396 Hz */
#define NOTE_FS6 (uint16_t)(1479) /* 1479 Hz */
#define NOTE_G6  (uint16_t)(1567) /* 1567 Hz */
#define NOTE_GS6 (uint16_t)(1661) /* 1661 Hz */
#define NOTE_A6  (uint16_t)(1760) /* 1760 Hz */
#define NOTE_AS6 (uint16_t)(1864) /* 1864 Hz */
#define NOTE_B6  (uint16_t)(1975) /* 1975 Hz */
#define NOTE_C7  (uint16_t)(2093) /* 2093 Hz */
#define NOTE_CS7 (uint16_t)(2217) /* 2217 Hz */
#define NOTE_D7  (uint16_t)(2349) /* 2349 Hz */
#define NOTE_DS7 (uint16_t)(2489) /* 2489 Hz */
#define NOTE_E7  (uint16_t)(2637) /* 2637 Hz */
#define NOTE_F7  (uint16_t)(2794) /* 2794 Hz */
#define NOTE_FS7 (uint16_t)(2960) /* 2960 Hz */
#define NOTE_G7  (uint16_t)(3136) /* 3136 Hz */
#define NOTE_GS7 (uint16_t)(3322) /* 3322 Hz */
#define NOTE_A7  (uint16_t)(3520) /* 3520 Hz */
#define NOTE_AS7 (uint16_t)(3729) /* 3729 Hz */
#define NOTE_B7  (uint16_t)(3951) /* 3951 Hz */
#define NOTE_C8  (uint16_t)(4186) /* 4186 Hz */
#define NOTE_CS8 (uint16_t)(4435) /* 4435 Hz */
#define NOTE_D8  (uint16_t)(4699) /* 4699 Hz */
#define NOTE_DS8 (uint16_t)(4978) /* 4978 Hz */


#define NOTE_RST 0x00

static const uint16_t melody[] = {  

    NOTE_C6,NOTE_C6,NOTE_G6,NOTE_G6,
    NOTE_A6,NOTE_A6,NOTE_G6,
    NOTE_F6,NOTE_F6,NOTE_E6,NOTE_E6,
    NOTE_D6,NOTE_D6,NOTE_C6,
    NOTE_G6,NOTE_G6,NOTE_F6,NOTE_F6,
    NOTE_E6,NOTE_E6,NOTE_D6,
    NOTE_G6,NOTE_G6,NOTE_F6,NOTE_F6,
    NOTE_E6,NOTE_E6,NOTE_D6,
    NOTE_C6,NOTE_C6,NOTE_G6,NOTE_G6,
    NOTE_A6,NOTE_A6,NOTE_G6,
    NOTE_F6,NOTE_F6,NOTE_E6,NOTE_E6,
    NOTE_D6,NOTE_D6,NOTE_C6,
};

static const uint32_t durationTick[] = {
    
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(400),
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(400),
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(400),
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(400),
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(400),
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(150),
    MSTOTICKS(150),MSTOTICKS(150),MSTOTICKS(400),
};

static uint8_t noteIdx;

static enum melodyState_e {
    
    MELODYIDLE=0,
    MELODYSTART,
    MELODYPLAYING,
    MELODYSTOP,

} melodyState;


static enum noteState_e {
    
    NOTESTART=0,
    NOTEPLAY,
    NOTEREST,

} noteState;

static void startMelody(void) {
    
    melodyState = MELODYSTART;
}

static void stopMelody(void) {
    
    melodyState = MELODYSTOP;
}

static uint32_t noteStartTick;
static uint32_t noteDurationTick;

static void playMelody(void) {

		if (sleep) return;

		switch (melodyState) {

        case MELODYIDLE:
            break;
        
        case MELODYSTART:
            
            noteIdx       = 0;
            melodyState   = MELODYPLAYING;
            noteState     = NOTESTART;
								
        case MELODYPLAYING:
                        
            switch (noteState) {
                
                case NOTESTART:

                    noteStartTick = systickCnt;
                    noteDurationTick = durationTick[noteIdx];

										/* Play note */	
										PWMSetFreq(melody[noteIdx]);

                    noteState = NOTEPLAY;                    
                    
                case NOTEPLAY:
                                        
                    if ((uint32_t)(systickCnt - noteStartTick) >= noteDurationTick) {

                        noteStartTick = systickCnt;
                        noteDurationTick = durationTick[noteIdx];
                        
												/* Stop note */
												PWMPause();

												noteState = NOTEREST;
                    }
                    break;
                    
                case NOTEREST:
                    
                    /* After each note we rest so that each note is distinct
                     * from one another.
                     */                    
                    
                    if ((uint32_t)(systickCnt - noteStartTick) >= noteDurationTick) {
                        
                        noteIdx++;
                        if (noteIdx == ARRAYSIZE(durationTick)) {
                            noteIdx = 0;
#ifndef MELODYONLOOP
                            melodyState = MELODYSTOP;
#endif                            
                        }
                        
                        noteState = NOTESTART;
                    }
                    break;
            }
            break;
                        
        case MELODYSTOP:
                        
            melodyState = MELODYIDLE;

						/* Stop note */
						PWMPause();

						break;
    }
}

static int getButtonValue(void) {
	return LL_GPIO_IsInputPinSet(GPIOA, LL_GPIO_PIN_6);
}


#define SYSTEMCLOCK 24000000U /* 24 MHz */


/**
  * @brief  Main program.
  * @retval int
  */
int main(void)
{
		/* Configure HSI as Systemclock source */
		APP_SystemClockConfig();

		/* Fixme! hardcoded 24Mhz */
		LL_InitTick(SYSTEMCLOCK, 100);  /* 10ms Tick */
		LL_SYSTICK_EnableIT();


		/* Configure GPIO Pins */
		APP_GpioConfig();

		
		
		/* Setup PWM hardware */
		TIMConfigure();
		PWMConfigure();	
		
	  /* Wait 1 second for any button bouncing to settle after reset, we may have
     * just been woken with a button press and need to filter it out
     */
	
    while (getButtonValue() == 0) {
        waitMs(100);        
    }

	
#ifndef BLINKTEST
    /* Read the pin to determine work time and relax time */
    setupTimer();
    
    /* Setup our initial work/relax state, waiting in relaxed state for button 
     * press 
     */   
    processList[0].periodTick = relaxTimeTicks;
    processList[0].lastTick   = systickCnt;
    processList[0].func       = processRelaxExpired;
    
		resetAllLeds();
		disableRedLeds();
		enableGreenLeds();

    ledState = STATERELAXWAITINGON;
    
#endif

    
    startMelody();
    
    /* Main loop scheduling processes */
    while (1) {
                
        /* Step through each process and test if period has expired and
         * if has, dispatch the function and adjust it last run time
         */        
        for (uint32_t i=0; i<ARRAYSIZE(processList); i++) {
            
            if ((uint32_t)(systickCnt - processList[i].lastTick) >= processList[i].periodTick) {
                
                (*processList[i].func)();
                processList[i].lastTick = systickCnt;
            }
        }        
    }    
}

/**
  * @brief  Configure HSI as Systemclock source
  * @param  None
  * @retval None
  */
static void APP_SystemClockConfig(void)
{
  /* Enable HSI */
  LL_RCC_HSI_Enable();
  while(LL_RCC_HSI_IsReady() != 1)
  {
  }

  /* Set AHB divider: HCLK = SYSCLK */
  LL_RCC_SetAHBPrescaler(LL_RCC_SYSCLK_DIV_1);

  /* HSISYS used as SYSCLK clock source  */
  LL_RCC_SetSysClkSource(LL_RCC_SYS_CLKSOURCE_HSISYS);
  while(LL_RCC_GetSysClkSource() != LL_RCC_SYS_CLKSOURCE_STATUS_HSISYS)
  {
  }

  /* Set APB1 divider */
  LL_RCC_SetAPB1Prescaler(LL_RCC_APB1_DIV_1);
  LL_Init1msTick(SYSTEMCLOCK);

  /* Update CMSIS variable (which can be updated also through SystemCoreClockUpdate function) */
  LL_SetSystemCoreClock(SYSTEMCLOCK);
}

/**
  * @brief  GPIO configuration program
  * @param  None
  * @retval None
  */
static void APP_GpioConfig(void)
{
    LL_EXTI_InitTypeDef EXTI_InitStruct = {0};

    /* Enable GPIO clocks */
    LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOA);
    LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOB);
    LL_IOP_GRP1_EnableClock(LL_IOP_GRP1_PERIPH_GPIOC);

	
	/*
	
	Output PA1 - OUT1 - LEDR1, LEDG1
	Output PA0 - OUT2 - LEDR2, LEDG2
	Output PB0 - OUT3 - LEDR3, LEDG3
	Output PB1 - OUT4 - LEDR4, LEDG4
	Output PB2 - OUT5 - LEDR5, LEDG5
	Output PB3 - OUT6 - LEDR6, LEDG6
	Output PB4 - OUT7 - LEDR7, LEDG7
	Output PB5 - OUT8
	
	
	
	Input PA3 - Enable RED LEDs
	Input PA4 - Enable GREEN LEDs
	Input PA6 - Button

	Output PA5 - Buzzer
	
	*/
	
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_1, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_0, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_0, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_1, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_2, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_3, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_4, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOB, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
	
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_3, LL_GPIO_MODE_OUTPUT);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_4, LL_GPIO_MODE_OUTPUT);

	/* Buzzer */
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
	
	/* WORK Timer Inputs */
	LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_7, LL_GPIO_PULL_DOWN);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_7, LL_GPIO_MODE_INPUT);
	
	/* RELAX Timer Inputs */
	LL_GPIO_SetPinPull(GPIOC, LL_GPIO_PIN_1, LL_GPIO_PULL_DOWN);
	LL_GPIO_SetPinMode(GPIOC, LL_GPIO_PIN_1, LL_GPIO_MODE_INPUT);
	
	/* Button input */
	LL_GPIO_SetPinPull(GPIOA, LL_GPIO_PIN_6, LL_GPIO_PULL_UP);
	LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_6, LL_GPIO_MODE_INPUT);	

    /* Register interrupt handler for Butto so we can wake from sleep */
    /* Configure PA6 as the EXTI6 interrupt input */
    LL_EXTI_SetEXTISource(LL_EXTI_CONFIG_PORTA, LL_EXTI_CONFIG_LINE6);

    /* Enable EXTI6 */
    EXTI_InitStruct.Line = LL_EXTI_LINE_6;
    EXTI_InitStruct.LineCommand = ENABLE;
    /* Event mode */
    EXTI_InitStruct.Mode = LL_EXTI_MODE_EVENT;
    /* Trigger Falling Mode */
    EXTI_InitStruct.Trigger = LL_EXTI_TRIGGER_FALLING;
    /* Initialize the EXTI registers according to the specified parameters in EXTI_InitStruct  */
    LL_EXTI_Init(&EXTI_InitStruct);
}


/* To simplify this implementation we have set the 
 * Lower and upperbounds to 366 Hz and 65536 Hz respectively.
 *
 * Min value for frequency is   366 Hz
 * Max value for frequency is 65536 Hz
 */
static int isPaused = 0;

static void	PWMSetFreq(uint16_t frequency) {

		if (frequency < 366) {

			PWMPause();

		} else {
	
				PWMUnpause();

				uint16_t prescaler = (SYSTEMCLOCK / 2) / frequency;
										
				LL_TIM_SetPrescaler(TIM1, prescaler);
				LL_TIM_SetAutoReload(TIM1, 2);
				LL_TIM_OC_SetCompareCH1(TIM1, 1); /* 50 % duty */				
		}
}

static void	PWMPause(void) {
	
		if (isPaused) return;

		LL_GPIO_SetPinMode(GPIOA, LL_GPIO_PIN_5, LL_GPIO_MODE_OUTPUT);
		LL_GPIO_ResetOutputPin(GPIOA, LL_GPIO_PIN_5);
		
		isPaused = 1;		
}

static void	PWMUnpause(void) {

		if (!isPaused) return;
	
		LL_GPIO_InitTypeDef GpioInit = {0};

		GpioInit.Pin = LL_GPIO_PIN_5;
		GpioInit.Mode = LL_GPIO_MODE_ALTERNATE;
		GpioInit.Alternate = LL_GPIO_AF_2;
		LL_GPIO_Init(GPIOA, &GpioInit);

		isPaused = 0;
}


static void PWMConfigure(void)
{
	// PA5 is PWM output TIM1_CH1 its initial state is 
	// configured as a simple output pulled low
	
  LL_TIM_OC_InitTypeDef TIM_OC_Initstruct = {0};
	
  TIM_OC_Initstruct.OCMode = LL_TIM_OCMODE_PWM1;
  TIM_OC_Initstruct.OCState = LL_TIM_OCSTATE_ENABLE;
  TIM_OC_Initstruct.OCPolarity = LL_TIM_OCPOLARITY_HIGH;
  TIM_OC_Initstruct.OCIdleState = LL_TIM_OCIDLESTATE_LOW;

  /* Set channel compare value */	
  TIM_OC_Initstruct.CompareValue = 0; // 50% duty cycle
  LL_TIM_OC_Init(TIM1, LL_TIM_CHANNEL_CH1, &TIM_OC_Initstruct);	

	/* Set to initial state to paused and pulled low.
	 * To start the PWM on the output pin call PWMUnpause()
	 */
	isPaused = 1;		
}

static void PWMStop(void)
{	
	PWMPause();
}

static void TIMConfigure(void)
{
  LL_TIM_InitTypeDef TIM1CountInit = {0};
	
	LL_APB1_GRP2_EnableClock(LL_APB1_GRP2_PERIPH_TIM1);
	 
  TIM1CountInit.ClockDivision       = LL_TIM_CLOCKDIVISION_DIV1;
  TIM1CountInit.CounterMode         = LL_TIM_COUNTERMODE_UP;
  TIM1CountInit.Prescaler           = (SYSTEMCLOCK / 2) / 25000; 
  TIM1CountInit.Autoreload          = 2;
  TIM1CountInit.RepetitionCounter   = 1; /* 25 KHz with 50% Duty cycle */   
  LL_TIM_Init(TIM1,&TIM1CountInit);    

  LL_TIM_EnableAllOutputs(TIM1);
  LL_TIM_EnableCounter(TIM1);
}

static void TIMStop(void)
{	
	LL_TIM_DisableCounter(TIM1);
	LL_TIM_DisableAllOutputs(TIM1);

  LL_TIM_DeInit(TIM1);
	
	LL_APB1_GRP2_DisableClock(LL_APB1_GRP2_PERIPH_TIM1);
}

static void APP_EnterDeepStop(void)
{
  /* Enable PWR clock */
  LL_APB1_GRP1_EnableClock(LL_APB1_GRP1_PERIPH_PWR);

  /* STOP mode with deep low power regulator ON */
  LL_PWR_SetLprMode(LL_PWR_LPR_MODE_DLPR);

  /* SRAM retention voltage aligned with digital LDO output */
  LL_PWR_SetStopModeSramVoltCtrl(LL_PWR_SRAM_RETENTION_VOLT_CTRL_LDO);

  /* Enter DeepSleep mode */
  LL_LPM_EnableDeepSleep();

  /* Request Wait For Event */
   __SEV();
   __WFE();
   __WFE();

   LL_LPM_EnableSleep();
}



/**
  * @brief  Error handling function
  * @param  None
  * @retval None
  */
void APP_ErrorHandler(void)
{
  /* Infinite loop */
  while (1)
  {
  }
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file：Pointer to the source file name
  * @param  line：assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* User can add His own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* Infinite loop */
  while (1)
  {
  }
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT Puya *****END OF FILE******************/
