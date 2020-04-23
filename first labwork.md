Command: sudo apt install traceroute

Output:

Reading package lists... Done

Building dependency tree

Reading state information... Done

The following packages were automatically installed and are no longer required:

gir1.2-geocodeglib-1.0 libfwup1 libllvm8 ubuntu-web-launchers

Use &#39;sudo apt autoremove&#39; to remove them.

The following NEW packages will be installed:

traceroute

0 upgraded, 1 newly installed, 0 to remove and 30 not upgraded.

Need to get 45.4 kB of archives.

After this operation, 152 kB of additional disk space will be used.

Get:1 http://vn.archive.ubuntu.com/ubuntu bionic/universe amd64 traceroute amd64 1:2.1.0-2 [45.4 kB]

Fetched 45.4 kB in 1s (37.9 kB/s)

Selecting previously unselected package traceroute.

(Reading database ... 181648 files and directories currently installed.)

Preparing to unpack .../traceroute\_1%3a2.1.0-2\_amd64.deb ...

Unpacking traceroute (1:2.1.0-2) ...

Setting up traceroute (1:2.1.0-2) ...

update-alternatives: using /usr/bin/traceroute.db to provide /usr/bin/traceroute (traceroute) in auto mode

update-alternatives: using /usr/bin/lft.db to provide /usr/bin/lft (lft) in auto mode

update-alternatives: using /usr/bin/traceproto.db to provide /usr/bin/traceproto (traceproto) in auto mode

update-alternatives: using /usr/sbin/tcptraceroute.db to provide /usr/sbin/tcptraceroute (tcptraceroute) in auto mode

Processing triggers for man-db (2.8.3-2ubuntu0.1) ...

---------------------------------------------------------------------------------------------------------------------------

Command: ping -c 4 usth.edu.vn

Output:

PING usth.edu.vn (104.27.161.15) 56(84) bytes of data.

64 bytes from 104.27.161.15 (104.27.161.15): icmp\_seq=1 ttl=58 time=48.8 ms

64 bytes from 104.27.161.15 (104.27.161.15): icmp\_seq=2 ttl=58 time=54.0 ms

64 bytes from 104.27.161.15 (104.27.161.15): icmp\_seq=3 ttl=58 time=50.6 ms

64 bytes from 104.27.161.15 (104.27.161.15): icmp\_seq=4 ttl=58 time=50.5 ms

--- usth.edu.vn ping statistics ---

4 packets transmitted, 4 received, 0% packet loss, time 3004ms

rtt min/avg/max/mdev = 48.833/51.006/54.025/1.884 ms

---------------------------------------------------------------------------------------------------------------------------

Command: traceroute usth.edu.vn

Output:

traceroute to usth.edu.vn (104.27.161.15), 30 hops max, 60 byte packets

1 \_gateway (192.168.0.1) 5.851 ms 22.110 ms 22.111 ms

2 \* \* \*

3 static.vnpt.vn (123.29.4.115) 30.578 ms 31.942 ms 32.760 ms

4 static.vnpt.vn (113.171.36.13) 32.750 ms 32.757 ms 32.751 ms

5 \* \* \*

6 static.vnpt.vn (113.171.37.137) 55.882 ms static.vnpt.vn (113.171.5.46) 32.977 ms static.vnpt.vn (113.171.37.137) 32.360 ms

7 static.vnpt.vn (113.171.35.81) 12.229 ms 12.950 ms 12.937 ms

8 static.vnpt.vn (113.171.37.243) 38.044 ms 38.044 ms 36.563 ms

9 d1-149-230-143-118-on-nets.com (118.143.230.149) 38.423 ms 53.987 ms 37.388 ms

10 218.189.5.26 (218.189.5.26) 29.774 ms 218.189.5.58 (218.189.5.58) 33.735 ms 218.189.5.26 (218.189.5.26) 33.244 ms

11 global.hgc.com.hk (218.189.8.6) 67.320 ms 66.439 ms global.hgc.com.hk (218.189.8.2) 61.316 ms

12 d1-195-238-143-118-on-nets.com (118.143.238.195) 64.720 ms d1-244-224-143-118-on-nets.com (118.143.224.244) 64.113 ms d1-195-238-143-118-on-nets.com (118.143.238.195) 64.718 ms

13 13335.sgw.equinix.com (27.111.228.132) 62.193 ms 61.663 ms 61.651 ms

14 104.27.161.15 (104.27.161.15) 52.674 ms 51.034 ms 47.723 ms
