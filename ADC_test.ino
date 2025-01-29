// Author: Paul Gasper
// Affiliation: Oregon State University - Openly Published Environmental Sensing Lab (OPEnS https://github.com/OPEnSLab-OSU)
// Date: January 28th, 2025

// EC Sense Software - Written for Adafruit Feather M0 Microcontroller https://www.adafruit.com/product/2772)

// Instructions: Stack Feather M0 microcontroller on top of EC Sense. Ensure electrode array is soldered to terminals. Connect microcontroller to computer using mini-usb cable. 
//               Upload software as provided. Go to tools --> serial monitor. You should now see output data show up in the serial monitor. 

// Terminals: [A] - Square wave source. [M] - Differential+ electrode. [N] - Differential- electrode. [B] - Square wave sink (path to ground via shunt resistor).

// Shunt Resistor Sizing: 
//    Seawater (~10,000uS/cm to ~50,000uS/cm) --> 10 Ohm
//    Brackish (~1,000uS/cm to ~10,000uS/cm) --> 100 Ohm
//    Fresh (~100uS/cm to ~1,000uS/cm) --> 1,000 Ohm
//    Distilled (~1uS/cm to ~100uS/cm) --> 10,000 Ohm



#include <Adafruit_ADS1X15.h>

// ADC Type Declaration
 Adafruit_ADS1115 ads; 

// Pin connected to the ALERT/RDY signal for new sample notification.
constexpr int READY_PIN = 3;
constexpr int CLOCK_PIN = 13;
constexpr int INTERRUPT_PIN = 12;


// This is required on ESP32 to put the ISR in IRAM. Define as
// empty for other platforms. Be careful - other platforms may have
// other requirements.
#ifndef IRAM_ATTR
#define IRAM_ATTR
#endif

// Variable names for ADC channel outputs.
float adc0_avg;
float adc1_avg;
float adc2_avg;
float adc3_avg;

// Set default gain values.
int gain0 = 0;
int gain1 = 0;

// Declare intermediate variable names/types.
int16_t adc0, adc1, adc2, adc3;
  float volts0, volts1, volts2, volts3;

// Check for new data availability (unused).
volatile bool new_data = false;
void IRAM_ATTR NewDataReadyISR() {
  new_data = true;
}

// Configure microprocessor (Feather M0) and Hypnos power rails (if used) --> (https://github.com/OPEnSLab-OSU/OPEnS-Hypnos).
void setup(void)
{

  while (!Serial ){
    delay(1);
  }
  Serial.begin(115200);
  delay(100);
  Serial.println("Hello!");

  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  pinMode(20, INPUT_PULLUP);
  pinMode(21, INPUT_PULLUP);

  Serial.println("Getting data from ADC0 (current) and ADC1 (differential voltage)...");
  Serial.println("[Current Shunt Voltage] [Current Gain] | [Differential Voltage] [Voltage Gain]");


  // Initial gain setting.
   ads.setGain(GAIN_ONE);
 
  // Initialize ADS1115 ADC/
  if (!ads.begin()) {
    Serial.println("Failed to initialize ADS.");
    while (1);
  }
}

// Repeatedly run the test program with minimal loop delay.
void loop(void)
{
  delay(1);
  test();
}

// Convert from ADC output to true voltage based on gain setting.
float countsToVolts(int16_t counts, int gain) {
float range;
switch (gain){
  case 1:
    range = 4.096;
    break;    
  case 2:
    range = 2.048;
    break;
  case 4:
    range = 1.024;
    break;
  case 8:
    range = 0.512;
    break;
  case 16:
    range = 0.256;
    break;
  default:
    range = 0.000;
  }
  return counts * ( range / 32768 );
}

// Test program to gather voltage and current data points.
void test()
{
  // Determine appropriate gain setting for current.
  ads.setGain(GAIN_ONE);
  gain0 = 1;
  adc0_avg = ads.readADC_SingleEnded(0);

  // Autoscaling for Current Measurement
  if (abs(adc0_avg) <= 16000 && abs(adc0_avg) >= -16000) {
    ads.setGain(GAIN_TWO);
    gain0 = 2;
    adc0_avg = ads.readADC_SingleEnded(0);
    if (abs(adc0_avg) <= 16000 && abs(adc0_avg) >= -16000) {
      ads.setGain(GAIN_FOUR);
      gain0 = 4;
      adc0_avg = ads.readADC_SingleEnded(0);
      if (abs(adc0_avg) <= 16000 && abs(adc0_avg) >= -16000) {
        ads.setGain(GAIN_EIGHT);
        gain0 = 8;
        adc0_avg = ads.readADC_SingleEnded(0);
        if (abs(adc0_avg) <= 16000 && abs(adc0_avg) >= -16000) {
          ads.setGain(GAIN_SIXTEEN);
          gain0 = 16;
          adc0_avg = ads.readADC_SingleEnded(0);
        }
        else {
        }
      }
      else {
      }
    }
    else {
    }
  }
  else {
  }

  // Take 100 samples and average
  adc0_avg = 0;
  for (int i=0; i <= 100;i++) {
    adc0_avg = adc0_avg + ads.readADC_SingleEnded(0);
  }
  adc0_avg = adc0_avg/100;

  // Convert to volts.
  volts0 = countsToVolts(adc0_avg, gain0);

  // Determine appropriate gain setting for voltage.
  ads.setGain(GAIN_ONE);
  gain1 = 1;
  adc1_avg = ads.readADC_SingleEnded(1);

  if (abs(adc1_avg) <= 16000 && abs(adc1_avg) >= -16000) {
    ads.setGain(GAIN_TWO);
    gain1 = 2;
    adc1_avg = ads.readADC_SingleEnded(1);
    if (abs(adc1_avg) <= 16000 && abs(adc1_avg) >= -16000) {
      ads.setGain(GAIN_FOUR);
      gain1 = 4;
      adc1_avg = ads.readADC_SingleEnded(1);
      if (abs(adc1_avg) <= 16000 && abs(adc1_avg) >= -16000) {
        ads.setGain(GAIN_EIGHT);
        gain1 = 8;
        adc1_avg = ads.readADC_SingleEnded(1);
        if (abs(adc1_avg) <= 16000 && abs(adc1_avg) >= -16000) {
          ads.setGain(GAIN_SIXTEEN);
          gain1 = 16;
          adc1_avg = ads.readADC_SingleEnded(1);
        }
        else {
        }
      }
      else {
      }
    }
    else {
    }
  }
  else {
  }

  // Take 100 samples and average
  adc1_avg = 0;
  for (int i=0; i <= 100;i++) {
    adc1_avg = adc1_avg + ads.readADC_SingleEnded(1);
  }
  adc1_avg = adc1_avg/100;

  // Convert to volts.
  volts1 = countsToVolts(adc1_avg, gain1);
  
  // Printout data to serial monitor.
  Serial.print(volts0, 4); Serial.print(" Current Gain: "); Serial.print(gain0); 
  Serial.print(" "); Serial.print(" | "); 
  Serial.print(volts1, 4); Serial.print(" Volts Gain: "); Serial.print(gain1); 
  Serial.println(" ");
}

