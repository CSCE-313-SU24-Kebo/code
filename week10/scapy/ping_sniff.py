from scapy.all import *

# Send a ping request to 8.8.8.8
# ping = IP(dst="8.8.8.8")/ICMP() # this is the stack !
# reply = sr1(ping)

# Define a function to print information about sniffed packets
def print_packet(packet):
    print(packet.show())

# Sniff packets for 10 seconds that match the ICMP ping request/reply
sniff(filter="icmp", prn=print_packet, timeout=10)

ping = IP(dst="8.8.8.8")/ICMP() # this is the stack !
reply = sr1(ping)

