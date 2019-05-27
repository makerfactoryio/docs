# Errata sheet

All known errors are listed below.

## ESP32 Version 1.3

| Modul | Description | |
|:-----:|:-----------------|:--------------|
| Micro bus |The label at the connector says IO3<br/>but it is connected to IO16.<br/>The label at the connector says IO1<br/>but it is connected to IO17.| IO3/RX &rarr; RX/IO16<br/>IO1/TX &rarr; TX/IO17 |
| GROVE | VP and VN are reversed | SW204 |
| POTENTIOMETER | VP and VN are reversed | SW300, SW302 |
| IO | VP and VN are reversed | CN210 |
| TFT | The labeling TFT is missing |
|  | The labeling of the switch SW314<br/>is not complitly correct. | Left side:<br/>IO34/T_DO &rarr; IO19/T_DO<br/>Back side:<br/>IO19/MISO &rarr; NC/MISO |
| UNIT Bus | The labeling of the switches are<br/>missing because there is not enough space. | Left switch: SW201<br/>Right side: SW200 |

## ESP32 Version 1.4

!!! Info
    This version is not available yet.   
