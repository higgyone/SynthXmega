EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:switches
LIBS:relays
LIBS:motors
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:TopSheet-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 6 6
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L VCC #PWR?
U 1 1 59FF443D
P 3950 3850
F 0 "#PWR?" H 3950 3700 50  0001 C CNN
F 1 "VCC" H 3950 4000 50  0000 C CNN
F 2 "" H 3950 3850 50  0001 C CNN
F 3 "" H 3950 3850 50  0001 C CNN
	1    3950 3850
	1    0    0    -1  
$EndComp
$Comp
L POT RV?
U 1 1 59FF4443
P 3950 4280
F 0 "RV?" V 3775 4280 50  0000 C CNN
F 1 "100k" V 3850 4280 50  0000 C CNN
F 2 "" H 3950 4280 50  0001 C CNN
F 3 "" H 3950 4280 50  0001 C CNN
	1    3950 4280
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 59FF444A
P 3950 4650
F 0 "#PWR?" H 3950 4400 50  0001 C CNN
F 1 "GND" H 3950 4500 50  0000 C CNN
F 2 "" H 3950 4650 50  0001 C CNN
F 3 "" H 3950 4650 50  0001 C CNN
	1    3950 4650
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 59FF4452
P 4440 4280
F 0 "R?" V 4520 4280 50  0000 C CNN
F 1 "330k" V 4440 4280 50  0000 C CNN
F 2 "" V 4370 4280 50  0001 C CNN
F 3 "" H 4440 4280 50  0001 C CNN
	1    4440 4280
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 59FF4462
P 5500 4610
F 0 "#PWR?" H 5500 4360 50  0001 C CNN
F 1 "GND" H 5500 4460 50  0000 C CNN
F 2 "" H 5500 4610 50  0001 C CNN
F 3 "" H 5500 4610 50  0001 C CNN
	1    5500 4610
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 59FF446E
P 5500 3810
F 0 "#PWR?" H 5500 3660 50  0001 C CNN
F 1 "VCC" H 5500 3960 50  0000 C CNN
F 2 "" H 5500 3810 50  0001 C CNN
F 3 "" H 5500 3810 50  0001 C CNN
	1    5500 3810
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 59FF4475
P 5560 3250
F 0 "R?" V 5640 3250 50  0000 C CNN
F 1 "150k" V 5560 3250 50  0000 C CNN
F 2 "" V 5490 3250 50  0001 C CNN
F 3 "" H 5560 3250 50  0001 C CNN
	1    5560 3250
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 59FF448B
P 7380 4540
F 0 "#PWR?" H 7380 4290 50  0001 C CNN
F 1 "GND" H 7380 4390 50  0000 C CNN
F 2 "" H 7380 4540 50  0001 C CNN
F 3 "" H 7380 4540 50  0001 C CNN
	1    7380 4540
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 59FF449C
P 7380 3250
F 0 "R?" V 7460 3250 50  0000 C CNN
F 1 "2.2M" V 7380 3250 50  0000 C CNN
F 2 "" V 7310 3250 50  0001 C CNN
F 3 "" H 7380 3250 50  0001 C CNN
	1    7380 3250
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 59FF44A9
P 8040 5930
F 0 "C?" H 8065 6030 50  0000 L CNN
F 1 "100n" H 8065 5830 50  0000 L CNN
F 2 "Capacitors_SMD:C_0603_HandSoldering" H 8078 5780 50  0001 C CNN
F 3 "" H 8040 5930 50  0001 C CNN
	1    8040 5930
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR?
U 1 1 59FF44B0
P 8040 6180
F 0 "#PWR?" H 8040 5930 50  0001 C CNN
F 1 "GND" H 8040 6030 50  0000 C CNN
F 2 "" H 8040 6180 50  0001 C CNN
F 3 "" H 8040 6180 50  0001 C CNN
	1    8040 6180
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 59FF44B8
P 8040 5680
F 0 "#PWR?" H 8040 5530 50  0001 C CNN
F 1 "VCC" H 8040 5830 50  0000 C CNN
F 2 "" H 8040 5680 50  0001 C CNN
F 3 "" H 8040 5680 50  0001 C CNN
	1    8040 5680
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 59FF44D3
P 5570 2420
F 0 "R?" V 5650 2420 50  0000 C CNN
F 1 "2.2k" V 5570 2420 50  0000 C CNN
F 2 "" V 5500 2420 50  0001 C CNN
F 3 "" H 5570 2420 50  0001 C CNN
	1    5570 2420
	0    1    1    0   
$EndComp
$Comp
L C C?
U 1 1 59FF44DA
P 4410 2420
F 0 "C?" H 4435 2520 50  0000 L CNN
F 1 "470uF" H 4435 2320 50  0000 L CNN
F 2 "" H 4448 2270 50  0001 C CNN
F 3 "" H 4410 2420 50  0001 C CNN
	1    4410 2420
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 59FF44E2
P 4990 2120
F 0 "R?" V 5070 2120 50  0000 C CNN
F 1 "100k" V 4990 2120 50  0000 C CNN
F 2 "" V 4920 2120 50  0001 C CNN
F 3 "" H 4990 2120 50  0001 C CNN
	1    4990 2120
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 59FF44F1
P 8920 4080
F 0 "R?" V 9000 4080 50  0000 C CNN
F 1 "3k" V 8920 4080 50  0000 C CNN
F 2 "" V 8850 4080 50  0001 C CNN
F 3 "" H 8920 4080 50  0001 C CNN
	1    8920 4080
	0    1    1    0   
