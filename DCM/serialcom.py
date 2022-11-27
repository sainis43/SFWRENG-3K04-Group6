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
frdm_port = "COM3"
# Text file data converted to integer data type

array =[]
Data = np.genfromtxt("data.txt",encoding=None)
for each in Data:
    array.append(each)

mode = array[0]
LRL = array[1]
URL =array[2]
AA = array[3]
APW = array[4]
VA = array[5]
VPW = array[6]
VRP = array[7]
ARP = array[8]
MSR = array[9]
AS = array[10]
VS = array[11]
PVARP = array[12]
AT = array[13]
RnT = array[14]
RF = array[15]
RyT = array[16]

if(endian_check()==True):
    # little endian
    Start = b'\x16' #unsigned 22
    SYNC = b'\x22' #unsigned 34
    Fn_set = b'\x55' #unsigned 85
    mode_en = struct.pack(">B", int(mode))
    LRL_en = struct.pack("<B", int(LRL))
    URL_en =struct.pack("<B", int(URL))
    VA_en = struct.pack("<f", float(VA))
    VPW_en = struct.pack("<f", float(VPW))
    VS_en = struct.pack("<f", float(VS))
    VRP_en = struct.pack("<H", int(VRP))
    AA_en = struct.pack("<f", float(AA))
    APW_en = struct.pack("<f", float(APW))
    AS_en = struct.pack("<f", float(AS))
    ARP_en = struct.pack("<H", int(ARP))
    PVARP_en = struct.pack("<H", int(PVARP))
    MSR_en = struct.pack("<B", int(MSR))
    AT_en = struct.pack("<B", int(AT))
    RnT_en = struct.pack("<B", int(RnT))
    RF_en = struct.pack("<B", int(RF))
    RyT_en = struct.pack("<B", int(RyT))
else:
    # Big endian
    Start = b'\x16' #unsigned 22
    SYNC = b'\x22' #unsigned 34
    Fn_set = b'\x55' #unsigned 85
    mode_en = struct.pack(">B", int(mode))
    LRL_en = struct.pack(">B", int(LRL))
    URL_en =struct.pack(">B", int(URL))
    VA_en = struct.pack(">f", float(VA))
    VPW_en = struct.pack(">f", float(VPW))
    VS_en = struct.pack(">f", float(VS))
    VRP_en = struct.pack(">H", int(VRP))
    AA_en = struct.pack(">f", float(AA))
    APW_en = struct.pack(">f", float(APW))
    AS_en = struct.pack(">f", float(AS))
    ARP_en = struct.pack(">H", int(ARP))
    PVARP_en = struct.pack(">H", int(PVARP))
    MSR_en = struct.pack(">B", int(MSR))
    AT_en = struct.pack(">B", int(AT))
    RnT_en = struct.pack(">B", int(RnT))
    RF_en = struct.pack(">B", int(RF))
    RyT_en = struct.pack(">B", int(RyT))

print("Start: ", Start)
print("SYNC: ", SYNC)
print("Fn_set: ", Fn_set)
print("mode: ", mode_en)
print("LRL_en: ", LRL_en)
print("URL_en: ", URL_en)
print("MSR_en: ", MSR_en)
print("AA_en: ", AA_en)
print("APW_en: ", APW_en)
print("AS_en: ", AS_en)
print("VA_en: ", VA_en)
print("VPW_en: ", VPW_en)
print("VS_en: ", VS_en)
print("ARP_en: ", ARP_en)
print("VRP_en: ", VRP_en)
print("PVARP_en: ", PVARP_en)
print("AT_en: ", AT_en)
print("RnT_en: ", RnT_en)
print("RF_en: ", RF_en)
print("RyT_en: ", RyT_en)

mode_de = struct.unpack("B", mode_en)
LRL_de = struct.unpack("B", LRL_en)
URL_de =struct.unpack("B", URL_en)
VA_de = struct.unpack("f", VA_en)
VPW_de = struct.unpack("f", VPW_en)
VS_de = struct.unpack("f", VS_en)
VRP_de = struct.unpack("H", VRP_en)
AA_de = struct.unpack("f", AA_en)
APW_de = struct.unpack("f", APW_en)
AS_de = struct.unpack("f", AS_en)
ARP_de = struct.unpack("H", ARP_en)
PVARP_de = struct.unpack("H", PVARP_en)
MSR_de = struct.unpack("B", MSR_en)
AT_de = struct.unpack("B", AT_en)
RnT_de = struct.unpack("B", RnT_en)
RF_de = struct.unpack("B", RF_en)
RyT_de = struct.unpack("B", RyT_en)

print("mode_en: ", mode_de[0])
print("LRL_en: ", LRL_de[0])
print("URL_en: ", URL_de[0])
print("MSR_en: ", MSR_de[0])
print("AA_en: ", AA_de[0])
print("APW_en: ", APW_de[0])
print("AS_en: ", AS_de[0])
print("VA_en: ", VA_de[0])
print("VPW_en: ", VPW_de[0])
print("VS_en: ", VS_de[0])
print("ARP_en: ", ARP_de[0])
print("VRP_en: ", VRP_de[0])
print("PVARP_en: ", PVARP_de[0])
print("AT_en: ", AT_de[0])
print("RnT_en: ", RnT_de[0])
print("RF_en: ", RF_de[0])
print("RyT_en: ", RyT_de[0])

