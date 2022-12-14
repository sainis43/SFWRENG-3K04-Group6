import serial
import serial.tools.list_ports
import struct
import numpy as np
import sys

def endian_check():
    if sys.byteorder == "little":
        return True
    else:
        return False

# # Mac ports, for windows you have to find the ports yourself
frdm_port = "COM4"
# Text file data converted to integer data type

array =[]
Data = np.genfromtxt("data.txt",encoding=None)
for each in Data:
    array.append(each)

MODE = array[0]
LRL = array[1]
#URL =array[2]
ATR_AMP = array[3]
AMP_PULSE_WIDTH = array[4]
VENT_AMP = array[5]
VENT_PULSE_WIDTH = array[6]
VRP = array[7]
ARP = array[8]
MSR = array[9]
AMP_sensitivity = array[10]
VENT_sensitivity = array[11]
PVARP = array[12]
Activity_theshold = array[13]
Reaction_time = array[14]
Response_factor = array[15]
Recovery_time = array[16]

if(endian_check()==True):
    #little endian
    Start = b'\x16' #unsigned 22
    SYNC = b'\x22' #unsigned 34
    Fn_set = b'\x55' #unsigned 85
    MODE_en = struct.pack("<B", int(MODE))
    LRL_en = struct.pack("<B", int(LRL))
    VENT_AMP_en = struct.pack("<f", float(VENT_AMP))
    VENT_PULSE_WIDTH_en = struct.pack("<f", float(VENT_PULSE_WIDTH))
    VENT_sensitivity_en = struct.pack("<f", float(VENT_sensitivity))
    VRP_en = struct.pack("<H", int(VRP))
    ATR_AMP_en = struct.pack("<f", float(ATR_AMP))
    AMP_PULSE_WIDTH_en = struct.pack("<f", float(AMP_PULSE_WIDTH))
    AMP_sensitivity_en = struct.pack("<f", float(AMP_sensitivity))
    ARP_en = struct.pack("<H", int(ARP))
    PVARP_en = struct.pack("<H", int(PVARP))
    MSR_en = struct.pack("<B", int(MSR))
    Activity_theshold_en = struct.pack("<B", int(Activity_theshold))
    Reaction_time_en = struct.pack("<B", int(Reaction_time))
    Response_factor_en = struct.pack("<B", int(Response_factor))
    Recovery_time_en = struct.pack("<B", int(Recovery_time))
else:
    #Big endian
    Start = b'\x16' #unsigned 22
    SYNC = b'\x22' #unsigned 34
    Fn_set = b'\x55' #unsigned 85
    MODE_en = struct.pack(">B", int(MODE))
    LRL_en = struct.pack(">B", int(LRL))
    VENT_AMP_en = struct.pack(">f", float(VENT_AMP))
    VENT_PULSE_WIDTH_en = struct.pack(">f", float(VENT_PULSE_WIDTH))
    VENT_sensitivity_en = struct.pack(">f", float(VENT_sensitivity))
    VRP_en = struct.pack(">H", int(VRP))
    ATR_AMP_en = struct.pack(">f", float(ATR_AMP))
    AMP_PULSE_WIDTH_en = struct.pack(">f", float(AMP_PULSE_WIDTH))
    AMP_sensitivity_en = struct.pack(">f", float(AMP_sensitivity))
    ARP_en = struct.pack(">H", int(ARP))
    PVARP_en = struct.pack(">H", int(PVARP))
    MSR_en = struct.pack(">B", int(MSR))
    Activity_theshold_en = struct.pack(">B", int(Activity_theshold))
    Reaction_time_en = struct.pack(">B", int(Reaction_time))
    Response_factor_en = struct.pack(">B", int(Response_factor))
    Recovery_time_en = struct.pack(">B", int(Recovery_time))

##print("Start: ", Start)
##print("SYNC: ", SYNC)
##print("Fn_set: ", Fn_set)
##print("MODE: ", MODE_en)
##print("LRL_en: ", LRL_en)
##print("MSR_en: ", MSR_en)
##print("ATR_AMP_en: ", ATR_AMP_en)
##print("AMP_PULSE_WIDTH_en: ", AMP_PULSE_WIDTH_en)
##print("AMP_sensitivity_en: ", AMP_sensitivity_en)
##print("VENT_AMP_en: ", VENT_AMP_en)
##print("VENT_PULSE_WIDTH_en: ", VENT_PULSE_WIDTH_en)
##print("VENT_sensitivity_en: ", VENT_sensitivity_en)
##print("ARP_en: ", ARP_en)
##print("VRP_en: ", VRP_en)
##print("PVARP_en: ", PVARP_en)
##print("Activity_theshold_en: ", Activity_theshold_en)
##print("Reaction_time_en: ", Reaction_time_en)
##print("Response_factor_en: ", Response_factor_en)
##print("Recovery_time_en: ", Recovery_time_en)

Signal_set = Start + Fn_set + MODE_en + LRL_en + ATR_AMP_en + AMP_PULSE_WIDTH_en + VENT_AMP_en + VENT_PULSE_WIDTH_en + VRP_en + ARP_en + MSR_en + AMP_sensitivity_en + VENT_sensitivity_en + PVARP_en + Activity_theshold_en + Reaction_time_en + Response_factor_en + Recovery_time_en
#print(Signal_set)