$EndComp
$Comp
L R R?
U 1 1 59FF44F8
P 9650 4410
F 0 "R?" V 9730 4410 50  0000 C CNN
F 1 "1.8k" V 9650 4410 50  0000 C CNN
F 2 "" V 9580 4410 50  0001 C CNN
F 3 "" H 9650 4410 50  0001 C CNN
	1    9650 4410
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 59FF4502
P 9650 4750
F 0 "#PWR?" H 9650 4500 50  0001 C CNN
F 1 "GND" H 9650 4600 50  0000 C CNN
F 2 "" H 9650 4750 50  0001 C CNN
F 3 "" H 9650 4750 50  0001 C CNN
	1    9650 4750
	1    0    0    -1  
$EndComp
Text HLabel 10070 4080 2    60   Output ~ 0
PWMOut
Text HLabel 3590 2420 0    60   Input ~ 0
SineIn
$Comp
L POT RV?
U 1 1 59FF450C
P 3370 3250
F 0 "RV?" V 3195 3250 50  0000 C CNN
F 1 "100k" V 3270 3250 50  0000 C CNN
F 2 "" H 3370 3250 50  0001 C CNN
F 3 "" H 3370 3250 50  0001 C CNN
	1    3370 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 59FF4513
P 3370 3620
F 0 "#PWR?" H 3370 3370 50  0001 C CNN
F 1 "GND" H 3370 3470 50  0000 C CNN
F 2 "" H 3370 3620 50  0001 C CNN
F 3 "" H 3370 3620 50  0001 C CNN
	1    3370 3620
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 59FF451B
P 3860 3250
F 0 "R?" V 3940 3250 50  0000 C CNN
F 1 "100k" V 3860 3250 50  0000 C CNN
F 2 "" V 3790 3250 50  0001 C CNN
F 3 "" H 3860 3250 50  0001 C CNN
	1    3860 3250
	0    1    1    0   
$EndComp
Text HLabel 3270 2820 0    60   Input ~ 0
LFOInput
$Comp
L TLV2374 U?
U 1 1 59FF45A0
P 5600 4180
F 0 "U?" H 5600 4380 50  0000 L CNN
F 1 "TLV2374" H 5600 3980 50  0000 L CNN
F 2 "" H 5550 4280 50  0001 C CNN
F 3 "" H 5650 4380 50  0001 C CNN
	1    5600 4180
	1    0    0    -1  
$EndComp
$Comp
L TLV2374 U?
U 2 1 59FF4615
P 7480 4080
F 0 "U?" H 7480 4280 50  0000 L CNN
F 1 "TLV2374" H 7480 3880 50  0000 L CNN
F 2 "" H 7430 4180 50  0001 C CNN
F 3 "" H 7530 4280 50  0001 C CNN
	2    7480 4080
	1    0    0    -1  
$EndComp
$Comp
L TLV2374 U?
U 3 1 59FF46B0
P 1680 1770
F 0 "U?" H 1680 1970 50  0000 L CNN
F 1 "TLV2374" H 1680 1570 50  0000 L CNN
F 2 "" H 1630 1870 50  0001 C CNN
F 3 "" H 1730 1970 50  0001 C CNN
	3    1680 1770
	1    0    0    -1  
$EndComp
$Comp
L TLV2374 U?
U 4 1 59FF472F
P 3980 6990
F 0 "U?" H 3980 7190 50  0000 L CNN
F 1 "TLV2374" H 3980 6790 50  0000 L CNN
F 2 "" H 3930 7090 50  0001 C CNN
F 3 "" H 4030 7190 50  0001 C CNN
	4    3980 6990
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 59FF57B0
P 7380 3640
F 0 "#PWR?" H 7380 3490 50  0001 C CNN
F 1 "VCC" H 7380 3790 50  0000 C CNN
F 2 "" H 7380 3640 50  0001 C CNN
F 3 "" H 7380 3640 50  0001 C CNN
	1    7380 3640
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 59FF5FE8
P 830 1470
F 0 "R?" V 910 1470 50  0000 C CNN
F 1 "33k" V 830 1470 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 760 1470 50  0001 C CNN
F 3 "" H 830 1470 50  0001 C CNN
	1    830  1470
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 59FF5FEF
P 830 1970
F 0 "R?" V 910 1970 50  0000 C CNN
F 1 "33k" V 830 1970 50  0000 C CNN
F 2 "Resistors_SMD:R_0603_HandSoldering" V 760 1970 50  0001 C CNN
F 3 "" H 830 1970 50  0001 C CNN
	1    830  1970
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 59FF5FF6
P 1580 2270
F 0 "#PWR?" H 1580 2020 50  0001 C CNN
F 1 "GND" H 1580 2120 50  0000 C CNN
F 2 "" H 1580 2270 50  0001 C CNN
F 3 "" H 1580 2270 50  0001 C CNN
	1    1580 2270
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 59FF5FFC
P 830 2270
F 0 "#PWR?" H 830 2020 50  0001 C CNN
F 1 "GND" H 830 2120 50  0000 C CNN
F 2 "" H 830 2270 50  0001 C CNN
F 3 "" H 830 2270 50  0001 C CNN
	1    830  2270
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 59FF6005
P 830 1270
F 0 "#PWR?" H 830 1120 50  0001 C CNN
F 1 "VCC" H 830 1420 50  0000 C CNN
F 2 "" H 830 1270 50  0001 C CNN
F 3 "" H 830 1270 50  0001 C CNN
	1    830  1270
	1    0    0    -1  
