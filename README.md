# ECSense

"EC Sense" is intended to be used as a cost-effective four-wire electrical conductivity meter for use in water applications. 

## Documentation Sections:
1) Breakdown of Repository Contents.
2) Instructions for Using "EC Sense."
3) Technical Documentation (Specifications, Schematics, Simulation Files, etc.).
4) How to Procure "EC Sense."

<hr>

### Breakdown of Repository Contents:

1) "ADC_test.ino" --> 
2) "BOM.csv"
3) "EC Sense - SmartRock.f3z"
4) "EC Sense - SmartRock (Schematic).pdf"
5) "Gerber.zip"
6) "PnP.csv"
   
<hr>

### Instructions for Using "EC Sense:"

"EC Sense" is designed to be used as a shield for the Adafruit Feather family of microprocessor boards. We recommend using "Adafruit Feather M0" variants (https://www.adafruit.com/product/2772 (basic), https://www.adafruit.com/product/3010 (WiFi), and others) paired with an "OPEnS Hypnos" (https://github.com/OPEnSLab-OSU/OPEnS-Hypnos) for power management, SD card data logging, and real time clock (RTC) functionality. Alternatively, the "Adafruit Feather M0 Adalogger" (https://www.adafruit.com/product/2796) paired with an "Adalogger FeatherWing - RTC + SD Add-on" (https://www.adafruit.com/product/2922) could be used to make a cost-effective datalogger for "EC Sense" using only commercially available boards. 

<hr>

### Technical Documentation:

#### Specifications Table - 
#### "EC Sense" Schematic - 
#### Simulation (LT Spice) - 

<hr>

### How to Procure "EC Sense:"

1) Go to "https://www.pcbway.com/" and make a "My PCBWay" account (or sign in, if you already have a member account).

   ![image](https://github.com/user-attachments/assets/4f1bcbd6-b0d2-40f4-86f4-aa8f18c171fd)

2) Once you have logged in, go to "https://member.pcbway.com/" and click "PCB Instant Quote."

   ![image](https://github.com/user-attachments/assets/2e58c136-2b3b-405c-acf1-c78681a9b109)

3) Then click "Quick-order PCB."

   ![image](https://github.com/user-attachments/assets/a7eae75a-f29b-45e6-95fd-16a0f3e925cd)

4) Under "PCB Specification Selection" click "+Add Gerber File" and upload "Gerber.zip" from the repository. After the gerber files archive has been uploaded, enter the desired quantity under "Quantity (single)." This quantity will need to match the quantity of assembled units, which will be addressed in a later step. Default options under "PCB Specification Selection" are acceptable, but you may tweak these options as appropriate for your application (for example, changing the color of the soldermask or selecting a different surface finish material). 
   
   ![image](https://github.com/user-attachments/assets/6b05176c-7f99-48a6-bf3a-77e95d7babb7)

5) Next, scroll down until you see "Assembly Service" and check the checkbox.

   ![image](https://github.com/user-attachments/assets/ff9f70c6-fa8b-4da8-be21-a9124550a477)

6) You will need to enter the desired quantity of assembled units. The number you enter here must match what you previously entered under "PCB Specification Selection --> Quantity (single)."

   ![image](https://github.com/user-attachments/assets/0f1c45ca-edb3-4a12-90db-bde9cfea8b38)

7) Make sure radio buttons under "Pay attention" are both marked as follows ("Contains sensitive components/parts" --> NO, "Do you accept alternative/substitutes made in China?" --> NO). All fields under "Other Parameters" may be ignored.

   ![image](https://github.com/user-attachments/assets/65e820f1-8e95-4512-8c00-e5db3d77e560)

8) (Optional) Under "Customized Services and Advanced Options" you have the option to have PCBWay conformally coat your boards. You may select this option if appropriate for your application.

   ![image](https://github.com/user-attachments/assets/67ef92c0-e922-4b15-8466-451e568010b8)

9)  Click "Save to Cart" and ensure you agree with the terms of service.

10)  Once in your shopping cart, you will need to upload the Bill-of-Materials (BOM) and Pick-and-Place (PnP) files. Extract "BOM.csv" and "PnP.csv" from the downloaded repository files, and upload both of them to your PCBWay order by clicking the "Add File" button

   ![image](https://github.com/user-attachments/assets/d8fb4d95-740f-4daa-be2d-a14101f33818)

11)  Upload "BOM.csv" to "Parts List (BOM) Upload" and "PnP.csv" to "Upload Centroid File." Then click "Submit Order Now."

   ![image](https://github.com/user-attachments/assets/c3300691-df6e-4d2d-aebc-3cb2abbbf53e)

12)  PCBWay will then review the order and begin manufacturing. You will receive a final quote from PCBWay via email once PCBWay has reviewed the assembly order for issues. The lead time is typically 3-6 weeks depending on quantity, component availability, holidays in China, and other factors. The order should pass right through PCBWay's design review process. Should you encounter issues with your order approval, contact Dr. Chet Udell (udellc@oregonstate.edu) for guidance. Enjoy using EC Sense!