Signal_echo = Start + SYNC + MODE_en + LRL_en + ATR_AMP_en + AMP_PULSE_WIDTH_en + VENT_AMP_en + VENT_PULSE_WIDTH_en + VRP_en + ARP_en + MSR_en + AMP_sensitivity_en + VENT_sensitivity_en + PVARP_en + Activity_theshold_en + Reaction_time_en + Response_factor_en + Recovery_time_en

with serial.Serial(frdm_port, 115200) as pacemaker:
    pacemaker.write(Signal_set)
    print(Signal_set)
    
with serial.Serial(frdm_port, 115200) as pacemaker:
    pacemaker.write(Signal_echo)
    data = pacemaker.read(38) #should be 37
    print("\n")
    print(data)
    MODE_de = data[0]
    LRL_de = data[1]
    ATR_AMP_de = struct.unpack("f", data[2:6])[0]
    AMP_PULSE_WIDTH_de = struct.unpack("f", data[6:10])[0]
    VENT_AMP_de = struct.unpack("f", data[10:14])[0]
    VENT_PULSE_WIDTH_de = struct.unpack("f", data[14:18])[0]
    VRP_de = struct.unpack("H", data[18:20])[0]
    ARP_de = struct.unpack("H", data[20:22])[0]
    MSR_de = struct.unpack("H", data[22:24])[0]
    AMP_sensitivity_de = struct.unpack("f", data[24:28])[0]
    VENT_sensitivity_de = struct.unpack("f", data[28:32])[0]
    PVARP_de = struct.unpack("H", data[32:34])[0]
    Activity_theshold_de = data[34]
    Reaction_time_de = data[35]
    Response_factor_de = data[36]
    Recovery_time_de = data[37]
    print(MODE_de)
    print("\n")
    print(LRL_de)
    print("\n")
    print(ATR_AMP_de)
    print("\n")
    print(AMP_PULSE_WIDTH_de)
    print("\n")
    print(VENT_AMP_de)
    print("\n")
    print(VENT_PULSE_WIDTH_de)
    print("\n")
    print(VRP_de)
    print("\n")
    print(ARP_de)
    print("\n")
    print(MSR_de)
    print("\n")
    print(AMP_sensitivity_de)
    print("\n")
    print(VENT_sensitivity_de)
    print("\n")
    print(PVARP_de)
    print("\n")
    print(Activity_theshold_de)
    print("\n")
    print(Reaction_time_de)
    print("\n")
    print(Response_factor_de)
    print("\n")
    print(Recovery_time_de)




##print("Recovery_time_en: ", Recovery_time_de[0])

##MODE_de = struct.unpack("B", MODE_en)
##LRL_de = struct.unpack("B", LRL_en)
##VENT_AMP_de = struct.unpack("f", VENT_AMP_en)
##VENT_PULSE_WIDTH_de = struct.unpack("f", VENT_PULSE_WIDTH_en)
##VENT_sensitivity_de = struct.unpack("f", VENT_sensitivity_en)
##VRP_de = struct.unpack("H", VRP_en)
##ATR_AMP_de = struct.unpack("f", ATR_AMP_en)
##AMP_PULSE_WIDTH_de = struct.unpack("f", AMP_PULSE_WIDTH_en)
##AMP_sensitivity_de = struct.unpack("f", AMP_sensitivity_en)
##ARP_de = struct.unpack("H", ARP_en)
##PVARP_de = struct.unpack("H", PVARP_en)
##MSR_de = struct.unpack("B", MSR_en)
##Activity_theshold_de = struct.unpack("B", Activity_theshold_en)
##Reaction_time_de = struct.unpack("B", Reaction_time_en)
##Response_factor_de = struct.unpack("B", Response_factor_en)
##Recovery_time_de = struct.unpack("B", Recovery_time_en)
##
##
##print("MODE_en: ", MODE_de[0])
##print("LRL_en: ", LRL_de[0])
##print("MSR_en: ", MSR_de[0])
##print("ATR_AMP_en: ", ATR_AMP_de[0])
##print("AMP_PULSE_WIDTH_en: ", AMP_PULSE_WIDTH_de[0])
##print("AMP_sensitivity_en: ", AMP_sensitivity_de[0])
##print("VENT_AMP_en: ", VENT_AMP_de[0])
##print("VENT_PULSE_WIDTH_en: ", VENT_PULSE_WIDTH_de[0])
##print("VENT_sensitivity_en: ", VENT_sensitivity_de[0])
##print("ARP_en: ", ARP_de[0])
##print("VRP_en: ", VRP_de[0])
##print("PVARP_en: ", PVARP_de[0])
##print("Activity_theshold_en: ", Activity_theshold_de[0])
##print("Reaction_time_en: ", Reaction_time_de[0])
##print("Response_factor_en: ", Response_factor_de[0])
##print("Recovery_time_en: ", Recovery_time_de[0])

##print("From the board:")
##print("red_en = ", red_rev)
##print("green_en = ", green_rev)
##print("blue_en = ", blue_rev)
##print("off_time = ",  off_rev)
##print("switch_time = ", switch_rev)
