EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "auto_driving_car"
Date "2021-12-25"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 2300 2850 0    50   ~ 0
ArduinoMKRWiFi1010
$Comp
L Driver_Motor:L298HN U2
U 1 1 61C5243B
P 7600 1600
F 0 "U2" H 7600 2481 50  0000 C CNN
F 1 "L298HN" H 7600 2390 50  0000 C CNN
F 2 "Package_TO_SOT_THT:TO-220-15_P2.54x2.54mm_StaggerOdd_Lead4.58mm_Vertical" H 7650 950 50  0001 L CNN
F 3 "http://www.st.com/st-web-ui/static/active/en/resource/technical/document/datasheet/CD00000240.pdf" H 7750 1850 50  0001 C CNN
	1    7600 1600
	1    0    0    -1  
$EndComp
$Comp
L s_motor-cache:ULN2003A U1
U 1 1 61C53E55
P 7450 3600
F 0 "U1" H 7450 4267 50  0000 C CNN
F 1 "ULN2003A" H 7450 4176 50  0000 C CNN
F 2 "" H 7500 3050 50  0001 L CNN
F 3 "" H 7550 3400 50  0001 C CNN
	1    7450 3600
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0101
U 1 1 61C59529
P 7600 2300
F 0 "#PWR0101" H 7600 2050 50  0001 C CNN
F 1 "GND" H 7605 2127 50  0000 C CNN
F 2 "" H 7600 2300 50  0001 C CNN
F 3 "" H 7600 2300 50  0001 C CNN
	1    7600 2300
	1    0    0    -1  
$EndComp
$Comp
L power:GND #PWR0102
U 1 1 61C59F01
P 7450 4200
F 0 "#PWR0102" H 7450 3950 50  0001 C CNN
F 1 "GND" H 7455 4027 50  0000 C CNN
F 2 "" H 7450 4200 50  0001 C CNN
F 3 "" H 7450 4200 50  0001 C CNN
	1    7450 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	5650 1100 7000 1100
Text GLabel 5650 1100 0    50   Input ~ 0
D1
Wire Wire Line
	7000 1200 5650 1200
Text GLabel 5650 1200 0    50   Input ~ 0
D2
Wire Wire Line
	7000 1300 5650 1300
Text GLabel 5650 1300 0    50   Input ~ 0
D0
Wire Wire Line
	7000 1500 5650 1500
Wire Wire Line
	7000 1600 5650 1600
Wire Wire Line
	7000 1700 5650 1700
Text GLabel 5650 1500 0    50   Input ~ 0
D3
Text GLabel 5650 1600 0    50   Input ~ 0
D4
Text GLabel 5650 1700 0    50   Input ~ 0
D5
$Comp
L Motor:Motor_DC M1
U 1 1 61C6F596
P 9450 1350
F 0 "M1" H 9608 1346 50  0000 L CNN
F 1 "Motor_DC" H 9608 1255 50  0000 L CNN
F 2 "" H 9450 1260 50  0001 C CNN
F 3 "~" H 9450 1260 50  0001 C CNN
	1    9450 1350
	1    0    0    -1  
$EndComp
$Comp
L Motor:Motor_DC M2
U 1 1 61C70B40
P 9450 2100
F 0 "M2" H 9608 2096 50  0000 L CNN
F 1 "Motor_DC" H 9608 2005 50  0000 L CNN
F 2 "" H 9450 2010 50  0001 C CNN
F 3 "~" H 9450 2010 50  0001 C CNN
	1    9450 2100
	1    0    0    -1  
$EndComp
Wire Wire Line
	8200 1700 8800 1700
Wire Wire Line
	8800 1700 8800 1900
Wire Wire Line
	8800 1900 9450 1900
Wire Wire Line
	8200 1800 8700 1800
Wire Wire Line
	8700 1800 8700 2400
Wire Wire Line
	8700 2400 9450 2400
Wire Wire Line
	8200 1500 9200 1500
Wire Wire Line
	9200 1500 9200 1150
Wire Wire Line
	9200 1150 9450 1150
Wire Wire Line
	8200 1400 9050 1400
Wire Wire Line
	9050 1400 9050 1650
Wire Wire Line
	9050 1650 9450 1650
Text GLabel 3450 750  0    50   Input ~ 0
Vbatt
Wire Wire Line
	3450 750  4550 750 
Wire Wire Line
	7600 750  7600 900 
Wire Wire Line
	7850 3200 7850 2800
Wire Wire Line
	7850 2800 4550 2800
Wire Wire Line
	4550 2800 4550 750 
Connection ~ 4550 750 
Wire Wire Line
	4550 750  7600 750 
Wire Wire Line
	7050 3600 5700 3600
Wire Wire Line
	7050 3700 5700 3700
