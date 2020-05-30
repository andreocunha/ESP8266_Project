EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Wire Wire Line
	7200 4200 7500 4200
Wire Wire Line
	3000 4700 3000 4400
Wire Wire Line
	4800 4600 4600 4600
Wire Wire Line
	4600 4600 4600 4400
Wire Wire Line
	4600 4400 3000 4400
Wire Wire Line
	4000 4700 4100 4700
Wire Wire Line
	4100 4700 4100 4800
Wire Wire Line
	4700 4800 4800 4800
Wire Wire Line
	4800 4800 4800 4700
Wire Wire Line
	7100 3800 7800 3800
Wire Wire Line
	6400 4600 7800 4600
Wire Wire Line
	7800 4600 7800 4200
Wire Wire Line
	7800 3800 7800 4200
Connection ~ 7800 4200
Wire Wire Line
	6400 4200 6800 4200
Wire Wire Line
	6400 4000 6500 4000
Wire Wire Line
	6500 4000 6500 3800
Wire Wire Line
	6500 3800 6800 3800
$Comp
L circuito_distanciamento_social-eagle-import:NODEMCU U$1
U 1 1 BABD3B23
P 5600 4000
F 0 "U$1" H 5600 4000 50  0001 C CNN
F 1 "NODEMCU" H 5600 4000 50  0001 C CNN
F 2 "circuito_distanciamento_social:NODEMCU" H 5600 4000 50  0001 C CNN
F 3 "" H 5600 4000 50  0001 C CNN
	1    5600 4000
	1    0    0    -1  
$EndComp
$Comp
L circuito_distanciamento_social-eagle-import:R-EU_0207_10 R1
U 1 1 0283DCCD
P 7000 4200
F 0 "R1" H 7150 4259 59  0000 L BNN
F 1 "R-EU_0207_10" H 6850 4070 59  0000 L BNN
F 2 "circuito_distanciamento_social:0207_10" H 7000 4200 50  0001 C CNN
F 3 "" H 7000 4200 50  0001 C CNN
	1    7000 4200
	1    0    0    -1  
$EndComp
$Comp
L circuito_distanciamento_social-eagle-import:AB9V G1
U 1 1 8FAD3F58
P 3500 4700
F 0 "G1" H 3275 4825 59  0000 L BNN
F 1 "AB9V" H 3275 4500 59  0000 L BNN
F 2 "circuito_distanciamento_social:AB9V" H 3500 4700 50  0001 C CNN
F 3 "" H 3500 4700 50  0001 C CNN
	1    3500 4700
	1    0    0    -1  
$EndComp
$Comp
L circuito_distanciamento_social-eagle-import:SW_DIP-1 SW1
U 1 1 E9E31E47
P 4400 4800
F 0 "SW1" H 4200 4925 59  0000 L BNN
F 1 "SW_DIP-1" H 4200 4600 59  0000 L BNN
F 2 "circuito_distanciamento_social:EDG-01" H 4400 4800 50  0001 C CNN
F 3 "" H 4400 4800 50  0001 C CNN
	1    4400 4800
	1    0    0    -1  
$EndComp
$Comp
L circuito_distanciamento_social-eagle-import:TLLG4400 LED1
U 1 1 D5D4A691
P 7600 4200
F 0 "LED1" V 7740 3720 59  0000 L BNN
F 1 "TLLG4400" V 7725 3220 59  0000 L BNN
F 2 "circuito_distanciamento_social:LED3MM" H 7600 4200 50  0001 C CNN
F 3 "" H 7600 4200 50  0001 C CNN
	1    7600 4200
	0    -1   -1   0   
$EndComp
$Comp
L circuito_distanciamento_social-eagle-import:F_TMB SG1
U 1 1 733EDE8A
P 6900 3700
F 0 "SG1" H 6800 3950 59  0000 L BNN
F 1 "F_TMB" H 7100 3700 59  0000 L BNN
F 2 "circuito_distanciamento_social:F_TMB" H 6900 3700 50  0001 C CNN
F 3 "" H 6900 3700 50  0001 C CNN
	1    6900 3700
	1    0    0    -1  
$EndComp
Text GLabel 4800 4200 0    10   BiDi ~ 0
GND
Text GLabel 4800 4300 0    10   BiDi ~ 0
3V
Text GLabel 6400 4700 0    10   BiDi ~ 0
3V
Text GLabel 4800 3400 0    10   BiDi ~ 0
GND
Text GLabel 6400 3900 0    10   BiDi ~ 0
GND
Text GLabel 6400 3800 0    10   BiDi ~ 0
3V
$EndSCHEMATC
