@echo off
rem Empty
echo on
ramp.exe 0 0 0 0
@echo off
rem Full numeric range
echo on 
ramp.exe 0 65535 65535 0
@echo off
rem Minimal integer range
echo on
ramp.exe 0 15 15 0
@echo off
rem 2 Arguments
echo on
ramp.exe 0 15
@echo off
rem 3 arguments
echo on
ramp.exe 0 15 8
@echo off
rem Error cases:
echo on
ramp.exe 0
ramp.exe 0 -1
ramp.exe 0 65536