Text GLabel 5650 3400 0    50   Input ~ 0
D8
Text GLabel 5650 3500 0    50   Input ~ 0
D9
Text GLabel 5700 3600 0    50   Input ~ 0
D10
Text GLabel 5700 3700 0    50   Input ~ 0
D13
$Comp
L Motor:Stepper_Motor_unipolar_5pin M3
U 1 1 61C7757F
P 9450 3700
F 0 "M3" H 9638 3824 50  0000 L CNN
F 1 "Stepper_Motor_unipolar_5pin" H 9638 3733 50  0000 L CNN
F 2 "" H 9460 3690 50  0001 C CNN
F 3 "http://www.infineon.com/dgdl/Application-Note-TLE8110EE_driving_UniPolarStepperMotor_V1.1.pdf?fileId=db3a30431be39b97011be5d0aa0a00b0" H 9460 3690 50  0001 C CNN
	1    9450 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9250 3400 9250 2800
Wire Wire Line
	9250 2800 7850 2800
Connection ~ 7850 2800
Wire Wire Line
	9150 3800 8550 3800
Wire Wire Line
	8550 3800 8550 3400
Wire Wire Line
	8550 3400 7850 3400
Wire Wire Line
	9550 3400 9550 3250
Wire Wire Line
	9550 3250 8000 3250
Wire Wire Line
	8000 3250 8000 3500
Wire Wire Line
	8000 3500 7850 3500
Wire Wire Line
	9150 3600 7850 3600
Wire Wire Line
	9350 3400 9350 3050
Wire Wire Line
	9350 3050 8250 3050
Wire Wire Line
	8250 3050 8250 3700
Wire Wire Line
	8250 3700 7850 3700
Wire Wire Line
	7150 5000 5700 5000
Wire Wire Line
	7150 5200 5700 5200
Wire Wire Line
	7150 5550 5700 5550
$Comp
L power:GND #PWR?
U 1 1 61C83303
P 7150 5750
F 0 "#PWR?" H 7150 5500 50  0001 C CNN
F 1 "GND" H 7155 5577 50  0000 C CNN
F 2 "" H 7150 5750 50  0001 C CNN
F 3 "" H 7150 5750 50  0001 C CNN
	1    7150 5750
	1    0    0    -1  
$EndComp
Text GLabel 5700 5000 0    50   Input ~ 0
D06
Text GLabel 5700 5200 0    50   Input ~ 0
D07
$Comp
L power:+3.3V #PWR?
U 1 1 61C83DA7
P 5700 5550
F 0 "#PWR?" H 5700 5400 50  0001 C CNN
F 1 "+3.3V" H 5715 5723 50  0000 C CNN
F 2 "" H 5700 5550 50  0001 C CNN
F 3 "" H 5700 5550 50  0001 C CNN
	1    5700 5550
	1    0    0    -1  
$EndComp
Text Label 7200 4800 0    50   ~ 0
URM37
Wire Wire Line
	7000 4850 7650 4850
Wire Wire Line
	7650 4850 7650 5750
Wire Wire Line
	7650 5750 7150 5750
Wire Wire Line
	7000 5750 7000 4850
Connection ~ 7150 5750
Wire Wire Line
	7150 5750 7000 5750
Text Label 7150 5050 0    50   ~ 0
ECHO
Text Label 7150 5250 0    50   ~ 0
Pulse
Text Label 7150 5600 0    50   ~ 0
pow
Wire Wire Line
	3550 2550 3550 2800
Wire Wire Line
	3550 4850 2650 4850
Wire Wire Line
	1850 4850 1850 2550
Wire Wire Line
	1850 2550 3550 2550
Wire Wire Line
	4550 2800 3550 2800
Connection ~ 4550 2800
Connection ~ 3550 2800
Wire Wire Line
	3550 2800 3550 4550
Text Label 3600 2900 0    50   ~ 0
VIN
$Comp
L power:GND #PWR?
U 1 1 61CAB3BB
P 2650 4850
F 0 "#PWR?" H 2650 4600 50  0001 C CNN
F 1 "GND" H 2655 4677 50  0000 C CNN
F 2 "" H 2650 4850 50  0001 C CNN
F 3 "" H 2650 4850 50  0001 C CNN
	1    2650 4850
	1    0    0    -1  
$EndComp
Connection ~ 2650 4850
Wire Wire Line
	2650 4850 1850 4850
Text Label 3000 950  0    50   ~ 0
NiH_series_5_units
Text Label 7600 4800 0    50   ~ 0
Ultra_sonic_distance_sensor
Wire Wire Line
	5650 3400 7050 3400
Wire Wire Line
	5650 3500 7050 3500
Wire Wire Line
	3550 4550 4600 4550
Wire Wire Line
	4600 4550 4600 5550
Wire Wire Line
	4600 5550 5700 5550
Connection ~ 3550 4550
Wire Wire Line
	3550 4550 3550 4850
Connection ~ 5700 5550
Text Label 3600 4650 0    50   ~ 0
3.3V
$EndSCHEMATC
