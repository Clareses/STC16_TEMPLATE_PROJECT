set filename=KEILOUT
set path=..\Output
::获取日期 将格式设置为：20110820
set datevar=%date:~0,4%%date:~5,2%%date:~8,2%
set timevar=%time:~0,2%
if /i %timevar% LSS 10 (
set timevar=0%time:~1,1%
)
::获取时间中的分、秒 将格式设置为：3220 ，表示 32分20秒
set timevar=%timevar%%time:~3,2%%time:~6,2%
set copyfilename=%filename%-%datevar%-%timevar%
copy %path%\%filename%.hex ..\HEX\%copyfilename%.hex
@echo filename:%copyfilename%.hex
