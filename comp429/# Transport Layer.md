October 26, 2022

The transport layer provides services to the Application layer and receives services from the network layer. It provides a process-by-process communication logical layer to the Application layer, using a port number. It ensures that packets are delivered error free, insequence, without duplication or loss of packets. It mangages the connection, whether it's connectionless or connection-oriented.

A port number is paired with an IP address to form a socket address - many applications have some well-known ports such as HTTP (80), FTP (20 and 21), and SMTP (25). 

The transport layer uses either a linear or a circular buffer format to hold and arrange incoming packets, with a sliding window to queue packets for acknowledgement. 