$EndComp
$Comp
L VCC #PWR?
U 1 1 59FF619F
P 1580 1220
F 0 "#PWR?" H 1580 1070 50  0001 C CNN
F 1 "VCC" H 1580 1370 50  0000 C CNN
F 2 "" H 1580 1220 50  0001 C CNN
F 3 "" H 1580 1220 50  0001 C CNN
	1    1580 1220
	1    0    0    -1  
$EndComp
Text Notes 2240 1770 0    60   ~ 0
VCC/2
Wire Wire Line
	3950 4430 3950 4650
Wire Wire Line
	3950 4130 3950 3850
Wire Wire Line
	4100 4280 4290 4280
Wire Wire Line
	4590 4280 4740 4280
Wire Wire Line
	4740 4280 5300 4280
Wire Wire Line
	5300 4080 5130 4080
Wire Wire Line
	5500 4480 5500 4610
Wire Wire Line
	5900 4180 6260 4180
Wire Wire Line
	6260 4180 7180 4180
Wire Wire Line
	6260 4180 6260 3250
Wire Wire Line
	6260 3250 5710 3250
Wire Wire Line
	4010 3250 4740 3250
Wire Wire Line
	4740 3250 5410 3250
Wire Wire Line
	4740 3250 4740 4280
Connection ~ 4740 4280
Connection ~ 6260 4180
Wire Wire Line
	8190 3250 7530 3250
Wire Wire Line
	6680 3250 7230 3250
Wire Wire Line
	8040 6080 8040 6180
Wire Wire Line
	8040 5780 8040 5680
Wire Wire Line
	4560 2420 4990 2420
Wire Wire Line
	4990 2420 5420 2420
Wire Wire Line
	4990 2270 4990 2420
Connection ~ 4990 2420
Wire Wire Line
	4260 2420 3590 2420
Wire Wire Line
	5720 2420 6680 2420
Connection ~ 6680 3250
Wire Wire Line
	9650 4750 9650 4560
Wire Wire Line
	3370 3400 3370 3620
Wire Wire Line
	3370 3100 3370 2820
Wire Wire Line
	3520 3250 3710 3250
Wire Wire Line
	3370 2820 3270 2820
Wire Wire Line
	5500 3880 5500 3810
Wire Wire Line
	6680 3980 7180 3980
Wire Wire Line
	6680 2420 6680 3250
Wire Wire Line
	6680 3250 6680 3980
Wire Wire Line
	7380 4380 7380 4540
Wire Wire Line
	7380 3780 7380 3640
Wire Wire Line
	7780 4080 8190 4080
Wire Wire Line
	8190 4080 8770 4080
Wire Wire Line
	8190 4080 8190 3250
Connection ~ 8190 4080
Wire Wire Line
	9070 4080 9650 4080
Wire Wire Line
	9650 4080 10070 4080
Wire Wire Line
	9650 4260 9650 4080
Connection ~ 9650 4080
Wire Wire Line
	830  1270 830  1320
Wire Wire Line
	830  1620 830  1670
Wire Wire Line
	830  1670 830  1820
Wire Wire Line
	830  2120 830  2270
Wire Wire Line
	1580 2070 1580 2270
Wire Wire Line
	1380 1670 830  1670
Connection ~ 830  1670
Wire Wire Line
	1380 1870 1280 1870
Wire Wire Line
	1280 1870 1280 2620
Wire Wire Line
	1280 2620 2100 2620
Wire Wire Line
	2100 2620 2100 1770
Wire Wire Line
	1980 1770 2100 1770
Wire Wire Line
	2100 1770 2630 1770
Wire Wire Line
	2630 1770 4990 1770
Connection ~ 2100 1770
Wire Wire Line
	1580 1470 1580 1220
Wire Wire Line
	5130 4080 5130 5560
Wire Wire Line
	4990 1770 4990 1970
Connection ~ 4740 3250
Wire Wire Line
	5130 5560 2630 5560
Wire Wire Line
	2630 5560 2630 1770
Connection ~ 2630 1770
NoConn ~ 3880 6690
NoConn ~ 3680 6890
NoConn ~ 4280 6990
NoConn ~ 3680 7090
NoConn ~ 3880 7290
$EndSCHEMATC
